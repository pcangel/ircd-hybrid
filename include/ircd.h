/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  ircd.h: A header for the ircd startup routines.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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

#ifndef INCLUDED_ircd_h
#define INCLUDED_ircd_h

#include "ircd_defs.h"
#include "setup.h"

struct Client;
struct dlink_list;

struct SetOptions
{
  int autoconn;      /* autoconn enabled for all servers? */
  int idletime;
  int floodcount;    /* Number of messages in 1 second    */
  /* XXX for join flood catching - Dianora */
  int joinfloodtime;
  int joinfloodcount;
  /* XXX */
  int rejecttime;
  int ident_timeout; /* timeout for identd lookups        */
  int spam_num;
  int spam_time;
  int maxlisters;
};

struct Counter
{
  int myserver; /* my servers          */
  int oper;     /* Opers               */
  int local;    /* Local Clients       */
  int total;    /* total clients       */
  int invisi;   /* invisible clients   */
  int max_loc;  /* MAX local clients   */
  int max_tot;  /* MAX global clients  */
  unsigned long totalrestartcount; /* Total client count ever */
};

struct ServerState_t
{
  int foreground;
};

char *get_ircd_platform(char *);

EXTERN struct SetOptions GlobalSetOptions; /* defined in ircd.c */
EXTERN unsigned long connect_id;	/* unique connect ID */
EXTERN struct ServerState_t server_state;
EXTERN char **myargv;
EXTERN char ircd_platform[PLATFORMLEN];
EXTERN const char *infotext[];
EXTERN const char *serno;
EXTERN const char *ircd_version;
EXTERN const char *logFileName;
EXTERN const char *pidFileName;
EXTERN int dorehash;
EXTERN int doremotd;
EXTERN struct Counter Count;
EXTERN time_t nextconnect;
EXTERN int default_server_capabs;
#ifdef HAVE_LIBCRYPTO
EXTERN int bio_spare_fd;
#endif /* HAVE_LIBCRYPTO */

EXTERN int splitmode;
EXTERN int splitchecking;
EXTERN int split_users;
EXTERN unsigned int split_servers;

EXTERN dlink_list unknown_list;       /* unknown clients ON this server only        */
EXTERN dlink_list local_client_list;  /* local clients only ON this server          */
EXTERN dlink_list serv_list;          /* local servers to this server ONLY          */
EXTERN dlink_list global_serv_list;   /* global servers on the network              */
EXTERN dlink_list oper_list;          /* our opers, duplicated in local_client_list */
EXTERN dlink_list lazylink_channels;  /* known about lazylink channels on HUB       */
EXTERN int rehashed_klines;
EXTERN unsigned long get_maxrss(void);

#endif
