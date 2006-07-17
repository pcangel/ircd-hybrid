/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  hostmask.c: Code to efficiently find IP & hostmask based configs.
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
#include "ircd_defs.h"
#include "s_conf.h"
#include "hostmask.h"
#include "numeric.h"
#include "send.h"

/* struct AccessItem* find_address_conf(const char*, const char*,
 * 	                               struct irc_ssaddr*, int, char *);
 * Input: The hostname, username, address, address family.
 * Output: The applicable AccessItem.
 * Side-effects: None
 */
struct AccessItem *
find_address_conf(const char *host, const char *user,
                  struct irc_ssaddr *ip, int aftype, char *password)
{
  struct AccessItem *iconf, *kconf;

  /* Find the best I-line... If none, return NULL -A1kmm */
  if ((iconf = find_conf_by_address(host, ip, CONF_CLIENT, aftype, user,
                                    password)) == NULL)
    return(NULL);

  /* If they are exempt from K-lines, return the best I-line. -A1kmm */
  if (IsConfExemptKline(iconf))
    return(iconf);

  /* Find the best K-line... -A1kmm */
  kconf = find_conf_by_address(host, ip, CONF_KILL, aftype, user, NULL);

  /* If they are K-lined, return the K-line. Otherwise, return the
   * I-line. -A1kmm */
  if (kconf != NULL)
    return(kconf);

  kconf = find_conf_by_address(host, ip, CONF_GLINE, aftype, user, NULL);
  if (kconf != NULL && !IsConfExemptGline(iconf))
    return(kconf);

  return(iconf);
}

struct AccessItem *
find_gline_conf(const char *host, const char *user,
                struct irc_ssaddr *ip, int aftype)
{
  struct AccessItem *eline;

  eline = find_conf_by_address(host, ip, CONF_EXEMPTKLINE, aftype,
                               user, NULL);
  if (eline != NULL)
    return(eline);

  return(find_conf_by_address(host, ip, CONF_GLINE, aftype, user, NULL));
}

/* find_kline_conf
 *
 * inputs	- pointer to hostname
 *		- pointer to username
 *		- incoming IP and type (IPv4 vs. IPv6)
 * outut	- pointer to kline conf if found NULL if not
 * side effects	-
 */
struct AccessItem *
find_kline_conf(const char *host, const char *user,
		struct irc_ssaddr *ip, int aftype)
{
  struct AccessItem *eline;

  eline = find_conf_by_address(host, ip, CONF_EXEMPTKLINE, aftype,
                               user, NULL);
  if (eline != NULL)
    return(eline);

  return(find_conf_by_address(host, ip, CONF_KILL, aftype, user, NULL));
}

/* struct AccessItem* find_dline_conf(struct irc_ssaddr*, int)
 *
 * Input:	An address, an address family.
 * Output:	The best matching D-line or exempt line.
 * Side effects: None.
 */
struct AccessItem *
find_dline_conf(const struct irc_ssaddr *addr, int aftype)
{
  struct AccessItem *eline;

  eline = find_conf_by_address(NULL, addr, CONF_EXEMPTDLINE | 1, aftype,
                               NULL, NULL);
  if (eline != NULL)
    return(eline);
  return(find_conf_by_address(NULL, addr, CONF_DLINE | 1, aftype, NULL, NULL));
}

/*
 * make_iline_prefix()
 *
 * inputs       - pointer to struct Client requesting output
 *              - pointer to struct AccessItem 
 * output       - pointer to static string with prefixes listed in ascii form
 * side effects - NONE
 */
char *
make_iline_prefix(struct Client *sptr, struct AccessItem *aconf)
{
  static char prefix_of_host[14];
  char *prefix_ptr = prefix_of_host;

  if (IsNoTilde(aconf))
    *prefix_ptr++ = '-';
  if (IsLimitIp(aconf))
    *prefix_ptr++ = '!';
  if (IsNeedIdentd(aconf))
    *prefix_ptr++ = '+';
  if (!IsNeedPassword(aconf))
    *prefix_ptr++ = '&';
  if (IsConfExemptResv(aconf))
    *prefix_ptr++ = '$';
  if (IsNoMatchIp(aconf))
    *prefix_ptr++ = '%';
  if (IsConfDoSpoofIp(aconf))
    *prefix_ptr++ = '=';
  if (MyOper(sptr) && IsConfExemptKline(aconf))
    *prefix_ptr++ = '^';
  if (MyOper(sptr) && IsConfExemptGline(aconf))
    *prefix_ptr++ = '_';
  if (MyOper(sptr) && IsConfExemptLimits(aconf))
    *prefix_ptr++ = '>';
  if (MyOper(sptr) && IsConfIdlelined(aconf))
    *prefix_ptr++ = '<';
  if (IsConfCanFlood(aconf))
    *prefix_ptr++ = '|';
  *prefix_ptr = '\0';

  return prefix_of_host;
}

/* report_auth()
 *
 * Inputs: pointer to client to report to
 * Output: None
 * Side effects: Reports configured auth{} blocks to client_p
 */
void
report_auth(struct Client *client_p)
{
  struct AddressRec *arec;
  struct ConfItem *conf;
  struct AccessItem *aconf;
  int i;

  for (i = 0; i < ATABLE_SIZE; i++)
  {
    for (arec = atable[i]; arec; arec = arec->next)
    {
      if (arec->type == CONF_CLIENT)
      {
        aconf = arec->aconf;

        if (!MyOper(client_p) && IsConfDoSpoofIp(aconf))
          continue;

	conf = aconf->conf_ptr;

        /* We are doing a partial list, based on what matches the u@h of the
         * sender, so prepare the strings for comparing --fl_
	 */
        if (ConfigFileEntry.hide_spoof_ips)
          sendto_one(client_p, form_str(RPL_STATSILINE), me.name,
                     client_p->name, 'I',
		     conf->name == NULL ? "*" : conf->name,
		     make_iline_prefix(client_p, aconf), aconf->user,
                     IsConfDoSpoofIp(aconf) ? "255.255.255.255" :
                     aconf->host, aconf->port,
		     aconf->class_ptr ? aconf->class_ptr->name : "<default>");
        else
          sendto_one(client_p, form_str(RPL_STATSILINE), me.name,
                     client_p->name, 'I',
		     conf->name == NULL ? "*" : conf->name,
		     make_iline_prefix(client_p, aconf), aconf->user,
                     aconf->host, aconf->port,
		     aconf->class_ptr ? aconf->class_ptr->name : "<default>");
      }
    }
  }
}

/* report_Klines()
 * Inputs: Client to report to,
 *	   type(==0 for perm, !=0 for temporary)
 *	   mask 
 * Output: None
 * Side effects: Reports configured K(or k)-lines to client_p.
 */
void
report_Klines(struct Client *client_p, int tkline)
{
  struct AddressRec *arec = NULL;
  struct AccessItem *aconf = NULL;
  int i;
  const char *p = NULL;

  if (tkline)
    p = "k";
  else
    p = "K";

  for (i = 0; i < ATABLE_SIZE; i++)
  {
    for (arec = atable[i]; arec; arec = arec->next)
    {
      if (arec->type == CONF_KILL)
      {
        if ((tkline && !((aconf = arec->aconf)->flags & CONF_FLAGS_TEMPORARY)) ||
            (!tkline && ((aconf = arec->aconf)->flags & CONF_FLAGS_TEMPORARY)))
          continue;

	if (IsOper(client_p))
	  sendto_one(client_p, form_str(RPL_STATSKLINE), me.name,
                     client_p->name, p, aconf->host, aconf->user,
		     aconf->reason, aconf->oper_reason ? aconf->oper_reason : "");
	else
          sendto_one(client_p, form_str(RPL_STATSKLINE), me.name,
                     client_p->name, p, aconf->host, aconf->user,
		     aconf->reason, "");
      }
    }
  }
}
