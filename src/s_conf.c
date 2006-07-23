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
#include "resv.h"
#include "channel.h"
#include "client.h"
#include "common.h"
#include "hash.h"
#include "ircd.h"
#include "listener.h"
#include "hostmask.h"
#include "numeric.h"
#include "send.h"
#include "userhost.h"
#include "s_user.h"
#include "channel_mode.h"

struct Callback *client_check_cb = NULL;

/* internally defined functions */
static void lookup_confhost(struct ConfItem *);
static void garbage_collect_ip_entries(void);
static int hash_ip(const struct irc_ssaddr *);
static int verify_access(struct Client *, const char *, struct AccessItem **);
static struct ip_entry *find_or_add_ip(const struct irc_ssaddr *);
static int check_class_limits(struct Client *, int, struct ClassItem *);
static void free_aconf_items(struct ConfItem *, dlink_list *);
static void free_match_items(struct ConfItem *, dlink_list *);

/*
 * bit_len
 */
static int cidr_limit_reached(int, struct irc_ssaddr *, struct ClassItem *);
static void remove_from_cidr_check(struct irc_ssaddr *, struct ClassItem *);
static void destroy_cidr_class(struct ClassItem *);

static void flags_to_ascii(unsigned int, const unsigned int[], char *, int);

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

/* conf_dns_callback()
 *
 * inputs	- pointer to struct AccessItem
 *		- pointer to DNSReply reply
 * output	- none
 * side effects	- called when resolver query finishes
 * if the query resulted in a successful search, hp will contain
 * a non-null pointer, otherwise hp will be null.
 * if successful save hp in the conf item it was called with
 */
static void
conf_dns_callback(void *vptr, struct DNSReply *reply)
{
  struct AccessItem *aconf = (struct AccessItem *)vptr;
  struct ConfItem *conf;

  MyFree(aconf->dns_query);
  aconf->dns_query = NULL;

  if (reply != NULL)
    memcpy(&aconf->ipnum, &reply->addr, sizeof(reply->addr));
  else
  {
    ilog(L_NOTICE, "Host not found: %s, ignoring connect{} block",
         aconf->host);
    conf = aconf->conf_ptr;
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "Ignoring connect{} block for %s - host not found",
			 conf->name);
    delete_conf_item(conf);
  }
}

/* conf_dns_lookup()
 *
 * do a nameserver lookup of the conf host
 * if the conf entry is currently doing a ns lookup do nothing, otherwise
 * allocate a dns_query and start ns lookup.
 */
static void
conf_dns_lookup(struct AccessItem *aconf)
{
  if (aconf->dns_query == NULL)
  {
    aconf->dns_query = MyMalloc(sizeof(struct DNSQuery));
    aconf->dns_query->ptr = aconf;
    aconf->dns_query->callback = conf_dns_callback;
    gethost_byname(aconf->host, aconf->dns_query);
  }
}

/* lookup_confhost()
 *
 * inputs	- pointer to ConfItem
 * output	- NONE
 * side effects	- start DNS lookups of all hostnames in the conf
 * line and convert an IP addresses in a.b.c.d number for to IP#s.
 */
static void
lookup_confhost(struct ConfItem *conf)
{
  struct AccessItem *aconf;
  struct addrinfo hints, *res;

  aconf = &conf->conf.AccessItem;

  if (EmptyString(aconf->host) || EmptyString(aconf->user))
  {
    ilog(L_ERROR, "Host/server name error: (%s) (%s)",
         aconf->host, conf->name);
    return;
  }

  if (has_wildcards(aconf->host))
    return;

  /*
   * Do name lookup now on hostnames given and store the
   * ip numbers in conf structure.
   */
  memset(&hints, 0, sizeof(hints));

  hints.ai_family   = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  /* Get us ready for a bind() and don't bother doing dns lookup */
  hints.ai_flags = AI_PASSIVE | AI_NUMERICHOST;

  if (irc_getaddrinfo(aconf->host, NULL, &hints, &res))
  {
    conf_dns_lookup(aconf);
    return;
  }

  assert(res != NULL);

  memcpy(&aconf->ipnum, res->ai_addr, res->ai_addrlen);
  aconf->ipnum.ss_len = res->ai_addrlen;
  aconf->ipnum.ss.sin_family = res->ai_family;
  irc_freeaddrinfo(res);
}

static const unsigned int shared_bit_table[] =
  { 'K', 'k', 'U', 'X', 'x', 'Y', 'Q', 'q', 'R', 'L', 0};

/* report_confitem_types()
 *
 * inputs       - pointer to client requesting confitem report
 *              - ConfType to report
 * output       - none
 * side effects	- report conf items to source_p
 */
void
report_confitem_types(struct Client *source_p, ConfType type, int temp)
{
  dlink_node *ptr = NULL;
  struct ConfItem *conf = NULL;
  struct AccessItem *aconf = NULL;
  struct MatchItem *matchitem = NULL;
  struct ClassItem *classitem = NULL;
  char buf[12];
  char *p = NULL;

  switch (type)
  {
  case GDENY_TYPE:
    DLINK_FOREACH(ptr, gdeny_items.head)
    {
      conf = ptr->data;
      aconf = &conf->conf.AccessItem;

      p = buf;

      if (aconf->flags & GDENY_BLOCK)
        *p++ = 'B';
      else
        *p++ = 'b';

      if (aconf->flags & GDENY_REJECT)
        *p++ = 'R';
      else
        *p++ = 'r';

      *p = '\0';

      sendto_one(source_p, ":%s %d %s V %s@%s %s %s",
                 me.name, RPL_STATSDEBUG, source_p->name, 
                 aconf->user, aconf->host, conf->name, buf);
    }
    break;

  case XLINE_TYPE:
    DLINK_FOREACH(ptr, xconf_items.head)
    {
      conf = ptr->data;
      matchitem = &conf->conf.MatchItem;

      sendto_one(source_p, form_str(RPL_STATSXLINE),
		 me.name, source_p->name, 
		 matchitem->hold ? "x": "X", matchitem->count,
		 conf->name, matchitem->reason);
    }
    break;

  case RXLINE_TYPE:
    DLINK_FOREACH(ptr, rxconf_items.head)
    {
      conf = ptr->data;
      matchitem = &conf->conf.MatchItem;

      sendto_one(source_p, form_str(RPL_STATSXLINE),
                 me.name, source_p->name,
                 matchitem->hold ? "xR": "XR", matchitem->count,
                 conf->name, matchitem->reason);
    }
    break;

  case RKLINE_TYPE:
    p = temp ? "Rk" : "RK";

    DLINK_FOREACH(ptr, rkconf_items.head)
    {
      aconf = &((struct ConfItem *)(conf = ptr->data))->conf.AccessItem;

      if (temp && !(conf->flags & CONF_FLAGS_TEMPORARY))
        continue;

      sendto_one(source_p, form_str(RPL_STATSKLINE), me.name,
                 source_p->name, p, aconf->host, aconf->user,
                 aconf->reason, aconf->oper_reason ? aconf->oper_reason : "");
    }
    break;

  case ULINE_TYPE:
    DLINK_FOREACH(ptr, uconf_items.head)
    {
      conf = ptr->data;
      matchitem = &conf->conf.MatchItem;

      p = buf;

      /* some of these are redundant for the sake of 
       * consistency with cluster{} flags
       */
      *p++ = 'c';
      flags_to_ascii(matchitem->action, shared_bit_table, p, 0);

      sendto_one(source_p, form_str(RPL_STATSULINE),
		 me.name, source_p->name, conf->name,
                 matchitem->user?matchitem->user: "*",
		 matchitem->host?matchitem->host: "*", buf);
    }

    DLINK_FOREACH(ptr, cluster_items.head)
    {
      conf = ptr->data;
      matchitem = &conf->conf.MatchItem;

      p = buf;

      *p++ = 'C';
      flags_to_ascii(matchitem->action, shared_bit_table, p, 0);

      sendto_one(source_p, form_str(RPL_STATSULINE),
                 me.name, source_p->name, conf->name,
                 "*", "*", buf);
    }

    break;

  case OPER_TYPE:
    DLINK_FOREACH(ptr, oconf_items.head)
    {
      conf = ptr->data;
      aconf = &conf->conf.AccessItem;

      /* Don't allow non opers to see oper privs */
      if (IsOper(source_p))
	sendto_one(source_p, form_str(RPL_STATSOLINE),
		   me.name, source_p->name, 'O', aconf->user, aconf->host,
		   conf->name, oper_privs_as_string(aconf->port),
		   aconf->class_ptr ? aconf->class_ptr->name : "<default>");
      else
	sendto_one(source_p, form_str(RPL_STATSOLINE),
		   me.name, source_p->name, 'O', aconf->user, aconf->host,
                   conf->name, "0",
		   aconf->class_ptr ? aconf->class_ptr->name : "<default>");
    }

  case CLASS_TYPE:
    DLINK_FOREACH(ptr, class_items.head)
    {
      conf = ptr->data;
      classitem = &conf->conf.ClassItem;
      sendto_one(source_p, form_str(RPL_STATSYLINE),
		 me.name, source_p->name, 'Y',
		 conf->name, PingFreq(classitem),
		 ConFreq(classitem),
		 MaxTotal(classitem), MaxSendq(classitem), CurrUserCount(classitem));
    }
    break;

  case CONF_TYPE:
  case CLIENT_TYPE:
    break;

  case SERVER_TYPE:
    DLINK_FOREACH(ptr, server_items.head)
    {
      p = buf;

      conf = ptr->data;
      aconf = &conf->conf.AccessItem;

      buf[0] = '\0';

      if (IsConfAllowAutoConn(aconf))
	*p++ = 'A';
      if (IsConfCryptLink(aconf))
	*p++ = 'C';
      if (aconf->fakename)
	*p++ = 'M';
      if (IsConfTopicBurst(aconf))
        *p++ = 'T';
      if (IsConfCompressed(aconf))
        *p++ = 'Z';
      if (buf[0] == '\0')
	*p++ = '*';

      *p = '\0';

      /* Allow admins to see actual ips
       * unless hide_server_ips is enabled
       */
      if (!ConfigServerHide.hide_server_ips && IsAdmin(source_p))
	sendto_one(source_p, form_str(RPL_STATSCLINE),
		   me.name, source_p->name, 'C', aconf->host,
		   buf, conf->name, aconf->port,
		   aconf->class_ptr ? aconf->class_ptr->name : "<default>");
        else
          sendto_one(source_p, form_str(RPL_STATSCLINE),
                     me.name, source_p->name, 'C',
		     "*@127.0.0.1", buf, conf->name, aconf->port,
		     aconf->class_ptr ? aconf->class_ptr->name : "<default>");
    }
    break;

  case HUB_TYPE:
    DLINK_FOREACH(ptr, hub_items.head)
    {
      conf = ptr->data;
      matchitem = &conf->conf.MatchItem;
      sendto_one(source_p, form_str(RPL_STATSHLINE), me.name,
		 source_p->name, 'H', matchitem->host, conf->name, 0, "*");
    }
    break;

  case LEAF_TYPE:
    DLINK_FOREACH(ptr, leaf_items.head)
    {
      conf = ptr->data;
      matchitem = &conf->conf.MatchItem;
      sendto_one(source_p, form_str(RPL_STATSLLINE), me.name,
		 source_p->name, 'L', matchitem->host, conf->name, 0, "*");
    }
    break;

  case GLINE_TYPE:
  case KLINE_TYPE:
  case DLINE_TYPE:
  case EXEMPTDLINE_TYPE:
  case CRESV_TYPE:
  case NRESV_TYPE:
  case CLUSTER_TYPE:
    break;
  }
}

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
 * Input: A client to find the active oper{} name for.
 * Output: The nick!user@host{oper} of the oper.
 *         "oper" is server name for remote opers
 * Side effects: None.
 */
char *
get_oper_name(const struct Client *client_p)
{
  /* +5 for !,@,{,} and null */
  static char buffer[NICKLEN+USERLEN+HOSTLEN+HOSTLEN+5];

  if (MyConnect(client_p) && IsOper(client_p))
    ircsprintf(buffer, "%s!%s@%s{%s}", client_p->name,
	       client_p->username, client_p->host,
	       client_p->localClient->auth_oper);
  else
    ircsprintf(buffer, "%s!%s@%s{%s}", client_p->name,
	       client_p->username, client_p->host,
               client_p->servptr->name);
  return buffer;
}

/*
 * flags_to_ascii
 *
 * inputs	- flags is a bitmask
 *		- pointer to table of ascii letters corresponding
 *		  to each bit
 *		- flag 1 for convert ToLower if bit missing 
 *		  0 if ignore.
 * output	- none
 * side effects	- string pointed to by p has bitmap chars written to it
 */
static void
flags_to_ascii(unsigned int flags, const unsigned int bit_table[], char *p,
	       int lowerit)
{
  unsigned int mask = 1;
  int i = 0;

  for (mask = 1; (mask != 0) && (bit_table[i] != 0); mask <<= 1, i++)
  {
    if (flags & mask)
      *p++ = bit_table[i];
    else if(lowerit)
      *p++ = ToLower(bit_table[i]);
  }
  *p = '\0';
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
