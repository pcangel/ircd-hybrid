/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  whowas.h: Header for the whowas functions.
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

#ifndef INCLUDED_whowas_h
#define INCLUDED_whowas_h

struct Whowas
{
  int hashv;
  time_t logoff;
  char name[NICKLEN];
  char username[USERLEN + 1]; 
  char hostname[HOSTLEN + 1];
  char realname[REALLEN + 1];
  char servername[HOSTLEN + 1];
  struct Client *online; /* Pointer to new nickname for chasing or NULL */
  dlink_node tnode;  /* for hash table... */
  dlink_node cnode; /* for client struct linked list */
};

EXTERN void whowas_init(void);
EXTERN void whowas_add_history(struct Client *, int);
EXTERN void whowas_off_history(struct Client *);
EXTERN struct Client *whowas_get_history(const char *, time_t);

/* XXX m_whowas.c in modules needs these */
EXTERN dlink_list WHOWASHASH[];
#endif
