/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_drop.c: Lets a lazylink indicate it no longer knows a channel.
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
#include "channel.h"
#include "client.h"
#include "common.h"
#include "hash.h"
#include "ircd.h"
#include "numeric.h"
#include "s_serv.h"       /* captab */
#include "s_user.h"
#include "send.h"
#include "handlers.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"


static void ms_drop(struct Client *, struct Client *, int, char *[]);

struct Message drop_msgtab = {
  "DROP", 0, 0, 2, 0, MFLG_SLOW | MFLG_UNREG, 0,
  { m_unregistered, m_ignore, ms_drop, m_ignore, m_ignore, m_ignore }
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&drop_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&drop_msgtab);
}

const char *_version = "$Revision$";
#endif


/*! \brief DROP command handler (called for servers only)
 *
 * "drop" a channel from consideration on a lazy link
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
 *      - parv[1] = channel
 *      - parv[2] = channel password (key)
 */
static void
ms_drop(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  struct Channel *chptr = NULL;

  if (EmptyString(parv[1]))
    return;

#ifdef DEBUGLL
  sendto_realops(UMODE_ALL, "DROP called by %s for %s",
                 client_p->name, parv[1]);
#endif
  if ((chptr = hash_find_channel(parv[1])) == NULL)
    return;

  if (client_p->localClient->serverMask) /* JIC */
    chptr->lazyLinkChannelExists &= ~client_p->localClient->serverMask;
}
