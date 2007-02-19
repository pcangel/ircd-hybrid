/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  parse_aline.c: All the functions needed for klining etc.
 *
 *  Copyright (C) 2005 by the past and present ircd coders, and others.
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
#include "server.h"
#include "channel.h"
#include "client.h"
#include "common.h"
#include "hash.h"
#include "ircd.h"
#include "listener.h"
#include "numeric.h"
#include "send.h"
#include "userhost.h"
#include "user.h"

static int find_user_host(struct Client *, char *, char *, char *, unsigned int);

int
valid_wild_card_simple(const char *data)
{
  const unsigned char *p = (const unsigned char *)data;
  int nonwild = 0;

  while (*p != '\0')
  {
    if ((*p == '\\' && *++p) || (*p && !IsMWildChar(*p)))
      if (++nonwild == General.min_nonwildcard_simple)
        return 1;
    if (*p != '\0')
      ++p;
  }

  return 0;
}

/* parse_aline
 *
 * input        - pointer to cmd name being used
 *              - pointer to client using cmd
 *              - parc parameter count
 *              - parv[] list of parameters to parse
 *              - parse_flags bit map of things to test
 *              - pointer to user or string to parse into
 *              - pointer to host or NULL to parse into if non NULL
 *              - pointer to optional tkline time or NULL 
 *              - pointer to target_server to parse into if non NULL
 *              - pointer to reason to parse into
 *
 * output       - 1 if valid, -1 if not valid
 * side effects - A generalised k/d/x etc. line parser,
 *               "ALINE [time] user@host|string [ON] target :reason"
 *                will parse returning a parsed user, host if
 *                h_p pointer is non NULL, string otherwise.
 *                if tkline_time pointer is non NULL a tk line will be set
 *                to non zero if found.
 *                if tkline_time pointer is NULL and tk line is found,
 *                error is reported.
 *                if target_server is NULL and an "ON" is found error
 *                is reported.
 *                if reason pointer is NULL ignore pointer,
 *                this allows usee of parse_a_line in unkline etc.
 *
 * - Dianora
 */
int
parse_aline(const char *cmd, struct Client *source_p,
	    int parc, char **parv,
	    int parse_flags, char **up_p, char **h_p, time_t *tkline_time, 
	    char **target_server, char **reason)
{
  int found_tkline_time = 0;
  static char def_reason[] = "No Reason";
  static char user[USERLEN * 4 + 1];
  static char host[HOSTLEN * 4 + 1];

  ++parv;
  --parc;

  found_tkline_time = valid_tkline(*parv, TK_MINUTES);

  if (found_tkline_time != 0)
  {
    ++parv;
    --parc;

    if (tkline_time != NULL)
      *tkline_time = found_tkline_time;
    else
    {
      sendto_one(source_p, ":%s NOTICE %s :temp_line not supported by %s",
		 me.name, source_p->name, cmd);
      return -1;
    }
  }

  if (parc == 0 || EmptyString(*parv))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, cmd);
    return -1;
  }

  if (h_p == NULL)
    *up_p = *parv;
  else
  {
    if (find_user_host(source_p, *parv, user, host, parse_flags) == 0)
      return -1;

    *up_p = user;
    *h_p = host;
  }
 
  --parc;
  ++parv;

  if (parc != 0)
  {
    if (!irccmp(*parv, "ON"))
    {
      --parc;
      ++parv;

      if (target_server == NULL)
      {
        sendto_one(source_p, ":%s NOTICE %s :ON server not supported by %s",
		   me.name, source_p->name, cmd);
        return -1;
      }

      if (!IsOperRemoteBan(source_p))
      {
        sendto_one(source_p, form_str(ERR_NOPRIVS),
                   me.name, source_p->name, "remoteban");
        return -1;
      }

      if (parc == 0 || EmptyString(*parv))
      {
        sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
          me.name, source_p->name, cmd);
        return -1;
      }

      *target_server = *parv;
      --parc;
      ++parv;
    }
    else
    {
      /* Make sure target_server *is* NULL if no ON server found
       * caller probably NULL'd it first, but no harm to do it again -db
       */
      if (target_server != NULL)
        *target_server = NULL;
    }
  }

  if (h_p != NULL)
  {
    if (strchr(user, '!') != NULL)
    {
      sendto_one(source_p, ":%s NOTICE %s :Invalid character '!' in kline",
                 me.name, source_p->name);
      return -1;
    }

    if ((parse_flags & AWILD) && !valid_wild_card(source_p, YES, 2, *up_p, *h_p))
      return -1;
  }
  else
    if ((parse_flags & AWILD) && !valid_wild_card(source_p, YES, 1, *up_p))
      return -1;

  if (reason != NULL)
  {
    if (parc != 0 && !EmptyString(*parv))
    {
      *reason = *parv;
      if (!valid_comment(source_p, *reason, YES))
        return -1;
    }
    else
      *reason = def_reason;
  }

  return 1;
}

/*
 * cluster_a_line
 *
 * inputs	- client sending the cluster
 *		- command name "KLINE" "XLINE" etc.
 *		- capab -- CAP_KLN etc. from server.h
 *		- cluster type -- CLUSTER_KLINE etc. from s_conf.h
 *		- pattern and args to send along
 * output	- none
 * side effects	- Take source_p send the pattern with args given
 *		  along to all servers that match capab and cluster type
*/
void
cluster_a_line(struct Client *source_p, const char *command,
               int capab, int cluster_type, const char *pattern, ...)
{
  va_list args;
  char buffer[IRCD_BUFSIZE];
  dlink_node *ptr = NULL;

  va_start(args, pattern);
  vsnprintf(buffer, sizeof(buffer), pattern, args);
  va_end(args);

  DLINK_FOREACH(ptr, cluster_confs.head)
  {
    const struct ClusterConf *conf = ptr->data;

    if ((conf->type & cluster_type))
      sendto_match_servs(source_p, conf->server, CAP_CLUSTER|capab,
                         "%s %s %s", command, conf->server, buffer);
  }
}

void
announce_a_line(struct Client *source_p, char *type, int expires,
                char *reason, char *oper_reason, char *pattern, ...)
{
  va_list args;
  char what[IRCD_BUFSIZE], buf[IRCD_BUFSIZE];

  va_start(args, pattern);
  vsnprintf(what, sizeof(what), pattern, args);
  va_end(args);

  if (expires)
  {
    snprintf(buf, sizeof(buf), "temporary %d min. %s", expires/60, type);
    type=buf;

    // Permanent ones have been announced when they were stored
    sendto_one(source_p, ":%s NOTICE %s :Added %s [%s]", type, what);
  }

  sendto_realops_flags(UMODE_ALL, L_ALL, "%s added %s for [%s] [%s%s%s]",
                       get_oper_name(source_p), type, what, reason,
                       oper_reason?"|":"", oper_reason?oper_reason:"");
  ilog(L_TRACE, "%s added %s for [%s] [%s%s%s]",
       get_oper_name(source_p), type, what, reason,
       oper_reason?"|":"", oper_reason?oper_reason:"");

  // TODO: Fix _TYPE here (add a param)
  log_oper_action(LOG_KLINE_TYPE, source_p, "[%s] [%s%s%s]\n", what, reason,
                  oper_reason?"|":"", oper_reason?oper_reason:"");
}

char *
a_line_format_reason(char *reason, char *type, int tkline_time)
{
  char buf[IRCD_BUFSIZE], *result;
  if (tkline_time)
    ircsprintf(buf, "Temporary %s %d min. - %s (%s)",
               type, tkline_time/60, reason, smalldate(CurrentTime));
  else
    ircsprintf(buf, "%s (%s)",
               reason, smalldate(CurrentTime));

  DupString(result, reason);
  return result;
}

/* valid_comment()
 *
 * inputs       - pointer to client
 *              - pointer to comment
 * output       - 0 if no valid comment,
 *              - 1 if valid
 * side effects - truncates reason where necessary
 */
int
valid_comment(struct Client *source_p, char *comment, int warn)
{
  if (strchr(comment, '"'))
  {
    if (warn)
      sendto_one(source_p, ":%s NOTICE %s :Invalid character '\"' in comment",
                 me.name, source_p->name);
    return 0;
  }

  if (strlen(comment) > REASONLEN)
    comment[REASONLEN-1] = '\0';

  return 1;
}

/* find_user_host()
 *
 * inputs	- pointer to client placing kline
 *              - pointer to user_host_or_nick
 *              - pointer to user buffer
 *              - pointer to host buffer
 * output	- 0 if not ok to kline, 1 to kline i.e. if valid user host
 * side effects -
 */
static int
find_user_host(struct Client *source_p, char *user_host_or_nick,
               char *luser, char *lhost, unsigned int flags)
{
  char lnick[NICKLEN];
  struct split_nuh_item nuh;

  if (lhost == NULL)
  {
    strlcpy(luser, user_host_or_nick, USERLEN*4 + 1);
    return 1;
  }

  nuh.nuhmask  = user_host_or_nick;
  nuh.nickptr  = lnick;
  nuh.userptr  = luser;
  nuh.hostptr  = lhost;

  nuh.nicksize = NICKLEN;
  nuh.usersize = USERLEN*4+1;
  nuh.hostsize = HOSTLEN*4+1;

  split_nuh(&nuh);

  if (!(flags & NOUSERLOOKUP) && irccmp(lnick, "*"))
  {
    const struct Client *target_p = NULL;

    // Try to find user@host mask from nick
    if ((target_p = find_chasing(source_p, lnick, NULL)) == NULL)
      return 0;

    if (IsExemptKline(target_p))
    {
      if (!IsServer(source_p))
        sendto_one(source_p, ":%s NOTICE %s :%s is E-lined",
                   me.name, source_p->name, target_p->name);
      return 0;
    }

    /*
     * turn the "user" bit into "*user", blow away '~'
     * if found in original user name (non-idented)
     */
    strlcpy(luser, target_p->username, USERLEN*4 + 1);

    if (target_p->username[0] == '~')
      luser[0] = '*';

    if (target_p->sockhost[0] == '\0' || !irccmp(target_p->sockhost, "0"))
      strlcpy(lhost, target_p->host, HOSTLEN*4 + 1);
    else
      strlcpy(lhost, target_p->sockhost, HOSTLEN*4 + 1);
    return 1;
  }

  return 1;
}

/*
 * valid_tkline()
 * 
 * inputs       - pointer to ascii string to check
 *              - whether the specified time is in seconds or minutes
 * output       - -1 not enough parameters
 *              - 0 if not an integer number, else the number
 * side effects - none
 * Originally written by Dianora (Diane, db@db.net)
 */
time_t
valid_tkline(const char *in, int minutes)
{
  time_t result = 0;
  const unsigned char *p = (const unsigned char *)in;

  for (; *p != '\0'; ++p)
  {
    if (!IsDigit(*p))
      return 0;

    result *= 10;
    result += (*p & 0xF);
  }

  /*
   * In the degenerate case where oper does a /quote kline 0 user@host :reason 
   * i.e. they specifically use 0, I am going to return 1 instead
   * as a return value of non-zero is used to flag it as a temporary kline
   */
  if (result == 0)
    result = 1;

  /* 
   * If the incoming time is in seconds convert it to minutes for the purpose
   * of this calculation
   */
  if (!minutes)
    result = result / (time_t)60; 

  if (result > MAX_TDKLINE_TIME)
    result = MAX_TDKLINE_TIME;

  result = result * (time_t)60;  /* turn it into seconds */

  return result;
}

/* valid_wild_card()
 *
 * input        - pointer to client
 *		- int flag, 0 for no warning oper 1 for warning oper
 *		- count of following varargs to check
 * output       - 0 if not valid, 1 if valid
 * side effects - NOTICE is given to source_p if warn is 1
 */
int
valid_wild_card(struct Client *source_p, int warn, int count, ...)
{
  char *p;
  char tmpch;
  int nonwild = 0;
  int anywild = 0;
  va_list args;

  /*
   * Now we must check the user and host to make sure there
   * are at least NONWILDCHARS non-wildcard characters in
   * them, otherwise assume they are attempting to kline
   * *@* or some variant of that. This code will also catch
   * people attempting to kline *@*.tld, as long as NONWILDCHARS
   * is greater than 3. In that case, there are only 3 non-wild
   * characters (tld), so if NONWILDCHARS is 4, the kline will
   * be disallowed.
   * -wnder
   */
  va_start(args, count);

  while (count--)
  {
    p = va_arg(args, char *);
    if (p == NULL)
      continue;

    while ((tmpch = *p++))
    {
      if (!IsKWildChar(tmpch))
      {
        /*
         * If we find enough non-wild characters, we can
         * break - no point in searching further.
         */
        if (++nonwild >= General.min_nonwildcard)
          return 1;
      }
      else
        anywild = 1;
    }
  }

  /* There are no wild characters in the ban, allow it */
  if(!anywild)
    return 1;

  if (warn)
    sendto_one(source_p, ":%s NOTICE %s :Please include at least %d "
               "non-wildcard characters with the mask",
               me.name, source_p->name, General.min_nonwildcard);
  return 0;
}
