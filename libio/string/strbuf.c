/*
 * strbuf.c: A dynamic string creation gadget
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

#include "strbuf.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

/* Cute little utility. What's it do?
 *
 * The idea is to have an "appendable, auto-flush" string buffer for stuff
 * like /NAMES. First, you add a 'header', then you mark that spot in the
 * buffer as the place to rewind to in case of overflow, and start adding
 * data. For an IRCD_BUFSIZE of 50, here's how the process of adding and
 * auto-flushing looks like:
 *                   here's the mark: v        EOB: |
 * :someserver.some.net REPLY #param :
 * :someserver.some.net REPLY #param :blah
 * :someserver.some.net REPLY #param :blah foobar
 * :someserver.some.net REPLY #param :blah foobar frobnicate
 * [ flushing ":someserver.some.net REPLY #param :blah foobar" ]
 * :someserver.some.net REPLY #param :frobnicate
 */

static void do_flush(struct strbuf *);

/* Should be called for initialization before using a buffer.
 * buf_init
 *
 * inputs       - pointer to the buffer
 *              - callback function to call whenever the buffer is flushed
 *  		- param to be passed to callback
 * Output	- none
 * Side effects	-
 */
void
buf_init(struct strbuf *buf, buf_callback callback, void *cb_param)
{
  buf->pos = buf->mark = 0;
  buf->callback = callback;
  buf->cb_param = cb_param;
  buf->separator = NULL;
  buf->sep_len = 0;
}

/* 
 * buf_mark
 *
 * Inputs	- pointer to struct strbuf
 * Output	- none
 * Side effects	- Marks the current position in a buffer as the place
 * 		  where flushes will rewind to
 */
void
buf_mark(struct strbuf *buf)
{
  buf->mark = buf->pos;
}

/*
 * Inputs	- pointer to struct strbuf
 * 		- pointer to separator char
 * Output	- none
 * Side effects	- Sets a separator string  to be inserted
 * 		  automatically between two messages,
 * 		  but not before the first or after the last
 */
void
buf_set_sep(struct strbuf *buf, char *sep)
{
  buf->separator = sep;
  buf->sep_len = strlen(sep);
}

/*
 * Inputs	- pointer to struct strbuf
 * 		- pointer to separator char
 * Output	- none
 * Side effects	- Combines buf_init and buf_set_sep
 */
void
buf_init_and_set_sep(struct strbuf *buf, buf_callback callback,
		     void *cb_param, char *sep)
{
  buf_init(buf, callback, cb_param);
  buf_set_sep(buf, sep);
}

/* buf_add
 *
 * Inputs	- pointer to strbuf buf
 *		- format string to add
 * Output	- none
 * Side effects	- Appends a message to the buffer
 * Bugs		- 
 * TBD: Should we provide a cheaper version for add_buf(&b, "%s", str) ?
 */
void
buf_add(struct strbuf *buf, char *format, ...)
{
  int oldpos;        /* End of old data, in case we need to flush the buffer */
  int new_msg_start; /* Start of new data (!= oldpos if we added a separator) */
  va_list args;

  /* First, try to fit the message in */
  oldpos = buf->pos;
  /* Do we need a separator? */
  if ((buf->pos > buf->mark) && buf->separator)
  {
    strcpy(buf->buf + buf->pos, buf->separator);
    buf->pos += buf->sep_len;
  }

  new_msg_start = buf->pos;
  va_start(args, format);
  /* There will always be at least IRCD_BUFSIZE left in the buffer.
   * However, the longest line we can send out is IRCD_BUFSIZE - 2.
   * Also, we need to respect the prefix (mark) that we put in front of
   * every message. Easier to cut the message off here instead of dealing
   * with "overly long" messages later...
   * Note that vsnprintf counts the trailing \0. We don't. thus -1, not -2
   */
  buf->pos += vsnprintf(buf->buf + buf->pos, IRCD_BUFSIZE - 1 - buf->mark,
                        format, args);
  va_end(args);

  if (buf->pos > IRCD_BUFSIZE - 2)
  { /* oops, we 'overflowed' the buffer, flush the old data,
     * shift the new one in place... */
    char swap = buf->buf[oldpos];
    int new_msg_length = buf->pos - new_msg_start;
    buf->buf[oldpos] = '\0';

    do_flush(buf);

    /* Now, move the new data back to the beginning of the buffer */
    buf->buf[oldpos] = swap;
    memmove(buf->buf + buf->mark, buf->buf + new_msg_start, new_msg_length);
    buf->pos = buf->mark + new_msg_length;
  }
}

/*
 * do_flush internal
 *
 * Inputs	- pointer to struct strbuf
 * Output	- none
 * Side effects	- flushes to output anything left in buffer
 */
static void
do_flush(struct strbuf *buf)
{
  buf->callback(buf->buf, buf->cb_param);
}

/*
 * buf_flush user callable
 *
 * Inputs	- pointer to struct strbuf
 * Output	- none
 * Side effects	- Flushes a buffer: 
 * 		  call the callback, and rewind to last mark 
 */
void
buf_flush(struct strbuf *buf)
{
  if (buf->pos == buf->mark)
    return; /* No data, nothing to do */

  /* make sure we have a terminating '\0' */
  buf->buf[ buf->pos ] = '\0';

  do_flush(buf);

  /* rewind to last mark */
  buf->pos = buf->mark;
}
