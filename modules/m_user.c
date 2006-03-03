/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_user.c: Sends username information.
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
#include "s_user.h"
#include "send.h"
#include "s_conf.h"
#include "msg.h"
#include "parse.h"
#include "conf/modules.h"

static void mr_user(struct Client*, struct Client*, int, char *[]);

struct Message user_msgtab = {
  "USER", 0, 0, 5, 0, MFLG_SLOW, 0L,
  { mr_user, m_registered, m_ignore, m_ignore, m_registered, m_ignore }
};

INIT_MODULE(m_user, "$Revision$")
{
  mod_add_cmd(&user_msgtab);
}

CLEANUP_MODULE
{
  mod_del_cmd(&user_msgtab);
}

/*
** mr_user
**      parv[0] = sender prefix
**      parv[1] = username (login name, account)
**      parv[2] = client host name (used only from other servers)
**      parv[3] = server host name (used only from other servers)
**      parv[4] = users real name info
*/
static void
mr_user(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  char *p = NULL;

  assert(source_p == client_p);

  if ((p = strchr(parv[1],'@')) != NULL)
    *p = '\0'; 

  if (*parv[4] == '\0')
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, EmptyString(parv[0]) ? "*" : parv[0], "USER");
    return;
  }

  if (!IsUnknown(source_p))
  {
    sendto_one(source_p, form_str(ERR_ALREADYREGISTRED),
               me.name, parv[0]);
    return;
  }

  source_p->localClient->registration &= ~REG_NEED_USER;

  /*
   * don't take the clients word for it, ever
   */
  source_p->servptr = &me;

  strlcpy(source_p->info, parv[4], sizeof(source_p->info));

  if (!IsGotId(source_p))
  {
    /*
     * save the username in the client
     * If you move this you'll break ping cookies..you've been warned
     */
    strlcpy(source_p->username, parv[1], sizeof(source_p->username));
  }

  if (!source_p->localClient->registration)
    /* NICK already received, now I have USER... */
    register_local_user(source_p, parv[1]);
}
