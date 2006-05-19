/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_etrace.c: Traces a path to a client/server.
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
#include "hash.h"
#include "common.h"
#include "ircd.h"
#include "numeric.h"
#include "s_serv.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "conf/modules.h"
#include "s_conf.h"

#define FORM_STR_RPL_ETRACE	":%s 709 %s %s %s %s %s %s :%s"

static void *do_etrace(va_list);
static void mo_etrace(struct Client *, struct Client *, int, char *[]);

struct Message etrace_msgtab = {
  "ETRACE", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, m_ignore, mo_etrace, m_ignore}
};

static struct Callback *etrace_cb;

INIT_MODULE(m_etrace, "$Revision$")
{
  etrace_cb = register_callback("doing_etrace", do_etrace);
  mod_add_cmd(&etrace_msgtab);
}

CLEANUP_MODULE
{
  mod_del_cmd(&etrace_msgtab);
  uninstall_hook(etrace_cb, do_etrace);
}

static void report_this_status(struct Client *, struct Client *);

/*
 * do_etrace()
 */
static void *
do_etrace(va_list args)
{
  struct Client *source_p = va_arg(args, struct Client *);
  int parc = va_arg(args, int);
  char **parv = va_arg(args, char **);
  const char *tname = NULL;
  struct Client *target_p = NULL;
  int wilds = 0;
  int do_all = 0;
  dlink_node *ptr;

  if (parc > 0)
  {
    tname = parv[1];
    if (tname != NULL)
      wilds = has_wildcards(tname);
    else
      tname = "*";
  }
  else
  {
    do_all = 1;
    tname = "*";
  }

  if (!wilds && !do_all)
  {
    target_p = find_client(tname);

    if (target_p && MyClient(target_p))
      report_this_status(source_p, target_p);
      
    sendto_one(source_p, form_str(RPL_ENDOFTRACE), me.name, 
	       source_p->name, tname);
    return NULL;
  }

  DLINK_FOREACH(ptr, local_client_list.head)
  {
    target_p = ptr->data;

    if (wilds)
    {
      if (match(tname, target_p->name) || match(target_p->name, tname))
	report_this_status(source_p, target_p);
    }
    else
      report_this_status(source_p, target_p);
  }

  sendto_one(source_p, form_str(RPL_ENDOFTRACE), me.name,
	     source_p->name, tname);
  return NULL;
}

/* mo_etrace()
 *      parv[0] = sender prefix
 *      parv[1] = servername
 */
static void
mo_etrace(struct Client *client_p, struct Client *source_p,
	  int parc, char *parv[])
{
  execute_callback(etrace_cb, source_p, parc, parv);
}

/* report_this_status()
 *
 * inputs	- pointer to client to report to
 * 		- pointer to client to report about
 * output	- NONE
 * side effects - NONE
 */
static void
report_this_status(struct Client *source_p, struct Client *target_p)
{
  const char *name;
  const char *class_name;

  name = get_client_name(target_p, HIDE_IP);
  class_name = get_client_className(target_p);

  set_time();

  if (target_p->status == STAT_CLIENT)
  {
    if (ConfigFileEntry.hide_spoof_ips)
      sendto_one(source_p, FORM_STR_RPL_ETRACE,
		 me.name, source_p->name,
		 IsOper(target_p) ? "Oper" : "User",
		 class_name,
		 target_p->name, target_p->username,
		 IsIPSpoof(target_p) ? "255.255.255.255" : target_p->sockhost,
		 target_p->info);
    else
      sendto_one(source_p, FORM_STR_RPL_ETRACE,
		 me.name, source_p->name, 
		 IsOper(target_p) ? "Oper" : "User", 
		 class_name,
		 target_p->name, target_p->username, target_p->sockhost,
		 target_p->info);
  }
}
