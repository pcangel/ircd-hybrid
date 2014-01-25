/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2014 ircd-hybrid development team
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
 */

/*! \file s_auth.h
 * \brief A header for the ident functions.
 * \version $Id$
 */

#ifndef INCLUDED_s_auth_h
#define INCLUDED_s_auth_h

enum
{
  AM_IN_AUTH     = 1 << 0,
  AM_DOING_AUTH  = 1 << 1,
  AM_DNS_PENDING = 1 << 2
};

#define SetInAuth(x)         ((x)->flags |= AM_IN_AUTH)
#define ClearInAuth(x)       ((x)->flags &= ~AM_IN_AUTH)
#define IsInAuth(x)          ((x)->flags &  AM_IN_AUTH)

#define SetDNSPending(x)     ((x)->flags |= AM_DNS_PENDING)
#define ClearDNSPending(x)   ((x)->flags &= ~AM_DNS_PENDING)
#define IsDNSPending(x)      ((x)->flags &  AM_DNS_PENDING)

#define SetDoingAuth(x)      ((x)->flags |= AM_DOING_AUTH)
#define ClearAuth(x)         ((x)->flags &= ~AM_DOING_AUTH)
#define IsDoingAuth(x)       ((x)->flags &  AM_DOING_AUTH)

struct Client;

struct AuthRequest
{
  dlink_node     node;  /* auth_doing_list */
  int            flags;
  struct Client *client;    /* pointer to client struct for request */
  fde_t          fd;        /* file descriptor for auth queries */
  time_t         timeout;   /* time when query expires */
};

extern void auth_init(void);
extern void start_auth(struct Client *);
extern void send_auth_query(struct AuthRequest *);
extern void remove_auth_request(struct AuthRequest *);
extern void delete_auth(struct AuthRequest *);
extern void release_auth_client(struct AuthRequest *);
#endif /* INCLUDED_s_auth_h */
