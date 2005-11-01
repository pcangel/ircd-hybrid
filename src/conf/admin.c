/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  admin.c: Defines the admin{} block of ircd.conf.
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

struct AdminConf Admin;

static dlink_node *hreset;

/*
 * reset_admin()
 *
 * Sets up default values before a rehash.
 *
 * inputs: none
 * output: none
 */
static void *
reset_admin(va_list args)
{
  if (!conf_cold)
  {
    MyFree(Admin.name);
    MyFree(Admin.description);
    MyFree(Admin.email);
  }

  Admin.name = Admin.description = Admin.email = NULL;

  return pass_callback(hreset);
}

/*
 * init_admin()
 *
 * Defines the admin{} conf section.
 *
 * inputs: none
 * output: none
 */
void
init_admin(void)
{
  struct ConfSection *s = add_conf_section("admin", 2);

  hreset = install_hook(reset_conf, reset_admin);

  add_conf_field(s, "name", CT_STRING, NULL, &Admin.name);
  add_conf_field(s, "description", CT_STRING, NULL, &Admin.description);
  add_conf_field(s, "email", CT_STRING, NULL, &Admin.email);
}
