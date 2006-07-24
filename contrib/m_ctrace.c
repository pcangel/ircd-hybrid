/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_ctrace.c: Traces a given class
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
#include "hash.h"
#include "common.h"
#include "ircd.h"
#include "numeric.h"
#include "s_serv.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "parse_aline.h"

static void *do_ctrace(va_list);
static void mo_ctrace(struct Client *, struct Client *, int, char *[]);
static void report_this_status(struct Client *, struct Client *);

struct Message ctrace_msgtab = {
  "CTRACE", 0, 0, 2, 0, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, m_ignore, m_ignore, mo_ctrace, m_ignore }
};

static struct Callback *ctrace_cb;

INIT_MODULE(m_ctrace, "$Revision$")
{
  ctrace_cb = register_callback("doing_ctrace", do_ctrace);
  mod_add_cmd(&ctrace_msgtab);
}

CLEANUP_MODULE
{
  mod_del_cmd(&ctrace_msgtab);
  uninstall_hook(ctrace_cb, do_ctrace);
}


/*
** mo_ctrace
**      parv[0] = sender prefix
**      parv[1] = classname
*/
static void
mo_ctrace(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "CTRACE");
    return;
  }

  execute_callback(ctrace_cb, source_p, parc, parv);
}

/*
 * do_ctrace
 */
static void *
do_ctrace(va_list args)
{
  struct Client *source_p = va_arg(args, struct Client *);
  char **parv;
  struct Client *target_p;
  char *class_looking_for;
  const char *class_name;
  dlink_node *ptr;

  va_arg(args, int);
  parv = va_arg(args, char **);
  class_looking_for = parv[1];

  /* report all direct connections */
  DLINK_FOREACH(ptr, local_client_list.head)
  {
    target_p = ptr->data;

    class_name = target_p->localClient->class->name;
    if ((class_name != NULL) && match(class_looking_for, class_name))
      report_this_status(source_p, target_p);
  }

  sendto_one(source_p, form_str(RPL_ENDOFTRACE), me.name,
             source_p->name, class_looking_for);
  return NULL;
}

/*
 * report_this_status
 *
 * inputs	- pointer to client to report to
 * 		- pointer to client to report about
 * output	- counter of number of hits
 * side effects - NONE
 */
static void
report_this_status(struct Client *source_p, struct Client *target_p)
{
  const char *name = NULL;
  const char *class_name = NULL;

  name = get_client_name(target_p, HIDE_IP);
  class_name = target_p->localClient->class->name;

  switch (target_p->status)
  {
    case STAT_CLIENT:
      if ((IsOper(source_p) && (MyClient(source_p) || !IsInvisible(target_p)))
          || IsOper(target_p))
      {
        if (IsAdmin(target_p) && !General.hide_spoof_ips)
          sendto_one(source_p, form_str(RPL_TRACEOPERATOR),
                       me.name, source_p->name, class_name, name,
                       IsAdmin(source_p) ? target_p->sockhost : "255.255.255.255",
                       CurrentTime - target_p->lasttime,
                       CurrentTime - target_p->localClient->last);
          else if (IsOper(target_p))
          {
            if (General.hide_spoof_ips)
	      sendto_one(source_p, form_str(RPL_TRACEOPERATOR),
		         me.name, source_p->name, class_name, name, 
		         IsIPSpoof(target_p) ? "255.255.255.255" : target_p->sockhost,
		         CurrentTime - target_p->lasttime,
		         CurrentTime - target_p->localClient->last);
	    else   
              sendto_one(source_p, form_str(RPL_TRACEOPERATOR),
                         me.name, source_p->name, class_name, name,
                         (IsIPSpoof(target_p) ? "255.255.255.255" : target_p->sockhost),
                         CurrentTime - target_p->lasttime,
                         CurrentTime - target_p->localClient->last);
          }
	  else
          {
            if (General.hide_spoof_ips)
	      sendto_one(source_p, form_str(RPL_TRACEUSER),
		         me.name, source_p->name, class_name, name,
                         IsIPSpoof(target_p) ? "255.255.255.255" : target_p->sockhost,
		         CurrentTime - target_p->lasttime,
		         CurrentTime - target_p->localClient->last);
            else
              sendto_one(source_p, form_str(RPL_TRACEUSER),
                         me.name, source_p->name, class_name, name,
                         (IsIPSpoof(target_p) ? "255.255.255.255" : target_p->sockhost),
                         CurrentTime - target_p->lasttime,
                         CurrentTime - target_p->localClient->last);
          }
        }
      break;
    case STAT_SERVER:
      if (!IsAdmin(source_p))
        name = get_client_name(target_p, MASK_IP);

      sendto_one(source_p, form_str(RPL_TRACESERVER),
		 me.name, source_p->name, class_name, 0,
		 0, name, *(target_p->serv->by) ?
		 target_p->serv->by : "*", "*",
		 me.name, CurrentTime - target_p->lasttime);
      break;
      
    default: /* ...we actually shouldn't come here... --msa */
      sendto_one(source_p, form_str(RPL_TRACENEWTYPE), me.name,
                 source_p->name, name);
      break;
  }
}
