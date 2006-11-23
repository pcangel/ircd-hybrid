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
 *  $Id: /local/oftc-hybrid/branches/oftc-hybrid-1.5/src/modules.c 865 2006-06-08T22:35:55.339311Z stu  $
 */

#include "stdinc.h"
#include "conf/conf.h"
#include "client.h"
#include "ircd_defs.h"
#include "send.h"
#include "restart.h"
#include "msg.h"
#include "handlers.h"
#include "numeric.h"
#include "parse.h"

#ifndef STATIC_MODULES

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

/*
 * modules_init
 *
 * input	- NONE
 * output	- NONE
 * side effects	- The basic module manipulation modules are loaded
 */
void
modules_init(void)
{
  mod_add_cmd(&modload_msgtab);
  mod_add_cmd(&modunload_msgtab);
  mod_add_cmd(&modreload_msgtab);
  mod_add_cmd(&modlist_msgtab);
  mod_add_cmd(&modrestart_msgtab);
}

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

  if (find_module(m_bn, 1) != NULL)
  {
    sendto_one(source_p, ":%s NOTICE %s :Module %s is already loaded",
               me.name, source_p->name, m_bn);
    return;
  }

  load_module(parv[1]);
}

/* unload a module .. */
static void
mo_modunload(struct Client *client_p, struct Client *source_p,
             int parc, char *parv[])
{
  char *m_bn;
  struct Module *modp;

  if (!IsAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  m_bn = basename(parv[1]);

  if ((modp = find_module(m_bn, 1)) == NULL)
  {
    sendto_one(source_p, ":%s NOTICE %s :Module %s is not loaded",
               me.name, source_p->name, m_bn);
    return;
  }

  /* XXX might want to simply un dlink it here */

  unload_module(modp); 
}

/* unload and load in one! */
static void
mo_modreload(struct Client *client_p, struct Client *source_p,
             int parc, char *parv[])
{
  char *m_bn;
  struct Module *modp;
  int check_core;

  if (!IsAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  m_bn = basename(parv[1]);

  if ((modp = find_module(m_bn, 1)) == NULL)
  {
    sendto_one(source_p, ":%s NOTICE %s :Module %s is not loaded",
               me.name, source_p->name, m_bn);
    return;
  }

  unload_module(modp);
  load_module(parv[1]);
}

/* list modules .. */
static void
mo_modlist(struct Client *client_p, struct Client *source_p,
	   int parc, char *parv[])
{
  dlink_node *ptr;
  struct Module *modp;

  if (!IsAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  DLINK_FOREACH(ptr, loaded_modules.head)
  {
    modp = ptr->data;

    if (parc > 1)
    {
      if (match(parv[1], modp->name))
      {
        sendto_one(source_p, form_str(RPL_MODLIST), me.name, parv[0],
                   modp->name, modp->address,
                   modp->version, ""); 
      }
    }
    else
    {
      sendto_one(source_p, form_str(RPL_MODLIST), me.name, parv[0],
                 modp->name, modp->address,
                 modp->version, "");
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
  struct Module *modp;
  
  if (!IsAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  sendto_one(source_p, ":%s NOTICE %s :Reloading all modules",
             me.name, source_p->name);

  modnum = dlink_list_length(&loaded_modules);

  DLINK_FOREACH_SAFE(ptr, tptr, loaded_modules.head)
  {
    modp = ptr->data;
    unload_module(modp);
  }

  boot_modules(1);

  sendto_realops_flags(UMODE_ALL, L_ALL,
              "Module Restart: %u modules unloaded, %lu modules loaded",
			modnum, dlink_list_length(&loaded_modules));
  ilog(L_WARN, "Module Restart: %u modules unloaded, %lu modules loaded",
       modnum, dlink_list_length(&loaded_modules));
}
#endif /* STATIC_MODULES */
