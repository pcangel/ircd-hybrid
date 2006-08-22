/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  auth.c: Defines the auth{} block of ircd.conf.
 *
 *  Copyright (C) 2006 by the Hybrid Development Team.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *  USA
 *
 *  $Id$
 */

#include "stdinc.h"
#include "conf/conf.h"
#include "client.h"
#include "numeric.h"
#include "send.h"
#include "s_serv.h"

int acb_type_auth = -1;

static struct AuthConf tmpauth = {{0}, 0};
static dlink_list tmpuh = {0};

// TODO: These should be modularised like acb_types
static const struct FlagMapping {
  char letter;
  const char *name;
  unsigned int flag;
} flag_mappings[] = {
  {'-', "no_tilde", AUTH_FLAG_NO_TILDE},
  {'+', "have_ident", AUTH_FLAG_NEED_IDENT},
  {'&', "need_password", AUTH_FLAG_NEED_PASSWORD},
  {'$', "resv_exempt", AUTH_FLAG_RESV_EXEMPT},
  {'=', "spoof_notice", AUTH_FLAG_SPOOF_NOTICE},
  {'^', "kline_exempt", AUTH_FLAG_KLINE_EXEMPT},
  {'_', "gline_exempt", AUTH_FLAG_GLINE_EXEMPT},
  {'>', "exceed_limit", AUTH_FLAG_EXCEED_LIMIT},
  {'<', "can_idle", AUTH_FLAG_CAN_IDLE},
  {'|', "can_flood", AUTH_FLAG_CAN_FLOOD},
  {0, "encrypted", AUTH_FLAG_ENCRYPTED},
  {0, NULL, 0}
};

static int do_report_auth(struct AuthConf *, struct Client *);
static int check_auth_passwd(struct AuthConf *, const char *);

/*
 * free_iline()
 *
 * Frees an auth{} block.
 *
 * inputs: pointer to struct AuthConf
 * output: none
 */
static void
free_iline(struct AuthConf *conf)
{
  unref_class(conf->class_ptr);
  MyFree(conf->spoof);
  MyFree(conf->password);
  MyFree(conf->redirserv);
  acb_generic_free(&conf->access);
}

/*
 * before_iline()
 *
 * Called before parsing a single auth{} block.
 * Frees all temporary storage.
 *
 * inputs: none
 * output: none
 */
static void
before_iline(void)
{
  while (tmpuh.head != NULL)
  {
    struct split_nuh_item *nuh = tmpuh.head->data;

    dlinkDelete(&nuh->node, &tmpuh);

    MyFree(nuh->userptr);
    MyFree(nuh->hostptr);
    MyFree(nuh);
  }

  MyFree(tmpauth.access.user);
  MyFree(tmpauth.access.host);
  MyFree(tmpauth.spoof);
  MyFree(tmpauth.password);
  MyFree(tmpauth.redirserv);

  if (tmpauth.class_ptr != NULL)
    unref_class(tmpauth.class_ptr);

  memset(&tmpauth, 0, sizeof(tmpauth));
  tmpauth.access.type = acb_type_auth;
}

/*
 * iline_user()
 *
 * Handles the "user=" field.
 *
 * inputs: the value
 * output: none
 */
static void
iline_user(void *value, void *unused)
{
  struct split_nuh_item nuh, *uh;
  char userbuf[USERLEN + 1];
  char hostbuf[HOSTLEN + 1];

  nuh.nuhmask = (char *) value;
  nuh.nickptr = NULL;
  nuh.userptr = userbuf;
  nuh.hostptr = hostbuf;

  nuh.nicksize = 0;
  nuh.usersize = sizeof(userbuf);
  nuh.hostsize = sizeof(hostbuf);

  split_nuh(&nuh);

  uh = MyMalloc(sizeof(*uh));
  DupString(uh->userptr, userbuf);
  DupString(uh->hostptr, hostbuf);
  dlinkAddTail(uh, &uh->node, &tmpuh);
}

/*
 * iline_class()
 *
 * Handles the "class=" field.
 *
 * inputs: the value
 * output: none
 */
static void
iline_class(void *value, void *unused)
{
  if (tmpauth.class_ptr != NULL)
    unref_class(tmpauth.class_ptr);

  tmpauth.class_ptr = ref_class_by_name(value);
}

/*
 * iline_flags()
 *
 * Handles the "flags=" list.
 *
 * inputs: pointer to a dlink_list of flag names
 * output: none
 */
static void
iline_flags(void *list, void *unused)
{
  const struct FlagMapping *p;
  int errors = NO;
  dlink_node *ptr;

  tmpauth.flags = 0;

  DLINK_FOREACH(ptr, ((dlink_list *)list)->head)
  {
    const char *str = ptr->data;
    int found = NO;

    for (p = flag_mappings; p->name; ++p)
      if (!irccmp(str, p->name))
      {
        found = YES;
        tmpauth.flags |= p->flag;
        break;
      }

    if (!found)
      errors = YES;
  }

  if (errors)
    parse_error("Invalid auth flags encountered, check your syntax");
}

/*
 * iline_flag()
 *
 * Parses an old-style switch.
 *
 * inputs:
 *   state  -  YES/NO casted to void
 *   flag   -  flag value casted to void
 * output: none
 */
static void
iline_flag(void *state, void *flag)
{
  if (*(int *) state)
    tmpauth.flags |= (unsigned long) flag;
  else
    tmpauth.flags &= ~((unsigned long) flag);
}

/*
 * after_iline()
 *
 * Called after parsing a single auth{} block.
 *
 * inputs: none
 * output: none
 */
static void
after_iline(void)
{
  if (tmpauth.class_ptr == NULL)
    parse_error("Invalid or non-existant class in auth{}");
  else if (dlink_list_length(&tmpuh) == 0)
    parse_error("Incomplete operator{} block");
  else
    while (tmpuh.head != NULL)
    {
      struct split_nuh_item *nuh = tmpuh.head->data;
      struct AuthConf *conf = MyMalloc(sizeof(struct AuthConf));
      memcpy(conf, &tmpauth, sizeof(*conf));

      conf->access.user = nuh->userptr;
      conf->access.host = nuh->hostptr;
      ref_class_by_ptr(conf->class_ptr);

      if (tmpauth.spoof)
        DupString(conf->spoof, tmpauth.spoof);
      if (tmpauth.password)
        DupString(conf->password, tmpauth.password);
      if (tmpauth.redirserv)
        DupString(conf->redirserv, tmpauth.redirserv);

      add_access_conf(&conf->access);

      dlinkDelete(&nuh->node, &tmpuh);
      MyFree(nuh);
    }

  before_iline();
}

/*
 * find_iline()
 *
 * Returns an auth entry matching the given user@host/ip.
 *
 * inputs:
 *   user  -  username part, can be NULL
 *   host  -  hostname part, can be NULL
 *   ip    -  IP address (with ss.sin_family set), can be NULL
 *   pwd   -  password given by the client
 * output: pointer to AuthConf
 */
struct AuthConf *
find_iline(const char *user, const char *host, const struct irc_ssaddr *ip,
           const char *pwd)
{
  return (struct AuthConf *) find_access_conf(acb_type_auth, user, host, ip,
    (ACB_EXAMINE_HANDLER *) check_auth_passwd, (void *) pwd);
}

static int
check_auth_passwd(struct AuthConf *conf, const char *pwd)
{
  if ((conf->flags & AUTH_FLAG_NEED_PASSWORD) || EmptyString(conf->password))
    return YES;
  return EmptyString(pwd) ? NO : !strcmp(conf->password, pwd);
}

/*
 * report_auth()
 *
 * Execute a /STATS I request.
 *
 * inputs: a client to send to
 * output: none
 */
void
report_auth(struct Client *source_p)
{
  if (General.stats_i_oper_only == 2 && !IsOper(source_p))
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               ID_or_name(&me, source_p->from),
               ID_or_name(source_p, source_p->from));
  else if (General.stats_i_oper_only == 1 && !IsOper(source_p))
  {
    struct AuthConf *conf = find_iline(source_p->username, source_p->host,
      MyConnect(source_p) ? &source_p->localClient->ip : NULL,
      MyConnect(source_p) ? source_p->localClient->passwd : NULL);
    if (conf)
      do_report_auth(conf, source_p);
  }
  else
    enum_access_confs((ACB_EXAMINE_HANDLER *) do_report_auth, source_p);
}

static int
do_report_auth(struct AuthConf *conf, struct Client *source_p)
{
  const struct FlagMapping *m;
  char prefix[sizeof(flag_mappings) / sizeof(flag_mappings[0])];
  char *p = prefix;

  if (conf->access.type != acb_type_auth ||
      (!MyOper(source_p) && conf->spoof))
    return 0;

  for (m = flag_mappings; m->name; m++)
    if ((conf->flags & m->flag))
      *p++ = m->letter;
  *p = 0;

  sendto_one(source_p, form_str(RPL_STATSILINE),
             ID_or_name(&me, source_p->from),
             ID_or_name(source_p, source_p->from), 'I', conf->spoof ?
             conf->spoof : "*", prefix, conf->access.user,
             (General.hide_spoof_ips && conf->spoof) ? "255.255.255.255" :
             conf->access.host, conf->redirport, conf->class_ptr->name);
  return 0;
}

/*
 * init_ilines()
 *
 * Defines the auth{} conf section.
 *
 * inputs: none
 * output: none
 */
void
init_ilines(void)
{
  struct ConfSection *s = add_conf_section("auth", 2);
  const struct FlagMapping *p;

  acb_type_auth = register_acb_type("auth", free_iline);

  s->before = before_iline;

  s->def_field = add_conf_field(s, "user", CT_STRING, iline_user, NULL);
  add_conf_field(s, "password", CT_STRING, NULL, &tmpauth.password);
  add_conf_field(s, "class", CT_STRING, iline_class, NULL);
  add_conf_field(s, "spoof", CT_STRING, NULL, &tmpauth.spoof);
  add_conf_field(s, "redirserv", CT_STRING, NULL, &tmpauth.redirserv);
  add_conf_field(s, "redirport", CT_NUMBER, NULL, &tmpauth.redirport);

  add_conf_field(s, "flags", CT_LIST, iline_flags, NULL);
  for (p = flag_mappings; p->name; ++p)
    add_conf_field(s, p->name, CT_BOOL, iline_flag,
                   (void *) (unsigned long) p->flag);

  s->after = after_iline;
}
