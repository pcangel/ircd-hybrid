/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_oper.c: Makes a user an IRC Operator.
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
#include "common.h"
#include "ircd.h"
#include "numeric.h"
#include "user.h"
#include "send.h"
#include "msg.h"
#include "motd.h"
#include "parse.h"
#include "packet.h"

static void failed_oper_notice(struct Client *, const char *, const char *);
static void m_oper(struct Client *, struct Client *, int, char *[]);
static void mo_oper(struct Client *, struct Client *, int, char *[]);

struct Message oper_msgtab = {
  "OPER", 0, 0, 3, 0, MFLG_SLOW, 0,
  { m_unregistered, m_oper, m_ignore, m_ignore, mo_oper, m_ignore }
};

INIT_MODULE(m_oper, "$Revision$")
{
  mod_add_cmd(&oper_msgtab);
}

CLEANUP_MODULE
{
  mod_del_cmd(&oper_msgtab);
}

/*
** m_oper
**      parv[0] = sender prefix
**      parv[1] = oper name
**      parv[2] = oper password
*/
static void
m_oper(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  struct OperatorConf *conf = NULL;
  const char *name = parv[1];
  const char *password = parv[2];

  if (EmptyString(password))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
	       me.name, source_p->name, "OPER");
    return;
  }

  /* end the grace period */
  if (!IsFloodDone(source_p))
    flood_endgrace(source_p);

  conf = find_operconf(name, source_p->username, source_p->host,
                       &source_p->localClient->ip);
  if (conf == NULL)
  {
    sendto_one(source_p, form_str(ERR_NOOPERHOST), me.name, source_p->name);
    conf = find_operconf(name, NULL, NULL, NULL);
    failed_oper_notice(source_p, name, (conf != NULL) ?
                       "host mismatch" : "no oper {} block");
    log_oper_action(LOG_FAILED_OPER_TYPE, source_p, "%s\n", name);
    return;
  }

  if (match_password(conf->passwd, password, conf->flags & OPER_FLAG_ENCRYPTED))
  {
    oper_up(source_p, conf);

    ilog(L_TRACE, "OPER %s by %s!%s@%s",
         name, source_p->name, source_p->username, source_p->host);
    log_oper_action(LOG_OPER_TYPE, source_p, "%s\n", name);
  }
  else
  {
    sendto_one(source_p, form_str(ERR_PASSWDMISMATCH), me.name, parv[0]);
    failed_oper_notice(source_p, name, "password mismatch");
    log_oper_action(LOG_FAILED_OPER_TYPE, source_p, "%s\n", name);
  }
}

/*
** mo_oper
**      parv[0] = sender prefix
**      parv[1] = oper name
**      parv[2] = oper password
*/
static void
mo_oper(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  sendto_one(source_p, form_str(RPL_YOUREOPER), me.name, source_p->name);
  send_message_file(source_p, &opermotd);
}

/* failed_oper_notice()
 *
 * inputs       - pointer to client doing /oper ...
 *              - pointer to nick they tried to oper as
 *              - pointer to reason they have failed
 * output       - nothing
 * side effects - notices all opers of the failed oper attempt if enabled
 */
static void
failed_oper_notice(struct Client *source_p, const char *name,
                   const char *reason)
{
  if (General.failed_oper_notice)
    sendto_realops_flags(UMODE_ALL, L_ALL, "Failed OPER attempt as %s "
                         "by %s (%s@%s) - %s", name, source_p->name,
                         source_p->username, source_p->host, reason);
}
