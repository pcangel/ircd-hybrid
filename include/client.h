/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2014 ircd-hybrid development team
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
 */

/*! \file client.h
 * \brief Header including structures, macros and prototypes for client handling
 * \version $Id$
 */


#ifndef INCLUDED_client_h
#define INCLUDED_client_h

#include "list.h"
#include "fdlist.h"
#include "config.h"
#include "ircd_defs.h"
#include "dbuf.h"
#include "channel.h"
#include "auth.h"

struct MaskItem;

/*
 * status macros.
 */
#define STAT_CONNECTING         0x01
#define STAT_HANDSHAKE          0x02
#define STAT_ME                 0x04
#define STAT_UNKNOWN            0x08
#define STAT_SERVER             0x10
#define STAT_CLIENT             0x20

#define REG_NEED_USER 0x1  /**< User must send USER command */
#define REG_NEED_NICK 0x2  /**< User must send NICK command */
#define REG_NEED_CAP  0x4  /**< In middle of CAP negotiations */
#define REG_INIT (REG_NEED_USER|REG_NEED_NICK)

#define ID_or_name(x,client_p)  ((IsCapable(client_p->from, CAP_TS6) && (x)->id[0]) ? (x)->id : (x)->name)

#define IsRegistered(x)         ((x)->status  > STAT_UNKNOWN)
#define IsConnecting(x)         ((x)->status == STAT_CONNECTING)
#define IsHandshake(x)          ((x)->status == STAT_HANDSHAKE)
#define IsMe(x)                 ((x)->status == STAT_ME)
#define IsUnknown(x)            ((x)->status == STAT_UNKNOWN)
#define IsServer(x)             ((x)->status == STAT_SERVER)
#define IsClient(x)             ((x)->status == STAT_CLIENT)

#define SetConnecting(x)        {(x)->status = STAT_CONNECTING; \
                                 (x)->handler = UNREGISTERED_HANDLER; }

#define SetHandshake(x)         {(x)->status = STAT_HANDSHAKE; \
                                 (x)->handler = UNREGISTERED_HANDLER; }

#define SetMe(x)                {(x)->status = STAT_ME; \
                                 (x)->handler = UNREGISTERED_HANDLER; }

#define SetUnknown(x)           {(x)->status = STAT_UNKNOWN; \
                                 (x)->handler = UNREGISTERED_HANDLER; }

#define SetServer(x)            {(x)->status = STAT_SERVER; \
                                 (x)->handler = SERVER_HANDLER; }

#define SetClient(x)            {(x)->status = STAT_CLIENT; \
                                 (x)->handler = HasUMode(x, UMODE_OPER) ? \
                                 OPER_HANDLER : CLIENT_HANDLER; }

#define MyConnect(x)            ((x)->localClient != NULL)
#define MyClient(x)             (MyConnect(x) && IsClient(x))

/*
 * ts stuff
 */
#define TS_CURRENT      6  /**< Current TS protocol version */
#define TS_MIN          6  /**< Minimum supported TS protocol version */
#define TS_DOESTS       0x20000000
#define DoesTS(x)       ((x)->tsinfo == TS_DOESTS)



#define CAP_MULTI_PREFIX  0x00000001
#define CAP_AWAY_NOTIFY   0x00000002
#define CAP_UHNAMES       0x00000004

#define HasCap(x, y) ((x)->localClient->cap_active & (y))


/* housekeeping flags */
#define FLAGS_PINGSENT       0x00000001  /**< Unreplied ping sent */
#define FLAGS_DEADSOCKET     0x00000002  /**< Local socket is dead--Exiting soon */
#define FLAGS_KILLED         0x00000004  /**< Prevents "QUIT" from being sent for this */
#define FLAGS_CLOSING        0x00000008  /**< Set when closing to suppress errors */
#define FLAGS_GOTID          0x00000010  /**< Successful ident lookup achieved */
#define FLAGS_NEEDID         0x00000020  /**< auth{} block say must use ident return */
#define FLAGS_SENDQEX        0x00000040  /**< Sendq exceeded */
#define FLAGS_IPHASH         0x00000080  /**< Iphashed this client */
#define FLAGS_MARK           0x00000100  /**< Marked client */
#define FLAGS_CANFLOOD       0x00000200  /**< Client has the ability to flood */
#define FLAGS_EXEMPTGLINE    0x00000400  /**< Client can't be G-lined */
#define FLAGS_EXEMPTKLINE    0x00000800  /**< Client is exempt from kline */
#define FLAGS_NOLIMIT        0x00001000  /**< Client is exempt from limits */
#define FLAGS_PING_COOKIE    0x00002000  /**< PING Cookie */
#define FLAGS_IP_SPOOFING    0x00004000  /**< Client IP is spoofed */
#define FLAGS_FLOODDONE      0x00008000  /**< Flood grace period has been ended. */
#define FLAGS_EOB            0x00010000  /**< Server has sent us an EOB */
#define FLAGS_HIDDEN         0x00020000  /**< A hidden server. Not shown in /links */
#define FLAGS_BLOCKED        0x00040000  /**< Must wait for COMM_SELECT_WRITE */
#define FLAGS_USERHOST       0x00080000  /**< Client is in userhost hash */
#define FLAGS_BURSTED        0x00100000  /**< User was already bursted */
#define FLAGS_EXEMPTRESV     0x00200000  /**< Client is exempt from RESV */
#define FLAGS_GOTUSER        0x00400000  /**< If we received a USER command */
#define FLAGS_FINISHED_AUTH  0x00800000  /**< Client has been released from auth */
#define FLAGS_FLOOD_NOTICED  0x01000000  /**< Notice to opers about this flooder has been sent */
#define FLAGS_SERVICE        0x02000000  /**< Client/server is a network service */
#define FLAGS_AUTH_SPOOF     0x04000000  /**< User's hostname has been spoofed by an auth{} spoof */
#define FLAGS_SSL            0x08000000  /**< User is connected via TLS/SSL */
#define FLAGS_SQUIT          0x10000000

#define HasFlag(x, y) ((x)->flags &   (y))
#define AddFlag(x, y) ((x)->flags |=  (y))
#define DelFlag(x, y) ((x)->flags &= ~(y))



/* umodes, settable flags */
#define UMODE_SERVNOTICE   0x00000001 /**< Server notices such as kill */
#define UMODE_CCONN        0x00000002 /**< Client Connections */
#define UMODE_REJ          0x00000004 /**< Bot Rejections */
#define UMODE_SKILL        0x00000008 /**< Server Killed */
#define UMODE_FULL         0x00000010 /**< Full messages */
#define UMODE_SPY          0x00000020 /**< See STATS / LINKS */
#define UMODE_DEBUG        0x00000040 /**< 'debugging' info */
#define UMODE_NCHANGE      0x00000080 /**< Nick change notice */
#define UMODE_WALLOP       0x00000100 /**< Send wallops to them */
#define UMODE_OPERWALL     0x00000200 /**< Operwalls */
#define UMODE_INVISIBLE    0x00000400 /**< Makes user invisible */
#define UMODE_BOTS         0x00000800 /**< Shows bots */
#define UMODE_EXTERNAL     0x00001000 /**< Show servers introduced and splitting */
#define UMODE_CALLERID     0x00002000 /**< Block unless caller id's */
#define UMODE_SOFTCALLERID 0x00004000 /**< Block unless on common channel */
#define UMODE_UNAUTH       0x00008000 /**< Show unauth connects here */
#define UMODE_LOCOPS       0x00010000 /**< Show locops */
#define UMODE_DEAF         0x00020000 /**< Don't receive channel messages */
#define UMODE_REGISTERED   0x00040000 /**< User has identified for that nick. */
#define UMODE_REGONLY      0x00080000 /**< Only registered nicks may PM */
#define UMODE_HIDDEN       0x00100000 /**< Operator status is hidden */
#define UMODE_OPER         0x00200000 /**< Operator */
#define UMODE_ADMIN        0x00400000 /**< Admin on server */
#define UMODE_FARCONNECT   0x00800000 /**< Can see remote client connects/exits */
#define UMODE_HIDDENHOST   0x01000000 /**< User's host is hidden */
#define UMODE_SSL          0x02000000 /**< User is connected via TLS/SSL */
#define UMODE_WEBIRC       0x04000000 /**< User connected via a webirc gateway */
#define UMODE_HIDEIDLE     0x08000000 /**< Hides idle and signon time in WHOIS */
#define UMODE_HIDECHANS    0x10000000 /**< Hides channel list in WHOIS */

#define UMODE_ALL          UMODE_SERVNOTICE

#define HasUMode(x, y) ((x)->umodes &   (y))
#define AddUMode(x, y) ((x)->umodes |=  (y))
#define DelUMode(x, y) ((x)->umodes &= ~(y))

#define SEND_UMODES  (UMODE_INVISIBLE | UMODE_OPER | UMODE_WALLOP |\
                      UMODE_REGONLY | UMODE_REGISTERED | UMODE_ADMIN |\
                      UMODE_HIDDEN | UMODE_HIDDENHOST | UMODE_SSL |\
                      UMODE_WEBIRC | UMODE_CALLERID | UMODE_SOFTCALLERID|\
                      UMODE_HIDECHANS)



/* oper priv flags */
#define OPER_FLAG_KILL_REMOTE    0x00000001  /**< Oper can global KILL */
#define OPER_FLAG_KILL           0x00000002  /**< Oper can do local KILL */
#define OPER_FLAG_UNKLINE        0x00000004  /**< Oper can use use UNKLINE command */
#define OPER_FLAG_GLINE          0x00000008  /**< Oper can use GLINE command */
#define OPER_FLAG_K              0x00000010  /**< Oper can use KLINE command */
#define OPER_FLAG_XLINE          0x00000020  /**< Oper can use XLINE command */
#define OPER_FLAG_DIE            0x00000040  /**< Oper can use DIE command */
#define OPER_FLAG_REHASH         0x00000080  /**< Oper can use REHASH command */
#define OPER_FLAG_ADMIN          0x00000100  /**< Oper can set user mode +a*/
#define OPER_FLAG_OPERWALL       0x00000200  /**< Oper can use OPERWALL command */
#define OPER_FLAG_REMOTEBAN      0x00000400  /**< Oper can set remote bans */
#define OPER_FLAG_GLOBOPS        0x00000800  /**< Oper can use GLOBOPS command */
#define OPER_FLAG_MODULE         0x00001000  /**< Oper can use MODULE commands */
#define OPER_FLAG_RESTART        0x00002000  /**< Oper can use RESTART command */
#define OPER_FLAG_DLINE          0x00004000  /**< Oper can use DLINE command */
#define OPER_FLAG_UNDLINE        0x00008000  /**< Oper can use UNDLINE command */
#define OPER_FLAG_SET            0x00010000  /**< Oper can use SET command */
#define OPER_FLAG_SQUIT          0x00020000  /**< Oper can do local SQUIT */
#define OPER_FLAG_SQUIT_REMOTE   0x00040000  /**< Oper can do global SQUIT */
#define OPER_FLAG_CONNECT        0x00080000  /**< Oper can do local CONNECT */
#define OPER_FLAG_CONNECT_REMOTE 0x00100000  /**< Oper can do global CONNECT */
#define OPER_FLAG_WALLOPS        0x00200000  /**< Oper can use WALLOPS command */
#define OPER_FLAG_LOCOPS         0x00400000  /**< Oper can use LOCOPS command */
#define OPER_FLAG_UNXLINE        0x00800000  /**< Oper can use UNXLINE command */


#define HasOFlag(x, y) (MyConnect(x) ? (x)->localClient->operflags & (y) : 0)
#define AddOFlag(x, y) ((x)->localClient->operflags |=  (y))
#define DelOFlag(x, y) ((x)->localClient->operflags &= ~(y))
#define ClrOFlag(x)    ((x)->localClient->operflags = 0)



/* flags macros. */
#define IsAuthFinished(x)       ((x)->flags & FLAGS_FINISHED_AUTH)
#define IsDead(x)               ((x)->flags & FLAGS_DEADSOCKET)
#define SetDead(x)              ((x)->flags |= FLAGS_DEADSOCKET)
#define IsClosing(x)            ((x)->flags & FLAGS_CLOSING)
#define SetClosing(x)           ((x)->flags |= FLAGS_CLOSING)
#define SetCanFlood(x)          ((x)->flags |= FLAGS_CANFLOOD)
#define IsCanFlood(x)           ((x)->flags & FLAGS_CANFLOOD)
#define IsDefunct(x)            ((x)->flags & (FLAGS_DEADSOCKET|FLAGS_CLOSING|FLAGS_KILLED))

/* oper flags */
#define MyOper(x)               (MyConnect(x) && HasUMode(x, UMODE_OPER))

#define SetOper(x)              {(x)->umodes |= UMODE_OPER; \
                                 if (!IsServer((x))) (x)->handler = OPER_HANDLER;}

#define ClearOper(x)            {(x)->umodes &= ~(UMODE_OPER|UMODE_ADMIN); \
                                 if (!HasUMode(x, UMODE_OPER) && !IsServer((x))) \
                                  (x)->handler = CLIENT_HANDLER; }

#define SetSendQExceeded(x)     ((x)->flags |= FLAGS_SENDQEX)
#define IsSendQExceeded(x)      ((x)->flags &  FLAGS_SENDQEX)

#define SetIpHash(x)            ((x)->flags |= FLAGS_IPHASH)
#define IsIpHash(x)             ((x)->flags & FLAGS_IPHASH)

#define SetUserHost(x)          ((x)->flags |= FLAGS_USERHOST)
#define IsUserHostIp(x)         ((x)->flags & FLAGS_USERHOST)

#define SetPingSent(x)          ((x)->flags |= FLAGS_PINGSENT)
#define IsPingSent(x)           ((x)->flags & FLAGS_PINGSENT)
#define ClearPingSent(x)        ((x)->flags &= ~FLAGS_PINGSENT)

#define SetNeedId(x)            ((x)->flags |= FLAGS_NEEDID)
#define IsNeedId(x)             ((x)->flags & FLAGS_NEEDID)

#define SetGotId(x)             ((x)->flags |= FLAGS_GOTID)
#define IsGotId(x)              ((x)->flags & FLAGS_GOTID)

#define IsExemptKline(x)        ((x)->flags & FLAGS_EXEMPTKLINE)
#define SetExemptKline(x)       ((x)->flags |= FLAGS_EXEMPTKLINE)
#define IsExemptLimits(x)       ((x)->flags & FLAGS_NOLIMIT)
#define SetExemptLimits(x)      ((x)->flags |= FLAGS_NOLIMIT)
#define IsExemptGline(x)        ((x)->flags & FLAGS_EXEMPTGLINE)
#define SetExemptGline(x)       ((x)->flags |= FLAGS_EXEMPTGLINE)
#define IsExemptResv(x)         ((x)->flags & FLAGS_EXEMPTRESV)
#define SetExemptResv(x)        ((x)->flags |= FLAGS_EXEMPTRESV)
#define SetIPSpoof(x)           ((x)->flags |= FLAGS_IP_SPOOFING)
#define IsIPSpoof(x)            ((x)->flags & FLAGS_IP_SPOOFING)

#define IsFloodDone(x)          ((x)->flags &  FLAGS_FLOODDONE)
#define SetFloodDone(x)         ((x)->flags |= FLAGS_FLOODDONE)
#define HasPingCookie(x)        ((x)->flags & FLAGS_PING_COOKIE)
#define SetPingCookie(x)        ((x)->flags |= FLAGS_PING_COOKIE)
#define IsHidden(x)             ((x)->flags &  FLAGS_HIDDEN)
#define SetHidden(x)            ((x)->flags |= FLAGS_HIDDEN)


/*! \brief addr_mask_type enumeration */
enum addr_mask_type
{
  HIDE_IP, /**< IP is hidden. Resolved hostname is shown instead */
  SHOW_IP, /**< IP is shown. No parts of it are hidden or masked */
  MASK_IP  /**< IP is masked. 255.255.255.255 is shown instead */
};

/*! \brief Server structure */
struct Server
{
  dlink_list server_list; /**< Servers on this server */
  dlink_list client_list; /**< Clients on this server */
  char by[NICKLEN + 1];   /**< Who activated this connection */
};

/*! \brief ListTask structure */
struct ListTask
{
  dlink_list show_mask; /**< Channels to show */
  dlink_list hide_mask; /**< Channels to hide */

  unsigned int hash_index; /**< The hash bucket we are currently in */
  unsigned int users_min;
  unsigned int users_max;
  unsigned int created_min;
  unsigned int created_max;
  unsigned int topicts_min;
  unsigned int topicts_max;
};

/*! \brief LocalUser structure
 *
 * Allocated only for local clients, that are directly connected
 * to \b this server with a socket.
 */
struct LocalUser
{
  dlink_node   lclient_node;

  unsigned int registration;
  unsigned int cap_client;  /**< Client capabilities (from us) */
  unsigned int cap_active;  /**< Active capabilities (to us) */
  unsigned int       caps;  /**< Capabilities bit-field */

  unsigned int operflags;     /**< IRC Operator privilege flags */
  unsigned int random_ping; /**< Holding a 32bit value used for PING cookies */

  unsigned int serial;     /**< Used to enforce 1 send per nick */

  time_t       lasttime;   /**< ...should be only LOCAL clients? --msa */
  time_t       firsttime;  /**< Time client was created */
  time_t       since;      /**< Last time we parsed something */
  time_t       last_join_time;   /**< When this client last joined a channel */
  time_t       last_leave_time;  /**< When this client last left a channel */
  int          join_leave_count; /**< Count of JOIN/LEAVE in less than
                                         MIN_JOIN_LEAVE_TIME seconds */
  int          oper_warn_count_down; /**< Warn opers of this possible
                                          spambot every time this gets to 0 */
  time_t       last_caller_id_time;
  time_t       first_received_message_time;
  time_t       last_nick_change;
  time_t       last_privmsg;  /**< Last time we got a PRIVMSG */
  time_t       last_away;  /**< Away since... */

  int          received_number_of_privmsgs;
  unsigned int number_of_nick_changes;

  struct ListTask  *list_task;

  struct dbuf_queue buf_sendq;
  struct dbuf_queue buf_recvq;

  struct
  {
    unsigned int messages;      /**< Statistics: protocol messages sent/received */
    uint64_t bytes;             /**< Statistics: total bytes sent/received */
  } recv, send;

  struct
  {
    unsigned int count;  /**< How many INVITE/KNOCK requests client has send */
    time_t last_attempt;  /**< Las time the INVITE/KNOCK request was issued */
  } invite, knock;

  struct AuthRequest auth;
  struct Listener *listener;   /**< Listener accepted from */
  dlink_list        acceptlist; /**< Clients I'll allow to talk to me */
  dlink_list        watches;   /**< Chain of Watch pointer blocks */
  dlink_list        confs;     /**< Configuration record associated */
  dlink_list        invited;   /**< Chain of invite pointer blocks */
  struct irc_ssaddr ip;
  int               aftype;    /**< Makes life easier for DNS res in IPV6 */
  int               country_id; /**< ID corresponding to a ISO 3166 country code */

  char              *passwd;
  fde_t             fd;
  /* Anti-flood stuff. We track how many messages were parsed and how
   * many we were allowed in the current second, and apply a simple
   * decay to avoid flooding.
   *   -- adrian
   */
  int allow_read;       /**< How many we're allowed to read in this second */
  int sent_parsed;      /**< How many messages we've parsed in this second */

  char*          response;  /**< Expected CHALLENGE response from client */
  char*          auth_oper; /**< Operator to become if they supply the response */
};

/*! \brief Client structure */
struct Client
{
  dlink_node node;
  dlink_node lnode;             /**< Used for Server->servers/users */

  struct LocalUser *localClient;
  struct Client    *hnext;      /**< For client hash table lookups by name */
  struct Client    *idhnext;    /**< For SID hash table lookups by sid */
  struct Server    *serv;       /**< ...defined, if this is a server */
  struct Client    *servptr;    /**< Points to server this Client is on */
  struct Client    *from;       /**< == self, if Local Client, *NEVER* NULL! */

  time_t            tsinfo;     /**< TS on the nick, SVINFO on server */

  unsigned int      flags;      /**< Client flags */
  unsigned int      umodes;     /**< Opers, normal users subset */
  unsigned int      hopcount;   /**< Number of servers to this 0 = local */
  unsigned int      status;     /**< Client type */
  unsigned int      handler;    /**< Handler index */

  dlink_list        whowas;
  dlink_list        channel;   /**< Chain of channel pointer blocks */

  char away[AWAYLEN + 1]; /**< Client's AWAY message. Can be set/unset via AWAY command */
  char name[HOSTLEN + 1]; /**< Unique name for a client nick or host */
  char svid[SVIDLEN + 1]; /**< Services ID */
  char id[IDLEN + 1];       /**< Client ID, unique ID per client */

  /*
   * client->username is the username from ident or the USER message,
   * If the client is idented the USER message is ignored, otherwise
   * the username part of the USER message is put here prefixed with a
   * tilde depending on the auth{} block. Once a client has registered,
   * this field should be considered read-only.
   */
  char              username[USERLEN + 1]; /* client's username */

  /*
   * client->host contains the resolved name or ip address
   * as a string for the user, it may be fiddled with for oper spoofing etc.
   * once it's changed the *real* address goes away. This should be
   * considered a read-only field after the client has registered.
   */
  char              host[HOSTLEN + 1];     /* client's hostname */

  /*
   * client->info for unix clients will normally contain the info from the
   * gcos field in /etc/passwd but anything can go here.
   */
  char              info[REALLEN + 1]; /* Free form additional client info */

  /*
   * client->sockhost contains the ip address gotten from the socket as a
   * string, this field should be considered read-only once the connection
   * has been made. (set in s_bsd.c only)
   */
  char              sockhost[HOSTIPLEN + 1]; /* This is the host name from the
                                                socket ip address as string */
  char             *certfp;
};


extern struct Client me;
extern dlink_list listing_client_list;
extern dlink_list global_client_list;
extern dlink_list unknown_list;       /* unknown clients ON this server only        */
extern dlink_list local_client_list;  /* local clients only ON this server          */
extern dlink_list serv_list;          /* local servers to this server ONLY          */
extern dlink_list global_serv_list;   /* global servers on the network              */
extern dlink_list oper_list;          /* our opers, duplicated in local_client_list */

extern int accept_message(struct Client *, struct Client *);
extern unsigned int idle_time_get(const struct Client *, const struct Client *);
extern struct split_nuh_item *find_accept(const char *, const char *,
                                          const char *, struct Client *,
                                          int (*)(const char *, const char *));
extern void del_accept(struct split_nuh_item *, struct Client *);
extern void del_all_accepts(struct Client *);
extern void exit_client(struct Client *, const char *);
extern void conf_try_ban(struct Client *, struct MaskItem *);
extern void check_conf_klines(void);
extern void client_init(void);
extern void dead_link_on_write(struct Client *, int);
extern void dead_link_on_read(struct Client *, int);
extern void exit_aborted_clients(void);
extern void free_exited_clients(void);
extern struct Client *make_client(struct Client *);
extern struct Client *find_chasing(struct Client *, const char *);
extern struct Client *find_person(const struct Client *const, const char *);
extern const char *get_client_name(const struct Client *, enum addr_mask_type);

#endif /* INCLUDED_client_h */
