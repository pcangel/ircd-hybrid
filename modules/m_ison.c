/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_ison.c: Provides a single line answer of whether a user is online.
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
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "conf/modules.h"
#include "string/strbuf.h"

static void do_ison(struct Client *, struct Client *, int, char *[]);
static void m_ison(struct Client *, struct Client *, int, char *[]);

struct Message ison_msgtab = {
  "ISON", 0, 0, 1, 1, MFLG_SLOW, 0,
  { m_unregistered, m_ison, m_ignore, m_ignore, m_ison, m_ignore }
};

INIT_MODULE(m_ison, "$Revision$")
{
  mod_add_cmd(&ison_msgtab);
}

CLEANUP_MODULE
{
  mod_del_cmd(&ison_msgtab);
}

/*
 * m_ison added by Darren Reed 13/8/91 to act as an efficent user indicator
 * with respect to cpu/bandwidth used. Implemented for NOTIFY feature in
 * clients. Designed to reduce number of whois requests. Can process
 * nicknames in batches as long as the maximum buffer length.
 *
 * format:
 * ISON :nicklist
 */
static void
m_ison(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  do_ison(client_p, source_p, parc, parv);
}

static void
do_ison(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  struct Client *target_p = NULL;
  char *nick;
  char *p;
  struct strbuf buf;
  int i;

  buf_init(&buf, buf_cb_sendto_one, source_p);
  buf_add(&buf, form_str(RPL_ISON), me.name, source_p->name);
  buf_mark(&buf);

  /* rfc1459 is ambigious about how to handle ISON
   * this should handle both interpretations.
   */
  for (i = 1; i < parc; i++)
  {
    for (nick = strtoken(&p, parv[i], " "); nick;
         nick = strtoken(&p, NULL,    " "))
    {
      if ((target_p = find_person(client_p, nick)))
	buf_add(&buf, "%s ", target_p->name);
    }
  }

  /*  current_insert_point--;
   *  Do NOT take out the trailing space, it breaks ircII
   *  --Rodder
   */

  buf_flush(&buf);
}
