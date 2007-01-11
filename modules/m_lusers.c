/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_lusers.c: Sends user statistics.
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
#include "conf/conf.h"
#include "handlers.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "server.h"    /* hunt_server */
#include "user.h"    /* show_lusers */
#include "send.h"
#include "msg.h"
#include "parse.h"

static void m_lusers(struct Client *, struct Client *, int, char *[]);
static void ms_lusers(struct Client *, struct Client *, int, char *[]);

struct Message lusers_msgtab = {
  "LUSERS", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_lusers, ms_lusers, m_ignore, ms_lusers, m_ignore}
};

INIT_MODULE(m_lusers, "$Revision$")
{
  mod_add_cmd(&lusers_msgtab);
}

CLEANUP_MODULE
{
  mod_del_cmd(&lusers_msgtab);
}

/* m_lusers - LUSERS message handler
 * parv[0] = sender
 * parv[1] = ignored, once was host/server mask.
 * parv[2] = server to query
 */
static void
m_lusers(struct Client *client_p, struct Client *source_p,
	 int parc, char *parv[])
{
  static time_t last_used = 0;

  if ((last_used + General.pace_wait_simple) > CurrentTime)
  {
    sendto_one(source_p, form_str(RPL_LOAD2HI), me.name, parv[0]);
    return;
  }

  last_used = CurrentTime;

  if (parc > 2 && !General.disable_remote_commands)
    if (hunt_server(source_p, ":%s LUSERS %s :%s",
                    2, parc, parv) != HUNTED_ISME)
      return;

  show_lusers(source_p);
}

/* ms_lusers - LUSERS message handler for servers and opers
 * parv[0] = sender
 * parv[1] = ignored, once was host/server mask.
 * parv[2] = server to query
 */
static void
ms_lusers(struct Client *client_p, struct Client *source_p,
	  int parc, char *parv[])
{
  if (parc > 2)
    if (hunt_server(source_p, ":%s LUSERS %s :%s",
                    2, parc, parv) != HUNTED_ISME)
        return;

  if (IsClient(source_p))
    show_lusers(source_p);
}
