/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  deny.h: Defines deny{} and exempt{} conf sections.
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

struct DenyConf
{
  struct AccessConf access;
  char *reason;
  char *oper_reason;
};

EXTERN int acb_type_deny;
EXTERN int acb_type_exempt;

struct Client;

EXTERN struct DenyConf *find_dline(const struct irc_ssaddr *);
EXTERN struct AccessConf *find_exempt(const struct irc_ssaddr *);
EXTERN void report_deny(struct Client *);
EXTERN void report_tdeny(struct Client *);
EXTERN void report_exempt(struct Client *);
EXTERN void add_dline(struct Client *, char *, char *, char *, int);

#ifdef IN_CONF_C
void init_deny(void);
#endif
