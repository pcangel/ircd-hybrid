/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  modules.c: A module loader.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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
#include "msg.h"
#include "conf/modules.h"
#include "ircd.h"
#include "client.h"
#include "send.h"
#include "s_conf.h"
#include "handlers.h"
#include "numeric.h"
#include "parse.h"
#include "ircd_defs.h"
#include "s_user.h"

static void mo_modload(struct Client *, struct Client *, int, char *[]);
static void mo_modlist(struct Client *, struct Client *, int, char *[]);
static void mo_modreload(struct Client *, struct Client *, int, char *[]);
static void mo_modunload(struct Client *, struct Client *, int, char *[]);
static void mo_modrestart(struct Client *, struct Client *, int, char *[]);

struct Message modload_msgtab = {
 "MODLOAD", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, m_ignore, mo_modload, m_ignore}
};

struct Message modunload_msgtab = {
 "MODUNLOAD", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, m_ignore, mo_modunload, m_ignore}
};

struct Message modreload_msgtab = {
  "MODRELOAD", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, m_ignore, mo_modreload, m_ignore}
};

struct Message modlist_msgtab = {
 "MODLIST", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, m_ignore, mo_modlist, m_ignore}
};

struct Message modrestart_msgtab = {
 "MODRESTART", 0, 0, 0, 0, MFLG_SLOW, 0,
 {m_unregistered, m_not_oper, m_ignore, m_ignore, mo_modrestart, m_ignore}
};

extern struct Message error_msgtab;

/* load a module .. */
static void
mo_modload(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  char *m_bn;

  if (!IsAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  m_bn = basename(parv[1]);

  if (findmodule_byname(m_bn) != NULL)
  {
    sendto_one(source_p, ":%s NOTICE %s :Module %s is already loaded",
               me.name, source_p->name, m_bn);
    return;
  }

  load_one_module(parv[1], 0);
}

/* unload a module .. */
static void
mo_modunload(struct Client *client_p, struct Client *source_p,
             int parc, char *parv[])
{
  char *m_bn;
  dlink_node *ptr;
  struct module *modp;

  if (!IsAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  m_bn = basename(parv[1]);

  if ((ptr = findmodule_byname(m_bn)) == NULL)
  {
    sendto_one(source_p, ":%s NOTICE %s :Module %s is not loaded",
               me.name, source_p->name, m_bn);
    return;
  }

  modp = ptr->data;

  if (modp->core == 1)
  {
    sendto_one(source_p,
               ":%s NOTICE %s :Module %s is a core module and may not be unloaded",
	       me.name, source_p->name, m_bn);
    return;
  }

  /* XXX might want to simply un dlink it here */

  if (unload_one_module(m_bn, 1) == -1)
  {
    sendto_one(source_p, ":%s NOTICE %s :Module %s is not loaded",
               me.name, source_p->name, m_bn);
  }
}

/* unload and load in one! */
static void
mo_modreload(struct Client *client_p, struct Client *source_p,
             int parc, char *parv[])
{
  char *m_bn;
  dlink_node *ptr;
  struct module *modp;
  int check_core;

  if (!IsAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  m_bn = basename(parv[1]);

  if ((ptr = findmodule_byname(m_bn)) == NULL)
  {
    sendto_one(source_p, ":%s NOTICE %s :Module %s is not loaded",
               me.name, source_p->name, m_bn);
    return;
  }

  modp = ptr->data;
  check_core = modp->core;

  if (unload_one_module(m_bn, 1) == -1)
  {
    sendto_one(source_p, ":%s NOTICE %s :Module %s is not loaded",
               me.name, source_p->name, m_bn);
    return;
  }

  if ((load_one_module(parv[1], check_core) == -1) && check_core)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, "Error reloading core "
                         "module, %s: terminating ircd", parv[1]);
    ilog(L_CRIT, "Error loading core module %s, terminating ircd", parv[1]);
    exit(0);
  }
}

/* list modules .. */
static void
mo_modlist(struct Client *client_p, struct Client *source_p,
	   int parc, char *parv[])
{
  dlink_node *ptr;
  struct module *modp;

  if (!IsAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  DLINK_FOREACH(ptr, mod_list.head)
  {
    modp = ptr->data;

    if (parc > 1)
    {
      if (match(parv[1], modp->name))
      {
        sendto_one(source_p, form_str(RPL_MODLIST), me.name, parv[0],
                   modp->name, modp->address,
                   modp->version, modp->core?"(core)":"");
      }
    }
    else
    {
      sendto_one(source_p, form_str(RPL_MODLIST), me.name, parv[0],
                 modp->name, modp->address,
                 modp->version, modp->core?"(core)":"");
    }
  }

  sendto_one(source_p, form_str(RPL_ENDOFMODLIST),
             me.name, source_p->name);
}

/* unload and reload all modules */
static void
mo_modrestart(struct Client *client_p, struct Client *source_p,
              int parc, char *parv[])
{
  unsigned int modnum = 0;
  dlink_node *ptr;
  dlink_node *tptr;
  struct module *modp;
  
  if (!IsAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  sendto_one(source_p, ":%s NOTICE %s :Reloading all modules",
             me.name, source_p->name);

  modnum = dlink_list_length(&mod_list);

  DLINK_FOREACH_SAFE(ptr, tptr, mod_list.head)
  {
    modp = ptr->data;
    unload_one_module(modp->name, 0);
  }

  load_all_modules(0);
  load_conf_modules();
  load_core_modules(0);

  sendto_realops_flags(UMODE_ALL, L_ALL,
              "Module Restart: %u modules unloaded, %lu modules loaded",
			modnum, dlink_list_length(&mod_list));
  ilog(L_WARN, "Module Restart: %u modules unloaded, %lu modules loaded",
       modnum, dlink_list_length(&mod_list));
}
