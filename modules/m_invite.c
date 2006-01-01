/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_invite.c: Invites the user to join a channel.
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
#include "common.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "hash.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "s_conf.h"
#include "s_serv.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "packet.h"

static void m_invite(struct Client *, struct Client *, int, char *[]);

struct Message invite_msgtab = {
  "INVITE", 0, 0, 3, 0, MFLG_SLOW, 0,
  { m_unregistered, m_invite, m_invite, m_ignore, m_invite, m_ignore }
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&invite_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&invite_msgtab);
}

const char *_version = "$Revision$";
#endif

/*! \brief INVITE command handler (called for clients only)
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
 *      - parv[1] = user to invite
 *      - parv[2] = channel name
 *      - parv[3] = invite timestamp
 */
static void
m_invite(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  struct Client *target_p = NULL;
  struct Channel *chptr = NULL;
  struct Membership *ms = NULL;

  if (IsServer(source_p))
    return;

  if (*parv[2] == '\0')
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "INVITE");
    return;
  }

  if (MyClient(source_p) && !IsFloodDone(source_p))
    flood_endgrace(source_p);

  if ((target_p = find_person(client_p, parv[1])) == NULL)
  {
    sendto_one(source_p, form_str(ERR_NOSUCHNICK),
               me.name, source_p->name, parv[1]);
    return;
  }

  /*
   * Do not send local channel invites to users if they are not on the
   * same server as the person sending the INVITE message. 
   */
  if ((*parv[2] == '&') && !MyConnect(target_p))
  {
    if (!ConfigServerHide.hide_servers)
      sendto_one(source_p, form_str(ERR_USERNOTONSERV),
                 me.name, source_p->name, target_p->name);
    return;
  }

  if ((chptr = hash_find_channel(parv[2])) == NULL)
  {
    sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
               me.name, source_p->name, parv[2]);
    return;
  }

  if (MyConnect(source_p) && (ms = find_channel_link(source_p, chptr)) == NULL)
  {
    sendto_one(source_p, form_str(ERR_NOTONCHANNEL),
               me.name, source_p->name, chptr->chname);
    return;
  }

  if (chptr->mode.mode & (MODE_INVITEONLY | MODE_PARANOID))
  {
    if (MyConnect(source_p) && !has_member_flags(ms, CHFL_CHANOP|CHFL_HALFOP))
    {
      sendto_one(source_p, form_str(ERR_CHANOPRIVSNEEDED),
                 me.name, source_p->name, chptr->chname);
      return;
    }
  }

  if (IsMember(target_p, chptr))
  {
    sendto_one(source_p, form_str(ERR_USERONCHANNEL),
               me.name, source_p->name, target_p->name, chptr->chname);
    return;
  }

  if (MyConnect(source_p))
  {
    sendto_one(source_p, form_str(RPL_INVITING), me.name,
               source_p->name, target_p->name, chptr->chname);

    if (target_p->away)
      sendto_one(source_p, form_str(RPL_AWAY),
                 me.name, source_p->name, target_p->name,
                 target_p->away);
  }
  else if (parc > 3 && IsDigit(*parv[3]))
    if (atoi(parv[3]) > chptr->channelts)
      return;

  if (!MyConnect(target_p) && ServerInfo.hub &&
      IsCapable(target_p->from, CAP_LL))
  {
    /* target_p is connected to a LL leaf, connected to us */
    if (IsClient(source_p))
      client_burst_if_needed(target_p->from, source_p);

    if ((chptr->lazyLinkChannelExists &
         target_p->from->localClient->serverMask) == 0)
      burst_channel(target_p->from, chptr);
  }

  if (MyConnect(target_p))
  {
    sendto_one(target_p, ":%s!%s@%s INVITE %s :%s",
               source_p->name, source_p->username,
               source_p->host,
               target_p->name, chptr->chname);

    if (chptr->mode.mode & MODE_INVITEONLY)
    {
      if (chptr->mode.mode & MODE_PARANOID)
      {
        /* Only do this if channel is set +i AND +p */
        sendto_channel_local(CHFL_CHANOP|CHFL_HALFOP, NO, chptr,
                             ":%s NOTICE %s :%s is inviting %s to %s.",
                             me.name, chptr->chname, source_p->name,
                             target_p->name, chptr->chname);
        sendto_channel_remote(source_p, client_p, CHFL_CHANOP|CHFL_HALFOP,
                              NOCAPS, NOCAPS, chptr,
                              ":%s NOTICE %s :%s is inviting %s to %s.",
                              source_p->name, chptr->chname, source_p->name,
                              target_p->name, chptr->chname);
      }

      /* Add the invite if channel is +i */
      add_invite(chptr, target_p);
    }
  }
  else if (target_p->from != client_p)
    sendto_one(target_p, ":%s INVITE %s %s %lu",
               ID_or_name(source_p, target_p->from),
               ID_or_name(target_p, target_p->from),
               chptr->chname, (unsigned long)chptr->channelts);
}
