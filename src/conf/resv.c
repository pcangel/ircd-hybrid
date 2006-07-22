/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  resv.c: Defines the resv{} block of ircd.conf.
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
#include "conf/conf.h"
#include "client.h"
#include "send.h"

// TODO: Add callbacks for ?resv.conf support with default handlers

static dlink_node *hreset, *hexpire;
static dlink_list nresv_confs = {0};
static dlink_list cresv_confs = {0};
static char *tmpreason = NULL;

/*
 * free_resvs()
 *
 * Frees a subset of all resvs.
 *
 * inputs:
 *   list      -  &nresv_confs or &cresv_confs
 *   type      -  "nick" or "channel"
 *   expiring  -  whether we free expired (YES) or all permanent (NO) resvs
 * output: none
 */
static void
free_resvs(dlink_list *list, const char *type, int expiring)
{
  dlink_node *ptr, *ptr_next;
  struct ResvConf *resv;

  DLINK_FOREACH_SAFE(ptr, ptr_next, list->head)
  {
    resv = ptr->data;
    if (expiring ? (resv->expires && resv->expires <= CurrentTime) :
        (resv->expires == 0))
    {
      if (expiring)
        sendto_realops_flags(UMODE_ALL, L_ALL,
          "Temporary %s resv for [%s] expired", type, resv->mask);

      dlinkDelete(ptr->data, list);
      MyFree(resv->mask);
      MyFree(resv->reason);
      MyFree(resv);
    }
  }
}

/*
 * reset_resv()
 *
 * Sets up default values before a rehash.
 *
 * inputs: none
 * output: none
 */
static void *
reset_resv(va_list args)
{
  free_resvs(&nresv_confs, "nick", NO);
  free_resvs(&cresv_confs, "channel", NO);

  return pass_callback(hreset);
}

/*
 * expire_resv()
 *
 * Frees expired resvs.
 *
 * inputs: none
 * output: none
 */
static void *
expire_resv(va_list args)
{
  free_resvs(&nresv_confs, "nick", YES);
  free_resvs(&cresv_confs, "channel", YES);

  return pass_callback(hexpire);
}

/*
 * do_find_resv()
 *
 * Traverses a list looking for a matching resv.
 *
 * inputs:
 *   list  -  &nresv_confs or &cresv_confs
 *   what  -  nick/channel to look for
 *   func  -  compare function
 * output: pointer to matching ResvConf or NULL
 */
static struct ResvConf *
do_find_resv(dlink_list *list, const char *what,
             int (* func) (const char *, const char *))
{
  dlink_node *ptr;

  DLINK_FOREACH(ptr, list->head)
  {
    struct ResvConf *resv = ptr->data;
    int matches = !func(resv->mask, what) ^ (func != irccmp);

    if (matches)
      return resv;
  }

  return NULL;
}

struct ResvConf *
find_nick_resv(const char *nick)
{
  return do_find_resv(&nresv_confs, nick, match);
}

struct ResvConf *
find_channel_resv(const char *chname)
{
  return do_find_resv(&cresv_confs, chname, match_chan);
}

/*
 * before_resv()
 *
 * Called before and after parsing a single resv{} block.
 *
 * inputs: none
 * output: none
 */
static void
before_resv(void)
{
  MyFree(tmpreason);
  tmpreason = NULL;
}

/*
 * resv_nick()
 * resv_channel()
 *
 * Parses a "nick=" or "channel=" field.
 *
 * inputs: mask string
 * output: none
 */
static void
resv_nick(void *mask, void *unused)
{
  if (!do_find_resv(&nresv_confs, mask, irccmp))
  {
    struct ResvConf *resv = MyMalloc(sizeof(struct ResvConf));

    DupString(resv->mask, collapse(mask));
    DupString(resv->reason, tmpreason ? tmpreason : "No reason");
    dlinkAddTail(resv, &resv->node, &nresv_confs);
  }
}

static void
resv_channel(void *mask, void *unused)
{
  if (IsChanPrefix(((char *) mask)[0]) &&
      !do_find_resv(&cresv_confs, mask, irccmp))
  {
    struct ResvConf *resv = MyMalloc(sizeof(struct ResvConf));

    DupString(resv->mask, collapse_esc(mask));
    DupString(resv->reason, tmpreason ? tmpreason : "No reason");
    dlinkAddTail(resv, &resv->node, &cresv_confs);
  }
}

/*
 * init_resv()
 *
 * Defines the resv{} conf section.
 *
 * inputs: none
 * output: none
 */
void
init_resv(void)
{
  struct ConfSection *s = add_conf_section("resv", 2);

  hreset = install_hook(reset_conf, reset_resv);
  hexpire = install_hook(cb_expire_confs, expire_resv);

  s->before = s->after = before_resv;

  s->def_field = add_conf_field(s, "reason", CT_STRING, NULL, &tmpreason);
  add_conf_field(s, "nick", CT_STRING, resv_nick, NULL);
  add_conf_field(s, "channel", CT_STRING, resv_channel, NULL);
}
