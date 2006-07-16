/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  hostmask.h: A header for the hostmask code.
 *
 *  Copyright (C) 2005 by the past and present ircd coders, and others.
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

#ifndef INCLUDE_hostmask_h
#define INCLUDE_hostmask_h 1

struct HostMaskEntry
{
  int type, subtype;
  unsigned long precedence;
  char *hostmask;
  void *data;
  struct HostMaskEntry *next, *nexthash;
};

EXTERN void report_Klines(struct Client *, int);
EXTERN void report_auth(struct Client *);

EXTERN char *make_iline_prefix(struct Client *, struct AccessItem *);
EXTERN struct AccessItem *find_address_conf(const char *, const char *,
                                            struct irc_ssaddr *, int, char *);
EXTERN struct AccessItem *find_kline_conf(const char *, const char *,
                                          struct irc_ssaddr *, int);
EXTERN struct AccessItem *find_gline_conf(const char *, const char *,
                                          struct irc_ssaddr *, int);
EXTERN struct AccessItem *find_dline_conf(const struct irc_ssaddr *, int);
EXTERN struct AccessItem *find_conf_by_address(const char *, const struct irc_ssaddr *,
                                               int, int, const char *, const char *);

#endif /* INCLUDE_hostmask_h */
