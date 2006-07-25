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
#include "s_serv.h"

// TODO: Add callbacks for dline.conf support with default handlers

int acb_type_deny, acb_type_exempt;

static struct DenyConf tmpdeny = {{0}};
static struct AccessConf tmpexempt = {0};
static dlink_node *hbanned;

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
 * before_deny()
 *
 * Called before parsing a single deny{} block.
 *
 * inputs: none
 * output: none
 */
static void
before_deny(void)
{
  MyFree(tmpdeny.reason);
  MyFree(tmpdeny.oper_reason);
  MyFree(tmpdeny.access.host);
  memset(&tmpdeny, 0, sizeof(tmpdeny));
  tmpdeny.access.type = acb_type_deny;
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
 * after_deny()
 *
 * Called after parsing a single deny{} block.
 *
 * inputs: none
 * output: none
 */
static void
after_deny(void)
{
  struct DenyConf *conf;

  if (tmpdeny.access.host == NULL ||
      parse_netmask(tmpdeny.access.host, NULL, NULL) == HM_HOST)
  {
    before_deny();
    return;
  }

  conf = MyMalloc(sizeof(*conf));
  memcpy(conf, &tmpdeny, sizeof(*conf));
  memset(&tmpdeny, 0, sizeof(tmpdeny));
  add_access_conf(&conf->access);
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

  s->before = before_deny;
  s2->before = before_exempt;

  s->def_field = add_conf_field(s, "ip", CT_STRING, parse_ip,
    &tmpdeny.access.host);
  s2->def_field = add_conf_field(s, "ip", CT_STRING, parse_ip,
    &tmpexempt.host);
  add_conf_field(s, "reason", CT_STRING, NULL, &tmpdeny.reason);

  s->after = after_deny;
  s2->after = after_exempt;
}
