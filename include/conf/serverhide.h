/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  serverhide.h: Defines serverhide{} conf section.
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

struct ServerHideConf
{
  char flatten_links;
  int links_delay;
  char hidden;
  char disable_hidden;
  char hide_servers;
  char *hidden_name;
  char hide_server_ips;
};

EXTERN struct ServerHideConf ServerHide;

#define LINKS_DELAY (ServerHide.flatten_links ? ServerHide.links_delay : 0)

#ifdef IN_CONF_C
void init_serverhide(void);
#endif
