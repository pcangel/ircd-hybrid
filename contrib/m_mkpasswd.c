/*
 *  m_mkpasswd.c: Encrypts a password online, DES or MD5.
 *
 *  Copyright 2002 W. Campbell and the ircd-hybrid development team
 *  Based on mkpasswd.c, originally by Nelson Minar (minar@reed.edu)
 *
 *  You can use this code in any way as long as these names remain.
 *
 *  $Id$
 */

#include "stdinc.h"
#include "handlers.h"
#include "ircd.h"
#include "numeric.h"
#include "s_conf.h"
#include "s_serv.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "conf/modules.h"

static void m_mkpasswd(struct Client *, struct Client *, int, char *[]);
static const char *m_mkpasswd_des(void);
static const char *m_mkpasswd_md5(void);

static const char saltChars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./";

struct Message mkpasswd_msgtab = {
  "MKPASSWD", 0, 0, 1, 2, MFLG_SLOW, 0,
  { m_unregistered, m_mkpasswd, m_ignore, m_ignore, m_mkpasswd, m_ignore }
};

INIT_MODULE(m_mkpasswd, "$Revision$")
{
  mod_add_cmd(&mkpasswd_msgtab);
}

CLEANUP_MODULE
{
  mod_del_cmd(&mkpasswd_msgtab);
}

static void
m_mkpasswd(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  static time_t last_used = 0;

  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "MKPASSWD");
    return;
  }

  if (!IsOper(source_p))
  {
    if ((last_used + ConfigFileEntry.pace_wait) > CurrentTime)
    {
      sendto_one(source_p, form_str(RPL_LOAD2HI),
                 me.name, source_p->name);
      return;
    }

    last_used = CurrentTime;
  }

  if (parv[2] == NULL || !irccmp(parv[2], "DES"))
    sendto_one(source_p, ":%s NOTICE %s :DES Encryption for [%s]: %s",
               me.name, source_p->name, parv[1], crypt(parv[1],
               m_mkpasswd_des()));
  else if (!irccmp(parv[2], "MD5"))
    sendto_one(source_p, ":%s NOTICE %s :MD5 Encryption for [%s]: %s",
               me.name, source_p->name, parv[1], crypt(parv[1],
               m_mkpasswd_md5()));
  else
    sendto_one(source_p, ":%s NOTICE %s :Syntax: MKPASSWD pass [DES|MD5]",
               me.name, source_p->name);
}

static const char *
m_mkpasswd_des(void)
{
  static char salt[3];

  salt[0] = saltChars[rand() % 64];
  salt[1] = saltChars[rand() % 64];
  salt[2] = '\0';

  return salt;
}

static const char *
m_mkpasswd_md5(void)
{
  static char salt[13];
  int i;

  salt[0] = '$';
  salt[1] = '1';
  salt[2] = '$';

  for (i = 3; i < 11; ++i)
    salt[i] = saltChars[rand() % 64];

  salt[11] = '$';
  salt[12] = '\0';

  return salt;
}
