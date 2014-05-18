/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2005-2014 ircd-hybrid development team
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
 */

/*! \file m_services.c
 * \brief Includes required functions for processing the CS/NS/MS/OS/BS services command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
//#include "channel_mode.h"
#include "numeric.h"
#include "conf.h"
#include "server.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "irc_string.h"
#include "user.h"
#include "hash.h"


/*
 * XXX: Each services alias handler is currently ugly copy&paste.
 * Configureable aliases will get implemented.
 */

static void
do_service_alias(struct Client *source_p, const char *name, const char *msg)
{
  struct Client *target_p = NULL;
  struct Client *server_p = NULL;

  if (EmptyString(msg))
  {
    sendto_one_numeric(source_p, &me, ERR_NOTEXTTOSEND);
    return;
  }

  target_p = find_person(source_p, name);
  server_p = hash_find_server(ConfigFileEntry.service_name);

  if (target_p && server_p && (target_p->servptr == server_p))
  {
    sendto_one(target_p, ":%s PRIVMSG %s :%s",
               source_p->id, target_p->id, msg);
    return;
  }

  sendto_one_numeric(source_p, &me, ERR_SERVICESDOWN, name);
}

static int
m_nickserv(struct Client *source_p, int parc, char *parv[])
{
  do_service_alias(source_p, "NickServ", parv[1]);
  return 0;
}

static int
m_chanserv(struct Client *source_p, int parc, char *parv[])
{
  do_service_alias(source_p, "ChanServ", parv[1]);
  return 0;
}

static int
m_memoserv(struct Client *source_p, int parc, char *parv[])
{
  do_service_alias(source_p, "MemoServ", parv[1]);
  return 0;
}

static int
m_operserv(struct Client *source_p, int parc, char *parv[])
{
  do_service_alias(source_p, "OperServ", parv[1]);
  return 0;
}

static int
m_statserv(struct Client *source_p, int parc, char *parv[])
{
  do_service_alias(source_p, "StatServ", parv[1]);
  return 0;
}

static int
m_hostserv(struct Client *source_p, int parc, char *parv[])
{
  do_service_alias(source_p, "HostServ", parv[1]);
  return 0;
}

static int
m_botserv(struct Client *source_p, int parc, char *parv[])
{
  do_service_alias(source_p, "BotServ", parv[1]);
  return 0;
}


static struct Message ms_msgtab =
{
  "MS", 0, 0, 0, 1, MFLG_SLOW, 0,
  { m_unregistered, m_memoserv, m_ignore, m_ignore, m_memoserv, m_ignore }
};

static struct Message ns_msgtab =
{
  "NS", 0, 0, 0, 1, MFLG_SLOW, 0,
  { m_unregistered, m_nickserv, m_ignore, m_ignore, m_nickserv, m_ignore }
};

static struct Message os_msgtab =
{
  "OS", 0, 0, 0, 1, MFLG_SLOW, 0,
  { m_unregistered, m_operserv, m_ignore, m_ignore, m_operserv, m_ignore }
};

static struct Message bs_msgtab =
{
  "BS", 0, 0, 0, 1, MFLG_SLOW, 0,
  { m_unregistered, m_botserv, m_ignore, m_ignore, m_botserv, m_ignore }
};

static struct Message cs_msgtab =
{
  "CS", 0, 0, 0, 1, MFLG_SLOW, 0,
  { m_unregistered, m_chanserv, m_ignore, m_ignore, m_chanserv, m_ignore }
};

static struct Message ss_msgtab =
{
  "SS", 0, 0, 0, 1, MFLG_SLOW, 0,
  { m_unregistered, m_statserv, m_ignore, m_ignore, m_statserv, m_ignore }
};

static struct Message hs_msgtab =
{
  "HS", 0, 0, 0, 1, MFLG_SLOW, 0,
  { m_unregistered, m_hostserv, m_ignore, m_ignore, m_hostserv, m_ignore }
};

static struct Message botserv_msgtab =
{
  "BOTSERV", 0, 0, 0, 1, MFLG_SLOW, 0,
  { m_unregistered, m_botserv, m_ignore, m_ignore, m_botserv, m_ignore }
};

static struct Message chanserv_msgtab =
{
  "CHANSERV", 0, 0, 0, 1, MFLG_SLOW, 0,
  { m_unregistered, m_chanserv, m_ignore, m_ignore, m_chanserv, m_ignore }
};

static struct Message memoserv_msgtab =
{
  "MEMOSERV", 0, 0, 0, 1, MFLG_SLOW, 0,
  { m_unregistered, m_memoserv, m_ignore, m_ignore, m_memoserv, m_ignore }
};

static struct Message nickserv_msgtab =
{
  "NICKSERV", 0, 0, 0, 1, MFLG_SLOW, 0,
  { m_unregistered, m_nickserv, m_ignore, m_ignore, m_nickserv, m_ignore }
};

static struct Message operserv_msgtab =
{
  "OPERSERV", 0, 0, 0, 1, MFLG_SLOW, 0,
  { m_unregistered, m_operserv, m_ignore, m_ignore, m_operserv, m_ignore }
};

static struct Message statserv_msgtab =
{
  "STATSERV", 0, 0, 0, 1, MFLG_SLOW, 0,
  { m_unregistered, m_statserv, m_ignore, m_ignore, m_statserv, m_ignore }
};

static struct Message hostserv_msgtab =
{
  "HOSTSERV", 0, 0, 0, 1, MFLG_SLOW, 0,
  { m_unregistered, m_hostserv, m_ignore, m_ignore, m_hostserv, m_ignore }
};


static void
module_init(void)
{
  mod_add_cmd(&botserv_msgtab);
  mod_add_cmd(&chanserv_msgtab);
  mod_add_cmd(&memoserv_msgtab);
  mod_add_cmd(&nickserv_msgtab);
  mod_add_cmd(&operserv_msgtab);
  mod_add_cmd(&statserv_msgtab);
  mod_add_cmd(&hostserv_msgtab);
  mod_add_cmd(&bs_msgtab);
  mod_add_cmd(&ns_msgtab);
  mod_add_cmd(&cs_msgtab);
  mod_add_cmd(&ms_msgtab);
  mod_add_cmd(&os_msgtab);
  mod_add_cmd(&ss_msgtab);
  mod_add_cmd(&hs_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&botserv_msgtab);
  mod_del_cmd(&chanserv_msgtab);
  mod_del_cmd(&memoserv_msgtab);
  mod_del_cmd(&nickserv_msgtab);
  mod_del_cmd(&operserv_msgtab);
  mod_del_cmd(&statserv_msgtab);
  mod_del_cmd(&hostserv_msgtab);
  mod_del_cmd(&bs_msgtab);
  mod_del_cmd(&ns_msgtab);
  mod_del_cmd(&cs_msgtab);
  mod_del_cmd(&ms_msgtab);
  mod_del_cmd(&os_msgtab);
  mod_del_cmd(&ss_msgtab);
  mod_del_cmd(&hs_msgtab);
}

struct module module_entry =
{
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
