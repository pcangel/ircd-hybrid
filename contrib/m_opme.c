/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_opme.c: Regains ops on opless channels
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
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "s_serv.h"
#include "send.h"
#include "whowas.h"
#include "hash.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "common.h"

// Change to #define to allow /OPME use on any channel, even if it's not opless
#undef NO_OPLESS_CHECK

static void mo_opme(struct Client *, struct Client *, int, char *[]);

struct Message opme_msgtab = {
  "OPME", 0, 0, 2, 0, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, m_ignore, m_ignore, mo_opme, m_ignore }
};

INIT_MODULE(m_opme, "$Revision$")
{
  mod_add_cmd(&opme_msgtab);
}

CLEANUP_MODULE
{
  mod_del_cmd(&opme_msgtab);
}

static int
chan_is_opless(const struct Channel *const chptr)
{
#ifndef NO_OPLESS_CHECK
  const dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, chptr->members.head)
    if (((struct Membership *)ptr->data)->flags & CHFL_CHANOP)
      return 0;
#endif

  return 1;
}

/*! \brief OPME command handler (called for operators only)
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
 *      - parv[1] = channel name
 */
static void
mo_opme(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  struct Channel *chptr = NULL;
  struct Membership *member = NULL;

  if (!IsAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  if ((chptr = hash_find_channel(parv[1])) == NULL)
  {
    sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL), me.name,
               source_p->name, parv[1]);
    return;
  }

  if ((member = find_channel_link(source_p, chptr)) == NULL)
  {
    sendto_one(source_p, form_str(ERR_NOTONCHANNEL), me.name,
               source_p->name, chptr->chname);
    return;
  }

  if (!chan_is_opless(chptr))
  {
    sendto_one(source_p, ":%s NOTICE %s :%s Channel is not opless",
               me.name, source_p->name, chptr->chname);
    return;
  }

  AddMemberFlag(member, CHFL_CHANOP);

  if (*parv[1] == '&')
    sendto_wallops_flags(UMODE_LOCOPS, &me, "OPME called for [%s] by %s",
                         chptr->chname, get_oper_name(source_p));
  else
  {
    sendto_wallops_flags(UMODE_WALLOP, &me, "OPME called for [%s] by %s",
                         chptr->chname, get_oper_name(source_p));
    sendto_server(NULL, source_p, NULL, NOCAPS, NOCAPS,
                  ":%s WALLOPS :OPME called for [%s] by %s",
                  me.name, chptr->chname, get_oper_name(source_p));
  }

  ilog(L_NOTICE, "OPME called for [%s] by %s",
       chptr->chname, get_oper_name(source_p));

  sendto_server(NULL, source_p, chptr, CAP_TS6, NOCAPS,
                ":%s PART %s", ID(source_p), chptr->chname);
  sendto_server(NULL, source_p, chptr, NOCAPS, CAP_TS6,
                ":%s PART %s", source_p->name, chptr->chname);
  sendto_server(NULL, source_p, chptr, CAP_TS6, NOCAPS,
                ":%s SJOIN %lu %s + :@%s",
                me.id, (unsigned long)chptr->channelts,
                chptr->chname, ID(source_p));
  sendto_server(NULL, source_p, chptr, NOCAPS, CAP_TS6,
                ":%s SJOIN %lu %s + :@%s",
                me.name, (unsigned long)chptr->channelts,
                chptr->chname, source_p->name);

  sendto_channel_local(ALL_MEMBERS, NO, chptr, ":%s MODE %s +o %s",
                       me.name, chptr->chname, source_p->name);
}
