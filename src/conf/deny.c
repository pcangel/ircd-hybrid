/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  deny.c: Defines the deny{} and exempt{} blocks of ircd.conf.
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
#include "server.h"
#include "ircd.h"
#include "parse_aline.h"
#include "user.h"

int acb_type_deny, acb_type_exempt;

static struct DenyConf tmpdeny = {{0}};
static struct AccessConf tmpexempt = {0};
static dlink_node *hbanned, *hverify;
static struct ConfStoreField dline_fields[] =
{
  { "host", CSF_STRING },
  { "reason", CSF_STRING },
  { "oper_reason", CSF_STRING },
  { NULL, CSF_STRING },
  { "oper", CSF_STRING },
  { "added", CSF_NUMBER },
  { NULL, 0 }
};
static struct ConfStore dline_store =
  {"dline", &ServerState.dlinefile, dline_fields};

static int write_perm_dline(struct DenyConf *, struct Client *);

static int do_report_deny(struct AccessConf *, void *);
static int do_report_tdeny(struct AccessConf *, void *);
static int do_report_exempt(struct AccessConf *, void *);

/*
 * free_dline()
 *
 * Frees a DenyConf struct.
 *
 * inputs: what to free
 * output: none
 */
static void
free_dline(struct DenyConf *dline)
{
  MyFree(dline->reason);
  MyFree(dline->oper_reason);
  acb_generic_free(&dline->access);
}

/*
 * before_exempt()
 *
 * Called before parsing a single exempt{ block.
 *
 * inputs: none
 * output: none
 */
static void
before_exempt(void)
{
  MyFree(tmpexempt.host);
  memset(&tmpexempt, 0, sizeof(tmpexempt));
  tmpexempt.type = acb_type_exempt;
}

/*
 * free_tmpdeny()
 *
 * Called before parsing a single deny{} block.
 *
 * inputs: none
 * output: none
 */
static void
free_tmpdeny(void)
{
  MyFree(tmpdeny.reason);
  MyFree(tmpdeny.oper_reason);
  MyFree(tmpdeny.access.host);
  memset(&tmpdeny, 0, sizeof(tmpdeny));
  tmpdeny.access.type = acb_type_deny;
}

static void
commit_tmpdeny(void)
{
  struct DenyConf *conf;

  if (tmpdeny.access.host == NULL ||
      parse_netmask(tmpdeny.access.host, NULL, NULL) == HM_HOST)
  {
    free_tmpdeny();
    return;
  }

  conf = MyMalloc(sizeof(*conf));
  memcpy(conf, &tmpdeny, sizeof(*conf));
  add_access_conf(&conf->access);

  memset(&tmpdeny, 0, sizeof(tmpdeny));
}

/*
 * parse_ip()
 *
 * Parses the "ip=" field.
 *
 * inputs: pointer to a string
 * output: none
 */
static void
parse_ip(void *value, void *where)
{
  struct split_nuh_item uh;
  char hostbuf[HOSTLEN + 1], **s = where;

  uh.nuhmask = value;
  uh.nickptr = uh.userptr = NULL;
  uh.hostptr = hostbuf;

  uh.nicksize = uh.usersize = 0;
  uh.hostsize = sizeof(hostbuf);

  split_nuh(&uh);

  MyFree(*s);
  DupString(*s, hostbuf);
}

/*
 * after_exempt()
 *
 * Called after parsing a single exempt{} block.
 *
 * inputs: none
 * output: none
 */
static void
after_exempt(void)
{
  struct AccessConf *conf;

  if (!tmpexempt.host || parse_netmask(tmpexempt.host, NULL, NULL) == HM_HOST)
  {
    before_exempt();
    return;
  }

  conf = MyMalloc(sizeof(*conf));
  memcpy(conf, &tmpexempt, sizeof(*conf));
  memset(&tmpexempt, 0, sizeof(tmpexempt));
  add_access_conf(conf);
}

static void *
load_dlines(va_list args)
{
  while (execute_callback(read_conf_store, dline_store, &tmpdeny.access.host,
                          &tmpdeny.reason, &tmpdeny.oper_reason, NULL, NULL,
                          NULL))
  {
    tmpdeny.access.type = acb_type_deny;
    commit_tmpdeny();
  }

  return pass_callback(hverify);
}

void
add_dline(struct Client *source_p, char *host,
          char *reason, char *oper_reason, int tdline_time)
{
  DupString(tmpdeny.access.host, host);
  tmpdeny.reason = a_line_format_reason(reason, "D-Line", tdline_time);
  DupString(tmpdeny.oper_reason, oper_reason);
  tmpdeny.access.expires = CurrentTime + tdline_time;

  if (! tdline_time && write_perm_dline(&tmpdeny, source_p))
    sendto_one(source_p, ":%s NOTICE %s :Added D-Line [%s] to storage",
               me.name, source_p->name, host);

  // TBD: should we still add it to memory if we can't store it?
  commit_tmpdeny();
  announce_a_line(source_p, "D-Line", tdline_time, reason, oper_reason,
                  "%s", host);

  rehashed_klines = 1;
}

static int
write_perm_dline(struct DenyConf *conf, struct Client *source_p)
{
/* XXX */
char *oper;
  return !!execute_callback(append_conf_store, dline_store, source_p,
                            conf->access.host, conf->reason, conf->oper_reason,
                            smalldate(CurrentTime), oper, CurrentTime);
}

/*
 * find_dline()
 *
 * Returns a matching DenyConf.
 *
 * inputs: IP address
 * output: pointer to the conf or NULL if not found
 */
struct DenyConf *
find_dline(const struct irc_ssaddr *ip)
{
  struct DenyConf *conf = (struct DenyConf *) find_access_conf(acb_type_deny,
    NULL, NULL, ip, NULL, NULL);

  if (conf && find_exempt(ip))
    conf = NULL;

  return conf;
}

/*
 * find_exempt()
 *
 * Returns a matching exempt entry.
 *
 * inputs: IP address
 * output: pointer to the conf or NULL if not found
 */
struct AccessConf *
find_exempt(const struct irc_ssaddr *ip)
{
  return find_access_conf(acb_type_exempt, NULL, NULL, ip, NULL, NULL);
}

/*
 * is_client_dlined()
 *
 * Hook function for is_client_banned.
 *
 * inputs:
 *   client  -  local client to check
 *   type    -  we set it to ban type if there's a match
 *   reason  -  we set it to ban reason (if any)
 * output: not NULL if they're banned
 */
static void *
is_client_dlined(va_list args)
{
  struct Client *client = va_arg(args, struct Client *);
  char **type = va_arg(args, char **);
  char **reason = va_arg(args, char **);
  struct DenyConf *conf = IsExemptKline(client) ? NULL :
    find_dline(&client->localClient->ip);

  if (conf)
  {
    *type = "D-line";
    *reason = conf->reason;
    return conf;
  }

  return pass_callback(hbanned, client, type, reason);
}

/*
 * report_deny()
 *
 * Send a /stats D reply to the given client.
 *
 * inputs: client pointer
 * output: none
 */
void report_deny(struct Client *source_p) { enum_access_confs(do_report_deny, source_p); }
void report_tdeny(struct Client *source_p) { enum_access_confs(do_report_tdeny, source_p); }
void report_exempt(struct Client *source_p) { enum_access_confs(do_report_exempt, source_p); }

static int
do_report_deny(struct AccessConf *conf, void *source_p)
{
  if (conf->type == acb_type_deny && !conf->expires)
  {
    struct Client *cptr = source_p;
    struct DenyConf *deny = (struct DenyConf *) conf;
    sendto_one(source_p, form_str(RPL_STATSDLINE), ID_or_name(&me, cptr->from),
               ID_or_name(cptr, cptr->from), 'D', conf->host,
               deny->reason ? deny->reason : "No reason",
               deny->oper_reason ? deny->oper_reason : "");
  }
  return NO;
}

static int
do_report_tdeny(struct AccessConf *conf, void *source_p)
{
  if (conf->type == acb_type_deny && conf->expires)
  {
    struct Client *cptr = source_p;
    struct DenyConf *deny = (struct DenyConf *) conf;
    sendto_one(source_p, form_str(RPL_STATSDLINE), ID_or_name(&me, cptr->from),
               ID_or_name(cptr, cptr->from), 'd', conf->host,
               deny->reason ? deny->reason : "No reason",
               deny->oper_reason ? deny->oper_reason : "");
  }
  return NO;
}

static int
do_report_exempt(struct AccessConf *conf, void *source_p)
{
  if (conf->type == acb_type_exempt)
  {
    struct Client *cptr = source_p;
    sendto_one(source_p, form_str(RPL_STATSDLINE), ID_or_name(&me, cptr->from),
               ID_or_name(cptr, cptr->from), 'e', conf->host, "", "");
  }
  return NO;
}

/*
 * init_deny()
 *
 * Defines the deny{} and exempt{} conf sections.
 *
 * inputs: none
 * output: none
 */
void
init_deny(void)
{
  struct ConfSection *s = add_conf_section("deny", 2);
  struct ConfSection *s2 = add_conf_section("exempt", 2);

  hbanned = install_hook(is_client_banned, is_client_dlined);

  acb_type_deny = register_acb_type("D-line", (ACB_FREE_HANDLER *) free_dline);
  acb_type_exempt = register_acb_type("exempt",
    (ACB_FREE_HANDLER *) acb_generic_free);

  s->before = free_tmpdeny;
  s2->before = before_exempt;

  s->def_field = add_conf_field(s, "ip", CT_STRING, parse_ip,
    &tmpdeny.access.host);
  s2->def_field = add_conf_field(s, "ip", CT_STRING, parse_ip,
    &tmpexempt.host);
  add_conf_field(s, "reason", CT_STRING, NULL, &tmpdeny.reason);

  s->after = commit_tmpdeny;
  s2->after = after_exempt;

  hverify = install_hook(verify_conf, load_dlines);
}
