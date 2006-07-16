/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  hostmask.c: Code to efficiently find IP & hostmask based configs.
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
#include "ircd_defs.h"
#include "s_conf.h"
#include "hostmask.h"
#include "numeric.h"
#include "send.h"

#ifdef IPV6
static unsigned long hash_ipv6(const struct irc_ssaddr *, int);
#endif
static unsigned long hash_ipv4(const struct irc_ssaddr *, int);

/* Hashtable stuff...now external as its used in m_stats.c */
struct AddressRec *atable[ATABLE_SIZE];

void
init_host_hash(void)
{
  memset(&atable, 0, sizeof(atable));
}

/* unsigned long hash_ipv4(struct irc_ssaddr*)
 * Input: An IP address.
 * Output: A hash value of the IP address.
 * Side effects: None
 */
static unsigned long
hash_ipv4(const struct irc_ssaddr *addr, int bits)
{
  if (bits != 0)
  {
    const struct sockaddr_in *v4 = (const struct sockaddr_in *)addr;
    unsigned long av = ntohl(v4->sin_addr.s_addr) & ~((1 << (32 - bits)) - 1);

    return (av ^ (av >> 12) ^ (av >> 24)) & (ATABLE_SIZE - 1);
  }

  return 0;
}

/* unsigned long hash_ipv6(struct irc_ssaddr*)
 * Input: An IP address.
 * Output: A hash value of the IP address.
 * Side effects: None
 */
#ifdef IPV6
static unsigned long
hash_ipv6(const struct irc_ssaddr *addr, int bits)
{
  unsigned long v = 0, n;
  const struct sockaddr_in6 *v6 = (const struct sockaddr_in6 *)addr;
  
  for (n = 0; n < 16; ++n)
  {
    if (bits >= 8)
    {
      v ^= v6->sin6_addr.s6_addr[n];
      bits -= 8;
    }
    else if (bits)
    {
      v ^= v6->sin6_addr.s6_addr[n] & ~((1 << (8 - bits)) - 1);
      return v & (ATABLE_SIZE - 1);
    }
    else
      return v & (ATABLE_SIZE - 1);
  }

  return v & (ATABLE_SIZE - 1);
}
#endif

/* int hash_text(const char *start)
 * Input: The start of the text to hash.
 * Output: The hash of the string between 1 and (TH_MAX-1)
 * Side-effects: None.
 */
static int
hash_text(const char *start)
{
  const char *p = start;
  unsigned long h = 0;

  for (; *p; ++p)
    h = (h << 4) - (h + ToLower(*p));

  return h & (ATABLE_SIZE - 1);
}

/* unsigned long get_hash_mask(const char *)
 * Input: The text to hash.
 * Output: The hash of the string right of the first '.' past the last
 *         wildcard in the string.
 * Side-effects: None.
 */
static unsigned long
get_mask_hash(const char *text)
{
  const char *hp = "", *p;

  for (p = text + strlen(text) - 1; p >= text; p--)
    if (*p == '*' || *p == '?')
      return hash_text(hp);
    else if (*p == '.')
      hp = p + 1;
  return hash_text(text);
}

/* struct AccessItem *find_conf_by_address(const char *, struct irc_ssaddr *,
 *                                         int type, int fam, const char *username)
 * Input: The hostname, the address, the type of mask to find, the address
 *        family, the username.
 * Output: The matching value with the highest precedence.
 * Side-effects: None
 * Note: Setting bit 0 of the type means that the username is ignored.
 * Warning: IsNeedPassword for everything that is not an auth{} entry
 * should always be true (i.e. aconf->flags & CONF_FLAGS_NEED_PASSWORD == 0)
 */
struct AccessItem *
find_conf_by_address(const char *name, const struct irc_ssaddr *addr, int type,
                     int fam, const char *username, const char *password)
{
  unsigned long hprecv = 0;
  struct AccessItem *hprec = NULL;
  struct AddressRec *arec;
  int b;

  if (username == NULL)
    username = "";
  if (password == NULL)
    password = "";

  if (addr)
  {
    /* Check for IPV6 matches... */
#ifdef IPV6
    if (fam == AF_INET6)
    {
      for (b = 128; b >= 0; b -= 16)
      {
        for (arec = atable[hash_ipv6(addr, b)]; arec; arec = arec->next)
          if (arec->type == (type & ~0x1) &&
              arec->precedence > hprecv &&
              arec->masktype == HM_IPV6 &&
              match_ipv6(addr, &arec->Mask.ipa.addr, arec->Mask.ipa.bits) &&
              (type & 0x1 || match(arec->username, username)) &&
              (IsNeedPassword(arec->aconf) || arec->aconf->passwd == NULL ||
	           match_password(password, arec->aconf->passwd,
                              arec->aconf->flags & CONF_FLAGS_ENCRYPTED)))
          {
            hprecv = arec->precedence;
            hprec = arec->aconf;
          }
      }
    }
    else
#endif
    if (fam == AF_INET)
    {
      for (b = 32; b >= 0; b -= 8)
      {
        for (arec = atable[hash_ipv4(addr, b)]; arec; arec = arec->next)
          if (arec->type == (type & ~0x1) &&
              arec->precedence > hprecv &&
              arec->masktype == HM_IPV4 &&
              match_ipv4(addr, &arec->Mask.ipa.addr, arec->Mask.ipa.bits) &&
              (type & 0x1 || match(arec->username, username)) &&
              (IsNeedPassword(arec->aconf) || arec->aconf->passwd == NULL ||
               match_password(password, arec->aconf->passwd,
                              arec->aconf->flags & CONF_FLAGS_ENCRYPTED)))
          {
            hprecv = arec->precedence;
            hprec = arec->aconf;
          }
      }
    }
  }

  if (name != NULL)
  {
    const char *p = name;

    while (1)
    {
      for (arec = atable[hash_text(p)]; arec != NULL; arec = arec->next)
        if ((arec->type == (type & ~0x1)) &&
            arec->precedence > hprecv &&
            (arec->masktype == HM_HOST) &&
            match(arec->Mask.hostname, name) &&
            (type & 0x1 || match(arec->username, username)) &&
            (IsNeedPassword(arec->aconf) || arec->aconf->passwd == NULL ||
             match_password(password, arec->aconf->passwd,
                            arec->aconf->flags & CONF_FLAGS_ENCRYPTED)))
        {
          hprecv = arec->precedence;
          hprec = arec->aconf;
        }
      p = strchr(p, '.');
      if (p == NULL)
        break;
      p++;
    }
    for (arec = atable[0]; arec; arec = arec->next)
      if (arec->type == (type & ~0x1) &&
          arec->precedence > hprecv &&
          arec->masktype == HM_HOST &&
          match(arec->Mask.hostname, name) &&
          (type & 0x1 || match(arec->username, username)) &&
          (IsNeedPassword(arec->aconf) || arec->aconf->passwd == NULL ||
           match_password(password, arec->aconf->passwd,
                          arec->aconf->flags & CONF_FLAGS_ENCRYPTED)))
      {
        hprecv = arec->precedence;
        hprec = arec->aconf;
      }
  }

  return hprec;
}

/* struct AccessItem* find_address_conf(const char*, const char*,
 * 	                               struct irc_ssaddr*, int, char *);
 * Input: The hostname, username, address, address family.
 * Output: The applicable AccessItem.
 * Side-effects: None
 */
struct AccessItem *
find_address_conf(const char *host, const char *user,
                  struct irc_ssaddr *ip, int aftype, char *password)
{
  struct AccessItem *iconf, *kconf;

  /* Find the best I-line... If none, return NULL -A1kmm */
  if ((iconf = find_conf_by_address(host, ip, CONF_CLIENT, aftype, user,
                                    password)) == NULL)
    return(NULL);

  /* If they are exempt from K-lines, return the best I-line. -A1kmm */
  if (IsConfExemptKline(iconf))
    return(iconf);

  /* Find the best K-line... -A1kmm */
  kconf = find_conf_by_address(host, ip, CONF_KILL, aftype, user, NULL);

  /* If they are K-lined, return the K-line. Otherwise, return the
   * I-line. -A1kmm */
  if (kconf != NULL)
    return(kconf);

  kconf = find_conf_by_address(host, ip, CONF_GLINE, aftype, user, NULL);
  if (kconf != NULL && !IsConfExemptGline(iconf))
    return(kconf);

  return(iconf);
}

struct AccessItem *
find_gline_conf(const char *host, const char *user,
                struct irc_ssaddr *ip, int aftype)
{
  struct AccessItem *eline;

  eline = find_conf_by_address(host, ip, CONF_EXEMPTKLINE, aftype,
                               user, NULL);
  if (eline != NULL)
    return(eline);

  return(find_conf_by_address(host, ip, CONF_GLINE, aftype, user, NULL));
}

/* find_kline_conf
 *
 * inputs	- pointer to hostname
 *		- pointer to username
 *		- incoming IP and type (IPv4 vs. IPv6)
 * outut	- pointer to kline conf if found NULL if not
 * side effects	-
 */
struct AccessItem *
find_kline_conf(const char *host, const char *user,
		struct irc_ssaddr *ip, int aftype)
{
  struct AccessItem *eline;

  eline = find_conf_by_address(host, ip, CONF_EXEMPTKLINE, aftype,
                               user, NULL);
  if (eline != NULL)
    return(eline);

  return(find_conf_by_address(host, ip, CONF_KILL, aftype, user, NULL));
}

/* struct AccessItem* find_dline_conf(struct irc_ssaddr*, int)
 *
 * Input:	An address, an address family.
 * Output:	The best matching D-line or exempt line.
 * Side effects: None.
 */
struct AccessItem *
find_dline_conf(const struct irc_ssaddr *addr, int aftype)
{
  struct AccessItem *eline;

  eline = find_conf_by_address(NULL, addr, CONF_EXEMPTDLINE | 1, aftype,
                               NULL, NULL);
  if (eline != NULL)
    return(eline);
  return(find_conf_by_address(NULL, addr, CONF_DLINE | 1, aftype, NULL, NULL));
}

/* void add_conf_by_address(int, struct AccessItem *aconf)
 * Input: 
 * Output: None
 * Side-effects: Adds this entry to the hash table.
 */
void
add_conf_by_address(int type, struct AccessItem *aconf)
{
  const char *address;
  const char *username;
  static unsigned long prec_value = 0xFFFFFFFF;
  int masktype, bits;
  unsigned long hv;
  struct AddressRec *arec;

  address = aconf->host;
  username = aconf->user;

  assert(type != 0); 
  assert(aconf != NULL);

  if (EmptyString(address))
    address = "/NOMATCH!/";

  arec = MyMalloc(sizeof(struct AddressRec));
  masktype = parse_netmask(address, &arec->Mask.ipa.addr, &bits);
  arec->Mask.ipa.bits = bits;
  arec->masktype = masktype;
#ifdef IPV6
  if (masktype == HM_IPV6)
  {
    /* We have to do this, since we do not re-hash for every bit -A1kmm. */
    bits -= bits % 16;
    arec->next = atable[(hv = hash_ipv6(&arec->Mask.ipa.addr, bits))];
    atable[hv] = arec;
  }
  else 
#endif
  if (masktype == HM_IPV4)
  {
    /* We have to do this, since we do not re-hash for every bit -A1kmm. */
    bits -= bits % 8;
    arec->next = atable[(hv = hash_ipv4(&arec->Mask.ipa.addr, bits))];
    atable[hv] = arec;
  }
  else
  {
    arec->Mask.hostname = address;
    arec->next = atable[(hv = get_mask_hash(address))];
    atable[hv] = arec;
  }
  arec->username = username;
  arec->aconf = aconf;
  arec->precedence = prec_value--;
  arec->type = type;
}

/* void delete_one_address(const char*, struct AccessItem*)
 * Input: An address string, the associated AccessItem.
 * Output: None
 * Side effects: Deletes an address record. Frees the AccessItem if there
 *               is nothing referencing it, sets it as illegal otherwise.
 */
void
delete_one_address_conf(const char *address, struct AccessItem *aconf)
{
  int masktype, bits;
  unsigned long hv;
  struct AddressRec *arec, *arecl = NULL;
  struct irc_ssaddr addr;
  masktype = parse_netmask(address, &addr, &bits);

#ifdef IPV6
  if (masktype == HM_IPV6)
  {
    /* We have to do this, since we do not re-hash for every bit -A1kmm. */
    bits -= bits % 16;
    hv = hash_ipv6(&addr, bits);
  }
  else
#endif
  if (masktype == HM_IPV4)
  {
    /* We have to do this, since we do not re-hash for every bit -A1kmm. */
    bits -= bits % 8;
    hv = hash_ipv4(&addr, bits);
  }
  else
    hv = get_mask_hash(address);
  for (arec = atable[hv]; arec; arec = arec->next)
  {
    if (arec->aconf == aconf)
    {
      if (arecl)
        arecl->next = arec->next;
      else
        atable[hv] = arec->next;
      delete_conf_item(aconf->conf_ptr);
      MyFree(arec);
      return;
    }
    arecl = arec;
  }
}

/* void clear_out_address_conf(void)
 * Input: None
 * Output: None
 * Side effects: Clears out all address records in the hash table,
 *               frees them, and frees the AccessItems if nothing references
 *               them, otherwise sets them as illegal.   
 */
void
clear_out_address_conf(void)
{
  int i;
  struct AddressRec *arec;
  struct AddressRec *last_arec;
  struct AddressRec *next_arec;
 
  for (i = 0; i < ATABLE_SIZE; i++)
  {
    last_arec = NULL;
    for (arec = atable[i]; arec; arec = next_arec)
    {
      /* We keep the temporary K-lines and destroy the
       * permanent ones, just to be confusing :) -A1kmm
       */  
      next_arec = arec->next;

      if (arec->aconf->flags & CONF_FLAGS_TEMPORARY)
      {
        last_arec = arec;
      }
      else   
      {
        /* unlink it from link list - Dianora */
  
        if (last_arec == NULL)
        {
          atable[i] = next_arec;
        }
        else
        {
          last_arec->next = next_arec;
        }

	delete_conf_item(arec->aconf->conf_ptr);
        MyFree(arec);
      }
    }
  }
}

/*
 * make_iline_prefix()
 *
 * inputs       - pointer to struct Client requesting output
 *              - pointer to struct AccessItem 
 * output       - pointer to static string with prefixes listed in ascii form
 * side effects - NONE
 */
char *
make_iline_prefix(struct Client *sptr, struct AccessItem *aconf)
{
  static char prefix_of_host[14];
  char *prefix_ptr = prefix_of_host;

  if (IsNoTilde(aconf))
    *prefix_ptr++ = '-';
  if (IsLimitIp(aconf))
    *prefix_ptr++ = '!';
  if (IsNeedIdentd(aconf))
    *prefix_ptr++ = '+';
  if (!IsNeedPassword(aconf))
    *prefix_ptr++ = '&';
  if (IsConfExemptResv(aconf))
    *prefix_ptr++ = '$';
  if (IsNoMatchIp(aconf))
    *prefix_ptr++ = '%';
  if (IsConfDoSpoofIp(aconf))
    *prefix_ptr++ = '=';
  if (MyOper(sptr) && IsConfExemptKline(aconf))
    *prefix_ptr++ = '^';
  if (MyOper(sptr) && IsConfExemptGline(aconf))
    *prefix_ptr++ = '_';
  if (MyOper(sptr) && IsConfExemptLimits(aconf))
    *prefix_ptr++ = '>';
  if (MyOper(sptr) && IsConfIdlelined(aconf))
    *prefix_ptr++ = '<';
  if (IsConfCanFlood(aconf))
    *prefix_ptr++ = '|';
  *prefix_ptr = '\0';

  return prefix_of_host;
}

/* report_auth()
 *
 * Inputs: pointer to client to report to
 * Output: None
 * Side effects: Reports configured auth{} blocks to client_p
 */
void
report_auth(struct Client *client_p)
{
  struct AddressRec *arec;
  struct ConfItem *conf;
  struct AccessItem *aconf;
  int i;

  for (i = 0; i < ATABLE_SIZE; i++)
  {
    for (arec = atable[i]; arec; arec = arec->next)
    {
      if (arec->type == CONF_CLIENT)
      {
        aconf = arec->aconf;

        if (!MyOper(client_p) && IsConfDoSpoofIp(aconf))
          continue;

	conf = aconf->conf_ptr;

        /* We are doing a partial list, based on what matches the u@h of the
         * sender, so prepare the strings for comparing --fl_
	 */
        if (ConfigFileEntry.hide_spoof_ips)
          sendto_one(client_p, form_str(RPL_STATSILINE), me.name,
                     client_p->name, 'I',
		     conf->name == NULL ? "*" : conf->name,
		     make_iline_prefix(client_p, aconf), aconf->user,
                     IsConfDoSpoofIp(aconf) ? "255.255.255.255" :
                     aconf->host, aconf->port,
		     aconf->class_ptr ? aconf->class_ptr->name : "<default>");
        else
          sendto_one(client_p, form_str(RPL_STATSILINE), me.name,
                     client_p->name, 'I',
		     conf->name == NULL ? "*" : conf->name,
		     make_iline_prefix(client_p, aconf), aconf->user,
                     aconf->host, aconf->port,
		     aconf->class_ptr ? aconf->class_ptr->name : "<default>");
      }
    }
  }
}

/* report_Klines()
 * Inputs: Client to report to,
 *	   type(==0 for perm, !=0 for temporary)
 *	   mask 
 * Output: None
 * Side effects: Reports configured K(or k)-lines to client_p.
 */
void
report_Klines(struct Client *client_p, int tkline)
{
  struct AddressRec *arec = NULL;
  struct AccessItem *aconf = NULL;
  int i;
  const char *p = NULL;

  if (tkline)
    p = "k";
  else
    p = "K";

  for (i = 0; i < ATABLE_SIZE; i++)
  {
    for (arec = atable[i]; arec; arec = arec->next)
    {
      if (arec->type == CONF_KILL)
      {
        if ((tkline && !((aconf = arec->aconf)->flags & CONF_FLAGS_TEMPORARY)) ||
            (!tkline && ((aconf = arec->aconf)->flags & CONF_FLAGS_TEMPORARY)))
          continue;

	if (IsOper(client_p))
	  sendto_one(client_p, form_str(RPL_STATSKLINE), me.name,
                     client_p->name, p, aconf->host, aconf->user,
		     aconf->reason, aconf->oper_reason ? aconf->oper_reason : "");
	else
          sendto_one(client_p, form_str(RPL_STATSKLINE), me.name,
                     client_p->name, p, aconf->host, aconf->user,
		     aconf->reason, "");
      }
    }
  }
}
