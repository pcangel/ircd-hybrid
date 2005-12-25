/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_user.h: A header for the user functions.
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

#ifndef INCLUDED_s_user_h
#define INCLUDED_s_user_h

#define IRC_MAXSID 3
#define IRC_MAXUID 6
#define TOTALSIDUID (IRC_MAXSID + IRC_MAXUID)

struct Client;
struct AccessItem;
struct ConfItem;

extern char new_uid[];

void init_uid(void);
void init_isupport(void);
void *change_simple_umode(va_list);
void *uid_get(va_list);

EXTERN int MaxClientCount;     /* GLOBAL - highest number of clients     */
EXTERN int MaxConnectionCount; /* GLOBAL - highest number of connections */
EXTERN struct Callback *entering_umode_cb;
EXTERN struct Callback *umode_cb;
EXTERN struct Callback *uid_get_cb;
EXTERN unsigned int user_modes[];

EXTERN void assemble_umode_buffer(void);
EXTERN void set_user_mode(struct Client *, struct Client *, int, char **);
EXTERN void send_umode(struct Client *, struct Client *,
                       unsigned int, unsigned int, char *);
EXTERN void send_umode_out(struct Client *, struct Client *, unsigned int);
EXTERN void show_lusers(struct Client *);
EXTERN void show_isupport(struct Client *);
EXTERN void oper_up(struct Client *, struct ConfItem *);

EXTERN void register_local_user(struct Client *, struct Client *,
                                const char *, const char *);
EXTERN void register_remote_user(struct Client *, struct Client *,
                                 const char *, const char *,
                                 const char *, const char *);
EXTERN int valid_hostname(const char *);
EXTERN int valid_username(const char *);
EXTERN void add_isupport(const char *, const char *, int);
EXTERN void delete_isupport(const char *);
EXTERN void rebuild_isupport_message_line(void);

#endif
