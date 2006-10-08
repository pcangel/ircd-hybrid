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
#include "numeric.h"
#include "send.h"
#include "server.h"

// TODO: Add callbacks for ?resv.conf support with default handlers

dlink_list nresv_confs = {0};
dlink_list cresv_confs = {0};
struct ResvConf *nresv_hash[RHSIZE] = {0};
struct ResvConf *cresv_hash[RHSIZE] = {0};
int num_hashed_resvs = 0;

static dlink_node *hreset, *hexpire;
static char *tmpreason = NULL;

static void do_report_resv(struct Client *, dlink_list *, struct ResvConf **);

/*
 * free_resvs()
 *
 * Frees a subset of all resvs.
 *
 * inputs:
 *   list      -  &nresv_confs or &cresv_confs
 *   hash      -  &nresv_hash or &cresv_hash, likewise
 *   type      -  "nick" or "channel"
 *   expiring  -  whether we free expired (YES) or all permanent (NO) resvs
 * output: none
 */
static void
free_resvs(dlink_list *list, struct ResvConf **hash, const char *type,
           int expiring)
{
  dlink_node *ptr, *ptr_next;
  struct ResvConf *prev, *resv;
  int i;

  for (i = 0; i < RHSIZE; i++)
    for (prev = NULL, resv = hash[i]; resv != NULL;
         resv = (prev != NULL ? prev->hnext : hash[i]))
      if (expiring ? (resv->expires && resv->expires <= CurrentTime) :
          (resv->expires == 0))
      {
        if (expiring)
          sendto_realops_flags(UMODE_ALL, L_ALL,
            "Temporary %s resv for [%s] expired", type, resv->mask);

        if (prev != NULL)
          prev->hnext = resv->hnext;
        else
          hash[i] = resv->hnext;

        MyFree(resv->mask);
        MyFree(resv->reason);
        MyFree(resv);
      }
      else
        prev = resv;

  DLINK_FOREACH_SAFE(ptr, ptr_next, list->head)
  {
    resv = ptr->data;
    if (expiring ? (resv->expires && resv->expires <= CurrentTime) :
        (resv->expires == 0))
    {
      if (expiring)
        sendto_realops_flags(UMODE_ALL, L_ALL,
          "Temporary %s resv for [%s] expired", type, resv->mask);

      dlinkDelete(&resv->node, list);

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
  free_resvs(&nresv_confs, nresv_hash, "nick", NO);
  free_resvs(&cresv_confs, cresv_hash, "channel", NO);

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
  free_resvs(&nresv_confs, nresv_hash, "nick", YES);
  free_resvs(&cresv_confs, cresv_hash, "channel", YES);

  return pass_callback(hexpire);
}

/*
 * do_find_resv()
 *
 * Traverses a list looking for a matching resv.
 *
 * inputs:
 *   list  -  &nresv_confs or &cresv_confs
 *   hash  -  &nresv_hash or &cresv_hash, likewise
 *   what  -  nick/channel to look for
 *   func  -  compare function
 * output: pointer to matching ResvConf or NULL
 */
struct ResvConf *
do_find_resv(dlink_list *list, struct ResvConf **hash, const char *what,
             int (* func) (const char *, const char *))
{
  dlink_node *ptr;
  struct ResvConf *resv;

  for (resv = hash[hash_text(what, RHSIZE)]; resv; resv = resv->hnext)
    if (!func(resv->mask, what) ^ (func != irccmp))
      return resv;

  DLINK_FOREACH(ptr, list->head)
  {
    resv = ptr->data;
    if (!func(resv->mask, what) ^ (func != irccmp))
      return resv;
  }

  return NULL;
}

struct ResvConf *
find_nick_resv(const char *nick)
{
  return do_find_resv(&nresv_confs, nresv_hash, nick, match);
}

struct ResvConf *
find_channel_resv(const char *chname)
{
  return do_find_resv(&cresv_confs, cresv_hash, chname, match_chan);
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
  if (!IsChanPrefix(((char *) mask)[0]) &&
      !do_find_resv(&nresv_confs, nresv_hash, mask, irccmp))
  {
    struct ResvConf *resv = MyMalloc(sizeof(struct ResvConf));

    DupString(resv->mask, collapse(mask));
    if (tmpreason)
      DupString(resv->reason, tmpreason);

    if (!has_wildcards(mask, NO))
    {
      unsigned int hashv = hash_text(mask, RHSIZE);
      resv->hnext = nresv_hash[hashv];
      nresv_hash[hashv] = resv;
    }
    else
      dlinkAddTail(resv, &resv->node, &nresv_confs);
  }
}

static void
resv_channel(void *mask, void *unused)
{
  if (IsChanPrefix(((char *) mask)[0]) &&
      !do_find_resv(&cresv_confs, cresv_hash, mask, irccmp))
  {
    struct ResvConf *resv = MyMalloc(sizeof(struct ResvConf));

    DupString(resv->mask, collapse_esc(mask));
    if (tmpreason)
      DupString(resv->reason, tmpreason);

    if (!has_wildcards(mask, YES))
    {
      unsigned int hashv = hash_text(mask, RHSIZE);
      resv->hnext = cresv_hash[hashv];
      cresv_hash[hashv] = resv;
    }
    else
      dlinkAddTail(resv, &resv->node, &cresv_confs);
  }
}

/*
 * report_resv()
 *
 * Sends a /stats Q reply to the given client.
 *
 * inputs: client pointer
 * output: none
 */
void
report_resv(struct Client *source_p)
{
  do_report_resv(source_p, &nresv_confs, nresv_hash);
  do_report_resv(source_p, &cresv_confs, cresv_hash);
}

static void
do_report_resv(struct Client *source_p, dlink_list *list,
               struct ResvConf **hash)
{
  dlink_node *ptr;
  struct ResvConf *conf;
  int i;

  for (i = 0; i < RHSIZE; i++)
    for (conf = hash[i]; conf; conf = conf->hnext)
      sendto_one(source_p, form_str(RPL_STATSQLINE),
                 ID_or_name(&me, source_p->from),
                 ID_or_name(source_p, source_p->from), 'Q', conf->mask,
                 conf->reason ? conf->reason : "No reason");

  DLINK_FOREACH(ptr, list->head)
  {
    conf = ptr->data;
    sendto_one(source_p, form_str(RPL_STATSQLINE),
               ID_or_name(&me, source_p->from),
               ID_or_name(source_p, source_p->from), 'Q', conf->mask,
               conf->reason ? conf->reason : "No reason");
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
  int i;
  char *names[2] = {"resv", "quarantine"};

  hreset = install_hook(reset_conf, reset_resv);
  hexpire = install_hook(expire_confs, expire_resv);

  for (i = 0; i < 2; i++)
  {
    struct ConfSection *s = add_conf_section(names[i], 2);

    s->before = s->after = before_resv;

    s->def_field = add_conf_field(s, "reason", CT_STRING, NULL, &tmpreason);
    add_conf_field(s, "nick", CT_STRING, resv_nick, NULL);
    add_conf_field(s, "channel", CT_STRING, resv_channel, NULL);
  }
}
