/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  modules.h: A header for the modules functions.
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

#ifndef INCLUDED_modules_h
#define INCLUDED_modules_h

#include "setup.h"
#include "parse.h"

#ifdef HAVE_SHL_LOAD
#include <dl.h>
#endif
#if !defined(STATIC_MODULES) && defined(HAVE_DLFCN_H)
#include <dlfcn.h>
#endif

#include "ircd_handler.h"
#include "msg.h"

struct module
{
  char *name;
  const char *version;
  void (* modinit) (void);
  void (* modremove) (void);
  void *handle;
  void *address;
  int core;
  dlink_node node;
};

#define INIT_MODULE(NAME, REV) \
  static void _modinit(void); \
  static void _moddeinit(void); \
  struct module NAME ## _module = {#NAME, REV, _modinit, _moddeinit}; \
  static void _modinit(void)

#define CLEANUP_MODULE \
  static void _moddeinit(void)

struct module_path
{
  dlink_node node;
  char path[PATH_MAX + 1];
};

void modules_init(void);

/* add a path */
EXTERN void mod_add_path(const char *);
EXTERN void mod_clear_paths(void);

/* load all modules */
EXTERN void load_all_modules(int);

/* load core modules */
EXTERN void load_core_modules(int);

/* Add this module to list of modules to be loaded from conf */
EXTERN void add_conf_module(const char *);
/* load all modules listed in conf */
EXTERN void load_conf_modules(void);

EXTERN int unload_one_module(char *, int);
EXTERN int load_one_module(char *, int);
EXTERN int load_a_module(char *, int, int);
EXTERN dlink_node *findmodule_byname(const char *);

#endif /* INCLUDED_modules_h */
