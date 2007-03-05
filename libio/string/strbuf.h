/*
 * strbuf.h: A dynamic string creation gadget
 *
 * Original version 2007 by Karsten Behrmann,
 * various modifications by the past and present ircd coders, and others.
 *
 * I wrote this code because it seemed like a nice idea at the time.
 * Feel free to do whatever you feel like with this stuff, just don't
 * claim you wrote it. If you really need to release this under the GPLv2,
 * you can do so.
 *
 * Now have fun, and leave the lawyers in the dog pen, next to the politicians.
 */

#include "../include/ircd_defs.h"

typedef void (*buf_callback)(char *, void *);

struct strbuf {
  /* Enough space for our buffer, and for an 'overflow' of data. */
  char buf[IRCD_BUFSIZE*2];
  char *separator;
  int sep_len;
  int mark, pos;
  buf_callback callback;
  void *cb_param;
};

void buf_init(struct strbuf *, buf_callback, void *);
void buf_mark(struct strbuf *);
void buf_set_sep(struct strbuf *, char *);
void buf_add(struct strbuf *, char *, ...);
void buf_flush(struct strbuf *);
void buf_init_and_set_sep(struct strbuf *buf, buf_callback callback,
			  void *cb_param, char *sep);
