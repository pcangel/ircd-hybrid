/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  glines.h: Defines glines{} conf section.
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

#define GDENY_REJECT    1
#define GDENY_BLOCK     2
#define GDENY_ERROR     4

struct GlineDenyConf
{
  char *server;
  char *user;
  char *host;
  struct irc_ssaddr ip;
  int action;
  dlink_node node;
};

struct GlineConf
{
  struct AccessConf access;
  time_t expires;
  char *reason;
};

EXTERN int enable_glines;
EXTERN time_t gline_duration;
EXTERN int gline_logging;
EXTERN int acb_type_gline;

EXTERN int is_gline_allowed(const char *, const char *, const char *,
  const struct irc_ssaddr *);
EXTERN struct GlineConf *place_gline(const char *, const char *, const char *);
EXTERN struct GlineConf *find_gline(const char *, const char *, const struct irc_ssaddr *);

#ifdef IN_CONF_C
void init_glines(void);
#endif
