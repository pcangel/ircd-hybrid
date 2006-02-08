/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ACCEPT_PASSWORD = 258,
     ACTION = 259,
     ADMIN = 260,
     AFTYPE = 261,
     T_ALLOW = 262,
     ANTI_NICK_FLOOD = 263,
     ANTI_SPAM_EXIT_MESSAGE_TIME = 264,
     AUTOCONN = 265,
     T_BLOCK = 266,
     BURST_AWAY = 267,
     BURST_TOPICWHO = 268,
     BYTES = 269,
     KBYTES = 270,
     MBYTES = 271,
     GBYTES = 272,
     TBYTES = 273,
     CALLER_ID_WAIT = 274,
     CAN_FLOOD = 275,
     CAN_IDLE = 276,
     CHANNEL = 277,
     CIDR_BITLEN_IPV4 = 278,
     CIDR_BITLEN_IPV6 = 279,
     CIPHER_PREFERENCE = 280,
     CLASS = 281,
     COMPRESSED = 282,
     COMPRESSION_LEVEL = 283,
     CONNECT = 284,
     CONNECTFREQ = 285,
     CRYPTLINK = 286,
     DEFAULT_CIPHER_PREFERENCE = 287,
     DEFAULT_FLOODCOUNT = 288,
     DEFAULT_SPLIT_SERVER_COUNT = 289,
     DEFAULT_SPLIT_USER_COUNT = 290,
     DENY = 291,
     DESCRIPTION = 292,
     DIE = 293,
     DISABLE_AUTH = 294,
     DISABLE_HIDDEN = 295,
     DISABLE_LOCAL_CHANNELS = 296,
     DISABLE_REMOTE_COMMANDS = 297,
     DOT_IN_IP6_ADDR = 298,
     DOTS_IN_IDENT = 299,
     DURATION = 300,
     EGDPOOL_PATH = 301,
     EMAIL = 302,
     ENABLE = 303,
     ENCRYPTED = 304,
     EXCEED_LIMIT = 305,
     EXEMPT = 306,
     FAILED_OPER_NOTICE = 307,
     FAKENAME = 308,
     IRCD_FLAGS = 309,
     FLATTEN_LINKS = 310,
     FFAILED_OPERLOG = 311,
     FKILLLOG = 312,
     FKLINELOG = 313,
     FGLINELOG = 314,
     FIOERRLOG = 315,
     FOPERLOG = 316,
     FOPERSPYLOG = 317,
     FUSERLOG = 318,
     GECOS = 319,
     GENERAL = 320,
     GLINE = 321,
     GLINES = 322,
     GLINE_EXEMPT = 323,
     GLINE_LOG = 324,
     GLINE_TIME = 325,
     GLINE_MIN_CIDR = 326,
     GLINE_MIN_CIDR6 = 327,
     GLOBAL_KILL = 328,
     IRCD_AUTH = 329,
     NEED_IDENT = 330,
     HAVENT_READ_CONF = 331,
     HIDDEN = 332,
     HIDDEN_ADMIN = 333,
     HIDDEN_NAME = 334,
     HIDDEN_OPER = 335,
     HIDE_SERVER_IPS = 336,
     HIDE_SERVERS = 337,
     HIDE_SPOOF_IPS = 338,
     HOST = 339,
     HUB = 340,
     HUB_MASK = 341,
     IDLETIME = 342,
     IGNORE_BOGUS_TS = 343,
     INVISIBLE_ON_CONNECT = 344,
     IP = 345,
     KILL = 346,
     KILL_CHASE_TIME_LIMIT = 347,
     KLINE = 348,
     KLINE_EXEMPT = 349,
     KLINE_REASON = 350,
     KLINE_WITH_REASON = 351,
     KNOCK_DELAY = 352,
     KNOCK_DELAY_CHANNEL = 353,
     LEAF_MASK = 354,
     LINKS_DELAY = 355,
     LISTEN = 356,
     T_LOG = 357,
     LOGGING = 358,
     LOG_LEVEL = 359,
     MAX_ACCEPT = 360,
     MAX_BANS = 361,
     MAX_CHANS_PER_USER = 362,
     MAX_GLOBAL = 363,
     MAX_IDENT = 364,
     MAX_LOCAL = 365,
     MAX_NICK_CHANGES = 366,
     MAX_NICK_TIME = 367,
     MAX_NUMBER = 368,
     MAX_TARGETS = 369,
     MAX_WATCH = 370,
     MESSAGE_LOCALE = 371,
     MIN_NONWILDCARD = 372,
     MIN_NONWILDCARD_SIMPLE = 373,
     MODULE = 374,
     MODULES = 375,
     NAME = 376,
     NEED_PASSWORD = 377,
     NETWORK_DESC = 378,
     NETWORK_NAME = 379,
     NICK = 380,
     NICK_CHANGES = 381,
     NO_CREATE_ON_SPLIT = 382,
     NO_JOIN_ON_SPLIT = 383,
     NO_OPER_FLOOD = 384,
     NO_TILDE = 385,
     NOT = 386,
     NUMBER = 387,
     NUMBER_PER_IDENT = 388,
     NUMBER_PER_CIDR = 389,
     NUMBER_PER_IP = 390,
     NUMBER_PER_IP_GLOBAL = 391,
     OPERATOR = 392,
     OPERS_BYPASS_CALLERID = 393,
     OPER_LOG = 394,
     OPER_ONLY_UMODES = 395,
     OPER_PASS_RESV = 396,
     OPER_SPY_T = 397,
     OPER_UMODES = 398,
     JOIN_FLOOD_COUNT = 399,
     JOIN_FLOOD_TIME = 400,
     PACE_WAIT = 401,
     PACE_WAIT_SIMPLE = 402,
     PASSWORD = 403,
     PATH = 404,
     PING_COOKIE = 405,
     PING_TIME = 406,
     PING_WARNING = 407,
     PORT = 408,
     QSTRING = 409,
     QUIET_ON_BAN = 410,
     REASON = 411,
     REDIRPORT = 412,
     REDIRSERV = 413,
     REGEX_T = 414,
     REHASH = 415,
     TREJECT_HOLD_TIME = 416,
     REMOTE = 417,
     REMOTEBAN = 418,
     RESTRICT_CHANNELS = 419,
     RESTRICTED = 420,
     RSA_PRIVATE_KEY_FILE = 421,
     RSA_PUBLIC_KEY_FILE = 422,
     SSL_CERTIFICATE_FILE = 423,
     RESV = 424,
     RESV_EXEMPT = 425,
     SECONDS = 426,
     MINUTES = 427,
     HOURS = 428,
     DAYS = 429,
     WEEKS = 430,
     SENDQ = 431,
     SEND_PASSWORD = 432,
     SERVERHIDE = 433,
     SERVERINFO = 434,
     SERVLINK_PATH = 435,
     IRCD_SID = 436,
     TKLINE_EXPIRE_NOTICES = 437,
     T_SHARED = 438,
     T_CLUSTER = 439,
     TYPE = 440,
     SHORT_MOTD = 441,
     SILENT = 442,
     SPOOF = 443,
     SPOOF_NOTICE = 444,
     STATS_I_OPER_ONLY = 445,
     STATS_K_OPER_ONLY = 446,
     STATS_O_OPER_ONLY = 447,
     STATS_P_OPER_ONLY = 448,
     TBOOL = 449,
     TMASKED = 450,
     T_REJECT = 451,
     TS_MAX_DELTA = 452,
     TS_WARN_DELTA = 453,
     TWODOTS = 454,
     T_ALL = 455,
     T_BOTS = 456,
     T_SOFTCALLERID = 457,
     T_CALLERID = 458,
     T_CCONN = 459,
     T_CLIENT_FLOOD = 460,
     T_DEAF = 461,
     T_DEBUG = 462,
     T_DRONE = 463,
     T_EXTERNAL = 464,
     T_FULL = 465,
     T_INVISIBLE = 466,
     T_IPV4 = 467,
     T_IPV6 = 468,
     T_LOCOPS = 469,
     T_LOGPATH = 470,
     T_L_CRIT = 471,
     T_L_DEBUG = 472,
     T_L_ERROR = 473,
     T_L_INFO = 474,
     T_L_NOTICE = 475,
     T_L_TRACE = 476,
     T_L_WARN = 477,
     T_MAX_CLIENTS = 478,
     T_NCHANGE = 479,
     T_OPERWALL = 480,
     T_REJ = 481,
     T_SERVNOTICE = 482,
     T_SKILL = 483,
     T_SPY = 484,
     T_SSL = 485,
     T_UMODES = 486,
     T_UNAUTH = 487,
     T_UNRESV = 488,
     T_UNXLINE = 489,
     T_WALLOP = 490,
     THROTTLE_TIME = 491,
     TOPICBURST = 492,
     TRUE_NO_OPER_FLOOD = 493,
     TKLINE = 494,
     TXLINE = 495,
     TRESV = 496,
     UNKLINE = 497,
     USER = 498,
     USE_EGD = 499,
     USE_EXCEPT = 500,
     USE_INVEX = 501,
     USE_KNOCK = 502,
     USE_LOGGING = 503,
     USE_WHOIS_ACTUALLY = 504,
     VHOST = 505,
     VHOST6 = 506,
     XLINE = 507,
     WARN = 508,
     WARN_NO_NLINE = 509
   };
#endif
/* Tokens.  */
#define ACCEPT_PASSWORD 258
#define ACTION 259
#define ADMIN 260
#define AFTYPE 261
#define T_ALLOW 262
#define ANTI_NICK_FLOOD 263
#define ANTI_SPAM_EXIT_MESSAGE_TIME 264
#define AUTOCONN 265
#define T_BLOCK 266
#define BURST_AWAY 267
#define BURST_TOPICWHO 268
#define BYTES 269
#define KBYTES 270
#define MBYTES 271
#define GBYTES 272
#define TBYTES 273
#define CALLER_ID_WAIT 274
#define CAN_FLOOD 275
#define CAN_IDLE 276
#define CHANNEL 277
#define CIDR_BITLEN_IPV4 278
#define CIDR_BITLEN_IPV6 279
#define CIPHER_PREFERENCE 280
#define CLASS 281
#define COMPRESSED 282
#define COMPRESSION_LEVEL 283
#define CONNECT 284
#define CONNECTFREQ 285
#define CRYPTLINK 286
#define DEFAULT_CIPHER_PREFERENCE 287
#define DEFAULT_FLOODCOUNT 288
#define DEFAULT_SPLIT_SERVER_COUNT 289
#define DEFAULT_SPLIT_USER_COUNT 290
#define DENY 291
#define DESCRIPTION 292
#define DIE 293
#define DISABLE_AUTH 294
#define DISABLE_HIDDEN 295
#define DISABLE_LOCAL_CHANNELS 296
#define DISABLE_REMOTE_COMMANDS 297
#define DOT_IN_IP6_ADDR 298
#define DOTS_IN_IDENT 299
#define DURATION 300
#define EGDPOOL_PATH 301
#define EMAIL 302
#define ENABLE 303
#define ENCRYPTED 304
#define EXCEED_LIMIT 305
#define EXEMPT 306
#define FAILED_OPER_NOTICE 307
#define FAKENAME 308
#define IRCD_FLAGS 309
#define FLATTEN_LINKS 310
#define FFAILED_OPERLOG 311
#define FKILLLOG 312
#define FKLINELOG 313
#define FGLINELOG 314
#define FIOERRLOG 315
#define FOPERLOG 316
#define FOPERSPYLOG 317
#define FUSERLOG 318
#define GECOS 319
#define GENERAL 320
#define GLINE 321
#define GLINES 322
#define GLINE_EXEMPT 323
#define GLINE_LOG 324
#define GLINE_TIME 325
#define GLINE_MIN_CIDR 326
#define GLINE_MIN_CIDR6 327
#define GLOBAL_KILL 328
#define IRCD_AUTH 329
#define NEED_IDENT 330
#define HAVENT_READ_CONF 331
#define HIDDEN 332
#define HIDDEN_ADMIN 333
#define HIDDEN_NAME 334
#define HIDDEN_OPER 335
#define HIDE_SERVER_IPS 336
#define HIDE_SERVERS 337
#define HIDE_SPOOF_IPS 338
#define HOST 339
#define HUB 340
#define HUB_MASK 341
#define IDLETIME 342
#define IGNORE_BOGUS_TS 343
#define INVISIBLE_ON_CONNECT 344
#define IP 345
#define KILL 346
#define KILL_CHASE_TIME_LIMIT 347
#define KLINE 348
#define KLINE_EXEMPT 349
#define KLINE_REASON 350
#define KLINE_WITH_REASON 351
#define KNOCK_DELAY 352
#define KNOCK_DELAY_CHANNEL 353
#define LEAF_MASK 354
#define LINKS_DELAY 355
#define LISTEN 356
#define T_LOG 357
#define LOGGING 358
#define LOG_LEVEL 359
#define MAX_ACCEPT 360
#define MAX_BANS 361
#define MAX_CHANS_PER_USER 362
#define MAX_GLOBAL 363
#define MAX_IDENT 364
#define MAX_LOCAL 365
#define MAX_NICK_CHANGES 366
#define MAX_NICK_TIME 367
#define MAX_NUMBER 368
#define MAX_TARGETS 369
#define MAX_WATCH 370
#define MESSAGE_LOCALE 371
#define MIN_NONWILDCARD 372
#define MIN_NONWILDCARD_SIMPLE 373
#define MODULE 374
#define MODULES 375
#define NAME 376
#define NEED_PASSWORD 377
#define NETWORK_DESC 378
#define NETWORK_NAME 379
#define NICK 380
#define NICK_CHANGES 381
#define NO_CREATE_ON_SPLIT 382
#define NO_JOIN_ON_SPLIT 383
#define NO_OPER_FLOOD 384
#define NO_TILDE 385
#define NOT 386
#define NUMBER 387
#define NUMBER_PER_IDENT 388
#define NUMBER_PER_CIDR 389
#define NUMBER_PER_IP 390
#define NUMBER_PER_IP_GLOBAL 391
#define OPERATOR 392
#define OPERS_BYPASS_CALLERID 393
#define OPER_LOG 394
#define OPER_ONLY_UMODES 395
#define OPER_PASS_RESV 396
#define OPER_SPY_T 397
#define OPER_UMODES 398
#define JOIN_FLOOD_COUNT 399
#define JOIN_FLOOD_TIME 400
#define PACE_WAIT 401
#define PACE_WAIT_SIMPLE 402
#define PASSWORD 403
#define PATH 404
#define PING_COOKIE 405
#define PING_TIME 406
#define PING_WARNING 407
#define PORT 408
#define QSTRING 409
#define QUIET_ON_BAN 410
#define REASON 411
#define REDIRPORT 412
#define REDIRSERV 413
#define REGEX_T 414
#define REHASH 415
#define TREJECT_HOLD_TIME 416
#define REMOTE 417
#define REMOTEBAN 418
#define RESTRICT_CHANNELS 419
#define RESTRICTED 420
#define RSA_PRIVATE_KEY_FILE 421
#define RSA_PUBLIC_KEY_FILE 422
#define SSL_CERTIFICATE_FILE 423
#define RESV 424
#define RESV_EXEMPT 425
#define SECONDS 426
#define MINUTES 427
#define HOURS 428
#define DAYS 429
#define WEEKS 430
#define SENDQ 431
#define SEND_PASSWORD 432
#define SERVERHIDE 433
#define SERVERINFO 434
#define SERVLINK_PATH 435
#define IRCD_SID 436
#define TKLINE_EXPIRE_NOTICES 437
#define T_SHARED 438
#define T_CLUSTER 439
#define TYPE 440
#define SHORT_MOTD 441
#define SILENT 442
#define SPOOF 443
#define SPOOF_NOTICE 444
#define STATS_I_OPER_ONLY 445
#define STATS_K_OPER_ONLY 446
#define STATS_O_OPER_ONLY 447
#define STATS_P_OPER_ONLY 448
#define TBOOL 449
#define TMASKED 450
#define T_REJECT 451
#define TS_MAX_DELTA 452
#define TS_WARN_DELTA 453
#define TWODOTS 454
#define T_ALL 455
#define T_BOTS 456
#define T_SOFTCALLERID 457
#define T_CALLERID 458
#define T_CCONN 459
#define T_CLIENT_FLOOD 460
#define T_DEAF 461
#define T_DEBUG 462
#define T_DRONE 463
#define T_EXTERNAL 464
#define T_FULL 465
#define T_INVISIBLE 466
#define T_IPV4 467
#define T_IPV6 468
#define T_LOCOPS 469
#define T_LOGPATH 470
#define T_L_CRIT 471
#define T_L_DEBUG 472
#define T_L_ERROR 473
#define T_L_INFO 474
#define T_L_NOTICE 475
#define T_L_TRACE 476
#define T_L_WARN 477
#define T_MAX_CLIENTS 478
#define T_NCHANGE 479
#define T_OPERWALL 480
#define T_REJ 481
#define T_SERVNOTICE 482
#define T_SKILL 483
#define T_SPY 484
#define T_SSL 485
#define T_UMODES 486
#define T_UNAUTH 487
#define T_UNRESV 488
#define T_UNXLINE 489
#define T_WALLOP 490
#define THROTTLE_TIME 491
#define TOPICBURST 492
#define TRUE_NO_OPER_FLOOD 493
#define TKLINE 494
#define TXLINE 495
#define TRESV 496
#define UNKLINE 497
#define USER 498
#define USE_EGD 499
#define USE_EXCEPT 500
#define USE_INVEX 501
#define USE_KNOCK 502
#define USE_LOGGING 503
#define USE_WHOIS_ACTUALLY 504
#define VHOST 505
#define VHOST6 506
#define XLINE 507
#define WARN 508
#define WARN_NO_NLINE 509




/* Copy the first part of user declarations.  */
#line 25 "ircd_parser.y"


#define YY_NO_UNPUT
#include <sys/types.h>

#include "stdinc.h"
#include "ircd.h"
#include "s_conf.h"
#include "client.h"	/* for UMODE_ALL only */
#include "modules.h"
#include "s_serv.h" /* for CAP_LL / IsCapable */
#include "hostmask.h"
#include "send.h"
#include "listener.h"
#include "resv.h"
#include "numeric.h"
#include "s_user.h"

#ifdef HAVE_LIBCRYPTO
#include <openssl/rsa.h>
#include <openssl/bio.h>
#include <openssl/pem.h>
#endif

static char *class_name = NULL;
static struct ConfItem *yy_conf = NULL;
static struct AccessItem *yy_aconf = NULL;
static struct MatchItem *yy_match_item = NULL;
static struct ClassItem *yy_class = NULL;
static char *yy_class_name = NULL;

static dlink_list col_conf_list  = { NULL, NULL, 0 };
static dlink_list hub_conf_list  = { NULL, NULL, 0 };
static dlink_list leaf_conf_list = { NULL, NULL, 0 };
static unsigned int listener_flags = 0;
static unsigned int regex_ban = 0;
static char userbuf[IRCD_BUFSIZE]; /* must be that big to allow things like *u*s*e*r* etc. */
static char hostbuf[IRCD_BUFSIZE];
static char reasonbuf[REASONLEN + 1];
static char gecos_name[REALLEN * 4];

EXTERN dlink_list gdeny_items; /* XXX */

static char *resv_reason = NULL;
static char *listener_address = NULL;
static int not_atom = 0;

struct CollectItem {
  dlink_node node;
  char *name;
  char *user;
  char *host;
  char *passwd;
  int  port;
  int  flags;
#ifdef HAVE_LIBCRYPTO
  char *rsa_public_key_file;
  RSA *rsa_public_key;
#endif
};

static void
free_collect_item(struct CollectItem *item)
{
  MyFree(item->name);
  MyFree(item->user);
  MyFree(item->host);
  MyFree(item->passwd);
#ifdef HAVE_LIBCRYPTO
  MyFree(item->rsa_public_key_file);
#endif
  MyFree(item);
}

static void
unhook_hub_leaf_confs(void)
{
  dlink_node *ptr;
  dlink_node *next_ptr;
  struct CollectItem *yy_hconf;
  struct CollectItem *yy_lconf;

  DLINK_FOREACH_SAFE(ptr, next_ptr, hub_conf_list.head)
  {
    yy_hconf = ptr->data;
    dlinkDelete(&yy_hconf->node, &hub_conf_list);
    free_collect_item(yy_hconf);
  }

  DLINK_FOREACH_SAFE(ptr, next_ptr, leaf_conf_list.head)
  {
    yy_lconf = ptr->data;
    dlinkDelete(&yy_lconf->node, &leaf_conf_list);
    free_collect_item(yy_lconf);
  }
}



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 124 "ircd_parser.y"
typedef union YYSTYPE {
  int number;
  char *string;
} YYSTYPE;
/* Line 196 of yacc.c.  */
#line 697 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 709 "y.tab.c"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1390

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  260
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  338
/* YYNRULES -- Number of rules. */
#define YYNRULES  725
/* YYNRULES -- Number of states. */
#define YYNSTATES  1463

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   509

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned short int yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   259,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   255,
       2,   258,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   257,     2,   256,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    41,    43,    45,    47,    50,    53,    54,    56,    59,
      63,    67,    71,    75,    79,    80,    82,    85,    89,    93,
      97,   103,   106,   108,   110,   112,   115,   120,   125,   131,
     134,   136,   138,   140,   142,   144,   146,   148,   150,   152,
     154,   156,   158,   161,   166,   171,   176,   181,   186,   191,
     196,   201,   206,   211,   216,   222,   225,   227,   229,   231,
     233,   236,   241,   246,   251,   257,   260,   262,   264,   266,
     268,   270,   272,   274,   276,   278,   280,   282,   284,   286,
     289,   294,   299,   304,   309,   314,   319,   324,   329,   334,
     339,   344,   349,   354,   359,   364,   369,   374,   379,   380,
     388,   389,   391,   394,   396,   398,   400,   402,   404,   406,
     408,   410,   412,   414,   416,   418,   420,   422,   424,   426,
     428,   430,   432,   434,   436,   438,   440,   443,   448,   450,
     455,   460,   465,   470,   475,   476,   482,   486,   488,   490,
     492,   494,   496,   498,   500,   502,   504,   506,   508,   510,
     512,   514,   516,   518,   520,   522,   524,   529,   534,   539,
     544,   549,   554,   559,   564,   569,   574,   579,   584,   589,
     594,   595,   601,   605,   607,   608,   612,   613,   616,   618,
     620,   622,   624,   626,   628,   630,   632,   634,   636,   638,
     640,   642,   644,   646,   648,   649,   657,   658,   660,   663,
     665,   667,   669,   671,   673,   675,   677,   679,   681,   683,
     685,   687,   689,   691,   694,   699,   701,   706,   711,   716,
     721,   726,   731,   736,   741,   746,   751,   756,   761,   762,
     769,   770,   776,   780,   782,   784,   786,   789,   791,   793,
     795,   797,   799,   802,   807,   811,   813,   815,   819,   824,
     829,   830,   837,   840,   842,   844,   846,   848,   850,   852,
     854,   856,   858,   860,   862,   864,   866,   868,   870,   872,
     874,   877,   882,   887,   892,   897,   902,   903,   909,   913,
     915,   916,   920,   921,   924,   926,   928,   930,   932,   934,
     936,   938,   940,   942,   944,   949,   954,   959,   964,   969,
     974,   979,   984,   989,   994,   995,  1002,  1005,  1007,  1009,
    1011,  1013,  1016,  1021,  1026,  1031,  1032,  1039,  1042,  1044,
    1046,  1048,  1050,  1053,  1058,  1063,  1064,  1070,  1074,  1076,
    1078,  1080,  1082,  1084,  1086,  1088,  1090,  1092,  1094,  1096,
    1098,  1099,  1106,  1109,  1111,  1113,  1115,  1118,  1123,  1124,
    1130,  1134,  1136,  1138,  1140,  1142,  1144,  1146,  1148,  1150,
    1152,  1154,  1156,  1158,  1159,  1167,  1168,  1170,  1173,  1175,
    1177,  1179,  1181,  1183,  1185,  1187,  1189,  1191,  1193,  1195,
    1197,  1199,  1201,  1203,  1205,  1207,  1209,  1211,  1214,  1219,
    1221,  1226,  1231,  1236,  1241,  1246,  1251,  1256,  1261,  1262,
    1268,  1272,  1274,  1275,  1279,  1280,  1283,  1285,  1287,  1289,
    1291,  1293,  1298,  1303,  1308,  1313,  1318,  1323,  1328,  1333,
    1338,  1339,  1346,  1347,  1353,  1357,  1359,  1361,  1364,  1366,
    1368,  1370,  1372,  1374,  1379,  1384,  1385,  1392,  1395,  1397,
    1399,  1401,  1403,  1408,  1413,  1419,  1422,  1424,  1426,  1428,
    1433,  1434,  1441,  1442,  1448,  1452,  1454,  1456,  1459,  1461,
    1463,  1465,  1467,  1469,  1474,  1479,  1485,  1488,  1490,  1492,
    1494,  1496,  1498,  1500,  1502,  1504,  1506,  1508,  1510,  1512,
    1514,  1516,  1518,  1520,  1522,  1524,  1526,  1528,  1530,  1532,
    1534,  1536,  1538,  1540,  1542,  1544,  1546,  1548,  1550,  1552,
    1554,  1556,  1558,  1560,  1562,  1564,  1566,  1568,  1570,  1572,
    1574,  1576,  1578,  1580,  1582,  1584,  1586,  1588,  1590,  1592,
    1594,  1596,  1598,  1600,  1602,  1607,  1612,  1617,  1622,  1627,
    1632,  1637,  1642,  1647,  1652,  1657,  1662,  1667,  1672,  1677,
    1682,  1687,  1692,  1697,  1702,  1707,  1712,  1717,  1722,  1727,
    1732,  1737,  1742,  1747,  1752,  1757,  1762,  1767,  1772,  1777,
    1782,  1787,  1792,  1797,  1802,  1807,  1812,  1817,  1822,  1827,
    1832,  1837,  1842,  1847,  1852,  1853,  1859,  1863,  1865,  1867,
    1869,  1871,  1873,  1875,  1877,  1879,  1881,  1883,  1885,  1887,
    1889,  1891,  1893,  1895,  1897,  1899,  1901,  1902,  1908,  1912,
    1914,  1916,  1918,  1920,  1922,  1924,  1926,  1928,  1930,  1932,
    1934,  1936,  1938,  1940,  1942,  1944,  1946,  1948,  1950,  1955,
    1960,  1965,  1970,  1975,  1976,  1983,  1986,  1988,  1990,  1992,
    1994,  1996,  1998,  2000,  2002,  2007,  2012,  2013,  2019,  2023,
    2025,  2027,  2029,  2034,  2039,  2040,  2046,  2050,  2052,  2054,
    2056,  2062,  2065,  2067,  2069,  2071,  2073,  2075,  2077,  2079,
    2081,  2083,  2085,  2087,  2089,  2091,  2093,  2095,  2097,  2099,
    2101,  2103,  2108,  2113,  2118,  2123,  2128,  2133,  2138,  2143,
    2148,  2153,  2158,  2163,  2168,  2173,  2178,  2183,  2188,  2194,
    2197,  2199,  2201,  2203,  2205,  2207,  2209,  2211,  2213,  2215,
    2220,  2225,  2230,  2235,  2240,  2245
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
     261,     0,    -1,    -1,   261,   262,    -1,   286,    -1,   292,
      -1,   307,    -1,   568,    -1,   344,    -1,   363,    -1,   376,
      -1,   272,    -1,   588,    -1,   402,    -1,   409,    -1,   419,
      -1,   428,    -1,   458,    -1,   468,    -1,   474,    -1,   488,
      -1,   552,    -1,   478,    -1,   267,    -1,     1,   255,    -1,
       1,   256,    -1,    -1,   264,    -1,   132,   263,    -1,   132,
     171,   263,    -1,   132,   172,   263,    -1,   132,   173,   263,
      -1,   132,   174,   263,    -1,   132,   175,   263,    -1,    -1,
     266,    -1,   132,   265,    -1,   132,    14,   265,    -1,   132,
      15,   265,    -1,   132,    16,   265,    -1,   120,   257,   268,
     256,   255,    -1,   268,   269,    -1,   269,    -1,   270,    -1,
     271,    -1,     1,   255,    -1,   119,   258,   154,   255,    -1,
     149,   258,   154,   255,    -1,   179,   257,   273,   256,   255,
      -1,   273,   274,    -1,   274,    -1,   277,    -1,   282,    -1,
     285,    -1,   279,    -1,   280,    -1,   281,    -1,   284,    -1,
     276,    -1,   283,    -1,   278,    -1,   275,    -1,     1,   255,
      -1,   168,   258,   154,   255,    -1,   166,   258,   154,   255,
      -1,   121,   258,   154,   255,    -1,   181,   258,   154,   255,
      -1,    37,   258,   154,   255,    -1,   124,   258,   154,   255,
      -1,   123,   258,   154,   255,    -1,   250,   258,   154,   255,
      -1,   251,   258,   154,   255,    -1,   223,   258,   132,   255,
      -1,    85,   258,   194,   255,    -1,     5,   257,   287,   256,
     255,    -1,   287,   288,    -1,   288,    -1,   289,    -1,   291,
      -1,   290,    -1,     1,   255,    -1,   121,   258,   154,   255,
      -1,    47,   258,   154,   255,    -1,    37,   258,   154,   255,
      -1,   103,   257,   293,   256,   255,    -1,   293,   294,    -1,
     294,    -1,   295,    -1,   296,    -1,   305,    -1,   306,    -1,
     297,    -1,   299,    -1,   301,    -1,   302,    -1,   304,    -1,
     300,    -1,   303,    -1,   298,    -1,     1,   255,    -1,   215,
     258,   154,   255,    -1,   139,   258,   154,   255,    -1,    63,
     258,   154,   255,    -1,    56,   258,   154,   255,    -1,    61,
     258,   154,   255,    -1,    62,   258,   154,   255,    -1,    59,
     258,   154,   255,    -1,    58,   258,   154,   255,    -1,    60,
     258,   154,   255,    -1,    57,   258,   154,   255,    -1,   104,
     258,   216,   255,    -1,   104,   258,   218,   255,    -1,   104,
     258,   222,   255,    -1,   104,   258,   220,   255,    -1,   104,
     258,   221,   255,    -1,   104,   258,   219,   255,    -1,   104,
     258,   217,   255,    -1,   248,   258,   194,   255,    -1,    -1,
     137,   308,   309,   257,   310,   256,   255,    -1,    -1,   313,
      -1,   310,   311,    -1,   311,    -1,   312,    -1,   314,    -1,
     315,    -1,   334,    -1,   335,    -1,   319,    -1,   318,    -1,
     323,    -1,   324,    -1,   326,    -1,   327,    -1,   328,    -1,
     329,    -1,   330,    -1,   325,    -1,   331,    -1,   332,    -1,
     333,    -1,   336,    -1,   316,    -1,   317,    -1,   337,    -1,
       1,   255,    -1,   121,   258,   154,   255,    -1,   154,    -1,
     243,   258,   154,   255,    -1,   148,   258,   154,   255,    -1,
      49,   258,   194,   255,    -1,   167,   258,   154,   255,    -1,
      26,   258,   154,   255,    -1,    -1,   231,   320,   258,   321,
     255,    -1,   321,   259,   322,    -1,   322,    -1,   201,    -1,
     204,    -1,   206,    -1,   207,    -1,   210,    -1,   228,    -1,
     224,    -1,   226,    -1,   232,    -1,   229,    -1,   209,    -1,
     225,    -1,   227,    -1,   211,    -1,   235,    -1,   202,    -1,
     203,    -1,   214,    -1,    73,   258,   194,   255,    -1,   162,
     258,   194,   255,    -1,   163,   258,   194,   255,    -1,    93,
     258,   194,   255,    -1,   252,   258,   194,   255,    -1,   242,
     258,   194,   255,    -1,    66,   258,   194,   255,    -1,   126,
     258,   194,   255,    -1,    38,   258,   194,   255,    -1,   160,
     258,   194,   255,    -1,     5,   258,   194,   255,    -1,    78,
     258,   194,   255,    -1,    80,   258,   194,   255,    -1,   225,
     258,   194,   255,    -1,    -1,    54,   338,   258,   339,   255,
      -1,   339,   259,   340,    -1,   340,    -1,    -1,   131,   341,
     343,    -1,    -1,   342,   343,    -1,    73,    -1,   162,    -1,
      93,    -1,   242,    -1,   252,    -1,    66,    -1,    38,    -1,
     160,    -1,     5,    -1,    78,    -1,   126,    -1,   225,    -1,
     142,    -1,    80,    -1,   163,    -1,    49,    -1,    -1,    26,
     345,   346,   257,   347,   256,   255,    -1,    -1,   350,    -1,
     347,   348,    -1,   348,    -1,   349,    -1,   360,    -1,   361,
      -1,   351,    -1,   352,    -1,   362,    -1,   353,    -1,   354,
      -1,   355,    -1,   356,    -1,   357,    -1,   358,    -1,   359,
      -1,     1,   255,    -1,   121,   258,   154,   255,    -1,   154,
      -1,   151,   258,   264,   255,    -1,   152,   258,   264,   255,
      -1,   135,   258,   132,   255,    -1,    30,   258,   264,   255,
      -1,   113,   258,   132,   255,    -1,   108,   258,   132,   255,
      -1,   110,   258,   132,   255,    -1,   109,   258,   132,   255,
      -1,   176,   258,   266,   255,    -1,    23,   258,   132,   255,
      -1,    24,   258,   132,   255,    -1,   134,   258,   132,   255,
      -1,    -1,   101,   364,   257,   369,   256,   255,    -1,    -1,
      54,   366,   258,   367,   255,    -1,   367,   259,   368,    -1,
     368,    -1,   230,    -1,    77,    -1,   369,   370,    -1,   370,
      -1,   371,    -1,   365,    -1,   374,    -1,   375,    -1,     1,
     255,    -1,   153,   258,   372,   255,    -1,   372,   259,   373,
      -1,   373,    -1,   132,    -1,   132,   199,   132,    -1,    90,
     258,   154,   255,    -1,    84,   258,   154,   255,    -1,    -1,
      74,   377,   257,   378,   256,   255,    -1,   378,   379,    -1,
     379,    -1,   380,    -1,   381,    -1,   383,    -1,   385,    -1,
     392,    -1,   393,    -1,   394,    -1,   396,    -1,   397,    -1,
     398,    -1,   382,    -1,   399,    -1,   400,    -1,   395,    -1,
     401,    -1,   384,    -1,     1,   255,    -1,   243,   258,   154,
     255,    -1,   148,   258,   154,   255,    -1,   189,   258,   194,
     255,    -1,    26,   258,   154,   255,    -1,    49,   258,   194,
     255,    -1,    -1,    54,   386,   258,   387,   255,    -1,   387,
     259,   388,    -1,   388,    -1,    -1,   131,   389,   391,    -1,
      -1,   390,   391,    -1,   189,    -1,    50,    -1,    94,    -1,
      75,    -1,    20,    -1,    21,    -1,   130,    -1,    68,    -1,
     170,    -1,   122,    -1,    94,   258,   194,   255,    -1,    75,
     258,   194,   255,    -1,    50,   258,   194,   255,    -1,    20,
     258,   194,   255,    -1,   130,   258,   194,   255,    -1,    68,
     258,   194,   255,    -1,   188,   258,   154,   255,    -1,   158,
     258,   154,   255,    -1,   157,   258,   132,   255,    -1,   122,
     258,   194,   255,    -1,    -1,   169,   403,   257,   404,   256,
     255,    -1,   404,   405,    -1,   405,    -1,   406,    -1,   407,
      -1,   408,    -1,     1,   255,    -1,   156,   258,   154,   255,
      -1,    22,   258,   154,   255,    -1,   125,   258,   154,   255,
      -1,    -1,   183,   410,   257,   411,   256,   255,    -1,   411,
     412,    -1,   412,    -1,   413,    -1,   414,    -1,   415,    -1,
       1,   255,    -1,   121,   258,   154,   255,    -1,   243,   258,
     154,   255,    -1,    -1,   185,   416,   258,   417,   255,    -1,
     417,   259,   418,    -1,   418,    -1,    93,    -1,   239,    -1,
     242,    -1,   252,    -1,   240,    -1,   234,    -1,   169,    -1,
     241,    -1,   233,    -1,   214,    -1,   200,    -1,    -1,   184,
     420,   257,   421,   256,   255,    -1,   421,   422,    -1,   422,
      -1,   423,    -1,   424,    -1,     1,   255,    -1,   121,   258,
     154,   255,    -1,    -1,   185,   425,   258,   426,   255,    -1,
     426,   259,   427,    -1,   427,    -1,    93,    -1,   239,    -1,
     242,    -1,   252,    -1,   240,    -1,   234,    -1,   169,    -1,
     241,    -1,   233,    -1,   214,    -1,   200,    -1,    -1,    29,
     429,   430,   257,   431,   256,   255,    -1,    -1,   434,    -1,
     431,   432,    -1,   432,    -1,   433,    -1,   435,    -1,   436,
      -1,   437,    -1,   438,    -1,   440,    -1,   439,    -1,   441,
      -1,   442,    -1,   454,    -1,   455,    -1,   456,    -1,   453,
      -1,   450,    -1,   452,    -1,   451,    -1,   449,    -1,   457,
      -1,     1,   255,    -1,   121,   258,   154,   255,    -1,   154,
      -1,    84,   258,   154,   255,    -1,   250,   258,   154,   255,
      -1,   177,   258,   154,   255,    -1,     3,   258,   154,   255,
      -1,   153,   258,   132,   255,    -1,     6,   258,   212,   255,
      -1,     6,   258,   213,   255,    -1,    53,   258,   154,   255,
      -1,    -1,    54,   443,   258,   444,   255,    -1,   444,   259,
     445,    -1,   445,    -1,    -1,   131,   446,   448,    -1,    -1,
     447,   448,    -1,    27,    -1,    31,    -1,    10,    -1,    12,
      -1,   237,    -1,   167,   258,   154,   255,    -1,    49,   258,
     194,   255,    -1,    31,   258,   194,   255,    -1,    27,   258,
     194,   255,    -1,    10,   258,   194,   255,    -1,    86,   258,
     154,   255,    -1,    99,   258,   154,   255,    -1,    26,   258,
     154,   255,    -1,    25,   258,   154,   255,    -1,    -1,    91,
     459,   257,   464,   256,   255,    -1,    -1,   185,   461,   258,
     462,   255,    -1,   462,   259,   463,    -1,   463,    -1,   159,
      -1,   464,   465,    -1,   465,    -1,   466,    -1,   467,    -1,
     460,    -1,     1,    -1,   243,   258,   154,   255,    -1,   156,
     258,   154,   255,    -1,    -1,    36,   469,   257,   470,   256,
     255,    -1,   470,   471,    -1,   471,    -1,   472,    -1,   473,
      -1,     1,    -1,    90,   258,   154,   255,    -1,   156,   258,
     154,   255,    -1,    51,   257,   475,   256,   255,    -1,   475,
     476,    -1,   476,    -1,   477,    -1,     1,    -1,    90,   258,
     154,   255,    -1,    -1,    64,   479,   257,   484,   256,   255,
      -1,    -1,   185,   481,   258,   482,   255,    -1,   482,   259,
     483,    -1,   483,    -1,   159,    -1,   484,   485,    -1,   485,
      -1,   486,    -1,   487,    -1,   480,    -1,     1,    -1,   121,
     258,   154,   255,    -1,   156,   258,   154,   255,    -1,    65,
     257,   489,   256,   255,    -1,   489,   490,    -1,   490,    -1,
     499,    -1,   500,    -1,   502,    -1,   503,    -1,   504,    -1,
     505,    -1,   506,    -1,   507,    -1,   508,    -1,   509,    -1,
     498,    -1,   511,    -1,   512,    -1,   513,    -1,   514,    -1,
     529,    -1,   515,    -1,   517,    -1,   519,    -1,   518,    -1,
     522,    -1,   516,    -1,   523,    -1,   524,    -1,   525,    -1,
     526,    -1,   528,    -1,   527,    -1,   543,    -1,   530,    -1,
     534,    -1,   535,    -1,   539,    -1,   520,    -1,   521,    -1,
     549,    -1,   547,    -1,   548,    -1,   531,    -1,   501,    -1,
     532,    -1,   533,    -1,   550,    -1,   538,    -1,   510,    -1,
     551,    -1,   536,    -1,   537,    -1,   494,    -1,   497,    -1,
     492,    -1,   493,    -1,   495,    -1,   496,    -1,   491,    -1,
       1,    -1,   115,   258,   132,   255,    -1,    71,   258,   132,
     255,    -1,    72,   258,   132,   255,    -1,    12,   258,   194,
     255,    -1,   249,   258,   194,   255,    -1,   161,   258,   264,
     255,    -1,   182,   258,   194,   255,    -1,    92,   258,   132,
     255,    -1,    83,   258,   194,   255,    -1,    88,   258,   194,
     255,    -1,    42,   258,   194,   255,    -1,    52,   258,   194,
     255,    -1,     8,   258,   194,   255,    -1,   112,   258,   264,
     255,    -1,   111,   258,   132,   255,    -1,   105,   258,   132,
     255,    -1,     9,   258,   264,   255,    -1,   198,   258,   264,
     255,    -1,   197,   258,   264,   255,    -1,    76,   258,   132,
     255,    -1,    96,   258,   194,   255,    -1,    95,   258,   154,
     255,    -1,    89,   258,   194,   255,    -1,   254,   258,   194,
     255,    -1,   192,   258,   194,   255,    -1,   193,   258,   194,
     255,    -1,   191,   258,   194,   255,    -1,   191,   258,   195,
     255,    -1,   190,   258,   194,   255,    -1,   190,   258,   195,
     255,    -1,   146,   258,   264,   255,    -1,    19,   258,   264,
     255,    -1,   138,   258,   194,   255,    -1,   147,   258,   264,
     255,    -1,   186,   258,   194,   255,    -1,   129,   258,   194,
     255,    -1,   238,   258,   194,   255,    -1,   141,   258,   194,
     255,    -1,   116,   258,   154,   255,    -1,    87,   258,   264,
     255,    -1,    44,   258,   132,   255,    -1,   114,   258,   132,
     255,    -1,   180,   258,   154,   255,    -1,    32,   258,   154,
     255,    -1,    28,   258,   132,   255,    -1,   244,   258,   194,
     255,    -1,    46,   258,   154,   255,    -1,   150,   258,   194,
     255,    -1,    39,   258,   194,   255,    -1,   236,   258,   264,
     255,    -1,    -1,   143,   540,   258,   541,   255,    -1,   541,
     259,   542,    -1,   542,    -1,   201,    -1,   204,    -1,   206,
      -1,   207,    -1,   210,    -1,   228,    -1,   224,    -1,   226,
      -1,   232,    -1,   229,    -1,   209,    -1,   225,    -1,   227,
      -1,   211,    -1,   235,    -1,   202,    -1,   203,    -1,   214,
      -1,    -1,   140,   544,   258,   545,   255,    -1,   545,   259,
     546,    -1,   546,    -1,   201,    -1,   204,    -1,   206,    -1,
     207,    -1,   210,    -1,   228,    -1,   224,    -1,   226,    -1,
     232,    -1,   229,    -1,   209,    -1,   225,    -1,   227,    -1,
     211,    -1,   235,    -1,   202,    -1,   203,    -1,   214,    -1,
     117,   258,   132,   255,    -1,   118,   258,   132,   255,    -1,
      33,   258,   132,   255,    -1,   205,   258,   266,   255,    -1,
      43,   258,   194,   255,    -1,    -1,    67,   553,   257,   554,
     256,   255,    -1,   554,   555,    -1,   555,    -1,   556,    -1,
     557,    -1,   558,    -1,   562,    -1,   563,    -1,   564,    -1,
       1,    -1,    48,   258,   194,   255,    -1,    45,   258,   264,
     255,    -1,    -1,   103,   559,   258,   560,   255,    -1,   560,
     259,   561,    -1,   561,    -1,   196,    -1,    11,    -1,   243,
     258,   154,   255,    -1,   121,   258,   154,   255,    -1,    -1,
       4,   565,   258,   566,   255,    -1,   566,   259,   567,    -1,
     567,    -1,   196,    -1,    11,    -1,    22,   257,   569,   256,
     255,    -1,   569,   570,    -1,   570,    -1,   572,    -1,   573,
      -1,   574,    -1,   575,    -1,   580,    -1,   576,    -1,   577,
      -1,   578,    -1,   579,    -1,   581,    -1,   582,    -1,   583,
      -1,   571,    -1,   584,    -1,   585,    -1,   586,    -1,   587,
      -1,     1,    -1,   164,   258,   194,   255,    -1,    41,   258,
     194,   255,    -1,   245,   258,   194,   255,    -1,   246,   258,
     194,   255,    -1,   247,   258,   194,   255,    -1,    97,   258,
     264,   255,    -1,    98,   258,   264,   255,    -1,   107,   258,
     132,   255,    -1,   155,   258,   194,   255,    -1,   106,   258,
     132,   255,    -1,    35,   258,   132,   255,    -1,    34,   258,
     132,   255,    -1,   127,   258,   194,   255,    -1,   128,   258,
     194,   255,    -1,    13,   258,   194,   255,    -1,   144,   258,
     132,   255,    -1,   145,   258,   264,   255,    -1,   178,   257,
     589,   256,   255,    -1,   589,   590,    -1,   590,    -1,   591,
      -1,   592,    -1,   594,    -1,   596,    -1,   595,    -1,   593,
      -1,   597,    -1,     1,    -1,    55,   258,   194,   255,    -1,
      82,   258,   194,   255,    -1,    79,   258,   154,   255,    -1,
     100,   258,   264,   255,    -1,    77,   258,   194,   255,    -1,
      40,   258,   194,   255,    -1,    81,   258,   194,   255,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   382,   382,   383,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   411,   411,   412,   416,
     420,   424,   428,   432,   438,   438,   439,   440,   441,   442,
     449,   452,   452,   453,   453,   453,   455,   472,   483,   486,
     487,   488,   488,   489,   489,   490,   490,   491,   492,   492,
     493,   493,   494,   496,   530,   590,   604,   622,   631,   645,
     654,   682,   712,   735,   744,   746,   746,   747,   747,   748,
     748,   750,   759,   768,   781,   783,   784,   786,   786,   787,
     788,   788,   789,   789,   790,   790,   791,   791,   792,   793,
     795,   799,   803,   810,   817,   824,   831,   838,   845,   852,
     859,   863,   867,   871,   875,   879,   883,   889,   899,   898,
     992,   992,   993,   993,   994,   994,   994,   994,   995,   995,
     996,   996,   996,   997,   997,   997,   998,   998,   998,   999,
     999,   999,   999,  1000,  1000,  1001,  1001,  1003,  1015,  1027,
    1061,  1073,  1084,  1126,  1136,  1135,  1141,  1141,  1142,  1146,
    1150,  1154,  1158,  1162,  1166,  1170,  1174,  1178,  1182,  1186,
    1190,  1194,  1198,  1202,  1206,  1210,  1216,  1227,  1238,  1249,
    1260,  1271,  1282,  1293,  1304,  1315,  1326,  1337,  1348,  1359,
    1371,  1370,  1374,  1374,  1375,  1375,  1376,  1376,  1378,  1385,
    1392,  1399,  1406,  1413,  1420,  1427,  1434,  1441,  1448,  1455,
    1462,  1469,  1476,  1483,  1497,  1496,  1538,  1538,  1540,  1540,
    1541,  1542,  1542,  1543,  1544,  1545,  1546,  1547,  1548,  1549,
    1550,  1551,  1552,  1553,  1555,  1564,  1573,  1579,  1585,  1591,
    1597,  1603,  1609,  1615,  1621,  1627,  1633,  1639,  1649,  1648,
    1665,  1664,  1668,  1668,  1669,  1673,  1679,  1679,  1680,  1680,
    1680,  1680,  1680,  1682,  1684,  1684,  1686,  1701,  1723,  1732,
    1745,  1744,  1813,  1813,  1814,  1814,  1814,  1814,  1815,  1815,
    1816,  1816,  1816,  1817,  1817,  1818,  1818,  1818,  1819,  1819,
    1819,  1821,  1858,  1871,  1882,  1891,  1903,  1902,  1906,  1906,
    1907,  1907,  1908,  1908,  1910,  1918,  1925,  1932,  1939,  1946,
    1953,  1960,  1967,  1974,  1983,  1994,  2005,  2016,  2027,  2038,
    2050,  2069,  2079,  2088,  2104,  2103,  2119,  2119,  2120,  2120,
    2120,  2120,  2122,  2131,  2146,  2160,  2159,  2175,  2175,  2176,
    2176,  2176,  2176,  2178,  2187,  2210,  2209,  2215,  2215,  2216,
    2220,  2224,  2228,  2232,  2236,  2240,  2244,  2248,  2252,  2256,
    2266,  2265,  2280,  2280,  2281,  2281,  2281,  2283,  2293,  2292,
    2298,  2298,  2299,  2303,  2307,  2311,  2315,  2319,  2323,  2327,
    2331,  2335,  2339,  2349,  2348,  2494,  2494,  2495,  2495,  2496,
    2496,  2496,  2497,  2497,  2498,  2498,  2499,  2499,  2499,  2500,
    2500,  2500,  2501,  2501,  2501,  2502,  2502,  2503,  2505,  2517,
    2529,  2538,  2564,  2582,  2600,  2606,  2610,  2618,  2628,  2627,
    2631,  2631,  2632,  2632,  2633,  2633,  2635,  2646,  2653,  2660,
    2667,  2677,  2718,  2729,  2740,  2755,  2766,  2779,  2792,  2801,
    2837,  2836,  2900,  2899,  2903,  2903,  2904,  2910,  2910,  2911,
    2911,  2911,  2911,  2913,  2932,  2942,  2941,  2963,  2963,  2964,
    2964,  2964,  2966,  2975,  2987,  2989,  2989,  2990,  2990,  2992,
    3014,  3013,  3055,  3054,  3058,  3058,  3059,  3065,  3065,  3066,
    3066,  3066,  3066,  3068,  3074,  3083,  3086,  3086,  3087,  3087,
    3088,  3088,  3089,  3089,  3090,  3090,  3091,  3091,  3092,  3092,
    3093,  3093,  3094,  3094,  3095,  3095,  3096,  3096,  3097,  3097,
    3098,  3098,  3099,  3099,  3100,  3100,  3101,  3101,  3102,  3102,
    3103,  3103,  3104,  3104,  3105,  3105,  3106,  3106,  3107,  3108,
    3108,  3109,  3109,  3110,  3110,  3111,  3111,  3112,  3112,  3113,
    3113,  3114,  3114,  3115,  3118,  3123,  3128,  3133,  3138,  3143,
    3148,  3153,  3158,  3163,  3168,  3173,  3178,  3183,  3188,  3193,
    3198,  3203,  3208,  3214,  3225,  3230,  3239,  3244,  3249,  3254,
    3259,  3262,  3267,  3270,  3275,  3280,  3285,  3290,  3295,  3300,
    3305,  3310,  3315,  3326,  3331,  3336,  3341,  3350,  3382,  3400,
    3405,  3414,  3419,  3424,  3430,  3429,  3434,  3434,  3435,  3438,
    3441,  3444,  3447,  3450,  3453,  3456,  3459,  3462,  3465,  3468,
    3471,  3474,  3477,  3480,  3483,  3486,  3492,  3491,  3496,  3496,
    3497,  3500,  3503,  3506,  3509,  3512,  3515,  3518,  3521,  3524,
    3527,  3530,  3533,  3536,  3539,  3542,  3545,  3548,  3553,  3558,
    3563,  3568,  3573,  3582,  3581,  3605,  3605,  3606,  3607,  3608,
    3609,  3610,  3611,  3612,  3614,  3620,  3627,  3626,  3631,  3631,
    3632,  3636,  3642,  3676,  3686,  3685,  3735,  3735,  3736,  3740,
    3749,  3752,  3752,  3753,  3753,  3754,  3754,  3755,  3755,  3756,
    3756,  3757,  3757,  3758,  3759,  3759,  3760,  3760,  3761,  3761,
    3762,  3764,  3769,  3774,  3779,  3784,  3789,  3794,  3799,  3804,
    3809,  3814,  3819,  3824,  3829,  3834,  3839,  3844,  3852,  3855,
    3855,  3856,  3856,  3857,  3858,  3859,  3859,  3860,  3861,  3863,
    3869,  3875,  3884,  3898,  3904,  3910
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ACCEPT_PASSWORD", "ACTION", "ADMIN",
  "AFTYPE", "T_ALLOW", "ANTI_NICK_FLOOD", "ANTI_SPAM_EXIT_MESSAGE_TIME",
  "AUTOCONN", "T_BLOCK", "BURST_AWAY", "BURST_TOPICWHO", "BYTES", "KBYTES",
  "MBYTES", "GBYTES", "TBYTES", "CALLER_ID_WAIT", "CAN_FLOOD", "CAN_IDLE",
  "CHANNEL", "CIDR_BITLEN_IPV4", "CIDR_BITLEN_IPV6", "CIPHER_PREFERENCE",
  "CLASS", "COMPRESSED", "COMPRESSION_LEVEL", "CONNECT", "CONNECTFREQ",
  "CRYPTLINK", "DEFAULT_CIPHER_PREFERENCE", "DEFAULT_FLOODCOUNT",
  "DEFAULT_SPLIT_SERVER_COUNT", "DEFAULT_SPLIT_USER_COUNT", "DENY",
  "DESCRIPTION", "DIE", "DISABLE_AUTH", "DISABLE_HIDDEN",
  "DISABLE_LOCAL_CHANNELS", "DISABLE_REMOTE_COMMANDS", "DOT_IN_IP6_ADDR",
  "DOTS_IN_IDENT", "DURATION", "EGDPOOL_PATH", "EMAIL", "ENABLE",
  "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT", "FAILED_OPER_NOTICE", "FAKENAME",
  "IRCD_FLAGS", "FLATTEN_LINKS", "FFAILED_OPERLOG", "FKILLLOG",
  "FKLINELOG", "FGLINELOG", "FIOERRLOG", "FOPERLOG", "FOPERSPYLOG",
  "FUSERLOG", "GECOS", "GENERAL", "GLINE", "GLINES", "GLINE_EXEMPT",
  "GLINE_LOG", "GLINE_TIME", "GLINE_MIN_CIDR", "GLINE_MIN_CIDR6",
  "GLOBAL_KILL", "IRCD_AUTH", "NEED_IDENT", "HAVENT_READ_CONF", "HIDDEN",
  "HIDDEN_ADMIN", "HIDDEN_NAME", "HIDDEN_OPER", "HIDE_SERVER_IPS",
  "HIDE_SERVERS", "HIDE_SPOOF_IPS", "HOST", "HUB", "HUB_MASK", "IDLETIME",
  "IGNORE_BOGUS_TS", "INVISIBLE_ON_CONNECT", "IP", "KILL",
  "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT", "KLINE_REASON",
  "KLINE_WITH_REASON", "KNOCK_DELAY", "KNOCK_DELAY_CHANNEL", "LEAF_MASK",
  "LINKS_DELAY", "LISTEN", "T_LOG", "LOGGING", "LOG_LEVEL", "MAX_ACCEPT",
  "MAX_BANS", "MAX_CHANS_PER_USER", "MAX_GLOBAL", "MAX_IDENT", "MAX_LOCAL",
  "MAX_NICK_CHANGES", "MAX_NICK_TIME", "MAX_NUMBER", "MAX_TARGETS",
  "MAX_WATCH", "MESSAGE_LOCALE", "MIN_NONWILDCARD",
  "MIN_NONWILDCARD_SIMPLE", "MODULE", "MODULES", "NAME", "NEED_PASSWORD",
  "NETWORK_DESC", "NETWORK_NAME", "NICK", "NICK_CHANGES",
  "NO_CREATE_ON_SPLIT", "NO_JOIN_ON_SPLIT", "NO_OPER_FLOOD", "NO_TILDE",
  "NOT", "NUMBER", "NUMBER_PER_IDENT", "NUMBER_PER_CIDR", "NUMBER_PER_IP",
  "NUMBER_PER_IP_GLOBAL", "OPERATOR", "OPERS_BYPASS_CALLERID", "OPER_LOG",
  "OPER_ONLY_UMODES", "OPER_PASS_RESV", "OPER_SPY_T", "OPER_UMODES",
  "JOIN_FLOOD_COUNT", "JOIN_FLOOD_TIME", "PACE_WAIT", "PACE_WAIT_SIMPLE",
  "PASSWORD", "PATH", "PING_COOKIE", "PING_TIME", "PING_WARNING", "PORT",
  "QSTRING", "QUIET_ON_BAN", "REASON", "REDIRPORT", "REDIRSERV", "REGEX_T",
  "REHASH", "TREJECT_HOLD_TIME", "REMOTE", "REMOTEBAN",
  "RESTRICT_CHANNELS", "RESTRICTED", "RSA_PRIVATE_KEY_FILE",
  "RSA_PUBLIC_KEY_FILE", "SSL_CERTIFICATE_FILE", "RESV", "RESV_EXEMPT",
  "SECONDS", "MINUTES", "HOURS", "DAYS", "WEEKS", "SENDQ", "SEND_PASSWORD",
  "SERVERHIDE", "SERVERINFO", "SERVLINK_PATH", "IRCD_SID",
  "TKLINE_EXPIRE_NOTICES", "T_SHARED", "T_CLUSTER", "TYPE", "SHORT_MOTD",
  "SILENT", "SPOOF", "SPOOF_NOTICE", "STATS_I_OPER_ONLY",
  "STATS_K_OPER_ONLY", "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY", "TBOOL",
  "TMASKED", "T_REJECT", "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS",
  "T_ALL", "T_BOTS", "T_SOFTCALLERID", "T_CALLERID", "T_CCONN",
  "T_CLIENT_FLOOD", "T_DEAF", "T_DEBUG", "T_DRONE", "T_EXTERNAL", "T_FULL",
  "T_INVISIBLE", "T_IPV4", "T_IPV6", "T_LOCOPS", "T_LOGPATH", "T_L_CRIT",
  "T_L_DEBUG", "T_L_ERROR", "T_L_INFO", "T_L_NOTICE", "T_L_TRACE",
  "T_L_WARN", "T_MAX_CLIENTS", "T_NCHANGE", "T_OPERWALL", "T_REJ",
  "T_SERVNOTICE", "T_SKILL", "T_SPY", "T_SSL", "T_UMODES", "T_UNAUTH",
  "T_UNRESV", "T_UNXLINE", "T_WALLOP", "THROTTLE_TIME", "TOPICBURST",
  "TRUE_NO_OPER_FLOOD", "TKLINE", "TXLINE", "TRESV", "UNKLINE", "USER",
  "USE_EGD", "USE_EXCEPT", "USE_INVEX", "USE_KNOCK", "USE_LOGGING",
  "USE_WHOIS_ACTUALLY", "VHOST", "VHOST6", "XLINE", "WARN",
  "WARN_NO_NLINE", "';'", "'}'", "'{'", "'='", "','", "$accept", "conf",
  "conf_item", "timespec_", "timespec", "sizespec_", "sizespec",
  "modules_entry", "modules_items", "modules_item", "modules_module",
  "modules_path", "serverinfo_entry", "serverinfo_items",
  "serverinfo_item", "serverinfo_ssl_certificate_file",
  "serverinfo_rsa_private_key_file", "serverinfo_name", "serverinfo_sid",
  "serverinfo_description", "serverinfo_network_name",
  "serverinfo_network_desc", "serverinfo_vhost", "serverinfo_vhost6",
  "serverinfo_max_clients", "serverinfo_hub", "admin_entry", "admin_items",
  "admin_item", "admin_name", "admin_email", "admin_description",
  "logging_entry", "logging_items", "logging_item", "logging_path",
  "logging_oper_log", "logging_fuserlog", "logging_ffailed_operlog",
  "logging_foperlog", "logging_foperspylog", "logging_fglinelog",
  "logging_fklinelog", "logging_ioerrlog", "logging_killlog",
  "logging_log_level", "logging_use_logging", "oper_entry", "@1",
  "oper_name_b", "oper_items", "oper_item", "oper_name", "oper_name_t",
  "oper_user", "oper_password", "oper_encrypted",
  "oper_rsa_public_key_file", "oper_class", "oper_umodes", "@2",
  "oper_umodes_items", "oper_umodes_item", "oper_global_kill",
  "oper_remote", "oper_remoteban", "oper_kline", "oper_xline",
  "oper_unkline", "oper_gline", "oper_nick_changes", "oper_die",
  "oper_rehash", "oper_admin", "oper_hidden_admin", "oper_hidden_oper",
  "oper_operwall", "oper_flags", "@3", "oper_flags_items",
  "oper_flags_item", "@4", "@5", "oper_flags_item_atom", "class_entry",
  "@6", "class_name_b", "class_items", "class_item", "class_name",
  "class_name_t", "class_ping_time", "class_ping_warning",
  "class_number_per_ip", "class_connectfreq", "class_max_number",
  "class_max_global", "class_max_local", "class_max_ident", "class_sendq",
  "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6",
  "class_number_per_cidr", "listen_entry", "@7", "listen_flags", "@8",
  "listen_flags_items", "listen_flags_item", "listen_items", "listen_item",
  "listen_port", "port_items", "port_item", "listen_address",
  "listen_host", "auth_entry", "@9", "auth_items", "auth_item",
  "auth_user", "auth_passwd", "auth_spoof_notice", "auth_class",
  "auth_encrypted", "auth_flags", "@10", "auth_flags_items",
  "auth_flags_item", "@11", "@12", "auth_flags_item_atom",
  "auth_kline_exempt", "auth_need_ident", "auth_exceed_limit",
  "auth_can_flood", "auth_no_tilde", "auth_gline_exempt", "auth_spoof",
  "auth_redir_serv", "auth_redir_port", "auth_need_password", "resv_entry",
  "@13", "resv_items", "resv_item", "resv_creason", "resv_channel",
  "resv_nick", "shared_entry", "@14", "shared_items", "shared_item",
  "shared_name", "shared_user", "shared_type", "@15", "shared_types",
  "shared_type_item", "cluster_entry", "@16", "cluster_items",
  "cluster_item", "cluster_name", "cluster_type", "@17", "cluster_types",
  "cluster_type_item", "connect_entry", "@18", "connect_name_b",
  "connect_items", "connect_item", "connect_name", "connect_name_t",
  "connect_host", "connect_vhost", "connect_send_password",
  "connect_accept_password", "connect_port", "connect_aftype",
  "connect_fakename", "connect_flags", "@19", "connect_flags_items",
  "connect_flags_item", "@20", "@21", "connect_flags_item_atom",
  "connect_rsa_public_key_file", "connect_encrypted", "connect_cryptlink",
  "connect_compressed", "connect_auto", "connect_hub_mask",
  "connect_leaf_mask", "connect_class", "connect_cipher_preference",
  "kill_entry", "@22", "kill_type", "@23", "kill_type_items",
  "kill_type_item", "kill_items", "kill_item", "kill_user", "kill_reason",
  "deny_entry", "@24", "deny_items", "deny_item", "deny_ip", "deny_reason",
  "exempt_entry", "exempt_items", "exempt_item", "exempt_ip",
  "gecos_entry", "@25", "gecos_flags", "@26", "gecos_flags_items",
  "gecos_flags_item", "gecos_items", "gecos_item", "gecos_name",
  "gecos_reason", "general_entry", "general_items", "general_item",
  "general_max_watch", "general_gline_min_cidr", "general_gline_min_cidr6",
  "general_burst_away", "general_use_whois_actually",
  "general_reject_hold_time", "general_tkline_expire_notices",
  "general_kill_chase_time_limit", "general_hide_spoof_ips",
  "general_ignore_bogus_ts", "general_disable_remote_commands",
  "general_failed_oper_notice", "general_anti_nick_flood",
  "general_max_nick_time", "general_max_nick_changes",
  "general_max_accept", "general_anti_spam_exit_message_time",
  "general_ts_warn_delta", "general_ts_max_delta",
  "general_havent_read_conf", "general_kline_with_reason",
  "general_kline_reason", "general_invisible_on_connect",
  "general_warn_no_nline", "general_stats_o_oper_only",
  "general_stats_P_oper_only", "general_stats_k_oper_only",
  "general_stats_i_oper_only", "general_pace_wait",
  "general_caller_id_wait", "general_opers_bypass_callerid",
  "general_pace_wait_simple", "general_short_motd",
  "general_no_oper_flood", "general_true_no_oper_flood",
  "general_oper_pass_resv", "general_message_locale", "general_idletime",
  "general_dots_in_ident", "general_max_targets", "general_servlink_path",
  "general_default_cipher_preference", "general_compression_level",
  "general_use_egd", "general_egdpool_path", "general_ping_cookie",
  "general_disable_auth", "general_throttle_time", "general_oper_umodes",
  "@27", "umode_oitems", "umode_oitem", "general_oper_only_umodes", "@28",
  "umode_items", "umode_item", "general_min_nonwildcard",
  "general_min_nonwildcard_simple", "general_default_floodcount",
  "general_client_flood", "general_dot_in_ip6_addr", "gline_entry", "@29",
  "gline_items", "gline_item", "gline_enable", "gline_duration",
  "gline_logging", "@30", "gline_logging_types", "gline_logging_type_item",
  "gline_user", "gline_server", "gline_action", "@31", "gdeny_types",
  "gdeny_type_item", "channel_entry", "channel_items", "channel_item",
  "channel_restrict_channels", "channel_disable_local_channels",
  "channel_use_except", "channel_use_invex", "channel_use_knock",
  "channel_knock_delay", "channel_knock_delay_channel",
  "channel_max_chans_per_user", "channel_quiet_on_ban", "channel_max_bans",
  "channel_default_split_user_count", "channel_default_split_server_count",
  "channel_no_create_on_split", "channel_no_join_on_split",
  "channel_burst_topicwho", "channel_jflood_count", "channel_jflood_time",
  "serverhide_entry", "serverhide_items", "serverhide_item",
  "serverhide_flatten_links", "serverhide_hide_servers",
  "serverhide_hidden_name", "serverhide_links_delay", "serverhide_hidden",
  "serverhide_disable_hidden", "serverhide_hide_server_ips", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,    59,   125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short int yyr1[] =
{
       0,   260,   261,   261,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   263,   263,   264,   264,
     264,   264,   264,   264,   265,   265,   266,   266,   266,   266,
     267,   268,   268,   269,   269,   269,   270,   271,   272,   273,
     273,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   287,   288,   288,   288,
     288,   289,   290,   291,   292,   293,   293,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   305,   305,   305,   305,   305,   305,   306,   308,   307,
     309,   309,   310,   310,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   312,   313,   314,
     315,   316,   317,   318,   320,   319,   321,   321,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     338,   337,   339,   339,   341,   340,   342,   340,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   345,   344,   346,   346,   347,   347,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   364,   363,
     366,   365,   367,   367,   368,   368,   369,   369,   370,   370,
     370,   370,   370,   371,   372,   372,   373,   373,   374,   375,
     377,   376,   378,   378,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   380,   381,   382,   383,   384,   386,   385,   387,   387,
     389,   388,   390,   388,   391,   391,   391,   391,   391,   391,
     391,   391,   391,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   403,   402,   404,   404,   405,   405,
     405,   405,   406,   407,   408,   410,   409,   411,   411,   412,
     412,   412,   412,   413,   414,   416,   415,   417,   417,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     420,   419,   421,   421,   422,   422,   422,   423,   425,   424,
     426,   426,   427,   427,   427,   427,   427,   427,   427,   427,
     427,   427,   427,   429,   428,   430,   430,   431,   431,   432,
     432,   432,   432,   432,   432,   432,   432,   432,   432,   432,
     432,   432,   432,   432,   432,   432,   432,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   440,   441,   443,   442,
     444,   444,   446,   445,   447,   445,   448,   448,   448,   448,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     459,   458,   461,   460,   462,   462,   463,   464,   464,   465,
     465,   465,   465,   466,   467,   469,   468,   470,   470,   471,
     471,   471,   472,   473,   474,   475,   475,   476,   476,   477,
     479,   478,   481,   480,   482,   482,   483,   484,   484,   485,
     485,   485,   485,   486,   487,   488,   489,   489,   490,   490,
     490,   490,   490,   490,   490,   490,   490,   490,   490,   490,
     490,   490,   490,   490,   490,   490,   490,   490,   490,   490,
     490,   490,   490,   490,   490,   490,   490,   490,   490,   490,
     490,   490,   490,   490,   490,   490,   490,   490,   490,   490,
     490,   490,   490,   490,   490,   490,   490,   490,   490,   490,
     490,   490,   490,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   517,   518,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   540,   539,   541,   541,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   544,   543,   545,   545,
     546,   546,   546,   546,   546,   546,   546,   546,   546,   546,
     546,   546,   546,   546,   546,   546,   546,   546,   547,   548,
     549,   550,   551,   553,   552,   554,   554,   555,   555,   555,
     555,   555,   555,   555,   556,   557,   559,   558,   560,   560,
     561,   561,   562,   563,   565,   564,   566,   566,   567,   567,
     568,   569,   569,   570,   570,   570,   570,   570,   570,   570,
     570,   570,   570,   570,   570,   570,   570,   570,   570,   570,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     589,   590,   590,   590,   590,   590,   590,   590,   590,   591,
     592,   593,   594,   595,   596,   597
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     0,     1,     2,     3,
       3,     3,     3,     3,     0,     1,     2,     3,     3,     3,
       5,     2,     1,     1,     1,     2,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     5,     2,     1,     1,     1,     1,
       2,     4,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     7,
       0,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     1,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       0,     5,     3,     1,     0,     3,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     7,     0,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     6,
       0,     5,     3,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     2,     4,     3,     1,     1,     3,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     4,     4,     4,     4,     0,     5,     3,     1,
       0,     3,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     2,     4,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     2,     4,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     2,     1,     1,     1,     2,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     7,     0,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     5,
       3,     1,     0,     3,     0,     2,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       0,     6,     0,     5,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     4,     4,     5,     2,     1,     1,     1,     4,
       0,     6,     0,     5,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     4,     4,     5,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     0,     6,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     0,     5,     3,     1,
       1,     1,     4,     4,     0,     5,     3,     1,     1,     1,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short int yydefact[] =
{
       2,     0,     1,     0,     0,     0,   214,   383,   455,     0,
     470,     0,   643,   270,   440,   248,     0,     0,   118,   324,
       0,     0,   335,   360,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      22,    20,    21,     7,    12,    24,    25,     0,     0,   216,
     385,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,    77,    79,    78,   690,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   672,   685,   673,   674,   675,
     676,   678,   679,   680,   681,   677,   682,   683,   684,   686,
     687,   688,   689,   235,     0,   217,   409,     0,   386,     0,
     468,     0,     0,   466,   467,     0,   543,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     616,     0,   594,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   487,   542,   538,   539,   536,   540,   541,
     537,   498,   488,   489,   527,   490,   491,   492,   493,   494,
     495,   496,   497,   532,   499,   500,   501,   502,   504,   509,
     505,   507,   506,   521,   522,   508,   510,   511,   512,   513,
     515,   514,   503,   517,   526,   528,   529,   518,   519,   534,
     535,   531,   520,   516,   524,   525,   523,   530,   533,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      91,    98,    92,    96,    93,    94,    97,    95,    89,    90,
       0,     0,     0,     0,    42,    43,    44,   148,     0,   121,
       0,   718,     0,     0,     0,     0,     0,     0,     0,     0,
     710,   711,   712,   716,   713,   715,   714,   717,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,    61,    58,    51,    60,    54,    55,    56,    52,
      59,    57,    53,     0,     0,    80,     0,     0,     0,     0,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   671,
       0,     0,   461,     0,     0,     0,   458,   459,   460,     0,
       0,   465,   482,     0,     0,   472,   481,     0,   478,   479,
     480,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   486,   653,   664,
       0,     0,   656,     0,     0,     0,   646,   647,   648,   649,
     650,   651,   652,     0,     0,     0,     0,     0,   296,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   273,   274,   275,   284,   276,   289,   277,   278,   279,
     280,   287,   281,   282,   283,   285,   286,   288,   452,     0,
     442,     0,   451,     0,   448,   449,   450,     0,   250,     0,
       0,     0,   259,     0,   257,   258,   260,   261,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    85,    45,     0,     0,     0,    41,     0,     0,
       0,     0,     0,     0,   327,   328,   329,   330,     0,     0,
       0,     0,     0,     0,     0,     0,   709,    62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,     0,     0,   345,     0,     0,   338,   339,   340,   341,
       0,     0,   368,     0,   363,   364,   365,     0,     0,     0,
      74,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   670,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   219,   220,   223,   224,   226,
     227,   228,   229,   230,   231,   232,   221,   222,   225,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   418,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   388,
     389,   390,   391,   392,   393,   395,   394,   396,   397,   405,
     402,   404,   403,   401,   398,   399,   400,   406,     0,     0,
       0,   457,     0,   464,     0,     0,     0,     0,   477,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,   485,     0,     0,
       0,     0,     0,     0,     0,   645,   290,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   272,     0,     0,     0,     0,   447,
     262,     0,     0,     0,     0,     0,   256,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,     0,     0,    40,     0,
       0,     0,     0,     0,   190,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   154,     0,
       0,     0,     0,   123,   124,   125,   126,   143,   144,   130,
     129,   131,   132,   138,   133,   134,   135,   136,   137,   139,
     140,   141,   127,   128,   142,   145,   331,     0,     0,     0,
       0,   326,     0,     0,     0,     0,     0,     0,     0,   708,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,   342,     0,     0,     0,     0,   337,   366,     0,
       0,     0,   362,    83,    82,    81,   705,   702,   701,   692,
      26,    26,    26,    26,    26,    28,    27,   696,   697,   700,
     698,   703,   704,   706,   707,   699,   691,   693,   694,   695,
     233,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   218,   407,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   387,     0,     0,   456,
     469,     0,     0,     0,   471,   556,   560,   547,   575,   588,
     587,   640,   592,   554,   642,   584,   590,   555,   545,   546,
     563,   552,   583,   553,   566,   551,   565,   564,   559,   558,
     557,   585,   544,   582,   638,   639,   579,   576,   620,   635,
     636,   621,   622,   623,   630,   624,   633,   637,   626,   631,
     627,   632,   625,   629,   628,   634,     0,   619,   581,   598,
     613,   614,   599,   600,   601,   608,   602,   611,   615,   604,
     609,   605,   610,   603,   607,   606,   612,     0,   597,   574,
     577,   591,   549,   586,   550,   578,   572,   573,   570,   571,
     568,   569,   562,   561,    34,    34,    34,    36,    35,   641,
     593,   580,   589,   548,   567,     0,     0,     0,     0,     0,
       0,   644,     0,     0,     0,     0,   302,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   271,     0,
       0,     0,   441,     0,     0,     0,   266,     0,   265,   249,
     103,   109,   107,   106,   108,   104,   105,   102,   110,   116,
     111,   115,   113,   114,   112,   101,   100,   117,    46,    47,
     146,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   122,     0,     0,     0,   325,   724,
     719,   723,   721,   725,   720,   722,    67,    73,    65,    69,
      68,    64,    63,    66,    72,    70,    71,     0,     0,     0,
     336,     0,     0,   361,    29,    30,    31,    32,    33,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   215,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   424,     0,     0,     0,     0,     0,     0,
       0,     0,   384,   462,   463,   483,   484,   476,     0,   475,
     617,     0,   595,     0,    37,    38,    39,   669,   668,     0,
     667,   655,   654,   661,   660,     0,   659,   663,   662,   317,
     294,   295,   316,   300,     0,   299,     0,   319,   315,   314,
     323,   318,   292,   322,   321,   320,   293,   291,   454,   446,
       0,   445,   453,   255,   254,     0,   253,   269,   268,     0,
     263,     0,     0,     0,     0,     0,   196,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   119,   333,   334,   332,   343,   349,
     355,   359,   358,   357,   354,   350,   353,   356,   351,   352,
       0,   348,   344,   367,   372,   378,   382,   381,   380,   377,
     373,   376,   379,   374,   375,     0,   371,   245,   246,   239,
     241,   243,   242,   240,   234,   247,   238,   236,   237,   244,
     413,   415,   416,   435,   439,   438,   434,   433,   432,   417,
     422,     0,   421,     0,   410,   436,   437,   408,   414,   431,
     412,   411,   473,     0,   618,   596,   665,     0,   657,     0,
       0,   297,   302,   308,   309,   305,   311,   307,   306,   313,
     310,   312,   304,   303,   443,     0,   251,     0,   267,   264,
     186,   153,   184,   151,   194,     0,   193,     0,   182,   176,
     187,   188,   179,   147,   183,   150,   185,   177,   178,   152,
     189,   158,   173,   174,   159,   160,   161,   168,   162,   171,
     175,   164,   169,   165,   170,   163,   167,   166,   172,     0,
     157,   181,   149,   180,   346,     0,   369,     0,     0,   419,
     424,   428,   429,   426,   427,   430,   425,   474,   666,   658,
     301,   298,   444,   252,     0,   191,   196,   206,   204,   213,
     203,   198,   207,   211,   200,   208,   210,   205,   199,   212,
     209,   201,   202,   197,   155,     0,   347,   370,   423,   420,
     195,   192,   156
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     1,    24,   885,   886,  1037,  1038,    25,   273,   274,
     275,   276,    26,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,    27,    71,    72,    73,
      74,    75,    28,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,    29,    61,   278,
     812,   813,   814,   279,   815,   816,   817,   818,   819,   820,
    1119,  1409,  1410,   821,   822,   823,   824,   825,   826,   827,
     828,   829,   830,   831,   832,   833,   834,   835,  1105,  1375,
    1376,  1434,  1377,  1453,    30,    49,   114,   604,   605,   606,
     115,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,    31,    58,   492,   761,  1245,  1246,   493,
     494,   495,  1077,  1078,   496,   497,    32,    56,   460,   461,
     462,   463,   464,   465,   466,   467,   741,  1224,  1225,  1350,
    1226,  1363,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,    33,    62,   523,   524,   525,   526,   527,    34,
      65,   555,   556,   557,   558,   559,   864,  1290,  1291,    35,
      66,   563,   564,   565,   566,   870,  1305,  1306,    36,    50,
     117,   638,   639,   640,   118,   641,   642,   643,   644,   645,
     646,   647,   648,   926,  1331,  1332,  1418,  1333,  1426,   649,
     650,   651,   652,   653,   654,   655,   656,   657,    37,    57,
     482,   756,  1240,  1241,   483,   484,   485,   486,    38,    51,
     355,   356,   357,   358,    39,   122,   123,   124,    40,    53,
     366,   666,  1198,  1199,   367,   368,   369,   370,    41,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     406,  1017,  1018,   233,   404,   996,   997,   234,   235,   236,
     237,   238,    42,    55,   435,   436,   437,   438,   439,   731,
    1215,  1216,   440,   441,   442,   728,  1209,  1210,    43,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,    44,   289,
     290,   291,   292,   293,   294,   295,   296,   297
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -854
static const short int yypact[] =
{
    -854,   904,  -854,  -222,  -249,  -244,  -854,  -854,  -854,  -242,
    -854,  -237,  -854,  -854,  -854,  -854,  -235,  -212,  -854,  -854,
    -203,  -194,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,    69,   747,   -73,
     -37,  -132,     4,  -102,   509,   -92,   -87,   -85,   -60,   716,
     134,    71,   -47,   381,   316,   -29,   -27,   -22,   -23,   -13,
      -1,     5,  -854,  -854,  -854,  -854,  -854,    21,    26,    30,
      31,    43,    46,    49,    52,    57,    58,    60,    67,    73,
      77,    79,    81,    83,   268,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,   -21,  -854,  -854,    40,  -854,    17,
    -854,    92,    10,  -854,  -854,   222,  -854,    94,    96,    97,
      98,   106,   109,   110,   111,   112,   114,   115,   118,   119,
     121,   125,   126,   128,   130,   135,   140,   142,   147,   152,
     153,   157,   158,   159,   161,   162,   173,   175,   177,   180,
    -854,   183,  -854,   184,   185,   187,   189,   191,   193,   196,
     197,   198,   199,   201,   206,   208,   211,   212,   220,   225,
     227,   232,    16,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,    65,
     802,    70,    25,    -5,   233,   236,   238,   247,   248,   249,
     250,   251,   253,   254,   258,   264,    90,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
      22,   265,   267,    42,  -854,  -854,  -854,  -854,   167,  -854,
     215,  -854,   269,   271,   272,   273,   274,   275,   276,   194,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,    23,   277,
     278,   280,   285,   286,   287,   288,   289,   291,   292,   296,
     221,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,     8,    20,  -854,   170,   298,   326,   137,
    -854,   252,   360,   394,   346,   424,   424,   425,   426,   365,
     366,   430,   424,   369,   370,   376,   377,   378,   318,  -854,
     763,   712,  -854,   317,   320,    29,  -854,  -854,  -854,   428,
     324,  -854,  -854,   325,   328,  -854,  -854,    63,  -854,  -854,
    -854,   390,   424,   395,   424,   456,   437,   461,   400,   401,
     406,   471,   452,   413,   476,   477,   478,   417,   424,   418,
     421,   484,   463,   434,   487,   490,   424,   497,   499,   479,
     502,   503,   442,   445,   382,   447,   387,   424,   424,   454,
     424,   492,   457,   459,   -72,   -58,   460,   464,   424,   424,
     529,   424,   468,   469,   470,   472,   410,  -854,  -854,  -854,
     411,   415,  -854,   419,   420,    37,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,   416,   422,   423,   435,   436,  -854,   438,
     439,   440,   446,   450,   451,   453,   458,   465,   467,   474,
     331,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,   475,
    -854,   482,  -854,    56,  -854,  -854,  -854,   427,  -854,   483,
     486,   488,  -854,    11,  -854,  -854,  -854,  -854,  -854,   514,
     521,   522,   525,   530,   532,   534,   538,   282,   549,   551,
     489,   455,  -854,  -854,   565,   567,   473,  -854,   564,   480,
     491,   493,   494,    55,  -854,  -854,  -854,  -854,   535,   536,
     540,   588,   556,   561,   424,   504,  -854,  -854,   608,   573,
     614,   615,   616,   617,   626,   629,   658,   637,   638,   539,
    -854,   542,   541,  -854,   543,    39,  -854,  -854,  -854,  -854,
     545,   544,  -854,    18,  -854,  -854,  -854,   550,   553,   554,
    -854,   555,   557,   558,   560,   188,   562,   563,   566,   568,
     569,   570,   571,   572,   574,   575,   576,   579,   580,  -854,
     582,   546,   583,   584,   585,   589,   590,   591,   592,   599,
     601,   602,   603,   604,    66,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,   609,
     605,   611,   620,   622,   623,   624,   625,   627,   630,  -854,
     632,   635,   641,   642,   643,   645,   648,   649,   237,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,   684,   686,
     612,  -854,   640,  -854,   733,   754,   652,   657,  -854,   661,
     662,   663,   664,   665,   666,   667,   668,   670,   672,   673,
     674,   680,   681,   682,   683,   687,   688,   690,   691,   692,
     693,   694,   696,   697,   699,   701,   702,   703,   706,   708,
     710,   711,   828,   715,   865,   717,   718,   719,   721,   722,
     724,   725,   726,   727,   728,   729,   730,   731,   732,   741,
     333,   742,   743,   744,   745,   746,   748,  -854,   655,   424,
     773,   752,   787,   834,   749,  -854,  -854,   808,   852,   817,
     818,   755,   824,   825,   826,   827,   829,   868,   734,   871,
     872,   839,   874,   781,  -854,   886,   785,   890,   791,  -854,
    -854,   789,   894,   895,   918,   796,  -854,   803,   804,   806,
     807,   809,   810,   815,   822,   823,   830,   831,   840,   841,
     843,   844,   850,   853,   857,  -854,   858,   860,  -854,   861,
     859,   862,   863,   864,  -854,   873,   875,   876,   878,   879,
     880,   881,   882,   883,   884,   885,   887,   888,  -854,   889,
     891,   892,   166,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,   926,   927,   930,
     893,  -854,   896,   897,   898,   899,   901,   902,   903,  -854,
     905,   906,   907,   908,   909,   910,   911,   912,   913,   914,
     915,  -854,  -854,   964,   916,   965,   917,  -854,  -854,   969,
     919,   920,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
     424,   424,   424,   424,   424,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,   998,  1012,   424,  1023,  1027,  1039,  1041,  1022,  1046,
    1047,   424,   424,   529,   925,  -854,  -854,  1028,   -69,   987,
    1029,  1030,   991,   992,   993,  1034,   931,  1036,  1037,  1038,
    1040,  1061,  1042,  1043,  1044,   940,  -854,   944,   945,  -854,
    -854,   946,   947,  1045,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -245,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -232,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,   529,   529,   529,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,    -8,   948,   950,    -7,   951,
     952,  -854,   953,   954,   955,   956,  1081,   958,   959,   960,
     961,   962,   963,   966,   967,   968,   970,   971,  -854,   972,
    1060,   973,  -854,   -61,   974,   975,  1021,  -223,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  1048,  1070,  1049,  1050,   976,  1051,  1052,  1053,  1054,
    1055,  1077,  1056,  1078,  1057,  1058,  1059,  1079,  1062,   977,
    1063,  1082,  1064,   982,  -854,   983,   984,   985,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,   986,   234,   999,
    -854,  1000,   775,  -854,  -854,  -854,  -854,  -854,  -854,  1004,
    1005,  1006,  1007,  1008,  1009,  1010,  1011,  1013,  1014,  1015,
    1016,  1017,  -854,  1018,  1019,  1020,  1024,  1025,  1026,  1031,
    1032,  1033,  1035,  1136,  1065,  1066,  1067,  1068,  1069,  1071,
    1072,  1073,  -854,  -854,  -854,  -854,  -854,  -854,  -208,  -854,
    -854,   828,  -854,   865,  -854,  -854,  -854,  -854,  -854,  -181,
    -854,  -854,  -854,  -854,  -854,  -179,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -162,  -854,   764,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -157,  -854,  -854,  -854,  -854,  -141,  -854,  -854,  -854,  1144,
    -854,   918,  1074,  1075,  1076,  1080,  1146,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,
     900,  1096,  1097,  1098,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -135,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -117,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,   -28,  -854,    19,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  1045,  -854,  -854,  -854,    -8,  -854,    -7,
     764,  -854,  1081,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  1060,  -854,   -61,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,    41,  -854,   594,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,    75,
    -854,  -854,  -854,  -854,  -854,   234,  -854,   775,    19,  -854,
    1136,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,   594,  -854,  1146,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,   900,  -854,  -854,  -854,  -854,
    -854,  -854,  -854
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -854,  -854,  -854,  -454,  -335,  -853,  -418,  -854,  -854,  1099,
    -854,  -854,  -854,  -854,   979,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  1207,  -854,
    -854,  -854,  -854,  -854,  1100,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,   481,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -173,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -153,  -854,  -854,  -150,  -854,  -854,  -854,  -854,   695,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,   -82,  -854,
     798,  -854,  -854,    44,  -854,  -854,  -854,  -854,  -854,   832,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,   -56,  -854,
    -854,   -53,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,   771,  -854,  -854,  -854,  -854,
    -854,  -854,   750,  -854,  -854,  -854,  -854,  -854,  -115,  -854,
    -854,  -854,   735,  -854,  -854,  -854,  -854,  -116,  -854,  -854,
    -854,  -854,   669,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -118,  -854,  -854,  -114,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,   -62,  -854,   833,  -854,  -854,  -854,  -854,
    -854,   957,  -854,  -854,  -854,  -854,  1184,  -854,  -854,  -854,
    -854,  -854,  -854,   -35,  -854,   942,  -854,  -854,  -854,  -854,
    1128,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,   108,  -854,  -854,  -854,   113,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,   922,  -854,  -854,  -854,  -854,
    -854,   -36,  -854,  -854,  -854,  -854,  -854,   -32,  -854,  -854,
    1223,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    1101,  -854,  -854,  -854,  -854,  -854,  -854,  -854
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned short int yytable[] =
{
     576,   577,   721,  1207,  1213,   120,    67,   583,    47,   551,
    1200,   120,   487,    48,  1201,    52,  1243,   126,   352,   560,
      54,   560,    59,  1202,   127,   128,   487,  1203,   129,  1421,
     352,  1422,  1250,    45,    46,   130,  1251,   670,   428,   672,
     551,   429,    68,   270,   131,    60,  1423,  1342,   132,   133,
    1424,  1343,    69,   686,    63,   134,   519,   478,   135,   136,
     137,   694,   138,    64,   362,   488,   428,   590,   139,   429,
      67,   478,   705,   706,  1346,   708,  1348,   520,  1347,   488,
    1349,   113,   430,   718,   719,   431,   722,   140,   141,   591,
     592,   243,   142,  1351,   121,   489,   593,  1352,  1364,   143,
     121,   490,  1365,   144,   145,   146,    68,   353,   147,   489,
     430,   148,   149,   431,  1366,   490,    69,   116,  1367,   353,
    1414,   150,   712,   713,  1415,   119,    70,   151,   152,   552,
     153,   154,   155,   156,   157,   270,   714,   715,  1416,   561,
     432,   561,  1417,  1174,  1175,   158,   244,   245,   246,   247,
     248,   249,   250,   251,   159,   125,   160,   161,   433,   162,
     552,   271,   163,   164,   491,   239,   165,   789,   432,  1244,
     240,   790,   241,   354,   594,   595,   596,   166,   491,   597,
     521,  1204,  1205,  1206,   363,   354,   433,   598,  1208,  1214,
      70,   272,   791,   553,   252,   281,   167,   242,   168,   848,
     599,   600,   169,   562,   792,   562,   170,   171,   172,   173,
     280,   522,   479,   174,   175,   793,   519,   601,   602,   364,
     794,   176,   298,   362,   553,   277,   479,  1419,   323,   253,
     324,  1420,   795,   325,   282,   326,   350,   520,   619,   796,
     620,   480,   603,   621,   797,   327,   798,   622,   365,   283,
     498,   554,   177,   271,   178,   480,  1425,   328,   299,   799,
     179,   329,   623,   624,   625,   180,   360,   765,   626,    76,
     181,   284,   426,   285,   871,   286,   287,   513,   537,   331,
     434,    77,   554,   272,   332,   660,   627,   800,   333,   334,
     628,   629,   801,   734,   288,   866,  1435,   351,   516,   481,
    1436,   335,    78,    79,   336,   254,   300,   337,   434,    80,
     338,   840,   758,   481,   802,   339,   340,   298,   341,   667,
     575,   630,   914,   631,   567,   342,   803,  1279,   804,   805,
    1454,   343,   443,   806,  1455,   344,   632,   345,   255,   346,
     521,   347,   301,   363,   302,   303,   511,  1034,  1035,  1036,
     359,   444,   371,   299,   372,   373,   374,   445,   633,   880,
     881,   882,   883,   884,   375,    81,    82,   376,   377,   378,
     379,   522,   380,   381,    83,    84,   382,   383,   364,   384,
     446,   447,   281,   385,   386,   448,   387,   304,   388,   305,
     634,   807,   570,   389,  1046,    85,    86,   808,   390,   449,
     391,   300,   306,  1280,   635,   392,   450,   365,   809,   810,
     393,   394,    87,    88,   636,   395,   396,   397,   811,   398,
     399,   282,  1123,    89,   518,   451,  1154,  1155,  1156,  1157,
    1158,   400,    90,   401,  1281,   402,   283,   301,   403,   302,
     303,   405,   407,   408,   307,   409,   571,   410,  1282,   411,
     535,   412,   568,   452,   413,   414,   415,   416,   284,   417,
     285,   453,   286,   287,   418,   720,   419,  1283,  1284,   420,
     421,   308,   309,  1285,  1286,  1287,  1288,   549,   422,   454,
     569,   288,   304,   423,   305,   424,  1289,   637,   455,   456,
     425,   499,   572,   935,   500,  1171,   501,   306,   775,   776,
     777,   778,   779,   780,   781,   502,   503,   504,   505,   506,
     126,   507,   508,    91,    92,    93,   509,   127,   128,   457,
     458,   129,   510,   514,   348,   515,   573,   528,   130,   529,
     530,   531,   532,   533,   534,   538,   539,   131,   540,   307,
     574,   132,   133,   541,   542,   543,   544,   545,   134,   546,
     547,   135,   136,   137,   548,   138,   575,   578,   579,   580,
     581,   139,   582,   584,   585,   789,   308,   309,  1161,   790,
     586,   587,   588,   589,   459,   658,  1169,  1170,   659,   663,
     140,   141,   662,   664,   669,   142,   665,   753,   673,   671,
     791,   674,   143,   675,   676,   677,   144,   145,   146,  1437,
     678,   147,   792,   679,   148,   149,   680,   681,   682,   683,
     684,   685,   687,   793,   150,   688,   689,   690,   794,   692,
     151,   152,   693,   153,   154,   155,   156,   157,   691,   695,
     795,   696,  1438,   697,   698,   699,   700,   796,   158,   701,
     702,   703,   797,  1439,   798,   704,   709,   159,   707,   160,
     161,   710,   162,   711,   716,   163,   164,   799,   717,   165,
    1440,   720,   723,   724,   725,   727,   726,  1441,   767,   729,
     166,   736,  1442,   730,  1443,   768,   769,   732,   733,   770,
     737,   738,   760,   784,   771,   800,   772,  1444,   773,   167,
     801,   168,   774,   739,   740,   169,   742,   743,   744,   170,
     171,   172,   173,   782,   745,   783,   174,   175,   746,   747,
     785,   748,   802,   619,   176,   620,   749,   243,   621,   786,
    1445,   787,   622,   750,   803,   751,   804,   805,   788,   842,
     843,   806,   752,   755,   844,   836,  1446,   623,   624,   625,
     757,   762,   845,   626,   763,   177,   764,   178,    76,   837,
     846,   838,   839,   179,  1447,   847,  1448,  1449,   180,   849,
      77,   627,   850,   181,   590,   628,   629,   851,   852,   853,
     854,   855,   244,   245,   246,   247,   248,   249,   250,   251,
     856,    78,    79,   857,  1353,  1354,   591,   592,    80,   807,
     858,   859,   860,   593,   861,   808,   630,   862,   631,   863,
     868,   865,   869,   443,   901,   873,   809,   810,   874,   875,
     876,   632,   877,   878,  1355,   879,   811,   887,   888,  1450,
     252,   889,   444,   890,   891,   892,   893,   894,   445,   895,
     896,   897,  1356,   633,   898,   899,  1451,   900,   937,  1357,
     938,   902,   903,   904,    81,    82,  1452,   905,   906,   907,
     908,   446,   447,    83,    84,   253,   448,   909,  1358,   910,
     911,   912,   913,   917,   916,   634,  1063,   939,  1294,   918,
     449,   594,   595,   596,    85,    86,   597,   450,   919,   635,
     920,   921,   922,   923,   598,   924,  1359,   941,   925,   636,
     927,    87,    88,   928,  1360,   940,   451,   599,   600,   929,
     930,   931,    89,   932,     2,     3,   933,   934,   942,     4,
     943,    90,   944,  1045,   601,   602,   945,   946,   947,   948,
     949,   950,   951,   952,   452,   953,     5,   954,   955,   956,
       6,   254,   453,     7,  1361,   957,   958,   959,   960,   603,
       8,  1049,   961,   962,  1295,   963,   964,   965,   966,   967,
     454,   968,   969,  1362,   970,     9,   971,   972,   973,   455,
     456,   974,   637,   975,   255,   976,   977,  1047,    10,    11,
     998,    12,  1019,  1020,  1021,  1296,  1022,  1023,    13,  1024,
    1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,  1050,  1297,
     457,   458,    91,    92,    93,    14,  1033,  1039,  1040,  1041,
    1042,  1043,  1052,  1044,  1051,    15,  1053,    16,  1298,  1299,
    1048,  1054,  1055,  1056,  1300,  1301,  1302,  1303,  1057,  1058,
    1059,  1060,  1062,  1061,    17,  1064,  1065,  1304,  1067,   978,
     979,   980,   981,  1066,   982,   983,  1068,   984,   985,   986,
    1069,    18,   987,  1070,  1071,   459,  1072,  1073,  1074,  1075,
    1076,  1079,   988,   989,   990,   991,   992,   993,  1080,  1081,
     994,  1082,  1083,   995,  1084,  1085,   999,  1000,  1001,  1002,
    1086,  1003,  1004,    19,  1005,  1006,  1007,  1087,  1088,  1008,
    1125,  1126,    20,    21,  1127,  1089,  1090,    22,    23,  1009,
    1010,  1011,  1012,  1013,  1014,  1091,  1092,  1015,  1093,  1094,
    1016,  1391,  1392,  1393,  1394,  1095,  1395,  1396,  1096,  1397,
    1398,  1399,  1097,  1098,  1400,  1099,  1100,  1101,  1147,  1149,
    1102,  1103,  1104,  1151,  1401,  1402,  1403,  1404,  1405,  1406,
    1159,  1106,  1407,  1107,  1108,  1408,  1109,  1110,  1111,  1112,
    1113,  1114,  1115,  1116,  1160,  1117,  1118,  1120,  1128,  1121,
    1122,  1129,  1130,  1131,  1132,  1162,  1133,  1134,  1135,  1163,
    1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,  1144,  1145,
    1146,  1164,  1150,  1165,  1148,  1153,  1166,  1152,  1167,  1168,
    1172,  1176,  1173,  1177,  1178,  1179,  1180,  1181,  1182,  1183,
    1184,  1185,  1186,  1188,  1187,  1192,  1189,  1190,  1191,  1193,
    1194,  1195,  1196,  1211,  1197,  1212,  1217,  1218,  1219,  1220,
    1221,  1222,  1223,  1227,  1228,  1229,  1230,  1231,  1232,  1239,
    1249,  1233,  1234,  1235,  1253,  1236,  1237,  1238,  1242,  1247,
    1248,  1262,  1264,  1268,  1256,  1270,  1272,  1274,  1275,  1276,
    1277,  1278,  1252,  1254,  1255,  1257,  1258,  1259,  1260,  1261,
    1263,  1265,  1266,  1267,  1292,  1293,  1269,  1271,  1273,  1307,
    1308,  1309,  1310,  1311,  1312,  1313,  1314,  1330,  1315,  1316,
    1317,  1318,  1319,  1320,  1321,  1322,  1368,  1374,   330,  1323,
    1324,  1325,  1462,  1461,  1460,  1433,  1326,  1327,  1328,   550,
    1329,   766,   754,  1124,   841,  1369,  1431,  1430,   872,   915,
    1456,  1457,  1459,  1432,  1458,   867,   361,   936,  1427,   668,
     427,  1345,   661,  1429,  1344,  1428,   759,   349,     0,     0,
    1334,  1335,  1336,  1337,  1338,     0,  1339,  1340,  1341,  1370,
    1371,  1372,     0,     0,     0,  1373,     0,     0,  1378,  1379,
    1380,  1381,  1382,  1383,  1384,  1385,  1386,  1387,  1388,  1389,
    1390,  1411,  1412,  1413,     0,     0,   512,   735,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   517,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     536
};

static const short int yycheck[] =
{
     335,   336,   420,    11,    11,     1,     1,   342,   257,     1,
     255,     1,     1,   257,   259,   257,    77,     1,     1,     1,
     257,     1,   257,   255,     8,     9,     1,   259,    12,    10,
       1,    12,   255,   255,   256,    19,   259,   372,     1,   374,
       1,     4,    37,     1,    28,   257,    27,   255,    32,    33,
      31,   259,    47,   388,   257,    39,     1,     1,    42,    43,
      44,   396,    46,   257,     1,    54,     1,     1,    52,     4,
       1,     1,   407,   408,   255,   410,   255,    22,   259,    54,
     259,   154,    45,   418,   419,    48,   421,    71,    72,    23,
      24,     1,    76,   255,    90,    84,    30,   259,   255,    83,
      90,    90,   259,    87,    88,    89,    37,    90,    92,    84,
      45,    95,    96,    48,   255,    90,    47,   154,   259,    90,
     255,   105,   194,   195,   259,   257,   121,   111,   112,   121,
     114,   115,   116,   117,   118,     1,   194,   195,   255,   121,
     103,   121,   259,   212,   213,   129,    56,    57,    58,    59,
      60,    61,    62,    63,   138,   257,   140,   141,   121,   143,
     121,   119,   146,   147,   153,   257,   150,     1,   103,   230,
     257,     5,   257,   156,   108,   109,   110,   161,   153,   113,
     125,  1034,  1035,  1036,   121,   156,   121,   121,   196,   196,
     121,   149,    26,   185,   104,     1,   180,   257,   182,   534,
     134,   135,   186,   185,    38,   185,   190,   191,   192,   193,
     257,   156,   156,   197,   198,    49,     1,   151,   152,   156,
      54,   205,     1,     1,   185,   154,   156,   255,   257,   139,
     257,   259,    66,   255,    40,   258,   257,    22,     1,    73,
       3,   185,   176,     6,    78,   258,    80,    10,   185,    55,
     255,   243,   236,   119,   238,   185,   237,   258,    37,    93,
     244,   256,    25,    26,    27,   249,   256,   256,    31,     1,
     254,    77,   256,    79,   256,    81,    82,   255,   255,   258,
     243,    13,   243,   149,   258,   256,    49,   121,   258,   258,
      53,    54,   126,   256,   100,   256,   255,   257,   256,   243,
     259,   258,    34,    35,   258,   215,    85,   258,   243,    41,
     258,   256,   256,   243,   148,   258,   258,     1,   258,   256,
     132,    84,   256,    86,   154,   258,   160,    93,   162,   163,
     255,   258,     1,   167,   259,   258,    99,   258,   248,   258,
     125,   258,   121,   121,   123,   124,   256,    14,    15,    16,
     258,    20,   258,    37,   258,   258,   258,    26,   121,   171,
     172,   173,   174,   175,   258,    97,    98,   258,   258,   258,
     258,   156,   258,   258,   106,   107,   258,   258,   156,   258,
      49,    50,     1,   258,   258,    54,   258,   166,   258,   168,
     153,   225,   255,   258,   729,   127,   128,   231,   258,    68,
     258,    85,   181,   169,   167,   258,    75,   185,   242,   243,
     258,   258,   144,   145,   177,   258,   258,   258,   252,   258,
     258,    40,   256,   155,   257,    94,   880,   881,   882,   883,
     884,   258,   164,   258,   200,   258,    55,   121,   258,   123,
     124,   258,   258,   258,   223,   258,   194,   258,   214,   258,
     256,   258,   154,   122,   258,   258,   258,   258,    77,   258,
      79,   130,    81,    82,   258,   132,   258,   233,   234,   258,
     258,   250,   251,   239,   240,   241,   242,   256,   258,   148,
     154,   100,   166,   258,   168,   258,   252,   250,   157,   158,
     258,   258,   132,   256,   258,   913,   258,   181,   216,   217,
     218,   219,   220,   221,   222,   258,   258,   258,   258,   258,
       1,   258,   258,   245,   246,   247,   258,     8,     9,   188,
     189,    12,   258,   258,   256,   258,   132,   258,    19,   258,
     258,   258,   258,   258,   258,   258,   258,    28,   258,   223,
     194,    32,    33,   258,   258,   258,   258,   258,    39,   258,
     258,    42,    43,    44,   258,    46,   132,   132,   132,   194,
     194,    52,   132,   194,   194,     1,   250,   251,   903,     5,
     194,   194,   194,   255,   243,   258,   911,   912,   258,   255,
      71,    72,   154,   258,   194,    76,   258,   256,   132,   194,
      26,   154,    83,   132,   194,   194,    87,    88,    89,     5,
     194,    92,    38,   132,    95,    96,   154,   194,   132,   132,
     132,   194,   194,    49,   105,   194,   132,   154,    54,   132,
     111,   112,   132,   114,   115,   116,   117,   118,   194,   132,
      66,   132,    38,   154,   132,   132,   194,    73,   129,   194,
     258,   194,    78,    49,    80,   258,   154,   138,   194,   140,
     141,   194,   143,   194,   194,   146,   147,    93,   194,   150,
      66,   132,   194,   194,   194,   255,   194,    73,   154,   258,
     161,   255,    78,   258,    80,   154,   154,   258,   258,   154,
     258,   258,   255,   194,   154,   121,   154,    93,   154,   180,
     126,   182,   154,   258,   258,   186,   258,   258,   258,   190,
     191,   192,   193,   154,   258,   154,   197,   198,   258,   258,
     255,   258,   148,     1,   205,     3,   258,     1,     6,   154,
     126,   154,    10,   258,   160,   258,   162,   163,   255,   194,
     194,   167,   258,   258,   194,   255,   142,    25,    26,    27,
     258,   258,   154,    31,   258,   236,   258,   238,     1,   258,
     194,   258,   258,   244,   160,   194,   162,   163,   249,   255,
      13,    49,   154,   254,     1,    53,    54,   194,   154,   154,
     154,   154,    56,    57,    58,    59,    60,    61,    62,    63,
     154,    34,    35,   154,    20,    21,    23,    24,    41,   225,
     132,   154,   154,    30,   255,   231,    84,   255,    86,   258,
     255,   258,   258,     1,   258,   255,   242,   243,   255,   255,
     255,    99,   255,   255,    50,   255,   252,   255,   255,   225,
     104,   255,    20,   255,   255,   255,   255,   255,    26,   255,
     255,   255,    68,   121,   255,   255,   242,   255,   154,    75,
     154,   258,   258,   258,    97,    98,   252,   258,   258,   258,
     258,    49,    50,   106,   107,   139,    54,   258,    94,   258,
     258,   258,   258,   258,   255,   153,   132,   255,    93,   258,
      68,   108,   109,   110,   127,   128,   113,    75,   258,   167,
     258,   258,   258,   258,   121,   258,   122,   154,   258,   177,
     258,   144,   145,   258,   130,   255,    94,   134,   135,   258,
     258,   258,   155,   258,     0,     1,   258,   258,   154,     5,
     258,   164,   255,   258,   151,   152,   255,   255,   255,   255,
     255,   255,   255,   255,   122,   255,    22,   255,   255,   255,
      26,   215,   130,    29,   170,   255,   255,   255,   255,   176,
      36,   154,   255,   255,   169,   255,   255,   255,   255,   255,
     148,   255,   255,   189,   255,    51,   255,   255,   255,   157,
     158,   255,   250,   255,   248,   255,   255,   194,    64,    65,
     255,    67,   255,   255,   255,   200,   255,   255,    74,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   154,   214,
     188,   189,   245,   246,   247,    91,   255,   255,   255,   255,
     255,   255,   194,   255,   255,   101,   154,   103,   233,   234,
     258,   194,   194,   258,   239,   240,   241,   242,   194,   194,
     194,   194,   154,   194,   120,   154,   154,   252,   154,   201,
     202,   203,   204,   194,   206,   207,   255,   209,   210,   211,
     154,   137,   214,   258,   154,   243,   255,   258,   154,   154,
     132,   255,   224,   225,   226,   227,   228,   229,   255,   255,
     232,   255,   255,   235,   255,   255,   201,   202,   203,   204,
     255,   206,   207,   169,   209,   210,   211,   255,   255,   214,
     154,   154,   178,   179,   154,   255,   255,   183,   184,   224,
     225,   226,   227,   228,   229,   255,   255,   232,   255,   255,
     235,   201,   202,   203,   204,   255,   206,   207,   255,   209,
     210,   211,   255,   255,   214,   255,   255,   258,   154,   154,
     258,   258,   258,   154,   224,   225,   226,   227,   228,   229,
     132,   258,   232,   258,   258,   235,   258,   258,   258,   258,
     258,   258,   258,   258,   132,   258,   258,   258,   255,   258,
     258,   255,   255,   255,   255,   132,   255,   255,   255,   132,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   132,   255,   132,   258,   255,   154,   258,   132,   132,
     255,   194,   154,   154,   154,   194,   194,   194,   154,   258,
     154,   154,   154,   132,   154,   255,   154,   154,   154,   255,
     255,   255,   255,   255,   159,   255,   255,   255,   255,   255,
     255,   255,   131,   255,   255,   255,   255,   255,   255,   159,
     199,   255,   255,   255,   154,   255,   255,   255,   255,   255,
     255,   154,   154,   154,   258,   258,   154,   255,   255,   255,
     255,   255,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   255,   255,   194,   194,   194,   255,
     255,   255,   255,   255,   255,   255,   255,   131,   255,   255,
     255,   255,   255,   255,   255,   255,   132,   131,    71,   255,
     255,   255,  1455,  1436,  1434,  1367,   255,   255,   255,   310,
     255,   493,   460,   812,   523,  1251,  1352,  1350,   563,   604,
    1415,  1417,  1420,  1365,  1418,   555,   122,   638,  1343,   367,
     182,  1203,   355,  1349,  1201,  1347,   483,    94,    -1,    -1,
     255,   255,   255,   255,   255,    -1,   255,   255,   255,   255,
     255,   255,    -1,    -1,    -1,   255,    -1,    -1,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,    -1,    -1,   256,   435,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     289
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short int yystos[] =
{
       0,   261,     0,     1,     5,    22,    26,    29,    36,    51,
      64,    65,    67,    74,    91,   101,   103,   120,   137,   169,
     178,   179,   183,   184,   262,   267,   272,   286,   292,   307,
     344,   363,   376,   402,   409,   419,   428,   458,   468,   474,
     478,   488,   552,   568,   588,   255,   256,   257,   257,   345,
     429,   469,   257,   479,   257,   553,   377,   459,   364,   257,
     257,   308,   403,   257,   257,   410,   420,     1,    37,    47,
     121,   287,   288,   289,   290,   291,     1,    13,    34,    35,
      41,    97,    98,   106,   107,   127,   128,   144,   145,   155,
     164,   245,   246,   247,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   154,   346,   350,   154,   430,   434,   257,
       1,    90,   475,   476,   477,   257,     1,     8,     9,    12,
      19,    28,    32,    33,    39,    42,    43,    44,    46,    52,
      71,    72,    76,    83,    87,    88,    89,    92,    95,    96,
     105,   111,   112,   114,   115,   116,   117,   118,   129,   138,
     140,   141,   143,   146,   147,   150,   161,   180,   182,   186,
     190,   191,   192,   193,   197,   198,   205,   236,   238,   244,
     249,   254,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   543,   547,   548,   549,   550,   551,   257,
     257,   257,   257,     1,    56,    57,    58,    59,    60,    61,
      62,    63,   104,   139,   215,   248,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
       1,   119,   149,   268,   269,   270,   271,   154,   309,   313,
     257,     1,    40,    55,    77,    79,    81,    82,   100,   589,
     590,   591,   592,   593,   594,   595,   596,   597,     1,    37,
      85,   121,   123,   124,   166,   168,   181,   223,   250,   251,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   257,   257,   255,   258,   258,   258,   256,
     288,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   256,   570,
     257,   257,     1,    90,   156,   470,   471,   472,   473,   258,
     256,   476,     1,   121,   156,   185,   480,   484,   485,   486,
     487,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   544,   258,   540,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   256,   490,     1,     4,
      45,    48,   103,   121,   243,   554,   555,   556,   557,   558,
     562,   563,   564,     1,    20,    26,    49,    50,    54,    68,
      75,    94,   122,   130,   148,   157,   158,   188,   189,   243,
     378,   379,   380,   381,   382,   383,   384,   385,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,     1,   156,
     185,   243,   460,   464,   465,   466,   467,     1,    54,    84,
      90,   153,   365,   369,   370,   371,   374,   375,   255,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   256,   294,   255,   258,   258,   256,   269,   257,     1,
      22,   125,   156,   404,   405,   406,   407,   408,   258,   258,
     258,   258,   258,   258,   258,   256,   590,   255,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   256,
     274,     1,   121,   185,   243,   411,   412,   413,   414,   415,
       1,   121,   185,   421,   422,   423,   424,   154,   154,   154,
     255,   194,   132,   132,   194,   132,   264,   264,   132,   132,
     194,   194,   132,   264,   194,   194,   194,   194,   194,   255,
       1,    23,    24,    30,   108,   109,   110,   113,   121,   134,
     135,   151,   152,   176,   347,   348,   349,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,     1,
       3,     6,    10,    25,    26,    27,    31,    49,    53,    54,
      84,    86,    99,   121,   153,   167,   177,   250,   431,   432,
     433,   435,   436,   437,   438,   439,   440,   441,   442,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   258,   258,
     256,   471,   154,   255,   258,   258,   481,   256,   485,   194,
     264,   194,   264,   132,   154,   132,   194,   194,   194,   132,
     154,   194,   132,   132,   132,   194,   264,   194,   194,   132,
     154,   194,   132,   132,   264,   132,   132,   154,   132,   132,
     194,   194,   258,   194,   258,   264,   264,   194,   264,   154,
     194,   194,   194,   195,   194,   195,   194,   194,   264,   264,
     132,   266,   264,   194,   194,   194,   194,   255,   565,   258,
     258,   559,   258,   258,   256,   555,   255,   258,   258,   258,
     258,   386,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   256,   379,   258,   461,   258,   256,   465,
     255,   366,   258,   258,   258,   256,   370,   154,   154,   154,
     154,   154,   154,   154,   154,   216,   217,   218,   219,   220,
     221,   222,   154,   154,   194,   255,   154,   154,   255,     1,
       5,    26,    38,    49,    54,    66,    73,    78,    80,    93,
     121,   126,   148,   160,   162,   163,   167,   225,   231,   242,
     243,   252,   310,   311,   312,   314,   315,   316,   317,   318,
     319,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   255,   258,   258,   258,
     256,   405,   194,   194,   194,   154,   194,   194,   264,   255,
     154,   194,   154,   154,   154,   154,   154,   154,   132,   154,
     154,   255,   255,   258,   416,   258,   256,   412,   255,   258,
     425,   256,   422,   255,   255,   255,   255,   255,   255,   255,
     171,   172,   173,   174,   175,   263,   264,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   256,   348,   255,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   443,   258,   258,   258,
     258,   258,   258,   258,   258,   256,   432,   154,   154,   255,
     255,   154,   154,   258,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   201,   202,
     203,   204,   206,   207,   209,   210,   211,   214,   224,   225,
     226,   227,   228,   229,   232,   235,   545,   546,   255,   201,
     202,   203,   204,   206,   207,   209,   210,   211,   214,   224,
     225,   226,   227,   228,   229,   232,   235,   541,   542,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,    14,    15,    16,   265,   266,   255,
     255,   255,   255,   255,   255,   258,   264,   194,   258,   154,
     154,   255,   194,   154,   194,   194,   258,   194,   194,   194,
     194,   194,   154,   132,   154,   154,   194,   154,   255,   154,
     258,   154,   255,   258,   154,   154,   132,   372,   373,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   258,   258,   258,   258,   338,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   320,
     258,   258,   258,   256,   311,   154,   154,   154,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   154,   258,   154,
     255,   154,   258,   255,   263,   263,   263,   263,   263,   132,
     132,   264,   132,   132,   132,   132,   154,   132,   132,   264,
     264,   266,   255,   154,   212,   213,   194,   154,   154,   194,
     194,   194,   154,   258,   154,   154,   154,   154,   132,   154,
     154,   154,   255,   255,   255,   255,   255,   159,   482,   483,
     255,   259,   255,   259,   265,   265,   265,    11,   196,   566,
     567,   255,   255,    11,   196,   560,   561,   255,   255,   255,
     255,   255,   255,   131,   387,   388,   390,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   159,
     462,   463,   255,    77,   230,   367,   368,   255,   255,   199,
     255,   259,   194,   154,   194,   194,   258,   194,   194,   194,
     194,   194,   154,   194,   154,   194,   194,   194,   154,   194,
     258,   194,   154,   194,   255,   255,   255,   255,   255,    93,
     169,   200,   214,   233,   234,   239,   240,   241,   242,   252,
     417,   418,   255,   255,    93,   169,   200,   214,   233,   234,
     239,   240,   241,   242,   252,   426,   427,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     131,   444,   445,   447,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   259,   546,   542,   255,   259,   255,   259,
     389,   255,   259,    20,    21,    50,    68,    75,    94,   122,
     130,   170,   189,   391,   255,   259,   255,   259,   132,   373,
     255,   255,   255,   255,   131,   339,   340,   342,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   201,   202,   203,   204,   206,   207,   209,   210,   211,
     214,   224,   225,   226,   227,   228,   229,   232,   235,   321,
     322,   255,   255,   255,   255,   259,   255,   259,   446,   255,
     259,    10,    12,    27,    31,   237,   448,   483,   567,   561,
     391,   388,   463,   368,   341,   255,   259,     5,    38,    49,
      66,    73,    78,    80,    93,   126,   142,   160,   162,   163,
     225,   242,   252,   343,   255,   259,   418,   427,   448,   445,
     343,   340,   322
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (0)
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
              (Loc).first_line, (Loc).first_column,	\
              (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      size_t yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

#endif /* YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()
    ;
#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to look-ahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 26:
#line 411 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:
#line 413 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number);
		}
    break;

  case 29:
#line 417 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number);
		}
    break;

  case 30:
#line 421 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number);
		}
    break;

  case 31:
#line 425 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number);
		}
    break;

  case 32:
#line 429 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number);
		}
    break;

  case 33:
#line 433 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number);
		}
    break;

  case 34:
#line 438 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 36:
#line 439 "ircd_parser.y"
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
    break;

  case 37:
#line 440 "ircd_parser.y"
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
    break;

  case 38:
#line 441 "ircd_parser.y"
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
    break;

  case 39:
#line 442 "ircd_parser.y"
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
    break;

  case 46:
#line 456 "ircd_parser.y"
    {
#ifndef STATIC_MODULES /* NOOP in the static case */
  if (ypass == 2)
  {
    char *m_bn;

    m_bn = basename(yylval.string);

    /* I suppose we should just ignore it if it is already loaded(since
     * otherwise we would flood the opers on rehash) -A1kmm.
     */
    add_conf_module(yylval.string);
  }
#endif
}
    break;

  case 47:
#line 473 "ircd_parser.y"
    {
#ifndef STATIC_MODULES
  if (ypass == 2)
    mod_add_path(yylval.string);
#endif
}
    break;

  case 63:
#line 497 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (ypass == 2 && ServerInfo.ctx) 
  {
    if (!ServerInfo.rsa_private_key_file)
    {
      yyerror("No rsa_private_key_file specified, SSL disabled");
      break;
    }

    if (SSL_CTX_use_certificate_file(ServerInfo.ctx,
      yylval.string, SSL_FILETYPE_PEM) <= 0)
    {
      yyerror(ERR_lib_error_string(ERR_get_error()));
      break;
    }

    if (SSL_CTX_use_PrivateKey_file(ServerInfo.ctx,
      ServerInfo.rsa_private_key_file, SSL_FILETYPE_PEM) <= 0)
    {
      yyerror(ERR_lib_error_string(ERR_get_error()));
      break;
    }

    if (!SSL_CTX_check_private_key(ServerInfo.ctx))
    {
      yyerror("RSA private key does not match the SSL certificate public key!");
      break;
    }
  }
#endif
}
    break;

  case 64:
#line 531 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (ypass == 1)
  {
    BIO *file;

    if (ServerInfo.rsa_private_key)
    {
      RSA_free(ServerInfo.rsa_private_key);
      ServerInfo.rsa_private_key = NULL;
    }

    if (ServerInfo.rsa_private_key_file)
    {
      MyFree(ServerInfo.rsa_private_key_file);
      ServerInfo.rsa_private_key_file = NULL;
    }

    DupString(ServerInfo.rsa_private_key_file, yylval.string);

    if ((file = BIO_new_file(yylval.string, "r")) == NULL)
    {
      yyerror("File open failed, ignoring");
      break;
    }

    ServerInfo.rsa_private_key = (RSA *)PEM_read_bio_RSAPrivateKey(file, NULL,
      0, NULL);

    BIO_set_close(file, BIO_CLOSE);
    BIO_free(file);

    if (ServerInfo.rsa_private_key == NULL)
    {
      yyerror("Couldn't extract key, ignoring");
      break;
    }

    if (!RSA_check_key(ServerInfo.rsa_private_key))
    {
      RSA_free(ServerInfo.rsa_private_key);
      ServerInfo.rsa_private_key = NULL;

      yyerror("Invalid key, ignoring");
      break;
    }

    /* require 2048 bit (256 byte) key */
    if (RSA_size(ServerInfo.rsa_private_key) != 256)
    {
      RSA_free(ServerInfo.rsa_private_key);
      ServerInfo.rsa_private_key = NULL;

      yyerror("Not a 2048 bit key, ignoring");
    }
  }
#endif
}
    break;

  case 65:
#line 591 "ircd_parser.y"
    {
  /* this isn't rehashable */
  if (ypass == 2)
  {
    if (ServerInfo.name == NULL)
    {
      /* the ircd will exit() in main() if we dont set one */
      if (strlen(yylval.string) <= HOSTLEN)
        DupString(ServerInfo.name, yylval.string);
    }
  }
}
    break;

  case 66:
#line 605 "ircd_parser.y"
    {
  /* this isn't rehashable */
  if (ypass == 2 && !ServerInfo.sid)
  {
    if ((strlen(yylval.string) == IRC_MAXSID) && IsDigit(yylval.string[0])
	&& IsAlNum(yylval.string[1]) && IsAlNum(yylval.string[2]))
    {
      DupString(ServerInfo.sid, yylval.string);
    }
    else
    {
      ilog(L_ERROR, "Ignoring config file entry SID -- invalid SID. Aborting.");
      exit(0);
    }
  }
}
    break;

  case 67:
#line 623 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
}
    break;

  case 68:
#line 632 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    char *p;

    if ((p = strchr(yylval.string, ' ')) != NULL)
      p = '\0';

    MyFree(ServerInfo.network_name);
    DupString(ServerInfo.network_name, yylval.string);
  }
}
    break;

  case 69:
#line 646 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
}
    break;

  case 70:
#line 655 "ircd_parser.y"
    {
  if (ypass == 2 && *yylval.string != '*')
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (irc_getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(L_ERROR, "Invalid netmask for server vhost(%s)", yylval.string);
    else
    {
      assert(res != NULL);

      memcpy(&ServerInfo.ip, res->ai_addr, res->ai_addrlen);
      ServerInfo.ip.ss.ss_family = res->ai_family;
      ServerInfo.ip.ss_len = res->ai_addrlen;
      irc_freeaddrinfo(res);

      ServerInfo.specific_ipv4_vhost = 1;
    }
  }
}
    break;

  case 71:
#line 683 "ircd_parser.y"
    {
#ifdef IPV6
  if (ypass == 2 && *yylval.string != '*')
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (irc_getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(L_ERROR, "Invalid netmask for server vhost6(%s)", yylval.string);
    else
    {
      assert(res != NULL);

      memcpy(&ServerInfo.ip6, res->ai_addr, res->ai_addrlen);
      ServerInfo.ip6.ss.ss_family = res->ai_family;
      ServerInfo.ip6.ss_len = res->ai_addrlen;
      irc_freeaddrinfo(res);

      ServerInfo.specific_ipv6_vhost = 1;
    }
  }
#endif
}
    break;

  case 72:
#line 713 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    recalc_fdlimit(NULL);

    if ((yyvsp[-1].number) < MAXCLIENTS_MIN)
    {
      char buf[IRCD_BUFSIZE];
      ircsprintf(buf, "MAXCLIENTS too low, setting to %d", MAXCLIENTS_MIN);
      yyerror(buf);
    }
    else if ((yyvsp[-1].number) > MAXCLIENTS_MAX)
    {
      char buf[IRCD_BUFSIZE];
      ircsprintf(buf, "MAXCLIENTS too high, setting to %d", MAXCLIENTS_MAX);
      yyerror(buf);
    }
    else
      ServerInfo.max_clients = (yyvsp[-1].number);
  }
}
    break;

  case 73:
#line 736 "ircd_parser.y"
    {
  if (ypass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 81:
#line 751 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
}
    break;

  case 82:
#line 760 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
}
    break;

  case 83:
#line 769 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
}
    break;

  case 100:
#line 796 "ircd_parser.y"
    {
                        }
    break;

  case 101:
#line 800 "ircd_parser.y"
    {
                        }
    break;

  case 102:
#line 804 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.userlog, yylval.string,
            sizeof(ConfigLoggingEntry.userlog));
}
    break;

  case 103:
#line 811 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.failed_operlog, yylval.string,
            sizeof(ConfigLoggingEntry.failed_operlog));
}
    break;

  case 104:
#line 818 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.operlog, yylval.string,
            sizeof(ConfigLoggingEntry.operlog));
}
    break;

  case 105:
#line 825 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.operspylog, yylval.string,
            sizeof(ConfigLoggingEntry.operspylog));
}
    break;

  case 106:
#line 832 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.glinelog, yylval.string,
            sizeof(ConfigLoggingEntry.glinelog));
}
    break;

  case 107:
#line 839 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.klinelog, yylval.string,
            sizeof(ConfigLoggingEntry.klinelog));
}
    break;

  case 108:
#line 846 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.ioerrlog, yylval.string,
            sizeof(ConfigLoggingEntry.ioerrlog));
}
    break;

  case 109:
#line 853 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.killlog, yylval.string,
            sizeof(ConfigLoggingEntry.killlog));
}
    break;

  case 110:
#line 860 "ircd_parser.y"
    { 
  if (ypass == 2)
    set_log_level(L_CRIT);
}
    break;

  case 111:
#line 864 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_ERROR);
}
    break;

  case 112:
#line 868 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_WARN);
}
    break;

  case 113:
#line 872 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_NOTICE);
}
    break;

  case 114:
#line 876 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_TRACE);
}
    break;

  case 115:
#line 880 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_INFO);
}
    break;

  case 116:
#line 884 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_DEBUG);
}
    break;

  case 117:
#line 890 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 118:
#line 899 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(OPER_TYPE);
    yy_aconf = &yy_conf->conf.AccessItem;
    SetConfEncrypted(yy_aconf); /* Yes, the default is encrypted */
  }
  else
  {
    MyFree(class_name);
    class_name = NULL;
  }
}
    break;

  case 119:
#line 912 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp;
    dlink_node *ptr;
    dlink_node *next_ptr;

    conf_add_class_to_conf(yy_conf, class_name);

    /* Now, make sure there is a copy of the "base" given oper
     * block in each of the collected copies
     */

    DLINK_FOREACH_SAFE(ptr, next_ptr, col_conf_list.head)
    {
      struct AccessItem *new_aconf;
      struct ConfItem *new_conf;
      yy_tmp = ptr->data;

      new_conf = make_conf_item(OPER_TYPE);
      new_aconf = &new_conf->conf.AccessItem;

      new_aconf->flags = yy_aconf->flags;

      if (yy_conf->name != NULL)
        DupString(new_conf->name, yy_conf->name);
      if (yy_tmp->user != NULL)
	DupString(new_aconf->user, yy_tmp->user);
      else
	DupString(new_aconf->user, "*");
      if (yy_tmp->host != NULL)
	DupString(new_aconf->host, yy_tmp->host);
      else
	DupString(new_aconf->host, "*");
      conf_add_class_to_conf(new_conf, class_name);
      if (yy_aconf->passwd != NULL)
        DupString(new_aconf->passwd, yy_aconf->passwd);

      new_aconf->port = yy_aconf->port;
#ifdef HAVE_LIBCRYPTO
      if (yy_aconf->rsa_public_key_file != NULL)
      {
        BIO *file;

        DupString(new_aconf->rsa_public_key_file,
		  yy_aconf->rsa_public_key_file);

        file = BIO_new_file(yy_aconf->rsa_public_key_file, "r");
        new_aconf->rsa_public_key = (RSA *)PEM_read_bio_RSA_PUBKEY(file, 
							   NULL, 0, NULL);
        BIO_set_close(file, BIO_CLOSE);
        BIO_free(file);
      }
#endif

#ifdef HAVE_LIBCRYPTO
      if (yy_tmp->name && (yy_tmp->passwd || yy_aconf->rsa_public_key)
	  && yy_tmp->host)
#else
      if (yy_tmp->name && yy_tmp->passwd && yy_tmp->host)
#endif
      {
        conf_add_class_to_conf(new_conf, class_name);
	if (yy_tmp->name != NULL)
	  DupString(new_conf->name, yy_tmp->name);
      }

      dlinkDelete(&yy_tmp->node, &col_conf_list);
      free_collect_item(yy_tmp);
    }

    yy_conf = NULL;
    yy_aconf = NULL;


    MyFree(class_name);
    class_name = NULL;
  }
}
    break;

  case 147:
#line 1004 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (strlen(yylval.string) > OPERNICKLEN)
      yylval.string[OPERNICKLEN] = '\0';

    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 148:
#line 1016 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (strlen(yylval.string) > OPERNICKLEN)
      yylval.string[OPERNICKLEN] = '\0';

    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 149:
#line 1028 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = userbuf;
    nuh.hostptr  = hostbuf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(userbuf);
    nuh.hostsize = sizeof(hostbuf);

    split_nuh(&nuh);

    if (yy_aconf->user == NULL)
    {
      DupString(yy_aconf->user, userbuf);
      DupString(yy_aconf->host, hostbuf);
    }
    else
    {
      struct CollectItem *yy_tmp = MyMalloc(sizeof(struct CollectItem));

      DupString(yy_tmp->user, userbuf);
      DupString(yy_tmp->host, hostbuf);

      dlinkAdd(yy_tmp, &yy_tmp->node, &col_conf_list);
    }
  }
}
    break;

  case 150:
#line 1062 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yy_aconf->passwd != NULL)
      memset(yy_aconf->passwd, 0, strlen(yy_aconf->passwd));

    MyFree(yy_aconf->passwd);
    DupString(yy_aconf->passwd, yylval.string);
  }
}
    break;

  case 151:
#line 1074 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      SetConfEncrypted(yy_aconf);
    else
      ClearConfEncrypted(yy_aconf);
  }
}
    break;

  case 152:
#line 1085 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (ypass == 2)
  {
    BIO *file;

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

    DupString(yy_aconf->rsa_public_key_file, yylval.string);
    file = BIO_new_file(yylval.string, "r");

    if (file == NULL)
    {
      yyerror("Ignoring rsa_public_key_file -- file doesn't exist");
      break;
    }

    yy_aconf->rsa_public_key = (RSA *)PEM_read_bio_RSA_PUBKEY(file, NULL, 0, NULL);

    if (yy_aconf->rsa_public_key == NULL)
    {
      yyerror("Ignoring rsa_public_key_file -- Key invalid; check key syntax.");
      break;
    }

    BIO_set_close(file, BIO_CLOSE);
    BIO_free(file);
  }
#endif /* HAVE_LIBCRYPTO */
}
    break;

  case 153:
#line 1127 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 154:
#line 1136 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 158:
#line 1143 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 159:
#line 1147 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 160:
#line 1151 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 161:
#line 1155 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 162:
#line 1159 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 163:
#line 1163 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 164:
#line 1167 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 165:
#line 1171 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 166:
#line 1175 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 167:
#line 1179 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 168:
#line 1183 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 169:
#line 1187 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 170:
#line 1191 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 171:
#line 1195 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 172:
#line 1199 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 173:
#line 1203 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 174:
#line 1207 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 175:
#line 1211 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 176:
#line 1217 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
    else
      yy_aconf->port &= ~OPER_FLAG_GLOBAL_KILL;
  }
}
    break;

  case 177:
#line 1228 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_REMOTE;
    else
      yy_aconf->port &= ~OPER_FLAG_REMOTE; 
  }
}
    break;

  case 178:
#line 1239 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_REMOTEBAN;
    else
      yy_aconf->port &= ~OPER_FLAG_REMOTEBAN;
  }
}
    break;

  case 179:
#line 1250 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_K;
    else
      yy_aconf->port &= ~OPER_FLAG_K;
  }
}
    break;

  case 180:
#line 1261 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_X;
    else
      yy_aconf->port &= ~OPER_FLAG_X;
  }
}
    break;

  case 181:
#line 1272 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_UNKLINE;
    else
      yy_aconf->port &= ~OPER_FLAG_UNKLINE; 
  }
}
    break;

  case 182:
#line 1283 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_GLINE;
    else
      yy_aconf->port &= ~OPER_FLAG_GLINE;
  }
}
    break;

  case 183:
#line 1294 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_N;
    else
      yy_aconf->port &= ~OPER_FLAG_N;
  }
}
    break;

  case 184:
#line 1305 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_DIE;
    else
      yy_aconf->port &= ~OPER_FLAG_DIE;
  }
}
    break;

  case 185:
#line 1316 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_REHASH;
    else
      yy_aconf->port &= ~OPER_FLAG_REHASH;
  }
}
    break;

  case 186:
#line 1327 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_ADMIN;
    else
      yy_aconf->port &= ~OPER_FLAG_ADMIN;
  }
}
    break;

  case 187:
#line 1338 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_HIDDEN_ADMIN;
    else
      yy_aconf->port &= ~OPER_FLAG_HIDDEN_ADMIN;
  }
}
    break;

  case 188:
#line 1349 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_HIDDEN_OPER;
    else
      yy_aconf->port &= ~OPER_FLAG_HIDDEN_OPER;
  }
}
    break;

  case 189:
#line 1360 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_OPERWALL;
    else
      yy_aconf->port &= ~OPER_FLAG_OPERWALL;
  }
}
    break;

  case 190:
#line 1371 "ircd_parser.y"
    {
}
    break;

  case 194:
#line 1375 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 196:
#line 1376 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 198:
#line 1379 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)yy_aconf->port &= ~OPER_FLAG_GLOBAL_KILL;
    else yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
  }
}
    break;

  case 199:
#line 1386 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTE;
    else yy_aconf->port |= OPER_FLAG_REMOTE;
  }
}
    break;

  case 200:
#line 1393 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_K;
    else yy_aconf->port |= OPER_FLAG_K;
  }
}
    break;

  case 201:
#line 1400 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_UNKLINE;
    else yy_aconf->port |= OPER_FLAG_UNKLINE;
  } 
}
    break;

  case 202:
#line 1407 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_X;
    else yy_aconf->port |= OPER_FLAG_X;
  }
}
    break;

  case 203:
#line 1414 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_GLINE;
    else yy_aconf->port |= OPER_FLAG_GLINE;
  }
}
    break;

  case 204:
#line 1421 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_DIE;
    else yy_aconf->port |= OPER_FLAG_DIE;
  }
}
    break;

  case 205:
#line 1428 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REHASH;
    else yy_aconf->port |= OPER_FLAG_REHASH;
  }
}
    break;

  case 206:
#line 1435 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_ADMIN;
    else yy_aconf->port |= OPER_FLAG_ADMIN;
  }
}
    break;

  case 207:
#line 1442 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_ADMIN;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_ADMIN;
  }
}
    break;

  case 208:
#line 1449 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_N;
    else yy_aconf->port |= OPER_FLAG_N;
  }
}
    break;

  case 209:
#line 1456 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPERWALL;
    else yy_aconf->port |= OPER_FLAG_OPERWALL;
  }
}
    break;

  case 210:
#line 1463 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPER_SPY;
    else yy_aconf->port |= OPER_FLAG_OPER_SPY;
  }
}
    break;

  case 211:
#line 1470 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_OPER;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_OPER;
  }
}
    break;

  case 212:
#line 1477 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTEBAN;
    else yy_aconf->port |= OPER_FLAG_REMOTEBAN;
  }
}
    break;

  case 213:
#line 1484 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) ClearConfEncrypted(yy_aconf);
    else SetConfEncrypted(yy_aconf);
  }
}
    break;

  case 214:
#line 1497 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = &yy_conf->conf.ClassItem;
  }
}
    break;

  case 215:
#line 1504 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    struct ConfItem *cconf;
    struct ClassItem *class = NULL;

    if (yy_class_name == NULL)
    {
      delete_conf_item(yy_conf);
    }
    else
    {
      cconf = find_exact_name_conf(CLASS_TYPE, yy_class_name, NULL, NULL);

      if (cconf != NULL)		/* The class existed already */
      {
        class = &cconf->conf.ClassItem;
        rebuild_cidr_class(class, yy_class);
        *class = *yy_class;
        delete_conf_item(yy_conf);

        MyFree(cconf->name);            /* Allows case change of class name */
        cconf->name = yy_class_name;
      }
      else	/* Brand new class */
      {
        MyFree(yy_conf->name);          /* just in case it was allocated */
        yy_conf->name = yy_class_name;
      }
    }
    yy_class_name = NULL;
  }
}
    break;

  case 234:
#line 1556 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 235:
#line 1565 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 236:
#line 1574 "ircd_parser.y"
    {
  if (ypass == 1)
    PingFreq(yy_class) = (yyvsp[-1].number);
}
    break;

  case 237:
#line 1580 "ircd_parser.y"
    {
  if (ypass == 1)
    PingWarning(yy_class) = (yyvsp[-1].number);
}
    break;

  case 238:
#line 1586 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxPerIp(yy_class) = (yyvsp[-1].number);
}
    break;

  case 239:
#line 1592 "ircd_parser.y"
    {
  if (ypass == 1)
    ConFreq(yy_class) = (yyvsp[-1].number);
}
    break;

  case 240:
#line 1598 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxTotal(yy_class) = (yyvsp[-1].number);
}
    break;

  case 241:
#line 1604 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxGlobal(yy_class) = (yyvsp[-1].number);
}
    break;

  case 242:
#line 1610 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxLocal(yy_class) = (yyvsp[-1].number);
}
    break;

  case 243:
#line 1616 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxIdent(yy_class) = (yyvsp[-1].number);
}
    break;

  case 244:
#line 1622 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxSendq(yy_class) = (yyvsp[-1].number);
}
    break;

  case 245:
#line 1628 "ircd_parser.y"
    {
  if (ypass == 1)
    CidrBitlenIPV4(yy_class) = (yyvsp[-1].number);
}
    break;

  case 246:
#line 1634 "ircd_parser.y"
    {
  if (ypass == 1)
    CidrBitlenIPV6(yy_class) = (yyvsp[-1].number);
}
    break;

  case 247:
#line 1640 "ircd_parser.y"
    {
  if (ypass == 1)
    NumberPerCidr(yy_class) = (yyvsp[-1].number);
}
    break;

  case 248:
#line 1649 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 249:
#line 1656 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 250:
#line 1665 "ircd_parser.y"
    {
}
    break;

  case 254:
#line 1670 "ircd_parser.y"
    {
  if (ypass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 255:
#line 1674 "ircd_parser.y"
    {
  if (ypass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 266:
#line 1687 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if ((listener_flags & LISTENER_SSL))
#ifdef HAVE_LIBCRYPTO
      if (!ServerInfo.ctx)
#endif
      {
        yyerror("SSL not available - port closed");
	break;
      }
    add_listener((yyvsp[0].number), listener_address, listener_flags);
    listener_flags = 0;
  }
}
    break;

  case 267:
#line 1702 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    int i;

    if ((listener_flags & LISTENER_SSL))
#ifdef HAVE_LIBCRYPTO
      if (!ServerInfo.ctx)
#endif
      {
        yyerror("SSL not available - port closed");
	break;
      }

    for (i = (yyvsp[-2].number); i <= (yyvsp[0].number); ++i)
      add_listener(i, listener_address, listener_flags);

    listener_flags = 0;
  }
}
    break;

  case 268:
#line 1724 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 269:
#line 1733 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 270:
#line 1745 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(CLIENT_TYPE);
    yy_aconf = &yy_conf->conf.AccessItem;
  }
  else
  {
    MyFree(class_name);
    class_name = NULL;
  }
}
    break;

  case 271:
#line 1757 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp = NULL;
    dlink_node *ptr = NULL, *next_ptr = NULL;

    if (yy_aconf->user && yy_aconf->host)
    {
      conf_add_class_to_conf(yy_conf, class_name);
      add_conf_by_address(CONF_CLIENT, yy_aconf);
    }
    else
      delete_conf_item(yy_conf);

    /* copy over settings from first struct */
    DLINK_FOREACH_SAFE(ptr, next_ptr, col_conf_list.head)
    {
      struct AccessItem *new_aconf;
      struct ConfItem *new_conf;

      new_conf = make_conf_item(CLIENT_TYPE);
      new_aconf = &new_conf->conf.AccessItem;

      yy_tmp = ptr->data;

      assert(yy_tmp->user && yy_tmp->host);

      if (yy_aconf->passwd != NULL)
        DupString(new_aconf->passwd, yy_aconf->passwd);
      if (yy_conf->name != NULL)
        DupString(new_conf->name, yy_conf->name);
      if (yy_aconf->passwd != NULL)
        DupString(new_aconf->passwd, yy_aconf->passwd);

      new_aconf->flags = yy_aconf->flags;
      new_aconf->port  = yy_aconf->port;

      DupString(new_aconf->user, yy_tmp->user);
      collapse(new_aconf->user);

      DupString(new_aconf->host, yy_tmp->host);
      collapse(new_aconf->host);

      conf_add_class_to_conf(new_conf, class_name);
      add_conf_by_address(CONF_CLIENT, new_aconf);
      dlinkDelete(&yy_tmp->node, &col_conf_list);
      free_collect_item(yy_tmp);
    }

    MyFree(class_name);
    class_name = NULL;
    yy_conf = NULL;
    yy_aconf = NULL;
  }
}
    break;

  case 291:
#line 1822 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp = NULL;
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = userbuf;
    nuh.hostptr  = hostbuf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(userbuf);
    nuh.hostsize = sizeof(hostbuf);

    split_nuh(&nuh);

    if (yy_aconf->user == NULL)
    {
      DupString(yy_aconf->user, userbuf);
      DupString(yy_aconf->host, hostbuf);
    }
    else
    {
      yy_tmp = MyMalloc(sizeof(struct CollectItem));

      DupString(yy_tmp->user, userbuf);
      DupString(yy_tmp->host, hostbuf);

      dlinkAdd(yy_tmp, &yy_tmp->node, &col_conf_list);
    }
  }
}
    break;

  case 292:
#line 1859 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    /* be paranoid */
    if (yy_aconf->passwd != NULL)
      memset(yy_aconf->passwd, 0, strlen(yy_aconf->passwd));

    MyFree(yy_aconf->passwd);
    DupString(yy_aconf->passwd, yylval.string);
  }
}
    break;

  case 293:
#line 1872 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
    else
      yy_aconf->flags &= ~CONF_FLAGS_SPOOF_NOTICE;
  }
}
    break;

  case 294:
#line 1883 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 295:
#line 1892 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      SetConfEncrypted(yy_aconf);
    else
      ClearConfEncrypted(yy_aconf);
  }
}
    break;

  case 296:
#line 1903 "ircd_parser.y"
    {
}
    break;

  case 300:
#line 1907 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 302:
#line 1908 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 304:
#line 1911 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_SPOOF_NOTICE;
    else yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
  }

}
    break;

  case 305:
#line 1919 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NOLIMIT;
    else yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
  }
}
    break;

  case 306:
#line 1926 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTKLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
  } 
}
    break;

  case 307:
#line 1933 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_IDENTD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
  }
}
    break;

  case 308:
#line 1940 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_CAN_FLOOD;
    else yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
  }
}
    break;

  case 309:
#line 1947 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_IDLE_LINED;
    else yy_aconf->flags |= CONF_FLAGS_IDLE_LINED;
  }
}
    break;

  case 310:
#line 1954 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NO_TILDE;
    else yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
  } 
}
    break;

  case 311:
#line 1961 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTGLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
  } 
}
    break;

  case 312:
#line 1968 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTRESV;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
  }
}
    break;

  case 313:
#line 1975 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_PASSWORD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
  }
}
    break;

  case 314:
#line 1984 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
    else
      yy_aconf->flags &= ~CONF_FLAGS_EXEMPTKLINE;
  }
}
    break;

  case 315:
#line 1995 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
    else
      yy_aconf->flags &= ~CONF_FLAGS_NEED_IDENTD;
  }
}
    break;

  case 316:
#line 2006 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
    else
      yy_aconf->flags &= ~CONF_FLAGS_NOLIMIT;
  }
}
    break;

  case 317:
#line 2017 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
    else
      yy_aconf->flags &= ~CONF_FLAGS_CAN_FLOOD;
  }
}
    break;

  case 318:
#line 2028 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
    else
      yy_aconf->flags &= ~CONF_FLAGS_NO_TILDE;
  }
}
    break;

  case 319:
#line 2039 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
    else
      yy_aconf->flags &= ~CONF_FLAGS_EXEMPTGLINE;
  }
}
    break;

  case 320:
#line 2051 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_conf->name);

    if (strlen(yylval.string) < HOSTLEN)
    {    
      DupString(yy_conf->name, yylval.string);
      yy_aconf->flags |= CONF_FLAGS_SPOOF_IP;
    }
    else
    {
      ilog(L_ERROR, "Spoofs must be less than %d..ignoring it", HOSTLEN);
      yy_conf->name = NULL;
    }
  }
}
    break;

  case 321:
#line 2070 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 322:
#line 2080 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[-1].number);
  }
}
    break;

  case 323:
#line 2089 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
    else
      yy_aconf->flags &= ~CONF_FLAGS_NEED_PASSWORD;
  }
}
    break;

  case 324:
#line 2104 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 325:
#line 2111 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 332:
#line 2123 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 333:
#line 2132 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (IsChanPrefix(*yylval.string))
    {
      char def_reason[] = "No reason";

      create_channel_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
    }
  }
  /* ignore it for now.. but we really should make a warning if
   * its an erroneous name --fl_ */
}
    break;

  case 334:
#line 2147 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 335:
#line 2160 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = &yy_conf->conf.MatchItem;
    yy_match_item->action = SHARED_ALL;
  }
}
    break;

  case 336:
#line 2168 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 343:
#line 2179 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 344:
#line 2188 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = userbuf;
    nuh.hostptr  = hostbuf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(userbuf);
    nuh.hostsize = sizeof(hostbuf);

    split_nuh(&nuh);

    DupString(yy_match_item->user, userbuf);
    DupString(yy_match_item->host, hostbuf);
  }
}
    break;

  case 345:
#line 2210 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = 0;
}
    break;

  case 349:
#line 2217 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 350:
#line 2221 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TKLINE;
}
    break;

  case 351:
#line 2225 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 352:
#line 2229 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 353:
#line 2233 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TXLINE;
}
    break;

  case 354:
#line 2237 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 355:
#line 2241 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 356:
#line 2245 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TRESV;
}
    break;

  case 357:
#line 2249 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 358:
#line 2253 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 359:
#line 2257 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 360:
#line 2266 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_match_item = &yy_conf->conf.MatchItem;
    yy_match_item->action = SHARED_ALL;
    DupString(yy_conf->name, "*");
  }
}
    break;

  case 361:
#line 2275 "ircd_parser.y"
    {
  yy_conf = NULL;
  yy_match_item = NULL;
}
    break;

  case 367:
#line 2284 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 368:
#line 2293 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = 0;
}
    break;

  case 372:
#line 2300 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 373:
#line 2304 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TKLINE;
}
    break;

  case 374:
#line 2308 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 375:
#line 2312 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 376:
#line 2316 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TXLINE;
}
    break;

  case 377:
#line 2320 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 378:
#line 2324 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 379:
#line 2328 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TRESV;
}
    break;

  case 380:
#line 2332 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 381:
#line 2336 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 382:
#line 2340 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 383:
#line 2349 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(SERVER_TYPE);
    yy_aconf = &yy_conf->conf.AccessItem;
    yy_aconf->passwd = NULL;
    /* defaults */
    yy_aconf->port = PORTNUM;

    if (ConfigFileEntry.burst_away)
      yy_aconf->flags = CONF_FLAGS_BURST_AWAY;
  }
  else
  {
    MyFree(class_name);
    class_name = NULL;
  }
}
    break;

  case 384:
#line 2367 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct CollectItem *yy_hconf=NULL;
    struct CollectItem *yy_lconf=NULL;
    dlink_node *ptr;
    dlink_node *next_ptr;
#ifdef HAVE_LIBCRYPTO
    if (yy_aconf->host &&
	((yy_aconf->passwd && yy_aconf->spasswd) ||
	 (yy_aconf->rsa_public_key && IsConfCryptLink(yy_aconf))))
#else /* !HAVE_LIBCRYPTO */
      if (yy_aconf->host && !IsConfCryptLink(yy_aconf) && 
	  yy_aconf->passwd && yy_aconf->spasswd)
#endif /* !HAVE_LIBCRYPTO */
	{
	  if (conf_add_server(yy_conf, class_name) == -1)
	  {
	    delete_conf_item(yy_conf);
	    yy_conf = NULL;
	    yy_aconf = NULL;
	  }
	}
	else
	{
	  /* Even if yy_conf ->name is NULL
	   * should still unhook any hub/leaf confs still pending
	   */
	  unhook_hub_leaf_confs();

	  if (yy_conf->name != NULL)
	  {
#ifndef HAVE_LIBCRYPTO
	    if (IsConfCryptLink(yy_aconf))
	      yyerror("Ignoring connect block -- no OpenSSL support");
#else
	    if (IsConfCryptLink(yy_aconf) && !yy_aconf->rsa_public_key)
	      yyerror("Ignoring connect block -- missing key");
#endif
	    if (yy_aconf->host == NULL)
	      yyerror("Ignoring connect block -- missing host");
	    else if (!IsConfCryptLink(yy_aconf) && 
		    (!yy_aconf->passwd || !yy_aconf->spasswd))
              yyerror("Ignoring connect block -- missing password");
	  }


          /* XXX
           * This fixes a try_connections() core (caused by invalid class_ptr
           * pointers) reported by metalrock. That's an ugly fix, but there
           * is currently no better way. The entire config subsystem needs an
           * rewrite ASAP. make_conf_item() shouldn't really add things onto
           * a doubly linked list immediately without any sanity checks!  -Michael
           */
          delete_conf_item(yy_conf);

          yy_aconf = NULL;
	  yy_conf = NULL;
	}

      /*
       * yy_conf is still pointing at the server that is having
       * a connect block built for it. This means, y_aconf->name 
       * points to the actual irc name this server will be known as.
       * Now this new server has a set or even just one hub_mask (or leaf_mask)
       * given in the link list at yy_hconf. Fill in the HUB confs
       * from this link list now.
       */        
      DLINK_FOREACH_SAFE(ptr, next_ptr, hub_conf_list.head)
      {
	struct ConfItem *new_hub_conf;
	struct MatchItem *match_item;

	yy_hconf = ptr->data;

	/* yy_conf == NULL is a fatal error for this connect block! */
	if ((yy_conf != NULL) && (yy_conf->name != NULL))
	{
	  new_hub_conf = make_conf_item(HUB_TYPE);
	  match_item = &new_hub_conf->conf.MatchItem;
	  DupString(new_hub_conf->name, yy_conf->name);
	  if (yy_hconf->user != NULL)
	    DupString(match_item->user, yy_hconf->user);
	  else
	    DupString(match_item->user, "*");
	  if (yy_hconf->host != NULL)
	    DupString(match_item->host, yy_hconf->host);
	  else
	    DupString(match_item->host, "*");
	}
	dlinkDelete(&yy_hconf->node, &hub_conf_list);
	free_collect_item(yy_hconf);
      }

      /* Ditto for the LEAF confs */

      DLINK_FOREACH_SAFE(ptr, next_ptr, leaf_conf_list.head)
      {
	struct ConfItem *new_leaf_conf;
	struct MatchItem *match_item;

	yy_lconf = ptr->data;

	if ((yy_conf != NULL) && (yy_conf->name != NULL))
	{
	  new_leaf_conf = make_conf_item(LEAF_TYPE);
	  match_item = &new_leaf_conf->conf.MatchItem;
	  DupString(new_leaf_conf->name, yy_conf->name);
	  if (yy_lconf->user != NULL)
	    DupString(match_item->user, yy_lconf->user);
	  else
	    DupString(match_item->user, "*");
	  if (yy_lconf->host != NULL)
	    DupString(match_item->host, yy_lconf->host);
	  else
	    DupString(match_item->host, "*");
	}
	dlinkDelete(&yy_lconf->node, &leaf_conf_list);
	free_collect_item(yy_lconf);
      }
      MyFree(class_name);
      class_name = NULL;
      yy_conf = NULL;
      yy_aconf = NULL;
  }
}
    break;

  case 408:
#line 2506 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yy_conf->name != NULL)
      yyerror("Multiple connect name entry");

    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 409:
#line 2518 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yy_conf->name != NULL)
      yyerror("Multiple connect name entry");

    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 410:
#line 2530 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 411:
#line 2539 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (irc_getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(L_ERROR, "Invalid netmask for server vhost(%s)", yylval.string);
    else
    {
      assert(res != NULL);

      memcpy(&yy_aconf->my_ipnum, res->ai_addr, res->ai_addrlen);
      yy_aconf->my_ipnum.ss.ss_family = res->ai_family;
      yy_aconf->my_ipnum.ss_len = res->ai_addrlen;
      irc_freeaddrinfo(res);
    }
  }
}
    break;

  case 412:
#line 2565 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if ((yyvsp[-1].string)[0] == ':')
      yyerror("Server passwords cannot begin with a colon");
    else if (strchr((yyvsp[-1].string), ' ') != NULL)
      yyerror("Server passwords cannot contain spaces");
    else {
      if (yy_aconf->spasswd != NULL)
        memset(yy_aconf->spasswd, 0, strlen(yy_aconf->spasswd));

      MyFree(yy_aconf->spasswd);
      DupString(yy_aconf->spasswd, yylval.string);
    }
  }
}
    break;

  case 413:
#line 2583 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if ((yyvsp[-1].string)[0] == ':')
      yyerror("Server passwords cannot begin with a colon");
    else if (strchr((yyvsp[-1].string), ' ') != NULL)
      yyerror("Server passwords cannot contain spaces");
    else {
      if (yy_aconf->passwd != NULL)
        memset(yy_aconf->passwd, 0, strlen(yy_aconf->passwd));

      MyFree(yy_aconf->passwd);
      DupString(yy_aconf->passwd, yylval.string);
    }
  }
}
    break;

  case 414:
#line 2601 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->port = (yyvsp[-1].number);
}
    break;

  case 415:
#line 2607 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 416:
#line 2611 "ircd_parser.y"
    {
#ifdef IPV6
  if (ypass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 417:
#line 2619 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->fakename);
    DupString(yy_aconf->fakename, yylval.string);
  }
}
    break;

  case 418:
#line 2628 "ircd_parser.y"
    {
}
    break;

  case 422:
#line 2632 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 424:
#line 2633 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 426:
#line 2636 "ircd_parser.y"
    {
  if (ypass == 2)
#ifndef HAVE_LIBZ
    yyerror("Ignoring flags = compressed; -- no zlib support");
#else
 {
   if (not_atom)ClearConfCompressed(yy_aconf);
   else SetConfCompressed(yy_aconf);
 }
#endif
}
    break;

  case 427:
#line 2647 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfCryptLink(yy_aconf);
    else SetConfCryptLink(yy_aconf);
  }
}
    break;

  case 428:
#line 2654 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfAllowAutoConn(yy_aconf);
    else SetConfAllowAutoConn(yy_aconf);
  }
}
    break;

  case 429:
#line 2661 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfAwayBurst(yy_aconf);
    else SetConfAwayBurst(yy_aconf);
  }
}
    break;

  case 430:
#line 2668 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfTopicBurst(yy_aconf);
    else SetConfTopicBurst(yy_aconf);
  }
}
    break;

  case 431:
#line 2678 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (ypass == 2)
  {
    BIO *file;

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

    DupString(yy_aconf->rsa_public_key_file, yylval.string);

    if ((file = BIO_new_file(yylval.string, "r")) == NULL)
    {
      yyerror("Ignoring rsa_public_key_file -- file doesn't exist");
      break;
    }

    yy_aconf->rsa_public_key = (RSA *)PEM_read_bio_RSA_PUBKEY(file, NULL, 0, NULL);

    if (yy_aconf->rsa_public_key == NULL)
    {
      yyerror("Ignoring rsa_public_key_file -- Key invalid; check key syntax.");
      break;
    }
      
    BIO_set_close(file, BIO_CLOSE);
    BIO_free(file);
  }
#endif /* HAVE_LIBCRYPTO */
}
    break;

  case 432:
#line 2719 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_ENCRYPTED;
    else
      yy_aconf->flags &= ~CONF_FLAGS_ENCRYPTED;
  }
}
    break;

  case 433:
#line 2730 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_CRYPTLINK;
    else
      yy_aconf->flags &= ~CONF_FLAGS_CRYPTLINK;
  }
}
    break;

  case 434:
#line 2741 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
#ifndef HAVE_LIBZ
      yyerror("Ignoring compressed=yes; -- no zlib support");
#else
      yy_aconf->flags |= CONF_FLAGS_COMPRESSED;
#endif
    else
      yy_aconf->flags &= ~CONF_FLAGS_COMPRESSED;
  }
}
    break;

  case 435:
#line 2756 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_ALLOW_AUTO_CONN;
    else
      yy_aconf->flags &= ~CONF_FLAGS_ALLOW_AUTO_CONN;
  }
}
    break;

  case 436:
#line 2767 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp;

    yy_tmp = (struct CollectItem *)MyMalloc(sizeof(struct CollectItem));
    DupString(yy_tmp->host, yylval.string);
    DupString(yy_tmp->user, "*");
    dlinkAdd(yy_tmp, &yy_tmp->node, &hub_conf_list);
  }
}
    break;

  case 437:
#line 2780 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp;

    yy_tmp = (struct CollectItem *)MyMalloc(sizeof(struct CollectItem));
    DupString(yy_tmp->host, yylval.string);
    DupString(yy_tmp->user, "*");
    dlinkAdd(yy_tmp, &yy_tmp->node, &leaf_conf_list);
  }
}
    break;

  case 438:
#line 2793 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 439:
#line 2802 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (ypass == 2)
  {
    struct EncCapability *ecap;
    const char *cipher_name;
    int found = 0;

    yy_aconf->cipher_preference = NULL;
    cipher_name = yylval.string;

    for (ecap = CipherTable; ecap->name; ecap++)
    {
      if ((irccmp(ecap->name, cipher_name) == 0) &&
          (ecap->cap & CAP_ENC_MASK))
      {
        yy_aconf->cipher_preference = ecap;
        found = 1;
        break;
      }
    }

    if (!found)
      yyerror("Invalid cipher");
  }
#else
  if (ypass == 2)
    yyerror("Ignoring cipher_preference -- no OpenSSL support");
#endif
}
    break;

  case 440:
#line 2837 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 441:
#line 2844 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (userbuf[0] && hostbuf[0])
    {
      if (regex_ban)
      {
        pcre *exp_user = NULL;
        pcre *exp_host = NULL;
        const char *errptr = NULL;

        if (!(exp_user = ircd_pcre_compile(userbuf, &errptr)) ||
            !(exp_host = ircd_pcre_compile(hostbuf, &errptr)))
        {
          ilog(L_ERROR, "Failed to add regular expression based K-Line: %s", errptr);
          break;
        }

        yy_conf = make_conf_item(RKLINE_TYPE);

        yy_aconf = &yy_conf->conf.AccessItem;
        yy_aconf->regexuser = exp_user;
        yy_aconf->regexhost = exp_host;

        DupString(yy_aconf->user, userbuf);
        DupString(yy_aconf->host, hostbuf);

        if (reasonbuf[0])
          DupString(yy_aconf->reason, reasonbuf);
        else
          DupString(yy_aconf->reason, "No reason");
      }
      else
      {
        yy_conf = make_conf_item(KLINE_TYPE);
        yy_aconf = &yy_conf->conf.AccessItem;

        DupString(yy_aconf->user, userbuf);
        DupString(yy_aconf->host, hostbuf);

        if (reasonbuf[0])
          DupString(yy_aconf->reason, reasonbuf);
        else
          DupString(yy_aconf->reason, "No reason");
        add_conf_by_address(CONF_KILL, yy_aconf);
      }
    }
    else
      delete_conf_item(yy_conf);

    yy_conf = NULL;
    yy_aconf = NULL;
  }
}
    break;

  case 442:
#line 2900 "ircd_parser.y"
    {
}
    break;

  case 446:
#line 2905 "ircd_parser.y"
    {
  if (ypass == 2)
    regex_ban = 1;
}
    break;

  case 453:
#line 2914 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = userbuf;
    nuh.hostptr  = hostbuf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(userbuf);
    nuh.hostsize = sizeof(hostbuf);

    split_nuh(&nuh);
  }
}
    break;

  case 454:
#line 2933 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 455:
#line 2942 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(DLINE_TYPE);
    yy_aconf = &yy_conf->conf.AccessItem;
    /* default reason */
    DupString(yy_aconf->reason, "No reason");
  }
}
    break;

  case 456:
#line 2951 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yy_aconf->host && parse_netmask(yy_aconf->host, NULL, NULL) != HM_HOST)
      add_conf_by_address(CONF_DLINE, yy_aconf);
    else
      delete_conf_item(yy_conf);
    yy_conf = NULL;
    yy_aconf = NULL;
  }
}
    break;

  case 462:
#line 2967 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 463:
#line 2976 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->reason);
    DupString(yy_aconf->reason, yylval.string);
  }
}
    break;

  case 469:
#line 2993 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.string[0] && parse_netmask(yylval.string, NULL, NULL) != HM_HOST)
    {
      yy_conf = make_conf_item(EXEMPTDLINE_TYPE);
      yy_aconf = &yy_conf->conf.AccessItem;
      DupString(yy_aconf->host, yylval.string);

      add_conf_by_address(CONF_EXEMPTDLINE, yy_aconf);

      yy_conf = NULL;
      yy_aconf = NULL;
    }
  }
}
    break;

  case 470:
#line 3014 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 471:
#line 3021 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (gecos_name[0])
    {
      if (regex_ban)
      {
        pcre *exp_p = NULL;
        const char *errptr = NULL;

        if (!(exp_p = ircd_pcre_compile(gecos_name, &errptr)))
        {
          ilog(L_ERROR, "Failed to add regular expression based X-Line: %s", errptr);
          break;
        }

        yy_conf = make_conf_item(RXLINE_TYPE);
        yy_conf->regexpname = exp_p;
      }
      else
        yy_conf = make_conf_item(XLINE_TYPE);

      yy_match_item = &yy_conf->conf.MatchItem;
      DupString(yy_conf->name, gecos_name);

      if (reasonbuf[0])
        DupString(yy_match_item->reason, reasonbuf);
      else
        DupString(yy_match_item->reason, "No reason");
    }
  }
}
    break;

  case 472:
#line 3055 "ircd_parser.y"
    {
}
    break;

  case 476:
#line 3060 "ircd_parser.y"
    {
  if (ypass == 2)
    regex_ban = 1;
}
    break;

  case 483:
#line 3069 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 484:
#line 3075 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 544:
#line 3119 "ircd_parser.y"
    {
  ConfigFileEntry.max_watch = yylval.number;
}
    break;

  case 545:
#line 3124 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[-1].number);
}
    break;

  case 546:
#line 3129 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[-1].number);
}
    break;

  case 547:
#line 3134 "ircd_parser.y"
    {
  ConfigFileEntry.burst_away = yylval.number;
}
    break;

  case 548:
#line 3139 "ircd_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 549:
#line 3144 "ircd_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 550:
#line 3149 "ircd_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 551:
#line 3154 "ircd_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[-1].number);
}
    break;

  case 552:
#line 3159 "ircd_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 553:
#line 3164 "ircd_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 554:
#line 3169 "ircd_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 555:
#line 3174 "ircd_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 556:
#line 3179 "ircd_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 557:
#line 3184 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[-1].number); 
}
    break;

  case 558:
#line 3189 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[-1].number);
}
    break;

  case 559:
#line 3194 "ircd_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[-1].number);
}
    break;

  case 560:
#line 3199 "ircd_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[-1].number);
}
    break;

  case 561:
#line 3204 "ircd_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[-1].number);
}
    break;

  case 562:
#line 3209 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[-1].number);
}
    break;

  case 563:
#line 3215 "ircd_parser.y"
    {
  if (((yyvsp[-1].number) > 0) && ypass == 1)
  {
    ilog(L_CRIT, "You haven't read your config file properly.");
    ilog(L_CRIT, "There is a line in the example conf that will kill your server if not removed.");
    ilog(L_CRIT, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
    break;

  case 564:
#line 3226 "ircd_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 565:
#line 3231 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 566:
#line 3240 "ircd_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 567:
#line 3245 "ircd_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 568:
#line 3250 "ircd_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 569:
#line 3255 "ircd_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 570:
#line 3260 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 571:
#line 3263 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 572:
#line 3268 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 573:
#line 3271 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 574:
#line 3276 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[-1].number);
}
    break;

  case 575:
#line 3281 "ircd_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[-1].number);
}
    break;

  case 576:
#line 3286 "ircd_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 577:
#line 3291 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[-1].number);
}
    break;

  case 578:
#line 3296 "ircd_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 579:
#line 3301 "ircd_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 580:
#line 3306 "ircd_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 581:
#line 3311 "ircd_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 582:
#line 3316 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 583:
#line 3327 "ircd_parser.y"
    {
  ConfigFileEntry.idletime = (yyvsp[-1].number);
}
    break;

  case 584:
#line 3332 "ircd_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[-1].number);
}
    break;

  case 585:
#line 3337 "ircd_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[-1].number);
}
    break;

  case 586:
#line 3342 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.servlink_path);
    DupString(ConfigFileEntry.servlink_path, yylval.string);
  }
}
    break;

  case 587:
#line 3351 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (ypass == 2)
  {
    struct EncCapability *ecap;
    const char *cipher_name;
    int found = 0;

    ConfigFileEntry.default_cipher_preference = NULL;
    cipher_name = yylval.string;

    for (ecap = CipherTable; ecap->name; ecap++)
    {
      if ((irccmp(ecap->name, cipher_name) == 0) &&
          (ecap->cap & CAP_ENC_MASK))
      {
        ConfigFileEntry.default_cipher_preference = ecap;
        found = 1;
        break;
      }
    }

    if (!found)
      yyerror("Invalid cipher");
  }
#else
  if (ypass == 2)
    yyerror("Ignoring default_cipher_preference -- no OpenSSL support");
#endif
}
    break;

  case 588:
#line 3383 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    ConfigFileEntry.compression_level = (yyvsp[-1].number);
#ifndef HAVE_LIBZ
    yyerror("Ignoring compression_level -- no zlib support");
#else
    if ((ConfigFileEntry.compression_level < 1) ||
        (ConfigFileEntry.compression_level > 9))
    {
      yyerror("Ignoring invalid compression_level, using default");
      ConfigFileEntry.compression_level = 0;
    }
#endif
  }
}
    break;

  case 589:
#line 3401 "ircd_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 590:
#line 3406 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 591:
#line 3415 "ircd_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 592:
#line 3420 "ircd_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 593:
#line 3425 "ircd_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 594:
#line 3430 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 598:
#line 3436 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 599:
#line 3439 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 600:
#line 3442 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 601:
#line 3445 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 602:
#line 3448 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 603:
#line 3451 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 604:
#line 3454 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 605:
#line 3457 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 606:
#line 3460 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 607:
#line 3463 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 608:
#line 3466 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 609:
#line 3469 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 610:
#line 3472 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 611:
#line 3475 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 612:
#line 3478 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 613:
#line 3481 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 614:
#line 3484 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 615:
#line 3487 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 616:
#line 3492 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 620:
#line 3498 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 621:
#line 3501 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 622:
#line 3504 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 623:
#line 3507 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 624:
#line 3510 "ircd_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 625:
#line 3513 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 626:
#line 3516 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 627:
#line 3519 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 628:
#line 3522 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 629:
#line 3525 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 630:
#line 3528 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 631:
#line 3531 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 632:
#line 3534 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 633:
#line 3537 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 634:
#line 3540 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 635:
#line 3543 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 636:
#line 3546 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 637:
#line 3549 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 638:
#line 3554 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[-1].number);
}
    break;

  case 639:
#line 3559 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[-1].number);
}
    break;

  case 640:
#line 3564 "ircd_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[-1].number);
}
    break;

  case 641:
#line 3569 "ircd_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[-1].number);
}
    break;

  case 642:
#line 3574 "ircd_parser.y"
    {
  ConfigFileEntry.dot_in_ip6_addr = yylval.number;
}
    break;

  case 643:
#line 3582 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = &yy_conf->conf.AccessItem;
  }
}
    break;

  case 644:
#line 3589 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    /*
     * since we re-allocate yy_conf/yy_aconf after the end of action=, at the
     * end we will have one extra, so we should free it.
     */
    if (yy_conf->name == NULL || yy_aconf->user == NULL)
    {
      delete_conf_item(yy_conf);
      yy_conf = NULL;
      yy_aconf = NULL;
    }
  }
}
    break;

  case 654:
#line 3615 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 655:
#line 3621 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_time = (yyvsp[-1].number);
}
    break;

  case 656:
#line 3627 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 660:
#line 3633 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 661:
#line 3637 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 662:
#line 3643 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = userbuf;
    nuh.hostptr  = hostbuf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(userbuf);
    nuh.hostsize = sizeof(hostbuf);

    split_nuh(&nuh);

    if (yy_aconf->user == NULL)
    {
      DupString(yy_aconf->user, userbuf);
      DupString(yy_aconf->host, hostbuf);
    }
    else
    {
      struct CollectItem *yy_tmp = MyMalloc(sizeof(struct CollectItem));

      DupString(yy_tmp->user, userbuf);
      DupString(yy_tmp->host, hostbuf);

      dlinkAdd(yy_tmp, &yy_tmp->node, &col_conf_list);
    }
  }
}
    break;

  case 663:
#line 3677 "ircd_parser.y"
    {
  if (ypass == 2)  
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 664:
#line 3686 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 665:
#line 3690 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp = NULL;
    dlink_node *ptr = NULL, *next_ptr = NULL;

    DLINK_FOREACH_SAFE(ptr, next_ptr, col_conf_list.head)
    {
      struct AccessItem *new_aconf;
      struct ConfItem *new_conf;

      yy_tmp = ptr->data;
      new_conf = make_conf_item(GDENY_TYPE);
      new_aconf = &new_conf->conf.AccessItem;

      new_aconf->flags = yy_aconf->flags;

      if (yy_conf->name != NULL)
        DupString(new_conf->name, yy_conf->name);
      else
        DupString(new_conf->name, "*");
      if (yy_aconf->user != NULL)
         DupString(new_aconf->user, yy_tmp->user);
      else   
        DupString(new_aconf->user, "*");
      if (yy_aconf->host != NULL)
        DupString(new_aconf->host, yy_tmp->host);
      else
        DupString(new_aconf->host, "*");

      dlinkDelete(&yy_tmp->node, &col_conf_list);
    }

    /*
     * In case someone has fed us with more than one action= after user/name
     * which would leak memory  -Michael
     */
    if (yy_conf->name == NULL || yy_aconf->user == NULL)
      delete_conf_item(yy_conf);

    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = &yy_conf->conf.AccessItem;
  }
}
    break;

  case 668:
#line 3737 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 669:
#line 3741 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 691:
#line 3765 "ircd_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 692:
#line 3770 "ircd_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 693:
#line 3775 "ircd_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 694:
#line 3780 "ircd_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 695:
#line 3785 "ircd_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 696:
#line 3790 "ircd_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[-1].number);
}
    break;

  case 697:
#line 3795 "ircd_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
    break;

  case 698:
#line 3800 "ircd_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[-1].number);
}
    break;

  case 699:
#line 3805 "ircd_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 700:
#line 3810 "ircd_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
    break;

  case 701:
#line 3815 "ircd_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[-1].number);
}
    break;

  case 702:
#line 3820 "ircd_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[-1].number);
}
    break;

  case 703:
#line 3825 "ircd_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 704:
#line 3830 "ircd_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 705:
#line 3835 "ircd_parser.y"
    {
  ConfigChannel.burst_topicwho = yylval.number;
}
    break;

  case 706:
#line 3840 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 707:
#line 3845 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 719:
#line 3864 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 720:
#line 3870 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 721:
#line 3876 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 722:
#line 3885 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (((yyvsp[-1].number) > 0) && ConfigServerHide.links_disabled == 1)
    {
      eventAddIsh("write_links_file", write_links_file, NULL, (yyvsp[-1].number));
      ConfigServerHide.links_disabled = 0;
    }

    ConfigServerHide.links_delay = (yyvsp[-1].number);
  }
}
    break;

  case 723:
#line 3899 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 724:
#line 3905 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 725:
#line 3911 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 7439 "y.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
	  char *yyfmt;
	  char const *yyf;
	  static char const yyunexpected[] = "syntax error, unexpected %s";
	  static char const yyexpecting[] = ", expecting %s";
	  static char const yyor[] = " or %s";
	  char yyformat[sizeof yyunexpected
			+ sizeof yyexpecting - 1
			+ ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
			   * (sizeof yyor - 1))];
	  char const *yyprefix = yyexpecting;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 1;

	  yyarg[0] = yytname[yytype];
	  yyfmt = yystpcpy (yyformat, yyunexpected);

	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
		  {
		    yycount = 1;
		    yysize = yysize0;
		    yyformat[sizeof yyunexpected - 1] = '\0';
		    break;
		  }
		yyarg[yycount++] = yytname[yyx];
		yysize1 = yysize + yytnamerr (0, yytname[yyx]);
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
		{
		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		    {
		      yyp += yytnamerr (yyp, yyarg[yyi++]);
		      yyf += 2;
		    }
		  else
		    {
		      yyp++;
		      yyf++;
		    }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
        }
      else
	{
	  yydestruct ("Error: discarding", yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (0)
     goto yyerrorlab;

yyvsp -= yylen;
  yyssp -= yylen;
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}



