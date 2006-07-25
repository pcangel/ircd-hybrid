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

struct Callback *client_check_cb = NULL;

/* internally defined functions */
static void garbage_collect_ip_entries(void);
static int hash_ip(const struct irc_ssaddr *);
static int verify_access(struct Client *, const char *, struct AccessItem **);
static struct ip_entry *find_or_add_ip(const struct irc_ssaddr *);
static int check_class_limits(struct Client *, int, struct ClassItem *);

/*
 * bit_len
 */
static int cidr_limit_reached(int, struct irc_ssaddr *, struct ClassItem *);
static void remove_from_cidr_check(struct irc_ssaddr *, struct ClassItem *);
static void destroy_cidr_class(struct ClassItem *);

/* usually, with hash tables, you use a prime number...
 * but in this case I am dealing with ip addresses,
 * not ascii strings.
 */
#define IP_HASH_SIZE 0x1000

struct ip_entry
{
  struct irc_ssaddr ip;
  int count;
  time_t last_attempt;
  struct ip_entry *next;
};

static struct ip_entry *ip_hash_table[IP_HASH_SIZE];
static BlockHeap *ip_entry_heap = NULL;
static int ip_entries_count = 0;

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

/* init_ip_hash_table()
 *
 * inputs               - NONE
 * output               - NONE
 * side effects         - allocate memory for ip_entry(s)
 *			- clear the ip hash table
 */
void
init_ip_hash_table(void)
{
  ip_entry_heap = BlockHeapCreate("ip", sizeof(struct ip_entry),
    2 * hard_fdlimit);
  memset(ip_hash_table, 0, sizeof(ip_hash_table));
}

/* find_or_add_ip()
 *
 * inputs       - pointer to struct irc_ssaddr
 * output       - pointer to a struct ip_entry
 * side effects -
 *
 * If the ip # was not found, a new struct ip_entry is created, and the ip
 * count set to 0.
 */
static struct ip_entry *
find_or_add_ip(const struct irc_ssaddr *ip_in)
{
  struct ip_entry *ptr = NULL;
  int hash_index = hash_ip(ip_in), res;
  const struct sockaddr_in *v4 = (const struct sockaddr_in *)ip_in, *ptr_v4;
#ifdef IPV6
  const struct sockaddr_in6 *v6 = (const struct sockaddr_in6 *)ip_in, *ptr_v6;
#endif

  for (ptr = ip_hash_table[hash_index]; ptr; ptr = ptr->next)
  {
#ifdef IPV6
    if (ptr->ip.ss.sin_family != ip_in->ss.sin_family)
      continue;
    if (ip_in->ss.sin_family == AF_INET6)
    {
      ptr_v6 = (struct sockaddr_in6 *)&ptr->ip;
      res = memcmp(&v6->sin6_addr, &ptr_v6->sin6_addr, sizeof(struct in6_addr));
    }
    else
#endif
    {
      ptr_v4 = (struct sockaddr_in *)&ptr->ip;
      res = memcmp(&v4->sin_addr, &ptr_v4->sin_addr, sizeof(struct in_addr));
    }

    if (res == 0)
    {
      /* Found entry already in hash, return it. */
      return ptr;
    }
  }

  if (ip_entries_count >= 2 * hard_fdlimit)
    garbage_collect_ip_entries();

  ptr = BlockHeapAlloc(ip_entry_heap);
  ++ip_entries_count;
  memcpy(&ptr->ip, ip_in, sizeof(struct irc_ssaddr));

  ptr->next = ip_hash_table[hash_index];
  ip_hash_table[hash_index] = ptr;

  return ptr;
}

/* remove_one_ip()
 *
 * inputs        - unsigned long IP address value
 * output        - NONE
 * side effects  - The ip address given, is looked up in ip hash table
 *                 and number of ip#'s for that ip decremented.
 *                 If ip # count reaches 0 and has expired,
 *		   the struct ip_entry is returned to the ip_entry_heap
 */
void
remove_one_ip(struct irc_ssaddr *ip_in)
{
  struct ip_entry *ptr;
  struct ip_entry *last_ptr = NULL;
  int hash_index = hash_ip(ip_in), res;
  struct sockaddr_in *v4 = (struct sockaddr_in *)ip_in, *ptr_v4;
#ifdef IPV6
  struct sockaddr_in6 *v6 = (struct sockaddr_in6 *)ip_in, *ptr_v6;
#endif

  for (ptr = ip_hash_table[hash_index]; ptr; ptr = ptr->next)
  {
#ifdef IPV6
    if (ptr->ip.ss.sin_family != ip_in->ss.sin_family)
      continue;
    if (ip_in->ss.sin_family == AF_INET6)
    {
      ptr_v6 = (struct sockaddr_in6 *)&ptr->ip;
      res = memcmp(&v6->sin6_addr, &ptr_v6->sin6_addr, sizeof(struct in6_addr));
    }
    else
#endif
    {
      ptr_v4 = (struct sockaddr_in *)&ptr->ip;
      res = memcmp(&v4->sin_addr, &ptr_v4->sin_addr, sizeof(struct in_addr));
    }
    if (res)
      continue;
    if (ptr->count > 0)
      ptr->count--;
    if (ptr->count == 0 &&
	(CurrentTime-ptr->last_attempt) >= ConfigFileEntry.throttle_time)
    {
      if (last_ptr != NULL)
	last_ptr->next = ptr->next;
      else
	ip_hash_table[hash_index] = ptr->next;

      BlockHeapFree(ip_entry_heap, ptr);
      ip_entries_count--;
      return;
    }
    last_ptr = ptr;
  }
}

/* hash_ip()
 *
 * input        - pointer to an irc_inaddr
 * output       - integer value used as index into hash table
 * side effects - hopefully, none
 */
static int
hash_ip(const struct irc_ssaddr *addr)
{
  if (addr->ss.sin_family == AF_INET)
  {
    const struct sockaddr_in *v4 = (const struct sockaddr_in *)addr;
    int hash;
    u_int32_t ip;

    ip   = ntohl(v4->sin_addr.s_addr);
    hash = ((ip >> 12) + ip) & (IP_HASH_SIZE-1);
    return hash;
  }
#ifdef IPV6
  else
  {
    int hash;
    const struct sockaddr_in6 *v6 = (const struct sockaddr_in6 *)addr;
    const u_int32_t *ip = (const u_int32_t *)&v6->sin6_addr.s6_addr;

    hash  = ip[0] ^ ip[3];
    hash ^= hash >> 16;  
    hash ^= hash >> 8;   
    hash  = hash & (IP_HASH_SIZE - 1);
    return hash;
  }
#else
  return 0;
#endif
}

/* count_ip_hash()
 *
 * inputs        - pointer to counter of number of ips hashed 
 *               - pointer to memory used for ip hash
 * output        - returned via pointers input
 * side effects  - NONE
 *
 * number of hashed ip #'s is counted up, plus the amount of memory
 * used in the hash.
 */
void
count_ip_hash(int *number_ips_stored, size_t *mem_ips_stored)
{
  struct ip_entry *ptr;
  int i;

  *number_ips_stored = 0;
  *mem_ips_stored    = 0;

  for (i = 0; i < IP_HASH_SIZE; i++)
  {
    for (ptr = ip_hash_table[i]; ptr; ptr = ptr->next)
    {
      *number_ips_stored += 1;
      *mem_ips_stored += sizeof(struct ip_entry);
    }
  }
}

/* garbage_collect_ip_entries()
 *
 * input	- NONE
 * output	- NONE
 * side effects	- free up all ip entries with no connections
 */
static void
garbage_collect_ip_entries(void)
{
  struct ip_entry *ptr;
  struct ip_entry *last_ptr;
  struct ip_entry *next_ptr;
  int i;

  for (i = 0; i < IP_HASH_SIZE; i++)
  {
    last_ptr = NULL;

    for (ptr = ip_hash_table[i]; ptr; ptr = next_ptr)
    {
      next_ptr = ptr->next;

      if (ptr->count == 0 &&
          (CurrentTime - ptr->last_attempt) >= ConfigFileEntry.throttle_time)
      {
        if (last_ptr != NULL)
          last_ptr->next = ptr->next;
        else
          ip_hash_table[i] = ptr->next;
        BlockHeapFree(ip_entry_heap, ptr);
        ip_entries_count--;
      }
      else
        last_ptr = ptr;
    }
  }
}

/* conf_connect_allowed()
 *
 * inputs	- pointer to inaddr
 *		- int type ipv4 or ipv6
 * output	- BANNED or accepted
 * side effects	- none
 */
int
conf_connect_allowed(const struct irc_ssaddr *addr)
{
  struct ip_entry *ip_found = NULL;
  struct AccessItem *aconf = find_dline_conf(addr, addr->ss.sin_family);

  /* DLINE exempt also gets you out of static limits/pacing... */
  if (aconf && (aconf->status & CONF_EXEMPTDLINE))
    return 0;

  if (aconf != NULL)
    return BANNED_CLIENT;

  ip_found = find_or_add_ip(addr);

  if ((CurrentTime - ip_found->last_attempt) <
      ConfigFileEntry.throttle_time)
  {
    ip_found->last_attempt = CurrentTime;
    return TOO_FAST;
  }

  ip_found->last_attempt = CurrentTime;
  return 0;
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
