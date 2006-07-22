/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  kill.c: Defines the kill{} block of ircd.conf.
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

dlink_list rkline_confs = {NULL, NULL, 0};

static int acb_type_kline = -1;
static struct KillConf tmpkill = {{0}, 0};
static dlink_node *hreset, *hexpire;
static char *report_letter;

static void report_kline(struct KillConf *, struct Client *);

/*
 * free_kline()
 *
 * Frees a KillConf item.
 *
 * inputs: pointer to KillConf
 * output: none
 */
static void
free_kline(struct KillConf *conf)
{
  MyFree(conf->regexuser);
  MyFree(conf->regexhost);
  MyFree(conf->reason);
  acb_generic_free(&conf->access);
}

/*
 * before_kline()
 *
 * Called before parsing a kill{} block.
 *
 * inputs: none
 * output: none
 */
static void
before_kline(void)
{
  MyFree(tmpkill.access.user);
  MyFree(tmpkill.access.host);
  MyFree(tmpkill.regexuser);
  MyFree(tmpkill.regexhost);
  MyFree(tmpkill.oper_reason);
  MyFree(tmpkill.reason);
  memset(&tmpkill, 0, sizeof(tmpkill));
  tmpkill.access.type = acb_type_kline;
}

/*
 * kline_type()
 *
 * Parses a "type=" field.
 *
 * inputs: item list
 * output: none
 */
static void
kline_type(void *list, void *unused)
{
  dlink_node *ptr;

  DLINK_FOREACH(ptr, ((dlink_list *) list)->head)
    if (!ircncmp(ptr->data, "regex", 5))
      tmpkill.access.type = -1;
    else
    {
      parse_error("Syntax error");
      break;
    }
}

/*
 * kline_user()
 *
 * Parses a "user=" field.
 *
 * inputs: user@host mask
 * output: none
 */
static void
kline_user(void *mask, void *unused)
{
  struct split_nuh_item uh;
  char userbuf[256], hostbuf[256];

  uh.nuhmask = mask;
  uh.nickptr = NULL;
  uh.userptr = userbuf;
  uh.hostptr = hostbuf;

  uh.nicksize = 0;
  uh.usersize = sizeof(userbuf);
  uh.hostsize = sizeof(hostbuf);

  split_nuh(&uh);

  MyFree(tmpkill.access.user);
  MyFree(tmpkill.access.host);
  DupString(tmpkill.access.user, userbuf);
  DupString(tmpkill.access.host, hostbuf);
}

/*
 * after_kline()
 *
 * Called after parsing a kill{} block.
 *
 * inputs: none
 * output: none
 */
static void
after_kline(void)
{
  struct KillConf *conf;
  const char *errptr = NULL;

  if (!tmpkill.access.user || !tmpkill.access.host)
  {
    before_kline();
    return;
  }

  if (tmpkill.access.type == -1)
    if (!(tmpkill.regexuser = ircd_pcre_compile(tmpkill.access.user, &errptr))
     || !(tmpkill.regexhost = ircd_pcre_compile(tmpkill.access.host, &errptr)))
    {
      parse_error("Failed to add regular expression based K-line: %s", errptr);
      before_kline();
      return;
    }

  if (!tmpkill.reason)
    DupString(tmpkill.reason, "No reason");

  conf = MyMalloc(sizeof(*conf));
  memcpy(conf, &tmpkill, sizeof(*conf));
  if (tmpkill.access.type == acb_type_kline)
    add_access_conf(&conf->access);
  else
  {
    conf->access.precedence = curprec--;
    dlinkAddTail(conf, &conf->node, &rkline_confs);
  }

  memset(&tmpkill, 0, sizeof(tmpkill));
}

/*
 * reset_rklines()
 *
 * Frees all permanent regex K-lines before a rehash.
 *
 * inputs: none
 * output: none
 */
static void *
reset_rklines(va_list args)
{
  dlink_node *ptr, *ptr_next;

  DLINK_FOREACH_SAFE(ptr, ptr_next, rkline_confs.head)
  {
    struct KillConf *conf = ptr->data;

    if (!conf->access.expires)
    {
      dlinkDelete(&conf->node, &rkline_confs);
      free_kline(conf);
    }
  }

  return pass_callback(hreset);
}

/*
 * expire_rklines()
 *
 * Goes through the regex K-line list and destroys the ones
 * already expired.
 *
 * inputs: none
 * output: none
 */
static void *
expire_rklines(va_list args)
{
  dlink_node *ptr, *ptr_next;

  DLINK_FOREACH_SAFE(ptr, ptr_next, rkline_confs.head)
  {
    struct KillConf *conf = ptr->data;

    if (conf->access.expires && conf->access.expires <= CurrentTime)
    {
      sendto_realops_flags(UMODE_ALL, L_ALL,
        "Temporary %s for [%s@%s] expired", "K-line",
        conf->access.user, conf->access.host);
      dlinkDelete(&conf->node, &rkline_confs);
      free_kline(conf);
    }
  }

  return pass_callback(hexpire);
}

/*
 * find_kline()
 *
 * Looks for a matching K-line.
 *
 * inputs:
 *   user      -  username part, can be NULL
 *   host      -  hostname part, can be NULL
 *   sockhost  -  IP address as string, used in pair with the next argument
 *   ip        -  IP address (with ss.sin_family set), can be NULL
 * output: pointer to KillConf
 */
struct KillConf *
find_kline(const char *user, const char *host, const char *sockhost,
           const struct irc_ssaddr *ip)
{
  struct KillConf *best = NULL;
  dlink_node *ptr;

  best = (struct KillConf *) find_access_conf(acb_type_kline, user, host, ip,
    NULL, NULL);

  DLINK_FOREACH(ptr, rkline_confs.head)
  {
    struct KillConf *rkline = ptr->data;

    if ((!best || rkline->access.precedence > best->access.precedence) &&
        !ircd_pcre_exec(rkline->regexuser, user) &&
        (!ircd_pcre_exec(rkline->regexhost, host) ||
         !ircd_pcre_exec(rkline->regexhost, sockhost)))
      best = rkline;
  }

  return best;
}

/*
 * report_klines()
 *
 * Sends a list of [Kk]-lines to client_p in /stats format.
 *
 * inputs:
 *   client_p  -  where to send
 *   tkline    -  YES if we should list temporary klines, NO if permanent ones
 * output: none
 */
void
report_klines(struct Client *client_p, int tkline)
{
  report_letter = tkline ? "k" : "K";
  enum_access_confs((ACB_EXAMINE_HANDLER *) report_kline, client_p);
}

static void
report_kline(struct KillConf *conf, struct Client *client_p)
{
  if (conf->access.type == acb_type_kline &&
      (report_letter[0] == 'K') == (conf->access.expires == 0))
    sendto_one(client_p, form_str(RPL_STATSKLINE), me.name,
               client_p->name, report_letter, conf->access.host,
               conf->access.user, conf->reason,
               (IsOper(client_p) && conf->oper_reason) ?
               conf->oper_reason : "");
}

/*
 * init_kill()
 *
 * Defines the kill{} conf section.
 *
 * inputs: none
 * output: none
 */
void
init_kill(void)
{
  struct ConfSection *s = add_conf_section("kill", 2);

  acb_type_kline = register_acb_type("K-line", free_kline);
  hreset = install_hook(reset_conf, reset_rklines);
  hexpire = install_hook(cb_expire_confs, expire_rklines);

  s->before = before_kline;

  s->def_field = add_conf_field(s, "user", CT_STRING, kline_user, NULL);
  add_conf_field(s, "type", CT_LIST, kline_type, NULL);
  add_conf_field(s, "reason", CT_STRING, NULL, &tmpkill.reason);

  s->after = after_kline;
}
