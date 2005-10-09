/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  restart.c: Functions to allow the ircd to restart.
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
#include "restart.h"
#include "common.h"
#include "ircd.h"
#include "send.h"
#include "client.h" /* for UMODE_ALL */


void
server_die(const char *mesg, int rboot)
{
  char buffer[IRCD_BUFSIZE];
  dlink_node *ptr = NULL;
  struct Client *target_p = NULL;
  static int was_here = 0;

  if (rboot && was_here++)
    abort();

  if (EmptyString(mesg))
    snprintf(buffer, sizeof(buffer), "Server %s",
             rboot ? "Restarting" : "Terminating");
  else
    snprintf(buffer, sizeof(buffer), "Server %s: %s",
             rboot ? "Restarting" : "Terminating", mesg);

  DLINK_FOREACH(ptr, local_client_list.head)
  {
    target_p = ptr->data;

    sendto_one(target_p, ":%s NOTICE %s :%s",
               me.name, target_p->name, buffer);
  }

  DLINK_FOREACH(ptr, serv_list.head)
  {
    target_p = ptr->data;

    sendto_one(target_p, ":%s ERROR :%s", me.name, buffer);
  }

  ilog(L_NOTICE, buffer);

  send_queued_all();
  close_fds(NULL);

  unlink(pidFileName);

  if (rboot)
  {
    execv(SPATH, myargv);
    exit(1);
  }
  else
    exit(0);
}

void
ircd_outofmemory(void)
{
  server_die("Out of memory", 1);
}
