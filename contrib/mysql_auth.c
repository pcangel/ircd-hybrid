#define USERNAME_LEN   32
#define PASSWORD_LEN   32
#define MYSQL_SERVER   "localhost"
#define MYSQL_USER     "ircd"
#define MYSQL_PASSWORD "somepass"
#define MYSQL_DATABASE "ircd"
#define MYSQL_QUERY1   "SELECT uid,class FROM uids WHERE username = '%s' AND password = '%s'"
#define MYSQL_QUERY2   "SELECT username FROM uids WHERE uid = '%s'"

/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  mysql_auth.c: Allows users to authorize against a MySQL db.
 *
 *  Copyright (C) 2005 by the past and present ircd coders, and others.
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
#include "client.h"
#include "common.h"
#include "hash.h"
#include "send.h"
#include "user.h"
#include "server.h"
#include "/usr/local/include/mysql/mysql.h"

static MYSQL *mysql;
static dlink_node *h_auth, *h_uid;
static char buffer[IRCD_BUFSIZE];

static void *my_authorize_client(va_list);
static void *my_uid_get(va_list);

INIT_MODULE(mysql_auth, "$Revision$")
{
  h_uid = install_hook(uid_get, my_uid_get);
  h_auth = install_hook(authorize_client, my_authorize_client);

  mysql = mysql_init(NULL);

  if (!mysql_real_connect(
    mysql,
    MYSQL_SERVER,
    MYSQL_USER,
    MYSQL_PASSWORD,
    MYSQL_DATABASE,
    0,
    NULL,
    0
  ))
  {
    ilog(L_CRIT, "Cannot connect to MySQL");
    sendto_realops_flags(UMODE_ALL, L_ALL, "Cannot connect to MySQL");
  }
}

CLEANUP_MODULE
{
  mysql_close(mysql);

  uninstall_hook(authorize_client, my_authorize_client);
  uninstall_hook(uid_get, my_uid_get);
}

/*
 * uid_is_registered()
 *
 * Checks if the generated UID is registered.
 *
 * inputs: pointer to UID string
 * output: YES/NO
 */
static int
uid_is_registered(const char *uid)
{
  int len = strlen(uid);
  char uid_esc[TOTALSIDUID*2 + 1];
  MYSQL_RES *res;

  if (len > TOTALSIDUID)
    len = TOTALSIDUID;
  mysql_real_escape_string(mysql, uid_esc, uid, len);

  len = snprintf(buffer, sizeof(buffer), MYSQL_QUERY2, uid_esc);

  if (mysql_real_query(mysql, buffer, len) != 0)
    return NO;

  res = mysql_store_result(mysql);
  len = mysql_num_rows(res);
  mysql_free_result(res);

  return len ? YES : NO;
}

/*
 * my_authorize_client()
 *
 * Overrides the normal auth{} lookup.
 *
 * inputs:
 *   source_p  -  pointer to struct Client
 *   username  -  new client's username
 * output: referenced class pointer or NULL, if the client's been exited
 */
static void *
my_authorize_client(va_list args)
{
  struct Class *cl = NULL;
  struct Client *source_p = va_arg(args, struct Client *);
  const char *username = va_arg(args, const char *);
  char *user = source_p->localClient->passwd;
  char *pass;

  // Client password should be in format user:pass

  if (user != NULL && (pass = strchr(user, ':')) != NULL)
  {
    char user_esc[USERNAME_LEN*2 + 1];
    char pass_esc[PASSWORD_LEN*2 + 1];
    int len;
    MYSQL_RES *res;

    *pass++ = 0;

    len = strlen(user);
    if (len > USERNAME_LEN)
      len = USERNAME_LEN;
    mysql_real_escape_string(mysql, user_esc, user, len);

    len = strlen(pass);
    if (len > PASSWORD_LEN)
      len = PASSWORD_LEN;
    mysql_real_escape_string(mysql, pass_esc, pass, len);

    // leave localClient->password unmodified, it is used by ircd sometimes
    *--pass = ':';

    len = snprintf(buffer, sizeof(buffer), MYSQL_QUERY1, user_esc, pass_esc);
    if (mysql_real_query(mysql, buffer, len) != 0)
    {
      ilog(L_ERROR, "MySQL query failed for %s",
           get_client_name(source_p, HIDE_IP));
      return pass_callback(h_auth, source_p, username);
    }

    res = mysql_store_result(mysql);

    if (mysql_num_rows(res) > 0)
    {
      struct Client *cptr;
      MYSQL_ROW row = mysql_fetch_row(res);

      strlcpy(buffer, row[0], TOTALSIDUID+1);
      cl = ref_class_by_name(row[1]);
      mysql_free_result(res);

      if (buffer[0])
      {
        // Got the UID, this means the user owns it.

        if ((cptr = hash_find_id(buffer)) != NULL)
          exit_client(cptr, &me, "Overridden");

        strlcpy(source_p->id, buffer, sizeof(source_p->id));
      }
    }

    mysql_free_result(res);

    if (cl != NULL)
      return cl;
  }

  // Nothing found, so use standard rules

  return pass_callback(h_auth, source_p, username);
}

/*
 * my_uid_get()
 *
 * Overrides the plain UID generation routine.
 *
 * inputs: pointer to struct Client
 * output: the generated UID
 */
static void *
my_uid_get(va_list args)
{
  struct Client *source_p = va_arg(args, struct Client *);
  char *uid;

  if (source_p->id[0])
    return source_p->id;

  while (uid_is_registered(uid = pass_callback(h_uid, source_p)))
    ;  // loop

  return uid;
}
