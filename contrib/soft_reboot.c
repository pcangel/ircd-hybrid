/************************************************************************
 *   IRC - Internet Relay Chat, contrib/soft_reboot.c
 *   Copyright (C) 2006 Hybrid Development Team
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 1, or (at your option)
 *   any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *   $Id$
 */

#include "stdinc.h"
#include "conf/conf.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "hash.h"
#include "ircd.h"
#include "ircd_defs.h"
#include "listener.h"
#include "numeric.h"
#include "packet.h"
#include "parse.h"
#include "restart.h"
#include "s_serv.h"
#include "s_user.h"
#include "send.h"

static dlink_node *h_shutdown, *h_verify;

struct SocketInfo
{
  int fd;
  int namelen;
  int caplen;
  int recvqlen;
  int sendqlen;
};

/*
 * make_dummy()
 *
 * Prepares a dummy server-alike local client.
 *
 * inputs: file descriptor to use
 * output: client pointer
 */
static struct Client *
make_dummy(int transfd)
{
  dlink_node *m;
  struct Client *client_p = make_client(NULL);

  fd_open(&client_p->localClient->fd, transfd, 1, "Softboot");
  client_p->localClient->caps = -1;

  strcpy(client_p->name, ".");
  strcpy(client_p->id, "...");
  dlinkAdd(client_p, &client_p->node, &global_client_list);

  m = dlinkFind(&unknown_list, client_p);
  dlinkDelete(m, &unknown_list);
  dlinkAdd(client_p, m, &serv_list);
  dlinkAdd(client_p, make_dlink_node(), &global_serv_list);

  make_server(client_p);
  SetServer(client_p);

  return client_p;
}

/*
 * write_dbuf()
 *
 * Writes the contents of a dbuf to the given socket.
 *
 * inputs:
 *   transfd  -  where to write to
 *   dbuf     -  dbuf pointer
 * output: none
 */
static void
write_dbuf(int transfd, struct dbuf_queue *dbuf)
{
  while (dbuf_length(dbuf) > 0)
  {
    struct dbuf_block *first = dbuf->blocks.head->data;

    write(transfd, first->data, first->size);
    dbuf_delete(dbuf, first->size);
  }
}

/*
 * introduce_socket()
 *
 * Encodes and writes socket information about the given client.
 *
 * inputs:
 *   transfd   -  where to write to
 *   client_p  -  local client to inform about
 * output: none
 */
static void
introduce_socket(int transfd, struct Client *client_p)
{
  struct SocketInfo si;
  const char *capabs = "";

  if (IsDefunct(client_p))
    return;

  if (IsServer(client_p))
    capabs = show_capabilities(client_p);

  si.fd = client_p->localClient->fd.fd;
  si.namelen = strlen(client_p->name);
  si.caplen = strlen(capabs);
  si.recvqlen = dbuf_length(&client_p->localClient->buf_recvq);
  si.sendqlen = dbuf_length(&client_p->localClient->buf_sendq);

  write(transfd, &si, sizeof(si));
  write(transfd, client_p->name, si.namelen);
  write(transfd, capabs, si.caplen);

  write_dbuf(transfd, &client_p->localClient->buf_recvq);
  write_dbuf(transfd, &client_p->localClient->buf_sendq);
}

/*
 * do_shutdown()
 *
 * Implements the /RESTART part of the soft reboot code.
 *
 * inputs:
 *   msg    -  shutdown message
 *   rboot  -  1 if it's a restart, 0 if plain exit
 * output: none
 */
static void *
do_shutdown(va_list args)
{
  const char *msg = va_arg(args, const char *);
  int rboot = va_arg(args, int);
  struct Client *client_p;
  dlink_node *ptr;
  int transfd[2];

  if (!rboot || socketpair(AF_UNIX, SOCK_STREAM, 0, transfd) < 0)
    return pass_callback(h_shutdown, msg, rboot);

  if (EmptyString(msg))
  {
    ilog(L_CRIT, "Server Soft-Rebooting");
    sendto_realops_flags(UMODE_ALL, L_ALL, "Server Soft-Rebooting");
  }
  else
  {
    ilog(L_CRIT, "Server Soft-Rebooting: %s", msg);
    sendto_realops_flags(UMODE_ALL, L_ALL, "Server Soft-Rebooting: %s", msg);
  }

  //
  // Prevent all sockets which belong to registered users/servers from
  // being closed on exec().
  //
  fcntl(transfd[0], F_SETFD, 0);

  DLINK_FOREACH(ptr, local_client_list.head)
  {
    client_p = ptr->data;
    if (!IsDefunct(client_p))
    {
      fcntl(client_p->localClient->fd.fd, F_SETFD, 0);
      if (client_p->localClient->list_task != NULL)
        sendto_one(client_p, form_str(RPL_LISTEND), me.name, client_p->name);
    }
  }

  DLINK_FOREACH(ptr, serv_list.head)
  {
    client_p = ptr->data;
    if (!IsDefunct(client_p))
      fcntl(client_p->localClient->fd.fd, F_SETFD, 0);
  }

  //
  // Start the new ircd.
  //
  switch (fork())
  {
    case -1:
      ilog(L_CRIT, "Unable to fork(): %s", strerror(errno));
      exit(1);

    case 0:
    {
      int i;
      char **argv, buf[24];

      snprintf(buf, sizeof(buf), "softboot_%d", transfd[0]);

      for (i = 0; myargv[i] != NULL; i++);
      argv = MyMalloc((i + 2) * sizeof(char *));

      for (i = 0; myargv[i] != NULL; i++)
        argv[i] = myargv[i];
      argv[i++] = buf;
      argv[i] = NULL;

      execv(SPATH, argv);
      ilog(L_CRIT, "Unable to execve(): %s", strerror(errno));
      exit(1);
    }
  }

  //
  // Pass our data.
  //
  burst_all(make_dummy(transfd[1]));

  write(transfd[1], "\001\r\n", 3);

  DLINK_FOREACH(ptr, local_client_list.head)
    introduce_socket(transfd[1], ptr->data);

  DLINK_FOREACH(ptr, serv_list.head)
    introduce_socket(transfd[1], ptr->data);

  exit(0);
}

/*
 * restore_socket()
 *
 * Restores socket related fields in struct LocalUser.
 *
 * inputs:
 *   client_p  -  client pointer
 *   fd        -  file descriptor
 * output: the same pointer or NULL if exited
 */
static struct Client *
restore_socket(struct Client *client_p, int fd)
{
  char buf[HOSTLEN+10];
  struct irc_ssaddr addr;
  int family, port;

  snprintf(buf, sizeof(buf), IsServer(client_p) ? "Server: %s" : "Nick: %s",
           client_p->name);

  client_p->localClient = BlockHeapAlloc(lclient_heap);
  fd_open(&client_p->localClient->fd, fd, 1, buf);

  addr.ss_len = sizeof(addr);
  getsockname(fd, (struct sockaddr *) &addr, &addr.ss_len);
  family = addr.ss.sin_family;
  port = ntohs(addr.ss.sin_port);

  if (!(client_p->localClient->listener = find_listener(port, &addr)))
  {
    memset(&addr.ss, 0, sizeof(addr.ss));
    addr.ss.sin_family = family;
    addr.ss.sin_port = htons(port);

    if (!(client_p->localClient->listener = find_listener(port, &addr)))
    {
      exit_client(client_p, &me, "Listener closed");
      return NULL;
    }
  }

  client_p->localClient->ip.ss_len = sizeof(client_p->localClient->ip.ss);
  getpeername(fd, (struct sockaddr *) &client_p->localClient->ip,
              &client_p->localClient->ip.ss_len);
  client_p->localClient->aftype = client_p->localClient->ip.ss.sin_family;

  if (irc_getnameinfo((struct sockaddr *) &client_p->localClient->ip,
                      client_p->localClient->ip.ss_len, client_p->sockhost,
                      sizeof(client_p->sockhost), NULL, 0,
                      NI_NUMERICHOST) != 0)
  {
    exit_client(client_p, &me, "Protocol family no longer supported");
    return NULL;
  }

  return client_p;
}

/*
 * restore_client()
 * restore_server()
 *
 * Restores a local user/server entity.
 *
 * inputs:
 *   client_p  -  client pointer
 *   capabs    -  user/server capab string
 * output: the same pointer or NULL if exited
 */
static struct Client *
restore_client(struct Client *client_p, char *capabs)
{
  char userbuf[USERLEN+1];
  struct Class *cptr;

  if (client_p->username[0] != '~')
    SetGotId(client_p);
  strlcpy(userbuf, client_p->username + !IsGotId(client_p),
          sizeof(userbuf));

  if (!(cptr = execute_callback(authorize_client, client_p, userbuf)))
    return NULL;
  attach_class(client_p, cptr);

  Count.local++, Count.totalrestartcount++;
  if (Count.local > Count.max_loc)
    Count.max_loc = Count.local;

  dlinkAdd(client_p, &client_p->localClient->lclient_node, &local_client_list);
  dlinkAdd(client_p, &client_p->lnode, &me.serv->client_list);
  return client_p;
}

static struct Client *
restore_server(struct Client *client_p, char *capabs)
{
  char *p = NULL, *s = NULL;
  int cap;

  SetGotId(client_p);

  for (s = strtoken(&p, capabs, " "); s; s = strtoken(&p, NULL, " "))
    if ((cap = find_capability(s)) != 0)
      SetCapable(client_p, cap);

  set_chcap_usage_counts(client_p);
  Count.myserver++;

  dlinkAdd(client_p, &client_p->localClient->lclient_node, &serv_list);
  dlinkAdd(client_p, &client_p->lnode, &me.serv->server_list);
  return client_p;
}

/*
 * restore_dbuf()
 *
 * Loads a dbuf contents from a file stream.
 *
 * inputs:
 *   f     -  file stream
 *   dbuf  -  dbuf to fill or NULL
 *   cnt   -  number of bytes to read
 * output: none
 */
static void
restore_dbuf(FILE *f, struct dbuf_queue *dbuf, int cnt)
{
  while (cnt > 0)
  {
    int nread = fread(readBuf, 1, sizeof(readBuf), f);

    dbuf_put(dbuf, readBuf, nread);
    cnt -= nread;
  }
}

/*
 * load_state()
 *
 * Loads ircd state from a socket stream.
 *
 * inputs: socket fd
 * output: none
 */
static void
load_state(int transfd)
{
  FILE *f = fdopen(transfd, "r");
  char buf[IRCD_BUFSIZE+1], *p;
  struct Client *dummy = make_dummy(transfd);
  struct Client *client_p;
  struct SocketInfo si;

  while (fgets(buf, sizeof(buf), f))
  {
    if ((p = strpbrk(buf, "\r\n")) != NULL)
      *p = 0;
    if (buf[0] == '\001')
      break;
    parse(dummy, buf, buf + strlen(buf));
  }

  SetDead(dummy);

  while (fread(&si, sizeof(si), 1, f) == 1)
  {
    assert(si.namelen < IRCD_BUFSIZE);
    assert(si.caplen < IRCD_BUFSIZE);

    fread(buf, 1, si.namelen, f);
    buf[si.namelen] = 0;

    if ((client_p = find_client(buf)) != NULL)
    {
      client_p->servptr = &me;
      client_p->from = client_p;
      client_p = restore_socket(client_p, si.fd);
    }

    fread(buf, 1, si.caplen, f);
    buf[si.caplen] = 0;

    if (client_p != NULL)
      client_p = (IsServer(client_p) ? restore_server : restore_client)
        (client_p, buf);

    restore_dbuf(f, client_p ? &client_p->localClient->buf_recvq : NULL,
                 si.recvqlen);
    restore_dbuf(f, client_p ? &client_p->localClient->buf_sendq : NULL,
                 si.sendqlen);
  }

  exit_one_client(dummy, "Soft reboot");
  fclose(f);
}

/*
 * do_verify_conf()
 *
 * Handles the conf verification callback.
 *
 * inputs: none
 * output: none
 */
static void *
do_verify_conf(va_list args)
{
  pass_callback(h_verify);

  if (conf_cold)
  {
    int i;

    for (i = 0; myargv[i] != NULL; i++)
      if (!ircncmp(myargv[i], "softboot_", 9))
      {
        load_state(atoi(myargv[i] + 9));
        myargv[i] = NULL;
      }
  }

  return NULL;
}

INIT_MODULE(soft_reboot, "$Revision$")
{
  h_shutdown = install_hook(ircd_shutdown, do_shutdown);
  h_verify = install_hook(verify_conf, do_verify_conf);
}

CLEANUP_MODULE
{
  uninstall_hook(verify_conf, do_verify_conf);
  uninstall_hook(ircd_shutdown, do_shutdown);
}
