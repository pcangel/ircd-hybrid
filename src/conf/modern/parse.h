/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  parse.h: ircd.conf low level parsing.
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

#define CONF_BUFSIZE 512

struct ConfParserContext {
  FBFILE *f;
  char *filename;
  int lineno;
};

EXTERN struct ConfParserContext conf_curctx;
EXTERN char conf_linebuf[];
EXTERN int conf_include_sptr;

EXTERN int conf_yy_input(char *, int);
EXTERN void yyerror(const char *);
EXTERN int yyparse(void);
EXTERN int yylex(void);
