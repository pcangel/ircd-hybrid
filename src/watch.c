/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *
 *  Copyright (C) 1997 Jukka Santala (Donwulff)
 *  Copyright (C) 2005 by the Hybrid Development Team.
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
 */

/*! \file watch.c
 * \brief File including functions for WATCH support
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "common.h"
#include "hash.h"
#include "ircd.h"
#include "numeric.h"
#include "s_conf.h"
#include "s_user.h"
#include "send.h"
#include "supported.h"
#include "watch.h"
#include "msg.h"

#define WATCH_HEAP_SIZE 32

static struct Watch *watchTable[HASHSIZE];

static BlockHeap *watch_heap = NULL;

void
init_watch(void)
{
  unsigned int idx;

  watch_heap = BlockHeapCreate("watch", sizeof(struct Watch), WATCH_HEAP_SIZE);

  for (idx = 0; idx < HASHSIZE; ++idx)
    watchTable[idx] = NULL;
}

/*
 * Rough figure of the datastructures for watch:
 *
 * NOTIFY HASH          client_p1
 *   |                    |- nick1
 * nick1-|- client_p1     |- nick2
 *   |   |- client_p2                client_p3
 *   |   |- client_p3   client_p2      |- nick1
 *   |                    |- nick1
 * nick2-|- client_p2     |- nick2
 *       |- client_p1
 */

/*
 * count_watch_memory()
 */
void
count_watch_memory(unsigned int *count, unsigned int *memory)
{
  unsigned int idx;

  for (idx = 0; idx < HASHSIZE; ++idx)
  {
    const struct Watch *anptr = watchTable[idx];

    for (; anptr; anptr = anptr->hnext)
    {
      (*count)++;
      (*memory) += sizeof(struct Watch);
    }
  }
}

/*
 * hash_check_watch()
 */
void
hash_check_watch(struct Client *client_p, int reply)
{
  struct Watch *anptr = NULL;
  dlink_node *ptr = NULL;
  assert(IsClient(client_p));
  if ((anptr = hash_get_watch(client_p->name)) == NULL)
    return;    /* This nick isn't on watch */

  /* Update the time of last change to item */
  anptr->lasttime = CurrentTime;

  /* Send notifies out to everybody on the list in header */
  DLINK_FOREACH(ptr, anptr->watched_by.head)
  {
    struct Client *target_p = ptr->data;

    sendto_one(target_p, form_str(reply),
               me.name, target_p->name, client_p->name,
               client_p->username, client_p->host,
               anptr->lasttime, client_p->info);
  }
}

/*
 * hash_get_watch()
 */
struct Watch *
hash_get_watch(const char *name)
{
  unsigned int hashv = strhash(name);
  struct Watch *anptr = NULL;

  if ((anptr = watchTable[hashv]))
    while (anptr && irccmp(anptr->nick, name))
      anptr = anptr->hnext;

  return anptr;
}

/*
 * add_to_watch_hash_table()
 */
void
add_to_watch_hash_table(const char *nick, struct Client *client_p)
{
  unsigned int hashv = strhash(nick);
  struct Watch *anptr = NULL;
  dlink_node *ptr = NULL;

  /* Find the right nick (header) in the bucket, or NULL... */
  if ((anptr = watchTable[hashv]))
    while (anptr && irccmp(anptr->nick, nick))
      anptr = anptr->hnext;

  /* If found NULL (no header for this nick), make one... */
  if (anptr == NULL)
  {
    anptr = BlockHeapAlloc(watch_heap);
    anptr->lasttime = CurrentTime;
    strlcpy(anptr->nick, nick, sizeof(anptr->nick));

    anptr->hnext = watchTable[hashv];
    watchTable[hashv] = anptr;
  }
  else
  {
    /* Is this client already on the watch-list? */
    ptr = dlinkFind(&anptr->watched_by, client_p);
  }

  if (ptr == NULL)
  {
    /* No it isn't, so add it in the bucket and client addint it */
    dlinkAdd(client_p, make_dlink_node(), &anptr->watched_by);
    dlinkAdd(anptr, make_dlink_node(), &client_p->localClient->watches);
  }
}

/*
 * del_from_watch_hash_table()
 */
void
del_from_watch_hash_table(const char *nick, struct Client *client_p)
{
  unsigned int hashv = strhash(nick);
  struct Watch *anptr = NULL;
  struct Watch *nlast = NULL;
  dlink_node *ptr = NULL;

  /* Find the right header, maintaining last-link pointer... */
  if ((anptr = watchTable[hashv]))
  {
    while (anptr && irccmp(anptr->nick, nick))
    {
      nlast = anptr;
      anptr = anptr->hnext;
    }
  }

  if (anptr == NULL)
    return;    /* No such watch */

  if ((ptr = dlinkFind(&anptr->watched_by, client_p)) == NULL)
    return;

  dlinkDelete(ptr, &anptr->watched_by);
  free_dlink_node(ptr);

  if ((ptr = dlinkFindDelete(&client_p->localClient->watches, anptr)))
    free_dlink_node(ptr);

  /* In case this header is now empty of notices, remove it */
  if (anptr->watched_by.head == NULL)
  {
    if (!nlast)
      watchTable[hashv] = anptr->hnext;
    else
      nlast->hnext = anptr->hnext;

    BlockHeapFree(watch_heap, anptr);
  }
}

/*
 * hash_del_watch_list()
 */
void
hash_del_watch_list(struct Client *client_p)
{
  dlink_node *ptr = NULL, *ptr_next = NULL;
  dlink_node *tmp = NULL;

  if (client_p->localClient->watches.head == NULL)
    return;    /* Nothing to do */

  DLINK_FOREACH_SAFE(ptr, ptr_next, client_p->localClient->watches.head)
  {
    struct Watch *anptr = ptr->data;

    assert(anptr);

    if ((tmp = dlinkFindDelete(&anptr->watched_by, client_p)))
      free_dlink_node(tmp);

    /*
     * If this leaves a header without notifies, remove it.
     * Need to find the last-pointer!
     */
    if (anptr->watched_by.head == NULL)
    {
      unsigned int hashv = 0;
      struct Watch *np2, *nl;

      hashv = strhash(anptr->nick);
      nl = NULL;
      np2 = watchTable[hashv];

      while (np2 && (np2 != anptr))
      {
        nl  = np2;
        np2 = np2->hnext;
      }

      if (nl)
        nl->hnext = anptr->hnext;
      else
        watchTable[hashv] = anptr->hnext;

      BlockHeapFree(watch_heap, anptr);
    }

    dlinkDelete(ptr, &client_p->localClient->watches);
    free_dlink_node(ptr);
  }

  assert(client_p->localClient->watches.head == NULL);
  assert(client_p->localClient->watches.tail == NULL);
}
