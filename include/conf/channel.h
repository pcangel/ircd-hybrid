/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  channel.h: Defines channel{} conf section.
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

struct ChannelConf
{
  char restrict_channels;
  char disable_local_channels;
  char use_invex, use_except;

  char use_knock;
  int knock_delay, knock_delay_channel;

  char burst_topicwho;
  int max_chans_per_user;
  char quiet_on_ban;
  int max_bans;
  int join_flood_count, join_flood_time;

  int default_split_user_count, default_split_server_count;
  char no_create_on_split, no_join_on_split;
};

extern struct ChannelConf Channel;

#ifdef IN_CONF_C
extern void init_channel(void);
#endif
