/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  connect.c: Defines the connect{} block of ircd.conf.
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

#include "stdinc.h"
#include "conf/conf.h"
#include "client.h"
#include "numeric.h"
#include "send.h"
#include "server.h"

dlink_list connect_confs = {0};

static dlink_node *hreset;
static struct ConnectConf tmpconn = {0};

FlagMap connect_flag_map =
{
  {0, "compressed", LINK_COMPRESSED},
  {0, "cryptlink", LINK_CRYPTLINK},
  {0, "encrypted", LINK_CRYPTPWD},
  {0, "autoconn", LINK_AUTOCONN},
  {0, "burst_away", LINK_BURSTAWAY},
  {0, "topicburst", LINK_TOPICBURST},
  {0, NULL, 0}
};

/*
 * free_interior()
 *
 * Frees all memory allocated by a connect entry,
 * except the ConnectConf struct itself.
 *
 * inputs: pointer to the conf
 * output: none
 */
static void
free_interior(struct ConnectConf *conf)
{
  MyFree(conf->name);
  MyFree(conf->host);
  MyFree(conf->allow_host);
  MyFree(conf->send_password);
  MyFree(conf->accept_password);
  MyFree(conf->fakename);

  if (conf->class_ptr)
    unref_class(conf->class_ptr);

  while (conf->hub_list.head)
  {
    dlink_node *ptr = conf->hub_list.head;
    MyFree(ptr->data);
    dlinkDelete(ptr, &conf->hub_list);
    free_dlink_node(ptr);
  }

  while (conf->leaf_list.head)
  {
    dlink_node *ptr = conf->leaf_list.head;
    MyFree(ptr->data);
    dlinkDelete(ptr, &conf->leaf_list);
    free_dlink_node(ptr);
  }

#ifdef HAVE_LIBCRYPTO
  if (conf->rsa_public_key)
    RSA_free(conf->rsa_public_key);
#endif
}

static void
clear_temp(void)
{
  free_interior(&tmpconn);
  memset(&tmpconn, 0, sizeof(tmpconn));
  tmpconn.aftype = AF_INET;
}

/*
 * ref_link_by_name()
 * ref_link_by_host()
 *
 * Finds and references a connect conf.
 *
 * inputs: link name
 * output: pointer to ConnectConf
 */
struct ConnectConf *
ref_link_by_name(const char *name)
{
  dlink_node *ptr;
  struct ConnectConf *conf;

  DLINK_FOREACH(ptr, connect_confs.head)
  {
    conf = ptr->data;
    if (match(name, conf->name))
      return ref_link_by_ptr(conf);
  }

  return NULL;
}

struct ConnectConf *
ref_link_by_host(const char *name)
{
  dlink_node *ptr;
  struct ConnectConf *conf;

  DLINK_FOREACH(ptr, connect_confs.head)
  {
    conf = ptr->data;
    if (!irccmp(conf->host, name))
      return ref_link_by_ptr(conf);
  }

  return NULL;
}

/*
 * ref_link_by_ptr()
 *
 * Increments the reference counter of a connect conf.
 *
 * inputs: pointer to ConnectConf
 * output: the same pointer
 */
struct ConnectConf *
ref_link_by_ptr(struct ConnectConf *conf)
{
  conf->refcnt++;
  return conf;
}

/*
 * unref_link()
 *
 * Decrements the reference counter of a connect conf.
 * When it reaches zero, the conf gets freed.
 *
 * inputs: pointer to ConnectConf
 * output: none
 */
void
unref_link(struct ConnectConf *conf)
{
  assert(conf->refcnt > 0);

  if (!--conf->refcnt)
  {
    free_interior(conf);
    MyFree(conf);
  }
}

/*
 * reset_connect()
 *
 * Sets up default values before a rehash.
 *
 * inputs: none
 * output: none
 */
static void *
reset_connect(va_list args)
{
  while (connect_confs.head)
  {
    struct ConnectConf *conf = connect_confs.head->data;
    dlinkDelete(&conf->node, &connect_confs);
    unref_link(conf);
  }

  return pass_callback(hreset);
}

/*
 * parse_aftype()
 *
 * Parses the "aftype=" field.
 *
 * inputs: pointer to a dlink list of strings
 * output: none
 */
static void
parse_aftype(void *plist, void *unused)
{
  dlink_list *list = plist;

  if (dlink_list_length(list) != 1)
  {
    err: parse_error("Syntax error");
    return;
  }

  if (!irccmp(list->head->data, "ipv4"))
    tmpconn.aftype = AF_INET;
#ifdef IPV6
  else if (!irccmp(list->head->data, "ipv6"))
    tmpconn.aftype = AF_INET6;
#endif
  else
    goto err;
}

/*
 * parse_vhost()
 *
 * Parses the "vhost=" field.
 *
 * inputs: vhost IP string
 * output: none
 */
static void
parse_vhost(void *ipstr, void *unused)
{
  struct addrinfo hints, *res;

  memset(&hints, 0, sizeof(hints));

  hints.ai_family   = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

  if (irc_getaddrinfo(ipstr, NULL, &hints, &res))
    parse_error("Invalid netmask for server vhost(%s)", ipstr);
  else
  {
    memcpy(&tmpconn.vhost, res->ai_addr, res->ai_addrlen);
    tmpconn.vhost.ss.sin_family = res->ai_family;
    tmpconn.vhost.ss_len = res->ai_addrlen;
    irc_freeaddrinfo(res);
  }
}

/*
 * parse_password()
 *
 * Parses a password field.
 *
 * inputs:
 *   ppwd    -  password string
 *   pwhere  -  where to store it (or NULL for both send_ and accept_password)
 * output: none
 */
static void
parse_password(void *ppwd, void *pwhere)
{
  char *pwd = ppwd;
  char **where = pwhere;

  if (pwd[0] == ':')
    parse_error("Server passwords cannot begin with a colon");
  else if (strchr(pwd, ' '))
    parse_error("Server passwords cannot contain spaces");
  else if (where)
  {
    MyFree(*where);
    DupString(*where, pwd);
  }
  else
  {
    MyFree(tmpconn.send_password);
    MyFree(tmpconn.accept_password);
    DupString(tmpconn.send_password, pwd);
    DupString(tmpconn.accept_password, pwd);
  }
}

/*
 * parse_class()
 *
 * Parses the "class=" field.
 *
 * inputs: pointer to class name
 * output: none
 */
static void
parse_class(void *name, void *unused)
{
  if (tmpconn.class_ptr)
    unref_class(tmpconn.class_ptr);

  tmpconn.class_ptr = ref_class_by_name(name);
}

/*
 * parse_mask()
 *
 * Parses a hub_mask/leaf_mask field.
 *
 * inputs:
 *   pmask  -  pointer to server name mask
 *   plist  -  where to add it
 * output: none
 */
static void
parse_mask(void *pmask, void *plist)
{
  char *mask;
  dlink_node *ptr = make_dlink_node();

  DupString(mask, pmask);
  dlinkAdd(mask, ptr, (dlink_list *) plist);
}

/*
 * parse_rsa_pkfile()
 *
 * Parses the "rsa_public_key_file=" field.
 *
 * inputs: pointer to the file name
 * output: none
 */
static void
parse_rsa_pkfile(void *value, void *unused)
{
#ifndef HAVE_LIBCRYPTO
  parse_error("no OpenSSL support");
#else
  const char *str = value;
  BIO *file = NULL;

  if (tmpconn.rsa_public_key != NULL)
  {
    RSA_free(tmpconn.rsa_public_key);
    tmpconn.rsa_public_key = NULL;
  }

  if ((file = BIO_new_file(str, "r")) == NULL)
  {
    parse_error("file doesn't exist");
    return;
  }

  tmpconn.rsa_public_key = (RSA*) PEM_read_bio_RSA_PUBKEY(file, NULL, 0, NULL);
  if (tmpconn.rsa_public_key == NULL)
    parse_error("key invalid; check key syntax");

  BIO_set_close(file, BIO_CLOSE);
  BIO_free(file);
#endif
}

/*
 * parse_cipherpref()
 *
 * Parses the "cipher_preference=" field.
 *
 * inputs: pointer to a cipher name
 * output: none
 */
static void
parse_cipherpref(void *value, void *unused)
{
#ifndef HAVE_LIBCRYPTO
  parse_error("no OpenSSL support");
#else
  struct EncCapability *ecap;

  tmpconn.cipher_preference = NULL;

  for (ecap = CipherTable; ecap->name; ecap++)
    if (!irccmp(ecap->name, value) && (ecap->cap & CAP_ENC_MASK))
    {
      tmpconn.cipher_preference = ecap;
      break;
    }

  if (!tmpconn.cipher_preference)
    parse_error("invalid cipher");
#endif
}

/*
 * parse_flags()
 *
 * Handles "flags=" list.
 *
 * inputs: pointer to a dlink_list of flag names
 * output: none
 */
static void
parse_flags(void *list, void *unused)
{
  const struct FlagMapping *p;
  int errors = NO;
  dlink_node *ptr;

  DLINK_FOREACH(ptr, ((dlink_list *) list)->head)
  {
    const char *str = ptr->data;
    int found = NO;

    for (p = connect_flag_map; p->flag; ++p)
      if (p->name && !irccmp(str, p->name))
      {
        found = YES;
        tmpconn.flags |= p->flag;
        break;
      }

    if (!found)
      errors = YES;
  }

  if (errors)
    parse_error("Invalid connect flags encountered, check your syntax");
}

/*
 * after_connect()
 *
 * Called after parsing a single connect{} block.
 *
 * inputs: none
 * output: none
 */
static void
after_connect(void)
{
  struct ConnectConf *conf;

  if (!tmpconn.name || !tmpconn.class_ptr ||
      (!tmpconn.send_password &&
#ifdef HAVE_LIBCRYPTO
       !tmpconn.accept_password && !tmpconn.rsa_public_key))
#else
       !tmpconn.accept_password))
#endif
  {
    parse_error("Incomplete connect{} block");
    clear_temp();
    return;
  }

  if (!tmpconn.host)
    DupString(tmpconn.host, tmpconn.name);

  conf = MyMalloc(sizeof(*conf));
  memcpy(conf, &tmpconn, sizeof(*conf));
  dlinkAdd(conf, &conf->node, &connect_confs);
  ref_link_by_ptr(conf);

  memset(&tmpconn, 0, sizeof(tmpconn));
}

/*
 * report_connect()
 *
 * Sends a /stats C reply to the given client.
 *
 * inputs: client pointer
 * output: none
 */
void
report_connect(struct Client *source_p)
{
  dlink_node *ptr;

  DLINK_FOREACH(ptr, connect_confs.head)
  {
    char buf[12] = "*", *p = buf;
    struct ConnectConf *conf = ptr->data;

    if ((conf->flags & LINK_AUTOCONN))
      *p++ = 'A';
    if ((conf->flags & LINK_CRYPTLINK))
      *p++ = 'C';
    if (conf->fakename)
      *p++ = 'M';
    if ((conf->flags & LINK_TOPICBURST))
      *p++ = 'T';
    if ((conf->flags & LINK_COMPRESSED))
      *p++ = 'Z';
    if (p > buf)
      *p = 0;

    sendto_one(source_p, form_str(RPL_STATSCLINE),
               ID_or_name(&me, source_p->from),
               ID_or_name(source_p, source_p->from), 'C',
               (!ServerHide.hide_server_ips && IsAdmin(source_p)) ?
               conf->host : "255.255.255.255", buf, conf->name, conf->port,
               conf->class_ptr->name);
  }
}

/*
 * report_hubleaf()
 *
 * Sends a /stats H reply to the given client.
 *
 * inputs: client pointer
 * output: none
 */
void
report_hubleaf(struct Client *to)
{
  dlink_node *ptr, *ptr2;
  struct ConnectConf *conf;

  DLINK_FOREACH(ptr, connect_confs.head)
  {
    conf = ptr->data;
    DLINK_FOREACH(ptr2, conf->hub_list.head)
      sendto_one(to, form_str(RPL_STATSHLINE), ID_or_name(&me, to->from),
                 ID_or_name(to, to->from), 'H', ptr2->data, conf->name, 0, "*");
  }

  DLINK_FOREACH(ptr, connect_confs.head)
  {
    conf = ptr->data;
    DLINK_FOREACH(ptr2, conf->leaf_list.head)
      sendto_one(to, form_str(RPL_STATSLLINE), ID_or_name(&me, to->from),
                 ID_or_name(to, to->from), 'L', ptr2->data, conf->name, 0, "*");
  }
}

/*
 * init_connect()
 *
 * Defines the connect{} conf section.
 *
 * inputs: none
 * output: none
 */
void
init_connect(void)
{
  struct ConfSection *s = add_conf_section("connect", 2);
  struct FlagSet *set = MyMalloc(sizeof(struct FlagSet));
  struct FlagMapping *f;

  hreset = install_hook(reset_conf, reset_connect);

  s->before = clear_temp;

  s->def_field = add_conf_field(s, "name", CT_STRING, NULL, &tmpconn.name);
  add_conf_field(s, "host", CT_STRING, NULL, &tmpconn.host);
  add_conf_field(s, "aftype", CT_LIST, parse_aftype, NULL);
  add_conf_field(s, "port", CT_NUMBER, NULL, &tmpconn.port);
  add_conf_field(s, "allow_host", CT_STRING, NULL, &tmpconn.allow_host);
  add_conf_field(s, "vhost", CT_STRING, parse_vhost, NULL);
  add_conf_field(s, "send_password", CT_STRING, parse_password,
    &tmpconn.send_password);
  add_conf_field(s, "accept_password", CT_STRING, parse_password,
    &tmpconn.accept_password);
  add_conf_field(s, "password", CT_STRING, parse_password, NULL);
  add_conf_field(s, "fakename", CT_STRING, NULL, &tmpconn.fakename);
  add_conf_field(s, "class", CT_STRING, parse_class, NULL);
  add_conf_field(s, "hub_mask", CT_STRING, parse_mask, &tmpconn.hub_list);
  add_conf_field(s, "leaf_mask", CT_STRING, parse_mask, &tmpconn.leaf_list);
  add_conf_field(s, "rsa_public_key_file", CT_STRING, parse_rsa_pkfile, NULL);
  add_conf_field(s, "cipher_preference", CT_STRING, parse_cipherpref, NULL);
  add_conf_field(s, "flags", CT_LIST, parse_flags, NULL);
  for(f = connect_flag_map; f->name != NULL; f++)
  {
    set->map = connect_flag_map;
    set->field = &tmpconn.flags;
    add_conf_field(s, f->name, CT_FLAG,  NULL, set);
  }

  s->after = after_connect;
}
