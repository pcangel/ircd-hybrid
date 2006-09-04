/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  operator.h: Defines operator{} conf section.
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

struct OperatorConf
{
  unsigned int flags;
  char *name;
  char *passwd;
  struct Class *class_ptr;
#ifdef HAVE_LIBCRYPTO
  RSA *rsa_public_key;
#endif
  dlink_list masks;
  dlink_node node;
};

#define OPER_FLAG_GLOBAL_KILL  0x00000001  /* oper can global kill        */
#define OPER_FLAG_REMOTE       0x00000002  /* oper can do squits/connects */
#define OPER_FLAG_UNKLINE      0x00000004  /* oper can use unkline        */
#define OPER_FLAG_GLINE        0x00000008  /* oper can use gline          */
#define OPER_FLAG_N            0x00000010  /* oper can umode n            */
#define OPER_FLAG_K            0x00000020  /* oper can kill/kline         */
#define OPER_FLAG_X            0x00000040  /* oper can xline              */
#define OPER_FLAG_DIE          0x00000080  /* oper can die                */
#define OPER_FLAG_REHASH       0x00000100  /* oper can rehash             */
#define OPER_FLAG_ADMIN        0x00000200  /* oper can set umode +a       */
#define OPER_FLAG_OPERWALL     0x00000800  /* oper can use OPERWALL       */
#define OPER_FLAG_HIDDEN_OPER  0x00001000  /* oper is hidden              */
#define OPER_FLAG_HIDDEN_ADMIN 0x00002000  /* admin is hidden             */
#define OPER_FLAG_REMOTEBAN    0x00004000  /* allow remote bans           */
#define OPER_FLAG_ENCRYPTED    0x00008000  /* password is encrypted       */

#define SetOperFlags(x,f)       ((x)->localClient->operflags |= (f))
#define ClearOperFlags(x)       ((x)->localClient->operflags = 0)
#define IsOperGlobalKill(x)     (MyConnect(x) ? (x)->localClient->operflags & OPER_FLAG_GLOBAL_KILL : 0)
#define IsOperRemote(x)         (MyConnect(x) ? (x)->localClient->operflags & OPER_FLAG_REMOTE : 0)
#define IsOperUnkline(x)        (MyConnect(x) ? (x)->localClient->operflags & OPER_FLAG_UNKLINE : 0)
#define IsOperGline(x)          (MyConnect(x) ? (x)->localClient->operflags & OPER_FLAG_GLINE : 0)
#define IsOperN(x)              (MyConnect(x) ? (x)->localClient->operflags & OPER_FLAG_N : 0)
#define IsOperK(x)              (MyConnect(x) ? (x)->localClient->operflags & OPER_FLAG_K : 0)
#define IsOperDie(x)            (MyConnect(x) ? (x)->localClient->operflags & OPER_FLAG_DIE : 0)
#define IsOperRehash(x)         (MyConnect(x) ? (x)->localClient->operflags & OPER_FLAG_REHASH : 0)
#define IsOperAdmin(x)          (MyConnect(x) ? (x)->localClient->operflags & OPER_FLAG_ADMIN : 0)
#define IsOperHiddenAdmin(x)    (MyConnect(x) ? (x)->localClient->operflags & OPER_FLAG_HIDDEN_ADMIN : 0)
#define IsOperX(x)              (MyConnect(x) ? (x)->localClient->operflags & OPER_FLAG_X : 0)
#define IsOperWall(x)           (MyConnect(x) ? (x)->localClient->operflags & OPER_FLAG_OPERWALL : 0)
#define IsOperRemoteBan(x)      (MyConnect(x) ? (x)->localClient->operflags & OPER_FLAG_REMOTEBAN : 0)
#define IsOperHidden(x)         (MyConnect(x) ? (x)->localClient->operflags & OPER_FLAG_HIDDEN_OPER : 0)

struct Client;

EXTERN dlink_list oper_confs;
EXTERN FlagMap oper_flag_map;

EXTERN char *oper_privs_as_string(int);
EXTERN struct OperatorConf *find_operconf(const char *, const char *,
  const char *, const struct irc_ssaddr *);
EXTERN void report_oper(struct Client *);

#ifdef IN_CONF_C
void init_operator(void);
#endif
