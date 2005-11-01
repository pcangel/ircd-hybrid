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

struct ServerHideConf ServerHide;

static dlink_node *hreset;

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

  return pass_callback(hreset, cold);
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

  hreset = install_hook(reset_conf, reset_channel);
}
