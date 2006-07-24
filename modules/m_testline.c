/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_testline.c: Tests a hostmask to see what will happen to it.
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
#include "ircd_defs.h"
#include "ircd.h"
#include "restart.h"
#include "send.h"
#include "msg.h"
#include "numeric.h"
#include "parse.h"
#include "hash.h"

static void mo_testline(struct Client *, struct Client *, int, char *[]);
static void mo_testgecos(struct Client *, struct Client *, int, char *[]);

struct Message testline_msgtab = {
  "TESTLINE", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, m_ignore, mo_testline, m_ignore}
};

struct Message testgecos_msgtab = {
  "TESTGECOS", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, m_ignore, mo_testgecos, m_ignore}
};
 
INIT_MODULE(m_testline, "$Revision$")
{
  mod_add_cmd(&testline_msgtab);
  mod_add_cmd(&testgecos_msgtab);
}

CLEANUP_MODULE
{
  mod_del_cmd(&testgecos_msgtab);
  mod_del_cmd(&testline_msgtab);
}
 
/* mo_testline()
 *
 * inputs       - pointer to physical connection request is coming from
 *              - pointer to source connection request is coming from
 *              - parc arg count
 *              - parv actual arguments   
 *   
 * output       - NONE
 * side effects - command to test I/K lines on server
 *   
 * i.e. /quote testline user@host,ip [password]
 *
 */
static void
mo_testline(struct Client *client_p, struct Client *source_p,
            int parc, char *parv[])
{
  int matches = 0;
  char *orig_parv1 = NULL;
  // IRCD_BUFSIZE to allow things like *u*s*e*r*n*a*m*e* etc.
  char given_name[IRCD_BUFSIZE];
  char given_host[IRCD_BUFSIZE];
  struct split_nuh_item nuh;
  struct ResvConf *resv;
  struct DenyConf *dline;
  struct AccessConf *exempt;
  struct KillConf *kline;
  struct AuthConf *iline;
  struct irc_ssaddr ip;
  char userhost[USERLEN + 1 + HOSTLEN + 1];

  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, ":%s NOTICE %s :usage: user@host|ip [password]",
               me.name, source_p->name);
    return;
  }

  resv = (IsChanPrefix(*parv[1]) ? find_channel_resv : find_nick_resv)(parv[1]);
  if (resv != NULL)
  {
    sendto_one(source_p, form_str(RPL_TESTLINE), me.name,
               source_p->name, resv->expires ? 'q' : 'Q', resv->expires ?
               (resv->expires - CurrentTime) / 60 : 0L, resv->mask,
               resv->reason ? resv->reason : "No reason", "");
    return;
  }

  DupString(orig_parv1, parv[1]);

  nuh.nuhmask  = parv[1];
  nuh.nickptr  = NULL;
  nuh.userptr  = given_name;
  nuh.hostptr  = given_host;

  nuh.nicksize = 0;
  nuh.usersize = sizeof(given_name);
  nuh.hostsize = sizeof(given_host);

  split_nuh(&nuh);

  if (parse_netmask(given_host, &ip, NULL) != HM_HOST)
  {
    if ((dline = find_dline(&ip)))
    {
      sendto_one(source_p, form_str(RPL_TESTLINE), me.name,
                 source_p->name, dline->access.expires ? 'd' : 'D',
                 dline->access.expires ?
                 (dline->access.expires - CurrentTime) / 60 : 0,
                 dline->access.host, dline->reason ? dline->reason :
                 "No reason", dline->oper_reason ? dline->oper_reason : "");
      ++matches;
    }

    if ((exempt = find_exempt(&ip)))
    {
      sendto_one(source_p,
                 ":%s NOTICE %s :Exempt D-line host [%s]",
                 me.name, source_p->name, exempt->host);
      ++matches;
    }
  }

  if ((kline = find_kline(given_name, given_host, NULL, &ip)))
  {
    snprintf(userhost, sizeof(userhost), "%s@%s",
             kline->access.user, kline->access.host);

    sendto_one(source_p, form_str(RPL_TESTLINE), me.name,
               source_p->name, kline->access.expires ? 'k' : 'K',
               kline->access.expires ?
               (kline->access.expires - CurrentTime) / 60 : 0L,
               userhost, kline->reason ? kline->reason : "No reason",
               kline->oper_reason ? kline->oper_reason : "");
    ++matches;
  }

  if ((iline = find_iline(given_name, given_host, &ip, NULL)))
  {
    snprintf(userhost, sizeof(userhost), "%s@%s",
             iline->access.user, iline->access.host);

    sendto_one(source_p, form_str(RPL_TESTLINE), me.name,
               source_p->name, iline->access.expires ? 'i' : 'I',
               iline->access.expires ?
               ((iline->access.expires - CurrentTime) / 60) : 0L,
               userhost, iline->class_ptr->name, "");
    ++matches;
  }

  if (!matches)
    sendto_one(source_p, form_str(RPL_NOTESTLINE),
               me.name, source_p->name, orig_parv1);

  MyFree(orig_parv1);
}

/* mo_testgecos()
 *
 * inputs       - pointer to physical connection request is coming from
 *              - pointer to source connection request is coming from
 *              - parc arg count
 *              - parv actual arguments   
 *   
 * output       - always 0
 * side effects - command to test X lines on server
 *   
 * i.e. /quote testgecos gecos
 *
 */
static void
mo_testgecos(struct Client *client_p, struct Client *source_p,
            int parc, char *parv[])
{
  struct GecosConf *conf;

  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, ":%s NOTICE %s :usage: gecos",
               me.name, source_p->name);
    return;
  }

  if ((conf = find_gecos_ban(parv[1])))
    sendto_one(source_p, form_str(RPL_TESTLINE),
               me.name, source_p->name, conf->expires ? 'x' : 'X',
               conf->expires ? (conf->expires - CurrentTime) / 60 : 0L,
               conf->mask, conf->reason ? conf->reason : "No reason", "");
  else
    sendto_one(source_p, form_str(RPL_NOTESTLINE),
               me.name, source_p->name, parv[1]);
}
