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
