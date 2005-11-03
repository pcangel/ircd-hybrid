/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  logging.c: Defines the logging{} block of ircd.conf.
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

#include "stdinc.h"
#include "conf/conf.h"
#include "ircd.h"

static dlink_node *hreset, *hverify;

/*
 * reset_logging()
 *
 * Sets up default values before a rehash.
 *
 * inputs: none
 * output: none
 */
static void *
reset_logging(va_list args)
{
  set_log_level(L_NOTICE);

  Logging.use_logging = YES;
  Logging.operlog[0] = Logging.userlog[0] = Logging.klinelog[0] =
    Logging.glinelog[0] = Logging.killlog[0] = Logging.operspylog[0] =
    Logging.ioerrlog[0] = Logging.failed_operlog[0] = 0;

  return pass_callback(hreset);
}

/*
 * verify_logging()
 *
 * Reopens log files.
 *
 * inputs: none
 * output: none
 */
static void *
verify_logging(va_list args)
{
  if (Logging.use_logging)
    reopen_log(logFileName);

  return pass_callback(hverify);
}

static void
set_log_path(void *value, void *where)
{
  strlcpy((char *) where, (const char *) value, PATH_MAX + 1);
}

static void
conf_log_level(void *list, void *unused)
{
  int i;
  char *value;
  struct { char *name; int level; } levels[7] = {
    {"L_CRIT", L_CRIT},
    {"L_ERROR", L_ERROR},
    {"L_WARN", L_WARN},
    {"L_NOTICE", L_NOTICE},
    {"L_TRACE", L_TRACE},
    {"L_INFO", L_INFO},
    {"L_DEBUG", L_DEBUG}
  };

  if (dlink_list_length((dlink_list *) list) != 1)
  {
    error:
    parse_error("value should be yes/no/masked");
    return;
  }

  value = (char *) ((dlink_list *) list)->head->data;

  for (i = 0; i < 7; i++)
    if (!irccmp(value, levels[i].name))
    {
      set_log_level(levels[i].level);
      return;
    }

  goto error;
}

/*
 * init_logging()
 *
 * Defines the logging{} conf section.
 *
 * inputs: none
 * output: none
 */
void
init_logging(void)
{
  char *names[2] = {"logging", "log"};
  char *short_fields[] =
    {"fuserlog", "foperlog", "fkilllog", "fklinelog", "fglinelog",
     "fioerrlog"};
  char *long_fields[] =
    {"fname_userlog", "fname_operlog", "fname_killlog", "fname_klinelog",
     "fname_glinelog", "fname_ioerrlog"};
  char *paths[] =
    {Logging.userlog, Logging.operlog, Logging.killlog, Logging.klinelog,
     Logging.glinelog, Logging.ioerrlog};
  int i, j;

  hreset = install_hook(reset_conf, reset_logging);
  hverify = install_hook(verify_conf, verify_logging);

  for (i = 0; i < 2; i++)
  {
    struct ConfSection *s = add_conf_section(names[i], 2);

    add_conf_field(s, "use_logging", CT_BOOL, NULL, &Logging.use_logging);
    add_conf_field(s, "logpath", CT_STRING, NULL, NULL);

    for (j = 0; j < 5; j++)
    {
      add_conf_field(s, short_fields[j], CT_STRING, set_log_path, paths[j]);
      add_conf_field(s, long_fields[j], CT_STRING, set_log_path, paths[j]);
    }

    add_conf_field(s, "log_level", CT_LIST, conf_log_level, NULL);
  }
}
