/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  user.c: User related functions.
 *
 *  Copyright (C) 2002-2006 by the past and present ircd coders, and others.
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
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "common.h"
#include "hash.h"
#include "ircd.h"
#include "listener.h"
#include "motd.h"
#include "numeric.h"
#include "user.h"
#include "server.h"
#include "send.h"
#include "whowas.h"
#include "packet.h"
#include "userhost.h"
#include "msg.h"
#include "watch.h"

int MaxClientCount     = 1;
int MaxConnectionCount = 1;
struct Callback *entering_umode_cb = NULL;
struct Callback *umode_cb = NULL;
struct Callback *authorize_client = NULL;
struct Callback *uid_get = NULL;

static char umode_buffer[IRCD_BUFSIZE];

static void user_welcome(struct Client *);
static void introduce_client(struct Client *, struct Client *);

/* Used for building up the isupport string,
 * used with init_isupport, add_isupport, delete_isupport
 */
struct Isupport 
{
  dlink_node node;
  char *name;
  char *options;
  int number;
};

static dlink_list support_list = { NULL, NULL, 0 };
MessageFile *isupportFile;

/* memory is cheap. map 0-255 to equivalent mode */
unsigned int user_modes[256] =
{
  /* 0x00 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* 0x0F */
  /* 0x10 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* 0x1F */
  /* 0x20 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* 0x2F */
  /* 0x30 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* 0x3F */
  0,                  /* @ */
  0,                  /* A */
  0,                  /* B */
  0,                  /* C */
  UMODE_DEAF,         /* D */
  0,                  /* E */
  0,                  /* F */
  UMODE_SOFTCALLERID, /* G */
  0,                  /* H */
  0,                  /* I */
  0,                  /* J */
  0,                  /* K */
  0,                  /* L */
  0,                  /* M */
  0,                  /* N */
  0,                  /* O */
  0,                  /* P */
  0,                  /* Q */
  0,                  /* R */
  0,                  /* S */
  0,                  /* T */
  0,                  /* U */
  0,                  /* V */
  0,                  /* W */
  0,                  /* X */
  0,                  /* Y */
  0,                  /* Z 0x5A */
  0, 0, 0, 0, 0,      /* 0x5F   */ 
  0,                  /* 0x60   */
  UMODE_ADMIN,        /* a */
  UMODE_BOTS,         /* b */
  UMODE_CCONN,        /* c */
  UMODE_DEBUG,        /* d */
  0,                  /* e */
  UMODE_FULL,         /* f */
  UMODE_CALLERID,     /* g */
  0,                  /* h */
  UMODE_INVISIBLE,    /* i */
  0,                  /* j */
  UMODE_SKILL,        /* k */
  UMODE_LOCOPS,       /* l */
  0,                  /* m */
  UMODE_NCHANGE,      /* n */
  UMODE_OPER,         /* o */
  0,                  /* p */
  0,                  /* q */
  UMODE_REJ,          /* r */
  UMODE_SERVNOTICE,   /* s */
  0,                  /* t */
  UMODE_UNAUTH,       /* u */
  0,                  /* v */
  UMODE_WALLOP,       /* w */
  UMODE_EXTERNAL,     /* x */
  UMODE_SPY,          /* y */
  UMODE_OPERWALL,     /* z      0x7A */
  0,0,0,0,0,          /* 0x7B - 0x7F */

  /* 0x80 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* 0x8F */
  /* 0x90 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* 0x9F */
  /* 0xA0 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* 0xAF */
  /* 0xB0 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* 0xBF */
  /* 0xC0 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* 0xCF */
  /* 0xD0 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* 0xDF */
  /* 0xE0 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* 0xEF */
  /* 0xF0 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0  /* 0xFF */
};

void
assemble_umode_buffer(void)
{
  unsigned int idx = 0;
  char *umode_buffer_ptr = umode_buffer;

  for (; idx < (sizeof(user_modes) / sizeof(int)); ++idx)
    if (user_modes[idx])
      *umode_buffer_ptr++ = idx;

  *umode_buffer_ptr = '\0';
}

/* show_lusers()
 *
 * inputs       - pointer to client
 * output       - NONE
 * side effects - display to client user counts etc.
 */
void
show_lusers(struct Client *source_p) 
{
  const char *from, *to;

  if (!MyConnect(source_p) && IsCapable(source_p->from, CAP_TS6) &&
      HasID(source_p))
  {
    from = me.id;
    to = source_p->id;
  }
  else
  {
    from = me.name;
    to = source_p->name;
  }

  if (!ServerHide.hide_servers || IsOper(source_p))
    sendto_one(source_p, form_str(RPL_LUSERCLIENT),
               from, to, (Count.total-Count.invisi),
               Count.invisi, dlink_list_length(&global_serv_list));
  else
    sendto_one(source_p, form_str(RPL_LUSERCLIENT), from, to,
               (Count.total-Count.invisi), Count.invisi, 1);

  if (Count.oper > 0)
    sendto_one(source_p, form_str(RPL_LUSEROP),
               from, to, Count.oper);

  if (dlink_list_length(&unknown_list) > 0)
    sendto_one(source_p, form_str(RPL_LUSERUNKNOWN),
               from, to, dlink_list_length(&unknown_list));

  if (dlink_list_length(&global_channel_list) > 0)
    sendto_one(source_p, form_str(RPL_LUSERCHANNELS),
               from, to, dlink_list_length(&global_channel_list));

  if (!ServerHide.hide_servers || IsOper(source_p))
  {
    sendto_one(source_p, form_str(RPL_LUSERME),
               from, to, Count.local, Count.myserver);
    sendto_one(source_p, form_str(RPL_LOCALUSERS),
               from, to, Count.local, Count.max_loc,
               Count.local, Count.max_loc);
  }
  else
  {
    sendto_one(source_p, form_str(RPL_LUSERME),
               from, to, Count.total, 0);
    sendto_one(source_p, form_str(RPL_LOCALUSERS), 
               from, to, Count.total, Count.max_tot,
               Count.total, Count.max_tot);
  }

  sendto_one(source_p, form_str(RPL_GLOBALUSERS),
             from, to, Count.total, Count.max_tot,
             Count.total, Count.max_tot);

  if (!ServerHide.hide_servers || IsOper(source_p))
    sendto_one(source_p, form_str(RPL_STATSCONN), from, to,
               MaxConnectionCount, MaxClientCount, Count.totalrestartcount);

  if (Count.local > MaxClientCount)
    MaxClientCount = Count.local;

  if ((Count.local + Count.myserver) > MaxConnectionCount)
    MaxConnectionCount = Count.local + Count.myserver; 
}

/*
 * reject_user()
 *
 * Performs a fast or delayed disconnect and updates statistics.
 *
 * inputs:
 *   source_p  -  the client we're disconnecting
 *   reason    -  exit reason
 *   delay     -  whether delaying user's exit makes any sense
 * output: always NULL
 */
void *
reject_user(struct Client *source_p, const char *reason, int delay)
{
  /* XXX It is problematical whether it is better to use the
   * capture reject code here or rely on the connecting too fast code.
   * - Dianora
   */
  if (delay && REJECT_HOLD_TIME > 0)
  {
    source_p->localClient->reject_delay = CurrentTime + REJECT_HOLD_TIME;
    SetCaptured(source_p);
  }
  else
    exit_client(source_p, &me, reason);

  ++ServerStats.is_ref;
  return NULL;
}

/*
 * do_authorize_client()
 *
 * Performs an access check on an incoming local user.
 *
 * inputs:
 *   client_p  -  client pointer
 *   username  -  new username
 * output: class pointer if authorized, NULL if client has exited
 */
void *
do_authorize_client(va_list args)
{
  struct Client *source_p = va_arg(args, struct Client *);
  const char *username = va_arg(args, const char *);
  char userbuf[USERLEN + 1];
  struct AuthConf *conf;
  char *type, *reason;

  snprintf(userbuf, sizeof(userbuf), "%s%s",
    IsGotId(source_p) ? "" : "~", username);
  conf = find_iline(userbuf, source_p->host, &source_p->localClient->ip,
    source_p->localClient->passwd);

  if (conf && (conf->redirserv || conf->redirport))
  {
    sendto_one(source_p, form_str(RPL_REDIR), me.name, source_p->name,
               conf->redirserv ? conf->redirserv : "*",
               conf->redirport ? conf->redirport :
               source_p->localClient->listener->port);
    conf = NULL;
  }

  // auth check
  if (!conf)
  {
    ilog(L_INFO, "Unauthorized client connection from %s on [%s/%u]",
      get_client_name(source_p, SHOW_IP),
      source_p->localClient->listener->name,
      source_p->localClient->listener->port);
    sendto_realops_flags(UMODE_UNAUTH, L_ALL,
      "Unauthorized client connection from %s (%s) on [%s/%u]",
      get_client_name(source_p, HIDE_IP), source_p->sockhost,
      source_p->localClient->listener->name,
      source_p->localClient->listener->port);
    sendto_one(source_p,
      ":%s NOTICE %s :You are not authorized to use this server",
      me.name, source_p->name);
    return reject_user(source_p, "Not authorized", YES);
  }

  // setup client parameters as required by is_client_banned
  strlcpy(source_p->username, (conf->flags & AUTH_FLAG_NO_TILDE) ?
    username : userbuf, sizeof(source_p->username));
  if ((conf->flags & AUTH_FLAG_EXCEED_LIMIT))
    SetExemptLimits(source_p);
  if ((conf->flags & AUTH_FLAG_KLINE_EXEMPT))
    SetExemptKline(source_p);
  if ((conf->flags & AUTH_FLAG_GLINE_EXEMPT))
    SetExemptGline(source_p);
  if ((conf->flags & AUTH_FLAG_RESV_EXEMPT))
    SetExemptResv(source_p);
  if ((conf->flags & AUTH_FLAG_EXCEED_LIMIT))
    SetExemptLimits(source_p);
  if ((conf->flags & AUTH_FLAG_CAN_IDLE))
    SetIdlelined(source_p);
  if ((conf->flags & AUTH_FLAG_CAN_FLOOD))
    SetCanFlood(source_p);

  // ban check
  if (execute_callback(is_client_banned, source_p, &type, &reason))
  {
    ilog(L_INFO, "Access denied (%s): %s",
         type, get_client_name(source_p, SHOW_IP));
    sendto_realops_flags(UMODE_REJ, L_ALL,
                         "%s Rejecting [%s], user %s (%s)",
                         type, reason, get_client_name(source_p, HIDE_IP),
                         source_p->sockhost);
    sendto_one(source_p, ":%s NOTICE %s :*** %s: %s", me.name, type,
               source_p->name, (reason && General.kline_with_reason) ?
               reason : "No reason");
    return reject_user(source_p, "Banned", YES);
  }

  // password check
  if (!EmptyString(conf->password))
    if (!match_password(source_p->localClient->passwd, conf->password,
                        conf->flags & AUTH_FLAG_ENCRYPTED))
    {
      ilog(L_INFO, "Bad password from %s", get_client_name(source_p, SHOW_IP));
      sendto_realops_flags(UMODE_UNAUTH, L_ALL,
                           "Bad password, rejecting %s (%s)",
                           get_client_name(source_p, HIDE_IP),
                           source_p->sockhost);
      sendto_one(source_p, form_str(ERR_PASSWDMISMATCH),
                 me.name, source_p->name);
      return reject_user(source_p, "Bad Password", YES);
    }

  // ident check
  if (!IsGotId(source_p) && (conf->flags & AUTH_FLAG_NEED_IDENT))
  {
    ilog(L_INFO, "No ident, rejecting %s", get_client_name(source_p, SHOW_IP));
    sendto_realops_flags(UMODE_REJ, L_ALL,
                         "No ident, rejecting %s (%s)",
                         get_client_name(source_p, HIDE_IP),
                         source_p->sockhost);
    sendto_one(source_p, ":%s NOTICE %s :*** Notice -- You need to install "
               "identd to use this server", me.name, source_p->name);
    return reject_user(source_p, "Install identd", YES);
  }

  // spoof check
  if (conf->spoof)
  {
    if ((conf->flags & AUTH_FLAG_SPOOF_NOTICE))
      sendto_realops_flags(UMODE_ALL, L_ADMIN,
                           "%s spoofing: %s as %s",
                           source_p->host, conf->spoof);

    SetIPSpoof(source_p);
    strlcpy(source_p->host, conf->spoof, sizeof(source_p->host));
  }

  return conf->class_ptr;
}

/*
 * register_local_user
 *      This function is called when both NICK and USER messages
 *      have been accepted for the client, in whatever order. Only
 *      after this, is the USER message propagated.
 *
 *      NICK's must be propagated at once when received, although
 *      it would be better to delay them too until full info is
 *      available. Doing it is not so simple though, would have
 *      to implement the following:
 *
 *      (actually it has been implemented already for a while) -orabidoo
 *
 *      1) user telnets in and gives only "NICK foobar" and waits
 *      2) another user far away logs in normally with the nick
 *         "foobar" (quite legal, as this server didn't propagate
 *         it).
 *      3) now this server gets nick "foobar" from outside, but
 *         has alread the same defined locally. Current server
 *         would just issue "KILL foobar" to clean out dups. But,
 *         this is not fair. It should actually request another
 *         nick from local user or kill him/her...
 */
void *
register_local_user(struct Client *source_p, const char *username)
{
  struct Class *cptr;
  int i;

  assert(source_p != NULL);
  assert(MyConnect(source_p));
  assert(source_p->username != username);
  assert(!source_p->localClient->registration);

  source_p->localClient->last = CurrentTime;
  // Straight up the maximum rate of flooding...
  source_p->localClient->allow_read = MAX_FLOOD_BURST;

  if (General.ping_cookie)
  {
    if (!IsPingSent(source_p) && !source_p->localClient->random_ping)
    {
      source_p->localClient->random_ping = (unsigned int)rand();
      sendto_one(source_p, "PING :%u",
                 source_p->localClient->random_ping);
      SetPingSent(source_p);
      return source_p;
    }

    if (!HasPingCookie(source_p))
      return source_p;
  }

  if (!valid_username(username))
    return reject_user(source_p, "Invalid username", YES);

  if (!valid_hostname(source_p->host))
  {
    sendto_one(source_p, ":%s NOTICE %s :*** Notice -- You have an illegal "
               "character in your hostname", me.name, source_p->name);
    strlcpy(source_p->host, source_p->sockhost, sizeof(source_p->host));
  }

  if (!(cptr = execute_callback(authorize_client, source_p, username)))
    return NULL;

  // Enforce class limits
  if ((i = attach_class(source_p, cptr)) == 0)
  {
    int lochost = find_or_add_ip(&source_p->localClient->ip)->count++;
    int globhost = 0, locuh = 0, globuh = 0, globnoid = 0, locnoid = 0;

    SetIpHash(source_p);

    count_user_host(source_p->username, source_p->host,
                    &globuh, &globhost, &locuh, &globnoid, &locnoid);

    /* XXX blah. go down checking the various silly limits
     * setting a_limit_reached if any limit is reached.
     * - Dianora
     */
    if (cptr->host_limit[0] > 0 && lochost >= cptr->host_limit[0])
      i++;
    else if (cptr->host_limit[1] > 0 && globhost >= cptr->host_limit[1])
      i++;
    else if (cptr->userhost_limit[0] > 0 && locuh >= cptr->userhost_limit[0])
      i++;
    else if (cptr->userhost_limit[1] > 0 && globuh >= cptr->userhost_limit[1])
      i++;
    else if (source_p->username[0] == '~')
    {
      if (cptr->noident_limit[0] > 0 && locnoid >= cptr->noident_limit[0])
        i++;
      else if (cptr->noident_limit[1] > 0 && globnoid >= cptr->noident_limit[1])
        i++;
    }
  }

  if (i != 0)
  {
    char *action = (i > 0 ? "rejecting" : "exceeding anyway");

    ilog(L_INFO, "Class limit reached for %s {%s}, %s",
         get_client_name(source_p, SHOW_IP), cptr->name, action);
    sendto_realops_flags(UMODE_FULL, L_ALL,
                         "Class limit reached for %s {%s}, %s",
                         get_client_name(source_p, HIDE_IP),
                         cptr->name, action);

    if (i > 0)
      return reject_user(source_p, "No more connections allowed - "
                         "try again later", NO);
    else
      sendto_one(source_p, ":%s NOTICE %s :*** Your class limit is reached, "
                 "but you have exceed_limit = yes;", me.name, source_p->name);
  }

  /* Limit clients -
   * We want to be able to have servers and F-line clients
   * connect, so save room for "buffer" connections.
   * Smaller servers may want to decrease this, and it should
   * probably be just a percentage of the MAXCLIENTS...
   *   -Taner
   */
  // Except "F:" clients
  if (Count.local >= ServerInfo.max_clients)
  {
    int exempt = (Count.local < ServerInfo.max_clients + MAX_BUFFER) &&
      IsExemptLimits(source_p);
    char *action = exempt ? "exceeding anyway" : "rejecting";

    ilog(L_INFO, "Server is full - %s: %s", action,
         get_client_name(source_p, SHOW_IP));
    sendto_realops_flags(UMODE_FULL, L_ALL,
                         "Server is full, %s: %s (%s)", action,
                         get_client_name(source_p, HIDE_IP),
                         source_p->sockhost);

    if (exempt)
      sendto_one(source_p, ":%s NOTICE %s :*** Server is full, but you have "
                 "exceed_limit = yes;", me.name, source_p->name);
    else
      return reject_user(source_p, "Sorry, server is full - try later", NO);
  }

  if (me.id[0] != '\0')
  {
    const char *id = execute_callback(uid_get, source_p);

    while (hash_find_id(id) != NULL)
      id = do_uid_get(NULL);

    strlcpy(source_p->id, id, sizeof(source_p->id));
    hash_add_id(source_p);
  }

  sendto_realops_flags(UMODE_CCONN, L_ALL,
                       "Client connecting: %s (%s@%s) [%s] {%s} [%s]",
                       source_p->name, source_p->username, source_p->host,
                       General.hide_spoof_ips && IsIPSpoof(source_p) ?
                       "255.255.255.255" : source_p->sockhost,
                       cptr->name, source_p->info);

  if (General.invisible_on_connect)
  {
    source_p->umodes |= UMODE_INVISIBLE;
    ++Count.invisi;
  }

  if (++Count.local > Count.max_loc)
  {
    Count.max_loc = Count.local;

    if (!(Count.max_loc % 10))
      sendto_realops_flags(UMODE_ALL, L_ALL, "New Max Local Clients: %d",
                           Count.max_loc);
  }

  SetClient(source_p);

  source_p->servptr = &me;
  dlinkAdd(source_p, &source_p->lnode, &source_p->servptr->serv->client_list);

  // Increment our total user count here
  if (++Count.total > Count.max_tot)
    Count.max_tot = Count.total;
  ++Count.totalrestartcount;

  source_p->localClient->allow_read = MAX_FLOOD_BURST;

  assert(dlinkFind(&unknown_list, source_p) != NULL);

  dlinkDelete(&source_p->localClient->lclient_node, &unknown_list);
  dlinkAdd(source_p, &source_p->localClient->lclient_node, &local_client_list);

  user_welcome(source_p);
  add_user_host(source_p->username, source_p->host, 0);
  SetUserHost(source_p);

  introduce_client(source_p, source_p);
  return source_p;
}

/* register_remote_user()
 *
 * inputs       - client_p directly connected client
 *              - source_p remote or directly connected client
 *              - username to register as
 *              - host name to register as
 *              - server name
 *              - realname (gecos)
 * output	- NONE
 * side effects	- This function is called when a remote client
 *		  is introduced by a server.
 */
void
register_remote_user(struct Client *client_p, struct Client *source_p,
                     const char *username, const char *host, const char *server,
                     const char *realname)
{
  struct Client *target_p = NULL;

  assert(source_p != NULL);
  assert(source_p->username != username);

  strlcpy(source_p->host, host, sizeof(source_p->host)); 
  strlcpy(source_p->info, realname, sizeof(source_p->info));
  strlcpy(source_p->username, username, sizeof(source_p->username));

  /*
   * coming from another server, take the servers word for it
   */
  source_p->servptr = find_server(server);

  /* Super GhostDetect:
   * If we can't find the server the user is supposed to be on,
   * then simply blow the user away.        -Taner
   */
  if (source_p->servptr == NULL)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "No server %s for user %s[%s@%s] from %s",
                         server, source_p->name, source_p->username,
                         source_p->host, source_p->from->name);
    kill_client(client_p, source_p, "%s (Server doesn't exist)", me.name);
    SetKilled(source_p);
    exit_client(source_p, &me, "Ghosted Client");
    return;
  }

  if ((target_p = source_p->servptr) && target_p->from != source_p->from)
  {
    sendto_realops_flags(UMODE_DEBUG, L_ALL,
                         "Bad User [%s] :%s USER %s@%s %s, != %s[%s]",
                         client_p->name, source_p->name, source_p->username,
                         source_p->host, source_p->servptr->name,
                         target_p->name, target_p->from->name);
    kill_client(client_p, source_p,
                "%s (NICK from wrong direction (%s != %s))",
                me.name, source_p->servptr->name, target_p->from->name);
    SetKilled(source_p);
    exit_client(source_p, &me, "USER server wrong direction");
    return;
  }

  /* Increment our total user count here */
  if (++Count.total > Count.max_tot)
    Count.max_tot = Count.total;

  SetClient(source_p);
  dlinkAdd(source_p, &source_p->lnode, &source_p->servptr->serv->client_list);
  add_user_host(source_p->username, source_p->host, 1);
  SetUserHost(source_p);

  introduce_client(client_p, source_p);
}

/* introduce_client()
 *
 * inputs	- client_p
 *              - source_p
 * output	- NONE
 * side effects - This common function introduces a client to the rest
 *		  of the net, either from a local client connect or
 *		  from a remote connect.
 */
static void
introduce_client(struct Client *client_p, struct Client *source_p)
{
  dlink_node *server_node = NULL;
  static char ubuf[12];

  if (MyClient(source_p))
    send_umode(source_p, source_p, 0, SEND_UMODES, ubuf);
  else
    send_umode(NULL, source_p, 0, SEND_UMODES, ubuf);

  watch_check_hash(source_p, RPL_LOGON);

  if (*ubuf == '\0')
  {
    ubuf[0] = '+';
    ubuf[1] = '\0';
  }

  DLINK_FOREACH(server_node, serv_list.head)
  {
    struct Client *server = server_node->data;

    if (server == client_p)
      continue;

    if (IsCapable(server, CAP_TS6) && HasID(source_p))
      sendto_one(server, ":%s UID %s %d %lu %s %s %s %s %s :%s",
                 source_p->servptr->id,
                 source_p->name, source_p->hopcount+1,
                 (unsigned long)source_p->tsinfo,
                 ubuf, source_p->username, source_p->host,
                 ((MyClient(source_p)&&!IsIPSpoof(source_p))?source_p->sockhost:"0"),
                 source_p->id, source_p->info);
    else
      sendto_one(server, "NICK %s %d %lu %s %s %s %s :%s",
                 source_p->name, source_p->hopcount+1,
                 (unsigned long)source_p->tsinfo,
                 ubuf, source_p->username, source_p->host,
                 source_p->servptr->name,
                 source_p->info);
  }
}

/* valid_hostname()
 *
 * Inputs       - pointer to hostname
 * Output       - 1 if valid, 0 if not
 * Side effects - check hostname for validity
 *
 * NOTE: this doesn't allow a hostname to begin with a dot and
 * will not allow more dots than chars.
 */
int
valid_hostname(const char *hostname)
{
  const char *p = hostname;

  assert(p != NULL);

  if ('.' == *p || ':' == *p)
    return 0;

  for (; *p != '\0'; ++p)
    if (!IsHostChar(*p))
      return 0;
  return 1;
}

/* valid_username()
 *
 * Inputs       - pointer to user
 * Output       - 1 if valid, 0 if not
 * Side effects - check username for validity
 *
 * Absolutely always reject any '*' '!' '?' '@' in an user name
 * reject any odd control characters names.
 * Allow '.' in username to allow for "first.last"
 * style of username
 */
int
valid_username(const char *username)
{
  int dots      = 0;
  const char *p = username;

  assert(p != NULL);

  if ('~' == *p)
    ++p;

  /* reject usernames that don't start with an alphanum
   * i.e. reject jokers who have '-@somehost' or '.@somehost'
   * or "-hi-@somehost", "h-----@somehost" would still be accepted.
   */
  if (!IsAlNum(*p))
    return 0;

  while (*++p)
  {
    if ((*p == '.') && General.dots_in_ident)
    {
      dots++;

      if (dots > General.dots_in_ident)
        return 0;
      if (!IsUserChar(p[1]))
        return 0;
    }
    else if (!IsUserChar(*p))
      return 0;
  }

  return 1;
}

/* change_simple_umode()
 *
 * this callback can be hooked to allow special handling of
 * certain usermodes
 */
void *
change_simple_umode(va_list args)
{
  struct Client *client_p;
  struct Client *source_p;
  int what;
  unsigned int flag;

  client_p = va_arg(args, struct Client *);
  source_p = va_arg(args, struct Client *);
  what = va_arg(args, int);
  flag = va_arg(args, unsigned int);

  if (what == MODE_ADD)
    source_p->umodes |= flag;
  else
    source_p->umodes &= ~flag;

  return NULL;
}

/* set_user_mode()
 *
 * added 15/10/91 By Darren Reed.
 * parv[0] - sender
 * parv[1] - username to change mode for
 * parv[2] - modes to change
 */
void
set_user_mode(struct Client *client_p, struct Client *source_p,
              int parc, char *parv[])
{
  unsigned int flag, setflags;
  char **p, *m, buf[IRCD_BUFSIZE];
  struct Client *target_p;
  int what = MODE_ADD, badflag = 0, i;

  assert(!(parc < 2));

  if ((target_p = find_person(client_p, parv[1])) == NULL)
  {
    if (MyConnect(source_p))
      sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
                 me.name, source_p->name, parv[1]);
    return;
  }

  if (IsServer(source_p))
  {
     sendto_realops_flags(UMODE_ALL, L_ADMIN, "*** Mode for User %s from %s",
                          parv[1], source_p->name);
     return;
  }

  if (source_p != target_p || target_p->from != source_p->from)
  {
     sendto_one(source_p, form_str(ERR_USERSDONTMATCH),
                me.name, source_p->name);
     return;
  }

  if (parc < 3)
  {
    m = buf;
    *m++ = '+';

    for (i = 0; i < 128; i++)
      if (source_p->umodes & user_modes[i])
        *m++ = (char)i;
    *m = '\0';

    sendto_one(source_p, form_str(RPL_UMODEIS),
               me.name, source_p->name, buf);
    return;
  }

  execute_callback(entering_umode_cb, client_p, source_p);

  /* find flags already set for user */
  setflags = source_p->umodes;

  /* parse mode change string(s) */
  for (p = &parv[2]; p && *p; p++)
  {
    for (m = *p; *m; m++)
    {
      switch (*m)
      {
        case '+':
          what = MODE_ADD;
          break;
        case '-':
          what = MODE_DEL;
          break;
        case 'o':
          if (what == MODE_ADD)
          {
            if (IsServer(client_p) && !IsOper(source_p))
            {
              ++Count.oper;
              SetOper(source_p);
            }
          }
          else
          {
            /* Only decrement the oper counts if an oper to begin with
             * found by Pat Szuta, Perly , perly@xnet.com 
             */
            if (!IsOper(source_p))
              break;

            ClearOper(source_p);
            source_p->umodes &= ~General.oper_only_umodes;
            Count.oper--;

            if (MyConnect(source_p))
            {
              dlink_node *dm;

              ClearOperFlags(source_p);

              if ((dm = dlinkFindDelete(&oper_list, source_p)) != NULL)
                free_dlink_node(dm);
            }
          }

          break;

        /* we may not get these,
         * but they shouldnt be in default
         */
        case ' ' :
        case '\n':
        case '\r':
        case '\t':
          break;

        default:
          if ((flag = user_modes[(unsigned char)*m]))
          {
            if (MyConnect(source_p) && !IsOper(source_p) &&
                (General.oper_only_umodes & flag))
            {
              badflag = 1;
            }
            else
              execute_callback(umode_cb, client_p, source_p, what, flag);
          }
          else
          {
            if (MyConnect(source_p))
              badflag = 1;
          }

          break;
      }
    }
  }

  if (badflag)
    sendto_one(source_p, form_str(ERR_UMODEUNKNOWNFLAG),
               me.name, source_p->name);

  if ((source_p->umodes & UMODE_NCHANGE) && !IsOperN(source_p))
  {
    sendto_one(source_p, ":%s NOTICE %s :*** You have no admin flag;",
               me.name, source_p->name);
    source_p->umodes &= ~UMODE_NCHANGE; /* only tcm's really need this */
  }

  if (MyConnect(source_p) && (source_p->umodes & UMODE_ADMIN) &&
      !IsOperAdmin(source_p) && !IsOperHiddenAdmin(source_p))
  {
    sendto_one(source_p, ":%s NOTICE %s :*** You have no admin flag;",
               me.name, source_p->name);
    source_p->umodes &= ~UMODE_ADMIN;
  }

  if (!(setflags & UMODE_INVISIBLE) && IsInvisible(source_p))
    ++Count.invisi;
  if ((setflags & UMODE_INVISIBLE) && !IsInvisible(source_p))
    --Count.invisi;

  /*
   * compare new flags with old flags and send string which
   * will cause servers to update correctly.
   */
  send_umode_out(client_p, source_p, setflags);
}

/* send_umode()
 * send the MODE string for user (user) to connection client_p
 * -avalon
 */
void
send_umode(struct Client *client_p, struct Client *source_p,
           unsigned int old, unsigned int sendmask, char *umode_buf)
{
  int what = 0;
  unsigned int i;
  unsigned int flag;
  char *m = umode_buf;

  /*
   * build a string in umode_buf to represent the change in the user's
   * mode between the new (source_p->umodes) and 'old'.
   */
  for (i = 0; i < 128; i++)
  {
    flag = user_modes[i];
    if (!flag)
      continue;

    if (MyClient(source_p) && !(flag & sendmask))
      continue;

    if ((flag & old) && !(source_p->umodes & flag))
    {
      if (what == MODE_DEL)
        *m++ = (char)i;
      else
      {
        what = MODE_DEL;
        *m++ = '-';
        *m++ = (char)i;
      }
    }
    else if (!(flag & old) && (source_p->umodes & flag))
    {
      if (what == MODE_ADD)
        *m++ = (char)i;
      else
      {
        what = MODE_ADD;
        *m++ = '+';
        *m++ = (char)i;
      }
    }
  }

  *m = '\0';

  if (*umode_buf && client_p)
    sendto_one(client_p, ":%s!%s@%s MODE %s :%s",
               source_p->name, source_p->username,
               source_p->host, source_p->name, umode_buf);
}

/* send_umode_out()
 *
 * inputs	-
 * output	- NONE
 * side effects - Only send ubuf out to servers that know about this client
 */
void
send_umode_out(struct Client *client_p, struct Client *source_p,
               unsigned int old)
{
  char buf[IRCD_BUFSIZE] = { '\0' };
  dlink_node *ptr = NULL;

  send_umode(NULL, source_p, old, IsOperHiddenAdmin(source_p) ?
             SEND_UMODES & ~UMODE_ADMIN : SEND_UMODES, buf);

  if (buf[0] != '\0')
  {
    DLINK_FOREACH(ptr, serv_list.head)
    {
      struct Client *target_p = ptr->data;

      if ((target_p != client_p) && (target_p != source_p))
        sendto_one(target_p, ":%s MODE %s :%s",
                   ID_or_name(source_p, target_p),
                   ID_or_name(source_p, target_p), buf);
    }
  }

  if (client_p && MyClient(client_p))
    send_umode(client_p, source_p, old, 0xffffffff, buf);
}

/* user_welcome()
 *
 * inputs	- client pointer to client to welcome
 * output	- NONE
 * side effects	-
 */
static void
user_welcome(struct Client *source_p)
{
#if defined(__TIME__) && defined(__DATE__)
  static const char built_date[] = __DATE__ " at " __TIME__;
#else
  static const char built_date[] = "unknown";
#endif

  if (IsIPSpoof(source_p))
    sendto_one(source_p,
               ":%s NOTICE %s :*** Spoofing your IP. congrats.",
               me.name, source_p->name);

  if (IsExemptKline(source_p))
    sendto_one(source_p,
               ":%s NOTICE %s :*** You are exempt from K/D/G lines. congrats.",
               me.name, source_p->name);
  /* The else here is to make sure that G line exempt users
   * do not get noticed twice.
   */
  else if (IsExemptGline(source_p))
    sendto_one(source_p, ":%s NOTICE %s :*** You are exempt from G lines.",
               me.name, source_p->name);

  if (IsExemptResv(source_p))
    sendto_one(source_p, ":%s NOTICE %s :*** You are exempt from resvs.",
               me.name, source_p->name);

  if (IsExemptLimits(source_p))
    sendto_one(source_p,
               ":%s NOTICE %s :*** You are exempt from user limits. congrats.",
               me.name,source_p->name);

  if (IsIdlelined(source_p))
    sendto_one(source_p,
               ":%s NOTICE %s :*** You are exempt from idle limits. congrats.",
               me.name, source_p->name);

  if (IsCanFlood(source_p))
    sendto_one(source_p, ":%s NOTICE %s :*** You are exempt from flood "
               "protection, aren't you fearsome.",
               me.name, source_p->name);

#ifdef HAVE_LIBCRYPTO
  if (source_p->localClient->fd.ssl != NULL)
    sendto_one(source_p, ":%s NOTICE %s :*** Connected securely via %s",
               me.name, source_p->name,
               ssl_get_cipher(source_p->localClient->fd.ssl));
#endif

  sendto_one(source_p, form_str(RPL_WELCOME), me.name, source_p->name, 
             ServerInfo.network_name, source_p->name);
  sendto_one(source_p, form_str(RPL_YOURHOST), me.name, source_p->name,
             get_listener_name(source_p->localClient->listener), ircd_version);
  sendto_one(source_p, form_str(RPL_CREATED),
             me.name, source_p->name, built_date);
  sendto_one(source_p, form_str(RPL_MYINFO),
             me.name, source_p->name, me.name, ircd_version, umode_buffer);
  send_message_file(source_p, isupportFile);

  if (source_p->id[0] != '\0')
    sendto_one(source_p, form_str(RPL_YOURID), me.name,
               source_p->name, source_p->id);

  show_lusers(source_p);

  if (General.short_motd)
  {
    sendto_one(source_p, "NOTICE %s :*** Notice -- motd was last changed at %s",
               source_p->name, motd.lastChangedDate);
    sendto_one(source_p,
               "NOTICE %s :*** Notice -- Please read the motd if you haven't "
               "read it", source_p->name);
    sendto_one(source_p, form_str(RPL_MOTDSTART),
               me.name, source_p->name, me.name);
    sendto_one(source_p, form_str(RPL_MOTD),
               me.name, source_p->name,
               "*** This is the short motd ***");
    sendto_one(source_p, form_str(RPL_ENDOFMOTD),
               me.name, source_p->name);
  }
  else  
    send_message_file(source_p, &motd);
}

/*
 * oper_up()
 *
 * Blindly opers up given source_p, using conf info.
 * All checks on passwords have already been done.
 *
 * inputs:
 *   source_p  -  pointer to given client to oper
 *   conf      -  pointer to oper conf found
 * output: none
 */
void
oper_up(struct Client *source_p, struct OperatorConf *conf)
{
  unsigned int old = source_p->umodes;

  SetOper(source_p);
  Count.oper++;

  assert(dlinkFind(&oper_list, source_p) == NULL);
  dlinkAdd(source_p, make_dlink_node(), &oper_list);

  if (conf->class_ptr != source_p->localClient->class)
    attach_class(source_p, conf->class_ptr);

  SetOperFlags(source_p, conf->flags);

  source_p->umodes |= General.oper_umodes;

  if (IsOperAdmin(source_p) || IsOperHiddenAdmin(source_p))
    source_p->umodes |= UMODE_ADMIN;
  if (!IsOperN(source_p))
    source_p->umodes &= ~UMODE_NCHANGE;

  send_umode_out(source_p, source_p, old);

  MyFree(source_p->localClient->auth_oper);
  DupString(source_p->localClient->auth_oper, conf->name);

  sendto_one(source_p, form_str(RPL_YOUREOPER), me.name, source_p->name);
  sendto_realops_flags(UMODE_ALL, L_ALL, "%s (%s@%s) is now an operator",
                       source_p->name, source_p->username, source_p->host);

  sendto_one(source_p, ":%s NOTICE %s :*** Oper privs are %s",
             me.name, source_p->name, oper_privs_as_string(conf->flags));
  send_message_file(source_p, &opermotd);
}

/*
 * UID code for TS6 SID code on EFnet
 */

char new_uid[TOTALSIDUID + 1] = {0};

/*
 * init_uid()
 * 
 * inputs	- NONE
 * output	- NONE
 * side effects	- new_uid is filled in with server id portion (sid)
 *		  (first 3 bytes) or defaulted to 'A'.
 *	          Rest is filled in with 'A' except for the last byte 
 *		  which is filled in with '@' 
 */
void
init_uid(void)
{
  int i;

  if (me.id[0])
    strcpy(new_uid, me.id);

  for (i = 0; i < IRC_MAXSID; i++)
    if (new_uid[i] == '\0') 
      new_uid[i] = 'A';

  /* NOTE: if IRC_MAXUID != 6, this will have to be rewritten */
  /* Yes nenolod, I have known it was off by one ever since I wrote it
   * But *JUST* for you, though, it really doesn't look as *pretty*
   * -Dianora
   */
  memcpy(new_uid + IRC_MAXSID, "AAAAA@", IRC_MAXUID);
}

/*
 * add_one_to_uid
 *
 * inputs	- index number into new_uid
 * output	- NONE
 * side effects	- new_uid is incremented by one
 *		  note this is a recursive function
 */
static void
add_one_to_uid(int i)
{
  if (i != IRC_MAXSID)    /* Not reached server SID portion yet? */
  {
    if (new_uid[i] == 'Z')
      new_uid[i] = '0';
    else if (new_uid[i] == '9')
    {
      new_uid[i] = 'A';
      add_one_to_uid(i-1);
    }
    else new_uid[i] = new_uid[i] + 1;
  }
  else
  {
    /* NOTE: if IRC_MAXUID != 6, this will have to be rewritten */
    if (new_uid[i] == 'Z')
      memcpy(new_uid+IRC_MAXSID, "AAAAAA", IRC_MAXUID);
    else
      new_uid[i] = new_uid[i] + 1;
  }
}

/*
 * do_uid_get
 *
 * inputs	- struct Client *
 * output	- new UID is returned to caller
 * side effects	- new_uid is incremented by one.
 */
void *
do_uid_get(va_list args)
{
  add_one_to_uid(TOTALSIDUID - 1);    /* index from 0 */
  return new_uid;
}

/*
 * init_isupport()
 *
 * input	- NONE
 * output	- NONE
 * side effects	- Must be called before isupport is enabled
 */
void
init_isupport(void)
{
  isupportFile = init_MessageLine();

  add_isupport("CALLERID", NULL, -1);
  add_isupport("CASEMAPPING", "rfc1459", -1);
  add_isupport("DEAF", "D", -1);
  add_isupport("KICKLEN", NULL, KICKLEN);
  add_isupport("MODES", NULL, MAXMODEPARAMS);
  add_isupport("NICKLEN", NULL, NICKLEN-1);
#ifdef HALFOPS
  add_isupport("PREFIX", "(ohv)@%+", -1);
  add_isupport("STATUSMSG", "@%+", -1);
#else
  add_isupport("PREFIX", "(ov)@+", -1);
  add_isupport("STATUSMSG", "@+", -1);
#endif
  add_isupport("TOPICLEN", NULL, TOPICLEN);
  add_isupport("CHANNELLEN", NULL, LOCAL_CHANNELLEN);
}

/*
 * add_isupport()
 *
 * input	- name of supported function
 *		- options if any
 *		- number if any
 * output	- NONE
 * side effects	- Each supported item must call this when activated
 */
void
add_isupport(const char *name, const char *options, int n)
{
  dlink_node *ptr;
  struct Isupport *support;

  DLINK_FOREACH(ptr, support_list.head)
  {
    support = ptr->data;

    if (irccmp(support->name, name) == 0)
    {
      MyFree(support->name);
      MyFree(support->options);
      break;
    }
  }

  if (ptr == NULL)
  {
    support = MyMalloc(sizeof(*support));
    dlinkAddTail(support, &support->node, &support_list);
  }

  DupString(support->name, name);
  if (options != NULL)
    DupString(support->options, options);
  support->number = n;

  rebuild_isupport_message_line();
}

/*
 * delete_isupport()
 *
 * input	- name of supported function
 * output	- NONE
 * side effects	- Each supported item must call this when deactivated
 */
void
delete_isupport(const char *name)
{
  dlink_node *ptr;
  struct Isupport *support;

  DLINK_FOREACH(ptr, support_list.head)
  {
    support = ptr->data;
    if (irccmp(support->name, name) == 0)
    {
      dlinkDelete(ptr, &support_list);
      MyFree(support->name);
      MyFree(support->options);
      MyFree(support);
      break;
    }
  }

  rebuild_isupport_message_line();
}

/*
 * rebuild_isupport_message_line
 *
 * input	- NONE
 * output	- NONE
 * side effects	- Destroy the isupport MessageFile lines, and rebuild.
 */
void
rebuild_isupport_message_line(void)
{
  char isupportbuffer[IRCD_BUFSIZE];
  char *p = isupportbuffer;
  dlink_node *ptr = NULL;
  int n = 0;
  int tokens = 0;
  size_t len = 0;
  size_t reserve = strlen(me.name) + HOSTLEN + strlen(form_str(RPL_ISUPPORT));

  destroy_MessageLine(isupportFile);

  DLINK_FOREACH(ptr, support_list.head)
  {
    struct Isupport *support = ptr->data;

    p += (n = ircsprintf(p, "%s", support->name));
    len += n;

    if (support->options != NULL)
    {
      p += (n = ircsprintf(p, "=%s", support->options));
      len += n;
    }

    if (support->number > 0)
    {
      p += (n = ircsprintf(p, "=%d", support->number));
      len += n;
    }

    *p++ = ' ';
    len++;
    *p = '\0';

    if (++tokens == (IRCD_MAXPARA-2) || len >= (sizeof(isupportbuffer)-reserve))
    { /* arbritrary for now */
      if (*--p == ' ')
        *p = '\0';

      addto_MessageLine(isupportFile, isupportbuffer);
      p = isupportbuffer;
      len = 0;
      n = tokens = 0;
    }
  }

  if (len != 0)
  {
    if (*--p == ' ')
      *p = '\0';
    addto_MessageLine(isupportFile, isupportbuffer);
  }
}

/*
 * Input: A client to find the active oper{} name for.
 * Output: The nick!user@host{oper} of the oper.
 *         "oper" is server name for remote opers
 * Side effects: None.
 */
char *
get_oper_name(const struct Client *client_p)
{
  /* +5 for !,@,{,} and null */
  static char buffer[NICKLEN+USERLEN+HOSTLEN+HOSTLEN+5];

  if (MyConnect(client_p) && IsOper(client_p))
    ircsprintf(buffer, "%s!%s@%s{%s}", client_p->name,
           client_p->username, client_p->host,
           client_p->localClient->auth_oper);
  else
    ircsprintf(buffer, "%s!%s@%s{%s}", client_p->name,
           client_p->username, client_p->host,
               client_p->servptr->name);
  return buffer;
}
