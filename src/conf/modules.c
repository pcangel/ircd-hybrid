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
#include "client.h"
#include "ircd_defs.h"
#include "send.h"
#include "restart.h"

dlink_list loaded_modules = {NULL, NULL, 0};

#ifdef STATIC_MODULES
static struct Module statmods[] = {STATIC_MODULES, NULL};
#endif
static dlink_list mod_paths = {NULL, NULL, 0};
static dlink_list mod_extra = {NULL, NULL, 0};
static dlink_node *hreset, *hpass;

static const char *core_modules[] =
{
  "m_die",
  "m_join",
  "m_kick",
  "m_kill",
  "m_message",
  "m_mode",
  "m_nick",
  "m_part",
  "m_quit",
  "m_server",
  "m_sjoin",
  "m_squit",
  NULL
};

//
// Windows ignores case in file names, so using M_PART for m_part
// is perfectly legal.
//

#ifdef _WIN32
# define _COMPARE   strcasecmp
# define _NCOMPARE  strncasecmp
#else
# define _COMPARE   strcmp
# define _NCOMPARE  strncmp
#endif

/*
 * find_module()
 *
 * Checks if a module is loaded.
 *
 * inputs: module name (with or without path/suffix)
 * output: pointer to struct Module or NULL
 */
struct Module *
find_module(const char *filename)
{
  dlink_node *ptr;
  char *name = basename(name), *p;
  int cnt = ((p = strchr(name, '.')) != NULL ? p - name : strlen(name));

  DLINK_FOREACH(ptr, loaded_modules.head)
  {
    struct Module *mod = ptr->data;

    if (!_NCOMPARE(mod->name, name, cnt) && !mod->name[cnt])
      return mod;
  }

  return NULL;
}

/*
 * load_module()
 *
 * A module is loaded from a file or taken from the static pool, if available.
 *
 * inputs:
 *   - module name (without path, with suffix if needed)
 *   - core module flag [YES/NO]
 * output:
 *   -1 if the module was already loaded (no error message),
 *    0 if loading failed (errors reported),
 *    1 if ok (success reported)
 */
int
load_module(const char *filename, int core)
{
  char name[PATH_MAX], *p;
  struct Module *mod = NULL;

  if (find_module(filename) != NULL)
    return -1;

  if (strpbrk(filename, "\\/"))   
    goto NotFound;

  //
  // Extract module name e.g. "m_part"
  //
  strlcpy(name, basename(filename), sizeof(name));
  if ((p = strchr(name, '.')) != NULL)
    *p = 0;

#ifdef DYNAMIC_MODULES
  {
    void *handle = NULL, *base;

    //
    // Try all paths specified in ircd.conf
    //
    DLINK_FOREACH(ptr, mod_paths.head)
    {
      char buf[PATH_MAX];

      snprintf(buf, sizeof(buf), "%s/%s", ptr->data, filename);
      if ((handle = modload(buf, &base)) != NULL)
        break;
    }

    //
    // Set 'mod' variable if mapped successfully
    //
    if (handle != NULL)
    {
      int cnt = strlen(name);
      struct Module *mod;

      strlcat(name, "_module", sizeof(name));

      if ((mod = modsym(handle, name)) == NULL)
      {
        ilog(L_CRIT, "File %s is not a hybrid module", filename);
        sendto_realops_flags(UMODE_ALL, L_ALL,
          "File %s is not a hybrid module", filename);

        modclose(handle);
        return 0;
      }

      mod->handle = handle;
      mod->address = address;
    }
  }
#endif

#ifdef STATIC_MODULES
  if (mod == NULL)
  {
    struct Module **mptr;

    //
    // Try static modules if there are any
    //
    for (mptr = statmods; *mptr; mptr++)
      if (!_COMPARE((*mptr)->name, filename))
      {
        mod = *mptr;
        break;
      }
  }
#endif

  //
  // Generate the final message
  //
  if (mod == NULL)
  {
    NotFound:
    ilog(L_CRIT, "Cannot locate module %s", filename);
    sendto_realops_flags(UMODE_ALL, L_ALL, "Cannot locate module %s",
      filename);
  }
  else
  {
    char message[IRCD_BUFSIZE];

    if (mod->address != NULL)
      snprintf(message, sizeof(message), "Module %s loaded at %p",
        mod->name, mod->address);
    else
      snprintf(message, sizeof(message), "Module %s loaded %s",
        mod->name, mod->handle ? "dynamically" : "statically");

    ilog(L_NOTICE, "%s", message);
    sendto_realops_flags(UMODE_ALL, L_ALL, "%s", message);

    dlinkAdd(mod, &mod->node, &loaded_modules);
    mod->core = core;
    mod->modinit();
  }

  return !!mod;
}

/*
 * unload_module()
 *
 * A module is unloaded. This is actually MUCH simplier.
 *
 * inputs: pointer to struct Module
 * output: none
 */
void
unload_module(struct Module *mod)
{
  mod->modremove();

  dlinkDelete(&mod->node, &loaded_modules);

#ifdef DYNAMIC_MODULES
  if (mod->handle != NULL)
    modclose(mod->handle);
#endif
}

/*
 * boot_static_modules()
 *
 * Run modinit and link these statically linked modules which
 * are not already overridden by dynamic ones.
 *
 * inputs: none
 * output: none
 */


/*
 * reset_modules()
 *
 * Called before entering the conf parser.
 * Clears out module paths.
 *
 * inputs: none
 * output: none
 */
static void *
reset_modules(va_list args)
{
  dlink_node *ptr, *ptr_next;

  DLINK_FOREACH_SAFE(ptr, ptr_next, mod_paths.head)
  {
    MyFree(ptr->data);
    dlinkDelete(ptr, &mod_paths);
    free_dlink_node(ptr);
  }

  DLINK_FOREACH_SAFE(ptr, ptr_next, mod_extra.head)
  {
    MyFree(ptr->data);
    dlinkDelete(ptr, &mod_extra);
    free_dlink_node(ptr);
  }

  return pass_callback(hreset);
}

/*
 * load_modules()
 *
 * Called just after switching to pass 2 parsing.  Implements module
 * bootup, loads extra modules, verifies that core modules are loaded.
 *
 * inputs: none
 * output: none
 */
static void *
load_modules(va_list args)
{
  if (conf_pass == 2)
  {
    dlink_node *ptr;
    const char **p;

    if (conf_cold)
    {
      boot_dynamic_modules();
      boot_static_modules();
    }

    DLINK_FOREACH_SAFE(ptr, mod_extra.head)
      if (!find_module(ptr->data))
        load_module(ptr->data, 0);

    for (p = core_modules; *p; p++)
      if (!find_module(*p))
      {
        ilog(L_CRIT, "Core module %s is missing", *p);
        if (conf_cold)
          server_die("No core modules", 0);
      }
  }

  return pass_callback(hpass);
}

/*
 * mod_add_path()
 *
 * Deals with path="..." conf entry.
 *
 * inputs: value text
 * output: none
 */
static void
mod_add_path(void *value, void *unused)
{
  if (!chdir((char *) value))
  {
    char *path;

    chdir(DPATH);
    DupString(path, (char *) value);

    dlinkAddTail(path, make_dlink_node(), &mod_paths);
  }
  else
    parse_error("directory not found");
}

/*
 * mod_add_module()
 *
 * Deals with module="..." conf entry.
 *
 * inputs: value text
 * output: none
 */
static void
mod_add_module(void *value, void *unused)
{
  char *name;

  DupString(name, (char *) value);
  dlinkAddTail(name, make_dlink_node(), &mod_extra);
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

  add_conf_field(s, "path", CT_STRING, mod_add_path, NULL);
  add_conf_field(s, "module", CT_STRING, mod_add_module, NULL);
}
