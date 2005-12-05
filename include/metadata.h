/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  metadata.h: header describing the metadata system
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

#ifndef METADATA_H_INCLUDED
#define METADATA_H_INCLUDED

#include "stdinc.h"				/* EXTERN */

/*
 * The metadata structure is a simple structure that defines a key,
 * and value, the value is a union.
 */
struct Metadata {
	char *key;
	union {
		char *strval;
		int intval;
	} u;
};

EXTERN struct Metadata *add_metadata_str(dlink_list *mtable, char *key, char *strval);
EXTERN struct Metadata *add_metadata_int(dlink_list *mtable, char *key, int intval);
EXTERN struct Metadata *find_metadata(dlink_list *mtable, char *key);
EXTERN void destroy_metadata(dlink_list *mtable, char *key);

#endif
