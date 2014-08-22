/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2014 ircd-hybrid development team
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

/*! \file m_away.c
 * \brief Includes required functions for processing the AWAY command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "conf.h"
#include "server.h"
#include "packet.h"
#include "user.h"


/*! \brief AWAY command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = away message
 */
static int
m_away(struct Client *source_p, int parc, char *parv[])
{
  if (!IsFloodDone(source_p))
    flood_endgrace(source_p);

  if (parc < 2 || EmptyString(parv[1]))
  {
    /* Marking as not away */
    if (source_p->away[0])
    {
      source_p->away[0] = '\0';

      /* We now send this only if they were away before --is */
      sendto_server(source_p, NOCAPS, NOCAPS, ":%s AWAY", source_p->id);
      sendto_common_channels_local(source_p, 1, CAP_AWAY_NOTIFY, ":%s!%s@%s AWAY",
                                   source_p->name, source_p->username,
                                   source_p->host);
    }

    sendto_one_numeric(source_p, &me, RPL_UNAWAY);
    return 0;
  }

  if ((source_p->localClient->away.last_attempt + ConfigGeneral.away_time) < CurrentTime)
    source_p->localClient->away.count = 0;

  if (source_p->localClient->away.count > ConfigGeneral.away_count)
  {
    sendto_one_numeric(source_p, &me, ERR_TOOMANYAWAY);
    return 0;
  }

  source_p->localClient->away.last_attempt = CurrentTime;
  source_p->localClient->away.count++;

  strlcpy(source_p->away, parv[1], sizeof(source_p->away));

  sendto_one_numeric(source_p, &me, RPL_NOWAWAY);
  sendto_common_channels_local(source_p, 1, CAP_AWAY_NOTIFY, ":%s!%s@%s AWAY :%s",
                               source_p->name, source_p->username,
                               source_p->host, source_p->away);
  sendto_server(source_p, NOCAPS, NOCAPS, ":%s AWAY :%s",
                source_p->id, source_p->away);
  return 0;
}

/*! \brief AWAY command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = away message
 */
static int
ms_away(struct Client *source_p, int parc, char *parv[])
{
  if (parc < 2 || EmptyString(parv[1]))
  {
    /* Marking as not away */
    if (source_p->away[0])
    {
      source_p->away[0] = '\0';

      /* We now send this only if they were away before --is */
      sendto_server(source_p, NOCAPS, NOCAPS, ":%s AWAY", source_p->id);
      sendto_common_channels_local(source_p, 1, CAP_AWAY_NOTIFY, ":%s!%s@%s AWAY",
                                   source_p->name, source_p->username,
                                   source_p->host);
    }

    return 0;
  }

  strlcpy(source_p->away, parv[1], sizeof(source_p->away));

  sendto_common_channels_local(source_p, 1, CAP_AWAY_NOTIFY, ":%s!%s@%s AWAY :%s",
                               source_p->name, source_p->username,
                               source_p->host, source_p->away);
  sendto_server(source_p, NOCAPS, NOCAPS, ":%s AWAY :%s",
                source_p->id, source_p->away);
  return 0;
}

static struct Message away_msgtab =
{
  "AWAY", NULL, 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_away, ms_away, m_ignore, m_away, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&away_msgtab);
  add_isupport("AWAYLEN", NULL, AWAYLEN);
}

static void
module_exit(void)
{
  mod_del_cmd(&away_msgtab);
  delete_isupport("AWAYLEN");
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
