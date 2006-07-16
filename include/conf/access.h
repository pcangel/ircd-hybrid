/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  access.h: Common code for user@host access control blocks.
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

struct AccessConf
{
  unsigned int type;
  unsigned int flags;
  uint64_t precedence;
  char *user;
  char *host;
  struct irc_ssaddr ip;
  struct AccessConf *hnext;
  time_t expires;
  char *text;
};

#define ATABLE_SIZE         4096
#define EXPIRE_FREQUENCY    60
#define MAX_ACB_TYPES       20

EXTERN struct AccessConf *atable[];
EXTERN struct Callback *cb_expire_confs;

typedef void ACB_FREE_HANDLER(struct AccessConf *);
typedef int ACB_EXAMINE_HANDLER(struct AccessConf *);

EXTERN void add_access_conf(struct AccessConf *);
EXTERN void destroy_access_conf(struct AccessConf *);
EXTERN void acb_generic_free(struct AccessConf *);
EXTERN void del_matching_access_confs(ACB_EXAMINE_HANDLER *);
EXTERN int register_acb_type(void *);
EXTERN void unregister_acb_type(int);

#ifdef IN_CONF_C
void init_access(void);
#endif
