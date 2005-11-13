/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  class.h: Defines class{} conf section.
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

struct Class
{
  char *name;
  int connectfreq, ping_time, ping_warning;
  long sendq_size;

  int userhost_limit[2], host_limit[2];

  int number_per_cidr;
  int cidr_bitlen_ipv4, cidr_bitlen_ipv6;
  dlink_list list_ipv4, list_ipv6;

  int max_ident, max_noident, max_number;

  int stale;
  int refcnt, cur_clients;
  dlink_node node;
};

typedef void (* ENUMCLASSFUNC) (struct Class *);

EXTERN struct Class *ref_class_by_name(const char *);
EXTERN struct Class *ref_class_by_ptr(struct Class *);
EXTERN void unref_class(struct Class *);
EXTERN struct Class *make_class(const char *);
EXTERN void delete_class(struct Class *);
EXTERN void enum_classes(ENUMCLASSFUNC);

#ifdef IN_CONF_C
void init_class(void);
#endif
