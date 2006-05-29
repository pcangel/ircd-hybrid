/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  recode.c: Adds codepage option to listen{} blocks.
 *
 *  Copyright (C) 2006 by the past and present ircd coders, and others.
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
 *  $Id: $
 */

#include <iconv.h>
#include "stdinc.h"
#include "client.h"
#include "listener.h"
#include "packet.h"
#include "send.h"
#include "conf/conf.h"

struct Conversion
{
  unsigned short port;
  char first;
  iconv_t to_utf8;
  iconv_t from_utf8;
  struct Conversion *hnext;
};

/*
 * Hashing doesn't affect performance here, as we are almost guaranteed
 * to have at most 1 entry per bucket.  Using 65536 as CONVSIZE would just
 * be a waste of 1 MB on 64-bit.
 */

#define CONVSIZE 1024

static struct Conversion *convtab[CONVSIZE];
static dlink_node *hreset, *hiorecv, *hiosend;
static struct ConfSection *section;
static struct ConfField *codepage;
static char *last_codepage = NULL;
static struct ConfField *port;
static CONFF_HANDLER *old_port_handler;

/*
 * free_convtab()
 *
 * Deletes all used recode entries and clears the TCP port hash table.
 *
 * inputs: none
 * output: none
 */
static void
free_convtab(void)
{
  int i;
  struct Conversion *p;

  for (i = 0; i < CONVSIZE; i++)
    while ((p = convtab[i]) != NULL)
    {
      if (p->first)
      {
        iconv_close(p->to_utf8);
        iconv_close(p->from_utf8);
      }

      convtab[i] = p->hnext;
      MyFree(p);
    }
}

/*
 * reset_convtab()
 *
 * Wrapper around free_convtab(), used as reset_conf handler.
 *
 * inputs: none
 * output: none
 */
static void *
reset_convtab(va_list args)
{
  free_convtab();

  return pass_callback(hreset);
}

/*
 * my_port_handler()
 *
 * Overrides default port= handler, adding a conversion if requested.
 *
 * inputs:
 *   list  -  pointer to dlink_list of longs
 *   var   -  where to write it
 * output: none
 */
static void
my_port_handler(void *list, void *var)
{
  if (last_codepage != NULL)
  {
    dlink_node *ptr;
    iconv_t to_utf8 = iconv_open("UTF-8", last_codepage);
    iconv_t from_utf8 = iconv_open(last_codepage, "UTF-8");

    if (to_utf8 == (iconv_t) -1 || from_utf8 == (iconv_t) -1)
    {
      parse_error("Unable to open character set [%s]: %s",
        last_codepage, strerror(errno));

      if (to_utf8 != (iconv_t) -1)
        iconv_close(to_utf8);
      if (from_utf8 != (iconv_t) -1)
        iconv_close(from_utf8);
    }
    else
    {
      char first = YES;

      DLINK_FOREACH(ptr, ((dlink_list *) list)->head)
      {
        unsigned short port = (unsigned short) (long) ptr->data;
        struct Conversion *conv = MyMalloc(sizeof(struct Conversion));

        conv->port = port;
        conv->first = first;
        conv->to_utf8 = to_utf8;
        conv->from_utf8 = from_utf8;
        conv->hnext = convtab[port % CONVSIZE];

        convtab[port % CONVSIZE] = conv;
        first = NO;
      }
    }

    MyFree(last_codepage);
    last_codepage = NULL;
  }

  old_port_handler(list, port);
}

/*
 * my_iorecv()
 *
 * Called when data is received from the network.
 *
 * inputs:
 *   client_p  -  the client we get input from
 *   length    -  amound of data read
 *   buf       -  data buffer
 * output: none
 */
static void *
my_iorecv(va_list args)
{
  struct Client *client_p = va_arg(args, struct Client *);
  size_t inlen = va_arg(args, int);
  const char *inbuf = va_arg(args, char *);
  unsigned short port = client_p->localClient->listener->port;
  struct Conversion *conv;

  for (conv = convtab[port % CONVSIZE]; conv != NULL; conv = conv->hnext)
    if (conv->port == port)
    {
      char transbuf[2 * READBUF_SIZE];
      size_t outlen = sizeof(transbuf);
      char *outbuf = transbuf;

      iconv(conv->to_utf8, NULL, NULL, NULL, NULL);
      iconv(conv->to_utf8, &inbuf, &inlen, &outbuf, &outlen);

      inlen = outbuf - transbuf;
      inbuf = transbuf;
    }

  return pass_callback(hiorecv, client_p, inlen, inbuf);
}

/*
 * my_iosend()
 *
 * Called when data is to be sent over the network.
 *
 * inputs:
 *   client_p  -  the client we write to
 *   length    -  amount of output data
 *   buf       -  data buffer
 * output: none
 */
static void *
my_iosend(va_list args)
{
  struct Client *client_p = va_arg(args, struct Client *);
  size_t inlen = va_arg(args, int);
  const char *inbuf = va_arg(args, char *);
  unsigned short port = client_p->localClient->listener->port;
  struct Conversion *conv;

  for (conv = convtab[port % CONVSIZE]; conv != NULL; conv = conv->hnext)
    if (conv->port == port)
    {
      char transbuf[2 * IRCD_BUFSIZE];
      size_t outlen = sizeof(transbuf);
      char *outbuf = transbuf;

      iconv(conv->from_utf8, NULL, NULL, NULL, NULL);
      iconv(conv->from_utf8, &inbuf, &inlen, &outbuf, &outlen);

      inlen = outbuf - transbuf;
      inbuf = transbuf;
    }

  return pass_callback(hiosend, client_p, inlen, inbuf);
}

/*
 * Module entry point.
 */
INIT_MODULE(recode, "$Revision: $")
{
  memset(&convtab, 0, sizeof(convtab));

  hreset = install_hook(reset_conf, reset_convtab);

  section = find_conf_section("listen");
  codepage = add_conf_field(section, "codepage", CT_STRING, NULL,
    &last_codepage);

  port = find_conf_field(section, "port");
  old_port_handler = port->handler;
  port->handler = my_port_handler;

  hiorecv = install_hook(iorecv_cb, my_iorecv);
  hiosend = install_hook(iosend_cb, my_iosend);
}

/*
 * Module uninstaller.
 */
CLEANUP_MODULE
{
  uninstall_hook(iorecv_cb, my_iorecv);
  uninstall_hook(iosend_cb, my_iosend);

  port->handler = old_port_handler;

  delete_conf_field(section, codepage);

  uninstall_hook(reset_conf, reset_convtab);

  free_convtab();
}
