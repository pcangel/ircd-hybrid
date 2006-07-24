/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_info.c: Sends information about the server.
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
#include "m_info.h"
#include "channel.h"
#include "client.h"
#include "common.h"
#include "ircd.h"
#include "numeric.h"
#include "s_serv.h"
#include "s_user.h"
#include "send.h"
#include "handlers.h"
#include "msg.h"
#include "parse.h"

static void send_conf_options(struct Client *);
static void send_birthdate_online_time(struct Client *);
static void *send_info_text(va_list args);

static void m_info(struct Client *, struct Client *, int, char *[]);
static void ms_info(struct Client *, struct Client *, int, char *[]);

struct Message info_msgtab = {
  "INFO", 0, 0, 0, 0, MFLG_SLOW, 0,
  { m_unregistered, m_info, ms_info, m_ignore, ms_info, m_ignore }
};

static struct Callback *info_cb = NULL;

INIT_MODULE(m_info, "$Revision$")
{
  info_cb = register_callback("doing_info", send_info_text);
  mod_add_cmd(&info_msgtab);
}

CLEANUP_MODULE
{
  uninstall_hook(info_cb, send_info_text);
  mod_del_cmd(&info_msgtab);
}

static const char *infotext[] =
{
  "IRC --",
  "Based on the original code written by Jarkko Oikarinen",
  "Copyright 1988, 1989, 1990, 1991 University of Oulu, Computing Center",
  "Copyright (c) 1996-2006 Hybrid Development Team",
  "",
  "This program is free software; you can redistribute it and/or",
  "modify it under the terms of the GNU General Public License as",
  "published by the Free Software Foundation; either version 2, or",
  "(at your option) any later version.",
  "",
  "",
  "The hybrid team is a group of ircd coders who were frustrated",
  "with the instability and all-out dirtiness of the EFnet ircd's",
  "available. hybrid is the name for the collective efforts of a group",
  "of people, all of us.",
  "",
  "Anyone is welcome to contribute to this effort. You are encouraged",
  "to participate in the Hybrid mailing list. To subscribe to the",
  "Hybrid List, use this link:",
  "  https://lists.ircd-hybrid.org/mailman/listinfo/hybrid",
  "",
  "The core team as, of this major release:",
  "",
  "adx, Piotr Nizynski <adx@irc7.pl>",
  "billy-jon, William Bierman III <bill@mu.org>",
  "cryogen, Stuart Walsh <stu@ipng.org.uk>",
  "Dianora, Diane Bruce <db@db.net>",
  "joshk, Joshua Kwan <joshk@triplehelix.org>",
  "knight, Alan LeVee <alan.levee@prometheus-designs.net>",
  "metalrock, Jack Low <jclow@csupomona.edu>",
  "Michael, Michael Wobst <michael.wobst@gmail.com>",
  "Rodder, Jon Lusky <lusky@blown.net>",
  "Wohali, Joan Touzet <joant@ieee.org>",
  "",
  "The following people have contributed blood, sweat, and/or code to",
  "recent releases of Hybrid, in nick alphabetical order:",
  "",
  "A1kmm, Andrew Miller <a1kmm@mware.virtualave.net>",
  "AndroSyn, Aaron Sethman <androsyn@ratbox.org>",
  "bane, Dragan Dosen <bane@idolnet.org>",
  "bysin, Ben Kittridge <bkittridge@cfl.rr.com>",
  "cosine, Patrick Alken <wnder@uwns.underworld.net>",
  "David-T, David Taylor <davidt@yadt.co.uk>",
  "fl, Lee Hardy <lee@leeh.co.uk>",
  "Garion, Joost Vunderink <garion@efnet.nl>",
  "Habeeb, David Supuran <habeeb@cfl.rr.com>",
  "Hwy101, W. Campbell <wcampbel@botbay.net>",
  "jmallett, Juli Mallett <jmallett@FreeBSD.org>",
  "jv, Jakub Vlasek <jv@pilsedu.cz>",
  "k9, Jeremy Chadwick <ircd@jdc.parodius.com>",
  "kire, Erik Small <smalle@hawaii.edu>",
  "kre, Dinko Korunic <kreator@fly.srk.fer.hr>",
  "madmax, Paul Lomax <madmax@efnet.org>",
  "nenolod, William Pitcock <nenolod@nenolod.net>",
  "Riedel, Dennis Vink, <riedel@chaotic.nl>",
  "scuzzy, David Todd <scuzzy@aniverse.net>",
  "spookey, David Colburn <spookey@spookey.org>",
  "TimeMr14C, Yusuf Iskenderoglu <uhc0@stud.uni-karlsruhe.de>",
  "toot, Toby Verrall <to7@antipope.fsnet.co.uk>",
  "vx0, Mark Miller <mark@oc768.net>",
  "wiz, Jason Dambrosio <jason@wiz.cx>",
  "Xride, Søren Straarup <xride@x12.dk>",
  "zb^3, Alfred Perlstein <alfred@freebsd.org>",
  "",
  "Others are welcome. Always. And if we left anyone off the above list,",
  "be sure to let us know that too. Many others have contributed to",
  "previous versions of this ircd and its ancestors, too many to list",
  "here.",
  "",
  "Send bug fixes/complaints/rotten tomatoes to bugs@ircd-hybrid.org.",
  "", NULL
};

/*
 * jdc -- Structure for our configuration value table
 */
struct InfoStruct
{
  const char *name;         /* Displayed variable name           */
  unsigned int output_type; /* See below #defines                */
  void *option;             /* Pointer reference to the value    */
  const char *desc;         /* ASCII description of the variable */
};

/* Types for output_type in InfoStruct */
#define OUTPUT_STRING     0x0001 /* Output option as %s w/ dereference  */
#define OUTPUT_STRING_PTR 0x0002 /* Output option as %s w/out deference */
#define OUTPUT_DECIMAL    0x0004 /* Output option as decimal (%d)       */
#define OUTPUT_BOOLEAN    0x0008 /* Output option as "ON" or "OFF"      */
#define OUTPUT_BOOLEAN_YN 0x0010 /* Output option as "YES" or "NO"      */
#define OUTPUT_BOOLEAN2   0x0020 /* Output option as "YES/NO/MASKED"    */

static const struct InfoStruct info_table[] =
{
  /* --[  START OF TABLE  ]-------------------------------------------- */
  {
    "network_name",
    OUTPUT_STRING,
    &ServerInfo.network_name,
    "Network name"
  },
  {
    "network_desc",
    OUTPUT_STRING,
    &ServerInfo.network_desc,
    "Network description"
  },
  {
    "hub",
    OUTPUT_BOOLEAN_YN,
    &ServerInfo.hub,
    "Server is a hub"
  },
  {
    "use_logging",
    OUTPUT_BOOLEAN_YN,
    &Logging.use_logging,
    "Enable logging"
  },
  {
    "fuserlog",
    OUTPUT_STRING_PTR,
    &Logging.userlog,
    "User log file"
  },
  {
    "foperlog",
    OUTPUT_STRING_PTR,
    &Logging.operlog,
    "Operator log file"
  },
  {
    "fkilllog",
    OUTPUT_STRING_PTR,
    &Logging.killlog,
    "Kill log file"
  },
  {
    "fklinelog",
    OUTPUT_STRING_PTR,
    &Logging.klinelog,
    "K-Line log file"
  },
  {
    "fglinelog",
    OUTPUT_STRING_PTR,
    &Logging.glinelog,
    "G-Line log file"
  },
  {
    "restrict_channels",
    OUTPUT_BOOLEAN_YN,
    &Channel.restrict_channels,
    "Only reserved channels are allowed"
  },
  {
    "disable_local_channels",
    OUTPUT_BOOLEAN_YN,
    &Channel.disable_local_channels,
    "Prevent users from joining &channels"
  },
 {
    "use_invex",
    OUTPUT_BOOLEAN_YN,
    &Channel.use_invex,
    "Enable chanmode +I (invite exceptions)"
  },
  {
    "use_except",
    OUTPUT_BOOLEAN_YN,
    &Channel.use_except,
    "Enable chanmode +e (ban exceptions)"
  },
  {
    "use_knock",
    OUTPUT_BOOLEAN_YN,
    &Channel.use_knock,
    "Enable /KNOCK"
  },
  {
    "knock_delay",
    OUTPUT_DECIMAL,
    &Channel.knock_delay,
    "Delay between a users KNOCK attempts"
  },
  {
    "knock_delay_channel",
    OUTPUT_DECIMAL,
    &Channel.knock_delay_channel,
    "Delay between KNOCK attempts to a channel"
  },
  {
    "max_chans_per_user",
    OUTPUT_DECIMAL,
    &Channel.max_chans_per_user,
    "Maximum number of channels a user can join"
  },
  {
    "quiet_on_ban",
    OUTPUT_BOOLEAN_YN,
    &Channel.quiet_on_ban,
    "Banned users may not send text to a channel"
  },
  {
    "max_bans",
    OUTPUT_DECIMAL,
    &Channel.max_bans,
    "Total +b/e/I modes allowed in a channel"
  },
  {
    "default_split_user_count",
    OUTPUT_DECIMAL,
    &Channel.default_split_user_count,
    "Startup value of SPLITUSERS"
  },
  {
    "default_split_server_count",
    OUTPUT_DECIMAL,
    &Channel.default_split_server_count,
    "Startup value of SPLITNUM"
  },
  {
    "no_create_on_split",
    OUTPUT_BOOLEAN_YN,
    &Channel.no_create_on_split,
    "Disallow creation of channels when split"
  },
  {
    "no_join_on_split",
    OUTPUT_BOOLEAN_YN,
    &Channel.no_join_on_split,
    "Disallow joining channels when split"
  },
  {
    "burst_topicwho",
    OUTPUT_BOOLEAN_YN,
    &Channel.burst_topicwho,
    "Enable sending of who set topic on topicburst"
  },
  {
    "flatten_links",
    OUTPUT_BOOLEAN_YN,
    &ServerHide.flatten_links,
    "Flatten /links list"
  },
  {
    "links_delay",
    OUTPUT_DECIMAL,
    &ServerHide.links_delay,
    "Links rehash delay"
  },
  {
    "hidden",
    OUTPUT_BOOLEAN_YN,
    &ServerHide.hidden,
    "Hide this server from a flattened /links on remote servers"
  },
  {
    "disable_hidden",
    OUTPUT_BOOLEAN_YN,
    &ServerHide.disable_hidden,
    "Prevent servers from hiding themselves from a flattened /links"
  },
  {
    "hide_servers",
    OUTPUT_BOOLEAN_YN,
    &ServerHide.hide_servers,
    "Hide servernames from users"
  },
  {
    "hidden_name",
    OUTPUT_STRING,
    &ServerHide.hidden_name,
    "Server name users see if hide_servers = yes"
  },
  {
    "hide_server_ips",
    OUTPUT_BOOLEAN_YN,
    &ServerHide.hide_server_ips,
    "Prevent people from seeing server IPs"
  },
  {
    "gline_min_cidr",
    OUTPUT_DECIMAL,
    &General.gline_min_cidr,
    "Minimum required length of a CIDR bitmask for IPv4 G-Lines"
  },
  {
    "gline_min_cidr6",
    OUTPUT_DECIMAL,
    &General.gline_min_cidr6,
    "Minimum required length of a CIDR bitmask for IPv6 G-Lines"
  },
  {
    "invisible_on_connect",
    OUTPUT_BOOLEAN_YN,
    &General.invisible_on_connect,
    "Automatically set mode +i on connecting users"
  },
  {
    "burst_away",
    OUTPUT_BOOLEAN_YN,
    &General.burst_away,
    "Send /away string that users have set on the server burst"
  },
  {
    "use_whois_actually",
    OUTPUT_BOOLEAN_YN,
    &General.use_whois_actually,
    "Show IP address on /WHOIS when possible"
  },
  {
    "kill_chase_time_limit",
    OUTPUT_DECIMAL,
    &General.kill_chase_time_limit,
    "Nick Change Tracker for KILL"
  },
  {
    "hide_spoof_ips",
    OUTPUT_BOOLEAN_YN,
    &General.hide_spoof_ips,
    "Hide spoofed IP's"
  },
  {
    "ignore_bogus_ts",
    OUTPUT_BOOLEAN_YN,
    &General.ignore_bogus_ts,
    "Ignore bogus timestamps from other servers"
  },
  {
    "disable_auth",
    OUTPUT_BOOLEAN_YN,
    &General.disable_auth,
    "Completely disable ident lookups"
  },
  {
    "disable_remote_commands",
    OUTPUT_BOOLEAN_YN,
    &General.disable_remote_commands,
    "Prevent users issuing commands on remote servers"
  },
  {
    "tkline_expire_notices",
    OUTPUT_BOOLEAN_YN,
    &General.tkline_expire_notices,
    "Show temporary kline/xline expire notices"
  },
  {
    "default_floodcount",
    OUTPUT_DECIMAL,
    &General.default_floodcount,
    "Startup value of FLOODCOUNT"
  },
  {
    "failed_oper_notice",
    OUTPUT_BOOLEAN,
    &General.failed_oper_notice,
    "Inform opers if someone /oper's with the wrong password"
  },
  {
    "dots_in_ident",
    OUTPUT_DECIMAL,
    &General.dots_in_ident,
    "Number of permissable dots in an ident"
  },
  {
    "dot_in_ip6_addr",
    OUTPUT_BOOLEAN,
    &General.dot_in_ip6_addr,
    "Suffix a . to ip6 addresses (for linked servers still running hybrid-6)"
  },
  {
    "min_nonwildcard",
    OUTPUT_DECIMAL,
    &General.min_nonwildcard,
    "Minimum non-wildcard chars in K/G lines"
  },
  {
    "min_nonwildcard_simple",
    OUTPUT_DECIMAL,
    &General.min_nonwildcard_simple,
    "Minimum non-wildcards in gecos bans"
  },
  {
    "max_accept",
    OUTPUT_DECIMAL,
    &General.max_accept,
    "Maximum nicknames on accept list"
  },
  {
    "anti_nick_flood",
    OUTPUT_BOOLEAN,
    &General.anti_nick_flood,
    "NICK flood protection"
  },
  {
    "max_nick_time",
    OUTPUT_DECIMAL,
    &General.max_nick_time,
    "NICK flood protection time interval"
  },
  {
    "max_nick_changes",
    OUTPUT_DECIMAL,
    &General.max_nick_changes,
    "NICK change threshhold setting"
  },
  {
    "anti_spam_exit_message_time",
    OUTPUT_DECIMAL,
    &General.anti_spam_exit_message_time,
    "Duration a client must be connected for to have an exit message"
  },
  {
    "ts_warn_delta",
    OUTPUT_DECIMAL,
    &General.ts_warn_delta,
    "Maximum permitted TS delta before displaying a warning"
  },
  {
    "ts_max_delta",
    OUTPUT_DECIMAL,
    &General.ts_max_delta,
    "Maximum permitted TS delta from another server"
  },
  {
    "kline_with_reason",
    OUTPUT_BOOLEAN_YN,
    &General.kline_with_reason,
    "Display K-line reason to client on disconnect"
  },
  {
    "kline_reason",
    OUTPUT_STRING,
    &General.kline_reason,
    "Reason given to K-lined clients on sign off"
  },
  {
    "warn_no_nline",
    OUTPUT_BOOLEAN,
    &General.warn_no_nline,
    "Display warning if connecting server lacks N-line"
  },
  {
    "stats_o_oper_only",
    OUTPUT_BOOLEAN_YN,
    &General.stats_o_oper_only,
    "STATS O output is only shown to operators"
  },
  {
    "stats_P_oper_only",
    OUTPUT_BOOLEAN_YN,
    &General.stats_P_oper_only,
    "STATS P is only shown to operators"
  },
  {
    "stats_i_oper_only",
    OUTPUT_BOOLEAN2,
    &General.stats_i_oper_only,
    "STATS I output is only shown to operators"
  },
  {
    "stats_k_oper_only",
    OUTPUT_BOOLEAN2,
    &General.stats_k_oper_only,
    "STATS K output is only shown to operators"
  },
  {
    "caller_id_wait",
    OUTPUT_DECIMAL,
    &General.caller_id_wait,
    "Minimum delay between notifying UMODE +g users of messages"
  },
  {
    "opers_bypass_callerid",
    OUTPUT_BOOLEAN_YN,
    &General.opers_bypass_callerid,
    "Allows IRC operators to message users who are +g (callerid)"
  },
  {
    "pace_wait_simple",
    OUTPUT_DECIMAL,
    &General.pace_wait_simple,
    "Minimum delay between less intensive commands"
  },
  {
    "pace_wait",
    OUTPUT_DECIMAL,
    &General.pace_wait,
    "Minimum delay between uses of certain commands"
  },
  {
    "short_motd",
    OUTPUT_BOOLEAN_YN,
    &General.short_motd,
    "Do not show MOTD; only tell clients they should read it"
  },
  {
    "ping_cookie",
    OUTPUT_BOOLEAN,
    &General.ping_cookie,
    "Require ping cookies to connect"
  },
  {
    "no_oper_flood",
    OUTPUT_BOOLEAN,
    &General.no_oper_flood,
    "Reduce flood control for operators"
  },
  {
    "true_no_oper_flood",
    OUTPUT_BOOLEAN,
    &General.true_no_oper_flood,
    "Completely disable flood control for operators"
  },
  {
    "oper_pass_resv",
    OUTPUT_BOOLEAN_YN,
    &General.oper_pass_resv,
    "Opers can over-ride RESVs"
  },
  {
    "idletime",
    OUTPUT_DECIMAL,
    &General.idletime,
    "Number of seconds before a client is considered idle"
  },
  {
    "max_targets",
    OUTPUT_DECIMAL,
    &General.max_targets,
    "The maximum number of PRIVMSG/NOTICE targets"
  },
  {
    "client_flood",
    OUTPUT_DECIMAL,
    &General.client_flood,
    "Maximum amount of data in a client's queue before they are disconnected"
  },
  {
    "throttle_time",
    OUTPUT_DECIMAL,
    &General.throttle_time,
    "Minimum time between client reconnects"
  },
  {
    "enable_glines",
    OUTPUT_BOOLEAN,
    &enable_glines,
    "G-line (network-wide K-line) support"
  },
  {
    "gline_duration",
    OUTPUT_DECIMAL,
    &gline_duration,
    "Expiry time for G-lines"
  },
  /* --[  END OF TABLE  ]---------------------------------------------- */
  {
    NULL,
    0,
    NULL,
    0
  }
};

/*! \brief INFO command handler (called for local clients only)
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
 *      - parv[1] = name of target (optional; string can be a nick or server
 *                  and can also include wildcards)
 */
static void
m_info(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  static time_t last_used = 0;

  if ((last_used + General.pace_wait) > CurrentTime)
  {
    /* safe enough to give this on a local connect only */
    sendto_one(source_p, form_str(RPL_LOAD2HI),
               me.name, source_p->name);
    return;
  }

  last_used = CurrentTime;

  if (!General.disable_remote_commands)
    if (hunt_server(source_p, ":%s INFO :%s",
                    1, parc, parv) != HUNTED_ISME)
      return;

  execute_callback(info_cb, source_p, parc, parv);
}

/*! \brief INFO command handler (called for remote clients and operators)
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
 *      - parv[1] = name of target (optional; string can be a nick or server
 *                  and can also include wildcards)
 */
static void
ms_info(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  if (hunt_server(source_p, ":%s INFO :%s",
                  1, parc, parv) != HUNTED_ISME)
    return;

  execute_callback(info_cb, source_p, parc, parv);
}

/* send_info_text()
 *
 * inputs	- client pointer to send info text to
 * output	- NONE
 * side effects	- info text is sent to client
 */
static void *
send_info_text(va_list args)
{
  struct Client *source_p = va_arg(args, struct Client *);
  const char **text = infotext;
  char *source, *target;
  
  if (!MyClient(source_p) && IsCapable(source_p->from, CAP_TS6) &&
      HasID(source_p))
    source = me.id, target = source_p->id;
  else
    source = me.name, target = source_p->name;

  while (*text)
  {
    const char *line = *text++;

    if (*line == '\0')
      line = " ";

    sendto_one(source_p, form_str(RPL_INFO),
               source, target, line);
  }

  if (IsOper(source_p))
    send_conf_options(source_p);

  send_birthdate_online_time(source_p);

  sendto_one(source_p, form_str(RPL_ENDOFINFO),
             me.name, source_p->name);
  return NULL;
}

/* send_birthdate_online_time()
 *
 * inputs	- client pointer to send to
 * output	- NONE
 * side effects	- birthdate and online time are sent
 */
static void
send_birthdate_online_time(struct Client *source_p)
{
  if (!MyClient(source_p) && IsCapable(source_p->from, CAP_TS6) && HasID(source_p))
  {
    sendto_one(source_p, ":%s %d %s :On-line since %s",
               me.id, RPL_INFO, source_p->id,
               myctime(me.firsttime));
  }
  else
  {
    sendto_one(source_p, ":%s %d %s :On-line since %s",
               me.name, RPL_INFO, source_p->name,
               myctime(me.firsttime));
  }
}

/* send_conf_options()
 *
 * inputs	- client pointer to send to
 * output	- NONE
 * side effects	- send config options to client
 */
static void
send_conf_options(struct Client *source_p)
{
  Info *infoptr;
  const char *from, *to;
  const struct InfoStruct *iptr = NULL;

  /* Now send them a list of all our configuration options
   * (mostly from defaults.h and setup.h)
   */
  if (!MyClient(source_p) && IsCapable(source_p->from, CAP_TS6) && HasID(source_p))
  {
    from = me.id;
    to = source_p->id;
  }
  else
  {
    from = me.name;
    to = source_p->name;
  }

  for (infoptr = MyInformation; infoptr->name; infoptr++)
  {
    if (infoptr->intvalue)
    {
      sendto_one(source_p, ":%s %d %s :%-30s %-5d [%-30s]",
                 from, RPL_INFO, to, infoptr->name,
                 infoptr->intvalue, infoptr->desc);
    }
    else
    {
      sendto_one(source_p, ":%s %d %s :%-30s %-5s [%-30s]",
                 from, RPL_INFO, to, infoptr->name,
                 infoptr->strvalue, infoptr->desc);
    }
  }

  /*
   * Parse the info_table[] and do the magic.
   */
  for (iptr = info_table; iptr->name; ++iptr)
  {
    switch (iptr->output_type)
    {
      /* For "char *" references */
      case OUTPUT_STRING:
      {
        const char *option = *((char **)iptr->option);

        sendto_one(source_p, ":%s %d %s :%-30s %-5s [%-30s]",
                   from, RPL_INFO, to,
                   iptr->name, option ? option : "NONE",
                   iptr->desc ? iptr->desc : "<none>");
        break;
      }

      /* For "char foo[]" references */
      case OUTPUT_STRING_PTR:
      {
        const char *option = iptr->option;

        sendto_one(source_p, ":%s %d %s :%-30s %-5s [%-30s]",
                   from, RPL_INFO, to,
                   iptr->name, option ? option : "NONE",
                   iptr->desc ? iptr->desc : "<none>");
        break;
      }

      /* Output info_table[i].option as a decimal value. */
      case OUTPUT_DECIMAL:
      {
        const int option = *((int *)iptr->option);

        sendto_one(source_p, ":%s %d %s :%-30s %-5d [%-30s]",
                   from, RPL_INFO, to, iptr->name,
                   option, iptr->desc ? iptr->desc : "<none>");
        break;
      }

      /* Output info_table[i].option as "ON" or "OFF" */
      case OUTPUT_BOOLEAN:
      {
        const int option = *((int *)iptr->option);

        sendto_one(source_p, ":%s %d %s :%-30s %-5s [%-30s]",
                   from, RPL_INFO, to,
                   iptr->name, option ? "ON" : "OFF",
                   iptr->desc ? iptr->desc : "<none>");

        break;
      }

      /* Output info_table[i].option as "YES" or "NO" */
      case OUTPUT_BOOLEAN_YN:
      {
        int option = *((int *)iptr->option);

        sendto_one(source_p, ":%s %d %s :%-30s %-5s [%-30s]",
                   from, RPL_INFO, to,
                   iptr->name, option ? "YES" : "NO",
                   iptr->desc ? iptr->desc : "<none>");
        break;
      }

      case OUTPUT_BOOLEAN2:
      {
        int option = *((int *)iptr->option);

        sendto_one(source_p, ":%s %d %s :%-30s %-5s [%-30s]",
                   from, RPL_INFO, to,
                   iptr->name, option ? ((option == 1) ? "MASK" : "YES") : "NO",
                   iptr->desc ? iptr->desc : "<none>");
        break;
      }
    }
  }

  /* Don't send oper_only_umodes...it's a bit mask, we will have to decode it
   * in order for it to show up properly to opers who issue INFO
   */
#ifndef EFNET
  /* jdc -- Only send compile information to admins. */
  if (IsAdmin(source_p))
    sendto_one(source_p, ":%s %d %s :Running on [%s]",
               from, RPL_INFO, to, ircd_platform); 
#endif
  sendto_one(source_p, form_str(RPL_INFO),
             from, to, "");
}
