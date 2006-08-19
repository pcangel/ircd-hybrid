/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_conf.c: Configuration file functions.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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
#include "ircd_defs.h"
#include "parse_aline.h"
#include "s_serv.h"
#include "channel.h"
#include "client.h"
#include "common.h"
#include "hash.h"
#include "ircd.h"
#include "listener.h"
#include "numeric.h"
#include "send.h"
#include "userhost.h"
#include "s_user.h"
#include "channel_mode.h"

static int check_class_limits(struct Client *, int, struct ClassItem *);
static int cidr_limit_reached(int, struct irc_ssaddr *, struct ClassItem *);
static void remove_from_cidr_check(struct irc_ssaddr *, struct ClassItem *);
static void destroy_cidr_class(struct ClassItem *);

/* check_class_limits()
 *
 * inputs       - client pointer
 *              - int exempt or not to limits
 *              - class pointer
 * output       - 0 if limits ok, non 0 if limits not ok
 * side effects	- NONE
 */
static int
check_class_limits(struct Client *client_p, int exempt,
                   struct ClassItem *aclass)
{
  struct ip_entry *ip_found;
  int a_limit_reached = 0;
  int local = 0, global = 0, ident = 0;

  ip_found = find_or_add_ip(&client_p->localClient->ip);
  ip_found->count++;
  SetIpHash(client_p);

  count_user_host(client_p->username, client_p->host,
                  &global, &local, &ident);

  /* XXX blah. go down checking the various silly limits
   * setting a_limit_reached if any limit is reached.
   * - Dianora
   */
  if (MaxTotal(aclass) != 0 && CurrUserCount(aclass) >= MaxTotal(aclass))
    a_limit_reached = 1;
  else if (MaxPerIp(aclass) != 0 && ip_found->count > MaxPerIp(aclass))
    a_limit_reached = 1;
  else if (MaxLocal(aclass) != 0 && local >= MaxLocal(aclass))
    a_limit_reached = 1;
  else if (MaxGlobal(aclass) != 0 && global >= MaxGlobal(aclass))
    a_limit_reached = 1;
  else if (MaxIdent(aclass) != 0 && ident >= MaxIdent(aclass) &&
           client_p->username[0] != '~')
    a_limit_reached = 1;

  if (a_limit_reached)
  {
    if (!exempt)
      return 0;  /* Already at maximum allowed */

    sendto_one(client_p,
               ":%s NOTICE %s :*** Your connection class is full, "
               "but you have exceed_limit = yes;", me.name, client_p->name);
  }

  if (cidr_limit_reached(exempt, &client_p->localClient->ip, aclass))
    return 0;  /* Already at maximum allowed */

  return 1;
}

/*
 * cidr_limit_reached
 *
 * inputs	- int flag allowing exemption of limits
 *		- pointer to the ip to be added
 *		- pointer to the class
 * output	- non zero if limit reached
 *		  0 if limit not reached
 * side effects	-
 */
static int
cidr_limit_reached(int exempt,
		   struct irc_ssaddr *ip, struct ClassItem *aclass)
{
  dlink_node *ptr = NULL;
  struct CidrItem *cidr;

  if (NumberPerCidr(aclass) <= 0)
    return 0;

  if (ip->ss.sin_family == AF_INET)
  {
    if (CidrBitlenIPV4(aclass) <= 0)
      return 0;

    DLINK_FOREACH(ptr, aclass->list_ipv4.head)
    {
      cidr = ptr->data;
      if (match_ipv4(ip, &cidr->mask, CidrBitlenIPV4(aclass)))
      {
        if (!exempt && (cidr->number_on_this_cidr >= NumberPerCidr(aclass)))
          return -1;
        cidr->number_on_this_cidr++;
        return 0;
      }
    }
    cidr = MyMalloc(sizeof(struct CidrItem));
    cidr->number_on_this_cidr = 1;
    cidr->mask = *ip;
    mask_addr(&cidr->mask, CidrBitlenIPV4(aclass));
    dlinkAdd(cidr, &cidr->node, &aclass->list_ipv4);
  }
#ifdef IPV6
  else if (CidrBitlenIPV6(aclass) > 0)
  {
    DLINK_FOREACH(ptr, aclass->list_ipv6.head)
    {
      cidr = ptr->data;
      if (match_ipv6(ip, &cidr->mask, CidrBitlenIPV6(aclass)))
      {
        if (!exempt && (cidr->number_on_this_cidr >= NumberPerCidr(aclass)))
          return -1;
        cidr->number_on_this_cidr++;
        return 0;
      }
    }
    cidr = MyMalloc(sizeof(struct CidrItem));
    cidr->number_on_this_cidr = 1;
    cidr->mask = *ip;
    mask_addr(&cidr->mask, CidrBitlenIPV6(aclass));
    dlinkAdd(cidr, &cidr->node, &aclass->list_ipv6);
  }
#endif
  return 0;
}

/*
 * remove_from_cidr_check
 *
 * inputs	- pointer to the ip to be removed
 *		- pointer to the class
 * output	- NONE
 * side effects	-
 */
static void
remove_from_cidr_check(struct irc_ssaddr *ip, struct ClassItem *aclass)
{
  dlink_node *ptr = NULL;
  dlink_node *next_ptr = NULL;
  struct CidrItem *cidr;

  if (NumberPerCidr(aclass) == 0)
    return;

  if (ip->ss.sin_family == AF_INET)
  {
    if (CidrBitlenIPV4(aclass) <= 0)
      return;

    DLINK_FOREACH_SAFE(ptr, next_ptr, aclass->list_ipv4.head)
    {
      cidr = ptr->data;
      if (match_ipv4(ip, &cidr->mask, CidrBitlenIPV4(aclass)))
      {
	cidr->number_on_this_cidr--;
	if (cidr->number_on_this_cidr == 0)
	{
	  dlinkDelete(ptr, &aclass->list_ipv4);
	  MyFree(cidr);
	  return;
	}
      }
    }
  }
#ifdef IPV6
  else if (CidrBitlenIPV6(aclass) > 0)
  {
    DLINK_FOREACH_SAFE(ptr, next_ptr, aclass->list_ipv6.head)
    {
      cidr = ptr->data;
      if (match_ipv6(ip, &cidr->mask, CidrBitlenIPV6(aclass)))
      {
	cidr->number_on_this_cidr--;
	if (cidr->number_on_this_cidr == 0)
	{
	  dlinkDelete(ptr, &aclass->list_ipv6);
	  MyFree(cidr);
	  return;
	}
      }
    }
  }
#endif
}

static void
rebuild_cidr_list(int aftype, struct ClassItem *oldcl, struct ClassItem *newcl,
                  dlink_list *old_list, dlink_list *new_list, int changed)
{
  dlink_node *ptr;
  struct Client *client_p;

  if (!changed)
  {
    *new_list = *old_list;
    old_list->head = old_list->tail = NULL;
    old_list->length = 0;
    return;
  }

  DLINK_FOREACH(ptr, local_client_list.head)
  {
    client_p = ptr->data;
    if (client_p->localClient->aftype != aftype)
      continue;
    if (client_p->localClient->class == NULL)
      continue;

    if (client_p->localClient->class == oldcl)
      cidr_limit_reached(1, &client_p->localClient->ip, newcl);
  }
}

/*
 * rebuild_cidr_class
 *
 * inputs	- pointer to old conf
 *		- pointer to new_class
 * output	- none
 * side effects	- rebuilds the class link list of cidr blocks
 */
void
rebuild_cidr_class(struct ClassItem *old_class, struct ClassItem *new_class)
{
  if (NumberPerCidr(old_class) > 0 && NumberPerCidr(new_class) > 0)
  {
    if (CidrBitlenIPV4(old_class) > 0 && CidrBitlenIPV4(new_class) > 0)
      rebuild_cidr_list(AF_INET, old_class, new_class,
                        &old_class->list_ipv4, &new_class->list_ipv4,
                        CidrBitlenIPV4(old_class) != CidrBitlenIPV4(new_class));

#ifdef IPV6
    if (CidrBitlenIPV6(old_class) > 0 && CidrBitlenIPV6(new_class) > 0)
      rebuild_cidr_list(AF_INET6, old_class, new_class,
                        &old_class->list_ipv6, &new_class->list_ipv6,
                        CidrBitlenIPV6(old_class) != CidrBitlenIPV6(new_class));
#endif
  }

  destroy_cidr_class(old_class);
}

/*
 * destroy_cidr_class
 *
 * inputs	- pointer to class
 * output	- none
 * side effects	- completely destroys the class link list of cidr blocks
 */
static void
destroy_cidr_class(struct ClassItem *aclass)
{
  destroy_cidr_list(&aclass->list_ipv4);
  destroy_cidr_list(&aclass->list_ipv6);
}
