/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  hostmask.h: Provides support for IPv4/IPv6/DNS hostmasks.
 *
 *  Copyright (C) 2002-2006 by the past and present ircd coders, and others.
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

enum
{
  HM_HOST,
  HM_IPV4,
  HM_IPV6
};

LIBIO_EXTERN int match_ipv6(const struct irc_ssaddr *,
  const struct irc_ssaddr *, int);
LIBIO_EXTERN int match_ipv4(const struct irc_ssaddr *,
  const struct irc_ssaddr *, int);
LIBIO_EXTERN void mask_addr(struct irc_ssaddr *, int);
LIBIO_EXTERN int parse_netmask(const char *, struct irc_ssaddr *, int *);
LIBIO_EXTERN unsigned int hash_ip(const struct irc_ssaddr *, int, unsigned int);
