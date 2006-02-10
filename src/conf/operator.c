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


static dlink_node *hreset = NULL;
static struct AccessItem tmpoper;

static const struct FlagMapping {
  const char *name;
  unsigned int flags;
} flag_mappings[] = {
  {"global_kill", OPER_FLAG_GLOBAL_KILL},
  {"remote", OPER_FLAG_REMOTE},
  {"remoteban", OPER_FLAG_REMOTEBAN},
  {"kline", OPER_FLAG_K},
  {"unkline", OPER_FLAG_UNKLINE},
  {"gline", OPER_FLAG_GLINE},
  {"xline", OPER_FLAG_X},
  {"operwall", OPER_FLAG_OPERWALL},
  {"nick_changes", OPER_FLAG_N},
  {"rehash", OPER_FLAG_REHASH},
  {"die", OPER_FLAG_DIE},
  {"admin", OPER_FLAG_ADMIN},
  {"hidden_admin", OPER_FLAG_HIDDEN_ADMIN},
  {"hidden_oper", OPER_FLAG_HIDDEN_OPER},
  { NULL, 0 }
};

void
conf_operator_report(struct Client *source_p)
{
  dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, oconf_items.head)
  {
    dlink_node *ptr_mask = NULL;
    struct ConfItem *conf = ptr->data;
    struct AccessItem *aconf = &conf->conf.AccessItem;
    assert(aconf->class_ptr);

    DLINK_FOREACH(ptr_mask, conf->mask_list.head)
    {
      const struct split_nuh_item *nuh = ptr_mask->data;

      /* Don't allow non opers to see oper privs */
      if (IsOper(source_p))
        sendto_one(source_p, form_str(RPL_STATSOLINE), me.name,
                   source_p->name, 'O', nuh->userptr, nuh->hostptr,
                   conf->name, oper_privs_as_string(aconf->port),
                   aconf->class_ptr->name);
      else
        sendto_one(source_p, form_str(RPL_STATSOLINE),
                   me.name, source_p->name, 'O', nuh->userptr, nuh->hostptr,
                   conf->name, "0",
                   aconf->class_ptr->name);
      }
    }
  }
}

static void
reset_operator(void)
{
  dlink_node *ptr = NULL, *ptr_next = NULL;

  DLINK_FOREACH_SAFE(ptr, ptr_next, oconf_items.head)
    delete_conf_item(ptr->data);
}

static void
before_operator(void)
{
  memset(&tmpoper, 0, sizeof(tmpoper));

  SetConfEncrypted(&tmpoper.conf->AccessItem);
}

static void
after_operator(void)
{
  struct ConfItem *oper = NULL;
  struct AccessItem *yy_tmp = &tmpoper.conf->AccessItem;

  if (tmpoper.name == NULL ||
      yy_tmp->host == NULL ||
      yy_tmp->user == NULL)
    return;

  if (&tmpoper.conf->AccessItem->class_ptr == NULL)
  {
    parse_error("Invalid or non-existant class in operator{}");
    return;
  }

  if (!yy_tmp->passwd && !yy_aconf->rsa_public_key)
    return;

  oper = make_conf_item(OPER_TYPE);

  /* XXX Temporary hack until we changed make_conf_item() so it doesn't add
   * newly created items onto doubly linked lists immediately after creation */
  &tmpoper.node->head = oper->node.head;
  &tmpoper.node->tail = oper->node.tail;
  &tmpoper.node->data = oper->node.data;

  memcpy(oper, &tmpoper, sizeof(*oper));
}

static void
oper_encrypted(void *value, void *where)
{

  if (*(int *)value)
    SetConfEncrypted(&tmpoper.conf->AccessItem);
  else
    ClearConfEncrypted(&tmpoper.conf->AccessItem);
}

static void
oper_user(void *value, *void where)
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

  dlinkAdd(cuh, &cuh->node, &tmpoper.conf->AccessItem->mask_list);
}

static void
operator_class(void *value, void *where)
{
  tmpoper.conf->AccessItem->class_ptr = find_class(value);
}

static void
oper_rsa_public_key_file(void *value, void *where)
{
  const char *str = value;
  struct AccessItem *yy_tmp = &tmpoper.conf->AccessItem;
  BIO *file = NULL;

  if (yy_aconf->rsa_public_key != NULL)
  {
    RSA_free(yy_aconf->rsa_public_key);
    yy_aconf->rsa_public_key = NULL;
  }

  if (yy_aconf->rsa_public_key_file != NULL)
  {
    MyFree(yy_aconf->rsa_public_key_file);
    yy_aconf->rsa_public_key_file = NULL;
  }

  DupString(yy_aconf->rsa_public_key_file, str);
  file = BIO_new_file(str, "r");

  if (file == NULL)
  {
    parse_error("Ignoring rsa_public_key_file -- file doesn't exist");
    return;
  }

  yy_aconf->rsa_public_key = (RSA *)PEM_read_bio_RSA_PUBKEY(file, NULL, 0, NULL);

  if (yy_aconf->rsa_public_key == NULL)
  {
    parse_error("Ignoring rsa_public_key_file -- Key invalid; check key syntax.");
    return;
  }

  BIO_set_close(file, BIO_CLOSE);
  BIO_free(file);
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
  dlink_node *ptr;
  unsigned int flags = 0;
  int found;
  struct FlagMapping *p;

  DLINK_FOREACH(ptr, ((dlink_list *)list)->head)
  {
    const char *str = ptr->data;

    found = 0;
    for (p = flags_mappings; p->name; ++p)
    {
      if (!irccmp(str, p->name))
      {
        flags |= p->flag;
        found = YES;
        break;
      }
    }

    if (!found)
      parse_error("Unknown flag [%s]", str);
  }

  &tmpoper.conf->AccessItem->port = flags;
}

void
init_operator(void)
{
  const char *alias[] = { "oper", "operator", NULL };
  const char *p = alias;

  hreset = install_hook(reset_conf, reset_operator);

  for (; p != NULL; ++p)
  {
    struct ConfSection *s = add_conf_section(p, 2);

    s->before = before_operator;

    add_conf_field(s, "name", CT_STRING, NULL, &tmpoper.name);
    add_conf_field(s, "user", CT_STRING, oper_user, NULL);
    add_conf_field(s, "class", CT_STRING, oper_class, NULL);
    add_conf_field(s, "password", CT_STRING, NULL, &tmpoper.conf->AccessItem->password);
    add_conf_field(s, "encrypted", CT_BOOL, oper_encrypted, NULL);
    add_conf_field(s, "rsa_public_keyfile", CT_STRING, oper_rsa_public_key_file, NULL);
    add_conf_field(s, "flags", CT_LIST, parse_flag_list, NULL);

    s->after = after_operator;
  }
}
