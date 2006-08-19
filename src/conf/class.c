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
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "s_serv.h"

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

static void destroy_cidr_list(dlink_list *);

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
enum_classes(ENUMCLASSFUNC ef, void *param)
{
  dlink_node *ptr;

  DLINK_FOREACH_SAFE(ptr, enum_node, class_list.head)
    ef(ptr->data, param);
}

//
// Class limits tracking.
//

static int
cidr_limit_reached(int exempt, struct irc_ssaddr *ip, struct Class *aclass)
{
  dlink_node *ptr = NULL;
  struct CidrItem *cidr;

  if (aclass->number_per_cidr <= 0)
    return 0;

  if (ip->ss.sin_family == AF_INET)
  {
    if (aclass->cidr_bitlen_ipv4 <= 0)
      return 0;

    DLINK_FOREACH(ptr, aclass->list_ipv4.head)
    {
      cidr = ptr->data;
      if (match_ipv4(ip, &cidr->mask, aclass->cidr_bitlen_ipv4))
      {
        if (!exempt && cidr->number_on_this_cidr >= aclass->number_per_cidr)
          return -1;
        cidr->number_on_this_cidr++;
        return 0;
      }
    }

    cidr = MyMalloc(sizeof(struct CidrItem));
    cidr->number_on_this_cidr = 1;
    cidr->mask = *ip;
    mask_addr(&cidr->mask, aclass->cidr_bitlen_ipv4);
    dlinkAdd(cidr, &cidr->node, &aclass->list_ipv4);
  }
#ifdef IPV6
  else if (aclass->cidr_bitlen_ipv6 > 0)
  {
    DLINK_FOREACH(ptr, aclass->list_ipv6.head)
    {
      cidr = ptr->data;
      if (match_ipv6(ip, &cidr->mask, aclass->cidr_bitlen_ipv6))
      {
        if (!exempt && cidr->number_on_this_cidr >= aclass->number_per_cidr)
          return -1;
        cidr->number_on_this_cidr++;
        return 0;
      }
    }

    cidr = MyMalloc(sizeof(struct CidrItem));
    cidr->number_on_this_cidr = 1;
    cidr->mask = *ip;
    mask_addr(&cidr->mask, aclass->cidr_bitlen_ipv6);
    dlinkAdd(cidr, &cidr->node, &aclass->list_ipv6);
  }
#endif

  return 0;
}

static void
remove_from_cidr_check(struct irc_ssaddr *ip, struct Class *aclass)
{
  dlink_node *ptr = NULL;
  dlink_node *next_ptr = NULL;
  struct CidrItem *cidr;

  if (aclass->number_per_cidr <= 0)
    return;

  if (ip->ss.sin_family == AF_INET)
  {
    if (aclass->cidr_bitlen_ipv4 <= 0)
      return;

    DLINK_FOREACH_SAFE(ptr, next_ptr, aclass->list_ipv4.head)
    {
      cidr = ptr->data;
      if (match_ipv4(ip, &cidr->mask, aclass->cidr_bitlen_ipv4))
      {
        cidr->number_on_this_cidr--;
        if (cidr->number_on_this_cidr == 0)
        {
          dlinkDelete(ptr, &aclass->list_ipv4);
          MyFree(cidr);
          return;
        }
      }
    }
  }
#ifdef IPV6
  else if (aclass->cidr_bitlen_ipv6 > 0)
    DLINK_FOREACH_SAFE(ptr, next_ptr, aclass->list_ipv6.head)
    {
      cidr = ptr->data;
      if (match_ipv6(ip, &cidr->mask, aclass->cidr_bitlen_ipv6))
      {
        cidr->number_on_this_cidr--;
        if (cidr->number_on_this_cidr == 0)
        {
          dlinkDelete(ptr, &aclass->list_ipv6);
          MyFree(cidr);
          return;
        }
      }
    }
#endif
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

static void
rebuild_cidr_list(int aftype, struct Class *oldcl, struct Class *newcl,
                  dlink_list *old_list, dlink_list *new_list, int changed)
{
  dlink_node *ptr;
  struct Client *client_p;

  if (!changed)
  {
    *new_list = *old_list;
    old_list->head = old_list->tail = NULL;
    old_list->length = 0;
    return;
  }

  DLINK_FOREACH(ptr, local_client_list.head)
  {
    client_p = ptr->data;
    if (client_p->localClient->aftype != aftype)
      continue;
    if (client_p->localClient->class == NULL)
      continue;

    if (client_p->localClient->class == oldcl)
      cidr_limit_reached(1, &client_p->localClient->ip, newcl);
  }
}

static void
rebuild_cidr_class(struct Class *old_class, struct Class *new_class)
{
  if (old_class->number_per_cidr > 0 && new_class->number_per_cidr > 0)
  {
    if (old_class->cidr_bitlen_ipv4 > 0 && new_class->cidr_bitlen_ipv4 > 0)
      rebuild_cidr_list(AF_INET, old_class, new_class,
                        &old_class->list_ipv4, &new_class->list_ipv4,
                        old_class->cidr_bitlen_ipv4 !=
                        new_class->cidr_bitlen_ipv4);

#ifdef IPV6
    if (old_class->cidr_bitlen_ipv6 > 0 && new_class->cidr_bitlen_ipv6 > 0)
      rebuild_cidr_list(AF_INET6, old_class, new_class,
                        &old_class->list_ipv6, &new_class->list_ipv6,
                        old_class->cidr_bitlen_ipv6 !=
                        new_class->cidr_bitlen_ipv6);
#endif
  }

  destroy_cidr_list(&old_class->list_ipv4);
  destroy_cidr_list(&old_class->list_ipv6);
}

void
detach_class(struct Client *source_p)
{
  struct Class *cptr = source_p->localClient->class;

  if (IsAddedCidr(source_p))
  {
    remove_from_cidr_check(&source_p->localClient->ip, cptr);
    ClearAddedCidr(source_p);
  }

  cptr->cur_clients--;
  unref_class(source_p->localClient->class);

  source_p->localClient->class = default_class;
}

int
attach_class(struct Client *source_p, struct Class *cptr)
{
  int exempt = !!IsExemptLimits(source_p);
  int a_limit_reached = 0;

  detach_class(source_p);

  source_p->localClient->class = ref_class_by_ptr(cptr);
  if (++cptr->cur_clients > cptr->max_number)
    a_limit_reached++;

  if (!cidr_limit_reached(exempt, &source_p->localClient->ip, cptr))
    SetAddedCidr(source_p);
  else
    a_limit_reached++;

  return a_limit_reached * (1 - exempt * 2);
}

//
// Configuration manager interface.
//

static void do_reset_class(struct Class *cl, void *unused)
{
  if (cl != default_class)
    cl->stale = YES;
}

static void do_verify_class(struct Class *cl, void *unused)
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

  enum_classes(do_reset_class, NULL);
  return pass_callback(hreset);
}

static void *
verify_classes(va_list args)
{
  enum_classes(do_verify_class, NULL);
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
    rebuild_cidr_class(cl, &tmpclass);
  }

  cl->connectfreq = tmpclass.connectfreq;
  cl->ping_time = tmpclass.ping_time;
  cl->ping_warning = tmpclass.ping_warning;
  cl->sendq_size = tmpclass.sendq_size;

  memcpy(cl->userhost_limit, tmpclass.userhost_limit,
    sizeof(cl->userhost_limit));
  memcpy(cl->host_limit, tmpclass.host_limit, sizeof(cl->host_limit));
  memcpy(cl->noident_limit, tmpclass.noident_limit,
    sizeof(cl->noident_limit));

  cl->number_per_cidr = tmpclass.number_per_cidr;
  cl->cidr_bitlen_ipv4 = tmpclass.cidr_bitlen_ipv4;
  cl->cidr_bitlen_ipv6 = tmpclass.cidr_bitlen_ipv6;
  cl->list_ipv4 = tmpclass.list_ipv4;
  cl->list_ipv6 = tmpclass.list_ipv6;

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

static void
do_report_class(struct Class *c, struct Client *source_p)
{
  sendto_one(source_p, form_str(RPL_STATSYLINE),
             ID_or_name(&me, source_p->from),
             ID_or_name(source_p, source_p->from), 'Y', c->name, c->ping_time,
             c->connectfreq, c->max_number, c->sendq_size, c->cur_clients);
}

void
report_class(struct Client *source_p)
{
  enum_classes((ENUMCLASSFUNC) do_report_class, source_p);
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
  add_conf_field(s, "userhost_limit", CT_LIST, local_or_global_limit,
    &tmpclass.userhost_limit);
  add_conf_field(s, "noident_limit", CT_LIST, local_or_global_limit,
    &tmpclass.noident_limit);

  add_conf_field(s, "number_per_cidr", CT_NUMBER, NULL,
    &tmpclass.number_per_cidr);
  add_conf_field(s, "cidr_bitlen_ipv4", CT_NUMBER, NULL,
    &tmpclass.cidr_bitlen_ipv4);
  add_conf_field(s, "cidr_bitlen_ipv6", CT_NUMBER, NULL,
    &tmpclass.cidr_bitlen_ipv4);

  add_conf_field(s, "max_number", CT_NUMBER, NULL, &tmpclass.max_number);

  // for backwards compatibility only, these names really sucked
  add_conf_field(s, "max_local", CT_NUMBER, NULL,
    &tmpclass.userhost_limit[0]);
  add_conf_field(s, "max_global", CT_NUMBER, NULL,
    &tmpclass.userhost_limit[1]);
  add_conf_field(s, "max_noident", CT_NUMBER, NULL,
    &tmpclass.noident_limit[0]);

  s->after = after_class;

  default_class = make_class("default");
}
