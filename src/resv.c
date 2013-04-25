/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  resv.c: Functions to reserve(jupe) a nick/channel.
 *
 *  Copyright (C) 2001-2002 Hybrid Development Team
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
#include "list.h"
#include "ircd.h"
#include "send.h"
#include "client.h"   
#include "memory.h"
#include "numeric.h"
#include "resv.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd_defs.h"
#include "s_misc.h"
#include "conf.h"
#include "conf_db.h"
#include "channel.h"
#include "hostmask.h"

dlink_list resv_channel_list = { NULL, NULL, 0 };


/* create_resv()
 *
 * inputs	- name of nick to create resv for
 *		- reason for resv
 *		- 1 if from ircd.conf, 0 if from elsewhere
 * output	- pointer to struct ResvNick
 * side effects	-
 */
struct MaskItem *
create_resv(const char *name, const char *reason, const dlink_list *list)
{
  struct MaskItem *conf = NULL;
  enum maskitem_type type;

  if (name == NULL || reason == NULL)
    return NULL;

  if (IsChanPrefix(*name))
    type = CONF_CRESV;
  else
    type = CONF_NRESV;

  if (find_exact_name_conf(type, NULL, name, NULL, NULL))
    return NULL;

  conf = conf_make(type);
  conf->name = xstrdup(name);
  conf->reason = xstrndup(reason, IRCD_MIN(strlen(reason), REASONLEN));

  if (list)
  {
    if (strlen(name) == 2 && IsAlpha(*(name + 1) && IsAlpha(*(name + 2))))
    {
      struct exempt *exptr = MyMalloc(sizeof(*exptr));

      exptr->name = xstrdup(name);
      exptr->coid = GeoIP_id_by_code(name);
      dlinkAdd(exptr, &exptr->node, &conf->exempt_list);
    }
    else
    {
      dlink_node *ptr = NULL;

      DLINK_FOREACH(ptr, list->head)
      {
        char nick[NICKLEN + 1];
        char user[USERLEN + 1];
        char host[HOSTLEN + 1];
        struct split_nuh_item nuh;
        struct exempt *exptr = NULL;

        nuh.nuhmask  = ptr->data;
        nuh.nickptr  = nick;
        nuh.userptr  = user;
        nuh.hostptr  = host;

        nuh.nicksize = sizeof(name);
        nuh.usersize = sizeof(user);
        nuh.hostsize = sizeof(host);

        split_nuh(&nuh);

        exptr = MyMalloc(sizeof(*exptr));
        exptr->name = xstrdup(name);
        exptr->user = xstrdup(user);
        exptr->host = xstrdup(host);
        exptr->type = parse_netmask(host, &exptr->addr, &exptr->bits);
        dlinkAdd(exptr, &exptr->node, &conf->exempt_list);
      }
    }
  }

  return conf;
}

int
resv_find_exempt(const struct Client *who, const struct MaskItem *conf)
{
  const dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, conf->exempt_list.head)
  {
    const struct exempt *exptr = ptr->data;

    if (exptr->coid)
    {
      if (exptr->coid == who->localClient->country_id)
        return 1;
    }
    else if (!match(exptr->name, who->name) && !match(exptr->user, who->username))
    {
      switch (exptr->type)
      {
        case HM_HOST:
          if (!match(exptr->host, who->host) || !match(exptr->host, who->sockhost))
            return 1;
          break;
        case HM_IPV4:
          if (who->localClient->aftype == AF_INET)
            if (match_ipv4(&who->localClient->ip, &exptr->addr, exptr->bits))
              return 1;
          break;
#ifdef IPV6
        case HM_IPV6:
          if (who->localClient->aftype == AF_INET6)
            if (match_ipv6(&who->localClient->ip, &exptr->addr, exptr->bits))
              return 1;
          break;
#endif
        default:
          assert(0);
      }
    }
  }

  return 0;
}

/* match_find_resv()
 *
 * inputs       - pointer to name
 * output       - pointer to a struct ResvChannel
 * side effects - Finds a reserved channel whose name matches 'name',
 *                if can't find one returns NULL.
 */
struct MaskItem *
match_find_resv(const char *name)
{
  dlink_node *ptr = NULL;

  if (EmptyString(name))
    return NULL;

  DLINK_FOREACH(ptr, resv_channel_list.head)
  {
    struct MaskItem *conf = ptr->data;

    if (!match(conf->name, name))
      return conf;
  }

  return NULL;
}

/* report_resv()
 *
 * inputs	- pointer to client pointer to report to.
 * output	- NONE
 * side effects	- report all resvs to client.
 */
void
report_resv(struct Client *source_p)
{
  dlink_node *ptr = NULL;
  struct MaskItem *conf = NULL;

  DLINK_FOREACH(ptr, resv_channel_list.head)
  {
    conf = ptr->data;
    sendto_one(source_p, form_str(RPL_STATSQLINE),
               me.name, source_p->name,
	       conf->until ? 'q' : 'Q', conf->count,
	       conf->name, conf->reason);
  }

  DLINK_FOREACH(ptr, nresv_items.head)
  {
    conf = ptr->data;
    sendto_one(source_p, form_str(RPL_STATSQLINE),
               me.name, source_p->name,
	       conf->until ? 'q' : 'Q', conf->count,
	       conf->name, conf->reason);
  }
}

/* valid_wild_card_simple()
 *
 * inputs	- data to check for sufficient non-wildcard characters
 * outputs	- 1 if valid, else 0
 * side effects	- none
 */
int
valid_wild_card_simple(const char *data)
{
  const unsigned char *p = (const unsigned char *)data;
  int nonwild = 0;

  while (*p != '\0')
  {
    if ((*p == '\\' && *++p) || (*p && !IsMWildChar(*p)))
      if (++nonwild == ConfigFileEntry.min_nonwildcard_simple)
        return 1;
    if (*p != '\0')
      ++p;
  }

  return 0;
}
