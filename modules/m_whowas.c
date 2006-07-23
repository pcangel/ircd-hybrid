/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_whois.c: Shows who a user was.
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
#include "ircd_defs.h"
#include "whowas.h"
#include "handlers.h"
#include "client.h"
#include "hash.h"
#include "ircd.h"
#include "numeric.h"
#include "s_serv.h"
#include "s_user.h"
#include "send.h"
#include "parse.h"
#include "msg.h"
#include "conf/modules.h"


static void m_whowas(struct Client *, struct Client *, int, char *[]);
static void whowas_do(struct Client *, int, char *[]);

struct Message whowas_msgtab = {
  "WHOWAS", 0, 0, 0, 0, MFLG_SLOW, 0,
  { m_unregistered, m_whowas, m_whowas, m_ignore, m_whowas, m_ignore }
};

INIT_MODULE(m_whowas, "$Revision$")
{
  mod_add_cmd(&whowas_msgtab);
}

CLEANUP_MODULE
{
  mod_del_cmd(&whowas_msgtab);
}

/*! \brief WHOWAS command handler (called for both local an remote clients)
 *
 * \param client_p Pointer to allocated Client struct with physical connection
 *                 to this server, i.e. with an open socket connected.
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = sender prefix
 *      - parv[1] = nick
 *      - parv[2] = count (optional; limited to 20 for remote requests)
 *      - parv[3] = name of target (optional; string can be a nick or server
 *                  and can also include wildcards)
 */
static void
m_whowas(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  static time_t last_used = 0;

  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NONICKNAMEGIVEN),
               me.name, source_p->name);
    return;
  }

  if (MyConnect(source_p) && !IsOper(source_p))
  {
    if ((last_used + ConfigFileEntry.pace_wait) > CurrentTime)
    {
      sendto_one(source_p,form_str(RPL_LOAD2HI),
                 me.name, source_p->name);
      return;
    }

    last_used = CurrentTime;
  }

  whowas_do(source_p, parc, parv);
}

static void
whowas_do(struct Client *source_p, int parc, char *parv[])
{
  const dlink_node *ptr = NULL;
  const char *nick = NULL;
  int cur = 0;
  int max = -1;

  if (parc > 2)
  {
    max = atoi(parv[2]);

    if (!MyConnect(source_p) && max > 20)
      max = 20;
  }

  if (parc > 3)
    if (hunt_server(source_p, ":%s WHOWAS %s %s :%s", 3,
                    parc, parv) != HUNTED_ISME)
      return;

  nick = parv[1];

  DLINK_FOREACH(ptr, WHOWASHASH[strhash(nick)].head)
  {
    const struct Whowas *temp = ptr->data;

    if (!irccmp(nick, temp->name))
    {
      sendto_one(source_p, form_str(RPL_WHOWASUSER),
                 me.name, source_p->name, temp->name,
                 temp->username, temp->hostname,
                 temp->realname);

      if (ConfigServerHide.hide_servers && !IsOper(source_p))
        sendto_one(source_p, form_str(RPL_WHOISSERVER),
                   me.name, source_p->name, temp->name,
                   ServerInfo.network_name, myctime(temp->logoff));
      else
        sendto_one(source_p, form_str(RPL_WHOISSERVER),
                   me.name, source_p->name, temp->name,
                   temp->servername, myctime(temp->logoff));
      ++cur;
    }

    if (max > 0 && cur >= max)
      break;
  }

  if (!cur)
    sendto_one(source_p, form_str(ERR_WASNOSUCHNICK),
               me.name, source_p->name, nick);

  sendto_one(source_p, form_str(RPL_ENDOFWHOWAS),
             me.name, source_p->name, parv[1]);
}
