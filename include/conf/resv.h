/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  resv.h: Defines resv{} conf section.
 *
 *  Copyright (C) 2006 by the Hybrid Development Team.
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

struct ResvConf
{
  char *mask;
  char *reason;
  time_t expires;
  dlink_node node;
};

EXTERN dlink_list cresv_confs;
EXTERN dlink_list nresv_confs;
EXTERN int num_hashed_resvs;

struct Client;

EXTERN struct ResvConf *do_find_resv(dlink_list *, const char *,
  int (*) (const char *, const char *));
EXTERN struct ResvConf *find_nick_resv(const char *);
EXTERN struct ResvConf *find_channel_resv(const char *);
EXTERN void report_resv(struct Client *);

#ifdef IN_CONF_C
void init_resv(void);
#endif
