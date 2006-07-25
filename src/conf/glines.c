/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  glines.c: Defines the glines{} block of ircd.conf.
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

int enable_glines = NO;
time_t gline_duration;
int gline_logging;
int acb_type_gline;
dlink_list pending_glines = {0};

static dlink_node *hreset, *hbanned;
static char *tmpdeny_server = NULL;
static dlink_list tmpdeny_masks = {0};
static dlink_list gdeny_confs = {0};

/*
 * reset_glines()
 *
 * Frees all gline deny entries before a rehash.
 *
 * inputs: none
 * output: none
 */
static void *
reset_glines(va_list args)
{
  while (gdeny_confs.head != NULL)
  {
    struct GlineDenyConf *conf = gdeny_confs.head->data;

    dlinkDelete(&conf->node, &gdeny_confs);

    MyFree(conf->server);
    MyFree(conf->user);
    MyFree(conf->host);
    MyFree(conf);
  }

  gline_duration = 12*3600;

  return pass_callback(hreset);
}

/*
 * clear_temp()
 *
 * Clears temporary storage after parsing a gline deny entry.
 *
 * inputs: none
 * output: none
 */
static void
clear_temp(void)
{
  MyFree(tmpdeny_server);
  tmpdeny_server = NULL;

  while (tmpdeny_masks.head)
  {
    struct split_nuh_item *uh = tmpdeny_masks.head->data;

    dlinkDelete(&uh->node, &tmpdeny_masks);

    MyFree(uh->userptr);
    MyFree(uh->hostptr);
    MyFree(uh);
  }
}

/*
 * parse_user()
 *
 * Parses a "user=" field.
 *
 * inputs: user@host mask
 * output: none
 */
static void
parse_user(void *value, void *unused)
{
  char *str = value;
  char userbuf[USERLEN + 1];
  char hostbuf[HOSTLEN + 1];
  struct split_nuh_item nuh, *cuh;

  nuh.nuhmask  = str;
  nuh.nickptr  = NULL;
  nuh.userptr  = userbuf;
  nuh.hostptr  = hostbuf;

  nuh.nicksize = 0;
  nuh.usersize = sizeof(userbuf);
  nuh.hostsize = sizeof(hostbuf);

  split_nuh(&nuh);

  cuh = MyMalloc(sizeof(*cuh));
  DupString(cuh->userptr, nuh.userptr);
  DupString(cuh->hostptr, nuh.hostptr);

  dlinkAddTail(cuh, &cuh->node, &tmpdeny_masks);
}

/*
 * do_parse_action()
 *
 * Parses a reject/block list.
 *
 * inputs:
 *   list   -  points to a string dlink list
 *   where  -  where to store the resulting flags
 * output: none
 */
static void
do_parse_action(void *list, void *where)
{
  int flags = 0;
  dlink_node *ptr;

  DLINK_FOREACH(ptr, ((dlink_list *) list)->head)
    if (!irccmp(ptr->data, "reject"))
      flags |= GDENY_REJECT;
    else if (!irccmp(ptr->data, "block"))
      flags |= GDENY_BLOCK;
    else
      flags |= GDENY_ERROR;

  if ((flags & GDENY_ERROR))
    parse_error("Invalid gline action encountered, check your syntax");

  *(int *) where = flags;
}

/*
 * parse_action()
 *
 * Parses an "action=" field, eventually adding a gline exempt.
 *
 * inputs: pointer to a string dlink list
 * output: none
 */
static void
parse_action(void *list, void *unused)
{
  int action, bits;
  dlink_node *ptr;
  struct split_nuh_item *uh;
  struct GlineDenyConf *conf;

  do_parse_action(list, &action);

  if (!(action & GDENY_ERROR))
  {
    if (dlink_list_length(&tmpdeny_masks) == 0)
    {
      uh = MyMalloc(sizeof(*uh));
      DupString(uh->userptr, "*");
      DupString(uh->hostptr, "*");
      dlinkAdd(uh, &uh->node, &tmpdeny_masks);
    }

    DLINK_FOREACH(ptr, tmpdeny_masks.head)
    {
      conf = MyMalloc(sizeof(*conf));
      DupString(conf->server, tmpdeny_server ? tmpdeny_server : "*");

      uh = ptr->data;
      conf->user = uh->userptr;
      conf->host = uh->hostptr;
      uh->userptr = uh->hostptr = NULL;

      if (parse_netmask(conf->host, &conf->ip, &bits) != HM_HOST)
        conf->ip.ss_port = bits;
      dlinkAddTail(conf, &conf->node, &gdeny_confs);
    }
  }

  clear_temp();
}

/*
 * is_gline_allowed()
 *
 * Checks if there is a gline deny entry against a proposed gline.
 *
 * inputs:
 *   server  -  server feeding the gline to us
 *   user    -  username of the oper issuing the gline
 *   host    -  hostname of the oper
 *   addr    -  IP address of the oper
 * output: GDENY_* flags (or 0 if no restrictions)
 */
int
is_gline_allowed(const char *server, const char *user, const char *host,
                 const char *addr)
{
  dlink_node *ptr;
  struct GlineDenyConf *conf;
  struct irc_ssaddr ip;
  struct addrinfo hints = {0}, *res;

  ip.ss.sin_family = AF_UNSPEC;
  if (EmptyString(addr))
    addr = host;

  hints.ai_family   = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags    = AI_NUMERICHOST;

  if (!irc_getaddrinfo(addr, NULL, &hints, &res))
  {
    memcpy(&ip, res->ai_addr, res->ai_addrlen);
    ip.ss.sin_family = res->ai_family;
    ip.ss_len = res->ai_addrlen;
    irc_freeaddrinfo(res);
  }

  DLINK_FOREACH(ptr, gdeny_confs.head)
  {
    conf = ptr->data;
    if (!match(user, conf->user) || !match(server, conf->server))
      continue;

    if (ip.ss.sin_family != AF_UNSPEC &&
        conf->ip.ss.sin_family != AF_UNSPEC && (
#ifdef IPV6
        (conf->ip.ss.sin_family == AF_INET6) ? match_ipv6 :
#endif
        match_ipv4)(&ip, &conf->ip, conf->ip.ss_port))
      return conf->action;
    if (match(conf->host, host))
      return conf->action;
  }

  return 0;
}

/*
 * free_gline()
 *
 * Frees a GlineConf entry.
 *
 * inputs: pointer to the conf
 * output: none
 */
static void
free_gline(struct GlineConf *conf)
{
  MyFree(conf->reason);
  acb_generic_free(&conf->access);
}

/*
 * place_gline()
 *
 * Applies a new G-line locally, without checking any privileges.
 *
 * inputs:
 *   user    -  username mask
 *   host    -  hostname mask
 *   reason  -  gline reason
 * output: pointer to the new conf item
 */
struct GlineConf *
place_gline(const char *user, const char *host, const char *reason)
{
  struct GlineConf *conf = MyMalloc(sizeof(struct GlineConf));

  conf->access.type = acb_type_gline;
  DupString(conf->access.user, user);
  DupString(conf->access.host, host);
  conf->access.expires = CurrentTime + gline_duration;
  DupString(conf->reason, reason);

  add_access_conf(&conf->access);
  return conf;
}

/*
 * find_gline()
 *
 * Looks for a G-line entry for a given user@host/ip.
 *
 * inputs:
 *   user  -  username part, can be NULL
 *   host  -  hostname part, can be NULL
 *   ip    -  IP address, can be NULL
 * output: pointer to a gline conf, if any
 */
struct GlineConf *
find_gline(const char *user, const char *host, const struct irc_ssaddr *ip)
{
  return (struct GlineConf *) find_access_conf(acb_type_gline, user, host, ip,
    NULL, NULL);
}

/*
 * is_client_glined()
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
is_client_glined(va_list args)
{
  struct Client *client = va_arg(args, struct Client *);
  char **type = va_arg(args, char **);
  char **reason = va_arg(args, char **);
  struct GlineConf *conf = (IsExemptGline(client) || IsExemptKline(client)) ?
    NULL : find_gline(client->username, client->host, &client->localClient->ip);

  if (conf)
  {
    *type = "G-line";
    *reason = conf->reason;
    return conf;
  }

  return pass_callback(hbanned, client, type, reason);
}

/*
 * report_glines()
 *
 * Sends a /stats G reply to the given client.
 *
 * inputs: client pointer
 * output: none
 */
static int
do_report_glines(struct GlineConf *conf, struct Client *source_p)
{
  if (conf->access.type == acb_type_gline)
    sendto_one(source_p, form_str(RPL_STATSKLINE),
               ID_or_name(&me, source_p->from),
               ID_or_name(source_p, source_p->from), "G",
               conf->access.host, conf->access.user,
               conf->reason ? conf->reason : "No reason", "");
  return NO;
}

void
report_glines(struct Client *to)
{
  if (enable_glines)
    enum_access_confs((ACB_EXAMINE_HANDLER *) do_report_glines, to);
  else
    sendto_one(to, ":%s NOTICE %s :This server does not support G-lines",
               ID_or_name(&me, to->from), ID_or_name(to, to->from));
}

void
report_pending_glines(struct Client *to)
{
  if (enable_glines)
  {
#ifdef GLINE_VOTING
    dlink_node *ptr;

    if (dlink_list_length(&pending_glines) > 0)
      sendto_one(to, ":%s NOTICE %s :Pending G-lines",
                 ID_or_name(&me, to->from), ID_or_name(to, to->from));

    DLINK_FOREACH(ptr, pending_glines.head)
    {
      char timebuffer[MAX_DATE_STRING];
      struct GlinePending *p = ptr->data;
      struct tm *tmptr = localtime(&p->request1.time_request);

      strftime(timebuffer, sizeof(timebuffer), "%Y/%m/%d %H:%M:%S", tmptr);
      sendto_one(to, ":%s NOTICE %s :1) %s!%s@%s on %s requested gline at %s "
                 "for %s@%s [%s]", ID_or_name(&me, to->from),
                 ID_or_name(to, to->from), p->request1.nick, p->request1.user,
                 p->request1.host, p->request1.server, timebuffer, p->user,
                 p->host, p->request1.reason);

      if (p->request2.nick[0])
      {
        tmptr = localtime(&p->request2.time_request);
        strftime(timebuffer, sizeof(timebuffer), "%Y/%m/%d %H:%M:%S", tmptr);
        sendto_one(to, ":%s NOTICE %s :2) %s!%s@%s on %s requested gline at %s "
                   "for %s@%s [%s]", ID_or_name(&me, to->from),
                   ID_or_name(to, to->from), p->request2.nick, p->request2.user,
                   p->request2.host, p->request2.server, timebuffer, p->user,
                   p->host, p->request2.reason);
      }
    }

    if (dlink_list_length(&pending_glines) > 0)
      sendto_one(to, ":%s NOTICE %s :End of Pending G-lines",
                 ID_or_name(&me, to->from), ID_or_name(to, to->from));
#else
    sendto_one(to, ":%s NOTICE %s :This server does not support G-line voting",
               ID_or_name(&me, to->from), ID_or_name(to, to->from));
#endif
  }
  else
    sendto_one(to, ":%s NOTICE %s :This server does not support G-lines",
               ID_or_name(&me, to->from), ID_or_name(to, to->from));
}

void
report_gline_deny(struct Client *to)
{
  dlink_node *ptr;
  struct GlineDenyConf *conf;
  char buf[3] = {0};

  if (enable_glines)
    DLINK_FOREACH(ptr, gdeny_confs.head)
    {
      conf = ptr->data;
      buf[0] = (conf->action & GDENY_BLOCK) ? 'B' : 'b';
      buf[1] = (conf->action & GDENY_REJECT) ? 'R' : 'r';
      sendto_one(to, ":%s %d %s V %s@%s %s %s", ID_or_name(&me, to->from),
                 RPL_STATSDEBUG, ID_or_name(to, to->from), conf->user,
                 conf->host, conf->server, buf);
    }
  else
    sendto_one(to, ":%s NOTICE %s :This server does not support G-lines",
               ID_or_name(&me, to->from), ID_or_name(to, to->from));
}

/*
 * init_glines()
 *
 * Defines the glines{} conf section.
 *
 * inputs: none
 * output: none
 */
void
init_glines(void)
{
  struct ConfSection *s = add_conf_section("glines", 2);

  hreset = install_hook(reset_conf, reset_glines);
  hbanned = install_hook(is_client_banned, is_client_glined);

  acb_type_gline = register_acb_type("G-line", (ACB_FREE_HANDLER *) free_gline);

  s->before = s->after = clear_temp;

  add_conf_field(s, "enable", CT_BOOL, NULL, &enable_glines);
  add_conf_field(s, "duration", CT_TIME, NULL, &gline_duration);
  add_conf_field(s, "logging", CT_LIST, do_parse_action, &gline_logging);
  add_conf_field(s, "user", CT_STRING, parse_user, NULL);
  add_conf_field(s, "name", CT_STRING, NULL, &tmpdeny_server);
  add_conf_field(s, "action", CT_LIST, parse_action, NULL);
}
