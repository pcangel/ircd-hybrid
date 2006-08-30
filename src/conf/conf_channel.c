/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  conf_channel.c: Defines the channel{} block of ircd.conf.
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

#include "stdinc.h"
#include "conf/conf.h"
#include "channel.h"
#include "ircd.h"
#include "user.h"

struct ChannelConf Channel;

static dlink_node *hreset, *hverify;
static int old_use_splitcode;

/*
 * reset_channel()
 *
 * Sets up default values before a rehash.
 *
 * inputs: none
 * output: none
 */
static void *
reset_channel(va_list args)
{
  if (Channel.use_except)
    delete_isupport("EXCEPTS");
  if (Channel.use_invex)
    delete_isupport("INVEX");

  old_use_splitcode = conf_cold ? NO : USE_SPLITCODE;

  Channel.restrict_channels = Channel.disable_local_channels =
    Channel.disable_fake_channels = NO;
  Channel.use_invex = Channel.use_except = YES;

  Channel.use_knock = YES;
  Channel.knock_delay = 5*60, Channel.knock_delay_channel = 1*60;

  Channel.burst_topicwho = YES;
  Channel.max_chans_per_user = 15;
  Channel.quiet_on_ban = YES;
  Channel.max_bans = 25;
  Channel.join_flood_count = 16, Channel.join_flood_time = 8;

  Channel.default_split_user_count = Channel.default_split_server_count = 0;
  Channel.no_create_on_split = YES, Channel.no_join_on_split = NO;

  return pass_callback(hreset);
}

/*
 * verify_channel()
 *
 * Sets up splitmode event if necessary. (After a rehash)
 *
 * inputs: none
 * output: none
 */
static void *
verify_channel(va_list args)
{
  int new_use_splitcode = USE_SPLITCODE;
  char buf[IRCD_BUFSIZE];

  if (new_use_splitcode != old_use_splitcode)
  {
    if (old_use_splitcode)
    {
      eventDelete(check_splitmode, NULL);
      splitmode = NO;
    }
    else
    {
      eventAddIsh("check_splitmode", check_splitmode, NULL, 60);
      if (conf_cold)
        splitmode = YES;
      else
        check_splitmode(NULL);
    }
  }

  strcpy(buf, Channel.disable_local_channels ? "#" : "#&");
  add_isupport("CHANTYPES", buf, -1);
  ircsprintf(buf + strlen(buf), ":%d", Channel.max_chans_per_user);
  add_isupport("CHANLIMIT", buf, -1);

  ircsprintf(buf, "b%s%s,k,l,imnpst",
    Channel.use_except ? "e" : "", Channel.use_invex ? "I" : "");
  add_isupport("CHANMODES", buf, -1);

  ircsprintf(buf + 1 + !!Channel.use_except + !!Channel.use_invex,
    ":%d", Channel.max_bans);
  add_isupport("MAXLIST", buf, -1);

  if (Channel.use_except)
    add_isupport("EXCEPTS", "e", -1);
  if (Channel.use_invex)
    add_isupport("INVEX", "I", -1);

  return pass_callback(hverify);
}

/*
 * init_channel()
 *
 * Defines the channel{} conf section.
 *
 * inputs: none
 * output: none
 */
void
init_channel(void)
{
  struct ConfSection *s = add_conf_section("channel", 2);

  hreset = install_hook(reset_conf, reset_channel);
  hverify = install_hook(verify_conf, verify_channel);

  add_conf_field(s, "restrict_channels", CT_BOOL, NULL,
    &Channel.restrict_channels);
  add_conf_field(s, "disable_local_channels", CT_BOOL, NULL,
    &Channel.disable_local_channels);
  add_conf_field(s, "disable_fake_channels", CT_BOOL, NULL,
    &Channel.disable_fake_channels);
  add_conf_field(s, "use_invex", CT_BOOL, NULL, &Channel.use_invex);
  add_conf_field(s, "use_except", CT_BOOL, NULL, &Channel.use_except);

  add_conf_field(s, "use_knock", CT_BOOL, NULL, &Channel.use_knock);
  add_conf_field(s, "knock_delay", CT_TIME, NULL, &Channel.knock_delay);
  add_conf_field(s, "knock_delay_channel", CT_TIME, NULL,
    &Channel.knock_delay_channel);

  add_conf_field(s, "burst_topicwho", CT_BOOL, NULL, &Channel.burst_topicwho);
  add_conf_field(s, "max_chans_per_user", CT_NUMBER, NULL,
    &Channel.max_chans_per_user);
  add_conf_field(s, "quiet_on_ban", CT_BOOL, NULL, &Channel.quiet_on_ban);
  add_conf_field(s, "max_bans", CT_NUMBER, NULL, &Channel.max_bans);
  add_conf_field(s, "join_flood_count", CT_NUMBER, NULL,
    &Channel.join_flood_count);
  add_conf_field(s, "join_flood_time", CT_TIME, NULL,
    &Channel.join_flood_time);

  add_conf_field(s, "default_split_user_count", CT_NUMBER, NULL,
    &Channel.default_split_user_count);
  add_conf_field(s, "default_split_server_count", CT_NUMBER, NULL,
    &Channel.default_split_server_count);
  add_conf_field(s, "no_create_on_split", CT_BOOL, NULL,
    &Channel.no_create_on_split);
  add_conf_field(s, "no_join_on_split", CT_BOOL, NULL,
    &Channel.no_join_on_split);
}
