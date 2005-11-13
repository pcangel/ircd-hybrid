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
     LAZYLINK = 354,
     LEAF_MASK = 355,
     LINKS_DELAY = 356,
     LISTEN = 357,
     T_LOG = 358,
     LOGGING = 359,
     LOG_LEVEL = 360,
     MAX_ACCEPT = 361,
     MAX_BANS = 362,
     MAX_CHANS_PER_USER = 363,
     MAX_GLOBAL = 364,
     MAX_IDENT = 365,
     MAX_LOCAL = 366,
     MAX_NICK_CHANGES = 367,
     MAX_NICK_TIME = 368,
     MAX_NUMBER = 369,
     MAX_TARGETS = 370,
     MAX_WATCH = 371,
     MESSAGE_LOCALE = 372,
     MIN_NONWILDCARD = 373,
     MIN_NONWILDCARD_SIMPLE = 374,
     MODULE = 375,
     MODULES = 376,
     NAME = 377,
     NEED_PASSWORD = 378,
     NETWORK_DESC = 379,
     NETWORK_NAME = 380,
     NICK = 381,
     NICK_CHANGES = 382,
     NO_CREATE_ON_SPLIT = 383,
     NO_JOIN_ON_SPLIT = 384,
     NO_OPER_FLOOD = 385,
     NO_TILDE = 386,
     NOT = 387,
     NUMBER = 388,
     NUMBER_PER_IDENT = 389,
     NUMBER_PER_CIDR = 390,
     NUMBER_PER_IP = 391,
     NUMBER_PER_IP_GLOBAL = 392,
     OPERATOR = 393,
     OPERS_BYPASS_CALLERID = 394,
     OPER_LOG = 395,
     OPER_ONLY_UMODES = 396,
     OPER_PASS_RESV = 397,
     OPER_SPY_T = 398,
     OPER_UMODES = 399,
     JOIN_FLOOD_COUNT = 400,
     JOIN_FLOOD_TIME = 401,
     PACE_WAIT = 402,
     PACE_WAIT_SIMPLE = 403,
     PASSWORD = 404,
     PATH = 405,
     PING_COOKIE = 406,
     PING_TIME = 407,
     PING_WARNING = 408,
     PORT = 409,
     QSTRING = 410,
     QUIET_ON_BAN = 411,
     REASON = 412,
     REDIRPORT = 413,
     REDIRSERV = 414,
     REGEX_T = 415,
     REHASH = 416,
     TREJECT_HOLD_TIME = 417,
     REMOTE = 418,
     REMOTEBAN = 419,
     RESTRICT_CHANNELS = 420,
     RESTRICTED = 421,
     RSA_PRIVATE_KEY_FILE = 422,
     RSA_PUBLIC_KEY_FILE = 423,
     SSL_CERTIFICATE_FILE = 424,
     RESV = 425,
     RESV_EXEMPT = 426,
     SECONDS = 427,
     MINUTES = 428,
     HOURS = 429,
     DAYS = 430,
     WEEKS = 431,
     SENDQ = 432,
     SEND_PASSWORD = 433,
     SERVERHIDE = 434,
     SERVERINFO = 435,
     SERVLINK_PATH = 436,
     IRCD_SID = 437,
     TKLINE_EXPIRE_NOTICES = 438,
     T_SHARED = 439,
     T_CLUSTER = 440,
     TYPE = 441,
     SHORT_MOTD = 442,
     SILENT = 443,
     SPOOF = 444,
     SPOOF_NOTICE = 445,
     STATS_I_OPER_ONLY = 446,
     STATS_K_OPER_ONLY = 447,
     STATS_O_OPER_ONLY = 448,
     STATS_P_OPER_ONLY = 449,
     TBOOL = 450,
     TMASKED = 451,
     T_REJECT = 452,
     TS_MAX_DELTA = 453,
     TS_WARN_DELTA = 454,
     TWODOTS = 455,
     T_ALL = 456,
     T_BOTS = 457,
     T_SOFTCALLERID = 458,
     T_CALLERID = 459,
     T_CCONN = 460,
     T_CLIENT_FLOOD = 461,
     T_DEAF = 462,
     T_DEBUG = 463,
     T_DRONE = 464,
     T_EXTERNAL = 465,
     T_FULL = 466,
     T_INVISIBLE = 467,
     T_IPV4 = 468,
     T_IPV6 = 469,
     T_LOCOPS = 470,
     T_LOGPATH = 471,
     T_L_CRIT = 472,
     T_L_DEBUG = 473,
     T_L_ERROR = 474,
     T_L_INFO = 475,
     T_L_NOTICE = 476,
     T_L_TRACE = 477,
     T_L_WARN = 478,
     T_MAX_CLIENTS = 479,
     T_NCHANGE = 480,
     T_OPERWALL = 481,
     T_REJ = 482,
     T_SERVNOTICE = 483,
     T_SKILL = 484,
     T_SPY = 485,
     T_SSL = 486,
     T_UMODES = 487,
     T_UNAUTH = 488,
     T_UNRESV = 489,
     T_UNXLINE = 490,
     T_WALLOP = 491,
     THROTTLE_TIME = 492,
     TOPICBURST = 493,
     TRUE_NO_OPER_FLOOD = 494,
     TKLINE = 495,
     TXLINE = 496,
     TRESV = 497,
     UNKLINE = 498,
     USER = 499,
     USE_EGD = 500,
     USE_EXCEPT = 501,
     USE_INVEX = 502,
     USE_KNOCK = 503,
     USE_LOGGING = 504,
     USE_WHOIS_ACTUALLY = 505,
     VHOST = 506,
     VHOST6 = 507,
     XLINE = 508,
     WARN = 509,
     WARN_NO_NLINE = 510
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
#define LAZYLINK 354
#define LEAF_MASK 355
#define LINKS_DELAY 356
#define LISTEN 357
#define T_LOG 358
#define LOGGING 359
#define LOG_LEVEL 360
#define MAX_ACCEPT 361
#define MAX_BANS 362
#define MAX_CHANS_PER_USER 363
#define MAX_GLOBAL 364
#define MAX_IDENT 365
#define MAX_LOCAL 366
#define MAX_NICK_CHANGES 367
#define MAX_NICK_TIME 368
#define MAX_NUMBER 369
#define MAX_TARGETS 370
#define MAX_WATCH 371
#define MESSAGE_LOCALE 372
#define MIN_NONWILDCARD 373
#define MIN_NONWILDCARD_SIMPLE 374
#define MODULE 375
#define MODULES 376
#define NAME 377
#define NEED_PASSWORD 378
#define NETWORK_DESC 379
#define NETWORK_NAME 380
#define NICK 381
#define NICK_CHANGES 382
#define NO_CREATE_ON_SPLIT 383
#define NO_JOIN_ON_SPLIT 384
#define NO_OPER_FLOOD 385
#define NO_TILDE 386
#define NOT 387
#define NUMBER 388
#define NUMBER_PER_IDENT 389
#define NUMBER_PER_CIDR 390
#define NUMBER_PER_IP 391
#define NUMBER_PER_IP_GLOBAL 392
#define OPERATOR 393
#define OPERS_BYPASS_CALLERID 394
#define OPER_LOG 395
#define OPER_ONLY_UMODES 396
#define OPER_PASS_RESV 397
#define OPER_SPY_T 398
#define OPER_UMODES 399
#define JOIN_FLOOD_COUNT 400
#define JOIN_FLOOD_TIME 401
#define PACE_WAIT 402
#define PACE_WAIT_SIMPLE 403
#define PASSWORD 404
#define PATH 405
#define PING_COOKIE 406
#define PING_TIME 407
#define PING_WARNING 408
#define PORT 409
#define QSTRING 410
#define QUIET_ON_BAN 411
#define REASON 412
#define REDIRPORT 413
#define REDIRSERV 414
#define REGEX_T 415
#define REHASH 416
#define TREJECT_HOLD_TIME 417
#define REMOTE 418
#define REMOTEBAN 419
#define RESTRICT_CHANNELS 420
#define RESTRICTED 421
#define RSA_PRIVATE_KEY_FILE 422
#define RSA_PUBLIC_KEY_FILE 423
#define SSL_CERTIFICATE_FILE 424
#define RESV 425
#define RESV_EXEMPT 426
#define SECONDS 427
#define MINUTES 428
#define HOURS 429
#define DAYS 430
#define WEEKS 431
#define SENDQ 432
#define SEND_PASSWORD 433
#define SERVERHIDE 434
#define SERVERINFO 435
#define SERVLINK_PATH 436
#define IRCD_SID 437
#define TKLINE_EXPIRE_NOTICES 438
#define T_SHARED 439
#define T_CLUSTER 440
#define TYPE 441
#define SHORT_MOTD 442
#define SILENT 443
#define SPOOF 444
#define SPOOF_NOTICE 445
#define STATS_I_OPER_ONLY 446
#define STATS_K_OPER_ONLY 447
#define STATS_O_OPER_ONLY 448
#define STATS_P_OPER_ONLY 449
#define TBOOL 450
#define TMASKED 451
#define T_REJECT 452
#define TS_MAX_DELTA 453
#define TS_WARN_DELTA 454
#define TWODOTS 455
#define T_ALL 456
#define T_BOTS 457
#define T_SOFTCALLERID 458
#define T_CALLERID 459
#define T_CCONN 460
#define T_CLIENT_FLOOD 461
#define T_DEAF 462
#define T_DEBUG 463
#define T_DRONE 464
#define T_EXTERNAL 465
#define T_FULL 466
#define T_INVISIBLE 467
#define T_IPV4 468
#define T_IPV6 469
#define T_LOCOPS 470
#define T_LOGPATH 471
#define T_L_CRIT 472
#define T_L_DEBUG 473
#define T_L_ERROR 474
#define T_L_INFO 475
#define T_L_NOTICE 476
#define T_L_TRACE 477
#define T_L_WARN 478
#define T_MAX_CLIENTS 479
#define T_NCHANGE 480
#define T_OPERWALL 481
#define T_REJ 482
#define T_SERVNOTICE 483
#define T_SKILL 484
#define T_SPY 485
#define T_SSL 486
#define T_UMODES 487
#define T_UNAUTH 488
#define T_UNRESV 489
#define T_UNXLINE 490
#define T_WALLOP 491
#define THROTTLE_TIME 492
#define TOPICBURST 493
#define TRUE_NO_OPER_FLOOD 494
#define TKLINE 495
#define TXLINE 496
#define TRESV 497
#define UNKLINE 498
#define USER 499
#define USE_EGD 500
#define USE_EXCEPT 501
#define USE_INVEX 502
#define USE_KNOCK 503
#define USE_LOGGING 504
#define USE_WHOIS_ACTUALLY 505
#define VHOST 506
#define VHOST6 507
#define XLINE 508
#define WARN 509
#define WARN_NO_NLINE 510




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
static char userbuf[IRCD_BUFSIZE];
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
#line 699 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 711 "y.tab.c"

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
#define YYLAST   1391

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  261
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  338
/* YYNRULES -- Number of rules. */
#define YYNRULES  726
/* YYNRULES -- Number of states. */
#define YYNSTATES  1464

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   510

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned short int yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   260,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   256,
       2,   259,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   258,     2,   257,     2,     2,     2,     2,
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
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255
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
    1291,  1293,  1295,  1300,  1305,  1310,  1315,  1320,  1325,  1330,
    1335,  1340,  1341,  1348,  1349,  1355,  1359,  1361,  1363,  1366,
    1368,  1370,  1372,  1374,  1376,  1381,  1386,  1387,  1394,  1397,
    1399,  1401,  1403,  1405,  1410,  1415,  1421,  1424,  1426,  1428,
    1430,  1435,  1436,  1443,  1444,  1450,  1454,  1456,  1458,  1461,
    1463,  1465,  1467,  1469,  1471,  1476,  1481,  1487,  1490,  1492,
    1494,  1496,  1498,  1500,  1502,  1504,  1506,  1508,  1510,  1512,
    1514,  1516,  1518,  1520,  1522,  1524,  1526,  1528,  1530,  1532,
    1534,  1536,  1538,  1540,  1542,  1544,  1546,  1548,  1550,  1552,
    1554,  1556,  1558,  1560,  1562,  1564,  1566,  1568,  1570,  1572,
    1574,  1576,  1578,  1580,  1582,  1584,  1586,  1588,  1590,  1592,
    1594,  1596,  1598,  1600,  1602,  1604,  1609,  1614,  1619,  1624,
    1629,  1634,  1639,  1644,  1649,  1654,  1659,  1664,  1669,  1674,
    1679,  1684,  1689,  1694,  1699,  1704,  1709,  1714,  1719,  1724,
    1729,  1734,  1739,  1744,  1749,  1754,  1759,  1764,  1769,  1774,
    1779,  1784,  1789,  1794,  1799,  1804,  1809,  1814,  1819,  1824,
    1829,  1834,  1839,  1844,  1849,  1854,  1855,  1861,  1865,  1867,
    1869,  1871,  1873,  1875,  1877,  1879,  1881,  1883,  1885,  1887,
    1889,  1891,  1893,  1895,  1897,  1899,  1901,  1903,  1904,  1910,
    1914,  1916,  1918,  1920,  1922,  1924,  1926,  1928,  1930,  1932,
    1934,  1936,  1938,  1940,  1942,  1944,  1946,  1948,  1950,  1952,
    1957,  1962,  1967,  1972,  1977,  1978,  1985,  1988,  1990,  1992,
    1994,  1996,  1998,  2000,  2002,  2004,  2009,  2014,  2015,  2021,
    2025,  2027,  2029,  2031,  2036,  2041,  2042,  2048,  2052,  2054,
    2056,  2058,  2064,  2067,  2069,  2071,  2073,  2075,  2077,  2079,
    2081,  2083,  2085,  2087,  2089,  2091,  2093,  2095,  2097,  2099,
    2101,  2103,  2105,  2110,  2115,  2120,  2125,  2130,  2135,  2140,
    2145,  2150,  2155,  2160,  2165,  2170,  2175,  2180,  2185,  2190,
    2196,  2199,  2201,  2203,  2205,  2207,  2209,  2211,  2213,  2215,
    2217,  2222,  2227,  2232,  2237,  2242,  2247
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
     262,     0,    -1,    -1,   262,   263,    -1,   287,    -1,   293,
      -1,   308,    -1,   569,    -1,   345,    -1,   364,    -1,   377,
      -1,   273,    -1,   589,    -1,   403,    -1,   410,    -1,   420,
      -1,   429,    -1,   459,    -1,   469,    -1,   475,    -1,   489,
      -1,   553,    -1,   479,    -1,   268,    -1,     1,   256,    -1,
       1,   257,    -1,    -1,   265,    -1,   133,   264,    -1,   133,
     172,   264,    -1,   133,   173,   264,    -1,   133,   174,   264,
      -1,   133,   175,   264,    -1,   133,   176,   264,    -1,    -1,
     267,    -1,   133,   266,    -1,   133,    14,   266,    -1,   133,
      15,   266,    -1,   133,    16,   266,    -1,   121,   258,   269,
     257,   256,    -1,   269,   270,    -1,   270,    -1,   271,    -1,
     272,    -1,     1,   256,    -1,   120,   259,   155,   256,    -1,
     150,   259,   155,   256,    -1,   180,   258,   274,   257,   256,
      -1,   274,   275,    -1,   275,    -1,   278,    -1,   283,    -1,
     286,    -1,   280,    -1,   281,    -1,   282,    -1,   285,    -1,
     277,    -1,   284,    -1,   279,    -1,   276,    -1,     1,   256,
      -1,   169,   259,   155,   256,    -1,   167,   259,   155,   256,
      -1,   122,   259,   155,   256,    -1,   182,   259,   155,   256,
      -1,    37,   259,   155,   256,    -1,   125,   259,   155,   256,
      -1,   124,   259,   155,   256,    -1,   251,   259,   155,   256,
      -1,   252,   259,   155,   256,    -1,   224,   259,   133,   256,
      -1,    85,   259,   195,   256,    -1,     5,   258,   288,   257,
     256,    -1,   288,   289,    -1,   289,    -1,   290,    -1,   292,
      -1,   291,    -1,     1,   256,    -1,   122,   259,   155,   256,
      -1,    47,   259,   155,   256,    -1,    37,   259,   155,   256,
      -1,   104,   258,   294,   257,   256,    -1,   294,   295,    -1,
     295,    -1,   296,    -1,   297,    -1,   306,    -1,   307,    -1,
     298,    -1,   300,    -1,   302,    -1,   303,    -1,   305,    -1,
     301,    -1,   304,    -1,   299,    -1,     1,   256,    -1,   216,
     259,   155,   256,    -1,   140,   259,   155,   256,    -1,    63,
     259,   155,   256,    -1,    56,   259,   155,   256,    -1,    61,
     259,   155,   256,    -1,    62,   259,   155,   256,    -1,    59,
     259,   155,   256,    -1,    58,   259,   155,   256,    -1,    60,
     259,   155,   256,    -1,    57,   259,   155,   256,    -1,   105,
     259,   217,   256,    -1,   105,   259,   219,   256,    -1,   105,
     259,   223,   256,    -1,   105,   259,   221,   256,    -1,   105,
     259,   222,   256,    -1,   105,   259,   220,   256,    -1,   105,
     259,   218,   256,    -1,   249,   259,   195,   256,    -1,    -1,
     138,   309,   310,   258,   311,   257,   256,    -1,    -1,   314,
      -1,   311,   312,    -1,   312,    -1,   313,    -1,   315,    -1,
     316,    -1,   335,    -1,   336,    -1,   320,    -1,   319,    -1,
     324,    -1,   325,    -1,   327,    -1,   328,    -1,   329,    -1,
     330,    -1,   331,    -1,   326,    -1,   332,    -1,   333,    -1,
     334,    -1,   337,    -1,   317,    -1,   318,    -1,   338,    -1,
       1,   256,    -1,   122,   259,   155,   256,    -1,   155,    -1,
     244,   259,   155,   256,    -1,   149,   259,   155,   256,    -1,
      49,   259,   195,   256,    -1,   168,   259,   155,   256,    -1,
      26,   259,   155,   256,    -1,    -1,   232,   321,   259,   322,
     256,    -1,   322,   260,   323,    -1,   323,    -1,   202,    -1,
     205,    -1,   207,    -1,   208,    -1,   211,    -1,   229,    -1,
     225,    -1,   227,    -1,   233,    -1,   230,    -1,   210,    -1,
     226,    -1,   228,    -1,   212,    -1,   236,    -1,   203,    -1,
     204,    -1,   215,    -1,    73,   259,   195,   256,    -1,   163,
     259,   195,   256,    -1,   164,   259,   195,   256,    -1,    93,
     259,   195,   256,    -1,   253,   259,   195,   256,    -1,   243,
     259,   195,   256,    -1,    66,   259,   195,   256,    -1,   127,
     259,   195,   256,    -1,    38,   259,   195,   256,    -1,   161,
     259,   195,   256,    -1,     5,   259,   195,   256,    -1,    78,
     259,   195,   256,    -1,    80,   259,   195,   256,    -1,   226,
     259,   195,   256,    -1,    -1,    54,   339,   259,   340,   256,
      -1,   340,   260,   341,    -1,   341,    -1,    -1,   132,   342,
     344,    -1,    -1,   343,   344,    -1,    73,    -1,   163,    -1,
      93,    -1,   243,    -1,   253,    -1,    66,    -1,    38,    -1,
     161,    -1,     5,    -1,    78,    -1,   127,    -1,   226,    -1,
     143,    -1,    80,    -1,   164,    -1,    49,    -1,    -1,    26,
     346,   347,   258,   348,   257,   256,    -1,    -1,   351,    -1,
     348,   349,    -1,   349,    -1,   350,    -1,   361,    -1,   362,
      -1,   352,    -1,   353,    -1,   363,    -1,   354,    -1,   355,
      -1,   356,    -1,   357,    -1,   358,    -1,   359,    -1,   360,
      -1,     1,   256,    -1,   122,   259,   155,   256,    -1,   155,
      -1,   152,   259,   265,   256,    -1,   153,   259,   265,   256,
      -1,   136,   259,   133,   256,    -1,    30,   259,   265,   256,
      -1,   114,   259,   133,   256,    -1,   109,   259,   133,   256,
      -1,   111,   259,   133,   256,    -1,   110,   259,   133,   256,
      -1,   177,   259,   267,   256,    -1,    23,   259,   133,   256,
      -1,    24,   259,   133,   256,    -1,   135,   259,   133,   256,
      -1,    -1,   102,   365,   258,   370,   257,   256,    -1,    -1,
      54,   367,   259,   368,   256,    -1,   368,   260,   369,    -1,
     369,    -1,   231,    -1,    77,    -1,   370,   371,    -1,   371,
      -1,   372,    -1,   366,    -1,   375,    -1,   376,    -1,     1,
     256,    -1,   154,   259,   373,   256,    -1,   373,   260,   374,
      -1,   374,    -1,   133,    -1,   133,   200,   133,    -1,    90,
     259,   155,   256,    -1,    84,   259,   155,   256,    -1,    -1,
      74,   378,   258,   379,   257,   256,    -1,   379,   380,    -1,
     380,    -1,   381,    -1,   382,    -1,   384,    -1,   386,    -1,
     393,    -1,   394,    -1,   395,    -1,   397,    -1,   398,    -1,
     399,    -1,   383,    -1,   400,    -1,   401,    -1,   396,    -1,
     402,    -1,   385,    -1,     1,   256,    -1,   244,   259,   155,
     256,    -1,   149,   259,   155,   256,    -1,   190,   259,   195,
     256,    -1,    26,   259,   155,   256,    -1,    49,   259,   195,
     256,    -1,    -1,    54,   387,   259,   388,   256,    -1,   388,
     260,   389,    -1,   389,    -1,    -1,   132,   390,   392,    -1,
      -1,   391,   392,    -1,   190,    -1,    50,    -1,    94,    -1,
      75,    -1,    20,    -1,    21,    -1,   131,    -1,    68,    -1,
     171,    -1,   123,    -1,    94,   259,   195,   256,    -1,    75,
     259,   195,   256,    -1,    50,   259,   195,   256,    -1,    20,
     259,   195,   256,    -1,   131,   259,   195,   256,    -1,    68,
     259,   195,   256,    -1,   189,   259,   155,   256,    -1,   159,
     259,   155,   256,    -1,   158,   259,   133,   256,    -1,   123,
     259,   195,   256,    -1,    -1,   170,   404,   258,   405,   257,
     256,    -1,   405,   406,    -1,   406,    -1,   407,    -1,   408,
      -1,   409,    -1,     1,   256,    -1,   157,   259,   155,   256,
      -1,    22,   259,   155,   256,    -1,   126,   259,   155,   256,
      -1,    -1,   184,   411,   258,   412,   257,   256,    -1,   412,
     413,    -1,   413,    -1,   414,    -1,   415,    -1,   416,    -1,
       1,   256,    -1,   122,   259,   155,   256,    -1,   244,   259,
     155,   256,    -1,    -1,   186,   417,   259,   418,   256,    -1,
     418,   260,   419,    -1,   419,    -1,    93,    -1,   240,    -1,
     243,    -1,   253,    -1,   241,    -1,   235,    -1,   170,    -1,
     242,    -1,   234,    -1,   215,    -1,   201,    -1,    -1,   185,
     421,   258,   422,   257,   256,    -1,   422,   423,    -1,   423,
      -1,   424,    -1,   425,    -1,     1,   256,    -1,   122,   259,
     155,   256,    -1,    -1,   186,   426,   259,   427,   256,    -1,
     427,   260,   428,    -1,   428,    -1,    93,    -1,   240,    -1,
     243,    -1,   253,    -1,   241,    -1,   235,    -1,   170,    -1,
     242,    -1,   234,    -1,   215,    -1,   201,    -1,    -1,    29,
     430,   431,   258,   432,   257,   256,    -1,    -1,   435,    -1,
     432,   433,    -1,   433,    -1,   434,    -1,   436,    -1,   437,
      -1,   438,    -1,   439,    -1,   441,    -1,   440,    -1,   442,
      -1,   443,    -1,   455,    -1,   456,    -1,   457,    -1,   454,
      -1,   451,    -1,   453,    -1,   452,    -1,   450,    -1,   458,
      -1,     1,   256,    -1,   122,   259,   155,   256,    -1,   155,
      -1,    84,   259,   155,   256,    -1,   251,   259,   155,   256,
      -1,   178,   259,   155,   256,    -1,     3,   259,   155,   256,
      -1,   154,   259,   133,   256,    -1,     6,   259,   213,   256,
      -1,     6,   259,   214,   256,    -1,    53,   259,   155,   256,
      -1,    -1,    54,   444,   259,   445,   256,    -1,   445,   260,
     446,    -1,   446,    -1,    -1,   132,   447,   449,    -1,    -1,
     448,   449,    -1,    99,    -1,    27,    -1,    31,    -1,    10,
      -1,    12,    -1,   238,    -1,   168,   259,   155,   256,    -1,
      49,   259,   195,   256,    -1,    31,   259,   195,   256,    -1,
      27,   259,   195,   256,    -1,    10,   259,   195,   256,    -1,
      86,   259,   155,   256,    -1,   100,   259,   155,   256,    -1,
      26,   259,   155,   256,    -1,    25,   259,   155,   256,    -1,
      -1,    91,   460,   258,   465,   257,   256,    -1,    -1,   186,
     462,   259,   463,   256,    -1,   463,   260,   464,    -1,   464,
      -1,   160,    -1,   465,   466,    -1,   466,    -1,   467,    -1,
     468,    -1,   461,    -1,     1,    -1,   244,   259,   155,   256,
      -1,   157,   259,   155,   256,    -1,    -1,    36,   470,   258,
     471,   257,   256,    -1,   471,   472,    -1,   472,    -1,   473,
      -1,   474,    -1,     1,    -1,    90,   259,   155,   256,    -1,
     157,   259,   155,   256,    -1,    51,   258,   476,   257,   256,
      -1,   476,   477,    -1,   477,    -1,   478,    -1,     1,    -1,
      90,   259,   155,   256,    -1,    -1,    64,   480,   258,   485,
     257,   256,    -1,    -1,   186,   482,   259,   483,   256,    -1,
     483,   260,   484,    -1,   484,    -1,   160,    -1,   485,   486,
      -1,   486,    -1,   487,    -1,   488,    -1,   481,    -1,     1,
      -1,   122,   259,   155,   256,    -1,   157,   259,   155,   256,
      -1,    65,   258,   490,   257,   256,    -1,   490,   491,    -1,
     491,    -1,   500,    -1,   501,    -1,   503,    -1,   504,    -1,
     505,    -1,   506,    -1,   507,    -1,   508,    -1,   509,    -1,
     510,    -1,   499,    -1,   512,    -1,   513,    -1,   514,    -1,
     515,    -1,   530,    -1,   516,    -1,   518,    -1,   520,    -1,
     519,    -1,   523,    -1,   517,    -1,   524,    -1,   525,    -1,
     526,    -1,   527,    -1,   529,    -1,   528,    -1,   544,    -1,
     531,    -1,   535,    -1,   536,    -1,   540,    -1,   521,    -1,
     522,    -1,   550,    -1,   548,    -1,   549,    -1,   532,    -1,
     502,    -1,   533,    -1,   534,    -1,   551,    -1,   539,    -1,
     511,    -1,   552,    -1,   537,    -1,   538,    -1,   495,    -1,
     498,    -1,   493,    -1,   494,    -1,   496,    -1,   497,    -1,
     492,    -1,     1,    -1,   116,   259,   133,   256,    -1,    71,
     259,   133,   256,    -1,    72,   259,   133,   256,    -1,    12,
     259,   195,   256,    -1,   250,   259,   195,   256,    -1,   162,
     259,   265,   256,    -1,   183,   259,   195,   256,    -1,    92,
     259,   133,   256,    -1,    83,   259,   195,   256,    -1,    88,
     259,   195,   256,    -1,    42,   259,   195,   256,    -1,    52,
     259,   195,   256,    -1,     8,   259,   195,   256,    -1,   113,
     259,   265,   256,    -1,   112,   259,   133,   256,    -1,   106,
     259,   133,   256,    -1,     9,   259,   265,   256,    -1,   199,
     259,   265,   256,    -1,   198,   259,   265,   256,    -1,    76,
     259,   133,   256,    -1,    96,   259,   195,   256,    -1,    95,
     259,   155,   256,    -1,    89,   259,   195,   256,    -1,   255,
     259,   195,   256,    -1,   193,   259,   195,   256,    -1,   194,
     259,   195,   256,    -1,   192,   259,   195,   256,    -1,   192,
     259,   196,   256,    -1,   191,   259,   195,   256,    -1,   191,
     259,   196,   256,    -1,   147,   259,   265,   256,    -1,    19,
     259,   265,   256,    -1,   139,   259,   195,   256,    -1,   148,
     259,   265,   256,    -1,   187,   259,   195,   256,    -1,   130,
     259,   195,   256,    -1,   239,   259,   195,   256,    -1,   142,
     259,   195,   256,    -1,   117,   259,   155,   256,    -1,    87,
     259,   265,   256,    -1,    44,   259,   133,   256,    -1,   115,
     259,   133,   256,    -1,   181,   259,   155,   256,    -1,    32,
     259,   155,   256,    -1,    28,   259,   133,   256,    -1,   245,
     259,   195,   256,    -1,    46,   259,   155,   256,    -1,   151,
     259,   195,   256,    -1,    39,   259,   195,   256,    -1,   237,
     259,   265,   256,    -1,    -1,   144,   541,   259,   542,   256,
      -1,   542,   260,   543,    -1,   543,    -1,   202,    -1,   205,
      -1,   207,    -1,   208,    -1,   211,    -1,   229,    -1,   225,
      -1,   227,    -1,   233,    -1,   230,    -1,   210,    -1,   226,
      -1,   228,    -1,   212,    -1,   236,    -1,   203,    -1,   204,
      -1,   215,    -1,    -1,   141,   545,   259,   546,   256,    -1,
     546,   260,   547,    -1,   547,    -1,   202,    -1,   205,    -1,
     207,    -1,   208,    -1,   211,    -1,   229,    -1,   225,    -1,
     227,    -1,   233,    -1,   230,    -1,   210,    -1,   226,    -1,
     228,    -1,   212,    -1,   236,    -1,   203,    -1,   204,    -1,
     215,    -1,   118,   259,   133,   256,    -1,   119,   259,   133,
     256,    -1,    33,   259,   133,   256,    -1,   206,   259,   267,
     256,    -1,    43,   259,   195,   256,    -1,    -1,    67,   554,
     258,   555,   257,   256,    -1,   555,   556,    -1,   556,    -1,
     557,    -1,   558,    -1,   559,    -1,   563,    -1,   564,    -1,
     565,    -1,     1,    -1,    48,   259,   195,   256,    -1,    45,
     259,   265,   256,    -1,    -1,   104,   560,   259,   561,   256,
      -1,   561,   260,   562,    -1,   562,    -1,   197,    -1,    11,
      -1,   244,   259,   155,   256,    -1,   122,   259,   155,   256,
      -1,    -1,     4,   566,   259,   567,   256,    -1,   567,   260,
     568,    -1,   568,    -1,   197,    -1,    11,    -1,    22,   258,
     570,   257,   256,    -1,   570,   571,    -1,   571,    -1,   573,
      -1,   574,    -1,   575,    -1,   576,    -1,   581,    -1,   577,
      -1,   578,    -1,   579,    -1,   580,    -1,   582,    -1,   583,
      -1,   584,    -1,   572,    -1,   585,    -1,   586,    -1,   587,
      -1,   588,    -1,     1,    -1,   165,   259,   195,   256,    -1,
      41,   259,   195,   256,    -1,   246,   259,   195,   256,    -1,
     247,   259,   195,   256,    -1,   248,   259,   195,   256,    -1,
      97,   259,   265,   256,    -1,    98,   259,   265,   256,    -1,
     108,   259,   133,   256,    -1,   156,   259,   195,   256,    -1,
     107,   259,   133,   256,    -1,    35,   259,   133,   256,    -1,
      34,   259,   133,   256,    -1,   128,   259,   195,   256,    -1,
     129,   259,   195,   256,    -1,    13,   259,   195,   256,    -1,
     145,   259,   133,   256,    -1,   146,   259,   265,   256,    -1,
     179,   258,   590,   257,   256,    -1,   590,   591,    -1,   591,
      -1,   592,    -1,   593,    -1,   595,    -1,   597,    -1,   596,
      -1,   594,    -1,   598,    -1,     1,    -1,    55,   259,   195,
     256,    -1,    82,   259,   195,   256,    -1,    79,   259,   155,
     256,    -1,   101,   259,   265,   256,    -1,    77,   259,   195,
     256,    -1,    40,   259,   195,   256,    -1,    81,   259,   195,
     256,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   383,   383,   384,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   412,   412,   413,   417,
     421,   425,   429,   433,   439,   439,   440,   441,   442,   443,
     450,   453,   453,   454,   454,   454,   456,   473,   484,   487,
     488,   489,   489,   490,   490,   491,   491,   492,   493,   493,
     494,   494,   495,   497,   531,   591,   605,   623,   632,   646,
     655,   683,   713,   736,   777,   779,   779,   780,   780,   781,
     781,   783,   792,   801,   814,   816,   817,   819,   819,   820,
     821,   821,   822,   822,   823,   823,   824,   824,   825,   826,
     828,   832,   836,   843,   850,   857,   864,   871,   878,   885,
     892,   896,   900,   904,   908,   912,   916,   922,   932,   931,
    1025,  1025,  1026,  1026,  1027,  1027,  1027,  1027,  1028,  1028,
    1029,  1029,  1029,  1030,  1030,  1030,  1031,  1031,  1031,  1032,
    1032,  1032,  1032,  1033,  1033,  1034,  1034,  1036,  1048,  1060,
    1079,  1091,  1102,  1144,  1154,  1153,  1158,  1158,  1159,  1162,
    1165,  1168,  1171,  1174,  1177,  1180,  1183,  1186,  1189,  1192,
    1195,  1198,  1201,  1204,  1207,  1210,  1215,  1226,  1237,  1248,
    1259,  1270,  1281,  1292,  1303,  1314,  1325,  1336,  1347,  1358,
    1370,  1369,  1373,  1373,  1374,  1374,  1375,  1375,  1377,  1384,
    1391,  1398,  1405,  1412,  1419,  1426,  1433,  1440,  1447,  1454,
    1461,  1468,  1475,  1482,  1496,  1495,  1537,  1537,  1539,  1539,
    1540,  1541,  1541,  1542,  1543,  1544,  1545,  1546,  1547,  1548,
    1549,  1550,  1551,  1552,  1554,  1563,  1572,  1578,  1584,  1590,
    1596,  1602,  1608,  1614,  1620,  1626,  1632,  1638,  1648,  1647,
    1664,  1663,  1667,  1667,  1668,  1672,  1678,  1678,  1679,  1679,
    1679,  1679,  1679,  1681,  1683,  1683,  1685,  1700,  1722,  1731,
    1744,  1743,  1812,  1812,  1813,  1813,  1813,  1813,  1814,  1814,
    1815,  1815,  1815,  1816,  1816,  1817,  1817,  1817,  1818,  1818,
    1818,  1820,  1839,  1852,  1863,  1872,  1884,  1883,  1887,  1887,
    1888,  1888,  1889,  1889,  1891,  1899,  1906,  1913,  1920,  1927,
    1934,  1941,  1948,  1955,  1964,  1975,  1986,  1997,  2008,  2019,
    2031,  2050,  2060,  2069,  2085,  2084,  2100,  2100,  2101,  2101,
    2101,  2101,  2103,  2112,  2127,  2141,  2140,  2156,  2156,  2157,
    2157,  2157,  2157,  2159,  2168,  2177,  2176,  2182,  2182,  2183,
    2187,  2191,  2195,  2199,  2203,  2207,  2211,  2215,  2219,  2223,
    2233,  2232,  2247,  2247,  2248,  2248,  2248,  2250,  2260,  2259,
    2265,  2265,  2266,  2270,  2274,  2278,  2282,  2286,  2290,  2294,
    2298,  2302,  2306,  2316,  2315,  2465,  2465,  2466,  2466,  2467,
    2467,  2467,  2468,  2468,  2469,  2469,  2470,  2470,  2470,  2471,
    2471,  2471,  2472,  2472,  2472,  2473,  2473,  2474,  2476,  2488,
    2500,  2509,  2535,  2553,  2571,  2577,  2581,  2589,  2599,  2598,
    2602,  2602,  2603,  2603,  2604,  2604,  2606,  2613,  2624,  2631,
    2638,  2645,  2655,  2696,  2707,  2718,  2733,  2744,  2757,  2770,
    2779,  2815,  2814,  2876,  2875,  2879,  2879,  2880,  2886,  2886,
    2887,  2887,  2887,  2887,  2889,  2905,  2915,  2914,  2936,  2936,
    2937,  2937,  2937,  2939,  2948,  2960,  2962,  2962,  2963,  2963,
    2965,  2987,  2986,  3028,  3027,  3031,  3031,  3032,  3038,  3038,
    3039,  3039,  3039,  3039,  3041,  3047,  3056,  3059,  3059,  3060,
    3060,  3061,  3061,  3062,  3062,  3063,  3063,  3064,  3064,  3065,
    3065,  3066,  3066,  3067,  3067,  3068,  3068,  3069,  3069,  3070,
    3070,  3071,  3071,  3072,  3072,  3073,  3073,  3074,  3074,  3075,
    3075,  3076,  3076,  3077,  3077,  3078,  3078,  3079,  3079,  3080,
    3081,  3081,  3082,  3082,  3083,  3083,  3084,  3084,  3085,  3085,
    3086,  3086,  3087,  3087,  3088,  3091,  3096,  3101,  3106,  3111,
    3116,  3121,  3126,  3131,  3136,  3141,  3146,  3151,  3156,  3161,
    3166,  3171,  3176,  3181,  3187,  3198,  3203,  3212,  3217,  3222,
    3227,  3232,  3235,  3240,  3243,  3248,  3253,  3258,  3263,  3268,
    3273,  3278,  3283,  3288,  3299,  3304,  3309,  3314,  3323,  3355,
    3373,  3378,  3387,  3392,  3397,  3403,  3402,  3407,  3407,  3408,
    3411,  3414,  3417,  3420,  3423,  3426,  3429,  3432,  3435,  3438,
    3441,  3444,  3447,  3450,  3453,  3456,  3459,  3465,  3464,  3469,
    3469,  3470,  3473,  3476,  3479,  3482,  3485,  3488,  3491,  3494,
    3497,  3500,  3503,  3506,  3509,  3512,  3515,  3518,  3521,  3526,
    3531,  3536,  3541,  3546,  3555,  3554,  3578,  3578,  3579,  3580,
    3581,  3582,  3583,  3584,  3585,  3587,  3593,  3600,  3599,  3604,
    3604,  3605,  3609,  3615,  3632,  3642,  3641,  3691,  3691,  3692,
    3696,  3705,  3708,  3708,  3709,  3709,  3710,  3710,  3711,  3711,
    3712,  3712,  3713,  3713,  3714,  3715,  3715,  3716,  3716,  3717,
    3717,  3718,  3720,  3725,  3730,  3735,  3740,  3745,  3750,  3755,
    3760,  3765,  3770,  3775,  3780,  3785,  3790,  3795,  3800,  3808,
    3811,  3811,  3812,  3812,  3813,  3814,  3815,  3815,  3816,  3817,
    3819,  3825,  3831,  3840,  3854,  3860,  3866
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
  "KLINE_WITH_REASON", "KNOCK_DELAY", "KNOCK_DELAY_CHANNEL", "LAZYLINK",
  "LEAF_MASK", "LINKS_DELAY", "LISTEN", "T_LOG", "LOGGING", "LOG_LEVEL",
  "MAX_ACCEPT", "MAX_BANS", "MAX_CHANS_PER_USER", "MAX_GLOBAL",
  "MAX_IDENT", "MAX_LOCAL", "MAX_NICK_CHANGES", "MAX_NICK_TIME",
  "MAX_NUMBER", "MAX_TARGETS", "MAX_WATCH", "MESSAGE_LOCALE",
  "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE", "MODULE", "MODULES", "NAME",
  "NEED_PASSWORD", "NETWORK_DESC", "NETWORK_NAME", "NICK", "NICK_CHANGES",
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
     505,   506,   507,   508,   509,   510,    59,   125,   123,    61,
      44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short int yyr1[] =
{
       0,   261,   262,   262,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   264,   264,   265,   265,
     265,   265,   265,   265,   266,   266,   267,   267,   267,   267,
     268,   269,   269,   270,   270,   270,   271,   272,   273,   274,
     274,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   288,   289,   289,   289,
     289,   290,   291,   292,   293,   294,   294,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   306,   306,   306,   306,   306,   306,   307,   309,   308,
     310,   310,   311,   311,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   313,   314,   315,
     316,   317,   318,   319,   321,   320,   322,   322,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     339,   338,   340,   340,   342,   341,   343,   341,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   346,   345,   347,   347,   348,   348,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   365,   364,
     367,   366,   368,   368,   369,   369,   370,   370,   371,   371,
     371,   371,   371,   372,   373,   373,   374,   374,   375,   376,
     378,   377,   379,   379,   380,   380,   380,   380,   380,   380,
     380,   380,   380,   380,   380,   380,   380,   380,   380,   380,
     380,   381,   382,   383,   384,   385,   387,   386,   388,   388,
     390,   389,   391,   389,   392,   392,   392,   392,   392,   392,
     392,   392,   392,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   404,   403,   405,   405,   406,   406,
     406,   406,   407,   408,   409,   411,   410,   412,   412,   413,
     413,   413,   413,   414,   415,   417,   416,   418,   418,   419,
     419,   419,   419,   419,   419,   419,   419,   419,   419,   419,
     421,   420,   422,   422,   423,   423,   423,   424,   426,   425,
     427,   427,   428,   428,   428,   428,   428,   428,   428,   428,
     428,   428,   428,   430,   429,   431,   431,   432,   432,   433,
     433,   433,   433,   433,   433,   433,   433,   433,   433,   433,
     433,   433,   433,   433,   433,   433,   433,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   441,   442,   444,   443,
     445,   445,   447,   446,   448,   446,   449,   449,   449,   449,
     449,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   460,   459,   462,   461,   463,   463,   464,   465,   465,
     466,   466,   466,   466,   467,   468,   470,   469,   471,   471,
     472,   472,   472,   473,   474,   475,   476,   476,   477,   477,
     478,   480,   479,   482,   481,   483,   483,   484,   485,   485,
     486,   486,   486,   486,   487,   488,   489,   490,   490,   491,
     491,   491,   491,   491,   491,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   491,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   491,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   491,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   491,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   518,   519,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   541,   540,   542,   542,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   545,   544,   546,
     546,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   548,
     549,   550,   551,   552,   554,   553,   555,   555,   556,   556,
     556,   556,   556,   556,   556,   557,   558,   560,   559,   561,
     561,   562,   562,   563,   564,   566,   565,   567,   567,   568,
     568,   569,   570,   570,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   590,   591,   591,   591,   591,   591,   591,   591,   591,
     592,   593,   594,   595,   596,   597,   598
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
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     0,     6,     0,     5,     3,     1,     1,     2,     1,
       1,     1,     1,     1,     4,     4,     0,     6,     2,     1,
       1,     1,     1,     4,     4,     5,     2,     1,     1,     1,
       4,     0,     6,     0,     5,     3,     1,     1,     2,     1,
       1,     1,     1,     1,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     0,     5,     3,
       1,     1,     1,     4,     4,     0,     5,     3,     1,     1,
       1,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short int yydefact[] =
{
       2,     0,     1,     0,     0,     0,   214,   383,   456,     0,
     471,     0,   644,   270,   441,   248,     0,     0,   118,   324,
       0,     0,   335,   360,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      22,    20,    21,     7,    12,    24,    25,     0,     0,   216,
     385,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,    77,    79,    78,   691,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   673,   686,   674,   675,   676,
     677,   679,   680,   681,   682,   678,   683,   684,   685,   687,
     688,   689,   690,   235,     0,   217,   409,     0,   386,     0,
     469,     0,     0,   467,   468,     0,   544,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     617,     0,   595,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   488,   543,   539,   540,   537,   541,   542,
     538,   499,   489,   490,   528,   491,   492,   493,   494,   495,
     496,   497,   498,   533,   500,   501,   502,   503,   505,   510,
     506,   508,   507,   522,   523,   509,   511,   512,   513,   514,
     516,   515,   504,   518,   527,   529,   530,   519,   520,   535,
     536,   532,   521,   517,   525,   526,   524,   531,   534,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      91,    98,    92,    96,    93,    94,    97,    95,    89,    90,
       0,     0,     0,     0,    42,    43,    44,   148,     0,   121,
       0,   719,     0,     0,     0,     0,     0,     0,     0,     0,
     711,   712,   713,   717,   714,   716,   715,   718,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,    61,    58,    51,    60,    54,    55,    56,    52,
      59,    57,    53,     0,     0,    80,     0,     0,     0,     0,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   672,
       0,     0,   462,     0,     0,     0,   459,   460,   461,     0,
       0,   466,   483,     0,     0,   473,   482,     0,   479,   480,
     481,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   487,   654,   665,
       0,     0,   657,     0,     0,     0,   647,   648,   649,   650,
     651,   652,   653,     0,     0,     0,     0,     0,   296,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   273,   274,   275,   284,   276,   289,   277,   278,   279,
     280,   287,   281,   282,   283,   285,   286,   288,   453,     0,
     443,     0,   452,     0,   449,   450,   451,     0,   250,     0,
       0,     0,   259,     0,   257,   258,   260,   261,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    85,    45,     0,     0,     0,    41,     0,     0,
       0,     0,     0,     0,   327,   328,   329,   330,     0,     0,
       0,     0,     0,     0,     0,     0,   710,    62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,     0,     0,   345,     0,     0,   338,   339,   340,   341,
       0,     0,   368,     0,   363,   364,   365,     0,     0,     0,
      74,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   671,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   219,   220,   223,   224,   226,
     227,   228,   229,   230,   231,   232,   221,   222,   225,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   418,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   388,
     389,   390,   391,   392,   393,   395,   394,   396,   397,   405,
     402,   404,   403,   401,   398,   399,   400,   406,     0,     0,
       0,   458,     0,   465,     0,     0,     0,     0,   478,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,   486,     0,     0,
       0,     0,     0,     0,     0,   646,   290,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   272,     0,     0,     0,     0,   448,
     262,     0,     0,     0,     0,     0,   256,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,     0,     0,    40,     0,
       0,     0,     0,     0,   190,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   154,     0,
       0,     0,     0,   123,   124,   125,   126,   143,   144,   130,
     129,   131,   132,   138,   133,   134,   135,   136,   137,   139,
     140,   141,   127,   128,   142,   145,   331,     0,     0,     0,
       0,   326,     0,     0,     0,     0,     0,     0,     0,   709,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,   342,     0,     0,     0,     0,   337,   366,     0,
       0,     0,   362,    83,    82,    81,   706,   703,   702,   693,
      26,    26,    26,    26,    26,    28,    27,   697,   698,   701,
     699,   704,   705,   707,   708,   700,   692,   694,   695,   696,
     233,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   218,   407,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   387,     0,     0,   457,
     470,     0,     0,     0,   472,   557,   561,   548,   576,   589,
     588,   641,   593,   555,   643,   585,   591,   556,   546,   547,
     564,   553,   584,   554,   567,   552,   566,   565,   560,   559,
     558,   586,   545,   583,   639,   640,   580,   577,   621,   636,
     637,   622,   623,   624,   631,   625,   634,   638,   627,   632,
     628,   633,   626,   630,   629,   635,     0,   620,   582,   599,
     614,   615,   600,   601,   602,   609,   603,   612,   616,   605,
     610,   606,   611,   604,   608,   607,   613,     0,   598,   575,
     578,   592,   550,   587,   551,   579,   573,   574,   571,   572,
     569,   570,   563,   562,    34,    34,    34,    36,    35,   642,
     594,   581,   590,   549,   568,     0,     0,     0,     0,     0,
       0,   645,     0,     0,     0,     0,   302,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   271,     0,
       0,     0,   442,     0,     0,     0,   266,     0,   265,   249,
     103,   109,   107,   106,   108,   104,   105,   102,   110,   116,
     111,   115,   113,   114,   112,   101,   100,   117,    46,    47,
     146,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   122,     0,     0,     0,   325,   725,
     720,   724,   722,   726,   721,   723,    67,    73,    65,    69,
      68,    64,    63,    66,    72,    70,    71,     0,     0,     0,
     336,     0,     0,   361,    29,    30,    31,    32,    33,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   215,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   424,     0,     0,     0,     0,     0,     0,
       0,     0,   384,   463,   464,   484,   485,   477,     0,   476,
     618,     0,   596,     0,    37,    38,    39,   670,   669,     0,
     668,   656,   655,   662,   661,     0,   660,   664,   663,   317,
     294,   295,   316,   300,     0,   299,     0,   319,   315,   314,
     323,   318,   292,   322,   321,   320,   293,   291,   455,   447,
       0,   446,   454,   255,   254,     0,   253,   269,   268,     0,
     263,     0,     0,     0,     0,     0,   196,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   119,   333,   334,   332,   343,   349,
     355,   359,   358,   357,   354,   350,   353,   356,   351,   352,
       0,   348,   344,   367,   372,   378,   382,   381,   380,   377,
     373,   376,   379,   374,   375,     0,   371,   245,   246,   239,
     241,   243,   242,   240,   234,   247,   238,   236,   237,   244,
     413,   415,   416,   436,   440,   439,   435,   434,   433,   417,
     422,     0,   421,     0,   410,   437,   438,   408,   414,   432,
     412,   411,   474,     0,   619,   597,   666,     0,   658,     0,
       0,   297,   302,   308,   309,   305,   311,   307,   306,   313,
     310,   312,   304,   303,   444,     0,   251,     0,   267,   264,
     186,   153,   184,   151,   194,     0,   193,     0,   182,   176,
     187,   188,   179,   147,   183,   150,   185,   177,   178,   152,
     189,   158,   173,   174,   159,   160,   161,   168,   162,   171,
     175,   164,   169,   165,   170,   163,   167,   166,   172,     0,
     157,   181,   149,   180,   346,     0,   369,     0,     0,   419,
     424,   429,   430,   427,   428,   426,   431,   425,   475,   667,
     659,   301,   298,   445,   252,     0,   191,   196,   206,   204,
     213,   203,   198,   207,   211,   200,   208,   210,   205,   199,
     212,   209,   201,   202,   197,   155,     0,   347,   370,   423,
     420,   195,   192,   156
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
    1376,  1435,  1377,  1454,    30,    49,   114,   604,   605,   606,
     115,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,    31,    58,   492,   761,  1245,  1246,   493,
     494,   495,  1077,  1078,   496,   497,    32,    56,   460,   461,
     462,   463,   464,   465,   466,   467,   741,  1224,  1225,  1350,
    1226,  1363,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,    33,    62,   523,   524,   525,   526,   527,    34,
      65,   555,   556,   557,   558,   559,   864,  1290,  1291,    35,
      66,   563,   564,   565,   566,   870,  1305,  1306,    36,    50,
     117,   638,   639,   640,   118,   641,   642,   643,   644,   645,
     646,   647,   648,   926,  1331,  1332,  1418,  1333,  1427,   649,
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
#define YYPACT_NINF -837
static const short int yypact[] =
{
    -837,   824,  -837,  -166,  -248,  -239,  -837,  -837,  -837,  -234,
    -837,  -223,  -837,  -837,  -837,  -837,  -217,  -207,  -837,  -837,
    -198,  -187,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,   200,   734,   -73,
     -67,  -161,    15,  -155,   499,  -149,  -143,  -130,  -113,   667,
      33,    -7,  -108,   543,   482,  -103,   -89,   -80,   -81,   -72,
     -70,    27,  -837,  -837,  -837,  -837,  -837,   -59,   -56,   -49,
     -33,   -30,   -27,    -9,    13,    19,    21,    50,    53,    67,
      68,    70,    74,    76,   223,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,   -66,  -837,  -837,   -63,  -837,     4,
    -837,    79,     3,  -837,  -837,    22,  -837,    80,    84,    85,
      87,    89,    91,    94,    95,   105,   111,   112,   116,   119,
     121,   123,   124,   125,   126,   127,   131,   134,   136,   137,
     143,   145,   147,   148,   150,   151,   157,   158,   161,   164,
    -837,   165,  -837,   168,   169,   170,   171,   176,   182,   183,
     185,   186,   188,   190,   192,   203,   204,   205,   209,   214,
     215,   216,    24,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,   388,
     745,    39,   313,     0,   218,   219,   220,   222,   225,   226,
     228,   229,   230,   231,   234,   235,   300,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
      78,   238,   243,    14,  -837,  -837,  -837,  -837,    12,  -837,
      20,  -837,   246,   247,   254,   255,   256,   258,   261,   371,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,   245,   262,
     264,   265,   266,   267,   269,   270,   271,   274,   276,   278,
     252,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,     5,    11,  -837,   120,   327,   384,   284,
    -837,   152,   207,   413,   352,   415,   415,   417,   419,   358,
     359,   425,   415,   364,   365,   370,   374,   377,   317,  -837,
     786,   412,  -837,   319,   320,    28,  -837,  -837,  -837,   426,
     328,  -837,  -837,   326,   330,  -837,  -837,    16,  -837,  -837,
    -837,   397,   415,   398,   415,   463,   442,   466,   405,   406,
     407,   470,   453,   414,   477,   480,   486,   428,   415,   432,
     436,   488,   478,   440,   503,   504,   415,   506,   509,   490,
     515,   519,   458,   459,   399,   461,   401,   415,   415,   462,
     415,   507,   471,   474,   -38,    92,   476,   479,   415,   415,
     532,   415,   481,   484,   489,   493,   416,  -837,  -837,  -837,
     418,   422,  -837,   430,   437,    10,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,   429,   441,   444,   445,   449,  -837,   451,
     452,   454,   460,   472,   473,   483,   491,   494,   496,   498,
     242,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,   500,
    -837,   501,  -837,     2,  -837,  -837,  -837,   456,  -837,   502,
     508,   514,  -837,     8,  -837,  -837,  -837,  -837,  -837,   518,
     520,   562,   563,   565,   566,   582,   584,   237,   585,   586,
     548,   510,  -837,  -837,   597,   603,   521,  -837,   629,   523,
     517,   522,   524,    88,  -837,  -837,  -837,  -837,   567,   579,
     591,   625,   593,   596,   415,   540,  -837,  -837,   643,   605,
     647,   648,   649,   650,   651,   653,   678,   657,   659,   559,
    -837,   561,   560,  -837,   564,    58,  -837,  -837,  -837,  -837,
     571,   569,  -837,    48,  -837,  -837,  -837,   574,   577,   578,
    -837,   580,   581,   587,   588,   -95,   589,   592,   595,   598,
     600,   601,   602,   609,   611,   613,   614,   615,   628,  -837,
     630,   576,   590,   618,   622,   633,   634,   642,   646,   652,
     654,   655,   658,   660,   189,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,   631,
     661,   665,   666,   668,   670,   671,   672,   673,   674,  -837,
     677,   681,   682,   685,   687,   688,   693,   694,    98,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,   683,   697,
     656,  -837,   662,  -837,   704,   747,   696,   698,  -837,   700,
     701,   702,   703,   709,   710,   711,   712,   713,   714,   715,
     716,   717,   718,   719,   720,   721,   722,   723,   727,   728,
     729,   730,   731,   732,   735,   736,   737,   739,   740,   741,
     742,   743,   808,   744,   843,   746,   749,   750,   751,   758,
     761,   765,   766,   768,   769,   770,   771,   772,   773,   774,
     292,   775,   776,   783,   784,   787,   793,  -837,   705,   415,
     626,   797,   752,   755,   796,  -837,  -837,   627,   782,   645,
     795,   798,   806,   847,   864,   865,   866,   805,   929,   908,
     909,   870,   911,   811,  -837,   919,   816,   922,   822,  -837,
    -837,   825,   932,   936,   959,   838,  -837,   839,   840,   841,
     842,   844,   845,   846,   853,   854,   856,   857,   859,   860,
     861,   862,   863,   867,   868,  -837,   869,   871,  -837,   872,
     873,   874,   875,   876,  -837,   877,   879,   880,   881,   882,
     883,   884,   885,   886,   887,   888,   889,   890,  -837,   891,
     892,   893,   155,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,   944,   965,   966,
     897,  -837,   898,   899,   900,   901,   902,   903,   904,  -837,
     905,   906,   907,   910,   912,   913,   914,   915,   916,   917,
     918,  -837,  -837,   967,   920,   971,   921,  -837,  -837,   974,
     923,   924,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
     415,   415,   415,   415,   415,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,   997,   998,   415,  1004,  1031,  1032,  1034,  1020,  1043,
    1045,   415,   415,   532,   925,  -837,  -837,  1028,    81,   989,
    1030,  1033,   991,   992,   994,  1035,   933,  1036,  1038,  1039,
    1040,  1063,  1042,  1044,  1046,   942,  -837,   946,   947,  -837,
    -837,   948,   949,  1047,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -238,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -230,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,   532,   532,   532,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,    -3,   950,   952,     9,   953,
     954,  -837,   955,   956,   957,   958,  1068,   960,   961,   962,
     963,   964,   968,   969,   970,   972,   973,   975,  -837,   976,
    1055,   977,  -837,   -64,   978,   979,   706,  -229,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  1026,  1067,  1041,  1048,   980,  1049,  1050,  1051,  1052,
    1053,  1072,  1054,  1075,  1056,  1057,  1058,  1082,  1059,   981,
    1060,  1083,  1061,   985,  -837,   986,  1001,  1002,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  1003,   321,  1005,
    -837,  1006,   708,  -837,  -837,  -837,  -837,  -837,  -837,  1007,
    1008,  1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,
    1018,  1019,  -837,  1021,  1022,  1023,  1024,  1025,  1027,  1029,
    1037,  1062,  1064,  1091,  1065,  1066,  1069,  1070,  1071,  1073,
    1074,  1076,  -837,  -837,  -837,  -837,  -837,  -837,  -206,  -837,
    -837,   808,  -837,   843,  -837,  -837,  -837,  -837,  -837,  -191,
    -837,  -837,  -837,  -837,  -837,  -139,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -134,  -837,   695,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -125,  -837,  -837,  -837,  -837,   -29,  -837,  -837,  -837,  1117,
    -837,   959,  1077,  1078,  1079,  1080,  1128,  1081,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1092,  1093,  1094,  1095,  1096,
     878,  1097,  1098,  1099,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
     -18,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,    -5,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,    30,  -837,    75,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  1047,  -837,  -837,  -837,    -3,  -837,     9,
     695,  -837,  1068,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  1055,  -837,   -64,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,    37,  -837,   621,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,    72,
    -837,  -837,  -837,  -837,  -837,   321,  -837,   708,    75,  -837,
    1091,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,   621,  -837,  1128,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,   878,  -837,  -837,  -837,
    -837,  -837,  -837,  -837
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -837,  -837,  -837,  -836,  -335,  -795,  -418,  -837,  -837,  1100,
    -837,  -837,  -837,  -837,   982,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  1205,  -837,
    -837,  -837,  -837,  -837,  1101,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,   475,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -174,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -153,  -837,  -837,  -147,  -837,  -837,  -837,  -837,   686,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,   -78,  -837,
     801,  -837,  -837,    35,  -837,  -837,  -837,  -837,  -837,   831,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,   -57,  -837,
    -837,   -54,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,   777,  -837,  -837,  -837,  -837,
    -837,  -837,   748,  -837,  -837,  -837,  -837,  -837,  -118,  -837,
    -837,  -837,   738,  -837,  -837,  -837,  -837,  -119,  -837,  -837,
    -837,  -837,   664,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -121,  -837,  -837,  -114,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,   -60,  -837,   823,  -837,  -837,  -837,  -837,
    -837,   983,  -837,  -837,  -837,  -837,  1185,  -837,  -837,  -837,
    -837,  -837,  -837,   -35,  -837,   943,  -837,  -837,  -837,  -837,
    1127,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,   108,  -837,  -837,  -837,   113,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,   896,  -837,  -837,  -837,  -837,
    -837,   -37,  -837,  -837,  -837,  -837,  -837,   -34,  -837,  -837,
    1221,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    1102,  -837,  -837,  -837,  -837,  -837,  -837,  -837
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned short int yytable[] =
{
     576,   577,   721,   478,   120,   352,   551,   583,  1207,   487,
      47,   428,   560,  1243,   429,   270,   120,   362,  1200,    48,
    1213,   519,  1201,   362,    52,   126,  1202,  1250,    67,   352,
    1203,  1251,   127,   128,   270,    54,   129,   670,   575,   672,
     478,    59,   520,   130,  1154,  1155,  1156,  1157,  1158,   560,
    1342,    60,   131,   686,  1343,   430,   132,   133,   431,   551,
      63,   694,   488,   134,    68,  1346,   135,   136,   137,  1347,
     138,    64,   705,   706,    69,   708,   139,   880,   881,   882,
     883,   884,   113,   718,   719,  1421,   722,  1422,   116,   519,
      45,    46,   489,   121,   353,   140,   141,   119,   490,   619,
     142,   620,  1423,   125,   621,   121,  1424,   143,   622,   239,
     520,   144,   145,   146,   432,   240,   147,  1348,   353,   148,
     149,  1349,  1351,   623,   624,   625,  1352,   552,   241,   626,
     150,  1364,   433,   561,   271,  1365,   151,   152,   363,   153,
     154,   155,   156,   157,   363,   242,   521,   627,   277,    70,
     280,   628,   629,   271,   158,   323,   789,   712,   713,   479,
     790,   354,   491,   159,   272,   160,   161,  1244,   162,   324,
     561,   163,   164,   364,  1425,   165,   325,   522,   326,   364,
     552,   791,   630,   272,   631,   354,   166,   327,   480,   328,
     590,   553,   350,   792,  1208,   351,   479,   562,   632,   848,
     331,    67,   365,   332,   793,   167,  1214,   168,   365,   794,
     333,   169,   591,   592,   521,   170,   171,   172,   173,   593,
     633,   795,   174,   175,    76,   480,   334,  1366,   796,   335,
     176,  1367,   336,   797,   562,   798,    77,    68,  1414,  1204,
    1205,  1206,  1415,   443,   553,   522,   481,    69,   799,   554,
     337,  1416,   634,   298,   434,  1417,   498,    78,    79,   758,
     360,   177,   444,   178,    80,   765,   635,   734,   445,   179,
     518,   516,   338,   667,   180,   567,   636,   800,   339,   181,
     340,   426,   801,   481,   329,   660,  1419,   714,   715,   299,
    1420,   446,   447,  1436,  1174,  1175,   448,  1437,   594,   595,
     596,   243,   554,   597,   802,   871,  1034,  1035,  1036,   341,
     449,   598,   342,  1426,   487,   866,   803,   450,   804,   805,
      81,    82,    70,   806,   599,   600,   343,   344,  1455,   345,
      83,    84,  1456,   346,   513,   347,   451,   300,   359,   371,
     572,   601,   602,   372,   373,   840,   374,   571,   375,   637,
     376,    85,    86,   377,   378,   935,   244,   245,   246,   247,
     248,   249,   250,   251,   379,   452,   603,   488,    87,    88,
     380,   381,   281,   453,   301,   382,   302,   303,   383,    89,
     384,   807,   385,   386,   387,   388,   389,   808,    90,   428,
     390,   454,   429,   391,  1046,   392,   393,   489,   809,   810,
     455,   456,   394,   490,   395,   252,   396,   397,   811,   398,
     399,   282,  1123,   619,  1279,   620,   400,   401,   621,   304,
     402,   305,   622,   403,   405,   720,   283,   407,   408,   409,
     410,   457,   458,   430,   306,   411,   431,   623,   624,   625,
     253,   412,   413,   626,   414,   415,   914,   416,   284,   417,
     285,   418,   286,   287,   775,   776,   777,   778,   779,   780,
     781,   627,   419,   420,   421,   628,   629,   491,   422,    91,
      92,    93,   288,   423,   424,   425,   307,   499,   500,   501,
     348,   502,   568,   298,   503,   504,   459,   505,   506,   507,
     508,  1280,   432,   509,   510,  1171,   630,   514,   631,   753,
     126,   537,   515,   308,   309,   528,   529,   127,   128,   549,
     433,   129,   632,   530,   531,   532,   254,   533,   130,   299,
     534,   538,  1281,   539,   540,   541,   542,   131,   543,   544,
     545,   132,   133,   546,   633,   547,  1282,   548,   134,   569,
     570,   135,   136,   137,   281,   138,   573,   574,   575,   255,
     578,   139,   579,   580,   581,  1283,  1284,   511,   582,   584,
     585,  1285,  1286,  1287,  1288,   586,   634,   300,  1161,   587,
     140,   141,   588,   589,  1289,   142,  1169,  1170,   658,   659,
     635,   662,   143,   282,   663,   664,   144,   145,   146,   665,
     636,   147,   669,   671,   148,   149,   673,   674,   283,   675,
     676,   677,   678,   679,   301,   150,   302,   303,   680,   681,
     682,   151,   152,   683,   153,   154,   155,   156,   157,   684,
     284,   689,   285,   685,   286,   287,  1438,   687,   535,   158,
     789,   688,   434,   690,   790,   691,   692,   693,   159,   695,
     160,   161,   696,   162,   288,   697,   163,   164,   698,   304,
     165,   305,   699,   700,   701,   791,   703,   707,   702,  1439,
     704,   166,   709,   637,   306,   720,   710,   792,   243,   711,
    1440,   716,   727,   767,   717,   768,   723,   729,   793,   724,
     167,   730,   168,   794,   725,   736,   169,  1441,   726,   732,
     170,   171,   172,   173,  1442,   795,   733,   174,   175,  1443,
     737,  1444,   796,   738,   739,   176,   307,   797,   740,   798,
     742,   743,   760,   744,  1445,  1353,  1354,   769,   770,   745,
     771,   772,   799,   244,   245,   246,   247,   248,   249,   250,
     251,   746,   747,   308,   309,    76,   177,   773,   178,   774,
     782,   783,   748,   784,   179,  1355,   443,    77,  1446,   180,
     749,   800,   786,   750,   181,   751,   801,   752,   787,   755,
     757,   762,   842,  1356,  1447,   444,   785,   763,    78,    79,
    1357,   445,   252,   764,   843,    80,   837,   788,   802,   836,
     845,   838,  1448,   839,  1449,  1450,   844,   590,   846,  1358,
     803,   847,   804,   805,   446,   447,   849,   806,   850,   448,
     851,  1294,   852,   853,   854,   855,   856,   253,   857,   591,
     592,   858,   859,   449,   860,   861,   593,   862,  1359,   863,
     450,  1047,  1052,   865,     2,     3,  1360,   868,   869,     4,
     873,    81,    82,   874,   875,   901,   876,   877,   937,   451,
    1054,    83,    84,   878,   879,   887,     5,  1451,   888,   902,
       6,   889,   938,     7,   890,   807,   891,   892,   893,   941,
       8,   808,    85,    86,  1452,   894,  1361,   895,   452,   896,
     897,   898,   809,   810,  1453,     9,   453,   903,  1295,    87,
      88,   904,   811,   254,   899,  1362,   900,   916,    10,    11,
      89,    12,   905,   906,   454,   594,   595,   596,    13,    90,
     597,   907,   942,   455,   456,   908,  1249,  1049,   598,  1296,
    1050,   909,   939,   910,   911,    14,   255,   912,   940,   913,
     917,   599,   600,  1297,   918,   919,    15,   920,    16,   921,
     922,   923,   924,   925,   457,   458,   927,  1053,   601,   602,
     928,   929,  1298,  1299,   930,    17,   931,   932,  1300,  1301,
    1302,  1303,   933,   934,   944,   943,   945,   946,   947,   948,
    1062,  1304,    18,   603,  1045,   949,   950,   951,   952,   953,
     954,   955,   956,   957,   958,   959,   960,   961,   962,   963,
      91,    92,    93,   964,   965,   966,   967,   968,   969,   459,
    1055,   970,   971,   972,    19,   973,   974,   975,   976,   977,
     998,  1057,  1019,    20,    21,  1020,  1021,  1022,    22,    23,
     978,   979,   980,   981,  1023,   982,   983,  1024,   984,   985,
     986,  1025,  1026,   987,  1027,  1028,  1029,  1030,  1031,  1032,
    1033,  1039,  1040,   988,   989,   990,   991,   992,   993,  1041,
    1042,   994,  1058,  1043,   995,   999,  1000,  1001,  1002,  1044,
    1003,  1004,  1051,  1005,  1006,  1007,  1048,  1056,  1008,  1059,
    1060,  1061,  1063,  1064,  1065,  1066,  1067,  1068,  1009,  1010,
    1011,  1012,  1013,  1014,  1069,  1070,  1015,  1071,  1072,  1016,
    1391,  1392,  1393,  1394,  1073,  1395,  1396,  1074,  1397,  1398,
    1399,  1075,  1076,  1400,  1079,  1080,  1081,  1082,  1083,  1125,
    1084,  1085,  1086,  1401,  1402,  1403,  1404,  1405,  1406,  1087,
    1088,  1407,  1089,  1090,  1408,  1091,  1092,  1093,  1094,  1095,
    1126,  1127,  1147,  1096,  1097,  1098,  1149,  1099,  1100,  1151,
    1159,  1160,  1101,  1102,  1103,  1104,  1106,  1162,  1107,  1108,
    1109,  1110,  1111,  1112,  1113,  1114,  1115,  1116,  1117,  1118,
    1120,  1121,  1122,  1128,  1129,  1130,  1131,  1132,  1133,  1134,
    1135,  1136,  1137,  1138,  1163,  1164,  1139,  1165,  1140,  1141,
    1142,  1143,  1144,  1145,  1146,  1166,  1167,  1150,  1168,  1148,
    1153,  1172,  1152,  1173,  1176,  1177,  1179,  1180,  1178,  1181,
    1182,  1184,  1183,  1185,  1186,  1187,  1188,  1189,  1192,  1190,
    1223,  1191,  1193,  1194,  1195,  1196,  1211,  1197,  1212,  1217,
    1218,  1219,  1220,  1221,  1222,  1239,  1227,  1228,  1229,  1230,
    1231,  1252,  1253,  1330,  1232,  1233,  1234,  1262,  1235,  1236,
    1264,  1237,  1238,  1242,  1247,  1248,  1254,  1268,  1272,  1256,
    1270,  1274,  1275,  1255,  1257,  1258,  1259,  1260,  1261,  1263,
    1368,  1265,  1266,  1267,  1269,  1271,  1273,  1276,  1277,  1278,
    1374,  1292,  1293,  1307,  1308,  1309,  1310,  1311,  1312,  1313,
    1314,  1315,  1316,  1317,  1318,  1319,   330,  1320,  1321,  1322,
    1323,  1324,  1463,  1325,  1462,  1326,  1369,  1124,  1461,  1434,
     915,   754,   550,  1327,   766,  1432,  1431,  1457,  1458,  1460,
     841,   872,   936,   867,  1459,  1433,   759,   361,  1428,   427,
     668,  1345,  1430,  1429,  1344,   349,     0,     0,  1328,     0,
    1329,  1334,  1335,     0,     0,  1336,  1337,  1338,     0,  1339,
    1340,   735,  1341,  1370,  1371,  1372,  1373,  1378,   661,     0,
    1379,  1380,  1381,  1382,  1383,  1384,  1385,     0,  1386,  1387,
    1388,  1389,  1390,  1411,  1412,  1413,     0,   512,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   517,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   536
};

static const short int yycheck[] =
{
     335,   336,   420,     1,     1,     1,     1,   342,    11,     1,
     258,     1,     1,    77,     4,     1,     1,     1,   256,   258,
      11,     1,   260,     1,   258,     1,   256,   256,     1,     1,
     260,   260,     8,     9,     1,   258,    12,   372,   133,   374,
       1,   258,    22,    19,   880,   881,   882,   883,   884,     1,
     256,   258,    28,   388,   260,    45,    32,    33,    48,     1,
     258,   396,    54,    39,    37,   256,    42,    43,    44,   260,
      46,   258,   407,   408,    47,   410,    52,   172,   173,   174,
     175,   176,   155,   418,   419,    10,   421,    12,   155,     1,
     256,   257,    84,    90,    90,    71,    72,   258,    90,     1,
      76,     3,    27,   258,     6,    90,    31,    83,    10,   258,
      22,    87,    88,    89,   104,   258,    92,   256,    90,    95,
      96,   260,   256,    25,    26,    27,   260,   122,   258,    31,
     106,   256,   122,   122,   120,   260,   112,   113,   122,   115,
     116,   117,   118,   119,   122,   258,   126,    49,   155,   122,
     258,    53,    54,   120,   130,   258,     1,   195,   196,   157,
       5,   157,   154,   139,   150,   141,   142,   231,   144,   258,
     122,   147,   148,   157,    99,   151,   256,   157,   259,   157,
     122,    26,    84,   150,    86,   157,   162,   259,   186,   259,
       1,   186,   258,    38,   197,   258,   157,   186,   100,   534,
     259,     1,   186,   259,    49,   181,   197,   183,   186,    54,
     259,   187,    23,    24,   126,   191,   192,   193,   194,    30,
     122,    66,   198,   199,     1,   186,   259,   256,    73,   259,
     206,   260,   259,    78,   186,    80,    13,    37,   256,  1034,
    1035,  1036,   260,     1,   186,   157,   244,    47,    93,   244,
     259,   256,   154,     1,   244,   260,   256,    34,    35,   257,
     257,   237,    20,   239,    41,   257,   168,   257,    26,   245,
     258,   257,   259,   257,   250,   155,   178,   122,   259,   255,
     259,   257,   127,   244,   257,   257,   256,   195,   196,    37,
     260,    49,    50,   256,   213,   214,    54,   260,   109,   110,
     111,     1,   244,   114,   149,   257,    14,    15,    16,   259,
      68,   122,   259,   238,     1,   257,   161,    75,   163,   164,
      97,    98,   122,   168,   135,   136,   259,   259,   256,   259,
     107,   108,   260,   259,   256,   259,    94,    85,   259,   259,
     133,   152,   153,   259,   259,   257,   259,   195,   259,   251,
     259,   128,   129,   259,   259,   257,    56,    57,    58,    59,
      60,    61,    62,    63,   259,   123,   177,    54,   145,   146,
     259,   259,     1,   131,   122,   259,   124,   125,   259,   156,
     259,   226,   259,   259,   259,   259,   259,   232,   165,     1,
     259,   149,     4,   259,   729,   259,   259,    84,   243,   244,
     158,   159,   259,    90,   259,   105,   259,   259,   253,   259,
     259,    40,   257,     1,    93,     3,   259,   259,     6,   167,
     259,   169,    10,   259,   259,   133,    55,   259,   259,   259,
     259,   189,   190,    45,   182,   259,    48,    25,    26,    27,
     140,   259,   259,    31,   259,   259,   257,   259,    77,   259,
      79,   259,    81,    82,   217,   218,   219,   220,   221,   222,
     223,    49,   259,   259,   259,    53,    54,   154,   259,   246,
     247,   248,   101,   259,   259,   259,   224,   259,   259,   259,
     257,   259,   155,     1,   259,   259,   244,   259,   259,   259,
     259,   170,   104,   259,   259,   913,    84,   259,    86,   257,
       1,   256,   259,   251,   252,   259,   259,     8,     9,   257,
     122,    12,   100,   259,   259,   259,   216,   259,    19,    37,
     259,   259,   201,   259,   259,   259,   259,    28,   259,   259,
     259,    32,    33,   259,   122,   259,   215,   259,    39,   155,
     256,    42,    43,    44,     1,    46,   133,   195,   133,   249,
     133,    52,   133,   195,   195,   234,   235,   257,   133,   195,
     195,   240,   241,   242,   243,   195,   154,    85,   903,   195,
      71,    72,   195,   256,   253,    76,   911,   912,   259,   259,
     168,   155,    83,    40,   256,   259,    87,    88,    89,   259,
     178,    92,   195,   195,    95,    96,   133,   155,    55,   133,
     195,   195,   195,   133,   122,   106,   124,   125,   155,   195,
     133,   112,   113,   133,   115,   116,   117,   118,   119,   133,
      77,   133,    79,   195,    81,    82,     5,   195,   257,   130,
       1,   195,   244,   155,     5,   195,   133,   133,   139,   133,
     141,   142,   133,   144,   101,   155,   147,   148,   133,   167,
     151,   169,   133,   195,   195,    26,   195,   195,   259,    38,
     259,   162,   155,   251,   182,   133,   195,    38,     1,   195,
      49,   195,   256,   155,   195,   155,   195,   259,    49,   195,
     181,   259,   183,    54,   195,   256,   187,    66,   195,   259,
     191,   192,   193,   194,    73,    66,   259,   198,   199,    78,
     259,    80,    73,   259,   259,   206,   224,    78,   259,    80,
     259,   259,   256,   259,    93,    20,    21,   155,   155,   259,
     155,   155,    93,    56,    57,    58,    59,    60,    61,    62,
      63,   259,   259,   251,   252,     1,   237,   155,   239,   155,
     155,   155,   259,   195,   245,    50,     1,    13,   127,   250,
     259,   122,   155,   259,   255,   259,   127,   259,   155,   259,
     259,   259,   195,    68,   143,    20,   256,   259,    34,    35,
      75,    26,   105,   259,   195,    41,   259,   256,   149,   256,
     155,   259,   161,   259,   163,   164,   195,     1,   195,    94,
     161,   195,   163,   164,    49,    50,   256,   168,   155,    54,
     195,    93,   155,   155,   155,   155,   155,   140,   155,    23,
      24,   133,   155,    68,   155,   256,    30,   256,   123,   259,
      75,   195,   195,   259,     0,     1,   131,   256,   259,     5,
     256,    97,    98,   256,   256,   259,   256,   256,   155,    94,
     195,   107,   108,   256,   256,   256,    22,   226,   256,   259,
      26,   256,   155,    29,   256,   226,   256,   256,   256,   155,
      36,   232,   128,   129,   243,   256,   171,   256,   123,   256,
     256,   256,   243,   244,   253,    51,   131,   259,   170,   145,
     146,   259,   253,   216,   256,   190,   256,   256,    64,    65,
     156,    67,   259,   259,   149,   109,   110,   111,    74,   165,
     114,   259,   155,   158,   159,   259,   200,   155,   122,   201,
     155,   259,   256,   259,   259,    91,   249,   259,   256,   259,
     259,   135,   136,   215,   259,   259,   102,   259,   104,   259,
     259,   259,   259,   259,   189,   190,   259,   155,   152,   153,
     259,   259,   234,   235,   259,   121,   259,   259,   240,   241,
     242,   243,   259,   259,   256,   259,   256,   256,   256,   256,
     155,   253,   138,   177,   259,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     246,   247,   248,   256,   256,   256,   256,   256,   256,   244,
     195,   256,   256,   256,   170,   256,   256,   256,   256,   256,
     256,   195,   256,   179,   180,   256,   256,   256,   184,   185,
     202,   203,   204,   205,   256,   207,   208,   256,   210,   211,
     212,   256,   256,   215,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   225,   226,   227,   228,   229,   230,   256,
     256,   233,   195,   256,   236,   202,   203,   204,   205,   256,
     207,   208,   256,   210,   211,   212,   259,   259,   215,   195,
     195,   195,   133,   155,   155,   195,   155,   256,   225,   226,
     227,   228,   229,   230,   155,   259,   233,   155,   256,   236,
     202,   203,   204,   205,   259,   207,   208,   155,   210,   211,
     212,   155,   133,   215,   256,   256,   256,   256,   256,   155,
     256,   256,   256,   225,   226,   227,   228,   229,   230,   256,
     256,   233,   256,   256,   236,   256,   256,   256,   256,   256,
     155,   155,   155,   256,   256,   256,   155,   256,   256,   155,
     133,   133,   259,   259,   259,   259,   259,   133,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   133,   133,   256,   133,   256,   256,
     256,   256,   256,   256,   256,   155,   133,   256,   133,   259,
     256,   256,   259,   155,   195,   155,   195,   195,   155,   195,
     155,   155,   259,   155,   155,   155,   133,   155,   256,   155,
     132,   155,   256,   256,   256,   256,   256,   160,   256,   256,
     256,   256,   256,   256,   256,   160,   256,   256,   256,   256,
     256,   195,   155,   132,   256,   256,   256,   155,   256,   256,
     155,   256,   256,   256,   256,   256,   195,   155,   155,   259,
     259,   256,   256,   195,   195,   195,   195,   195,   195,   195,
     133,   195,   195,   195,   195,   195,   195,   256,   256,   256,
     132,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,    71,   256,   256,   256,
     256,   256,  1456,   256,  1437,   256,  1251,   812,  1435,  1367,
     604,   460,   310,   256,   493,  1352,  1350,  1415,  1417,  1420,
     523,   563,   638,   555,  1418,  1365,   483,   122,  1343,   182,
     367,  1203,  1349,  1347,  1201,    94,    -1,    -1,   256,    -1,
     256,   256,   256,    -1,    -1,   256,   256,   256,    -1,   256,
     256,   435,   256,   256,   256,   256,   256,   256,   355,    -1,
     256,   256,   256,   256,   256,   256,   256,    -1,   256,   256,
     256,   256,   256,   256,   256,   256,    -1,   256,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   273,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   289
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short int yystos[] =
{
       0,   262,     0,     1,     5,    22,    26,    29,    36,    51,
      64,    65,    67,    74,    91,   102,   104,   121,   138,   170,
     179,   180,   184,   185,   263,   268,   273,   287,   293,   308,
     345,   364,   377,   403,   410,   420,   429,   459,   469,   475,
     479,   489,   553,   569,   589,   256,   257,   258,   258,   346,
     430,   470,   258,   480,   258,   554,   378,   460,   365,   258,
     258,   309,   404,   258,   258,   411,   421,     1,    37,    47,
     122,   288,   289,   290,   291,   292,     1,    13,    34,    35,
      41,    97,    98,   107,   108,   128,   129,   145,   146,   156,
     165,   246,   247,   248,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   155,   347,   351,   155,   431,   435,   258,
       1,    90,   476,   477,   478,   258,     1,     8,     9,    12,
      19,    28,    32,    33,    39,    42,    43,    44,    46,    52,
      71,    72,    76,    83,    87,    88,    89,    92,    95,    96,
     106,   112,   113,   115,   116,   117,   118,   119,   130,   139,
     141,   142,   144,   147,   148,   151,   162,   181,   183,   187,
     191,   192,   193,   194,   198,   199,   206,   237,   239,   245,
     250,   255,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   544,   548,   549,   550,   551,   552,   258,
     258,   258,   258,     1,    56,    57,    58,    59,    60,    61,
      62,    63,   105,   140,   216,   249,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
       1,   120,   150,   269,   270,   271,   272,   155,   310,   314,
     258,     1,    40,    55,    77,    79,    81,    82,   101,   590,
     591,   592,   593,   594,   595,   596,   597,   598,     1,    37,
      85,   122,   124,   125,   167,   169,   182,   224,   251,   252,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   258,   258,   256,   259,   259,   259,   257,
     289,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   257,   571,
     258,   258,     1,    90,   157,   471,   472,   473,   474,   259,
     257,   477,     1,   122,   157,   186,   481,   485,   486,   487,
     488,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   545,   259,   541,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   257,   491,     1,     4,
      45,    48,   104,   122,   244,   555,   556,   557,   558,   559,
     563,   564,   565,     1,    20,    26,    49,    50,    54,    68,
      75,    94,   123,   131,   149,   158,   159,   189,   190,   244,
     379,   380,   381,   382,   383,   384,   385,   386,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,     1,   157,
     186,   244,   461,   465,   466,   467,   468,     1,    54,    84,
      90,   154,   366,   370,   371,   372,   375,   376,   256,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   257,   295,   256,   259,   259,   257,   270,   258,     1,
      22,   126,   157,   405,   406,   407,   408,   409,   259,   259,
     259,   259,   259,   259,   259,   257,   591,   256,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   257,
     275,     1,   122,   186,   244,   412,   413,   414,   415,   416,
       1,   122,   186,   422,   423,   424,   425,   155,   155,   155,
     256,   195,   133,   133,   195,   133,   265,   265,   133,   133,
     195,   195,   133,   265,   195,   195,   195,   195,   195,   256,
       1,    23,    24,    30,   109,   110,   111,   114,   122,   135,
     136,   152,   153,   177,   348,   349,   350,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,     1,
       3,     6,    10,    25,    26,    27,    31,    49,    53,    54,
      84,    86,   100,   122,   154,   168,   178,   251,   432,   433,
     434,   436,   437,   438,   439,   440,   441,   442,   443,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   259,   259,
     257,   472,   155,   256,   259,   259,   482,   257,   486,   195,
     265,   195,   265,   133,   155,   133,   195,   195,   195,   133,
     155,   195,   133,   133,   133,   195,   265,   195,   195,   133,
     155,   195,   133,   133,   265,   133,   133,   155,   133,   133,
     195,   195,   259,   195,   259,   265,   265,   195,   265,   155,
     195,   195,   195,   196,   195,   196,   195,   195,   265,   265,
     133,   267,   265,   195,   195,   195,   195,   256,   566,   259,
     259,   560,   259,   259,   257,   556,   256,   259,   259,   259,
     259,   387,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   257,   380,   259,   462,   259,   257,   466,
     256,   367,   259,   259,   259,   257,   371,   155,   155,   155,
     155,   155,   155,   155,   155,   217,   218,   219,   220,   221,
     222,   223,   155,   155,   195,   256,   155,   155,   256,     1,
       5,    26,    38,    49,    54,    66,    73,    78,    80,    93,
     122,   127,   149,   161,   163,   164,   168,   226,   232,   243,
     244,   253,   311,   312,   313,   315,   316,   317,   318,   319,
     320,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   256,   259,   259,   259,
     257,   406,   195,   195,   195,   155,   195,   195,   265,   256,
     155,   195,   155,   155,   155,   155,   155,   155,   133,   155,
     155,   256,   256,   259,   417,   259,   257,   413,   256,   259,
     426,   257,   423,   256,   256,   256,   256,   256,   256,   256,
     172,   173,   174,   175,   176,   264,   265,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   257,   349,   256,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   444,   259,   259,   259,
     259,   259,   259,   259,   259,   257,   433,   155,   155,   256,
     256,   155,   155,   259,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   202,   203,
     204,   205,   207,   208,   210,   211,   212,   215,   225,   226,
     227,   228,   229,   230,   233,   236,   546,   547,   256,   202,
     203,   204,   205,   207,   208,   210,   211,   212,   215,   225,
     226,   227,   228,   229,   230,   233,   236,   542,   543,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,    14,    15,    16,   266,   267,   256,
     256,   256,   256,   256,   256,   259,   265,   195,   259,   155,
     155,   256,   195,   155,   195,   195,   259,   195,   195,   195,
     195,   195,   155,   133,   155,   155,   195,   155,   256,   155,
     259,   155,   256,   259,   155,   155,   133,   373,   374,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   259,   259,   259,   259,   339,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   321,
     259,   259,   259,   257,   312,   155,   155,   155,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   155,   259,   155,
     256,   155,   259,   256,   264,   264,   264,   264,   264,   133,
     133,   265,   133,   133,   133,   133,   155,   133,   133,   265,
     265,   267,   256,   155,   213,   214,   195,   155,   155,   195,
     195,   195,   155,   259,   155,   155,   155,   155,   133,   155,
     155,   155,   256,   256,   256,   256,   256,   160,   483,   484,
     256,   260,   256,   260,   266,   266,   266,    11,   197,   567,
     568,   256,   256,    11,   197,   561,   562,   256,   256,   256,
     256,   256,   256,   132,   388,   389,   391,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   160,
     463,   464,   256,    77,   231,   368,   369,   256,   256,   200,
     256,   260,   195,   155,   195,   195,   259,   195,   195,   195,
     195,   195,   155,   195,   155,   195,   195,   195,   155,   195,
     259,   195,   155,   195,   256,   256,   256,   256,   256,    93,
     170,   201,   215,   234,   235,   240,   241,   242,   243,   253,
     418,   419,   256,   256,    93,   170,   201,   215,   234,   235,
     240,   241,   242,   243,   253,   427,   428,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     132,   445,   446,   448,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   260,   547,   543,   256,   260,   256,   260,
     390,   256,   260,    20,    21,    50,    68,    75,    94,   123,
     131,   171,   190,   392,   256,   260,   256,   260,   133,   374,
     256,   256,   256,   256,   132,   340,   341,   343,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   202,   203,   204,   205,   207,   208,   210,   211,   212,
     215,   225,   226,   227,   228,   229,   230,   233,   236,   322,
     323,   256,   256,   256,   256,   260,   256,   260,   447,   256,
     260,    10,    12,    27,    31,    99,   238,   449,   484,   568,
     562,   392,   389,   464,   369,   342,   256,   260,     5,    38,
      49,    66,    73,    78,    80,    93,   127,   143,   161,   163,
     164,   226,   243,   253,   344,   256,   260,   419,   428,   449,
     446,   344,   341,   323
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
#line 412 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:
#line 414 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number);
		}
    break;

  case 29:
#line 418 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number);
		}
    break;

  case 30:
#line 422 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number);
		}
    break;

  case 31:
#line 426 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number);
		}
    break;

  case 32:
#line 430 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number);
		}
    break;

  case 33:
#line 434 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number);
		}
    break;

  case 34:
#line 439 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 36:
#line 440 "ircd_parser.y"
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
    break;

  case 37:
#line 441 "ircd_parser.y"
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
    break;

  case 38:
#line 442 "ircd_parser.y"
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
    break;

  case 39:
#line 443 "ircd_parser.y"
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
    break;

  case 46:
#line 457 "ircd_parser.y"
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
#line 474 "ircd_parser.y"
    {
#ifndef STATIC_MODULES
  if (ypass == 2)
    mod_add_path(yylval.string);
#endif
}
    break;

  case 63:
#line 498 "ircd_parser.y"
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
#line 532 "ircd_parser.y"
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
#line 592 "ircd_parser.y"
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
#line 606 "ircd_parser.y"
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
#line 624 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
}
    break;

  case 68:
#line 633 "ircd_parser.y"
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
#line 647 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
}
    break;

  case 70:
#line 656 "ircd_parser.y"
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
#line 684 "ircd_parser.y"
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
#line 714 "ircd_parser.y"
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
#line 737 "ircd_parser.y"
    {
  if (ypass == 2 && ServerInfo.hub != yylval.number)
  {
    if ((ServerInfo.hub = yylval.number))
    {
      /* Don't become a hub if we have an LL uplink. */
      if (uplink != NULL)
      {
        ServerInfo.hub = NO;
        sendto_realops_flags(UMODE_ALL, L_ALL,
                             "Ignoring config file line hub=yes; "
                             "due to active LazyLink (%s)", uplink->name);
      }
    }
    else
    {
      dlink_node *ptr = NULL;

      /* Don't become a leaf if we have a lazylink active. */
      DLINK_FOREACH(ptr, serv_list.head)
      {
        struct Client *acptr = ptr->data;

        if (MyConnect(acptr) && IsCapable(acptr, CAP_LL))
        {
          ServerInfo.hub = YES;
          sendto_realops_flags(UMODE_ALL, L_ALL,
                               "Ignoring config file line hub=no; "
                               "due to active LazyLink (%s)",
                               acptr->name);
          break;
        }
      }
    }
  }
}
    break;

  case 81:
#line 784 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
}
    break;

  case 82:
#line 793 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
}
    break;

  case 83:
#line 802 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
}
    break;

  case 100:
#line 829 "ircd_parser.y"
    {
                        }
    break;

  case 101:
#line 833 "ircd_parser.y"
    {
                        }
    break;

  case 102:
#line 837 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.userlog, yylval.string,
            sizeof(ConfigLoggingEntry.userlog));
}
    break;

  case 103:
#line 844 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.failed_operlog, yylval.string,
            sizeof(ConfigLoggingEntry.failed_operlog));
}
    break;

  case 104:
#line 851 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.operlog, yylval.string,
            sizeof(ConfigLoggingEntry.operlog));
}
    break;

  case 105:
#line 858 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.operspylog, yylval.string,
            sizeof(ConfigLoggingEntry.operspylog));
}
    break;

  case 106:
#line 865 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.glinelog, yylval.string,
            sizeof(ConfigLoggingEntry.glinelog));
}
    break;

  case 107:
#line 872 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.klinelog, yylval.string,
            sizeof(ConfigLoggingEntry.klinelog));
}
    break;

  case 108:
#line 879 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.ioerrlog, yylval.string,
            sizeof(ConfigLoggingEntry.ioerrlog));
}
    break;

  case 109:
#line 886 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.killlog, yylval.string,
            sizeof(ConfigLoggingEntry.killlog));
}
    break;

  case 110:
#line 893 "ircd_parser.y"
    { 
  if (ypass == 2)
    set_log_level(L_CRIT);
}
    break;

  case 111:
#line 897 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_ERROR);
}
    break;

  case 112:
#line 901 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_WARN);
}
    break;

  case 113:
#line 905 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_NOTICE);
}
    break;

  case 114:
#line 909 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_TRACE);
}
    break;

  case 115:
#line 913 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_INFO);
}
    break;

  case 116:
#line 917 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_DEBUG);
}
    break;

  case 117:
#line 923 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 118:
#line 932 "ircd_parser.y"
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
#line 945 "ircd_parser.y"
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
#line 1037 "ircd_parser.y"
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
#line 1049 "ircd_parser.y"
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
#line 1061 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp;

    if (yy_aconf->user == NULL)
    {
      split_nuh(yylval.string, NULL, &yy_aconf->user, &yy_aconf->host);
    }
    else
    {
      yy_tmp = (struct CollectItem *)MyMalloc(sizeof(struct CollectItem));
      split_nuh(yylval.string, NULL, &yy_tmp->user, &yy_tmp->host);
      dlinkAdd(yy_tmp, &yy_tmp->node, &col_conf_list);
    }
  }
}
    break;

  case 150:
#line 1080 "ircd_parser.y"
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
#line 1092 "ircd_parser.y"
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
#line 1103 "ircd_parser.y"
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
#line 1145 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 154:
#line 1154 "ircd_parser.y"
    {
  yy_aconf->modes = 0;
}
    break;

  case 158:
#line 1160 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 159:
#line 1163 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 160:
#line 1166 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 161:
#line 1169 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 162:
#line 1172 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 163:
#line 1175 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 164:
#line 1178 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 165:
#line 1181 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 166:
#line 1184 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 167:
#line 1187 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 168:
#line 1190 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 169:
#line 1193 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 170:
#line 1196 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 171:
#line 1199 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 172:
#line 1202 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 173:
#line 1205 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 174:
#line 1208 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 175:
#line 1211 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 176:
#line 1216 "ircd_parser.y"
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
#line 1227 "ircd_parser.y"
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
#line 1238 "ircd_parser.y"
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
#line 1249 "ircd_parser.y"
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
#line 1260 "ircd_parser.y"
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
#line 1271 "ircd_parser.y"
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
#line 1282 "ircd_parser.y"
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
#line 1293 "ircd_parser.y"
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
#line 1304 "ircd_parser.y"
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
#line 1315 "ircd_parser.y"
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
#line 1326 "ircd_parser.y"
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
#line 1337 "ircd_parser.y"
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
#line 1348 "ircd_parser.y"
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
#line 1359 "ircd_parser.y"
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
#line 1370 "ircd_parser.y"
    {
}
    break;

  case 194:
#line 1374 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 196:
#line 1375 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 198:
#line 1378 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)yy_aconf->port &= ~OPER_FLAG_GLOBAL_KILL;
    else yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
  }
}
    break;

  case 199:
#line 1385 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTE;
    else yy_aconf->port |= OPER_FLAG_REMOTE;
  }
}
    break;

  case 200:
#line 1392 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_K;
    else yy_aconf->port |= OPER_FLAG_K;
  }
}
    break;

  case 201:
#line 1399 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_UNKLINE;
    else yy_aconf->port |= OPER_FLAG_UNKLINE;
  } 
}
    break;

  case 202:
#line 1406 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_X;
    else yy_aconf->port |= OPER_FLAG_X;
  }
}
    break;

  case 203:
#line 1413 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_GLINE;
    else yy_aconf->port |= OPER_FLAG_GLINE;
  }
}
    break;

  case 204:
#line 1420 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_DIE;
    else yy_aconf->port |= OPER_FLAG_DIE;
  }
}
    break;

  case 205:
#line 1427 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REHASH;
    else yy_aconf->port |= OPER_FLAG_REHASH;
  }
}
    break;

  case 206:
#line 1434 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_ADMIN;
    else yy_aconf->port |= OPER_FLAG_ADMIN;
  }
}
    break;

  case 207:
#line 1441 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_ADMIN;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_ADMIN;
  }
}
    break;

  case 208:
#line 1448 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_N;
    else yy_aconf->port |= OPER_FLAG_N;
  }
}
    break;

  case 209:
#line 1455 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPERWALL;
    else yy_aconf->port |= OPER_FLAG_OPERWALL;
  }
}
    break;

  case 210:
#line 1462 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPER_SPY;
    else yy_aconf->port |= OPER_FLAG_OPER_SPY;
  }
}
    break;

  case 211:
#line 1469 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_OPER;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_OPER;
  }
}
    break;

  case 212:
#line 1476 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTEBAN;
    else yy_aconf->port |= OPER_FLAG_REMOTEBAN;
  }
}
    break;

  case 213:
#line 1483 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) ClearConfEncrypted(yy_aconf);
    else SetConfEncrypted(yy_aconf);
  }
}
    break;

  case 214:
#line 1496 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = &yy_conf->conf.ClassItem;
  }
}
    break;

  case 215:
#line 1503 "ircd_parser.y"
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
#line 1555 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 235:
#line 1564 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 236:
#line 1573 "ircd_parser.y"
    {
  if (ypass == 1)
    PingFreq(yy_class) = (yyvsp[-1].number);
}
    break;

  case 237:
#line 1579 "ircd_parser.y"
    {
  if (ypass == 1)
    PingWarning(yy_class) = (yyvsp[-1].number);
}
    break;

  case 238:
#line 1585 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxPerIp(yy_class) = (yyvsp[-1].number);
}
    break;

  case 239:
#line 1591 "ircd_parser.y"
    {
  if (ypass == 1)
    ConFreq(yy_class) = (yyvsp[-1].number);
}
    break;

  case 240:
#line 1597 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxTotal(yy_class) = (yyvsp[-1].number);
}
    break;

  case 241:
#line 1603 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxGlobal(yy_class) = (yyvsp[-1].number);
}
    break;

  case 242:
#line 1609 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxLocal(yy_class) = (yyvsp[-1].number);
}
    break;

  case 243:
#line 1615 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxIdent(yy_class) = (yyvsp[-1].number);
}
    break;

  case 244:
#line 1621 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxSendq(yy_class) = (yyvsp[-1].number);
}
    break;

  case 245:
#line 1627 "ircd_parser.y"
    {
  if (ypass == 1)
    CidrBitlenIPV4(yy_class) = (yyvsp[-1].number);
}
    break;

  case 246:
#line 1633 "ircd_parser.y"
    {
  if (ypass == 1)
    CidrBitlenIPV6(yy_class) = (yyvsp[-1].number);
}
    break;

  case 247:
#line 1639 "ircd_parser.y"
    {
  if (ypass == 1)
    NumberPerCidr(yy_class) = (yyvsp[-1].number);
}
    break;

  case 248:
#line 1648 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 249:
#line 1655 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 250:
#line 1664 "ircd_parser.y"
    {
}
    break;

  case 254:
#line 1669 "ircd_parser.y"
    {
  if (ypass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 255:
#line 1673 "ircd_parser.y"
    {
  if (ypass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 266:
#line 1686 "ircd_parser.y"
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
#line 1701 "ircd_parser.y"
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
#line 1723 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 269:
#line 1732 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 270:
#line 1744 "ircd_parser.y"
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
#line 1756 "ircd_parser.y"
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
#line 1821 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp;

    if (yy_aconf->user == NULL)
      split_nuh(yylval.string, NULL, &yy_aconf->user, &yy_aconf->host);
    else
    {
      yy_tmp = MyMalloc(sizeof(struct CollectItem));
      split_nuh(yylval.string, NULL, &yy_tmp->user, &yy_tmp->host);
      dlinkAdd(yy_tmp, &yy_tmp->node, &col_conf_list);
    }
  }
}
    break;

  case 292:
#line 1840 "ircd_parser.y"
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
#line 1853 "ircd_parser.y"
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
#line 1864 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 295:
#line 1873 "ircd_parser.y"
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
#line 1884 "ircd_parser.y"
    {
}
    break;

  case 300:
#line 1888 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 302:
#line 1889 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 304:
#line 1892 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_SPOOF_NOTICE;
    else yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
  }

}
    break;

  case 305:
#line 1900 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NOLIMIT;
    else yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
  }
}
    break;

  case 306:
#line 1907 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTKLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
  } 
}
    break;

  case 307:
#line 1914 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_IDENTD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
  }
}
    break;

  case 308:
#line 1921 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_CAN_FLOOD;
    else yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
  }
}
    break;

  case 309:
#line 1928 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_IDLE_LINED;
    else yy_aconf->flags |= CONF_FLAGS_IDLE_LINED;
  }
}
    break;

  case 310:
#line 1935 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NO_TILDE;
    else yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
  } 
}
    break;

  case 311:
#line 1942 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTGLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
  } 
}
    break;

  case 312:
#line 1949 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTRESV;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
  }
}
    break;

  case 313:
#line 1956 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_PASSWORD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
  }
}
    break;

  case 314:
#line 1965 "ircd_parser.y"
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
#line 1976 "ircd_parser.y"
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
#line 1987 "ircd_parser.y"
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
#line 1998 "ircd_parser.y"
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
#line 2009 "ircd_parser.y"
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
#line 2020 "ircd_parser.y"
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
#line 2032 "ircd_parser.y"
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
#line 2051 "ircd_parser.y"
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
#line 2061 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[-1].number);
  }
}
    break;

  case 323:
#line 2070 "ircd_parser.y"
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
#line 2085 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 325:
#line 2092 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 332:
#line 2104 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 333:
#line 2113 "ircd_parser.y"
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
#line 2128 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 335:
#line 2141 "ircd_parser.y"
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
#line 2149 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 343:
#line 2160 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 344:
#line 2169 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    split_nuh(yylval.string, NULL, &yy_match_item->user, &yy_match_item->host);
  }
}
    break;

  case 345:
#line 2177 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = 0;
}
    break;

  case 349:
#line 2184 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 350:
#line 2188 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TKLINE;
}
    break;

  case 351:
#line 2192 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 352:
#line 2196 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 353:
#line 2200 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TXLINE;
}
    break;

  case 354:
#line 2204 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 355:
#line 2208 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 356:
#line 2212 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TRESV;
}
    break;

  case 357:
#line 2216 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 358:
#line 2220 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 359:
#line 2224 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 360:
#line 2233 "ircd_parser.y"
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
#line 2242 "ircd_parser.y"
    {
  yy_conf = NULL;
  yy_match_item = NULL;
}
    break;

  case 367:
#line 2251 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 368:
#line 2260 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = 0;
}
    break;

  case 372:
#line 2267 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 373:
#line 2271 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TKLINE;
}
    break;

  case 374:
#line 2275 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 375:
#line 2279 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 376:
#line 2283 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TXLINE;
}
    break;

  case 377:
#line 2287 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 378:
#line 2291 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 379:
#line 2295 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TRESV;
}
    break;

  case 380:
#line 2299 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 381:
#line 2303 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 382:
#line 2307 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 383:
#line 2316 "ircd_parser.y"
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
#line 2334 "ircd_parser.y"
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
	  if (conf_add_server(yy_conf, scount, class_name) >= 0)
	  {
	    ++scount;
	  }
	  else
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
#line 2477 "ircd_parser.y"
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
#line 2489 "ircd_parser.y"
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
#line 2501 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 411:
#line 2510 "ircd_parser.y"
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
#line 2536 "ircd_parser.y"
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
#line 2554 "ircd_parser.y"
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
#line 2572 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->port = (yyvsp[-1].number);
}
    break;

  case 415:
#line 2578 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 416:
#line 2582 "ircd_parser.y"
    {
#ifdef IPV6
  if (ypass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 417:
#line 2590 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->fakename);
    DupString(yy_aconf->fakename, yylval.string);
  }
}
    break;

  case 418:
#line 2599 "ircd_parser.y"
    {
}
    break;

  case 422:
#line 2603 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 424:
#line 2604 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 426:
#line 2607 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfLazyLink(yy_aconf);
    else SetConfLazyLink(yy_aconf);
  }
}
    break;

  case 427:
#line 2614 "ircd_parser.y"
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

  case 428:
#line 2625 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfCryptLink(yy_aconf);
    else SetConfCryptLink(yy_aconf);
  }
}
    break;

  case 429:
#line 2632 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfAllowAutoConn(yy_aconf);
    else SetConfAllowAutoConn(yy_aconf);
  }
}
    break;

  case 430:
#line 2639 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfAwayBurst(yy_aconf);
    else SetConfAwayBurst(yy_aconf);
  }
}
    break;

  case 431:
#line 2646 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfTopicBurst(yy_aconf);
    else SetConfTopicBurst(yy_aconf);
  }
}
    break;

  case 432:
#line 2656 "ircd_parser.y"
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

  case 433:
#line 2697 "ircd_parser.y"
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

  case 434:
#line 2708 "ircd_parser.y"
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

  case 435:
#line 2719 "ircd_parser.y"
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

  case 436:
#line 2734 "ircd_parser.y"
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

  case 437:
#line 2745 "ircd_parser.y"
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

  case 438:
#line 2758 "ircd_parser.y"
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

  case 439:
#line 2771 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 440:
#line 2780 "ircd_parser.y"
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

  case 441:
#line 2815 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 442:
#line 2822 "ircd_parser.y"
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

  case 443:
#line 2876 "ircd_parser.y"
    {
}
    break;

  case 447:
#line 2881 "ircd_parser.y"
    {
  if (ypass == 2)
    regex_ban = 1;
}
    break;

  case 454:
#line 2890 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    char *user = NULL, *host = NULL;

    split_nuh(yylval.string, NULL, &user, &host);

    strlcpy(userbuf, user, sizeof(userbuf));
    strlcpy(hostbuf, host, sizeof(hostbuf));

    MyFree(user);
    MyFree(host);
  }
}
    break;

  case 455:
#line 2906 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 456:
#line 2915 "ircd_parser.y"
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

  case 457:
#line 2924 "ircd_parser.y"
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

  case 463:
#line 2940 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 464:
#line 2949 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->reason);
    DupString(yy_aconf->reason, yylval.string);
  }
}
    break;

  case 470:
#line 2966 "ircd_parser.y"
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

  case 471:
#line 2987 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 472:
#line 2994 "ircd_parser.y"
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

  case 473:
#line 3028 "ircd_parser.y"
    {
}
    break;

  case 477:
#line 3033 "ircd_parser.y"
    {
  if (ypass == 2)
    regex_ban = 1;
}
    break;

  case 484:
#line 3042 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 485:
#line 3048 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 545:
#line 3092 "ircd_parser.y"
    {
  ConfigFileEntry.max_watch = yylval.number;
}
    break;

  case 546:
#line 3097 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[-1].number);
}
    break;

  case 547:
#line 3102 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[-1].number);
}
    break;

  case 548:
#line 3107 "ircd_parser.y"
    {
  ConfigFileEntry.burst_away = yylval.number;
}
    break;

  case 549:
#line 3112 "ircd_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 550:
#line 3117 "ircd_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 551:
#line 3122 "ircd_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 552:
#line 3127 "ircd_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[-1].number);
}
    break;

  case 553:
#line 3132 "ircd_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 554:
#line 3137 "ircd_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 555:
#line 3142 "ircd_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 556:
#line 3147 "ircd_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 557:
#line 3152 "ircd_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 558:
#line 3157 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[-1].number); 
}
    break;

  case 559:
#line 3162 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[-1].number);
}
    break;

  case 560:
#line 3167 "ircd_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[-1].number);
}
    break;

  case 561:
#line 3172 "ircd_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[-1].number);
}
    break;

  case 562:
#line 3177 "ircd_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[-1].number);
}
    break;

  case 563:
#line 3182 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[-1].number);
}
    break;

  case 564:
#line 3188 "ircd_parser.y"
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

  case 565:
#line 3199 "ircd_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 566:
#line 3204 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 567:
#line 3213 "ircd_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 568:
#line 3218 "ircd_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 569:
#line 3223 "ircd_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 570:
#line 3228 "ircd_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 571:
#line 3233 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 572:
#line 3236 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 573:
#line 3241 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 574:
#line 3244 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 575:
#line 3249 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[-1].number);
}
    break;

  case 576:
#line 3254 "ircd_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[-1].number);
}
    break;

  case 577:
#line 3259 "ircd_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 578:
#line 3264 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[-1].number);
}
    break;

  case 579:
#line 3269 "ircd_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 580:
#line 3274 "ircd_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 581:
#line 3279 "ircd_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 582:
#line 3284 "ircd_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 583:
#line 3289 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 584:
#line 3300 "ircd_parser.y"
    {
  ConfigFileEntry.idletime = (yyvsp[-1].number);
}
    break;

  case 585:
#line 3305 "ircd_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[-1].number);
}
    break;

  case 586:
#line 3310 "ircd_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[-1].number);
}
    break;

  case 587:
#line 3315 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.servlink_path);
    DupString(ConfigFileEntry.servlink_path, yylval.string);
  }
}
    break;

  case 588:
#line 3324 "ircd_parser.y"
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

  case 589:
#line 3356 "ircd_parser.y"
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

  case 590:
#line 3374 "ircd_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 591:
#line 3379 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 592:
#line 3388 "ircd_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 593:
#line 3393 "ircd_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 594:
#line 3398 "ircd_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 595:
#line 3403 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 599:
#line 3409 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 600:
#line 3412 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 601:
#line 3415 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 602:
#line 3418 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 603:
#line 3421 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 604:
#line 3424 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 605:
#line 3427 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 606:
#line 3430 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 607:
#line 3433 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 608:
#line 3436 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 609:
#line 3439 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 610:
#line 3442 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 611:
#line 3445 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 612:
#line 3448 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 613:
#line 3451 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 614:
#line 3454 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 615:
#line 3457 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 616:
#line 3460 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 617:
#line 3465 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 621:
#line 3471 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 622:
#line 3474 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 623:
#line 3477 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 624:
#line 3480 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 625:
#line 3483 "ircd_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 626:
#line 3486 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 627:
#line 3489 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 628:
#line 3492 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 629:
#line 3495 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 630:
#line 3498 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 631:
#line 3501 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 632:
#line 3504 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 633:
#line 3507 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 634:
#line 3510 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 635:
#line 3513 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 636:
#line 3516 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 637:
#line 3519 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 638:
#line 3522 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 639:
#line 3527 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[-1].number);
}
    break;

  case 640:
#line 3532 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[-1].number);
}
    break;

  case 641:
#line 3537 "ircd_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[-1].number);
}
    break;

  case 642:
#line 3542 "ircd_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[-1].number);
}
    break;

  case 643:
#line 3547 "ircd_parser.y"
    {
  ConfigFileEntry.dot_in_ip6_addr = yylval.number;
}
    break;

  case 644:
#line 3555 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = &yy_conf->conf.AccessItem;
  }
}
    break;

  case 645:
#line 3562 "ircd_parser.y"
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

  case 655:
#line 3588 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 656:
#line 3594 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_time = (yyvsp[-1].number);
}
    break;

  case 657:
#line 3600 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 661:
#line 3606 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 662:
#line 3610 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 663:
#line 3616 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yy_aconf->user == NULL)
    {
      split_nuh(yylval.string, NULL, &yy_aconf->user, &yy_aconf->host);
    }
    else
    {
      struct CollectItem *yy_tmp = MyMalloc(sizeof(struct CollectItem));
      split_nuh(yylval.string, NULL, &yy_tmp->user, &yy_tmp->host);
      dlinkAdd(yy_tmp, &yy_tmp->node, &col_conf_list);
    }
  }
}
    break;

  case 664:
#line 3633 "ircd_parser.y"
    {
  if (ypass == 2)  
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 665:
#line 3642 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 666:
#line 3646 "ircd_parser.y"
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

  case 669:
#line 3693 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 670:
#line 3697 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 692:
#line 3721 "ircd_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 693:
#line 3726 "ircd_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 694:
#line 3731 "ircd_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 695:
#line 3736 "ircd_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 696:
#line 3741 "ircd_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 697:
#line 3746 "ircd_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[-1].number);
}
    break;

  case 698:
#line 3751 "ircd_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
    break;

  case 699:
#line 3756 "ircd_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[-1].number);
}
    break;

  case 700:
#line 3761 "ircd_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 701:
#line 3766 "ircd_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
    break;

  case 702:
#line 3771 "ircd_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[-1].number);
}
    break;

  case 703:
#line 3776 "ircd_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[-1].number);
}
    break;

  case 704:
#line 3781 "ircd_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 705:
#line 3786 "ircd_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 706:
#line 3791 "ircd_parser.y"
    {
  ConfigChannel.burst_topicwho = yylval.number;
}
    break;

  case 707:
#line 3796 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 708:
#line 3801 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 720:
#line 3820 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 721:
#line 3826 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 722:
#line 3832 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 723:
#line 3841 "ircd_parser.y"
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

  case 724:
#line 3855 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 725:
#line 3861 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 726:
#line 3867 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 7403 "y.tab.c"

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



