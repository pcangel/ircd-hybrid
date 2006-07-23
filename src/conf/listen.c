/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  listen.c: Defines the listen{} block of ircd.conf.
 *
 *  Copyright (C) 2006 by the Hybrid Development Team.
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
#include "listener.h"
#include "conf/conf.h"

static char *listen_host = NULL;
static int flags = 0;
static dlink_node *hreset;

/*
 * reset_listen()
 *
 * Marks all listeners as closed.
 *
 * inputs: none
 * output: none
 */
static void *
reset_listen(va_list args)
{
  close_listeners();
  return pass_callback(hreset);
}

/*
 * set_listen_flags()
 *
 * Parses a list of listener flags.
 *
 * inputs: pointer to dlink_list of strings
 * output: none
 */
static void
set_listen_flags(void *list, void *unused)
{
  dlink_node *ptr;

  flags = 0;

  DLINK_FOREACH(ptr, ((dlink_list *) list)->head)
  {
    char *fl = (char *) ptr->data;

    if (!irccmp(fl, "hidden"))
      flags |= LISTENER_HIDDEN;
    else if (!irccmp(fl, "ssl"))
      flags |= LISTENER_SSL;
    else
    {
      parse_error("unknown listener parameter");
      break;
    }
  }
}

/*
 * set_listen_port()
 *
 * Parses a list of port numbers and (re)opens a listener.
 *
 * inputs: pointer to dlink_list of integers
 * output: none
 */
static void
set_listen_port(void *list, void *unused)
{
  dlink_node *ptr;

  if ((flags & LISTENER_SSL))
#ifdef HAVE_LIBCRYPTO
    if (!ServerInfo.ctx)
#endif
    {
      parse_error("SSL not available, port closed");
      goto reset_listen;
    }

  DLINK_FOREACH(ptr, ((dlink_list *) list)->head)
  {
    long port = (long) ptr->data;

    if (port < 1 || port > 65535)
    {
      parse_error("%d is not an allowed TCP port number", port);
      break;
    }

    add_listener((int) port, listen_host, flags);
  }

reset_listen:
  MyFree(listen_host);
  listen_host = NULL;
  flags = 0;
}

/*
 * init_listen()
 *
 * Initializes support for listen{} blocks.
 *
 * inputs: none
 * output: none
 */
void
init_listen(void)
{
  struct ConfSection *s = add_conf_section("listen", 2);

  hreset = install_hook(reset_conf, reset_listen);

  add_conf_field(s, "flags", CT_LIST, set_listen_flags, NULL);
  add_conf_field(s, "host", CT_STRING, NULL, &listen_host);
  add_conf_field(s, "ip", CT_STRING, NULL, &listen_host);
  add_conf_field(s, "port", CT_NLIST, set_listen_port, NULL);
}
