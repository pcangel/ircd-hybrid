/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  stores.h: A header for dynamic-conf storage backends
 *
 *  Copyright (C) 2007 by the Hybrid Development Team.
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

/* Except for CSF_NONE, each take the indicated type on append_,
 * and a pointer to it on read and delete (in the latter,
 * NULL specifies a wildcard)
 */
enum CsfType {
  CSF_NONE,              /* void* on read and write */
  CSF_STRING,            /* char*  */
  CSF_STRING_MATCH_CASE, /* char*  */
  CSF_NUMBER,            /* int    */
  CSF_DATETIME,          /* time_t */
}

/* These take a va_list so we can at some point chain them more easily,
 * if desired.
 */
struct ConfStoreFunctions
{
  struct ConfStoreHandle *(*open)(char *, struct ConfStoreField *);
  int (*read)(struct ConfStoreHandle *, va_list);
  int (*close)(struct ConfStoreHandle *);
  int (*append)(char *, struct ConfStoreField *, va_list);
  int (*delete)(char *, struct ConfStoreField *, va_list);
};

/* Only declared, differs between backends */
struct ConfStoreHandle;

struct ConfStoreField
{
  const char *name; /* The name, for e.g. SQL column names */
  enum CsfType type;
};


EXTERN int register_store_backend(struct ConfStoreFunctions *);
EXTERN int deregister_store_backend(struct ConfStoreFunctions *);

EXTERN struct ConfStoreHandle *open_conf_store(char *, struct ConfStoreField *);
EXTERN int read_conf_store(struct ConfStoreHandle *, ...);
EXTERN int close_conf_store(struct ConfStoreHandle *);

EXTERN int append_conf_store(char *, struct ConfStoreField *, ...);
EXTERN int delete_conf_store(char *, struct ConfStoreField *, ...);
