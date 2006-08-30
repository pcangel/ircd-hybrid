/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_kline.c: Bans a user.
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
#include "client.h"
#include "common.h"
#include "ircd.h"
#include "numeric.h"
#include "parse_aline.h"
#include "send.h"
#include "hash.h"
#include "handlers.h"
#include "server.h"
#include "msg.h"
#include "parse.h"
#include "user.h"

static void me_kline(struct Client *, struct Client *, int, char *[]);
static void mo_kline(struct Client *, struct Client *, int, char *[]);
static void ms_kline(struct Client *, struct Client *, int, char *[]);
static void mo_dline(struct Client *, struct Client *, int, char *[]);
static void me_unkline(struct Client *, struct Client *, int, char *[]);
static void mo_unkline(struct Client *, struct Client *, int, char *[]);
static void ms_unkline(struct Client *, struct Client *, int, char *[]);
static void mo_undline(struct Client *, struct Client *, int, char *[]);

static char buffer[IRCD_BUFSIZE];

static int already_placed_kline(struct Client *, const char *, const char *, int);
static void apply_kline(struct Client *, struct KillConf *, const char *, time_t);
static void apply_tkline(struct Client *, struct KillConf *, int);


struct Message kline_msgtab = {
  "KLINE", 0, 0, 2, 0, MFLG_SLOW, 0,
   { m_unregistered, m_not_oper, ms_kline, me_kline, mo_kline, m_ignore }
};

struct Message dline_msgtab = {
  "DLINE", 0, 0, 2, 0, MFLG_SLOW, 0,
   { m_unregistered, m_not_oper, m_ignore, m_ignore, mo_dline, m_ignore }
};

struct Message unkline_msgtab = {
  "UNKLINE", 0, 0, 2, 0, MFLG_SLOW, 0,
   { m_unregistered, m_not_oper, ms_unkline, me_unkline, mo_unkline, m_ignore }
};

struct Message undline_msgtab = {
  "UNDLINE", 0, 0, 2, 0, MFLG_SLOW, 0,
   { m_unregistered, m_not_oper, m_ignore, m_ignore, mo_undline, m_ignore }
};

INIT_MODULE(m_kline, "$Revision$")
{
  mod_add_cmd(&kline_msgtab);
  mod_add_cmd(&unkline_msgtab);
  mod_add_cmd(&dline_msgtab);
  mod_add_cmd(&undline_msgtab);

  add_capability("KLN", CAP_KLN, 1);
  add_capability("UNKLN", CAP_UNKLN, 1);
}

CLEANUP_MODULE
{
  delete_capability("UNKLN");
  delete_capability("KLN");

  mod_del_cmd(&undline_msgtab);
  mod_del_cmd(&dline_msgtab);
  mod_del_cmd(&unkline_msgtab);
  mod_del_cmd(&kline_msgtab);
}


/*! \brief KLINE command handler (called for operators only)
 *
 * \param client_p Pointer to allocated Client struct with physical connection
 *                 to this server, i.e. with an open socket connected.
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = sender prefix
 *      - parv[1] = time in minutes
 *      - parv[2] = nick or user@host mask
 *      - parv[3] = reason (optional)
 *  or
 *      - parv[0] = sender prefix
 *      - parv[1] = nick or user@host mask
 *      - parv[2] = reason (optional)
 */
static void
mo_kline(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  char *reason = NULL;
  char *oper_reason;
  char *user = NULL;
  char *host = NULL;
  const char *current_date;
  char *target_server = NULL;
  struct KillConf *conf;
  time_t tkline_time = 0;
  time_t cur_time;

  if (!IsOperK(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, source_p->name, "kline");
    return;
  }

  if (parse_aline("KLINE", source_p, parc, parv, AWILD, &user, &host,
                  &tkline_time, &target_server, &reason) < 0)
    return;

  if (target_server != NULL)
  {
    if (HasID(source_p))
    {
      sendto_server(NULL, source_p, NULL, CAP_KLN|CAP_TS6, NOCAPS,
                    ":%s KLINE %s %lu %s %s :%s",
                    source_p->id, target_server, (unsigned long)tkline_time,
                    user, host, reason);
      sendto_server(NULL, source_p, NULL, CAP_KLN, CAP_TS6,
                    ":%s KLINE %s %lu %s %s :%s",
                    source_p->name, target_server, (unsigned long)tkline_time,
                    user, host, reason);
    }
    else
      sendto_server(NULL, source_p, NULL, CAP_KLN, NOCAPS,
                    ":%s KLINE %s %lu %s %s :%s",
                    source_p->name, target_server, (unsigned long)tkline_time,
                    user, host, reason);

    /* Allow ON to apply local kline as well if it matches */
    if (!match(target_server, me.name))
      return;
  }
  else
    cluster_a_line(source_p, "KLINE", CAP_KLN, SHARED_KLINE,
                   "%d %s %s :%s", tkline_time, user, host, reason);

  if (already_placed_kline(source_p, user, host, YES))
    return;

  /* Look for an oper reason */
  if ((oper_reason = strchr(reason, '|')) != NULL)
    *oper_reason++ = '\0';

  cur_time = CurrentTime;
  current_date = smalldate(cur_time);
  conf = MyMalloc(sizeof(struct KillConf));
  DupString(conf->access.user, user);
  DupString(conf->access.host, host);

  if (tkline_time != 0)
  {
    ircsprintf(buffer, "Temporary K-line %d min. - %s (%s)",
               (int)(tkline_time/60), reason, current_date);
    DupString(conf->reason, buffer);

    if (oper_reason != NULL)
      DupString(conf->oper_reason, oper_reason);
    apply_tkline(source_p, conf, tkline_time);
  }
  else
  {
    ircsprintf(buffer, "%s (%s)", reason, current_date);
    DupString(conf->reason, buffer);

    if (oper_reason != NULL)
      DupString(conf->oper_reason, oper_reason);
    apply_kline(source_p, conf, current_date, cur_time);
  }
}

/* me_kline - handle remote kline. no propagation */
static void
me_kline(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  struct KillConf *conf;
  int tkline_time;
  const char* current_date;
  time_t cur_time;
  char *kuser, *khost, *kreason, *oper_reason;

  if (parc != 6 || EmptyString(parv[5]))
    return;

  if (!match(parv[1], me.name))
    return;

  tkline_time = valid_tkline(parv[2], TK_SECONDS);
  kuser = parv[3];
  khost = parv[4];
  kreason = parv[5];

  if ((oper_reason = strchr(kreason, '|')) != NULL)
    *oper_reason++ = '\0';

  cur_time = CurrentTime;
  current_date = smalldate(cur_time);

  if (find_shared(source_p->servptr->name, source_p->username, source_p->host,
                  source_p->sockhost, SHARED_KLINE))
  {
    if (!IsClient(source_p) ||
        already_placed_kline(source_p, kuser, khost, YES))
      return;

    conf = MyMalloc(sizeof(*conf));
    DupString(conf->access.user, kuser);
    DupString(conf->access.host, khost);

    if (tkline_time != 0)
    {
      ircsprintf(buffer, "Temporary K-line %d min. - %s (%s)",
                 (int)(tkline_time/60), kreason, current_date);
      DupString(conf->reason, buffer);

      if (oper_reason != NULL)
        DupString(conf->oper_reason, oper_reason);
      apply_tkline(source_p, conf, tkline_time);
    }
    else
    {
      ircsprintf(buffer, "%s (%s)", kreason, current_date);
      DupString(conf->reason, buffer);

      if (oper_reason != NULL)
        DupString(conf->oper_reason, oper_reason);
      apply_kline(source_p, conf, current_date, cur_time);
    }
  }
}

/*! \brief KLINE command handler (called for remote clients and servers only)
 *
 * Returns various information such as maxmimum entries, slots that
 * are in use and collision count
 *
 * \param client_p Pointer to allocated Client struct with physical connection
 *                 to this server, i.e. with an open socket connected.
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = sender prefix
 *      - parv[1] = target server (string may include wildcards)
 *      - parv[2] = duration in minutes
 *      - parv[3] = username
 *      - parv[4] = hostname
 *      - parv[5] = reason
 */
static void
ms_kline(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  if (parc != 6 || EmptyString(parv[5]))
    return;

  sendto_match_servs(source_p, parv[1], CAP_KLN,
                     "KLINE %s %s %s %s :%s",
                     parv[1], parv[2], parv[3], parv[4], parv[5]);

  me_kline(client_p, source_p, parc, parv);
}

/* apply_kline()
 *
 * inputs	-
 * output	- NONE
 * side effects	- kline as given, is added to the hashtable
 *		  and conf file
 */
static void 
apply_kline(struct Client *source_p, struct KillConf *conf,
            const char *current_date, time_t cur_time)
{
  FBFILE *out = NULL;
  conf->access.type = acb_type_kline;
  add_access_conf(&conf->access);

// TBD - don't keep the *line in memory if we cannot open the conf file
  if ((out = fbopen(ServerState.klinefile, "a")) == NULL)
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "*** Problem opening %s", ServerState.klinefile);
  else
    write_csv_line(out, "%s%s%s%s%s%s%d",
                   conf->access.user, conf->access.host,
                   conf->reason, conf->oper_reason, current_date,
                   get_oper_name(source_p), cur_time);

  sendto_realops_flags(UMODE_ALL, L_ALL,
                       "%s added K-Line for [%s@%s] [%s]",
                       get_oper_name(source_p),
                       conf->access.user, conf->access.host, conf->reason);
  sendto_one(source_p, ":%s NOTICE %s :Added K-Line [%s@%s] to %s",
             MyConnect(source_p) ? me.name : ID_or_name(&me, source_p->from),
             source_p->name, conf->access.user, conf->access.host,
             ServerState.klinefile);
  ilog(L_TRACE, "%s added K-Line for [%s@%s] [%s]",
       get_oper_name(source_p), conf->access.user, conf->access.host,
       conf->reason);
  log_oper_action(LOG_KLINE_TYPE, source_p, "[%s@%s] [%s]\n",
                  conf->access.user, conf->access.host, conf->reason);

  // Now, activate kline against current online clients
  rehashed_klines = 1;
}

/* apply_tkline()
 *
 * inputs	-
 * output	- NONE
 * side effects	- tkline as given is placed
 */
static void
apply_tkline(struct Client *source_p, struct KillConf *conf,
             int tkline_time)
{
  conf->access.type = acb_type_kline;
  conf->access.expires = CurrentTime + tkline_time;
  add_access_conf(&conf->access);

  sendto_realops_flags(UMODE_ALL, L_ALL,
                       "%s added temporary %d min. K-Line for [%s@%s] [%s]",
                       get_oper_name(source_p), tkline_time/60,
                       conf->access.user, conf->access.host, conf->reason);
  sendto_one(source_p, ":%s NOTICE %s :Added temporary %d min. K-Line [%s@%s]",
             MyConnect(source_p) ? me.name : ID_or_name(&me, source_p->from),
             source_p->name, tkline_time/60, conf->access.user,
             conf->access.host);
  ilog(L_TRACE, "%s added temporary %d min. K-Line for [%s@%s] [%s]",
       get_oper_name(source_p), tkline_time/60,
       conf->access.user, conf->access.host, conf->reason);
  log_oper_action(LOG_TEMP_KLINE_TYPE, source_p, "[%s@%s] [%s]\n",
                  conf->access.user, conf->access.host, conf->reason);

  rehashed_klines = 1;
}

/* apply_tdline()
 *
 * inputs	-
 * output	- NONE
 * side effects	- tkline as given is placed
 */
static void
apply_tdline(struct Client *source_p, struct DenyConf *conf,
             const char *current_date, int tkline_time)
{
  conf->access.type = acb_type_deny;
  conf->access.expires = CurrentTime + tkline_time;
  add_access_conf(&conf->access);

  sendto_realops_flags(UMODE_ALL, L_ALL,
                       "%s added temporary %d min. D-Line for [%s] [%s]",
                       get_oper_name(source_p), tkline_time/60,
                       conf->access.host, conf->reason);
  sendto_one(source_p, ":%s NOTICE %s :Added temporary %d min. D-Line [%s]",
             MyConnect(source_p) ? me.name : ID_or_name(&me, source_p->from),
             source_p->name, tkline_time/60, conf->access.host);
  ilog(L_TRACE, "%s added temporary %d min. D-Line for [%s] [%s]",
       get_oper_name(source_p), tkline_time/60, conf->access.host,
       conf->reason);
  log_oper_action(LOG_TEMP_DLINE_TYPE, source_p, "[%s@%s] [%s]\n",
                  conf->access.user, conf->access.host, conf->reason);

  rehashed_klines = 1;
}

/* mo_dline()
 *
 * inputs	- pointer to server
 *		- pointer to client
 *		- parameter count
 *		- parameter list
 * output	-
 * side effects - D line is added
 *
 */
static void
mo_dline(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  char def_reason[] = "No reason";
  char *dlhost, *oper_reason, *reason;
  const struct Client *target_p = NULL;
  struct irc_ssaddr daddr;
  struct DenyConf *conf;
  time_t tkline_time = 0;
  int bits, t;
  const char *current_date = NULL;
  time_t cur_time;
  char hostip[HOSTIPLEN];
  FBFILE *out = NULL;

  if (!IsOperK(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, source_p->name, "kline");
    return;
  }

  if (parse_aline("DLINE", source_p,  parc, parv, AWILD, &dlhost,
                  NULL, &tkline_time, NULL, &reason) < 0)
    return;

  if ((t = parse_netmask(dlhost, NULL, &bits)) == HM_HOST)
  {
    if ((target_p = find_chasing(source_p, dlhost, NULL)) == NULL)
      return;

    assert(IsClient(target_p));

    if (!MyConnect(target_p))
    {
      sendto_one(source_p,
           ":%s NOTICE %s :Can't DLINE nick on another server",
                 me.name, source_p->name);
      return;
    }

    if (IsExemptKline(target_p))
    {
      sendto_one(source_p,
                 ":%s NOTICE %s :%s is E-lined", me.name,
                 source_p->name, target_p->name);
      return;
    }

    strlcpy(hostip, source_p->sockhost, sizeof(hostip));
    t = parse_netmask(hostip, NULL, &bits);
    dlhost = hostip;
    assert(t == HM_IPV4 || t == HM_IPV6);
  }

  if (bits < 8)
  {
    sendto_one(source_p,
      ":%s NOTICE %s :For safety, bitmasks less than 8 require conf access.",
               me.name, source_p->name);
    return;
  }

#ifdef IPV6
  if (t == HM_IPV6)
    t = AF_INET6;
  else
#endif
    t = AF_INET;

  parse_netmask(dlhost, &daddr, NULL);

  if ((conf = (struct DenyConf *) find_exempt(&daddr)) ||
      (conf = find_dline(&daddr)))
  {
    if (conf->access.type == acb_type_exempt)
      sendto_one(source_p,
                 ":%s NOTICE %s :[%s] is (E)d-lined by [%s]",
                 me.name, source_p->name, dlhost, conf->access.host);
    else
      sendto_one(source_p,
                 ":%s NOTICE %s :[%s] already D-lined by [%s] - %s",
                 me.name, source_p->name, dlhost, conf->access.host,
                 conf->reason ? conf->reason : def_reason);
    return;
  }

  cur_time = CurrentTime;
  current_date = smalldate(cur_time);

  // Look for an oper reason
  if ((oper_reason = strchr(reason, '|')) != NULL)
    *oper_reason++ = '\0';

  if (!valid_comment(source_p, reason, YES))
    return;

  conf = MyMalloc(sizeof(*conf));
  DupString(conf->access.host, dlhost);

  if (tkline_time != 0)
  {
    ircsprintf(buffer, "Temporary D-line %d min. - %s (%s)",
               (int)(tkline_time/60), reason, current_date);
    DupString(conf->reason, buffer);

    if (oper_reason != NULL)
      DupString(conf->oper_reason, oper_reason);

    apply_tdline(source_p, conf, current_date, tkline_time);
  }
  else
  {
    ircsprintf(buffer, "%s (%s)", reason, current_date);
    DupString(conf->reason, buffer);

    if (oper_reason != NULL)
      DupString(conf->oper_reason, oper_reason);

    conf->access.type = acb_type_deny;
    add_access_conf(&conf->access);

    if ((out = fbopen(ServerState.dlinefile, "a")) == NULL)
      sendto_realops_flags(UMODE_ALL, L_ALL,
                           "*** Problem opening %s", ServerState.dlinefile);
    else
      write_csv_line(out, "%s%s%s%s%s%d",
                     conf->access.host, conf->reason, conf->oper_reason,
                     current_date, get_oper_name(source_p), cur_time);
// TBD - don't keep the *line in memory if we cannot open the conf file
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "%s added D-Line for [%s] [%s]",
                         get_oper_name(source_p), conf->access.host,
                         conf->reason);
    sendto_one(source_p, ":%s NOTICE %s :Added D-Line [%s] to %s",
               me.name, source_p->name, conf->access.host,
               ServerState.dlinefile);
    ilog(L_TRACE, "%s added D-Line for [%s] [%s]",
         get_oper_name(source_p), conf->access.host, conf->reason);
    log_oper_action(LOG_DLINE_TYPE, source_p, "[%s] [%s]\n",
                    conf->access.host, conf->reason);
  }

  rehashed_klines = 1;
}

/* already_placed_kline()
 * inputs	- user to complain to, username & host to check for
 * outputs	- returns 1 on existing K-line, 0 if doesn't exist
 * side effects	- notifies source_p if the K-line already exists
 */
/*
 * Note: This currently works if the new K-line is a special case of an
 *       existing K-line, but not the other way round. To do that we would
 *       have to walk the hash and check every existing K-line. -A1kmm.
 */
static int
already_placed_kline(struct Client *source_p, const char *luser,
                     const char *lhost, int warn)
{
  const char *reason;
  struct irc_ssaddr iphost, *piphost;
  struct KillConf *conf;
  int t;

  if ((t = parse_netmask(lhost, &iphost, &t)) != HM_HOST)
  {
#ifdef IPV6
    if (t == HM_IPV6)
      t = AF_INET6;
    else
#endif
      t = AF_INET;
    piphost = &iphost;
  }
  else
  {
    t = 0;
    piphost = NULL;
  }

  if ((conf = find_kline(luser, lhost, NULL, piphost)))
  {
    if (warn)
    {
      reason = conf->reason ? conf->reason : "No reason";
      sendto_one(source_p,
                 ":%s NOTICE %s :[%s@%s] already K-Lined by [%s@%s] - %s",
                 me.name, source_p->name, luser, lhost, conf->access.user,
                 conf->access.host, reason);
    }

    return 1;
  }

  return 0;
}

/*
 * mo_unkline
 * Added Aug 31, 1997 
 * common (Keith Fralick) fralick@gate.net
 *
 *      parv[0] = sender
 *      parv[1] = address to remove
 *
 */
static void
mo_unkline(struct Client *client_p,struct Client *source_p,
           int parc, char *parv[])
{
  char *target_server = NULL;
  char *user, *host;
  struct KillConf *conf;
  time_t expires;

  if (!IsOperUnkline(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, source_p->name, "unkline");
    return;
  }

  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "UNKLINE");
    return;
  }

  if (parse_aline("UNKLINE", source_p, parc, parv, 0, &user,
                  &host, NULL, &target_server, NULL) < 0)
    return;

  if (target_server != NULL)
  {
     sendto_match_servs(source_p, target_server, CAP_UNKLN,
                        "UNKLINE %s %s %s",
                        target_server, user, host);

    // Allow ON to apply local unkline as well if it matches
    if (!match(target_server, me.name))
      return;
  }
  else
    cluster_a_line(source_p, "UNKLINE", CAP_UNKLN, SHARED_UNKLINE,
                   "%s %s", user, host);

  conf = (struct KillConf *) find_exact_access_conf(acb_type_kline, user, host);
  if (!conf)
  {
    sendto_one(source_p, ":%s NOTICE %s :No K-Line for [%s@%s] found", 
               me.name, source_p->name, user, host);
    return;
  }

  expires = conf->access.expires;
  destroy_access_conf(&conf->access);

  if (expires)
  {
    sendto_one(source_p,
               ":%s NOTICE %s :Un-klined [%s@%s] from temporary K-Lines",
               me.name, source_p->name, user, host);
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "%s has removed the temporary K-Line for: [%s@%s]",
                         get_oper_name(source_p), user, host);
    ilog(L_NOTICE, "%s removed temporary K-Line for [%s@%s]",
         get_oper_name(source_p), user, host);
  }
  else
  {
    remove_conf_line(123, source_p, user, host);
    sendto_one(source_p, ":%s NOTICE %s :K-Line for [%s@%s] is removed", 
               me.name, source_p->name, user, host);
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "%s has removed the K-Line for: [%s@%s]",
                         get_oper_name(source_p), user, host);
    ilog(L_NOTICE, "%s removed K-Line for [%s@%s]",
         get_oper_name(source_p), user, host);
  }
}

/* me_unkline()
 *
 * inputs	- server
 *		- client
 *		- parc
 *		- parv
 * outputs	- none
 * side effects	- if server is authorized, kline is removed
 *                does not propagate message
 */
static void
me_unkline(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  const char *kuser = NULL, *khost = NULL;
  struct KillConf *conf;
  time_t expires;

  if (parc != 4 || EmptyString(parv[3]))
    return;

  kuser = parv[2];
  khost = parv[3];

  if (!IsClient(source_p) || !match(parv[1], me.name))
    return;

  if (!find_shared(source_p->servptr->name, source_p->username, source_p->host,
                   source_p->sockhost, SHARED_UNKLINE))
    return;

  conf = (struct KillConf *) find_exact_access_conf(acb_type_kline,
    kuser, khost);
  if (!conf)
  {
    sendto_one(source_p, ":%s NOTICE %s :No K-Line for [%s@%s] found",
               me.name, source_p->name, kuser, khost);
    return;
  }

  expires = conf->access.expires;
  destroy_access_conf(&conf->access);

  if (expires)
  {
    sendto_one(source_p,
               ":%s NOTICE %s :Un-klined [%s@%s] from temporary K-Lines",
               me.name, source_p->name, kuser, khost);
    sendto_realops_flags(UMODE_ALL, L_ALL,  
                         "%s has removed the temporary K-Line for: [%s@%s]",
                         get_oper_name(source_p), kuser, khost);
    ilog(L_NOTICE, "%s removed temporary K-Line for [%s@%s]",
         get_oper_name(source_p), kuser, khost);
  }
  else
  {
    remove_conf_line(123, source_p, kuser, khost);
    sendto_one(source_p, ":%s NOTICE %s :K-Line for [%s@%s] is removed",
               me.name, source_p->name, kuser, khost);
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "%s has removed the K-Line for: [%s@%s]",
                         get_oper_name(source_p), kuser, khost);

    ilog(L_NOTICE, "%s removed K-Line for [%s@%s]",
         get_oper_name(source_p), kuser, khost);
  }
}

// ms_unkline - propagates and handles a remote unkline message
static void
ms_unkline(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  if (parc != 4 || EmptyString(parv[3]))
    return;

  sendto_match_servs(source_p, parv[1], CAP_UNKLN,
                     "UNKLINE %s %s %s",
                     parv[1], parv[2], parv[3]);

  me_unkline(client_p, source_p, parc, parv);
}

/*
** m_undline
** added May 28th 2000 by Toby Verrall <toot@melnet.co.uk>
** based totally on m_unkline
** added to hybrid-7 7/11/2000 --is
**
**      parv[0] = sender nick
**      parv[1] = dline to remove
*/
static void
mo_undline(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  struct irc_ssaddr ip;
  struct DenyConf *conf;
  time_t expires;

  if (!IsOperUnkline(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, source_p->name, "unkline");
    return;
  }

  if (parse_netmask(parv[1], &ip, NULL) == HM_HOST ||
      !(conf = find_dline(&ip)))
  {
    sendto_one(source_p, ":%s NOTICE %s :No D-Line for [%s] found",
               me.name, source_p->name, parv[1]);
    return;
  }

  expires = conf->access.expires;
  destroy_access_conf(&conf->access);

  if (expires)
  {
    sendto_one(source_p,
              ":%s NOTICE %s :Un-Dlined [%s] from temporary D-Lines",
              me.name, source_p->name, parv[1]);
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "%s has removed the temporary D-Line for: [%s]",
                         get_oper_name(source_p), parv[1]);
    ilog(L_NOTICE, "%s removed temporary D-Line for [%s]",
         get_oper_name(source_p), parv[1]);
  }
  else
  {
    remove_conf_line(123, source_p, parv[1], NULL);
    sendto_one(source_p, ":%s NOTICE %s :D-Line for [%s] is removed",
               me.name, source_p->name, parv[1]);
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "%s has removed the D-Line for: [%s]",
                         get_oper_name(source_p), parv[1]);
    ilog(L_NOTICE, "%s removed D-Line for [%s]",
         get_oper_name(source_p), parv[1]);
  }
}
