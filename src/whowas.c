/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *
 *  Copyright (C) 2005 by the past and present ircd coders, and others.
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

/*! \file whowas.c
 * \brief Maintains a history of nick names
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "whowas.h"
#include "hash.h"
#include "ircd.h"
#include "ircd_defs.h"
#include "numeric.h"

static struct Whowas WHOWAS[NICKNAMEHISTORYLENGTH];
dlink_list WHOWASHASH[HASHSIZE];


/*! \brief Adds the currently defined name of the client to history.
 *         Usually called before changing to a new name (nick).
 *         Client must be a fully registered user.
 * \param client_p pointer to Client struct to add
 * \param online   either 1 if it's a nick change or 0 on client exit
 */
void
whowas_add_history(struct Client *client_p, int online)
{
  static unsigned int whowas_next = 0;
  struct Whowas *who = &WHOWAS[whowas_next];

  assert(IsClient(client_p));

  if (++whowas_next == NICKNAMEHISTORYLENGTH)
    whowas_next = 0;

  assert(client_p && client_p->servptr);

  if (who->hashv != -1)
  {
    if (who->online)
      dlinkDelete(&who->cnode, &who->online->whowas);

    dlinkDelete(&who->tnode, &WHOWASHASH[who->hashv]);
  }

  who->hashv = strhash(client_p->name);
  who->logoff = CurrentTime;

  /*
   * NOTE: strcpy ok here, the sizes in the client struct MUST
   * match the sizes in the whowas struct
   */
  strcpy(who->name, client_p->name);
  strcpy(who->username, client_p->username);
  strcpy(who->hostname, client_p->host);
  strcpy(who->realname, client_p->info);

  strlcpy(who->servername, client_p->servptr->name, sizeof(who->servername));

  if (online)
  {
    who->online = client_p;
    dlinkAdd(who, &who->cnode, &client_p->whowas);
  }
  else
    who->online = NULL;

  dlinkAdd(who, &who->tnode, &WHOWASHASH[who->hashv]);
}

/*! \brief This must be called when the client structure is about to
 *         be released. History mechanism keeps pointers to client
 *         structures and it must know when they cease to exist.
 * \param client_p pointer to Client struct
 */
void
whowas_off_history(struct Client *client_p)
{
  dlink_node *ptr = NULL, *ptr_next = NULL;

  DLINK_FOREACH_SAFE(ptr, ptr_next, client_p->whowas.head)
  {
    struct Whowas *temp = ptr->data;
    temp->online = NULL;
    dlinkDelete(&temp->cnode, &client_p->whowas);
  }
}

/*! \brief Returns the current client that was using the given
 *         nickname within the timelimit. Returns NULL, if no
 *         one found...
 * \param nick      name of the nick
 * \param timelimit maximum age for a client since log-off
 */
struct Client *
whowas_get_history(const char *nick, time_t timelimit)
{
  dlink_node *ptr = NULL;

  timelimit = CurrentTime - timelimit;

  DLINK_FOREACH(ptr, WHOWASHASH[strhash(nick)].head)
  {
    struct Whowas *temp = ptr->data;

    if (irccmp(nick, temp->name))
      continue;
    if (temp->logoff < timelimit)
      continue;
    return temp->online;
  }

  return NULL;
}

/*! \brief Initializes required whowas tables
 */
void
whowas_init(void)
{
  unsigned int i;

  for (i = 0; i < NICKNAMEHISTORYLENGTH; ++i)
  {
    memset(&WHOWAS[i], 0, sizeof(struct Whowas));
    WHOWAS[i].hashv = -1;
  }

  /*
   * Global variables are always 0 initialized,
   * but we do this anyway.
   */
  memset(WHOWASHASH, 0, sizeof(WHOWASHASH));
}
