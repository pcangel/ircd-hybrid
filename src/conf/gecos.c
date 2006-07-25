/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  gecos.c: Defines the gecos{} block of ircd.conf.
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

// TODO: Add callbacks for (r)xline.conf support with default handlers

dlink_list gecos_confs = {0};

static dlink_node *hreset, *hexpire, *hbanned;
static struct GecosConf tmpgecos = {0};
static char regex_flag = NO;

/*
 * free_xlines()
 *
 * Frees a subset of all gecos bans.
 *
 * inputs: whether we free expired (YES) or all permanent (NO) bans
 * output: none
 */
static void
free_xlines(int expiring)
{
  dlink_node *ptr, *ptr_next;
  struct GecosConf *xline;

  DLINK_FOREACH_SAFE(ptr, ptr_next, gecos_confs.head)
  {
    xline = ptr->data;
    if (expiring ? (xline->expires && xline->expires <= CurrentTime) :
        (xline->expires == 0))
    {
      if (expiring)
        sendto_realops_flags(UMODE_ALL, L_ALL,
          "Temporary %s for [%s] expired", "gecos ban", xline->mask);

      dlinkDelete(ptr->data, &gecos_confs);
      MyFree(xline->mask);
      MyFree(xline->reason);
      MyFree(xline->regex);
      MyFree(xline);
    }
  }
}

/*
 * reset_gecos()
 *
 * Sets up default values before a rehash.
 *
 * inputs: none
 * output: none
 */
static void *
reset_gecos(va_list args)
{
  free_xlines(NO);
  return pass_callback(hreset);
}

/*
 * expire_resv()
 *
 * Frees expired resvs.
 *
 * inputs: none
 * output: none
 */
static void *
expire_gecos(va_list args)
{
  free_xlines(YES);
  return pass_callback(hexpire);
}

/*
 * find_gecos_ban()
 *
 * Traverses the list looking for a matching gecos ban.
 *
 * inputs: gecos string to check
 * output: pointer to matching GecosConf or NULL
 */
struct GecosConf *
find_gecos_ban(const char *what)
{
  dlink_node *ptr;
  struct GecosConf *conf;

  DLINK_FOREACH(ptr, gecos_confs.head)
  {
    conf = ptr->data;
    if (conf->regex ? !ircd_pcre_exec(conf->regex, what) :
        match(conf->mask, what))
      return conf;
  }

  return NULL;
}

struct GecosConf *
find_exact_xline(const char *what, int regex)
{
  dlink_node *ptr;
  struct GecosConf *conf;

  DLINK_FOREACH(ptr, gecos_confs.head)
  {
    conf = ptr->data;
    if (!!conf->regex != regex)
      continue;
    if (!irccmp(conf->mask, what))
      return conf;
  }

  return NULL;
}

/*
 * before_gecos()
 *
 * Called before parsing a single gecos{} block.
 *
 * inputs: none
 * output: none
 */
static void
before_gecos(void)
{
  MyFree(tmpgecos.mask);
  MyFree(tmpgecos.reason);
  MyFree(tmpgecos.regex);
  tmpgecos.mask = tmpgecos.reason = NULL;
  tmpgecos.regex = NULL;
  regex_flag = NO;
}

/*
 * parse_type()
 *
 * Parses the "type=" field.
 *
 * inputs: pointer to a dlink list of strings
 * output: none
 */
static void
parse_type(void *list, void *unused)
{
  dlink_node *ptr;

  DLINK_FOREACH(ptr, ((dlink_list *) list)->head)
    if (!ircncmp(ptr->data, "regex", 5))
      regex_flag = YES;
    else
    {
      parse_error("Syntax error");
      break;
    }
}

/*
 * after_gecos()
 *
 * Called after parsing a single gecos{} block.
 *
 * inputs: none
 * output: none
 */
static void
after_gecos(void)
{
  struct GecosConf *conf;
  const char *errptr = NULL;

  if (!tmpgecos.mask)
  {
    parse_error("Incomplete gecos{} block");
    before_gecos();
    return;
  }

  if (regex_flag)
    if (!(tmpgecos.regex = ircd_pcre_compile(tmpgecos.mask, &errptr)))
    {
      parse_error("Failed to add regular expression based gecos ban: %s",
        errptr);
      before_gecos();
      return;
    }

  if (!tmpgecos.reason)
    DupString(tmpgecos.reason, "No reason");

  conf = MyMalloc(sizeof(*conf));
  memcpy(conf, &tmpgecos, sizeof(*conf));
  memset(&tmpgecos, 0, sizeof(tmpgecos));
  dlinkAddTail(conf, &conf->node, &gecos_confs);
}

/*
 * is_client_xlined()
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
is_client_xlined(va_list args)
{
  struct Client *client = va_arg(args, struct Client *);
  char **type = va_arg(args, char **);
  char **reason = va_arg(args, char **);
  struct GecosConf *conf = IsExemptKline(client) ? NULL :
    find_gecos_ban(client->info);

  if (conf)
  {
    *type = "X-line";
    *reason = conf->reason;
    conf->count++;
    return conf;
  }

  return pass_callback(hbanned, client, type, reason);
}

/*
 * report_gecos()
 *
 * Sends a /stats X reply to the given client.
 *
 * inputs: client pointer
 * output: none
 */
void
report_gecos(struct Client *source_p)
{
  dlink_node *ptr;
  struct GecosConf *conf;
  char buf[3];

  DLINK_FOREACH(ptr, gecos_confs.head)
  {
    conf = ptr->data;

    strcpy(buf, conf->regex ? "R" : "");
    strcat(buf, conf->expires ? "x" : "X");

    sendto_one(source_p, form_str(RPL_STATSXLINE),
               ID_or_name(&me, source_p->from),
               ID_or_name(source_p, source_p->from), buf,
               conf->count, conf->mask, conf->reason ?
               conf->reason : "No reason");
  }
}

/*
 * init_gecos()
 *
 * Defines the gecos{} conf section.
 *
 * inputs: none
 * output: none
 */
void
init_gecos(void)
{
  struct ConfSection *s = add_conf_section("gecos", 2);

  hreset = install_hook(reset_conf, reset_gecos);
  hexpire = install_hook(expire_confs, expire_gecos);
  hbanned = install_hook(is_client_banned, is_client_xlined);

  s->before = before_gecos;

  s->def_field = add_conf_field(s, "mask", CT_STRING, NULL, &tmpgecos.mask);
  add_conf_field(s, "reason", CT_STRING, NULL, &tmpgecos.reason);
  add_conf_field(s, "type", CT_LIST, parse_type, NULL);

  s->after = after_gecos;
}
