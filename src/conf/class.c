/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  class.c: Defines the class{} block of ircd.conf.
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

struct CidrItem
{
  struct irc_ssaddr mask;
  int number_on_this_cidr;
  dlink_node node;
};

struct Class *default_class = NULL;
dlink_list class_list = {NULL, NULL, 0};

static dlink_node *enum_node = NULL;
static dlink_node *hreset, *hverify;
static struct Class tmpclass;

//
// Low configuration layer: object storage and reference counting.
//

struct Class *
ref_class_by_name(const char *name)
{
  dlink_node *ptr;

  DLINK_FOREACH(ptr, class_list.head)
  {
    struct Class *cl = ptr->data;

    if (!strcasecmp(cl->name, name))
      return ref_class_by_ptr(cl);
  }

  return NULL;
}

struct Class *
ref_class_by_ptr(struct Class *cl)
{
  if (cl != default_class)
    cl->refcnt++;
  return cl;
}

static void
destroy_cidr_list(dlink_list *l)
{
  while (l->head != NULL)
  {
    struct CidrItem *cidr = l->head->data;

    dlinkDelete(&cidr->node, l);
    MyFree(cidr);
  }
}

void
unref_class(struct Class *cl)
{
  if (cl == default_class)
    return;

  assert(cl->refcnt > 0);

  if (--cl->refcnt == 0)
  {
    destroy_cidr_list(&cl->list_ipv4);
    destroy_cidr_list(&cl->list_ipv6);
    MyFree(cl);
  }
}

struct Class *
make_class(const char *name)
{
  struct Class *cl = MyMalloc(sizeof(struct Class));

  DupString(cl->name, name);

  ref_class_by_ptr(cl);
  dlinkAddTail(cl, &cl->node, &class_list);

  return cl;
}

void
delete_class(struct Class *cl)
{
  if (&cl->node == enum_node)
    enum_node = cl->node.next;

  dlinkDelete(&cl->node, &class_list);
  unref_class(cl);
}

void
enum_classes(ENUMCLASSFUNC ef)
{
  dlink_node *ptr;

  DLINK_FOREACH_SAFE(ptr, enum_node, class_list.head)
    ef(ptr->data);
}

//
// TODO: Class matching and assigning (limits!)
//

//
// Configuration manager interface.
//

static void do_reset_class(struct Class *cl)
{
  if (cl != default_class)
    cl->stale = YES;
}

static void do_verify_class(struct Class *cl)
{
  if (cl->stale)
    delete_class(cl);
}

static void *
reset_classes(va_list args)
{
  default_class->connectfreq = DEFAULT_CONNECTFREQUENCY;
  default_class->ping_time = DEFAULT_PINGFREQUENCY;
  default_class->max_number = MAXIMUM_LINKS_DEFAULT;
  default_class->sendq_size = DEFAULT_SENDQ;

  enum_classes(do_reset_class);
  return pass_callback(hreset);
}

static void *
verify_classes(va_list args)
{
  enum_classes(do_verify_class);
  return pass_callback(hverify);
}

static void
before_class(void)
{
  memset(&tmpclass, 0, sizeof(tmpclass));
}

static void
after_class(void)
{
  struct Class *cl;

  if (tmpclass.name == NULL)
    return;

  if ((cl = ref_class_by_name(tmpclass.name)) == NULL)
  {
    cl = make_class(tmpclass.name);
    MyFree(tmpclass.name);
  }
  else
  {
    cl->name = tmpclass.name;
    unref_class(cl);
  }

  cl->connectfreq = tmpclass.connectfreq;
  cl->ping_time = tmpclass.ping_time;
  cl->ping_warning = tmpclass.ping_warning;
  cl->sendq_size = tmpclass.sendq_size;

  memcpy(cl->userhost_limit, tmpclass.userhost_limit,
    sizeof(cl->userhost_limit));
  memcpy(cl->host_limit, tmpclass.host_limit, sizeof(cl->host_limit));

  // TODO: number per cidr stuff ..

  cl->max_ident = tmpclass.max_ident;
  cl->max_noident = tmpclass.max_noident;
  cl->max_number = tmpclass.max_number;

  cl->stale = NO;
}

static void
local_or_global_limit(void *value, void *where)
{
  dlink_list *list = value;
  dlink_node *ptr;

  DLINK_FOREACH(ptr, list->head)
  {
    char *item = ptr->data, *s;
    int type = 0;  // assume local

    if ((s = strchr(item, ':')) != NULL)
    {
      *s++ = 0;
      if (!strcasecmp(item, "global"))
        type = 1;
      else if (strcasecmp(item, "local"))
      {
        parse_error("unknown limit type [%s]", item);
        return;
      }
    }
    else
      s = item;

    *(((int *) where) + type) = atoi(s);
  }
}

void
init_class(void)
{
  struct ConfSection *s = add_conf_section("class", 1);

  hreset = install_hook(reset_conf, reset_classes);
  hverify = install_hook(verify_conf, verify_classes);

  s->before = before_class;

  s->def_field = add_conf_field(s, "name", CT_STRING, NULL, &tmpclass.name);
  add_conf_field(s, "connectfreq", CT_TIME, NULL, &tmpclass.connectfreq);
  add_conf_field(s, "ping_time", CT_TIME, NULL, &tmpclass.ping_time);
  add_conf_field(s, "ping_warning", CT_TIME, NULL, &tmpclass.ping_warning);
  add_conf_field(s, "sendq", CT_SIZE, NULL, &tmpclass.sendq_size);

  add_conf_field(s, "host_limit", CT_LIST, local_or_global_limit,
    &tmpclass.host_limit);
  add_conf_field(s, "number_per_ip", CT_NUMBER, local_or_global_limit,
    &tmpclass.host_limit);
  add_conf_field(s, "userhost_limit", CT_LIST, local_or_global_limit,
    &tmpclass.userhost_limit);
  add_conf_field(s, "number_per_userhost", CT_NUMBER, local_or_global_limit,
    &tmpclass.userhost_limit);

  add_conf_field(s, "number_per_cidr", CT_NUMBER, NULL,
    &tmpclass.number_per_cidr);
  add_conf_field(s, "cidr_bitlen_ipv4", CT_NUMBER, NULL,
    &tmpclass.cidr_bitlen_ipv4);
  add_conf_field(s, "cidr_bitlen_ipv6", CT_NUMBER, NULL,
    &tmpclass.cidr_bitlen_ipv4);

  add_conf_field(s, "max_ident", CT_NUMBER, NULL, &tmpclass.max_ident);
  add_conf_field(s, "max_noident", CT_NUMBER, NULL, &tmpclass.max_noident);
  add_conf_field(s, "max_number", CT_NUMBER, NULL, &tmpclass.max_number);

  // for backwards compatibility only, these names really sucked
  add_conf_field(s, "max_local", CT_NUMBER, NULL,
    &tmpclass.userhost_limit[0]);
  add_conf_field(s, "max_global", CT_NUMBER, NULL,
    &tmpclass.userhost_limit[1]);

  s->after = after_class;

  default_class = make_class("default");
}
