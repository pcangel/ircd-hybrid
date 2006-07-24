/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  connect.h: Defines connect{} conf section.
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

#define LINK_COMPRESSED 1
#define LINK_CRYPTLINK  2
#define LINK_CRYPTPWD   4
#define LINK_AUTOCONN   8
#define LINK_BURSTAWAY  16
#define LINK_TOPICBURST 32
#define LINK_STALE      64

struct ConnectConf
{
  char *name;
  char *host;
  int aftype;
  int port;
  char *allow_host;
  struct irc_ssaddr vhost;
  char *send_password;
  char *accept_password;
  char *fakename;
  struct Class *class_ptr;
  dlink_list hub_list;
  dlink_list leaf_list;
#ifdef HAVE_LIBCRYPTO
  RSA *rsa_public_key;
  struct EncCapability *cipher_preference;
#endif
  time_t hold;
  unsigned int flags;
  dlink_node node;
  int refcnt;
};

EXTERN dlink_list connect_confs;

EXTERN struct ConnectConf *ref_link_by_ptr(struct ConnectConf *);
EXTERN void unref_link(struct ConnectConf *);

#ifdef IN_CONF_C
void init_connect(void);
#endif
