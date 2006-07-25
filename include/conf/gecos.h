/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  gecos.h: Defines gecos{} conf section.
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

struct GecosConf
{
  char *mask;
  char *reason;
  pcre *regex;
  int count;
  time_t expires;
  dlink_node node;
};

EXTERN dlink_list gecos_confs;

struct Client;

EXTERN struct GecosConf *find_exact_xline(const char *, int);
EXTERN struct GecosConf *find_gecos_ban(const char *);
EXTERN void report_gecos(struct Client *);

#ifdef IN_CONF_C
void init_gecos(void);
#endif
