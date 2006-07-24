/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  shared.c: Defines the shared{} and cluster{} blocks of ircd.conf.
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

dlink_list cluster_confs = {0};
dlink_list shared_confs = {0};

static dlink_node *hreset;
static char *tmpserver = NULL;
static char tmpuser[USERLEN + 1];
static char tmphost[HOSTLEN + 1];
static int tmpflags;
// TODO: These should be modularised like acb_types
static const struct FlagMapping {
  const char *name;
  unsigned int flag;
} flag_mappings[] = {
  {"kline", SHARED_KLINE},
  {"tkline", SHARED_TKLINE},
  {"unkline", SHARED_UNKLINE},
  {"xline", SHARED_XLINE},
  {"txline", SHARED_TXLINE},
  {"unxline", SHARED_UNXLINE},
  {"resv", SHARED_RESV},
  {"tresv", SHARED_TRESV},
  {"unresv", SHARED_UNRESV},
  {"locops", SHARED_LOCOPS},
  {NULL, 0}
};

/*
 * reset_shared()
 *
 * Frees all shared/cluster blocks before a rehash.
 *
 * inputs: none
 * output: none
 */
static void *
reset_shared(va_list args)
{
  struct SharedConf *shared;
  struct ClusterConf *cluster;

  while (shared_confs.head)
  {
    shared = shared_confs.head->data;
    dlinkDelete(&shared->node, &shared_confs);

    MyFree(shared->server);
    MyFree(shared->user);
    MyFree(shared->host);
    MyFree(shared);
  }

  while (cluster_confs.head)
  {
    cluster = cluster_confs.head->data;
    dlinkDelete(&cluster->node, &cluster_confs);

    MyFree(cluster->server);
    MyFree(cluster);
  }

  return pass_callback(hreset);
}

/*
 * clear_temp()
 *
 * Clears temporary storage before and after parsing a single shared/cluster block.
 *
 * inputs: none
 * output: none
 */
static void
clear_temp(void)
{
  MyFree(tmpserver);
  tmpserver = NULL;
  tmpuser[0] = tmphost[0] = 0;
  tmpflags = 0;
}

/*
 * parse_user()
 *
 * Parses the "user=" field.
 *
 * inputs: user@host mask
 * output: none
 */
static void
parse_user(void *value, void *unused)
{
  struct split_nuh_item uh;

  uh.nuhmask = value;
  uh.nickptr = NULL;
  uh.userptr = tmpuser;
  uh.hostptr = tmphost;

  uh.nicksize = 0;
  uh.usersize = sizeof(tmpuser);
  uh.hostsize = sizeof(tmphost);

  split_nuh(&uh);
}

/*
 * parse_type()
 *
 * Parses the "type=" field.
 *
 * inputs: pointer to a dlink list of string
 * output: none
 */
static void
parse_type(void *list, void *unused)
{
  const struct FlagMapping *p;
  int errors = NO;
  dlink_node *ptr;

  tmpflags = 0;

  DLINK_FOREACH(ptr, ((dlink_list *)list)->head)
  {
    const char *str = ptr->data;
    int found = NO, all = !irccmp(str, "all");

    for (p = flag_mappings; p->name; ++p)
      if (all || !irccmp(str, p->name))
      {
        found = YES;
        tmpflags |= p->flag;
        if (!all)
          break;
      }

    if (!found)
      errors = YES;
  }

  if (errors)
    parse_error("Invalid type specifier, check your syntax");
}

/*
 * after_shared()
 *
 * Configures a single shared{} block.
 *
 * inputs: none
 * output: none
 */
static void
after_shared(void)
{
  struct SharedConf *conf;
  int bits;

  if (!tmpflags)
  {
    MyFree(tmpserver);
    return;
  }

  conf = MyMalloc(sizeof(*conf));

  if (tmpserver)
    conf->server = tmpserver;
  else
    DupString(conf->server, "*");
  tmpserver = NULL;

  DupString(conf->user, tmpuser[0] ? tmpuser : "*");
  DupString(conf->host, tmphost[0] ? tmphost : "*");
  if (parse_netmask(conf->host, &conf->ip, &bits) != HM_HOST)
    conf->ip.ss_port = bits;
  conf->type = tmpflags;

  dlinkAddTail(conf, &conf->node, &shared_confs);
}

/*
 * after_cluster()
 *
 * Configures a single cluster{} block.
 *
 * inputs: none
 * output: none
 */
static void
after_cluster(void)
{
  struct ClusterConf *conf;

  if (!tmpflags)
    return;

  conf = MyMalloc(sizeof(*conf));
  if (tmpserver)
    conf->server = tmpserver;
  else
    DupString(conf->server, "*");

  conf->type = tmpflags;
  dlinkAddTail(conf, &conf->node, &cluster_confs);
}

/*
 * find_shared()
 *
 * Looks for a shared{} entry.
 *
 * inputs:
 *   serv  -  server that is trying to feed us
 *   user  -  username of the oper
 *   host  -  hostname of the oper
 *   ip    -  IP address of the oper
 *   type  -  operation type, e.g. SHARED_KLINE
 * output: pointer to a shared conf or NULL
 */
struct SharedConf *
find_shared(const char *serv, const char *user, const char *host,
            const struct irc_ssaddr *ip, int type)
{
  dlink_node *ptr;
  struct SharedConf *conf;

  DLINK_FOREACH(ptr, shared_confs.head)
  {
    conf = ptr->data;
    if (!(conf->type & type) || !match(conf->server, serv) ||
        !match(conf->user, user))
      continue;

    if (conf->ip.ss.sin_family != AF_UNSPEC && (
#ifdef IPV6
        (conf->ip.ss.sin_family == AF_INET6) ? match_ipv6 :
#endif
        match_ipv4)(ip, &conf->ip, conf->ip.ss_port))
      return conf;
    if (match(conf->host, host))
      return conf;
  }

  return NULL;
}

/*
 * init_shared()
 *
 * Defines the shared{} and cluster{} conf sections.
 *
 * inputs: none
 * output: none
 */
void
init_shared(void)
{
  struct ConfSection *s = add_conf_section("shared", 2);
  struct ConfSection *s2 = add_conf_section("cluster", 2);

  hreset = install_hook(reset_conf, reset_shared);

  s->before = s2->before = clear_temp;

  add_conf_field(s, "name", CT_STRING, NULL, &tmpserver);
  add_conf_field(s2, "name", CT_STRING, NULL, &tmpserver);
  add_conf_field(s, "user", CT_STRING, parse_user, NULL);
  add_conf_field(s, "type", CT_LIST, parse_type, NULL);
  add_conf_field(s2, "type", CT_LIST, parse_type, NULL);

  s->after = after_shared;
  s2->after = after_cluster;
}
