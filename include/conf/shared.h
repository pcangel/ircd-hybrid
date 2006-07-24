/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  shared.h: Defines admin{} and shared{} conf sections.
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

#define SHARED_KLINE    1
#define SHARED_TKLINE   2
#define SHARED_UNKLINE  4
#define SHARED_XLINE    8
#define SHARED_TXLINE   16
#define SHARED_UNXLINE  32
#define SHARED_RESV     64
#define SHARED_TRESV    128
#define SHARED_UNRESV   256
#define SHARED_LOCOPS   512

struct SharedConf
{
  char *server;
  char *user;
  char *host;
  struct irc_ssaddr ip;
  int type;
  dlink_node node;
};

struct ClusterConf
{
  char *server;
  int type;
  dlink_node node;
};

EXTERN dlink_list cluster_confs;
EXTERN dlink_list shared_confs;

EXTERN struct SharedConf *find_shared(const char *, const char *, const char *,
  const struct irc_ssaddr *, int);

#ifdef IN_CONF_C
void init_shared(void);
#endif
