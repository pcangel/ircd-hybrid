/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2001-2014 ircd-hybrid development team
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
 */

/*! \file m_map.c
 * \brief Includes required functions for processing the MAP command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "modules.h"
#include "numeric.h"
#include "send.h"
#include "conf.h"
#include "ircd.h"
#include "irc_string.h"
#include "parse.h"
#include "s_user.h"



static void dump_map(struct Client *client,
                     struct Client *server,
                     unsigned int prompt_length)
{
  dlink_node *ptr = NULL;
  struct Client *target_p = NULL;
  static char prompt[64];
  static char buf[IRCD_BUFSIZE];
  char *p = prompt + prompt_length;
  int cnt = 0;
  int bufpos = 0;

  *p = '\0';

  if (prompt_length > 60)
    sendto_one(client, form_str(RPL_MAPMORE), me.name,
               client->name, prompt, server->name);
  else
  {
    int dashes;

    bufpos += snprintf(buf + bufpos, sizeof(buf) - bufpos, "%s", server->name);

    if (HasUMode(client, UMODE_OPER) && server->id[0])
      bufpos += snprintf(buf + bufpos, sizeof(buf) - bufpos, "[%s]", server->id);

    buf[bufpos++] = ' ';
    dashes = 50 - bufpos - prompt_length;
    for (; dashes > 0; --dashes)
      buf[bufpos++] = '-';
    buf[bufpos++] = ' ';
    buf[bufpos++] = '|';

    bufpos += snprintf(buf + bufpos, sizeof(buf) - bufpos, " Users %5d (%1.2f%%)",
                       dlink_list_length(&server->serv->client_list), 100 *
                       (float)dlink_list_length(&server->serv->client_list) /
                       (float)Count.total);
    sendto_one(client, form_str(RPL_MAP), me.name, client->name,
               prompt, buf);
  }

  if (prompt_length > 0)
  {
    *(p - 1) = ' ';

    if (*(p - 2) == '`')
      *(p - 2) = ' ';
  }

  if (prompt_length > 60)
    return;
  strcpy(p, "|-");

  DLINK_FOREACH(ptr, server->serv->server_list.head)
  {
    target_p = ptr->data;

    if (IsHidden(target_p) && !HasUMode(client, UMODE_OPER))
      continue;

    if (HasFlag(target_p, FLAGS_SERVICE) && ConfigServerHide.hide_services)
      if (!HasUMode(client, UMODE_OPER))
        continue;

    ++cnt;
  }

  DLINK_FOREACH(ptr, server->serv->server_list.head)
  {
    target_p = ptr->data;

    if (IsHidden(target_p) && !HasUMode(client, UMODE_OPER))
      continue;

    if (HasFlag(target_p, FLAGS_SERVICE) && ConfigServerHide.hide_services)
      if (!HasUMode(client, UMODE_OPER))
        continue;

    if (--cnt == 0)
      *p = '`';
    dump_map(client, target_p, prompt_length + 2);
  }

  if (prompt_length > 0)
    *(p - 1) = '-';
}

/* m_map()
 *      parv[0] = sender prefix
 */
static int
m_map(struct Client *client_p, struct Client *source_p,
      int parc, char *parv[])
{
  static time_t last_used = 0;

  if (ConfigServerHide.flatten_links)
    return m_not_oper(client_p, source_p, parc, parv);

  if ((last_used + ConfigFileEntry.pace_wait) > CurrentTime)
  {
    /* safe enough to give this on a local connect only */
    sendto_one(source_p, form_str(RPL_LOAD2HI),
               me.name, source_p->name);
    return 0;
  }

  last_used = CurrentTime;

  dump_map(source_p, &me, 0);
  sendto_one(source_p, form_str(RPL_MAPEND), me.name, source_p->name);
  return 0;
}

/* mo_map()
 *      parv[0] = sender prefix
 */
static int
mo_map(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  dump_map(source_p, &me, 0);
  sendto_one(source_p, form_str(RPL_MAPEND), me.name, source_p->name);
  return 0;
}

static struct Message map_msgtab =
{
  "MAP", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_map, m_ignore, m_ignore, mo_map, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&map_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&map_msgtab);
}

struct module module_entry =
{
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
