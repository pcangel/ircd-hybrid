/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_accept.c: Allows a user to talk to a +g user.
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
#include "handlers.h"
#include "client.h"
#include "hash.h"       /* for find_client() */
#include "ircd.h"
#include "numeric.h"
#include "s_conf.h"
#include "s_serv.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "s_user.h"
#include "modules.h"

static void m_accept(struct Client *, struct Client *, int, char *[]);
static void build_nuh_list(struct Client *, char *, char *, char *);
static void add_accept(const char *, const char *, const char *, struct Client *);
static void list_accepts(struct Client *);

struct Message accept_msgtab = {
  "ACCEPT", 0, 0, 0, 0, MFLG_SLOW, 0,
  { m_unregistered, m_accept, m_ignore, m_ignore, m_accept, m_ignore }
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&accept_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&accept_msgtab);
}

const char *_version = "$Revision$";
#endif

/*
 * m_accept - ACCEPT command handler
 *      parv[0] = sender prefix
 *      parv[1] = servername
 */
static void
m_accept(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  struct Accept *accept = NULL;
  char *mask, *nick, *user, *host;
  char *p = NULL;
  char addbuf[IRCD_BUFSIZE] = { '\0' };
  char delbuf[IRCD_BUFSIZE] = { '\0' };
  int accept_num = 0;
  
  if (parc < 2)
  {
    list_accepts(source_p);
    return;
  }

  build_nuh_list(source_p, addbuf, delbuf, parv[1]);

  /* parse the delete list */
  for (mask = strtoken(&p, delbuf, ","); mask != NULL;
       mask = strtoken(&p, NULL,   ","))
  {
    /* user isn't on clients accept list */
    split_nuh(mask, &nick, &user, &host);

    if ((accept = find_accept(nick, user, host, source_p, 0)) == NULL)
    {
      sendto_one(source_p, form_str(ERR_ACCEPTNOT),
                 me.name, source_p->name, nick, user, host);
      MyFree(nick);
      MyFree(user);
      MyFree(host);
      continue;
    }

    del_accept(accept, source_p);

    MyFree(nick);
    MyFree(user);
    MyFree(host);
  }

  /* get the number of accepts they have */ 
  accept_num = dlink_list_length(&source_p->localClient->acceptlist);

  /* parse the add list */
  for (mask = strtoken(&p, addbuf, ","); mask;
       mask = strtoken(&p, NULL,   ","), ++accept_num)
  {
     /* user is already on clients accept list */
    split_nuh(mask, &nick, &user, &host);

    if ((accept = find_accept(nick, user, host, source_p, 0)) != NULL)
    {
      sendto_one(source_p, form_str(ERR_ACCEPTEXIST),
                 me.name, source_p->name, nick, user, host);
      MyFree(nick);
      MyFree(user);
      MyFree(host);
      continue;
    }

    if (accept_num >= ConfigFileEntry.max_accept)
    {
      sendto_one(source_p, form_str(ERR_ACCEPTFULL),
                 me.name, source_p->name);
      MyFree(nick);
      MyFree(user);
      MyFree(host);
      return;
    }

    add_accept(nick, user, host, source_p);
    MyFree(nick);
    MyFree(user);
    MyFree(host);
  }
}

/* build_nuh_list()
 *
 * input	- pointer to client
 *		- pointer to addbuffer
 *		- pointer to remove buffer
 *		- pointer to list of nicks
 *		- pointer to list of nicks!user@host
 * output	- 
 * side effects - addbuf/delbuf are modified to give valid masks
 */
static void
build_nuh_list(struct Client *source_p, char *addbuf,
               char *delbuf, char *inbuf)
{
  char *mask = NULL;
  char *p = NULL;
  char *buf_p = NULL;

  /* build list of nuh to add into addbuf, nuh to remove in delbuf */
  for (mask = strtoken(&p, inbuf, ","); mask; 
       mask = strtoken(&p,  NULL, ","))
  {
    if (*mask == '-')
      buf_p = delbuf, ++mask;
    else
      buf_p = addbuf;

    if (*buf_p != '\0')
      strlcat(buf_p, ",", IRCD_BUFSIZE);
    strlcat(buf_p, mask, IRCD_BUFSIZE);
  }
}

/* add_accept()
 *
 * input	- nick
 *		- username
 * 		- host
 * 		- pointer to client to add to acceptlist
 * output	- none
 * side effects - target is added to clients list
 */
static void
add_accept(const char *nick, const char *user,
           const char *host, struct Client *source_p)
{
  struct Accept *accept = MyMalloc(sizeof(*accept));

  DupString(accept->nick, nick);
  DupString(accept->user, user);
  DupString(accept->host, host);

  dlinkAdd(accept, &accept->node, &source_p->localClient->acceptlist);

  list_accepts(source_p);
}

/* list_accepts()
 *
 * input 	- pointer to client
 * output	- none
 * side effects	- print accept list to client
 */
static void
list_accepts(struct Client *source_p)
{
  struct Accept *accept;
  int len = 0;
  char nuh_list[IRCD_BUFSIZE] = { '\0' };
  char *t = nuh_list;
  const dlink_node *ptr = NULL;

  len = strlen(me.name) + strlen(source_p->name) + 12;

  DLINK_FOREACH(ptr, source_p->localClient->acceptlist.head)
  {
    accept = ptr->data;

    if ((t - nuh_list) + strlen(source_p->name) + len > IRCD_BUFSIZE)
    {
      *(t - 1) = '\0';
      sendto_one(source_p, form_str(RPL_ACCEPTLIST),
                 me.name, source_p->name, nuh_list);
      t = nuh_list;
    }

    t += ircsprintf(t, "%s!%s@%s ",
		    accept->nick, accept->user, accept->host);
  }

  if (nuh_list[0] != '\0')
  {
    *(t - 1) = '\0';
    sendto_one(source_p, form_str(RPL_ACCEPTLIST),
               me.name, source_p->name, nuh_list);
  }

  sendto_one(source_p, form_str(RPL_ENDOFACCEPT),
             me.name, source_p->name);
}
