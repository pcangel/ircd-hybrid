/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  hash.c: Maintains hashtables.
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
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "common.h"
#include "handlers.h"
#include "hash.h"
#include "userhost.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "user.h"

static BlockHeap *userhost_heap = NULL;
static BlockHeap *namehost_heap = NULL;
static struct UserHost *find_or_add_userhost(const char *);

static unsigned int ircd_random_key = 0;

/* The actual hash tables, They MUST be of the same HASHSIZE, variable
 * size tables could be supported but the rehash routine should also
 * rebuild the transformation maps, I kept the tables of equal size 
 * so that I can use one hash function.
 */
static struct Client *idTable[HASHSIZE];
static struct Client *clientTable[HASHSIZE];
static struct Channel *channelTable[HASHSIZE];
static struct UserHost *userhostTable[HASHSIZE];
static struct ResvChannel *resvchannelTable[HASHSIZE];

/* usually, with hash tables, you use a prime number...
 * but in this case I am dealing with ip addresses,
 * not ascii strings.
 */
#define IP_HASH_SIZE 0x1000

static struct ip_entry *ip_hash_table[IP_HASH_SIZE] = {0};
static BlockHeap *ip_entry_heap = NULL;
static int ip_entries_count = 0;


/* init_hash()
 *
 * inputs       - NONE
 * output       - NONE
 * side effects - Initialize the maps used by hash
 *                functions and clear the tables
 */
void
hash_init(void)
{
  unsigned int i;

  /* Default the userhost/namehost sizes to CLIENT_HEAP_SIZE for now,
   * should be a good close approximation anyway
   * - Dianora
   */
  userhost_heap = BlockHeapCreate("userhost", sizeof(struct UserHost), CLIENT_HEAP_SIZE);
  namehost_heap = BlockHeapCreate("namehost", sizeof(struct NameHost), CLIENT_HEAP_SIZE);

  ircd_random_key = rand() % 256;  /* better than nothing --adx */

  // Clear the hash tables first
  for (i = 0; i < HASHSIZE; ++i)
  {
    idTable[i]          = NULL;
    clientTable[i]      = NULL;
    channelTable[i]     = NULL;
    userhostTable[i]    = NULL;
    resvchannelTable[i] = NULL;
  }

  // Initialize IP hashing
  ip_entry_heap = BlockHeapCreate("ip", sizeof(struct ip_entry),
                                  hard_fdlimit * 2);
}

/*
 * New hash function based on the Fowler/Noll/Vo (FNV) algorithm from
 * http://www.isthe.com/chongo/tech/comp/fnv/
 *
 * Here, we use the FNV-1 method, which gives slightly better results
 * than FNV-1a.   -Michael
 */
unsigned int
strhash(const char *name)
{
  const unsigned char *p = (const unsigned char *)name;
  unsigned int hval = FNV1_32_INIT;

  if (*p == '\0')
    return 0;
  for (; *p != '\0'; ++p)
  {
    hval += (hval << 1) + (hval <<  4) + (hval << 7) +
            (hval << 8) + (hval << 24);
    hval ^= (ToLower(*p) ^ ircd_random_key);
  }

  return (hval >> FNV1_32_BITS) ^ (hval & ((1 << FNV1_32_BITS) -1));
}

/************************** Externally visible functions ********************/

/* Optimization note: in these functions I supposed that the CSE optimization
 * (Common Subexpression Elimination) does its work decently, this means that
 * I avoided introducing new variables to do the work myself and I did let
 * the optimizer play with more free registers, actual tests proved this
 * solution to be faster than doing things like tmp2=tmp->hnext... and then
 * use tmp2 myself which would have given less freedom to the optimizer.
 */

/* hash_add_client()
 *
 * inputs       - pointer to client
 * output       - NONE
 * side effects - Adds a client's name in the proper hash linked
 *                list, can't fail, client_p must have a non-null
 *                name or expect a coredump, the name is infact
 *                taken from client_p->name
 */
void
hash_add_client(struct Client *client_p)
{
  unsigned int hashv = strhash(client_p->name);

  client_p->hnext = clientTable[hashv];
  clientTable[hashv] = client_p;
}

/* hash_add_channel()
 *
 * inputs       - pointer to channel
 * output       - NONE
 * side effects - Adds a channel's name in the proper hash linked
 *                list, can't fail. chptr must have a non-null name
 *                or expect a coredump. As before the name is taken
 *                from chptr->name, we do hash its entire lenght
 *                since this proved to be statistically faster
 */
void
hash_add_channel(struct Channel *chptr)
{
  unsigned int hashv = strhash(chptr->chname);

  chptr->hnextch = channelTable[hashv];
  channelTable[hashv] = chptr;
}

void
hash_add_userhost(struct UserHost *userhost)
{
  unsigned int hashv = strhash(userhost->host);

  userhost->next = userhostTable[hashv];
  userhostTable[hashv] = userhost;
}

void
hash_add_id(struct Client *client_p)
{
  unsigned int hashv = strhash(client_p->id);

  client_p->idhnext = idTable[hashv];
  idTable[hashv] = client_p;
}

/* hash_del_id()
 *
 * inputs       - pointer to client
 * output       - NONE
 * side effects - Removes an ID from the hash linked list
 */
void
hash_del_id(struct Client *client_p)
{
  unsigned int hashv = strhash(client_p->id);
  struct Client *tmp = idTable[hashv];

  if (tmp != NULL)
  {
    if (tmp == client_p)
    {
      idTable[hashv] = client_p->idhnext;
      client_p->idhnext = client_p;
    }
    else
    {
      while (tmp->idhnext != client_p)
      {
        if ((tmp = tmp->idhnext) == NULL)
          return;
      }

      tmp->idhnext = tmp->idhnext->idhnext;
      client_p->idhnext = client_p;
    }
  }
}

/* hash_del_client()
 *
 * inputs       - pointer to client
 * output       - NONE
 * side effects - Removes a Client's name from the hash linked list
 */
void
hash_del_client(struct Client *client_p)
{
  unsigned int hashv = strhash(client_p->name);
  struct Client *tmp = clientTable[hashv];

  if (tmp != NULL)
  {
    if (tmp == client_p)
    {
      clientTable[hashv] = client_p->hnext;
      client_p->hnext = client_p;
    }
    else
    {
      while (tmp->hnext != client_p)
      {
        if ((tmp = tmp->hnext) == NULL)
          return;
      }

      tmp->hnext = tmp->hnext->hnext;
      client_p->hnext = client_p;
    }
  }
}

/* hash_del_userhost()
 *
 * inputs       - pointer to userhost
 * output       - NONE
 * side effects - Removes a userhost from the hash linked list
 */
void
hash_del_userhost(struct UserHost *userhost)
{
  unsigned int hashv = strhash(userhost->host);
  struct UserHost *tmp = userhostTable[hashv];

  if (tmp != NULL)
  {
    if (tmp == userhost)
    {
      userhostTable[hashv] = userhost->next;
      userhost->next = userhost;
    }
    else
    {
      while (tmp->next != userhost)
      {
        if ((tmp = tmp->next) == NULL)
          return;
      }

      tmp->next = tmp->next->next;
      userhost->next = userhost;
    }
  }
}

/* hash_del_channel()
 *
 * inputs       - pointer to client
 * output       - NONE
 * side effects - Removes the channel's name from the corresponding
 *                hash linked list
 */
void
hash_del_channel(struct Channel *chptr)
{
  unsigned int hashv = strhash(chptr->chname);
  struct Channel *tmp = channelTable[hashv];

  if (tmp != NULL)
  {
    if (tmp == chptr)
    {
      channelTable[hashv] = chptr->hnextch;
      chptr->hnextch = chptr;
    }
    else
    {
      while (tmp->hnextch != chptr)
      {
        if ((tmp = tmp->hnextch) == NULL)
          return;
      }

      tmp->hnextch = tmp->hnextch->hnextch;
      chptr->hnextch = chptr;
    }
  }
}

/* find_client()
 *
 * inputs       - pointer to name
 * output       - NONE
 * side effects - New semantics: finds a client whose name is 'name'
 *                if can't find one returns NULL. If it finds one moves
 *                it to the top of the list and returns it.
 */
struct Client *
find_client(const char *name)
{
  unsigned int hashv = strhash(name);
  struct Client *client_p;

  if ((client_p = clientTable[hashv]) != NULL)
  {
    if (irccmp(name, client_p->name))
    {
      struct Client *prev;

      while (prev = client_p, (client_p = client_p->hnext) != NULL)
      {
        if (!irccmp(name, client_p->name))
        {
          prev->hnext = client_p->hnext;
          client_p->hnext = clientTable[hashv];
          clientTable[hashv] = client_p;
          break;
        }
      }
    }
  }

  return client_p;
}

struct Client *
hash_find_id(const char *name)
{
  unsigned int hashv = strhash(name);
  struct Client *client_p;

  if ((client_p = idTable[hashv]) != NULL)
  {
    if (irccmp(name, client_p->id))
    {
      struct Client *prev;

      while (prev = client_p, (client_p = client_p->idhnext) != NULL)
      {
        if (!irccmp(name, client_p->id))
        {
          prev->idhnext = client_p->idhnext;
          client_p->idhnext = idTable[hashv];
          idTable[hashv] = client_p;
          break;
        }
      }
    }
  }

  return client_p;
}

/*
 * Whats happening in this next loop ? Well, it takes a name like
 * foo.bar.edu and proceeds to earch for *.edu and then *.bar.edu.
 * This is for checking full server names against masks although
 * it isnt often done this way in lieu of using matches().
 *
 * Rewrote to do *.bar.edu first, which is the most likely case,
 * also made const correct
 * --Bleep
 */
static struct Client *
hash_find_masked_server(const char *name)
{
  char buf[HOSTLEN + 1];
  char *p = buf;
  char *s = NULL;
  struct Client *server = NULL;

  if (*name == '*' || *name == '.')
    return NULL;

  /*
   * copy the damn thing and be done with it
   */
  strlcpy(buf, name, sizeof(buf));

  while ((s = strchr(p, '.')) != NULL)
  {
    *--s = '*';

    /* Dont need to check IsServer() here since nicknames cant
     * have *'s in them anyway.
     */
    if ((server = find_client(s)) != NULL)
      return server;
    p = s + 2;
  }

  return NULL;
}

struct Client *
find_server(const char *name)
{
  unsigned int hashv = strhash(name);
  struct Client *client_p = NULL;

  if (IsDigit(*name) && strlen(name) == IRC_MAXSID)
    client_p = hash_find_id(name);

  if ((client_p == NULL) && (client_p = clientTable[hashv]) != NULL)
  {
    if ((!IsServer(client_p) && !IsMe(client_p)) ||
        irccmp(name, client_p->name))
    {
      struct Client *prev;

      while (prev = client_p, (client_p = client_p->hnext) != NULL)
      {
        if ((IsServer(client_p) || IsMe(client_p)) &&
            !irccmp(name, client_p->name))
        {
          prev->hnext = client_p->hnext;
          client_p->hnext = clientTable[hashv];
          clientTable[hashv] = client_p;
          break;
        }
      }
    }
  }

  return (client_p != NULL) ? client_p : hash_find_masked_server(name);
}

/* hash_find_channel()
 *
 * inputs       - pointer to name
 * output       - NONE
 * side effects - New semantics: finds a channel whose name is 'name', 
 *                if can't find one returns NULL, if can find it moves
 *                it to the top of the list and returns it.
 */
struct Channel *
hash_find_channel(const char *name)
{
  unsigned int hashv = strhash(name);
  struct Channel *chptr = NULL;

  if ((chptr = channelTable[hashv]) != NULL)
  {
    if (irccmp(name, chptr->chname))
    {
      struct Channel *prev;

      while (prev = chptr, (chptr = chptr->hnextch) != NULL)
      {
        if (!irccmp(name, chptr->chname))
        {
          prev->hnextch = chptr->hnextch;
          chptr->hnextch = channelTable[hashv];
          channelTable[hashv] = chptr;
          break;
        }
      }
    }
  }

  return chptr;
}

/* hash_get_bucket(int type, unsigned int hashv)
 *
 * inputs       - hash value (must be between 0 and HASHSIZE - 1)
 * output       - NONE
 * returns      - pointer to first channel in channelTable[hashv]
 *                if that exists;
 *                NULL if there is no channel in that place;
 *                NULL if hashv is an invalid number.
 * side effects - NONE
 */
void *
hash_get_bucket(int type, unsigned int hashv)
{
  assert(hashv < HASHSIZE);
  if (hashv >= HASHSIZE)
      return NULL;

  switch (type)
  {
    case HASH_TYPE_ID:
      return idTable[hashv];
      break;
    case HASH_TYPE_CHANNEL:
      return channelTable[hashv];
      break;
    case HASH_TYPE_CLIENT:
      return clientTable[hashv];
      break;
    case HASH_TYPE_USERHOST:
      return userhostTable[hashv];
      break;
    case HASH_TYPE_RESERVED:
      return resvchannelTable[hashv];
      break;
    default:
      assert(0);
  }

  return NULL;
}

struct UserHost *
hash_find_userhost(const char *host)
{
  unsigned int hashv = strhash(host);
  struct UserHost *userhost;

  if ((userhost = userhostTable[hashv]))
  {
    if (irccmp(host, userhost->host))
    {
      struct UserHost *prev;

      while (prev = userhost, (userhost = userhost->next) != NULL)
      {
        if (!irccmp(host, userhost->host))
        {
          prev->next = userhost->next;
          userhost->next = userhostTable[hashv];
          userhostTable[hashv] = userhost;
          break;
        }
      }
    }
  }

  return userhost;
}

/* count_user_host()
 *
 * inputs	- user name
 *		- hostname
 * 		- pointer to where global count should go
 *      - same as above, but counts all *@host
 *		- pointer to where local count should go
 *		- pointer to where global ~*@host count should go
 *      - pointer to where local ~*@host count should go
 * output	- none
 * side effects	-
 */
void
count_user_host(const char *user, const char *host, int *globuh,
                int *globhost, int *locuh, int *globnonid, int *locnonid)
{
  dlink_node *ptr;
  struct UserHost *found_userhost;
  struct NameHost *nameh;

  if ((found_userhost = hash_find_userhost(host)) == NULL)
    return;

  if (globhost)
    *globhost = found_userhost->total_clients;
  if (globnonid)
    *globnonid = found_userhost->total_nonident;
  if (locnonid)
    *locnonid = found_userhost->local_nonident;

  DLINK_FOREACH(ptr, found_userhost->names.head)
  {
    nameh = ptr->data;

    if (!irccmp(user, nameh->name))
    {
      if (globuh)
        *globuh = nameh->total;
      if (locuh)
        *locuh = nameh->local;
      return;
    }
  }
}

/* add_user_host()
 *
 * inputs	- user name
 *		- hostname
 *		- int flag 1 if global, 0 if local
 * output	- none
 * side effects	- add given user@host to hash tables
 */
void
add_user_host(const char *user, const char *host, int global)
{
  dlink_node *ptr;
  struct UserHost *found_userhost;
  struct NameHost *nameh;

  if ((found_userhost = find_or_add_userhost(host)) == NULL)
    return;

  found_userhost->total_clients++;

  if (*user == '~')
  {
    found_userhost->total_nonident++;
    if (!global)
      found_userhost->local_nonident++;
    user++;
  }

  DLINK_FOREACH(ptr, found_userhost->names.head)
  {
    nameh = ptr->data;

    if (!irccmp(user, nameh->name))
    {
      nameh->total++;
      if (!global)
        nameh->local++;
      return;
    }
  }

  nameh = BlockHeapAlloc(namehost_heap);
  strlcpy(nameh->name, user, sizeof(nameh->name));

  nameh->total = 1;
  if (!global)
    nameh->local = 1;

  dlinkAdd(nameh, &nameh->node, &found_userhost->names);
}

/* delete_user_host()
 *
 * inputs	- user name
 *		- hostname
 *		- int flag 1 if global, 0 if local
 * output	- none
 * side effects	- delete given user@host to hash tables
 */
void
delete_user_host(const char *user, const char *host, int global)
{
  dlink_node *ptr;
  struct NameHost *nameh;
  struct UserHost *found_userhost = hash_find_userhost(host);

  if (!found_userhost)
    return;

  found_userhost->total_clients--;

  if (*user == '~')
  {
    found_userhost->total_nonident--;
    if (!global)
      found_userhost->local_nonident--;
    user++;
  }

  DLINK_FOREACH(ptr, found_userhost->names.head)
  {
    nameh = ptr->data;

    if (!irccmp(user, nameh->name))
    {
      if (nameh->total > 0 && (global || nameh->local > 0))
      {
        nameh->total--;
        if (!global)
          nameh->local--;
      }

      if (!nameh->total && !nameh->local)
      {
        dlinkDelete(&nameh->node, &found_userhost->names);
        BlockHeapFree(namehost_heap, nameh);
      }

      if (dlink_list_length(&found_userhost->names) == 0)
      {
        hash_del_userhost(found_userhost);
        BlockHeapFree(userhost_heap, found_userhost);
      }

      return;
    }
  }
}

/* find_or_add_userhost()
 *
 * inputs	- host name
 * output	- none
 * side effects	- find UserHost * for given host name
 */
static struct UserHost *
find_or_add_userhost(const char *host)
{
  struct UserHost *userhost;

  if ((userhost = hash_find_userhost(host)) != NULL)
    return userhost;

  userhost = BlockHeapAlloc(userhost_heap);
  strlcpy(userhost->host, host, sizeof(userhost->host));
  hash_add_userhost(userhost);

  return userhost;
}

/* garbage_collect_ip_entries()
 *
 * input    - NONE
 * output   - NONE
 * side effects - free up all ip entries with no connections
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

      if (ptr->count == 0 && (CurrentTime - ptr->last_attempt) >=
          General.throttle_time)
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

/* find_or_add_ip()
 *
 * inputs       - pointer to struct irc_ssaddr
 * output       - pointer to a struct ip_entry
 * side effects -
 *
 * If the ip # was not found, a new struct ip_entry is created, and the ip
 * count set to 0.
 */
struct ip_entry *
find_or_add_ip(const struct irc_ssaddr *ip_in)
{
  struct ip_entry *ptr = NULL, *last = NULL;
  unsigned int hash_index = hash_ip(ip_in, -1, IP_HASH_SIZE), res;
  const struct sockaddr_in *v4 = (const struct sockaddr_in *)ip_in, *ptr_v4;
#ifdef IPV6
  const struct sockaddr_in6 *v6 = (const struct sockaddr_in6 *)ip_in, *ptr_v6;
#endif

  for (ptr = ip_hash_table[hash_index]; ptr; last = ptr, ptr = ptr->next)
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
      // Found entry already in hash, return it.
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
 *         the struct ip_entry is returned to the ip_entry_heap
 */
void
remove_one_ip(struct irc_ssaddr *ip_in)
{
  struct ip_entry *ptr;
  struct ip_entry *last_ptr = NULL;
  unsigned int hash_index = hash_ip(ip_in, -1, IP_HASH_SIZE), res;
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
    if (ptr->count == 0 && (CurrentTime - ptr->last_attempt) >=
        General.throttle_time)
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

/* ip_connect_allowed()
 *
 * inputs   - pointer to inaddr
 *      - int type ipv4 or ipv6
 * output   - BANNED or accepted
 * side effects - none
 */
int
ip_connect_allowed(const struct irc_ssaddr *addr)
{
  struct ip_entry *ip_found = NULL;

  if (find_dline(addr))
    return BANNED_CLIENT;

  ip_found = find_or_add_ip(addr);

  if ((CurrentTime - ip_found->last_attempt) < General.throttle_time &&
      !find_exempt(addr))
  {
    ip_found->last_attempt = CurrentTime;
    return TOO_FAST;
  }

  ip_found->last_attempt = CurrentTime;
  return 0;
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
