/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  parse.c: Low level ircd.conf handling.
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

#include "stdinc.h"
#include "conf/conf.h"
#include "modern.h"
#include "client.h"
#include "ircd.h"
#include "restart.h"
#include "send.h"

struct ConfParserContext conf_curctx;
char conf_linebuf[CONF_BUFSIZE];

/*
 * parse_error()
 *
 * Log a parse error message.
 *
 * inputs:
 *   fmt  -  error message format
 * output: none
 */
static void
do_parse_error(int fatal, const char *fmt, va_list args)
{
  char *newbuf = stripws(conf_linebuf);
  char msg[CONF_BUFSIZE];

  vsnprintf(msg, sizeof(msg), fmt, args);

  if (conf_pass != 0)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, "\"%s\", line %u: %s: %s",
      conf_curctx.filename, conf_curctx.lineno+1, msg, newbuf);
    ilog(fatal ? L_CRIT : L_WARN, "\"%s\", line %u: %s: %s",
      conf_curctx.filename, conf_curctx.lineno+1, msg, newbuf);
  }
  else
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, "Conf %s: %s",
                         fatal ? "FATAL" : "ERROR", msg);
    ilog(fatal ? L_CRIT : L_WARN, "Conf %s: %s",
         fatal ? "FATAL" : "ERROR", msg);
  }
}

void
parse_error(const char *fmt, ...)
{
  va_list args;

  va_start(args, fmt);
  do_parse_error(NO, fmt, args);
  va_end(args);
}

void
parse_fatal(const char *fmt, ...)
{
  va_list args;

  va_start(args, fmt);
  do_parse_error(YES, fmt, args);
  va_end(args);

  server_die("misconfigured server", NO);
}

/*
 * yyerror()
 *
 * Log a parse error message if the current pass is 2.
 *
 * inputs:
 *   msg  -  error message
 * output: none
 */
void
yyerror(const char *msg)
{
  if (conf_pass == 2)
    parse_error("%s", msg);
}

/*
 * conf_yy_input()
 *
 * Loads a block of data from the conf file.
 *
 * inputs:
 *   buf  -  address of destination buffer
 *   siz  -  size of the buffer
 * output: number of bytes actually read
 */
int
conf_yy_input(char *buf, int siz)
{
  return fbgets(buf, siz, conf_curctx.f) == NULL ? 0 : strlen(buf);
}

/*
 * read_conf_files()
 *
 * Initializes ircd.conf parsing.
 *
 * inputs: YES on bootup, NO on rehash
 * output: none
 */
void
read_conf_files(int cold)
{
  conf_curctx.f = fbopen(ServerState.configfile, "r");
  if (!conf_curctx.f)
  {
    parse_error("Cannot open %s", ServerState.configfile);
    return;
  }

  conf_cold = cold;
  execute_callback(reset_conf);

  conf_pass = 1;
  conf_curctx.filename = ServerState.configfile;
  conf_curctx.lineno = 0;
  conf_linebuf[0] = 0;
  yyparse();

  conf_pass = 2;
  execute_callback(switch_conf_pass);
  fbrewind(conf_curctx.f);
  conf_curctx.lineno = 0;
  conf_linebuf[0] = 0;
  yyparse();

  execute_callback(verify_conf);
  conf_pass = 0;
}
