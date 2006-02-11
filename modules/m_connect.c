/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_connect.c: Connects to a remote IRC server.
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
#include "handlers.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "s_conf.h"
#include "s_serv.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "hash.h"
#include "modules.h"

static void mo_connect(struct Client *, struct Client *, int, char *[]);
static void ms_connect(struct Client *, struct Client *, int, char *[]);

struct Message connect_msgtab = {
  "CONNECT", 0, 0, 2, 0, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, ms_connect, m_ignore, mo_connect, m_ignore }
};

INIT_MODULE(m_connect, "$Revision$")
{
  mod_add_cmd(&connect_msgtab);
}

CLEANUP_MODULE
{
  mod_del_cmd(&connect_msgtab);
}

/*! \brief CONNECT command handler (called for operators only)
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
 *      - parv[1] = servername
 *      - parv[2] = port number
 *      - parv[3] = remote server
 */
static void
mo_connect(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  int port = 0;
  struct ConfItem *conf = NULL;
  struct AccessItem *aconf = NULL;
  struct Client *target_p = NULL;

  /* always privileged with handlers */
  if (MyConnect(source_p) && !IsOperRemote(source_p) && parc > 3)
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, source_p->name, "connect");
    return;
  }

  if (hunt_server(client_p, source_p, ":%s CONNECT %s %s :%s", 3,
                  parc, parv) != HUNTED_ISME)
    return;

  if (*parv[1] == '\0')
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "CONNECT");
    return;
  }

  if ((target_p = find_server(parv[1])))
  {
    sendto_one(source_p,
               ":%s NOTICE %s :Connect: Server %s already exists from %s.",
               me.name, source_p->name, parv[1], target_p->from->name);
    return;
  }

  /*
   * Try to find the name, then host, if both fail notify ops and bail
   */
  if ((conf = find_matching_name_conf(SERVER_TYPE,
                                      parv[1], NULL, NULL, 0)) != NULL)
    aconf = &conf->conf.AccessItem;
  else if ((conf = find_matching_name_conf(SERVER_TYPE,
                                           NULL, NULL, parv[1], 0)) != NULL)
    aconf = &conf->conf.AccessItem;
  
  if (conf == NULL)
  {
    sendto_one(source_p,
               ":%s NOTICE %s :Connect: Host %s not listed in ircd.conf",
               me.name, source_p->name, parv[1]);
    return;
  }

  /*
   * Get port number from user, if given.  If not specified,
   * use the default from configuration structure.
   */
  port = aconf->port;

  if (parc > 2 && !EmptyString(parv[2]))
    port = atoi(parv[2]);

  if (port <= 0 || port > 0xFFFF)
  {
    sendto_one(source_p, ":%s NOTICE %s :Connect: Illegal or missing port number",
               me.name, source_p->name);
    return;
  }

  if (find_servconn_in_progress(conf->name))
  {
    sendto_one(source_p, ":%s NOTICE %s :Connect: a connection to %s "
               "is already in progress.", me.name, source_p->name, conf->name);
    return;
  }

  /*
   * Notify all operators about remote connect requests
   */
  ilog(L_TRACE, "CONNECT From %s : %s %s", 
       source_p->name, parv[1], parv[2] ? parv[2] : "");

  /*
   * At this point we should be calling connect_server with a valid
   * connect{} and a valid port in the connect{}
   */
  if (serv_connect(aconf, source_p, port))
  {
    if (!ConfigServerHide.hide_server_ips && IsAdmin(source_p))
      sendto_one(source_p, ":%s NOTICE %s :*** Connecting to %s[%s].%d",
                 me.name, source_p->name, aconf->host,
                 conf->name, port);
    else
      sendto_one(source_p, ":%s NOTICE %s :*** Connecting to %s.%d",
                 me.name, source_p->name, conf->name, port);
  }
  else
  {
    sendto_one(source_p, ":%s NOTICE %s :*** Couldn't connect to %s.%d",
               me.name, source_p->name, conf->name, port);
  }

  /*
   * Client is either connecting with all the data it needs or has been
   * destroyed
   */
}

/*! \brief CONNECT command handler (called for remote clients only)
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
 *      - parv[1] = servername
 *      - parv[2] = port number
 *      - parv[3] = remote server
 */
static void
ms_connect(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  int port = 0;
  struct ConfItem *conf = NULL;
  struct AccessItem *aconf = NULL;
  struct Client *target_p = NULL;

  if (hunt_server(client_p, source_p, ":%s CONNECT %s %s :%s", 3,
                  parc, parv) != HUNTED_ISME)
    return;

  if (*parv[1] == '\0')
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "CONNECT");
    return;
  }

  if ((target_p = find_server(parv[1])))
  {
    sendto_one(source_p,
               ":%s NOTICE %s :Connect: Server %s already exists from %s.",
               me.name, source_p->name, parv[1], target_p->from->name);
    return;
  }

  /*
   * Try to find the name, then host, if both fail notify ops and bail
   */
  if ((conf = find_matching_name_conf(SERVER_TYPE,
                                      parv[1], NULL, NULL, 0)) != NULL)
    aconf = &conf->conf.AccessItem;
  else if ((conf = find_matching_name_conf(SERVER_TYPE,
                                           NULL, NULL, parv[1], 0)) != NULL)
    aconf = &conf->conf.AccessItem;

  if (aconf == NULL)
  {
    sendto_one(source_p,
               ":%s NOTICE %s :Connect: Host %s not listed in ircd.conf",
               me.name, source_p->name, parv[1]);
    return;
  }

  assert(aconf != NULL);

  /*
   * Get port number from user, if given. If not specified,
   * use the default from configuration structure.
   */
  port = aconf->port;

  if (parc > 2 && !EmptyString(parv[2]))
  {
    port = atoi(parv[2]);

    /* if someone sends port 0, use the config port instead */
    if (port == 0)
      port = aconf->port;
  }

  if (port <= 0 || port > 0xFFFF)
  {
    sendto_one(source_p, ":%s NOTICE %s :Connect: Illegal or missing port number",
               me.name, source_p->name);
    return;
  }

  if (find_servconn_in_progress(conf->name))
  {
    sendto_one(source_p, ":%s NOTICE %s :Connect: a connection to %s "
               "is already in progress.", me.name, source_p->name, conf->name);
    return;
  }

  /*
   * Notify all operators about remote connect requests
   */
  sendto_wallops_flags(UMODE_WALLOP, &me, "Remote CONNECT %s %d from %s",
                       parv[1], port, source_p->name);
  sendto_server(NULL, NULL, NULL, NOCAPS, NOCAPS,
                ":%s WALLOPS :Remote CONNECT %s %d from %s",
                me.name, parv[1], port, source_p->name);

  ilog(L_TRACE, "CONNECT From %s : %s %d", 
       source_p->name, parv[1], port);

  /*
   * At this point we should be calling connect_server with a valid
   * connect{} and a valid port in the connect{}
   */
  if (serv_connect(aconf, source_p, port))
    sendto_one(source_p, ":%s NOTICE %s :*** Connecting to %s.%d",
               me.name, source_p->name, conf->name, port);
  else
    sendto_one(source_p, ":%s NOTICE %s :*** Couldn't connect to %s.%d",
               me.name, source_p->name, conf->name, port);

  /*
   * Client is either connecting with all the data it needs or has been
   * destroyed
   */
}
