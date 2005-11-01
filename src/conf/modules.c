/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  modules.c: Defines the modules{} block of ircd.conf.
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
#include "modules.h"

#ifndef STATIC_MODULES

static dlink_node *hreset, *hpass;

/* XXX should move things from src/modules.c here later */

static void *
reset_modules(va_list args)
{
  mod_clear_paths();
  return pass_callback(hreset);
}

static void *
load_modules(va_list args)
{
  if (conf_pass == 2)
  {
    if (conf_cold)
    {
      load_core_modules(1);
      load_all_modules(1);
    }

    load_conf_modules();
  }

  return pass_callback(hpass);
}

static void
_mod_add_path(void *value, void *unused)
{
  char *path = (char *) value;

  if (!chdir(path))
  {
    chdir(DPATH);
    mod_add_path((char *) value);
  }
  else
    parse_error("directory not found");
}

static void
_mod_add_module(void *value, void *unused)
{
  add_conf_module((char *) value);
}

/*
 * init_modules()
 *
 * Defines the modules{} conf section.
 *
 * inputs: none
 * output: none
 */
void
init_modules(void)
{
  struct ConfSection *s = add_conf_section("modules", 1);

  hreset = install_hook(reset_conf, reset_modules);
  hpass = install_hook(switch_conf_pass, load_modules);

  add_conf_field(s, "path", CT_STRING, _mod_add_path, NULL);
  add_conf_field(s, "module", CT_STRING, _mod_add_module, NULL);
}

#endif
