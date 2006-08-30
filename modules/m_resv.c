/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_resv.c: Reserves(jupes) a nickname or channel.
 *
 *  Copyright (C) 2001-2002 Hybrid Development Team
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
#include "channel.h"
#include "ircd.h"
#include "numeric.h"
#include "server.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "parse_aline.h"
#include "hash.h"
#include "user.h"

static void mo_resv(struct Client *, struct Client *, int, char *[]);
static void me_resv(struct Client *, struct Client *, int, char *[]);
static void ms_resv(struct Client *, struct Client *, int, char *[]);
static void mo_unresv(struct Client *, struct Client *, int, char *[]);
static void ms_unresv(struct Client *, struct Client *, int, char *[]);

static void parse_resv(struct Client *, char *, int, char *);
static void remove_resv(struct Client *, const char *);

struct Message resv_msgtab = {
  "RESV", 0, 0, 3, 0, MFLG_SLOW, 0,
  { m_ignore, m_not_oper, ms_resv, me_resv, mo_resv, m_ignore }
};

struct Message unresv_msgtab = {
  "UNRESV", 0, 0, 2, 0, MFLG_SLOW, 0,
  { m_ignore, m_not_oper, ms_unresv, m_ignore, mo_unresv, m_ignore }
};

INIT_MODULE(m_resv, "$Revision$")
{
  mod_add_cmd(&resv_msgtab);
  mod_add_cmd(&unresv_msgtab);
}

CLEANUP_MODULE
{
  mod_del_cmd(&unresv_msgtab);
  mod_del_cmd(&resv_msgtab);
}

/* mo_resv()
 *   parv[0] = sender prefix
 *   parv[1] = channel/nick to forbid
 */
static void
mo_resv(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  char *resv = NULL;
  char *reason = NULL;
  char *target_server = NULL;
  time_t tkline_time = 0;

  /* RESV #channel ON irc.server.com :abuse
   * RESV kiddie ON irc.server.com :abuse
   */
  if (parse_aline("RESV", source_p, parc, parv,
		  AWILD, &resv, NULL, &tkline_time, &target_server, &reason) < 0)
    return;

  if (target_server != NULL)
  {
    // if a given expire time is given, ENCAP it
    if (tkline_time != 0)
      sendto_match_servs(source_p, target_server, CAP_ENCAP,
			 "ENCAP %s RESV %d %s 0 :%s",
			 target_server, (int)tkline_time, resv, reason);
    else
      sendto_match_servs(source_p, target_server, CAP_CLUSTER,
			 "RESV %s %s :%s",
			 target_server, resv, reason);
    // Allow ON to apply local resv as well if it matches
    if (!match(target_server, me.name))
      return;
  }
  else
  {
    /* RESV #channel :abuse
     * RESV kiddie :abuse
     */
    if (tkline_time != 0)
      cluster_a_line(source_p, "ENCAP", CAP_ENCAP, SHARED_RESV,
		     "RESV %d %s 0 : %s", (int)tkline_time, resv, reason);
    else
      cluster_a_line(source_p, "RESV", CAP_KLN, SHARED_RESV,
		     "%s : %s", resv, reason);
  }

  parse_resv(source_p, resv, (int)tkline_time, reason);
}

/* me_resv()
 *
 * inputs	- server
 *		- client (oper)
 *		- parc number of arguments
 *		- parv list of arguments
 * via parv[]
 * parv[0] = client name applying resv
 * parv[1] = tkline_time
 * parv[2] = name
 * parv[3] = 0
 * parv[4] = reason
 * parc should be 5
 *
 * outputs	- NONE
 * side effects -
 */
static void
me_resv(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  if (parc != 5 || !IsClient(source_p))
    return;

  parse_resv(source_p, parv[2], atoi(parv[1]), parv[4]);
}

/* ms_resv()
 *   parv[0] = sender prefix
 *   parv[1] = target server
 *   parv[2] = channel/nick to resv
 *   parv[3] = reason
 */
static void
ms_resv(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  if ((parc != 4) || EmptyString(parv[3]))
    return;

  sendto_match_servs(source_p, parv[1], CAP_CLUSTER,
                     "RESV %s %s :%s",
                     parv[1], parv[2], parv[3]);

  if (!IsClient(source_p) || !match(parv[1], me.name))
    return;

  if (find_shared(source_p->servptr->name, source_p->username, source_p->host,
                  source_p->sockhost, SHARED_RESV))
    parse_resv(source_p, parv[2], 0, parv[3]);
}

/* mo_unresv()
 *   parv[0] = sender prefix
 *   parv[1] = channel/nick to unforbid
 */
static void
mo_unresv(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  char *resv = NULL;
  char *reason = NULL;
  char *target_server = NULL;

  // UNRESV #channel ON irc.server.com
  // UNRESV kiddie ON irc.server.com
  if (parse_aline("UNRESV", source_p, parc, parv,
		  0, &resv, NULL, NULL, &target_server, &reason) < 0)
    return;

  if (target_server != NULL)
  {
    sendto_match_servs(source_p, target_server, CAP_CLUSTER,
                       "UNRESV %s %s",
                       target_server, resv);

    // Allow ON to apply local unresv as well if it matches
    if (!match(target_server, me.name))
      return;
  }
  else 
    cluster_a_line(source_p, "UNRESV", CAP_KLN, SHARED_UNRESV, resv);

  remove_resv(source_p, resv);
}

/* ms_unresv()
 *     parv[0] = sender prefix
 *     parv[1] = target server
 *     parv[2] = resv to remove
 */
static void
ms_unresv(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  if ((parc != 3) || EmptyString(parv[2]))
    return;

  sendto_match_servs(source_p, parv[1], CAP_CLUSTER,
                     "UNRESV %s %s",
                     parv[1], parv[2]);

  if (!IsClient(source_p) || !match(parv[1], me.name))
    return;

  if (find_shared(source_p->servptr->name, source_p->username, source_p->host,
                  source_p->sockhost, SHARED_UNRESV))
    remove_resv(source_p, parv[2]);
}

/* parse_resv()
 *
 * inputs	- source_p, NULL supported
 *		- thing to resv
 *		- time_t if tkline
 *		- reason
 * outputs	- none
 * side effects	- parse resv, create if valid
 */
static void
parse_resv(struct Client *source_p, char *name, int tkline_time, char *reason)
{
  struct ResvConf *conf = NULL;
  FBFILE *out = NULL;

  if (!IsAdmin(source_p) && has_wildcards(name, IsChanPrefix(*name)))
  {
    sendto_one(source_p, ":%s NOTICE %s :You must be an admin to perform a "
               "wildcard RESV", me.name, source_p->name);
    return;
  }

  if (IsChanPrefix(*name))
  {
    if (find_channel_resv(name))
    {
      sendto_one(source_p,
	   ":%s NOTICE %s :A RESV has already been placed on channel: %s",
                   me.name, source_p->name, name);
      return;
    }

    conf = MyMalloc(sizeof(*conf));
    DupString(conf->mask, name);
    DupString(conf->reason, reason);
    if (!has_wildcards(name, YES))
    {
      unsigned int hashv = hash_text(name, RHSIZE);
      conf->hnext = cresv_hash[hashv];
      cresv_hash[hashv] = conf;
      num_hashed_resvs++;
    }
    else
      dlinkAdd(conf, &conf->node, &cresv_confs);

    if (tkline_time != 0)
    {
      sendto_one(source_p,
                 ":%s NOTICE %s :A %d minute %s RESV has been placed on "
                 "channel: %s", me.name, source_p->name, tkline_time/60,
                 (MyClient(source_p) ? "local" : "remote"), name);
      sendto_realops_flags(UMODE_ALL, L_ALL,
                           "%s has placed a %d minute %s RESV on "
                           "channel: %s [%s]", get_oper_name(source_p),
                           tkline_time/60, (MyClient(source_p) ?
                           "local" : "remote"), conf->mask, conf->reason);
      ilog(L_TRACE, "%s added temporary %d min. RESV for [%s] [%s]",
           get_oper_name(source_p), (int)tkline_time/60,
           conf->mask, conf->reason);
      conf->expires = CurrentTime + tkline_time;
    }
    else
    {
      sendto_one(source_p,
                 ":%s NOTICE %s :A %s RESV has been placed on channel %s",
                 me.name, source_p->name,
                 (MyClient(source_p) ? "local" : "remote"), name);
      sendto_realops_flags(UMODE_ALL, L_ALL,
                           "%s has placed a %s RESV on channel %s : [%s]",
                           get_oper_name(source_p), (MyClient(source_p) ?
                           "local" : "remote"), conf->mask, conf->reason);
// TBD - don't keep the *line in memory if we cannot open the conf file
    if ((out = fbopen(ServerState.cresvfile, "a")) == NULL)
      sendto_realops_flags(UMODE_ALL, L_ALL,
                           "*** Problem opening %s", ServerState.cresvfile);
    else
      write_csv_line(out, "%s%s",
                   conf->mask, conf->reason);
    }
  }
  else
  {
    if (!valid_wild_card_simple(name))
    {
      sendto_one(source_p, ":%s NOTICE %s :Please include at least %d non-wildcard characters with the resv",
                 me.name, source_p->name, General.min_nonwildcard_simple);
      return;
    }

    if (find_nick_resv(name))
    {
      sendto_one(source_p,
                 ":%s NOTICE %s :A RESV has already been placed on nick %s",
                 me.name, source_p->name, name);
      return;
    }

    conf = MyMalloc(sizeof(*conf));
    DupString(conf->mask, name);
    DupString(conf->reason, reason);
    if (!has_wildcards(name, NO))
    {
      unsigned int hashv = hash_text(name, RHSIZE);
      conf->hnext = nresv_hash[hashv];
      nresv_hash[hashv] = conf;
      num_hashed_resvs++;
    }
    else
      dlinkAdd(conf, &conf->node, &nresv_confs);

    if (tkline_time != 0)
    {
      sendto_one(source_p,
                 ":%s NOTICE %s :A %d minute %s RESV has been placed on nick "
                 "%s : [%s]", me.name, source_p->name, tkline_time/60,
                 (MyClient(source_p) ? "local" : "remote"),
                 conf->mask, conf->reason);
      sendto_realops_flags(UMODE_ALL, L_ALL,
                           "%s has placed a %d minute %s RESV on nick %s : "
                           "[%s]", get_oper_name(source_p), tkline_time/60,
                           (MyClient(source_p) ? "local" : "remote"),
                           conf->mask, conf->reason);
      ilog(L_TRACE, "%s added temporary %d min. RESV for [%s] [%s]",
           get_oper_name(source_p), (int)tkline_time/60,
           conf->mask, conf->reason);
      conf->expires = CurrentTime + tkline_time;
    }
    else
    {
      sendto_one(source_p,
                 ":%s NOTICE %s :A %s RESV has been placed on nick %s : [%s]",
                 me.name, source_p->name,
                 (MyClient(source_p) ? "local" : "remote"),
                 conf->mask, conf->reason);
      sendto_realops_flags(UMODE_ALL, L_ALL,
                           "%s has placed a %s RESV on nick %s : [%s]",
                           get_oper_name(source_p), (MyClient(source_p) ?
                           "local" : "remote"), conf->mask, conf->reason);
   if ((out = fbopen(ServerState.nresvfile, "a")) == NULL)
      sendto_realops_flags(UMODE_ALL, L_ALL,
                           "*** Problem opening %s", ServerState.nresvfile);
    else
      write_csv_line(out, "%s%s",
                   conf->mask, conf->reason);
    }
  }
}

static void
remove_resv(struct Client *source_p, const char *name)
{
  struct ResvConf *conf, *prev;

  if (IsChanPrefix(*name))
  {
    if (!(conf = do_find_resv(&cresv_confs, cresv_hash, name, irccmp)))
    {
      sendto_one(source_p,
                 ":%s NOTICE %s :A RESV does not exist for channel: %s",
                 me.name, source_p->name, name);
      return;
    }

    if (!has_wildcards(conf->mask, YES))
    {
      unsigned int hashv = hash_text(conf->mask, RHSIZE);
      if (cresv_hash[hashv] == conf)
        cresv_hash[hashv] = conf->hnext;
      else
      {
        // make it core if not found
        for (prev = cresv_hash[hashv]; prev->hnext != conf; prev = prev->hnext)
          ;
        prev->hnext = conf->hnext;
      }
      num_hashed_resvs--;
    }
    else
      dlinkDelete(&conf->node, &cresv_confs);

    if (!conf->expires)
      remove_conf_line(123, source_p, name, NULL);

    MyFree(conf->mask);
    MyFree(conf->reason);
    MyFree(conf);

    sendto_one(source_p,
               ":%s NOTICE %s :The RESV has been removed on channel: %s",
               me.name, source_p->name, name);
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "%s has removed the RESV for channel: %s",
                         get_oper_name(source_p), name);
  }
  else
  {
    if (!(conf = do_find_resv(&nresv_confs, nresv_hash, name, irccmp)))
    {
      sendto_one(source_p, ":%s NOTICE %s :A RESV does not exist for nick: %s",
                 me.name, source_p->name, name);
      return;
    }

    if (!has_wildcards(conf->mask, NO))
    {
      unsigned int hashv = hash_text(conf->mask, RHSIZE);
      if (nresv_hash[hashv] == conf)
        nresv_hash[hashv] = conf->hnext;
      else
      {
        // make it core if not found
        for (prev = nresv_hash[hashv]; prev->hnext != conf; prev = prev->hnext)
          ;
        prev->hnext = conf->hnext;
      }
      num_hashed_resvs--;
    }
    else
      dlinkDelete(&conf->node, &nresv_confs);

    if (!conf->expires)
      remove_conf_line(456, source_p, name, NULL);

    MyFree(conf->mask);
    MyFree(conf->reason);
    MyFree(conf);

    sendto_one(source_p, ":%s NOTICE %s :The RESV has been removed on nick: %s",
               me.name, source_p->name, name);
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "%s has removed the RESV for nick: %s",
                         get_oper_name(source_p), name);
  }
}
