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

/*! \file watch.h
 * \brief Header including structures and prototypes for WATCH support
 * \version $Id$
 */

#ifndef INCLUDED_watch_h
#define INCLUDED_watch_h

struct Watch
{
  struct Watch *hnext;
  dlink_list watched_by;
  char nick[NICKLEN];
  time_t lasttime;
};

extern void init_watch(void);
extern void add_to_watch_hash_table(const char *, struct Client *);
extern void del_from_watch_hash_table(const char *, struct Client *);
extern void hash_check_watch(struct Client *, int);
extern void hash_del_watch_list(struct Client *);
extern void count_watch_memory(unsigned int *, unsigned int *);
extern struct Watch *hash_get_watch(const char *);
#endif
