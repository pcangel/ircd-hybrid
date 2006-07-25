/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  kill.h: Defines kill{} conf section.
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

struct KillConf
{
  struct AccessConf access;
  pcre *regexuser;
  pcre *regexhost;
  dlink_node node;
  char *oper_reason;
  char *reason;
};

EXTERN int acb_type_kline;
EXTERN dlink_list rkline_confs;

struct Client;

EXTERN void free_kline(struct KillConf *);
EXTERN struct KillConf *find_kline(const char *, const char *, const char *,
  const struct irc_ssaddr *);
EXTERN struct KillConf *find_exact_kline(const char *, const char *);
EXTERN struct KillConf *find_exact_rkline(const char *, const char *);
EXTERN void report_klines(struct Client *);
EXTERN void report_tklines(struct Client *);

#ifdef IN_CONF_C
void init_kill(void);
#endif
