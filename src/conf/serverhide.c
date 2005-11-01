/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  serverhide.c: Defines the serverhide{} block of ircd.conf.
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
#include "s_serv.h"

struct ServerHideConf ServerHide;

static dlink_node *hreset, *hverify;
static int old_links_delay;

/*
 * reset_serverhide()
 *
 * Sets up default values before a rehash.
 *
 * inputs: none
 * output: none
 */
static void *
reset_serverhide(va_list args)
{
  int cold = va_arg(args, int);

  old_links_delay = cold ? 0 : LINKS_DELAY;

  ServerHide.flatten_links = NO;
  ServerHide.links_delay = 5*60;
  ServerHide.hidden = ServerHide.disable_hidden = ServerHide.hide_servers = NO;
  if (!cold)
    MyFree(ServerHide.hidden_name);
  DupString(ServerHide.hidden_name, "*.hidden.com");
  ServerHide.hide_server_ips = NO;

  return pass_callback(hreset, cold);
}

/*
 * verify_serverhide()
 *
 * Sets up the delayed links timer if necessary. (After a rehash)
 *
 * inputs: none
 * output: none
 */
static void *
verify_serverhide(va_list args)
{
  int cold = va_arg(args, int);
  int new_links_delay = LINKS_DELAY;

  if (new_links_delay != old_links_delay)
  {
    if (old_links_delay != 0)
      eventDelete(write_links_file, NULL);
    else
      write_links_file(NULL);

    if (new_links_delay != 0)
      eventAdd("write_links_file", write_links_file, NULL, new_links_delay);
  }

  return pass_callback(hverify, cold);
}

/*
 * init_serverhide()
 *
 * Defines the serverhide{} conf section.
 *
 * inputs: none
 * output: none
 */
void
init_serverhide(void)
{
  struct ConfSection *s = add_conf_section("serverhide", 2);

  hreset = install_hook(reset_conf, reset_serverhide);
  hverify = install_hook(verify_conf, verify_serverhide);

  add_conf_field(s, "flatten_links", CT_BOOL, NULL, &ServerHide.flatten_links);
  add_conf_field(s, "links_delay", CT_TIME, NULL, &ServerHide.links_delay);
  add_conf_field(s, "hidden", CT_BOOL, NULL, &ServerHide.hidden);
  add_conf_field(s, "disable_hidden", CT_BOOL, NULL,
    &ServerHide.disable_hidden);
  add_conf_field(s, "hide_servers", CT_BOOL, NULL, &ServerHide.hide_servers);
  add_conf_field(s, "hidden_name", CT_STRING, NULL, &ServerHide.hidden_name);
  add_conf_field(s, "hide_server_ips", CT_BOOL, NULL,
    &ServerHide.hide_server_ips);
}
