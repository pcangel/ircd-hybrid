/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  oper_override.c: Gives flagged IRC opers channel mode privileges.
 *
 *  Copyright (C) 2006 by the past and present ircd coders, and others.
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
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "ircd.h"
#include "send.h"

static unsigned int flag_override;
static dlink_node *haccess;

static void *
get_channel_access(va_list args)
{
  struct Client *client_p = va_arg(args, struct Client *);
  struct Membership *ms = va_arg(args, struct Membership *);
  int *level = va_arg(args, int *);

  if (MyOper(client_p) && (client_p->localClient->operflags & flag_override))
    *level = CHACCESS_CHANOP;
  else
    pass_callback(haccess, client_p, ms, level);

  return NULL;
}

INIT_MODULE(oper_override, "$Revision$")
{
  flag_override = register_conf_flag(oper_flag_map, 'V', "override");
  haccess = install_hook(channel_access_cb, get_channel_access);
}

CLEANUP_MODULE
{
  dlink_node *ptr;

  DLINK_FOREACH(ptr, oper_list.head)
    ((struct Client *) ptr->data)->localClient->operflags &= ~flag_override;

  DLINK_FOREACH(ptr, oper_confs.head)
    ((struct OperatorConf *) ptr->data)->flags &= ~flag_override;

  uninstall_hook(channel_access_cb, get_channel_access);
  unregister_conf_flag(oper_flag_map, flag_override);

  sendto_realops_flags(UMODE_ALL, L_ALL,
    "Disabled override flag for all oper{} blocks, rehash to re-enable");
}
