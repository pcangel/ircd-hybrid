/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  stores.c: General functions to support storage backends
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

static struct ConfStoreHandle *open_fail(char *, struct ConfStoreField *);
static int read_fail(struct ConfStoreHandle *, va_list);
static int close_fail(struct ConfStoreHandle *);
static int append_fail(char *, struct ConfStoreField *, va_list);
static int delete_fail(char *, struct ConfStoreField *, va_list);

static struct ConfStoreFunctions no_store = {
  open_fail, read_fail, close_fail,
  append_fail, delete_fail
};

static struct ConfStoreFunctions *backend = &no_store;

/* Registers a new backend.
 *
 * Should only be called by one backend, having more than one loaded at a time
 * is an error, for now.
 */
int
register_store_backend(struct ConfStoreFunctions *funcs)
{
  if (backend == &no_store)
  {
    backend = funcs;
    return 0;
  } else {
    ilog(L_ERROR, "Attempted to register a conf store when one was already registered.");
    return -1;
  }
}

int
deregister_store_backend(struct ConfStoreFunctions *funcs)
{
  if (backend == funcs)
  {
    backend = &no_store;
    return 0;
  } else {
    ilog(L_ERROR, "Attempted to deregister a conf store that wasn't active.");
    return -1;
  }
}


static struct ConfStoreHandle *
open_fail(char *name, struct ConfStoreField *fields)
{
  return NULL;
}

static int
read_fail(struct ConfStoreHandle *handle, va_list args)
{
  return 0;
}

static int
close_fail(struct ConfStoreHandle *handle)
{
  return -1;
}

static int
append_fail(char *name, struct ConfStoreField *fields, va_list args)
{
  return -1;
}

static int
delete_fail(char *name, struct ConfStoreField *fields, va_list args)
{
  return -1;
}


/* open_conf_store()
 *
 * Opens a conf backend and returns a handler for reading data from it.
 *
 * inputs:
 *     filename - The name of the file / database table to open.
 *                Exact semantics depend on the backend
 *     fields   - Which fields are expected to be stored,
 *                and how they should be retrieved.
 *
 * The backends will likely store fields somewhere inside the ConfStoreHandle,
 * so this should not point to a place on the stack that doesn't live as
 * long as the returned handle will.
 */
struct ConfStoreHandle *
open_conf_store(char *filename, struct ConfStoreField *fields)
{
  return backend->open(filename, fields);
}

/* read_conf_store()
 *
 * Attempts to read the next entry from the conf store.
 *
 * Allocates memory for CSF_STRING and other pointer fields as needed.
 * These are allocated by standard allocators and must be freed by the caller.
 *
 * inputs:
 *     handle - the handle from open_conf_store()
 *     ...    - Pointers to the places to store to (NULL is allowed, and
 *              specifies that the field should not be retrieved)
 *
 * returns
 *     1 on success, and 0 when no more records are found
 */
int
read_conf_store(struct ConfStoreHandle *handle, ...)
{
  va_list args;
  int result;

  va_start(args, handle);
  result = backend->read(handle, args);
  va_end(args);

  return result;
}

/* close_conf_store()
 *
 * Frees all resources associated with a given conf store handle.
 *
 * Should return zero on success and nonzero on failure,
 * but as you cannot do anything sensible when a close fails,
 * nobody will check this.
 */
int
close_conf_store(struct ConfStoreHandle *handle)
{
  return backend->close(handle);
}

/* append_conf_store()
 *
 * Appends a config item to a store
 *
 * This does not require an open_conf_store(),
 * as no facility seems neccessary at this point to mass-add items.
 *
 * inputs:
 *     name   - name to store to (see description under open_ )
 *     fields - how to store (ditto)
 *     ...    - the data to store
 */
int
append_conf_store(char *name, struct ConfStoreField *fields, ...)
{
  va_list args;
  int result;

  va_start(args, fields);
  result = backend->append(name, fields, args);
  va_end(args);

  return result;
}

/* delete_conf_store()
 *
 * Attempts to delete an item from a store
 *
 * Note: do NOT pass direct types (char*, int, time_t, ...) but pointers to
 * them. This allows for NULL to specify a wildcard.
 *
 * returns the number of items deleted, or -1 on error.
 */
int
delete_conf_store(char *name, struct ConfStoreField *fields, ...)
{
  va_list args;
  int result;

  va_start(args, fields);
  result = backend->delete(name, fields, args);
  va_end(args);

  return result;
}
