/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  general.c: Defines the general{} block of ircd.conf.
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

#include "stdinc.h"
#include "conf/conf.h"
#include "client.h"
#include "numeric.h"
#include "s_serv.h"

struct GeneralConf General;

static dlink_node *hreset;

/*
 * reset_general()
 *
 * Sets up default values before a rehash.
 *
 * inputs: none
 * output: none
 */
static void *
reset_general(va_list args)
{
  int cold = va_arg(args, int);

  /* Local connection initialization */
  General.disable_auth = General.ping_cookie = NO;
  General.dots_in_ident = 0, General.dot_in_ip6_addr = YES;
  General.short_motd = NO;
  General.invisible_on_connect = YES;

  /* Registered clients settings */
  General.hide_spoof_ips = General.use_whois_actually = YES;
  General.burst_away = General.disable_remote_commands = NO;
  General.stats_o_oper_only = General.stats_P_oper_only = 0,
    General.stats_i_oper_only = General.stats_k_oper_only = 1;

  /* Abuse protection */
  General.throttle_time = 10;
  General.max_targets = MAX_TARGETS_DEFAULT;
  General.max_accept = 20;
  General.caller_id_wait = 60;
  General.opers_bypass_callerid = NO;
  General.oper_pass_resv = YES;
  General.client_flood = CLIENT_FLOOD_DEFAULT;
  General.no_oper_flood = General.true_no_oper_flood = NO;
  General.pace_wait_simple = 1, General.pace_wait = 10;
  General.default_floodcount = 8;
  General.anti_nick_flood = NO;
  General.max_nick_time = 20, General.max_nick_changes = 5;
  General.anti_spam_exit_message_time = 0;
  General.reject_hold_time = General.idletime = 0;

  /* Opers settings */
  General.oper_only_umodes = UMODE_DEBUG, General.oper_umodes = UMODE_LOCOPS |
    UMODE_SERVNOTICE | UMODE_OPERWALL | UMODE_WALLOP;
  General.kill_chase_time_limit = 90;
  General.min_nonwildcard = 4, General.min_nonwildcard_simple = 3;
  General.gline_min_cidr = 16, General.gline_min_cidr6 = 48;
  General.kline_with_reason = YES;
  if (!cold)
    MyFree(General.kline_reason);
  General.kline_reason = NULL;
  General.tkline_expire_notices = General.failed_oper_notice = YES;

  /* Server to server options */
  General.warn_no_nline = YES;
  General.ignore_bogus_ts = NO;
  General.ts_warn_delta = TS_WARN_DELTA_DEFAULT, General.ts_max_delta =
    TS_MAX_DELTA_DEFAULT;
  if (!cold)
    MyFree(General.servlink_path);
  DupString(General.servlink_path, SLPATH);
#ifdef HAVE_LIBCRYPTO
  General.default_cipher_preference = NULL;
#endif
  General.use_egd = NO;
  if (!cold)
    MyFree(General.egdpool_path);
  General.egdpool_path = NULL;
  General.compression_level = 0;

  return pass_callback(hreset, cold);
}

/*
 * stats_oper_only()
 *
 * Handles yes/no/masked values.
 *
 * inputs:
 *   list  -  pointer to a dlink list of string pointers
 *   var   -  where we should write the result
 * output: none
 */
static void
stats_oper_only(void *list, void *var)
{
  char *value;

  if (dlink_list_length((dlink_list *) list) != 1)
  {
    error:
    parse_error("value should be yes/no/masked");
    return;
  }

  value = (char *) ((dlink_list *) list)->head->data;
  if (!irccmp(value, "no"))
    *(char *) var = 0;
  else if (!irccmp(value, "masked"))
    *(char *) var = 1;
  else if (!irccmp(value, "yes"))
    *(char *) var = 2;
  else
    goto error;
}

/*
 * set_message_locale()
 *
 * Controls the message_locale field.
 *
 * inputs:
 *   str    -  pointer to a string containing locale name
 *   param  -  unused
 * output: none
 */
static void
set_message_locale(void *str, void *param)
{
  char *loc = (char *) param;

  if (strlen(loc) > LOCALE_LENGTH - 2)
    loc[LOCALE_LENGTH - 1] = 0;

  set_locale(loc);
}

/*
 * havent_read_conf()
 *
 * Exits the ircd because of lame admin. ;)
 *
 * inputs:
 *   value  -  1 in example.conf
 *   param  -  unused
 * output: none
 */
static void
havent_read_conf(void *value, void *param)
{
  if (*(int *) value > 0)
  {
    ilog(L_CRIT, "You haven't read your config file properly.");
    ilog(L_CRIT, "There is a line in the example conf that will kill your "
                 "server if not removed.");
    ilog(L_CRIT, "Consider actually reading/editing the conf file, and "
                 "removing this line.");
    exit(0);
  }
}

/*
 * set_compression_level()
 *
 * Controls the compression_level field.
 *
 * inputs:
 *   value  -  pointer to an integer value containing new level
 *   param  -  unused
 * output: none
 */
static void
set_compression_level(void *value, void *param)
{
#ifndef HAVE_LIBZ
  parse_error("Ignoring compression_level, no zlib support");
#else
  int lvl = *(int *) param;

  if (lvl < 1 || lvl > 9)
  {
    parse_error("Ignoring invalid compression_level, using default");
    General.compression_level = 0;
  }
  else
    General.compression_level = lvl;
#endif
}

/*
 * set_default_cipher()
 *
 * Controls the default_cipher_preference field.
 *
 * inputs:
 *   value  -  pointer to cipher name
 *   param  -  unused
 * output: none
 */
static void
set_default_cipher(void *value, void *param)
{
#ifndef HAVE_LIBCRYPTO
  parse_error("Ignoring default_cipher_preference (no OpenSSL support)");
#else
  struct EncCapability *ecap;
  char *cipher_name;

  General.default_cipher_preference = NULL;
  cipher_name = (char *) param;

  for (ecap = CipherTable; ecap->name != NULL; ecap++)
    if (!irccmp(ecap->name, cipher_name) && (ecap->cap && CAP_ENC_MASK))
    {
      General.default_cipher_preference = ecap;
      return;
    }

  parse_error("Invalid cipher");
#endif
}

/* XXX this should go to s_user.c to simplify modularisation */
static struct UmodeMapping {
  char *name;
  unsigned int umode;
} umode_mappings[] = {
  {"bots", UMODE_BOTS},
  {"cconn", UMODE_CCONN},
  {"deaf", UMODE_DEAF},
  {"debug", UMODE_DEBUG},
  {"full", UMODE_FULL},
  {"softcallerid", UMODE_SOFTCALLERID},
  {"callerid", UMODE_CALLERID},
  {"invisible", UMODE_INVISIBLE},
  {"skill", UMODE_SKILL},
  {"locops", UMODE_LOCOPS},
  {"nchange", UMODE_NCHANGE},
  {"rej", UMODE_REJ},
  {"servnotice", UMODE_SERVNOTICE},
  {"unauth", UMODE_UNAUTH},
  {"wallop", UMODE_WALLOP},
  {"external", UMODE_EXTERNAL},
  {"spy", UMODE_SPY},
  {"operwall", UMODE_OPERWALL},
  {NULL, 0}
};

/*
 * parse_umode_list()
 *
 * Parses a list of usermodes.
 *
 * inputs:
 *   list  -  points to a dlink_list of strings to parse
 *   var   -  where to save the result as unsigned int
 * output: none
 */
static void
parse_umode_list(void *list, void *var)
{
  dlink_node *ptr;
  char *str;
  unsigned int umodes = 0;
  int found;
  struct UmodeMapping *p;

  DLINK_FOREACH(ptr, ((dlink_list *) list)->head)
  {
    str = (char *) ptr->data;

    found = NO;
    for (p = umode_mappings; p->name; p++)
      if (!irccmp(str, p->name))
      {
        umodes |= p->umode;
        found = YES;
        break;
      }

    if (!found)
      parse_error("Unknown umode [%s]", str);
  }

  *(unsigned int *) var = umodes;
}

/*
 * init_general()
 *
 * Defines the general{} conf section.
 *
 * inputs: none
 * output: none
 */
void
init_general(void)
{
  struct ConfSection *s = add_conf_section("general", 1);

  hreset = install_hook(reset_conf, reset_general);

  /* Local connection initialization */
  add_conf_field(s, "disable_auth", CT_BOOL, NULL, &General.disable_auth);
  add_conf_field(s, "ping_cookie", CT_BOOL, NULL, &General.ping_cookie);
  add_conf_field(s, "dots_in_ident", CT_NUMBER, NULL, &General.dots_in_ident);
  add_conf_field(s, "dot_in_ip6_addr", CT_BOOL, NULL, &General.dot_in_ip6_addr);
  add_conf_field(s, "short_motd", CT_BOOL, NULL, &General.short_motd);
  add_conf_field(s, "invisible_on_connect", CT_BOOL, NULL,
    &General.invisible_on_connect);

  /* Registered clients settings */
  add_conf_field(s, "hide_spoof_ips", CT_BOOL, NULL, &General.hide_spoof_ips);
  add_conf_field(s, "use_whois_actually", CT_BOOL, NULL,
    &General.use_whois_actually);
  add_conf_field(s, "burst_away", CT_BOOL, NULL, &General.burst_away);
  add_conf_field(s, "disable_remote_commands", CT_BOOL, NULL,
    &General.disable_remote_commands);
  add_conf_field(s, "message_locale", CT_STRING, set_message_locale, NULL);
  add_conf_field(s, "stats_o_oper_only", CT_BOOL, NULL,
    &General.stats_o_oper_only);
  add_conf_field(s, "stats_P_oper_only", CT_BOOL, NULL,
    &General.stats_P_oper_only);
  add_conf_field(s, "stats_i_oper_only", CT_LIST, stats_oper_only,
    &General.stats_i_oper_only);
  add_conf_field(s, "stats_k_oper_only", CT_LIST, stats_oper_only,
    &General.stats_k_oper_only);

  /* Abuse protection */
  add_conf_field(s, "throttle_time", CT_NUMBER, NULL, &General.throttle_time);
  add_conf_field(s, "max_targets", CT_NUMBER, NULL, &General.max_targets);
  add_conf_field(s, "max_accept", CT_NUMBER, NULL, &General.max_accept);
  add_conf_field(s, "caller_id_wait", CT_TIME, NULL, &General.caller_id_wait);
  add_conf_field(s, "opers_bypass_callerid", CT_BOOL, NULL,
    &General.opers_bypass_callerid);
  add_conf_field(s, "oper_pass_resv", CT_BOOL, NULL, &General.oper_pass_resv);
  add_conf_field(s, "client_flood", CT_NUMBER, NULL, &General.client_flood);
  add_conf_field(s, "no_oper_flood", CT_BOOL, NULL, &General.no_oper_flood);
  add_conf_field(s, "true_no_oper_flood", CT_BOOL, NULL,
    &General.true_no_oper_flood);
  add_conf_field(s, "pace_wait_simple", CT_TIME, NULL,
    &General.pace_wait_simple);
  add_conf_field(s, "pace_wait", CT_TIME, NULL, &General.pace_wait);
  add_conf_field(s, "default_floodcount", CT_NUMBER, NULL,
    &General.default_floodcount);
  add_conf_field(s, "anti_nick_flood", CT_BOOL, NULL, &General.anti_nick_flood);
  add_conf_field(s, "max_nick_time", CT_TIME, NULL, &General.max_nick_time);
  add_conf_field(s, "max_nick_changes", CT_NUMBER, NULL,
    &General.max_nick_changes);
  add_conf_field(s, "anti_spam_exit_message_time", CT_TIME, NULL,
    &General.anti_spam_exit_message_time);
  add_conf_field(s, "reject_hold_time", CT_TIME, NULL,
    &General.reject_hold_time);
  add_conf_field(s, "idletime", CT_TIME, NULL, &General.idletime);
  add_conf_field(s, "havent_read_conf", CT_NUMBER, havent_read_conf, NULL);

  /* Opers settings */
  add_conf_field(s, "oper_only_umodes", CT_LIST, parse_umode_list,
    &General.oper_only_umodes);
  add_conf_field(s, "oper_umodes", CT_LIST, parse_umode_list,
    &General.oper_umodes);
  add_conf_field(s, "kill_chase_time_limit", CT_TIME, NULL,
    &General.kill_chase_time_limit);
  add_conf_field(s, "min_nonwildcard", CT_NUMBER, NULL,
    &General.min_nonwildcard);
  add_conf_field(s, "min_nonwildcard_simple", CT_NUMBER, NULL,
    &General.min_nonwildcard_simple);
  add_conf_field(s, "gline_min_cidr", CT_NUMBER, NULL, &General.gline_min_cidr);
  add_conf_field(s, "gline_min_cidr6", CT_NUMBER, NULL,
    &General.gline_min_cidr6);
  add_conf_field(s, "kline_with_reason", CT_BOOL, NULL,
    &General.kline_with_reason);
  add_conf_field(s, "kline_reason", CT_STRING, NULL, &General.kline_reason);
  add_conf_field(s, "tkline_expire_notices", CT_BOOL, NULL,
    &General.tkline_expire_notices);
  add_conf_field(s, "failed_oper_notice", CT_BOOL, NULL,
    &General.failed_oper_notice);

  /* Server to server options */
  add_conf_field(s, "warn_no_nline", CT_BOOL, NULL, &General.warn_no_nline);
  add_conf_field(s, "ignore_bogus_ts", CT_BOOL, NULL, &General.ignore_bogus_ts);
  add_conf_field(s, "ts_warn_delta", CT_TIME, NULL, &General.ts_warn_delta);
  add_conf_field(s, "ts_max_delta", CT_TIME, NULL, &General.ts_max_delta);
  add_conf_field(s, "servlink_path", CT_STRING, NULL, &General.servlink_path);
  add_conf_field(s, "default_cipher_preference", CT_STRING, set_default_cipher,
    NULL);
  add_conf_field(s, "use_egd", CT_BOOL, NULL, &General.use_egd);
  add_conf_field(s, "egdpool_path", CT_STRING, NULL, &General.egdpool_path);
  add_conf_field(s, "compression_level", CT_NUMBER, set_compression_level,
    NULL);
}
