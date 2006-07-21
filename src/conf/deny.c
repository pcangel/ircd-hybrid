/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  deny.c: Defines the deny{} block of ircd.conf.
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

static struct DenyConf tmpdeny = {{0}};
static struct AccessConf tmpexempt = {0};
static int acb_type_deny, acb_type_exempt;

/*
 * free_dline()
 *
 * Frees a DenyConf struct.
 *
 * inputs: what to free
 * output: none
 */
static void
free_dline(struct DenyConf *dline)
{
  MyFree(dline->reason);
  acb_generic_free(&dline->access);
}

/*
 * before_deny()
 *
 * Called before parsing a single deny{} block.
 *
 * inputs: none
 * output: none
 */
static void
before_deny(void)
{
  MyFree(tmpdeny.reason);
  MyFree(tmpdeny.access.host);
  memset(&tmpdeny, 0, sizeof(tmpdeny));
  tmpdeny.access.type = acb_type_deny;
}

/*
 * before_exempt()
 *
 * Called before parsing a single exempt{ block.
 *
 * inputs: none
 * output: none
 */
static void
before_exempt(void)
{
  MyFree(tmpexempt.host);
  memset(&tmpexempt, 0, sizeof(tmpexempt));
  tmpexempt.type = acb_type_exempt;
}

/*
 * parse_ip()
 *
 * Parses the "ip=" field.
 *
 * inputs: pointer to a string
 * output: none
 */
static void
parse_ip(void *value, void *where)
{
  struct split_nuh_item uh;
  char hostbuf[HOSTLEN + 1], **s = where;

  uh.nuhmask = value;
  uh.nickptr = uh.userptr = NULL;
  uh.hostptr = hostbuf;

  uh.nicksize = uh.usersize = 0;
  uh.hostsize = sizeof(hostbuf);

  split_nuh(&uh);

  MyFree(*s);
  DupString(*s, hostbuf);
}

/*
 * after_deny()
 *
 * Called after parsing a single deny{} block.
 *
 * inputs: none
 * output: none
 */
static void
after_deny(void)
{
  struct DenyConf *conf;

  if (tmpdeny.access.host == NULL ||
      parse_netmask(tmpdeny.access.host, NULL, NULL) == HM_HOST)
  {
    before_deny();
    return;
  }

  conf = MyMalloc(sizeof(*conf));
  memcpy(conf, &tmpdeny, sizeof(*conf));
  memset(&tmpdeny, 0, sizeof(tmpdeny));
  add_access_conf(&conf->access);
}

/*
 * after_exempt()
 *
 * Called after parsing a single exempt{} block.
 *
 * inputs: none
 * output: none
 */
static void
after_exempt(void)
{
  struct AccessConf *conf;

  if (!tmpexempt.host || parse_netmask(tmpexempt.host, NULL, NULL) == HM_HOST)
  {
    before_exempt();
    return;
  }

  conf = MyMalloc(sizeof(*conf));
  memcpy(conf, &tmpexempt, sizeof(*conf));
  memset(&tmpexempt, 0, sizeof(tmpexempt));
  add_access_conf(conf);
}

/*
 * find_dline()
 *
 * Returns a matching DenyConf.
 *
 * inputs: IP address
 * output: pointer to the conf or NULL if not found
 */
struct DenyConf *
find_dline(const struct irc_ssaddr *ip)
{
  struct DenyConf *conf = (struct DenyConf *) find_access_conf(acb_type_deny,
    NULL, NULL, ip, NULL, NULL);

  if (conf && find_exempt(ip))
    conf = NULL;

  return conf;
}

/*
 * find_exempt()
 *
 * Returns a matching exempt entry.
 *
 * inputs: IP address
 * output: pointer to the conf or NULL if not found
 */
struct AccessConf *
find_exempt(const struct irc_ssaddr *ip)
{
  return find_access_conf(acb_type_exempt, NULL, NULL, ip, NULL, NULL);
}

/*
 * init_deny()
 *
 * Defines the deny{} conf section.
 *
 * inputs: none
 * output: none
 */
void
init_deny(void)
{
  struct ConfSection *s = add_conf_section("deny", 2);
  struct ConfSection *s2 = add_conf_section("exempt", 2);

  acb_type_deny = register_acb_type("D-line", (ACB_FREE_HANDLER *) free_dline);
  acb_type_exempt = register_acb_type("exempt",
    (ACB_FREE_HANDLER *) acb_generic_free);

  s->before = before_deny;
  s2->before = before_exempt;

  s->def_field = add_conf_field(s, "ip", CT_STRING, parse_ip,
    &tmpdeny.access.host);
  s2->def_field = add_conf_field(s, "ip", CT_STRING, parse_ip,
    &tmpexempt.host);
  add_conf_field(s, "reason", CT_STRING, NULL, &tmpdeny.reason);

  s->after = after_deny;
  s2->after = after_exempt;
}
