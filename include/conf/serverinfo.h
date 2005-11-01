/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  serverinfo.h: Defines serverinfo{} conf section.
 *
 *  Copyright (C) 2005 by the Hybrid Development Team.
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

struct ServerInfoConf
{
  char *network_name, *network_desc;
  char hub;
  struct irc_ssaddr vhost;
#ifdef IPV6
  struct irc_ssaddr vhost6;
#endif
  int max_clients;
#ifdef HAVE_LIBCRYPTO
  char *rsa_private_key_file;
  RSA *rsa_private_key;
  SSL_CTX *ctx;
#endif
};

extern struct ServerInfoConf ServerInfo;

#ifdef IN_CONF_C
void init_serverinfo(void);
#endif
