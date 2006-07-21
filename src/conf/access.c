/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  access.c: Common code for user@host access control blocks.
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
#include "send.h"

struct AccessConf *atable[ATABLE_SIZE] = {0};
struct Callback *cb_expire_confs = NULL;
uint64_t curprec = ~0;

static dlink_node *hreset;
static struct
{
  const char *name;
  ACB_FREE_HANDLER *free;
} acb_types[MAX_ACB_TYPES] = {{0}};

/*
 * hash_ipv4()
 *
 * Hash algorithm for IPv4.
 *
 * inputs: the IP address
 * output: hash value
 */
static unsigned int
hash_ipv4(const struct irc_ssaddr *addr, int bits)
{
  if (bits != 0)
  {
    const struct sockaddr_in *v4 = (const struct sockaddr_in *) addr;
    unsigned int av = ntohl(v4->sin_addr.s_addr) & ~((1 << (32 - bits)) - 1);

    return (av ^ (av >> 12) ^ (av >> 24)) % ATABLE_SIZE;
  }

  return 0;
}

/*
 * hash_ipv6()
 *
 * Hash algorithm for IPv6.
 *
 * inputs: the IP address
 * output: hash value
 */
#ifdef IPV6
static unsigned int
hash_ipv6(const struct irc_ssaddr *addr, int bits)
{
  const struct sockaddr_in6 *v6 = (const struct sockaddr_in6 *) addr;
  unsigned int av = 0, n;

  for (n = 0; n < 16; n++)
    if (bits >= 8)
    {
      av ^= v6->sin6_addr.s6_addr[n];
      bits -= 8;
    }
    else
    {
      if (bits > 0)
        av ^= v6->sin6_addr.s6_addr[n] & ~((1 << (8 - bits)) - 1);
      break;
    }

  return av % ATABLE_SIZE;
}
#endif

/*
 * hash_hostmask()
 *
 * Calculates the hash value for a given hostmask.
 *
 * inputs:
 *   p     -  the hostname to hash
 *   addr  -  where to store mask info
 * output: hash value
 */
static unsigned int
hash_hostmask(const char *p, struct irc_ssaddr *addr)
{
  int bits;
  unsigned int hv;
  const char *seg;

  switch (parse_netmask(p, addr, &bits))
  {
    case HM_IPV4:
      hv = hash_ipv4(addr, bits - bits % 8);
      break;
#ifdef IPV6
    case HM_IPV6:
      hv = hash_ipv6(addr, bits - bits % 16);
      break;
#endif
    default:
      //
      // Choose the longest domain substring which contains no wildcards.
      // This way hash value will be as precise as possible.
      //
      for (seg = p; *p; p++)
        if (*p == '.' && !seg)
          seg = p + 1;
        else if (IsMWildChar(*p))
          seg = NULL;

      hv = seg ? hash_text(seg, ATABLE_SIZE) : 0;
  }

  addr->ss_port = (in_port_t) bits;

  return hv;
}

/*
 * add_access_conf()
 *
 * Adds an AccessConf entry to the hash table.
 *
 * inputs: pointer to AccessConf struct
 * output: none
 */
void
add_access_conf(struct AccessConf *conf)
{
  unsigned int hv = hash_hostmask(conf->host, &conf->ip);

  conf->precedence = curprec--;
  conf->hnext = atable[hv];
  atable[hv] = conf;
}

/*
 * destroy_access_conf()
 *
 * Deletes an AccessConf entry from the hash table and frees its memory.
 *
 * inputs: pointer to AccessConf struct
 * output: none
 */
void
destroy_access_conf(struct AccessConf *conf)
{
  struct irc_ssaddr addr;
  unsigned int hv = hash_hostmask(conf->host, &addr);
  struct AccessConf *prev;

  if (conf == atable[hv])
    atable[hv] = conf->hnext;
  else
  {
    for (prev = atable[hv]; prev->hnext != conf; prev = prev->hnext)
      assert(prev->type >= 0);  // let it core if not found
    prev->hnext = conf->hnext;
  }

  acb_types[conf->type].free(conf);
}

/*
 * acb_generic_free()
 *
 * Generic free procedure for ACB's.
 *
 * inputs: pointer to AccessConf struct
 * output: none
 */
void
acb_generic_free(struct AccessConf *conf)
{
  MyFree(conf->user);
  MyFree(conf->host);
  MyFree(conf);
}

/*
 * enum_access_confs()
 *
 * Enumerates all AccessConfs.  Calls the supplied routine on each one,
 * if 1 is returned then this one is deleted and freed.
 * Any number of AccessConfs can be deleted by this function.
 *
 * inputs: pointer to checking routine
 * output: none
 */
void
enum_access_confs(ACB_EXAMINE_HANDLER *examine, void *param)
{
  unsigned int hv;
  struct AccessConf *prev, *conf;

  for (hv = 0; hv < ATABLE_SIZE; hv++)
    for (prev = NULL, conf = atable[hv]; conf != NULL;
         conf = (prev ? prev->hnext : atable[hv]))
    {
      assert(conf->type >= 0);
      if (examine(conf, param))
      {
        if (prev != NULL)
          prev->hnext = conf->hnext;
        else
          atable[hv] = conf->hnext;

        acb_types[conf->type].free(conf);
      }
      else
        prev = conf;
    }
}

static int is_acb_permanent(struct AccessConf *conf, void *unused)
{
  return !conf->expires;
}

static int is_acb_expired(struct AccessConf *conf, void *unused)
{
  if (conf->expires && conf->expires <= CurrentTime)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL,
      "Temporary %s for [%s@%s] expired",
      acb_types[conf->type].name, conf->user, conf->host);
    return YES;
  }

  return NO;
}

static int is_acb_orphaned(struct AccessConf *conf, void *unused)
{
  return !acb_types[conf->type].name;
}

/*
 * register_acb_type()
 *
 * Allocates a unique value for AccessConf.type field to be used by modules.
 *
 * inputs: pointer to routine which frees a conf entry of this type
 * output: requested value
 */
int
register_acb_type(const char *name, void *fh)
{
  int i;

  assert(name != NULL);
  assert(fh != NULL);

  for (i = 0; i < MAX_ACB_TYPES; i++)
    if (acb_types[i].name == NULL)
    {
      acb_types[i].name = name;
      acb_types[i].free = (ACB_FREE_HANDLER *) fh;
      return i;
    }

  return -1;
}

/*
 * unregister_acb_type()
 *
 * Deallocates an AccessConf.type specifier.
 *
 * inputs: type value
 * output: none
 */
void
unregister_acb_type(int id)
{
  acb_types[id].name = NULL;
  acb_types[id].free = NULL;
  enum_access_confs(is_acb_orphaned, NULL);
}

/*
 * reset_access()
 *
 * Deletes all non-expiring ACB's before a rehash.
 *
 * inputs: none
 * output: none
 */
static void *
reset_access(va_list args)
{
  enum_access_confs(is_acb_permanent, NULL);
  return pass_callback(hreset);
}

/*
 * find_access_conf()
 *
 * Looks for an access conf matching given criteria.
 *
 * inputs:
 *   type  -  only check confs of this type
 *   user  -  if non-NULL, limit to confs matching given username
 *   host  -  limit to confs matching given hostname...
 *   ip    -  ...or IP address (either host or ip must be non-NULL)
 *   func  -  function which verifies additional criteria, can be NULL
 * output: pointer to struct AccessConf or NULL if not found
 */
struct AccessConf *
find_access_conf(int type, const char *user, const char *host,
                 const struct irc_ssaddr *ip, ACB_EXAMINE_HANDLER *func,
                 void *param)
{
  struct AccessConf *conf, *best = NULL;
  int bits;

  if (ip != NULL)
    if (ip->ss.sin_family == AF_INET)
      for (bits = 32; bits >= 0; bits -= 8)
        for (conf = atable[hash_ipv4(ip, bits)]; conf; conf = conf->hnext)
          if ((best == NULL || conf->precedence > best->precedence) &&
              conf->type == type && match_ipv4(ip, &conf->ip, conf->ip.ss_port)
              && (EmptyString(user) || match(conf->user, user)) &&
              (!func || func(conf, param)))
            best = conf;
#ifdef IPV6
    else if (ip->ss.sin_family == AF_INET6)
      for (bits = 128; bits >= 0; bits -= 16)
        for (conf = atable[hash_ipv6(ip, bits)]; conf; conf = conf->hnext)
          if ((best == NULL || conf->precedence > best->precedence) &&
              conf->type == type && match_ipv6(ip, &conf->ip, conf->ip.ss_port)
              && (EmptyString(user) || match(conf->user, user)) &&
              (!func || func(conf, param)))
            best = conf;
#endif

  if (host != NULL)
    while (1)
    {
      for (conf = atable[hash_text(host, ATABLE_SIZE)]; conf; conf = conf->hnext)
        if ((best == NULL || conf->precedence > best->precedence) &&
            conf->type == type && match(conf->host, host) &&
            (EmptyString(user) || match(conf->user, user)) &&
            (!func || func(conf, param)))
          best = conf;

      if (*host)
        do {
          if (*host++ == '.')
            break;
        }
        while (*host);
      else
        break;
    }

  return best;
}

/*
 * expire_confs()
 *
 * Called periodically to remove expired conf entries.
 *
 * inputs: none
 * output: none
 */
static void
expire_confs(void *unused)
{
  enum_access_confs(is_acb_expired, NULL);
  execute_callback(cb_expire_confs);
}

/*
 * init_access()
 *
 * Initializes ACB's support.
 *
 * inputs: none
 * output: none
 */
void
init_access(void)
{
  hreset = install_hook(reset_conf, reset_access);

  cb_expire_confs = register_callback(NULL, NULL);
  eventAddIsh("expire_confs", expire_confs, NULL, EXPIRE_FREQUENCY);
}
