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
