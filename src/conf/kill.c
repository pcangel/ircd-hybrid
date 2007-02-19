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
#include "server.h"
#include "ircd.h"
#include "parse_aline.h"
#include "user.h"

dlink_list rkline_confs = {NULL, NULL, 0};
int acb_type_kline;

static struct KillConf tmpkill = {{0}, 0};
static dlink_node *hreset, *hexpire, *hbanned, *hverify;
static struct ConfStoreField kline_fields[] =
{
  { "user", CSF_STRING },
  { "host", CSF_STRING },
  { "reason", CSF_STRING },
  { "oper_reason", CSF_STRING },
  { NULL, CSF_STRING },
  { "oper", CSF_STRING },
  { "added", CSF_NUMBER },
  { NULL, 0 }
};
static struct ConfStore kline_store = {"kline", kline_fields};
static struct ConfStore rkline_store = {"rkline", kline_fields};

static int write_perm_kline(struct KillConf *, const char *);

static void do_report_kline(struct KillConf *, struct Client *);
static void do_report_tkline(struct KillConf *, struct Client *);

/*
 * free_kline()
 *
 * Frees a KillConf item.
 *
 * inputs: pointer to KillConf
 * output: none
 */
void
free_kline(struct KillConf *conf)
{
  MyFree(conf->regexuser);
  MyFree(conf->regexhost);
  MyFree(conf->oper_reason);
  MyFree(conf->reason);
  acb_generic_free(&conf->access);
}

/*
 * free_tmpkill()
 *
 * Called before parsing a kill{} block.
 *
 * inputs: none
 * output: none
 */
static void
free_tmpkill(void)
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

static int
commit_tmpkill(const char **errptr)
{
  struct KillConf *conf;

  if (!tmpkill.access.user || !tmpkill.access.host)
  {
    free_tmpkill();
    *errptr = "Missing user/host";
    return 0;
  }

  if (tmpkill.access.type == -1)
    if (!(tmpkill.regexuser = ircd_pcre_compile(tmpkill.access.user, errptr))
     || !(tmpkill.regexhost = ircd_pcre_compile(tmpkill.access.host, errptr)))
    {
      free_tmpkill();
      return 0;
    }

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
  return 1;
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
  const char *errptr = NULL;
  const char *type = (tmpkill.access.type == -1) ? "RK-line" : "K-line";

  if (! commit_tmpkill(&errptr))
    parse_error("Failed to add %s: %s", type, errptr);
}

/*
 * load_klines()
 *
 * Loads permanent klines from external storage.
 *
 * inputs: none
 * output: none
 */
static void *
load_klines(va_list args)
{
  const char *errptr = NULL;

  while (execute_callback(read_conf_store, kline_store, &tmpkill.access.user,
                          &tmpkill.access.host, &tmpkill.reason,
                          &tmpkill.oper_reason, NULL, NULL, NULL))
  {
    tmpkill.access.type = acb_type_kline;
    if (! commit_tmpkill(&errptr))
      ilog(L_ERROR, "Failed to load K-line from conf store: %s", errptr);
  }

  while (execute_callback(read_conf_store, rkline_store, &tmpkill.access.user,
                          &tmpkill.access.host, &tmpkill.reason,
                          &tmpkill.oper_reason, NULL, NULL, NULL))
  {
    tmpkill.access.type = -1;
    if (! commit_tmpkill(&errptr))
      ilog(L_ERROR, "Failed to load RK-line from conf store: %s", errptr);
  }

  return pass_callback(hverify);
}

static void
add_line(struct Client *source_p, char *type, char *user, char *host,
         char *reason, char *oper_reason, int tkline_time)
{
  const char *errptr = NULL;

  DupString(tmpkill.access.user, user);
  DupString(tmpkill.access.host, host);

  tmpkill.reason = a_line_format_reason(reason, type, tkline_time);
  DupString(tmpkill.oper_reason, oper_reason);
  tmpkill.access.expires = CurrentTime + tkline_time;

  // We have to do this first, as commit_tmpkill() zeroes out tmpkill :/
  if (!tkline_time && write_perm_kline(&tmpkill, get_oper_name(source_p)))
    sendto_one(source_p, ":%s NOTICE %s :Added %s [%s@%s] to storage",
               me.name, source_p->name, type, user, host);

  if (commit_tmpkill(&errptr))
    announce_a_line(source_p, type, tkline_time, reason, oper_reason,
                    "%s@%s", user, host);
  else
    sendto_one(source_p, ":%s NOTICE %s :Failed to add %s: %s",
               me.name, source_p->name, type, errptr);
}

void
add_rkline(struct Client *source_p, char *user, char *host, char *reason,
           char *oper_reason, int tkline_time)
{
  tmpkill.access.type = -1;
  add_line(source_p, "RK-Line", user, host, reason, oper_reason, tkline_time);
}

void
add_kline(struct Client *source_p, char *user, char *host, char *reason,
          char *oper_reason, int tkline_time)
{
  tmpkill.access.type = acb_type_kline;
  add_line(source_p, "K-Line", user, host, reason, oper_reason, tkline_time);
  rehashed_klines = 1;
}

/*
 * write_perm_kline()
 *
 * Saves a permanent K-line into an external store.
 *
 * inputs:
 *   conf     -  pointer to struct KillConf
 *   oper     -  oper who issued the K-line
 * output: 0 on error
 */
static int
write_perm_kline(struct KillConf *conf, const char *oper)
{
  struct ConfStore *store;

  if (conf->access.type == acb_type_kline)
    store = &kline_store;
  else if (conf->access.type == -1)
    store = &rkline_store;
  else
    return 0;

  return !!execute_callback(append_conf_store, store, conf->access.user,
                            conf->access.host, conf->reason, conf->oper_reason,
                            smalldate(CurrentTime), oper, CurrentTime);
}

/*
 * delete_perm_kline()
 *
 * Deletes a permanent K-line from an external store.
 *
 * inputs: pointer to struct KillConf
 * output: 0 on error
 */
int
delete_perm_kline(struct KillConf *conf)
{
  struct ConfStore *store;

  if (conf->access.type == acb_type_kline)
    store = &kline_store;
  else if (conf->access.type == -1)
    store = &rkline_store;
  else
    return 0;

  return !!execute_callback(delete_conf_store, store, conf->access.user,
                            conf->access.host, NULL, NULL, NULL, NULL, NULL);
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

struct KillConf *
find_exact_rkline(const char *user, const char *host)
{
  dlink_node *ptr;

  DLINK_FOREACH(ptr, rkline_confs.head)
  {
    struct KillConf *conf = ptr->data;
    if (!irccmp(conf->access.host, host) && !irccmp(conf->access.user, user))
      return conf;
  }

  return NULL;
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
static void
do_report_klines(struct Client *client_p, int tkline)
{
  void (* func)(struct KillConf *, struct Client *) = tkline ?
    do_report_tkline : do_report_kline;
  struct KillConf *conf;
  dlink_node *ptr;

  if (General.stats_k_oper_only == 2 && !IsOper(client_p))
    sendto_one(client_p, form_str(ERR_NOPRIVILEGES),
               ID_or_name(&me, client_p->from),
               ID_or_name(client_p, client_p->from));
  else if (General.stats_k_oper_only == 1 && !IsOper(client_p))
  {
    if ((conf = find_kline(client_p->username, client_p->host,
      client_p->sockhost, MyConnect(client_p) ?
      &client_p->localClient->ip : NULL)))
      func(conf, client_p);
  }
  else
  {
    enum_access_confs((ACB_EXAMINE_HANDLER*) func, client_p);
    DLINK_FOREACH(ptr, rkline_confs.head)
      func(ptr->data, client_p);
  }
}

void report_klines(struct Client *client_p) { do_report_klines(client_p, NO); }
void report_tklines(struct Client *client_p) { do_report_klines(client_p, YES); }

static void
do_report_kline(struct KillConf *conf, struct Client *client_p)
{
  if ((conf->access.type == acb_type_kline || conf->access.type == -1) &&
      !conf->access.expires)
    sendto_one(client_p, form_str(RPL_STATSKLINE),
               ID_or_name(&me, client_p->from),
               ID_or_name(client_p, client_p->from),
               (conf->access.type < 0) ? "RK" : "K",
               conf->access.host, conf->access.user, conf->reason,
               (IsOper(client_p) && conf->oper_reason) ?
               conf->oper_reason : "");
}

static void
do_report_tkline(struct KillConf *conf, struct Client *client_p)
{
  if ((conf->access.type == acb_type_kline || conf->access.type == -1) &&
      conf->access.expires)
    sendto_one(client_p, form_str(RPL_STATSKLINE),
               ID_or_name(&me, client_p->from),
               ID_or_name(client_p, client_p->from),
               (conf->access.type < 0) ? "Rk" : "k",
               conf->access.host, conf->access.user, conf->reason,
               (IsOper(client_p) && conf->oper_reason) ?
               conf->oper_reason : "");
}

/*
 * is_client_klined()
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
is_client_klined(va_list args)
{
  struct Client *client = va_arg(args, struct Client *);
  char **type = va_arg(args, char **);
  char **reason = va_arg(args, char **);
  struct KillConf *conf = IsExemptKline(client) ? NULL :
    find_kline(client->username, client->host, client->sockhost,
               &client->localClient->ip);

  if (conf)
  {
    *type = "K-line";
    *reason = conf->reason;
    return conf;
  }

  return pass_callback(hbanned, client, type, reason);
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
  hexpire = install_hook(expire_confs, expire_rklines);
  hbanned = install_hook(is_client_banned, is_client_klined);

  s->before = free_tmpkill;

  s->def_field = add_conf_field(s, "user", CT_STRING, kline_user, NULL);
  add_conf_field(s, "type", CT_LIST, kline_type, NULL);
  add_conf_field(s, "reason", CT_STRING, NULL, &tmpkill.reason);

  s->after = after_kline;

  hverify = install_hook(verify_conf, load_klines);
}
