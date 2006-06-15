/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_version.c: Shows ircd version information.
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
#include "handlers.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "s_conf.h"
#include "s_serv.h"
#include "s_user.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "conf/modules.h"

static char *confopts(struct Client *);
static void m_version(struct Client *, struct Client *, int, char *[]);
static void ms_version(struct Client *, struct Client *, int, char *[]);
static void mo_version(struct Client *, struct Client *, int, char *[]);

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

/* Option string. */
static const char serveropts[] = {
  ' ',
  'T',
  'S',
#ifdef TS_CURRENT
  '0' + TS_CURRENT,
#endif
/* ONLY do TS */
/* ALWAYS do TS_WARNINGS */
  'o',
  'w',
  '\0'
};

struct Message version_msgtab = {
  "VERSION", 0, 0, 0, 0, MFLG_SLOW, 0,
  { m_unregistered, m_version, ms_version, m_ignore, mo_version, m_ignore }
};

INIT_MODULE(m_version, "$Revision$")
{
  mod_add_cmd(&version_msgtab);
}

CLEANUP_MODULE
{
  mod_del_cmd(&version_msgtab);
}

/*
 * m_version - VERSION command handler
 *      parv[0] = sender prefix
 *      parv[1] = remote server
 */
static void
m_version(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  static time_t last_used = 0;

  if ((last_used + ConfigFileEntry.pace_wait_simple) > CurrentTime)
  {
    /* safe enough to give this on a local connect only */
    sendto_one(source_p, form_str(RPL_LOAD2HI),
               me.name, source_p->name);
    return;
  }

  last_used = CurrentTime;

  if (!ConfigFileEntry.disable_remote)
    if (hunt_server(source_p, ":%s VERSION :%s",
                    1, parc, parv) != HUNTED_ISME)
      return;

  sendto_one(source_p, form_str(RPL_VERSION),
             me.name, source_p->name, ircd_version, serno,
             me.name, confopts(source_p), serveropts);
  show_isupport(source_p);
}

/*
 * mo_version - VERSION command handler
 *      parv[0] = sender prefix
 *      parv[1] = remote server
 */
static void
mo_version(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  
  if (hunt_server(source_p, ":%s VERSION :%s", 
		  1, parc, parv) != HUNTED_ISME)
    return;

  sendto_one(source_p, form_str(RPL_VERSION), me.name, parv[0], ircd_version, 
  	     serno, me.name, confopts(source_p), serveropts);

  show_isupport(source_p);
}

/*
 * ms_version - VERSION command handler
 *      parv[0] = sender prefix
 *      parv[1] = remote server
 */
static void
ms_version(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  if (hunt_server(source_p, ":%s VERSION :%s", 
                  1, parc, parv) != HUNTED_ISME)
    return;

  sendto_one(source_p, form_str(RPL_VERSION),
             ID_or_name(&me, client_p),
             ID_or_name(source_p, client_p),
             ircd_version, serno,
             me.name, confopts(source_p), serveropts);
  show_isupport(source_p);
}

/* confopts()
 *
 * input  - client pointer
 * output - ircd.conf option string
 * side effects - none
 */
static char *
confopts(struct Client *source_p)
{
  static char result[12];
  char *p = result;

  if (ConfigChannel.use_except)
    *p++ = 'e';
  if (ConfigFileEntry.glines)
    *p++ = 'G';
  *p++ = 'g';

  /* might wanna hide this :P */
  if (ServerInfo.hub && 
      (!ConfigFileEntry.disable_remote || IsOper(source_p)))
  {
    *p++ = 'H';
  }

  if (ConfigChannel.use_invex)
    *p++ = 'I';
  if (ConfigChannel.use_knock)
    *p++ = 'K';
  *p++ = 'M';

  if (ConfigFileEntry.ignore_bogus_ts)
    *p++ = 'T';
#ifdef USE_SYSLOG
  *p++ = 'Y';
#endif
#ifdef HAVE_LIBZ
  *p++ = 'Z';
#endif
  *p++ = '6';

  *p = '\0';

  return result;
}
