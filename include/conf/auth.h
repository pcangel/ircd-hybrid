/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  auth.h: Defines auth{} conf section.
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

#define AUTH_FLAG_SPOOF_NOTICE  1
#define AUTH_FLAG_EXCEED_LIMIT  2
#define AUTH_FLAG_KLINE_EXEMPT  4
#define AUTH_FLAG_NEED_IDENT    8
#define AUTH_FLAG_CAN_FLOOD     16
#define AUTH_FLAG_CAN_IDLE      32
#define AUTH_FLAG_NO_TILDE      64
#define AUTH_FLAG_GLINE_EXEMPT  128
#define AUTH_FLAG_RESV_EXEMPT   256
#define AUTH_FLAG_NEED_PASSWORD 512
#define AUTH_FLAG_ENCRYPTED     1024

struct AuthConf
{
  struct AccessConf access;
  struct Class *class_ptr;
  unsigned int flags;
  char *spoof;
  char *password;
  char *redirserv;
  int redirport;
};

EXTERN int acb_type_auth;

struct Client;

EXTERN struct AuthConf *find_iline(const char *, const char *,
  const struct irc_ssaddr *, const char *);
EXTERN void report_auth(struct Client *);

#ifdef IN_CONF_C
void init_ilines(void);
#endif
