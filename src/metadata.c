/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  metadata.c: metadata system
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
#include "metadata.h"

struct Metadata *
add_metadata_str (dlink_list * list, char *key, char *strval)
{
  struct Metadata *mdptr;

  assert (key != NULL);
  assert (strval != NULL);

  if (find_metadata (list, key) != NULL)
    return NULL;

  mdptr = MyMalloc (sizeof (struct Metadata));
  memset (mdptr, 0, sizeof (struct Metadata));
  DupString (key, mdptr->key);
  DupString (strval, mdptr->u.strval);

  dlinkAdd (mdptr, make_dlink_node (), list);

  return mdptr;
}

struct Metadata *
add_metadata_int (dlink_list * list, char *key, int intval)
{
  struct Metadata *mdptr;

  assert (key != NULL);

  if (find_metadata (list, key) != NULL)
    return NULL;

  mdptr = MyMalloc (sizeof (struct Metadata));
  memset (mdptr, 0, sizeof (struct Metadata));
  DupString (key, mdptr->key);
  mdptr->u.intval = intval;

  dlinkAdd (mdptr, make_dlink_node (), list);

  return mdptr;
}

struct Metadata *
find_metadata (dlink_list * list, char *key)
{
  dlink_node *n;

  assert (key != NULL);

  DLINK_FOREACH (n, list->head)
  {
    struct Metadata *md = (struct Metadata *) n->data;

    if (!irccmp (key, md->key))
      return md;
  }

  return NULL;
}

void
destroy_metadata (dlink_list * list, char *key)
{
  struct Metadata *md;

  assert (key != NULL);

  if ((md = find_metadata (list, key)) == NULL)
    return;

  if (md->u.strval != NULL)
    MyFree (md->u.strval);

  dlinkFindDelete (list, md);

  MyFree (md);
}
