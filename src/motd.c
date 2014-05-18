/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2000 Kevin L. Mitchell <klmitch@mit.edu>
 *  Copyright (c) 2013-2014 ircd-hybrid development team
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
 */

/*! \file motd.c
 * \brief Message-of-the-day manipulation implementation.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "ircd.h"
#include "conf.h"
#include "send.h"
#include "numeric.h"
#include "client.h"
#include "irc_string.h"
#include "memory.h"
#include "log.h"
#include "motd.h"
#include "hostmask.h"


/** Global list of messages of the day. */
static struct
{
  struct Motd *local;    /**< Local MOTD. */
  struct Motd *remote;   /**< Remote MOTD. */
  dlink_list other;      /**< MOTDs specified in configuration file. */
  dlink_list cachelist;  /**< List of MotdCache entries. */
} MotdList;


/*! \brief Create a struct Motd and initialize it.
 * \param hostmask Hostmask (or connection class name) to filter on.
 * \param path Path to MOTD file.
 */
static struct Motd *
motd_create(const char *hostmask, const char *path)
{
  struct Motd *tmp = MyCalloc(sizeof(struct Motd));

  if (EmptyString(hostmask))
    tmp->type = MOTD_UNIVERSAL;
  else if (class_find(hostmask, 1))
    tmp->type = MOTD_CLASS;
  else
  {
    switch (parse_netmask(hostmask, &tmp->address, &tmp->addrbits))
    {
      case HM_IPV4:
      tmp->type = MOTD_IPMASKV4;
      break;
#ifdef IPV6
    case HM_IPV6:
      tmp->type = MOTD_IPMASKV6;
      break;
#endif
    default: /* HM_HOST */
      tmp->type = MOTD_HOSTMASK;
      break;
    }
  }

  if (hostmask)
    tmp->hostmask = xstrdup(hostmask);

  tmp->path = xstrdup(path);
  tmp->maxcount = MOTD_MAXLINES;

  return tmp;
}

/*! brief\ This function reads a motd out of a file (if needed) and caches it.
 * If a matching cache entry already exists, reuse it. Otherwise,
 * allocate and populate a new MotdCache for it.
 * \param motd Specification for MOTD file.
 * \return Matching MotdCache entry.
 */
static struct MotdCache *
motd_cache(struct Motd *motd)
{
  FILE *file = NULL;
  struct MotdCache *cache = NULL;
  struct stat sb;
  char line[MOTD_LINESIZE + 2];  /* +2 for \r\n */
  char *tmp = NULL;
  unsigned int i = 0;
  dlink_node *ptr = NULL;

  assert(motd);
  assert(motd->path);

  if (motd->cache)
    return motd->cache;

  /* Try to find it in the list of cached files... */
  DLINK_FOREACH(ptr, MotdList.cachelist.head)
  {
    cache = ptr->data;

    if (!strcmp(cache->path, motd->path) && cache->maxcount == motd->maxcount)
    {
      cache->ref++;  /* Increase reference count... */
      motd->cache = cache;  /* Remember cache... */
      return motd->cache;  /* Return it */
    }
  }

  /* Need the file's modification time */
  if (stat(motd->path, &sb) == -1)
  {
    ilog(LOG_TYPE_IRCD, "Couldn't stat \"%s\": %s", motd->path,
         strerror(errno));
    return 0;
  }

  /* Gotta read in the file, now */
  if ((file = fopen(motd->path, "r")) == NULL)
  {
    ilog(LOG_TYPE_IRCD, "Couldn't open \"%s\": %s", motd->path,
         strerror(errno));
    return 0;
  }

  /* Ok, allocate a structure; we'll realloc later to trim memory */
  cache = MyCalloc(sizeof(struct MotdCache) + (MOTD_LINESIZE * MOTD_MAXLINES));
  cache->ref = 1;
  cache->path = xstrdup(motd->path);
  cache->maxcount = motd->maxcount;
  cache->modtime = *localtime((time_t *)&sb.st_mtime); /* store modtime */

  while (cache->count < cache->maxcount && fgets(line, sizeof(line), file))
  {
    /* Copy over line, stopping when we overflow or hit line end */
    for (tmp = line, i = 0; i < (MOTD_LINESIZE - 1) && *tmp && *tmp != '\r' && *tmp != '\n'; ++tmp, ++i)
      cache->motd[cache->count][i] = *tmp;
    cache->motd[cache->count][i] = '\0';

    cache->count++;
  }

  fclose(file);  /* Close the file */

  /* Trim memory usage a little */
  motd->cache = MyCalloc(sizeof(struct MotdCache) +
                         (MOTD_LINESIZE * cache->count));
  memcpy(motd->cache, cache, sizeof(struct MotdCache) +
         (MOTD_LINESIZE * cache->count));
  MyFree(cache);

  /* Now link it in... */
  dlinkAdd(motd->cache, &motd->cache->node, &MotdList.cachelist);

  return motd->cache;
}

/*! \brief Clear and dereference the Motd::cache element of \a motd.
 * If the MotdCache::ref count goes to zero, free it.
 * \param motd MOTD to uncache.
 */
static void
motd_decache(struct Motd *motd)
{
  struct MotdCache *cache = NULL;

  assert(motd);

  if ((cache = motd->cache) == NULL)  /* We can be called for records with no cache */
    return;

  motd->cache = NULL;  /* Zero the cache */

  if (--cache->ref == 0)  /* Reduce reference count... */
  {
    dlinkDelete(&cache->node, &MotdList.cachelist);
    MyFree(cache->path);  /* Free path info... */
    MyFree(cache);  /* Very simple for a reason... */
  }
}

/*! \brief Deallocate a MOTD structure.
 * If it has cached content, uncache it.
 * \param motd MOTD to destroy.
 */
static void
motd_destroy(struct Motd *motd)
{
  assert(motd);

  if (motd->cache)  /* Drop the cache */
    motd_decache(motd);

  MyFree(motd->path);  /* We always must have a path */
  MyFree(motd->hostmask);
  MyFree(motd);
}

/*! \brief Find the first matching MOTD block for a user.
 * If the user is remote, always use remote MOTD.
 * Otherwise, if there is a hostmask- or class-based MOTD that matches
 * the user, use it.
 * Otherwise, use the local MOTD.
 * \param client_p Client to find MOTD for.
 * \return Pointer to first matching MOTD for the client.
 */
static struct Motd *
motd_lookup(const struct Client *client_p)
{
  dlink_node *ptr = NULL;
  const struct ClassItem *class = NULL;

  assert(client_p);

  if (!MyConnect(client_p))  /* Not my user, always return remote motd */
    return MotdList.remote;

  class = get_class_ptr(&client_p->localClient->confs);
  assert(class);

  /* Check the motd blocks first */
  DLINK_FOREACH(ptr, MotdList.other.head)
  {
    struct Motd *motd = ptr->data;

    switch (motd->type)
    {
      case MOTD_CLASS:
        if (!match(motd->hostmask, class->name))
          return motd;
        break;
      case MOTD_HOSTMASK:
        if (!match(motd->hostmask, client_p->host))
          return motd;
        break;
      case MOTD_IPMASKV4:
          if (client_p->localClient->aftype == AF_INET)
            if (match_ipv4(&client_p->localClient->ip, &motd->address, motd->addrbits))
              return motd;
        break;
#ifdef IPV6
      case MOTD_IPMASKV6:
          if (client_p->localClient->aftype == AF_INET6)
            if (match_ipv6(&client_p->localClient->ip, &motd->address, motd->addrbits))
              return motd;
        break;
#endif
      default: break;
    }
  }

  return MotdList.local;  /* Ok, return the default motd */
}

/*! \brief Send the content of a MotdCache to a user.
 * If \a cache is NULL, simply send ERR_NOMOTD to the client.
 * \param source_p Client to send MOTD to.
 * \param cache MOTD body to send to client.
 */
static void
motd_forward(struct Client *source_p, const struct MotdCache *cache)
{
  if (!cache)  /* No motd to send */
  {
    sendto_one_numeric(source_p, &me, ERR_NOMOTD);
    return;
  }

  /* Send the motd */
  sendto_one_numeric(source_p, &me, RPL_MOTDSTART, me.name);

  for (unsigned int i = 0; i < cache->count; ++i)
    sendto_one_numeric(source_p, &me, RPL_MOTD, cache->motd[i]);
  sendto_one_numeric(source_p, &me, RPL_ENDOFMOTD);
}

/*! \brief Find the MOTD for a client and send it.
 * \param client_p Client being greeted.
 */
void
motd_send(struct Client *client_p)
{
  assert(client_p);

  motd_forward(client_p, motd_cache(motd_lookup(client_p)));
}

/*! \brief Send the signon MOTD to a user.
 * If general::short_motd is true and a matching MOTD exists for the
 * user, direct the client to type /MOTD to read it. Otherwise, call
 * motd_forward() for the user.
 * \param source_p Client that has just connected.
 */
void
motd_signon(struct Client *source_p)
{
  const struct MotdCache *cache = motd_cache(motd_lookup(source_p));

  if (!ConfigFileEntry.short_motd || !cache)
    motd_forward(source_p, cache);
  else
  {
    sendto_one_notice(source_p, &me, ":*** Notice -- motd was last changed at %d/%d/%d %d:%02d",
                      cache->modtime.tm_year + 1900,
                      cache->modtime.tm_mon + 1,
                      cache->modtime.tm_mday,
                      cache->modtime.tm_hour,
                      cache->modtime.tm_min);
    sendto_one_notice(source_p, &me, ":*** Notice -- Please read the motd if you haven't read it");
    sendto_one_numeric(source_p, &me, RPL_MOTDSTART, me.name);
    sendto_one_numeric(source_p, &me, RPL_MOTD,
                       "*** This is the short motd ***");
    sendto_one_numeric(source_p, &me, RPL_ENDOFMOTD);
  }
}

/*! \brief Clear all cached MOTD bodies.
 * The local and remote MOTDs are re-cached immediately.
 */
void
motd_recache(void)
{
  dlink_node *ptr = NULL;

  motd_decache(MotdList.local);  /* Decache local and remote MOTDs */
  motd_decache(MotdList.remote);

  DLINK_FOREACH(ptr, MotdList.other.head)  /* Now all the others */
    motd_decache(ptr->data);

  /* now recache local and remote MOTDs */
  motd_cache(MotdList.local);
  motd_cache(MotdList.remote);
}

/*! \brief Re-cache the local and remote MOTDs.
 * If they already exist, they are deallocated first.
 */
void
motd_init(void)
{
  if (MotdList.local)  /* Destroy old local... */
    motd_destroy(MotdList.local);

  MotdList.local = motd_create(NULL, MPATH);
  motd_cache(MotdList.local);  /* Init local and cache it */

  if (MotdList.remote)  /* Destroy old remote... */
    motd_destroy(MotdList.remote);

  MotdList.remote = motd_create(NULL, MPATH);
  motd_cache(MotdList.remote);  /* Init remote and cache it */
}

/* \brief Add a new MOTD.
 * \param hostmask Hostmask (or connection class name) to send this to.
 * \param path Pathname of file to send.
 */
void
motd_add(const char *hostmask, const char *path)
{
  struct Motd *motd = motd_create(hostmask, path);  /* create the motd */

  dlinkAdd(motd, &motd->node, &MotdList.other);
}

/*! \brief Clear out all MOTDs.
 * Compared to motd_recache(), this destroys all hostmask- or
 * class-based MOTDs rather than simply uncaching them.
 * Re-cache the local and remote MOTDs.
 */
void
motd_clear(void)
{
  dlink_node *ptr = NULL, *ptr_next = NULL;

  motd_decache(MotdList.local);  /* Decache local and remote MOTDs */
  motd_decache(MotdList.remote);

  DLINK_FOREACH_SAFE(ptr, ptr_next, MotdList.other.head)  /* Destroy other MOTDs */
  {
    dlinkDelete(ptr, &MotdList.other);
    motd_destroy(ptr->data);
  }

  /* now recache local and remote MOTDs */
  motd_cache(MotdList.local);
  motd_cache(MotdList.remote);
}

/*! \brief Report list of non-default MOTDs.
 * \param source_p Client requesting statistics.
 */
void
motd_report(struct Client *source_p)
{
  const dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, MotdList.other.head)
  {
    const struct Motd *motd = ptr->data;

    sendto_one_numeric(source_p, &me, RPL_STATSTLINE,
                       motd->hostmask, motd->path);
  }
}

/*! \brief Report MOTD memory usage to a client.
 * \param source_p Client requesting memory usage.
 */
void
motd_memory_count(struct Client *source_p)
{
  const dlink_node *ptr = NULL;
  unsigned int mt  = 0;  /* motd count */
  unsigned int mtc = 0;  /* motd cache count */
  size_t mtm  = 0;  /* memory consumed by motd */
  size_t mtcm = 0;  /* memory consumed by motd cache */

  if (MotdList.local)
  {
    mt++;
    mtm += sizeof(struct Motd);
    mtm += MotdList.local->path ? (strlen(MotdList.local->path) + 1) : 0;
  }

  if (MotdList.remote)
  {
    mt++;
    mtm += sizeof(struct Motd);
    mtm += MotdList.remote->path ? (strlen(MotdList.remote->path) + 1) : 0;
  }

  DLINK_FOREACH(ptr, MotdList.other.head)
  {
    const struct Motd *motd = ptr->data;

    mt++;
    mtm += sizeof(struct Motd);
    mtm += motd->path ? (strlen(motd->path) + 1) : 0;
  }

  DLINK_FOREACH(ptr, MotdList.cachelist.head)
  {
    const struct MotdCache *cache = ptr->data;

    mtc++;
    mtcm += sizeof(struct MotdCache) + (MOTD_LINESIZE * (cache->count - 1));
  }

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "z :Motds %u(%u) Cache %u(%u)",
                     mt, mtm, mtc, mtcm);
}
