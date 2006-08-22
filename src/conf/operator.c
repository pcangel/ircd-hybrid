/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  operator.c: Defines the operator{} block of ircd.conf.
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
#include "ircd_defs.h"
#include "client.h"
#include "numeric.h"
#include "send.h"
#include "s_serv.h"

dlink_list oper_confs = {NULL, NULL, 0};

static dlink_node *hreset;
static struct OperatorConf tmpoper = {0};

// TODO: These should be modularised like acb_types
static const struct FlagMapping {
  char letter;
  const char *name;
  unsigned int flag;
} flag_mappings[] = {
  {'A', "admin", OPER_FLAG_ADMIN},
  {'B', "remoteban", OPER_FLAG_REMOTEBAN},
  {'D', "die", OPER_FLAG_DIE},
  {'G', "gline", OPER_FLAG_GLINE},
  {'H', "rehash", OPER_FLAG_REHASH},
  {'K', "kline", OPER_FLAG_K},
  {'L', "operwall", OPER_FLAG_OPERWALL},
  {'N', "nick_changes", OPER_FLAG_N},
  {'O', "global_kill", OPER_FLAG_GLOBAL_KILL},
  {'R', "remote", OPER_FLAG_REMOTE},
  {'U', "unkline", OPER_FLAG_UNKLINE},
  {'X', "xline", OPER_FLAG_X},
  {0, "hidden_admin", OPER_FLAG_HIDDEN_ADMIN},
  {0, "hidden_oper", OPER_FLAG_HIDDEN_OPER},
  {0, NULL, 0}
};

/*
 * oper_privs_as_string()
 *
 * Translates an integer flags value to a string representation.
 *
 * inputs: flags
 * output: static string
 */
char *
oper_privs_as_string(int flags)
{
  const struct FlagMapping *m;
  static char str[32];
  char *p = str;

  for (m = flag_mappings; m->letter; m++)
    if ((flags & m->flag) != 0)
      *p++ = m->letter;
    else
      *p++ = tolower(m->letter);

  *p = 0;
  return str;
}

/*
 * conf_operator_report()
 *
 * Reports all OperatorConf blocks along with their mask lists.
 *
 * inputs: a client to send to
 * output: none
 */
void
conf_operator_report(struct Client *source_p)
{
  dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, oper_confs.head)
  {
    dlink_node *ptr_mask = NULL;
    struct OperatorConf *conf = ptr->data;

    assert(conf->class_ptr);

    DLINK_FOREACH(ptr_mask, conf->masks.head)
    {
      const struct split_nuh_item *nuh = ptr_mask->data;

      // Don't allow non opers to see oper privs
      sendto_one(source_p, form_str(RPL_STATSOLINE), me.name, source_p->name,
                 'O', nuh->userptr, nuh->hostptr, conf->name,
                 IsOper(source_p) ? oper_privs_as_string(conf->flags) : "0",
                 conf->class_ptr->name);
    }
  }
}

/*
 * clear_operconf()
 *
 * Frees all memory used by fields of a OperatorConf struct.
 *
 * inputs: pointer to operconf
 * output: none
 */
static void
clear_operconf(struct OperatorConf *conf)
{
  dlink_node *ptr, *ptr_next;

  MyFree(conf->name);
  MyFree(conf->passwd);
  conf->name = conf->passwd = NULL;

  DLINK_FOREACH_SAFE(ptr, ptr_next, conf->masks.head)
  {
    struct split_nuh_item *mask = ptr->data;

    dlinkDelete(ptr, &conf->masks);

    MyFree(mask->userptr);
    MyFree(mask->hostptr);
    MyFree(mask);
  }

  if (conf->class_ptr != NULL)
  {
    unref_class(conf->class_ptr);
    conf->class_ptr = NULL;
  }

#ifdef HAVE_LIBCRYPTO
  if (conf->rsa_public_key != NULL)
  {
    RSA_free(conf->rsa_public_key);
    conf->rsa_public_key = NULL;
  }
#endif
}

/*
 * find_operconf()
 *
 * Looks for a OperatorConf struct matching given parameters.
 *
 * inputs:
 *   name  -  operator name
 *   user  -  username to match, can be NULL
 *   host  -  hostname to match, can be NULL
 *   ip    -  IP address to match, can be NULL
 * output: pointer to struct OperatorConf or NULL
 */
struct OperatorConf *
find_operconf(const char *name, const char *user, const char *host,
              const struct irc_ssaddr *ip)
{
  dlink_node *ptr, *ptr_mask;
  struct OperatorConf *conf;
  struct irc_ssaddr ipmask;
  int mbits;

  DLINK_FOREACH(ptr, oper_confs.head)
  {
    conf = ptr->data;
    if (irccmp(conf->name, name))
      continue;

    DLINK_FOREACH(ptr_mask, conf->masks.head)
    {
      struct split_nuh_item *uh = ptr_mask->data;

      if (user && !match(uh->userptr, user))
        continue;

      if (host != NULL || ip != NULL)
      {
        /* We get here once or twice per find_operconf() call,
         * so we can afford this.   -- adx
         */
        switch (parse_netmask(uh->hostptr, &ipmask, &mbits))
        {
          case HM_IPV4: if (!ip || !match_ipv4(ip, &ipmask, mbits))
                          continue;
#ifdef IPV6
          case HM_IPV6: if (!ip || !match_ipv6(ip, &ipmask, mbits))
                          continue;
#endif
          default: if (!host || !match(uh->hostptr, host))
                     continue;
        }
      }

      return conf;
    }
  }

  return NULL;
}

/*
 * reset_operator()
 *
 * Frees all operator{} blocks.  Called on a rehash.
 *
 * inputs: none
 * output: none
 */
static void *
reset_operator(va_list args)
{
  struct OperatorConf *conf;

  while (oper_confs.head != NULL)
  {
    conf = oper_confs.head->data;
    dlinkDelete(&conf->node, &oper_confs);
    clear_operconf(conf);
    MyFree(conf);
  }

  return pass_callback(hreset);
}

/*
 * before_operator()
 *
 * Called before processing a single operator{} block.
 *
 * inputs: none
 * output: none
 */
static void
before_operator(void)
{
  clear_operconf(&tmpoper);
  tmpoper.flags |= OPER_FLAG_ENCRYPTED;
}

/*
 * after_operator()
 *
 * Called after parsing a single operator{} block.
 *
 * inputs: none
 * output: none
 */
static void
after_operator(void)
{
  struct OperatorConf *oper;

  if (tmpoper.class_ptr == NULL)
  {
    parse_error("Invalid or non-existant class in operator{}");
    clear_operconf(&tmpoper);
    return;
  }

  if (tmpoper.name == NULL || dlink_list_length(&tmpoper.masks) == 0 ||
#ifdef HAVE_LIBCRYPTO
      !tmpoper.passwd
#else
      (!tmpoper.passwd && !tmpoper.rsa_public_key)
#endif
     )
  {
    parse_error("Incomplete operator{} block");
    clear_operconf(&tmpoper);
    return;
  }

  oper = MyMalloc(sizeof(struct OperatorConf));

  memcpy(oper, &tmpoper, sizeof(*oper));
  memset(&tmpoper, 0, sizeof(tmpoper));

  dlinkAddTail(oper, &oper->node, &oper_confs);
}

/*
 * oper_encrypted()
 *
 * Parses the "encrypted=" directive.
 *
 * inputs: binary value (given as a pointer)
 * output: none
 */
static void
oper_encrypted(void *value, void *where)
{
  if (*(int *) value)
    tmpoper.flags |= OPER_FLAG_ENCRYPTED;
  else
    tmpoper.flags &= ~OPER_FLAG_ENCRYPTED;
}

/*
 * oper_user()
 *
 * Parses the "user=" directive.
 *
 * inputs: new user@host mask
 * output: none
 */
static void
oper_user(void *value, void *where)
{
  char *str = value;
  char userbuf[USERLEN + 1];
  char hostbuf[HOSTLEN + 1];
  struct split_nuh_item nuh, *cuh;

  nuh.nuhmask  = str;
  nuh.nickptr  = NULL;
  nuh.userptr  = userbuf;
  nuh.hostptr  = hostbuf;

  nuh.nicksize = 0;
  nuh.usersize = sizeof(userbuf);
  nuh.hostsize = sizeof(hostbuf);

  split_nuh(&nuh);

  cuh = MyMalloc(sizeof(*cuh));
  DupString(cuh->userptr, nuh.userptr);
  DupString(cuh->hostptr, nuh.hostptr);

  dlinkAddTail(cuh, &cuh->node, &tmpoper.masks);
}

/*
 * oper_class()
 *
 * Parses the "class=" directive.
 *
 * inputs: class name pointer
 * output: none
 */
static void
oper_class(void *value, void *where)
{
  if (tmpoper.class_ptr != NULL)
    unref_class(tmpoper.class_ptr);

  tmpoper.class_ptr = ref_class_by_name(value);
}

/*
 * oper_rsa_public_key_file()
 *
 * Parses the "rsa_public_key_file=" directive.
 *
 * inputs: file name pointer
 * output: none
 */
static void
oper_rsa_public_key_file(void *value, void *where)
{
#ifndef HAVE_LIBCRYPTO
  parse_error("no OpenSSL support");
#else
  const char *str = value;
  BIO *file = NULL;

  if (tmpoper.rsa_public_key != NULL)
  {
    RSA_free(tmpoper.rsa_public_key);
    tmpoper.rsa_public_key = NULL;
  }

  if ((file = BIO_new_file(str, "r")) == NULL)
  {
    parse_error("file doesn't exist");
    return;
  }

  tmpoper.rsa_public_key = (RSA *)PEM_read_bio_RSA_PUBKEY(file, NULL, 0, NULL);
  if (tmpoper.rsa_public_key == NULL)
    parse_error("key invalid; check key syntax");

  BIO_set_close(file, BIO_CLOSE);
  BIO_free(file);
#endif
}

/*
 * parse_flag_list()
 *
 * Parses a list of oper flags
 *
 * inputs:
 *   list  -  points to a dlink_list of strings to parse
 *   var   -  where to save the result as unsigned int
 * output: none
 */
static void
parse_flag_list(void *list, void *where)
{
  const struct FlagMapping *p;
  int errors = NO;
  dlink_node *ptr;

  tmpoper.flags &= OPER_FLAG_ENCRYPTED;

  DLINK_FOREACH(ptr, ((dlink_list *)list)->head)
  {
    const char *str = ptr->data;
    int found = NO, all = !irccmp(str, "all");

    for (p = flag_mappings; p->name; ++p)
      if (all || !irccmp(str, p->name))
      {
        found = YES;
        if (!all || p->letter)
          tmpoper.flags |= p->flag;
        if (!all || !p->letter)
          break;
      }

    if (!found)
      errors = YES;
  }

  if (errors)
    parse_error("Invalid oper flags encountered, check your syntax");
}

/*
 * report_oper()
 *
 * Sends a /stats O reply to the given client.
 *
 * inputs: client pointer
 * output: none
 */
void
report_oper(struct Client *to)
{
  dlink_node *ptr, *ptr2;
  struct OperatorConf *conf;
  struct split_nuh_item *uh;

  if (General.stats_o_oper_only && !IsOper(to))
    sendto_one(to, form_str(ERR_NOPRIVILEGES), ID_or_name(&me, to->from),
               ID_or_name(to, to->from));
  else
    DLINK_FOREACH(ptr, oper_confs.head)
    {
      conf = ptr->data;
      DLINK_FOREACH(ptr2, conf->masks.head)
      {
        uh = ptr2->data;
        sendto_one(to, form_str(RPL_STATSOLINE), ID_or_name(&me, to->from),
                   ID_or_name(to, to->from), 'O', uh->userptr, uh->hostptr,
                   conf->name, IsOper(to) ? oper_privs_as_string(conf->flags) :
                   "0", conf->class_ptr->name);
      }
    }
}

/*
 * init_operator()
 *
 * Initializes oper{} block support.
 *
 * inputs: none
 * output: none
 */
void
init_operator(void)
{
  const char *alias[] = { "oper", "operator", NULL };
  const char **p = alias;

  hreset = install_hook(reset_conf, reset_operator);

  for (; *p != NULL; ++p)
  {
    struct ConfSection *s = add_conf_section(*p, 2);

    s->before = before_operator;

    s->def_field = add_conf_field(s, "name", CT_STRING, NULL, &tmpoper.name);
    add_conf_field(s, "user", CT_STRING, oper_user, NULL);
    add_conf_field(s, "class", CT_STRING, oper_class, NULL);
    add_conf_field(s, "password", CT_STRING, NULL, &tmpoper.passwd);
    add_conf_field(s, "encrypted", CT_BOOL, oper_encrypted, NULL);
    add_conf_field(s, "rsa_public_keyfile", CT_STRING, oper_rsa_public_key_file, NULL);
    add_conf_field(s, "flags", CT_LIST, parse_flag_list, NULL);

    s->after = after_operator;
  }
}
