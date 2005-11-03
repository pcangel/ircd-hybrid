/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  general.h: Defines general{} conf section.
 *
 *  Copyright (C) 2005 by the Hybrid Development Team.
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

struct GeneralConf
{
  /* Local connection initialization */
  char disable_auth;
  char ping_cookie;
  int dots_in_ident;
  char dot_in_ip6_addr;
  char short_motd;
  char invisible_on_connect;

  /* Registered clients settings */
  char hide_spoof_ips;
  char use_whois_actually;
  char burst_away;
  char disable_remote_commands;  /* XXX this should go to serverhide */
  char stats_o_oper_only, stats_P_oper_only, stats_i_oper_only,
    stats_k_oper_only;

  /* Abuse protection */
  int throttle_time;
  int max_targets;
  int max_accept;
  int caller_id_wait;
  char opers_bypass_callerid;
  char oper_pass_resv;
  int client_flood;
  char no_oper_flood, true_no_oper_flood;
  int pace_wait_simple, pace_wait;
  int default_floodcount;
  char anti_nick_flood;
  int max_nick_time, max_nick_changes;
  int anti_spam_exit_message_time;
  int reject_hold_time;
  int idletime;

  /* Opers settings */
  unsigned int oper_only_umodes, oper_umodes;
  int kill_chase_time_limit;
  int min_nonwildcard, min_nonwildcard_simple;
  int gline_min_cidr, gline_min_cidr6;
  char kline_with_reason;
  char *kline_reason;
  char tkline_expire_notices;
  char failed_oper_notice;

  /* Server to server options */
  char warn_no_nline;
  char ignore_bogus_ts;
  int ts_warn_delta, ts_max_delta;
  char *servlink_path;
#ifdef HAVE_LIBCRYPTO
  struct EncCapability *default_cipher_preference;
#endif
  char use_egd, *egdpool_path;
  int compression_level;
  int max_watch;
};

EXTERN struct GeneralConf General;

#ifdef IN_CONF_C
void init_general(void);
#endif
