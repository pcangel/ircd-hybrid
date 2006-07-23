/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  serverinfo.c: Defines the serverinfo{} block of ircd.conf.
 *
 *  Copyright (C) 2005 by the Hybrid Development Team.
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
#include "hash.h"
#include "ircd.h"
#include "s_serv.h"
#include "s_user.h"

struct ServerInfoConf ServerInfoX = {0};

static dlink_node *hreset, *hverify;

/*
 * reset_serverinfo()
 *
 * Sets up default values before a rehash.
 *
 * inputs: none
 * output: none
 */
static void *
reset_serverinfo(va_list args)
{
  memset(&ServerInfoX.vhost, 0, sizeof(ServerInfoX.vhost));
#ifdef IPV6
  memset(&ServerInfoX.vhost6, 0, sizeof(ServerInfoX.vhost6));
#endif
  ServerInfoX.hub = NO;
  ServerInfoX.max_clients = 512;

  return pass_callback(hreset);
}

/*
 * verify_serverinfo()
 *
 * Checks if required settings are defined.
 *
 * inputs: none
 * output: none
 */
static void *
verify_serverinfo(va_list args)
{
  char *p;

  if (!me.name[0])
    parse_fatal("name= field missing in serverinfo{} section");

  if (!me.info[0])
    parse_fatal("description= field missing in serverinfo{} section");

  if (ServerInfoX.network_name == NULL)
    parse_fatal("network_name= field missing in serverinfo{} section");

  if ((p = strchr(ServerInfoX.network_name, ' ')) != NULL)
    *p = 0;

  if (ServerInfoX.network_desc == NULL)
    DupString(ServerInfoX.network_desc, ServerInfoX.network_name);

  if (conf_cold && me.id[0])
  {
    hash_add_id(&me);
    memcpy(new_uid, me.id, IRC_MAXSID);
  }

  recalc_fdlimit(NULL);

  if (ServerInfoX.max_clients < MAXCLIENTS_MIN)
  {
    parse_error("MAXCLIENTS=%d too low, setting to %d",
      ServerInfoX.max_clients, MAXCLIENTS_MIN);

    ServerInfoX.max_clients = MAXCLIENTS_MIN;
  }
  else if (ServerInfoX.max_clients > MAXCLIENTS_MAX)
  {
    parse_error("MAXCLIENTS=%d too high, setting to %d",
      ServerInfoX.max_clients, MAXCLIENTS_MAX);

    ServerInfoX.max_clients = MAXCLIENTS_MAX;
  }

  return pass_callback(hverify);
}

static void
si_set_name(void *value, void *unused)
{
  char *name = (char *) value;

  if (strlen(name) > HOSTLEN)
  {
    if (conf_cold)
      parse_fatal("server name too long (max %d)", HOSTLEN);
    else
      parse_error("server name too long (max %d)", HOSTLEN);
  }
  else if (conf_cold)
    strcpy(me.name, name);
  else if (strcmp(me.name, name) != 0)
    parse_error("cannot change server name on rehash");
}

static void
si_set_sid(void *value, void *unused)
{
  char *sid = (char *) value;

  /* XXX */
  if (!IsDigit(sid[0]) || !IsAlNum(sid[1]) || !IsAlNum(sid[2]) || sid[3] != 0)
    parse_error("invalid SID, must match [0-9][0-9A-Z][0-9A-Z]");
  else if (conf_cold)
    strcpy(me.id, sid);
  else if (strcmp(me.id, sid) != 0)
    parse_error("cannot change SID on rehash");
}

static void
si_set_description(void *value, void *unused)
{
  strlcpy(me.info, (char *) value, sizeof(me.info));
}

static void
si_set_vhost(void *value, void *where)
{
  char *addrstr = (char *) value;
  struct irc_ssaddr *dest = (struct irc_ssaddr *) where;
  struct addrinfo hints, *res;

  if (*addrstr == '*')
    return;

  memset(&hints, 0, sizeof(hints));

#ifdef IPV6
  hints.ai_family   = (where == ServerInfoX.vhost6 ? AF_INET6 : AF_INET);
#else
  hints.ai_family   = AF_INET;
#endif
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

  if (irc_getaddrinfo(addrstr, NULL, &hints, &res))
    parse_error("invalid netmask");
  else
  {
    memcpy(dest, res->ai_addr, res->ai_addrlen);
    dest->ss.sin_family = res->ai_family;
    dest->ss_len = res->ai_addrlen;
    irc_freeaddrinfo(res);
  }
}

static void
si_set_rsa_private_key(void *value, void *unused)
{
#ifndef HAVE_LIBCRYPTO
  parse_error("no OpenSSL support");
#else
  BIO *file;

  if (ServerInfoX.rsa_private_key)
  {
    RSA_free(ServerInfoX.rsa_private_key);
    ServerInfoX.rsa_private_key = NULL;
  }

  if ((file = BIO_new_file(value, "r")) == NULL)
  {
    parse_error("file doesn't exist");
    return;
  }

  ServerInfoX.rsa_private_key = (RSA *) PEM_read_bio_RSAPrivateKey(file, NULL,
    0, NULL);

  BIO_set_close(file, BIO_CLOSE);
  BIO_free(file);

  if (!ServerInfoX.rsa_private_key)
    parse_error("key invalid; check key syntax");
  else if (!RSA_check_key(ServerInfoX.rsa_private_key)
  {
    RSA_free(ServerInfoX.rsa_private_key);
    ServerInfoX.rsa_private_key = NULL;
    parse_error("invalid key, ignoring");
  }
  else if (RSA_size(ServerInfoX.rsa_private_key) != 2048/8)
  {
    RSA_free(ServerInfoX.rsa_private_key);
    ServerInfoX.rsa_private_key = NULL;
    parse_error("not a 2048-bit key, ignoring");
  }
#endif
}

static void
si_set_ssl_certificate(void *value, void *unused)
{
#ifndef HAVE_LIBCRYPTO
  parse_error("no OpenSSL support");
#else
  if (!ServerInfoX.rsa_private_key)
    parse_error("put a valid rsa_private_key_file before this line");
  else if (SSL_CTX_use_certificate_file(ServerInfoX.ctx, value,
    SSL_FILETYPE_PEM) <= 0)
    parse_error(ERR_lib_error_string(ERR_get_error()));
  else if (SSL_CTX_use_PrivateKey_file(ServerInfoX.ctx,
    ServerInfoX.rsa_private_key_file, SSL_FILETYPE_PEM) <= 0)
    parse_error(ERR_lib_error_string(ERR_get_error()));
  else if (!SSL_CTX_check_private_key(ServerInfoX.ctx))
    parse_error("RSA private key does not match "
                "the SSL certificate public key");
#endif
}

/*
 * init_serverinfo()
 *
 * Defines the serverhide{} conf section.
 *
 * inputs: none
 * output: none
 */
void
init_serverinfo(void)
{
  struct ConfSection *s = add_conf_section("serverinfo", 2);

  hreset = install_hook(reset_conf, reset_serverinfo);
  hverify = install_hook(verify_conf, verify_serverinfo);

  add_conf_field(s, "name", CT_STRING, si_set_name, NULL);
  add_conf_field(s, "sid", CT_STRING, si_set_sid, NULL);
  add_conf_field(s, "description", CT_STRING, si_set_description, NULL);
  add_conf_field(s, "network_name", CT_STRING, NULL, &ServerInfoX.network_name);
  add_conf_field(s, "network_desc", CT_STRING, NULL, &ServerInfoX.network_desc);
  add_conf_field(s, "hub", CT_BOOL, NULL, &ServerInfoX.hub);
  add_conf_field(s, "vhost", CT_STRING, si_set_vhost, &ServerInfoX.vhost);
#ifdef IPV6
  add_conf_field(s, "vhost6", CT_STRING, si_set_vhost, &ServerInfoX.vhost6);
#endif
  add_conf_field(s, "max_clients", CT_NUMBER, NULL, &ServerInfoX.max_clients);
#ifdef HAVE_LIBCRYPTO
  add_conf_field(s, "rsa_private_key_file", CT_STRING, si_set_rsa_private_key,
    NULL);
  add_conf_field(s, "ssl_certificate_file", CT_STRING, si_set_ssl_certificate,
    NULL);
#endif
}
