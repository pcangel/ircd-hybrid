/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_conf.c: Configuration file functions.
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
#include "ircd_defs.h"
#include "parse_aline.h"
#include "s_serv.h"
#include "channel.h"
#include "client.h"
#include "common.h"
#include "hash.h"
#include "ircd.h"
#include "listener.h"
#include "numeric.h"
#include "send.h"
#include "userhost.h"
#include "s_user.h"
#include "channel_mode.h"

static int check_class_limits(struct Client *, int, struct ClassItem *);

/* check_class_limits()
 *
 * inputs       - client pointer
 *              - int exempt or not to limits
 *              - class pointer
 * output       - 0 if limits ok, non 0 if limits not ok
 * side effects	- NONE
 */
static int
check_class_limits(struct Client *client_p, int exempt,
                   struct ClassItem *aclass)
{
  struct ip_entry *ip_found;
  int a_limit_reached = 0;
  int local = 0, global = 0, ident = 0;

  ip_found = find_or_add_ip(&client_p->localClient->ip);
  ip_found->count++;
  SetIpHash(client_p);

  count_user_host(client_p->username, client_p->host,
                  &global, &local, &ident);

  /* XXX blah. go down checking the various silly limits
   * setting a_limit_reached if any limit is reached.
   * - Dianora
   */
  if (MaxTotal(aclass) != 0 && CurrUserCount(aclass) >= MaxTotal(aclass))
    a_limit_reached = 1;
  else if (MaxPerIp(aclass) != 0 && ip_found->count > MaxPerIp(aclass))
    a_limit_reached = 1;
  else if (MaxLocal(aclass) != 0 && local >= MaxLocal(aclass))
    a_limit_reached = 1;
  else if (MaxGlobal(aclass) != 0 && global >= MaxGlobal(aclass))
    a_limit_reached = 1;
  else if (MaxIdent(aclass) != 0 && ident >= MaxIdent(aclass) &&
           client_p->username[0] != '~')
    a_limit_reached = 1;

  if (a_limit_reached)
  {
    if (!exempt)
      return 0;  /* Already at maximum allowed */

    sendto_one(client_p,
               ":%s NOTICE %s :*** Your connection class is full, "
               "but you have exceed_limit = yes;", me.name, client_p->name);
  }

  if (cidr_limit_reached(exempt, &client_p->localClient->ip, aclass))
    return 0;  /* Already at maximum allowed */

  return 1;
}
