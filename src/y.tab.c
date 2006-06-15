/* A Bison parser, made from ircd_parser.y, by GNU bison 1.75.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

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
#define YYBISON	1

/* Pure parsers.  */
#define YYPURE	0

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
     DISABLE_FAKE_CHANNELS = 295,
     DISABLE_HIDDEN = 296,
     DISABLE_LOCAL_CHANNELS = 297,
     DISABLE_REMOTE_COMMANDS = 298,
     DOT_IN_IP6_ADDR = 299,
     DOTS_IN_IDENT = 300,
     DURATION = 301,
     EGDPOOL_PATH = 302,
     EMAIL = 303,
     ENABLE = 304,
     ENCRYPTED = 305,
     EXCEED_LIMIT = 306,
     EXEMPT = 307,
     FAILED_OPER_NOTICE = 308,
     FAKENAME = 309,
     IRCD_FLAGS = 310,
     FLATTEN_LINKS = 311,
     FFAILED_OPERLOG = 312,
     FKILLLOG = 313,
     FKLINELOG = 314,
     FGLINELOG = 315,
     FIOERRLOG = 316,
     FOPERLOG = 317,
     FOPERSPYLOG = 318,
     FUSERLOG = 319,
     GECOS = 320,
     GENERAL = 321,
     GLINE = 322,
     GLINES = 323,
     GLINE_EXEMPT = 324,
     GLINE_LOG = 325,
     GLINE_TIME = 326,
     GLINE_MIN_CIDR = 327,
     GLINE_MIN_CIDR6 = 328,
     GLOBAL_KILL = 329,
     IRCD_AUTH = 330,
     NEED_IDENT = 331,
     HAVENT_READ_CONF = 332,
     HIDDEN = 333,
     HIDDEN_ADMIN = 334,
     HIDDEN_NAME = 335,
     HIDDEN_OPER = 336,
     HIDE_SERVER_IPS = 337,
     HIDE_SERVERS = 338,
     HIDE_SPOOF_IPS = 339,
     HOST = 340,
     HUB = 341,
     HUB_MASK = 342,
     IDLETIME = 343,
     IGNORE_BOGUS_TS = 344,
     INVISIBLE_ON_CONNECT = 345,
     IP = 346,
     KILL = 347,
     KILL_CHASE_TIME_LIMIT = 348,
     KLINE = 349,
     KLINE_EXEMPT = 350,
     KLINE_REASON = 351,
     KLINE_WITH_REASON = 352,
     KNOCK_DELAY = 353,
     KNOCK_DELAY_CHANNEL = 354,
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
#define DISABLE_FAKE_CHANNELS 295
#define DISABLE_HIDDEN 296
#define DISABLE_LOCAL_CHANNELS 297
#define DISABLE_REMOTE_COMMANDS 298
#define DOT_IN_IP6_ADDR 299
#define DOTS_IN_IDENT 300
#define DURATION 301
#define EGDPOOL_PATH 302
#define EMAIL 303
#define ENABLE 304
#define ENCRYPTED 305
#define EXCEED_LIMIT 306
#define EXEMPT 307
#define FAILED_OPER_NOTICE 308
#define FAKENAME 309
#define IRCD_FLAGS 310
#define FLATTEN_LINKS 311
#define FFAILED_OPERLOG 312
#define FKILLLOG 313
#define FKLINELOG 314
#define FGLINELOG 315
#define FIOERRLOG 316
#define FOPERLOG 317
#define FOPERSPYLOG 318
#define FUSERLOG 319
#define GECOS 320
#define GENERAL 321
#define GLINE 322
#define GLINES 323
#define GLINE_EXEMPT 324
#define GLINE_LOG 325
#define GLINE_TIME 326
#define GLINE_MIN_CIDR 327
#define GLINE_MIN_CIDR6 328
#define GLOBAL_KILL 329
#define IRCD_AUTH 330
#define NEED_IDENT 331
#define HAVENT_READ_CONF 332
#define HIDDEN 333
#define HIDDEN_ADMIN 334
#define HIDDEN_NAME 335
#define HIDDEN_OPER 336
#define HIDE_SERVER_IPS 337
#define HIDE_SERVERS 338
#define HIDE_SPOOF_IPS 339
#define HOST 340
#define HUB 341
#define HUB_MASK 342
#define IDLETIME 343
#define IGNORE_BOGUS_TS 344
#define INVISIBLE_ON_CONNECT 345
#define IP 346
#define KILL 347
#define KILL_CHASE_TIME_LIMIT 348
#define KLINE 349
#define KLINE_EXEMPT 350
#define KLINE_REASON 351
#define KLINE_WITH_REASON 352
#define KNOCK_DELAY 353
#define KNOCK_DELAY_CHANNEL 354
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

#ifndef YYSTYPE
#line 123 "ircd_parser.y"
typedef union {
  int number;
  char *string;
} yystype;
/* Line 193 of /usr/local/share/bison/yacc.c.  */
#line 686 "y.tab.c"
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif

#ifndef YYLTYPE
typedef struct yyltype
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} yyltype;
# define YYLTYPE yyltype
# define YYLTYPE_IS_TRIVIAL 1
#endif

/* Copy the second part of user declarations.  */


/* Line 213 of /usr/local/share/bison/yacc.c.  */
#line 707 "y.tab.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYLTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAX (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAX)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];	\
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
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAX;	\
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  2
#define YYLAST   1395

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  261
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  339
/* YYNRULES -- Number of rules. */
#define YYNRULES  727
/* YYNRULES -- Number of states. */
#define YYNSTATES  1468

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   510

#define YYTRANSLATE(X) \
  ((unsigned)(X) <= YYMAXUTOK ? yytranslate[X] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned short yytranslate[] =
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
static const unsigned short yyprhs[] =
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
    2101,  2103,  2105,  2110,  2115,  2120,  2125,  2130,  2135,  2140,
    2145,  2150,  2155,  2160,  2165,  2170,  2175,  2180,  2185,  2190,
    2195,  2201,  2204,  2206,  2208,  2210,  2212,  2214,  2216,  2218,
    2220,  2222,  2227,  2232,  2237,  2242,  2247,  2252
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     262,     0,    -1,    -1,   262,   263,    -1,   287,    -1,   293,
      -1,   308,    -1,   569,    -1,   345,    -1,   364,    -1,   377,
      -1,   273,    -1,   590,    -1,   403,    -1,   410,    -1,   420,
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
      -1,    86,   259,   195,   256,    -1,     5,   258,   288,   257,
     256,    -1,   288,   289,    -1,   289,    -1,   290,    -1,   292,
      -1,   291,    -1,     1,   256,    -1,   122,   259,   155,   256,
      -1,    48,   259,   155,   256,    -1,    37,   259,   155,   256,
      -1,   104,   258,   294,   257,   256,    -1,   294,   295,    -1,
     295,    -1,   296,    -1,   297,    -1,   306,    -1,   307,    -1,
     298,    -1,   300,    -1,   302,    -1,   303,    -1,   305,    -1,
     301,    -1,   304,    -1,   299,    -1,     1,   256,    -1,   216,
     259,   155,   256,    -1,   140,   259,   155,   256,    -1,    64,
     259,   155,   256,    -1,    57,   259,   155,   256,    -1,    62,
     259,   155,   256,    -1,    63,   259,   155,   256,    -1,    60,
     259,   155,   256,    -1,    59,   259,   155,   256,    -1,    61,
     259,   155,   256,    -1,    58,   259,   155,   256,    -1,   105,
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
      50,   259,   195,   256,    -1,   168,   259,   155,   256,    -1,
      26,   259,   155,   256,    -1,    -1,   232,   321,   259,   322,
     256,    -1,   322,   260,   323,    -1,   323,    -1,   202,    -1,
     205,    -1,   207,    -1,   208,    -1,   211,    -1,   229,    -1,
     225,    -1,   227,    -1,   233,    -1,   230,    -1,   210,    -1,
     226,    -1,   228,    -1,   212,    -1,   236,    -1,   203,    -1,
     204,    -1,   215,    -1,    74,   259,   195,   256,    -1,   163,
     259,   195,   256,    -1,   164,   259,   195,   256,    -1,    94,
     259,   195,   256,    -1,   253,   259,   195,   256,    -1,   243,
     259,   195,   256,    -1,    67,   259,   195,   256,    -1,   127,
     259,   195,   256,    -1,    38,   259,   195,   256,    -1,   161,
     259,   195,   256,    -1,     5,   259,   195,   256,    -1,    79,
     259,   195,   256,    -1,    81,   259,   195,   256,    -1,   226,
     259,   195,   256,    -1,    -1,    55,   339,   259,   340,   256,
      -1,   340,   260,   341,    -1,   341,    -1,    -1,   132,   342,
     344,    -1,    -1,   343,   344,    -1,    74,    -1,   163,    -1,
      94,    -1,   243,    -1,   253,    -1,    67,    -1,    38,    -1,
     161,    -1,     5,    -1,    79,    -1,   127,    -1,   226,    -1,
     143,    -1,    81,    -1,   164,    -1,    50,    -1,    -1,    26,
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
      55,   367,   259,   368,   256,    -1,   368,   260,   369,    -1,
     369,    -1,   231,    -1,    78,    -1,   370,   371,    -1,   371,
      -1,   372,    -1,   366,    -1,   375,    -1,   376,    -1,     1,
     256,    -1,   154,   259,   373,   256,    -1,   373,   260,   374,
      -1,   374,    -1,   133,    -1,   133,   200,   133,    -1,    91,
     259,   155,   256,    -1,    85,   259,   155,   256,    -1,    -1,
      75,   378,   258,   379,   257,   256,    -1,   379,   380,    -1,
     380,    -1,   381,    -1,   382,    -1,   384,    -1,   386,    -1,
     393,    -1,   394,    -1,   395,    -1,   397,    -1,   398,    -1,
     399,    -1,   383,    -1,   400,    -1,   401,    -1,   396,    -1,
     402,    -1,   385,    -1,     1,   256,    -1,   244,   259,   155,
     256,    -1,   149,   259,   155,   256,    -1,   190,   259,   195,
     256,    -1,    26,   259,   155,   256,    -1,    50,   259,   195,
     256,    -1,    -1,    55,   387,   259,   388,   256,    -1,   388,
     260,   389,    -1,   389,    -1,    -1,   132,   390,   392,    -1,
      -1,   391,   392,    -1,   190,    -1,    51,    -1,    95,    -1,
      76,    -1,    20,    -1,    21,    -1,   131,    -1,    69,    -1,
     171,    -1,   123,    -1,    95,   259,   195,   256,    -1,    76,
     259,   195,   256,    -1,    51,   259,   195,   256,    -1,    20,
     259,   195,   256,    -1,   131,   259,   195,   256,    -1,    69,
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
     418,   260,   419,    -1,   419,    -1,    94,    -1,   240,    -1,
     243,    -1,   253,    -1,   241,    -1,   235,    -1,   170,    -1,
     242,    -1,   234,    -1,   215,    -1,   201,    -1,    -1,   185,
     421,   258,   422,   257,   256,    -1,   422,   423,    -1,   423,
      -1,   424,    -1,   425,    -1,     1,   256,    -1,   122,   259,
     155,   256,    -1,    -1,   186,   426,   259,   427,   256,    -1,
     427,   260,   428,    -1,   428,    -1,    94,    -1,   240,    -1,
     243,    -1,   253,    -1,   241,    -1,   235,    -1,   170,    -1,
     242,    -1,   234,    -1,   215,    -1,   201,    -1,    -1,    29,
     430,   431,   258,   432,   257,   256,    -1,    -1,   435,    -1,
     432,   433,    -1,   433,    -1,   434,    -1,   436,    -1,   437,
      -1,   438,    -1,   439,    -1,   441,    -1,   440,    -1,   442,
      -1,   443,    -1,   455,    -1,   456,    -1,   457,    -1,   454,
      -1,   451,    -1,   453,    -1,   452,    -1,   450,    -1,   458,
      -1,     1,   256,    -1,   122,   259,   155,   256,    -1,   155,
      -1,    85,   259,   155,   256,    -1,   251,   259,   155,   256,
      -1,   178,   259,   155,   256,    -1,     3,   259,   155,   256,
      -1,   154,   259,   133,   256,    -1,     6,   259,   213,   256,
      -1,     6,   259,   214,   256,    -1,    54,   259,   155,   256,
      -1,    -1,    55,   444,   259,   445,   256,    -1,   445,   260,
     446,    -1,   446,    -1,    -1,   132,   447,   449,    -1,    -1,
     448,   449,    -1,    27,    -1,    31,    -1,    10,    -1,    12,
      -1,   238,    -1,   168,   259,   155,   256,    -1,    50,   259,
     195,   256,    -1,    31,   259,   195,   256,    -1,    27,   259,
     195,   256,    -1,    10,   259,   195,   256,    -1,    87,   259,
     155,   256,    -1,   100,   259,   155,   256,    -1,    26,   259,
     155,   256,    -1,    25,   259,   155,   256,    -1,    -1,    92,
     460,   258,   465,   257,   256,    -1,    -1,   186,   462,   259,
     463,   256,    -1,   463,   260,   464,    -1,   464,    -1,   160,
      -1,   465,   466,    -1,   466,    -1,   467,    -1,   468,    -1,
     461,    -1,     1,    -1,   244,   259,   155,   256,    -1,   157,
     259,   155,   256,    -1,    -1,    36,   470,   258,   471,   257,
     256,    -1,   471,   472,    -1,   472,    -1,   473,    -1,   474,
      -1,     1,    -1,    91,   259,   155,   256,    -1,   157,   259,
     155,   256,    -1,    52,   258,   476,   257,   256,    -1,   476,
     477,    -1,   477,    -1,   478,    -1,     1,    -1,    91,   259,
     155,   256,    -1,    -1,    65,   480,   258,   485,   257,   256,
      -1,    -1,   186,   482,   259,   483,   256,    -1,   483,   260,
     484,    -1,   484,    -1,   160,    -1,   485,   486,    -1,   486,
      -1,   487,    -1,   488,    -1,   481,    -1,     1,    -1,   122,
     259,   155,   256,    -1,   157,   259,   155,   256,    -1,    66,
     258,   490,   257,   256,    -1,   490,   491,    -1,   491,    -1,
     500,    -1,   501,    -1,   503,    -1,   504,    -1,   505,    -1,
     506,    -1,   507,    -1,   508,    -1,   509,    -1,   510,    -1,
     499,    -1,   512,    -1,   513,    -1,   514,    -1,   515,    -1,
     530,    -1,   516,    -1,   518,    -1,   520,    -1,   519,    -1,
     523,    -1,   517,    -1,   524,    -1,   525,    -1,   526,    -1,
     527,    -1,   529,    -1,   528,    -1,   544,    -1,   531,    -1,
     535,    -1,   536,    -1,   540,    -1,   521,    -1,   522,    -1,
     550,    -1,   548,    -1,   549,    -1,   532,    -1,   502,    -1,
     533,    -1,   534,    -1,   551,    -1,   539,    -1,   511,    -1,
     552,    -1,   537,    -1,   538,    -1,   495,    -1,   498,    -1,
     493,    -1,   494,    -1,   496,    -1,   497,    -1,   492,    -1,
       1,    -1,   116,   259,   133,   256,    -1,    72,   259,   133,
     256,    -1,    73,   259,   133,   256,    -1,    12,   259,   195,
     256,    -1,   250,   259,   195,   256,    -1,   162,   259,   265,
     256,    -1,   183,   259,   195,   256,    -1,    93,   259,   133,
     256,    -1,    84,   259,   195,   256,    -1,    89,   259,   195,
     256,    -1,    43,   259,   195,   256,    -1,    53,   259,   195,
     256,    -1,     8,   259,   195,   256,    -1,   113,   259,   265,
     256,    -1,   112,   259,   133,   256,    -1,   106,   259,   133,
     256,    -1,     9,   259,   265,   256,    -1,   199,   259,   265,
     256,    -1,   198,   259,   265,   256,    -1,    77,   259,   133,
     256,    -1,    97,   259,   195,   256,    -1,    96,   259,   155,
     256,    -1,    90,   259,   195,   256,    -1,   255,   259,   195,
     256,    -1,   193,   259,   195,   256,    -1,   194,   259,   195,
     256,    -1,   192,   259,   195,   256,    -1,   192,   259,   196,
     256,    -1,   191,   259,   195,   256,    -1,   191,   259,   196,
     256,    -1,   147,   259,   265,   256,    -1,    19,   259,   265,
     256,    -1,   139,   259,   195,   256,    -1,   148,   259,   265,
     256,    -1,   187,   259,   195,   256,    -1,   130,   259,   195,
     256,    -1,   239,   259,   195,   256,    -1,   142,   259,   195,
     256,    -1,   117,   259,   155,   256,    -1,    88,   259,   265,
     256,    -1,    45,   259,   133,   256,    -1,   115,   259,   133,
     256,    -1,   181,   259,   155,   256,    -1,    32,   259,   155,
     256,    -1,    28,   259,   133,   256,    -1,   245,   259,   195,
     256,    -1,    47,   259,   155,   256,    -1,   151,   259,   195,
     256,    -1,    39,   259,   195,   256,    -1,   237,   259,   265,
     256,    -1,    -1,   144,   541,   259,   542,   256,    -1,   542,
     260,   543,    -1,   543,    -1,   202,    -1,   205,    -1,   207,
      -1,   208,    -1,   211,    -1,   229,    -1,   225,    -1,   227,
      -1,   233,    -1,   230,    -1,   210,    -1,   226,    -1,   228,
      -1,   212,    -1,   236,    -1,   203,    -1,   204,    -1,   215,
      -1,    -1,   141,   545,   259,   546,   256,    -1,   546,   260,
     547,    -1,   547,    -1,   202,    -1,   205,    -1,   207,    -1,
     208,    -1,   211,    -1,   229,    -1,   225,    -1,   227,    -1,
     233,    -1,   230,    -1,   210,    -1,   226,    -1,   228,    -1,
     212,    -1,   236,    -1,   203,    -1,   204,    -1,   215,    -1,
     118,   259,   133,   256,    -1,   119,   259,   133,   256,    -1,
      33,   259,   133,   256,    -1,   206,   259,   267,   256,    -1,
      44,   259,   195,   256,    -1,    -1,    68,   554,   258,   555,
     257,   256,    -1,   555,   556,    -1,   556,    -1,   557,    -1,
     558,    -1,   559,    -1,   563,    -1,   564,    -1,   565,    -1,
       1,    -1,    49,   259,   195,   256,    -1,    46,   259,   265,
     256,    -1,    -1,   104,   560,   259,   561,   256,    -1,   561,
     260,   562,    -1,   562,    -1,   197,    -1,    11,    -1,   244,
     259,   155,   256,    -1,   122,   259,   155,   256,    -1,    -1,
       4,   566,   259,   567,   256,    -1,   567,   260,   568,    -1,
     568,    -1,   197,    -1,    11,    -1,    22,   258,   570,   257,
     256,    -1,   570,   571,    -1,   571,    -1,   574,    -1,   575,
      -1,   576,    -1,   577,    -1,   582,    -1,   578,    -1,   579,
      -1,   580,    -1,   581,    -1,   583,    -1,   584,    -1,   585,
      -1,   573,    -1,   586,    -1,   587,    -1,   588,    -1,   589,
      -1,   572,    -1,     1,    -1,    40,   259,   195,   256,    -1,
     165,   259,   195,   256,    -1,    42,   259,   195,   256,    -1,
     246,   259,   195,   256,    -1,   247,   259,   195,   256,    -1,
     248,   259,   195,   256,    -1,    98,   259,   265,   256,    -1,
      99,   259,   265,   256,    -1,   108,   259,   133,   256,    -1,
     156,   259,   195,   256,    -1,   107,   259,   133,   256,    -1,
      35,   259,   133,   256,    -1,    34,   259,   133,   256,    -1,
     128,   259,   195,   256,    -1,   129,   259,   195,   256,    -1,
      13,   259,   195,   256,    -1,   145,   259,   133,   256,    -1,
     146,   259,   265,   256,    -1,   179,   258,   591,   257,   256,
      -1,   591,   592,    -1,   592,    -1,   593,    -1,   594,    -1,
     596,    -1,   598,    -1,   597,    -1,   595,    -1,   599,    -1,
       1,    -1,    56,   259,   195,   256,    -1,    83,   259,   195,
     256,    -1,    80,   259,   155,   256,    -1,   101,   259,   265,
     256,    -1,    78,   259,   195,   256,    -1,    41,   259,   195,
     256,    -1,    82,   259,   195,   256,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   382,   382,   383,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   411,   411,   412,   416,
     420,   424,   428,   432,   438,   438,   439,   440,   441,   442,
     449,   452,   452,   453,   453,   453,   455,   459,   466,   469,
     469,   471,   471,   471,   472,   472,   473,   473,   474,   475,
     475,   476,   476,   479,   513,   573,   587,   605,   614,   628,
     637,   665,   695,   718,   727,   729,   729,   730,   730,   730,
     731,   733,   742,   751,   764,   766,   766,   769,   769,   769,
     770,   771,   771,   772,   772,   773,   773,   774,   774,   775,
     778,   782,   786,   793,   800,   807,   814,   821,   828,   835,
     842,   846,   850,   854,   858,   862,   866,   872,   882,   881,
     975,   975,   976,   976,   977,   977,   977,   977,   977,   978,
     978,   979,   979,   979,   980,   980,   980,   981,   981,   981,
     982,   982,   982,   982,   983,   983,   984,   986,   998,  1010,
    1044,  1056,  1067,  1109,  1119,  1118,  1124,  1124,  1125,  1129,
    1133,  1137,  1141,  1145,  1149,  1153,  1157,  1161,  1165,  1169,
    1173,  1177,  1181,  1185,  1189,  1193,  1199,  1210,  1221,  1232,
    1243,  1254,  1265,  1276,  1287,  1298,  1309,  1320,  1331,  1342,
    1354,  1353,  1357,  1357,  1358,  1358,  1359,  1359,  1361,  1368,
    1375,  1382,  1389,  1396,  1403,  1410,  1417,  1424,  1431,  1438,
    1445,  1452,  1459,  1466,  1480,  1479,  1521,  1521,  1523,  1523,
    1524,  1524,  1525,  1525,  1526,  1527,  1528,  1529,  1530,  1531,
    1532,  1533,  1534,  1535,  1538,  1547,  1556,  1562,  1568,  1574,
    1580,  1586,  1592,  1598,  1604,  1610,  1616,  1622,  1632,  1631,
    1648,  1647,  1651,  1651,  1652,  1656,  1662,  1662,  1663,  1663,
    1663,  1663,  1663,  1665,  1667,  1667,  1669,  1684,  1706,  1715,
    1728,  1727,  1796,  1796,  1797,  1797,  1797,  1797,  1797,  1798,
    1798,  1799,  1799,  1799,  1800,  1800,  1801,  1801,  1801,  1802,
    1802,  1804,  1841,  1854,  1865,  1874,  1886,  1885,  1889,  1889,
    1890,  1890,  1891,  1891,  1893,  1901,  1908,  1915,  1922,  1929,
    1936,  1943,  1950,  1957,  1966,  1977,  1988,  1999,  2010,  2021,
    2033,  2052,  2062,  2071,  2087,  2086,  2102,  2102,  2103,  2103,
    2103,  2103,  2105,  2114,  2129,  2143,  2142,  2158,  2158,  2159,
    2159,  2159,  2159,  2161,  2170,  2193,  2192,  2198,  2198,  2199,
    2203,  2207,  2211,  2215,  2219,  2223,  2227,  2231,  2235,  2239,
    2249,  2248,  2263,  2263,  2264,  2264,  2264,  2266,  2276,  2275,
    2281,  2281,  2282,  2286,  2290,  2294,  2298,  2302,  2306,  2310,
    2314,  2318,  2322,  2332,  2331,  2477,  2477,  2478,  2478,  2479,
    2479,  2479,  2479,  2480,  2480,  2481,  2481,  2482,  2482,  2482,
    2483,  2483,  2483,  2484,  2484,  2484,  2485,  2485,  2488,  2500,
    2512,  2521,  2547,  2565,  2583,  2589,  2593,  2601,  2611,  2610,
    2614,  2614,  2615,  2615,  2616,  2616,  2618,  2629,  2636,  2643,
    2650,  2660,  2701,  2712,  2723,  2738,  2749,  2762,  2775,  2784,
    2820,  2819,  2883,  2882,  2886,  2886,  2887,  2893,  2893,  2894,
    2894,  2894,  2894,  2896,  2915,  2925,  2924,  2946,  2946,  2947,
    2947,  2947,  2949,  2958,  2970,  2972,  2972,  2973,  2973,  2975,
    2997,  2996,  3038,  3037,  3041,  3041,  3042,  3048,  3048,  3049,
    3049,  3049,  3049,  3051,  3057,  3066,  3069,  3069,  3070,  3070,
    3070,  3071,  3071,  3072,  3072,  3073,  3073,  3074,  3074,  3075,
    3075,  3076,  3076,  3077,  3077,  3078,  3078,  3079,  3079,  3080,
    3080,  3081,  3081,  3082,  3082,  3083,  3083,  3084,  3084,  3085,
    3085,  3086,  3086,  3087,  3087,  3088,  3088,  3089,  3089,  3090,
    3091,  3091,  3092,  3092,  3093,  3093,  3094,  3094,  3095,  3095,
    3096,  3096,  3097,  3097,  3101,  3106,  3111,  3116,  3121,  3126,
    3131,  3136,  3141,  3146,  3151,  3156,  3161,  3166,  3171,  3176,
    3181,  3186,  3191,  3197,  3208,  3213,  3222,  3227,  3232,  3237,
    3242,  3245,  3250,  3253,  3258,  3263,  3268,  3273,  3278,  3283,
    3288,  3293,  3298,  3309,  3314,  3319,  3324,  3333,  3365,  3383,
    3388,  3397,  3402,  3407,  3413,  3412,  3417,  3417,  3418,  3421,
    3424,  3427,  3430,  3433,  3436,  3439,  3442,  3445,  3448,  3451,
    3454,  3457,  3460,  3463,  3466,  3469,  3475,  3474,  3479,  3479,
    3480,  3483,  3486,  3489,  3492,  3495,  3498,  3501,  3504,  3507,
    3510,  3513,  3516,  3519,  3522,  3525,  3528,  3531,  3536,  3541,
    3546,  3551,  3556,  3565,  3564,  3588,  3588,  3589,  3589,  3590,
    3591,  3592,  3593,  3594,  3597,  3603,  3610,  3609,  3614,  3614,
    3615,  3619,  3625,  3659,  3669,  3668,  3718,  3718,  3719,  3723,
    3732,  3735,  3735,  3736,  3736,  3736,  3737,  3737,  3738,  3738,
    3739,  3739,  3740,  3740,  3741,  3742,  3742,  3743,  3743,  3744,
    3744,  3745,  3747,  3752,  3757,  3762,  3767,  3772,  3777,  3782,
    3787,  3792,  3797,  3802,  3807,  3812,  3817,  3822,  3827,  3832,
    3840,  3843,  3843,  3844,  3844,  3844,  3845,  3846,  3847,  3847,
    3848,  3851,  3857,  3863,  3872,  3886,  3892,  3898
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ACCEPT_PASSWORD", "ACTION", "ADMIN", 
  "AFTYPE", "T_ALLOW", "ANTI_NICK_FLOOD", "ANTI_SPAM_EXIT_MESSAGE_TIME", 
  "AUTOCONN", "T_BLOCK", "BURST_AWAY", "BURST_TOPICWHO", "BYTES", 
  "KBYTES", "MBYTES", "GBYTES", "TBYTES", "CALLER_ID_WAIT", "CAN_FLOOD", 
  "CAN_IDLE", "CHANNEL", "CIDR_BITLEN_IPV4", "CIDR_BITLEN_IPV6", 
  "CIPHER_PREFERENCE", "CLASS", "COMPRESSED", "COMPRESSION_LEVEL", 
  "CONNECT", "CONNECTFREQ", "CRYPTLINK", "DEFAULT_CIPHER_PREFERENCE", 
  "DEFAULT_FLOODCOUNT", "DEFAULT_SPLIT_SERVER_COUNT", 
  "DEFAULT_SPLIT_USER_COUNT", "DENY", "DESCRIPTION", "DIE", 
  "DISABLE_AUTH", "DISABLE_FAKE_CHANNELS", "DISABLE_HIDDEN", 
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
  "MAX_BANS", "MAX_CHANS_PER_USER", "MAX_GLOBAL", "MAX_IDENT", 
  "MAX_LOCAL", "MAX_NICK_CHANGES", "MAX_NICK_TIME", "MAX_NUMBER", 
  "MAX_TARGETS", "MAX_WATCH", "MESSAGE_LOCALE", "MIN_NONWILDCARD", 
  "MIN_NONWILDCARD_SIMPLE", "MODULE", "MODULES", "NAME", "NEED_PASSWORD", 
  "NETWORK_DESC", "NETWORK_NAME", "NICK", "NICK_CHANGES", 
  "NO_CREATE_ON_SPLIT", "NO_JOIN_ON_SPLIT", "NO_OPER_FLOOD", "NO_TILDE", 
  "NOT", "NUMBER", "NUMBER_PER_IDENT", "NUMBER_PER_CIDR", "NUMBER_PER_IP", 
  "NUMBER_PER_IP_GLOBAL", "OPERATOR", "OPERS_BYPASS_CALLERID", "OPER_LOG", 
  "OPER_ONLY_UMODES", "OPER_PASS_RESV", "OPER_SPY_T", "OPER_UMODES", 
  "JOIN_FLOOD_COUNT", "JOIN_FLOOD_TIME", "PACE_WAIT", "PACE_WAIT_SIMPLE", 
  "PASSWORD", "PATH", "PING_COOKIE", "PING_TIME", "PING_WARNING", "PORT", 
  "QSTRING", "QUIET_ON_BAN", "REASON", "REDIRPORT", "REDIRSERV", 
  "REGEX_T", "REHASH", "TREJECT_HOLD_TIME", "REMOTE", "REMOTEBAN", 
  "RESTRICT_CHANNELS", "RESTRICTED", "RSA_PRIVATE_KEY_FILE", 
  "RSA_PUBLIC_KEY_FILE", "SSL_CERTIFICATE_FILE", "RESV", "RESV_EXEMPT", 
  "SECONDS", "MINUTES", "HOURS", "DAYS", "WEEKS", "SENDQ", 
  "SEND_PASSWORD", "SERVERHIDE", "SERVERINFO", "SERVLINK_PATH", 
  "IRCD_SID", "TKLINE_EXPIRE_NOTICES", "T_SHARED", "T_CLUSTER", "TYPE", 
  "SHORT_MOTD", "SILENT", "SPOOF", "SPOOF_NOTICE", "STATS_I_OPER_ONLY", 
  "STATS_K_OPER_ONLY", "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY", "TBOOL", 
  "TMASKED", "T_REJECT", "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS", 
  "T_ALL", "T_BOTS", "T_SOFTCALLERID", "T_CALLERID", "T_CCONN", 
  "T_CLIENT_FLOOD", "T_DEAF", "T_DEBUG", "T_DRONE", "T_EXTERNAL", 
  "T_FULL", "T_INVISIBLE", "T_IPV4", "T_IPV6", "T_LOCOPS", "T_LOGPATH", 
  "T_L_CRIT", "T_L_DEBUG", "T_L_ERROR", "T_L_INFO", "T_L_NOTICE", 
  "T_L_TRACE", "T_L_WARN", "T_MAX_CLIENTS", "T_NCHANGE", "T_OPERWALL", 
  "T_REJ", "T_SERVNOTICE", "T_SKILL", "T_SPY", "T_SSL", "T_UMODES", 
  "T_UNAUTH", "T_UNRESV", "T_UNXLINE", "T_WALLOP", "THROTTLE_TIME", 
  "TOPICBURST", "TRUE_NO_OPER_FLOOD", "TKLINE", "TXLINE", "TRESV", 
  "UNKLINE", "USER", "USE_EGD", "USE_EXCEPT", "USE_INVEX", "USE_KNOCK", 
  "USE_LOGGING", "USE_WHOIS_ACTUALLY", "VHOST", "VHOST6", "XLINE", "WARN", 
  "WARN_NO_NLINE", "';'", "'}'", "'{'", "'='", "','", "$accept", "conf", 
  "conf_item", "timespec_", "timespec", "sizespec_", "sizespec", 
  "modules_entry", "modules_items", "modules_item", "modules_module", 
  "modules_path", "serverinfo_entry", "serverinfo_items", 
  "serverinfo_item", "serverinfo_ssl_certificate_file", 
  "serverinfo_rsa_private_key_file", "serverinfo_name", "serverinfo_sid", 
  "serverinfo_description", "serverinfo_network_name", 
  "serverinfo_network_desc", "serverinfo_vhost", "serverinfo_vhost6", 
  "serverinfo_max_clients", "serverinfo_hub", "admin_entry", 
  "admin_items", "admin_item", "admin_name", "admin_email", 
  "admin_description", "logging_entry", "logging_items", "logging_item", 
  "logging_path", "logging_oper_log", "logging_fuserlog", 
  "logging_ffailed_operlog", "logging_foperlog", "logging_foperspylog", 
  "logging_fglinelog", "logging_fklinelog", "logging_ioerrlog", 
  "logging_killlog", "logging_log_level", "logging_use_logging", 
  "oper_entry", "@1", "oper_name_b", "oper_items", "oper_item", 
  "oper_name", "oper_name_t", "oper_user", "oper_password", 
  "oper_encrypted", "oper_rsa_public_key_file", "oper_class", 
  "oper_umodes", "@2", "oper_umodes_items", "oper_umodes_item", 
  "oper_global_kill", "oper_remote", "oper_remoteban", "oper_kline", 
  "oper_xline", "oper_unkline", "oper_gline", "oper_nick_changes", 
  "oper_die", "oper_rehash", "oper_admin", "oper_hidden_admin", 
  "oper_hidden_oper", "oper_operwall", "oper_flags", "@3", 
  "oper_flags_items", "oper_flags_item", "@4", "@5", 
  "oper_flags_item_atom", "class_entry", "@6", "class_name_b", 
  "class_items", "class_item", "class_name", "class_name_t", 
  "class_ping_time", "class_ping_warning", "class_number_per_ip", 
  "class_connectfreq", "class_max_number", "class_max_global", 
  "class_max_local", "class_max_ident", "class_sendq", 
  "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6", 
  "class_number_per_cidr", "listen_entry", "@7", "listen_flags", "@8", 
  "listen_flags_items", "listen_flags_item", "listen_items", 
  "listen_item", "listen_port", "port_items", "port_item", 
  "listen_address", "listen_host", "auth_entry", "@9", "auth_items", 
  "auth_item", "auth_user", "auth_passwd", "auth_spoof_notice", 
  "auth_class", "auth_encrypted", "auth_flags", "@10", "auth_flags_items", 
  "auth_flags_item", "@11", "@12", "auth_flags_item_atom", 
  "auth_kline_exempt", "auth_need_ident", "auth_exceed_limit", 
  "auth_can_flood", "auth_no_tilde", "auth_gline_exempt", "auth_spoof", 
  "auth_redir_serv", "auth_redir_port", "auth_need_password", 
  "resv_entry", "@13", "resv_items", "resv_item", "resv_creason", 
  "resv_channel", "resv_nick", "shared_entry", "@14", "shared_items", 
  "shared_item", "shared_name", "shared_user", "shared_type", "@15", 
  "shared_types", "shared_type_item", "cluster_entry", "@16", 
  "cluster_items", "cluster_item", "cluster_name", "cluster_type", "@17", 
  "cluster_types", "cluster_type_item", "connect_entry", "@18", 
  "connect_name_b", "connect_items", "connect_item", "connect_name", 
  "connect_name_t", "connect_host", "connect_vhost", 
  "connect_send_password", "connect_accept_password", "connect_port", 
  "connect_aftype", "connect_fakename", "connect_flags", "@19", 
  "connect_flags_items", "connect_flags_item", "@20", "@21", 
  "connect_flags_item_atom", "connect_rsa_public_key_file", 
  "connect_encrypted", "connect_cryptlink", "connect_compressed", 
  "connect_auto", "connect_hub_mask", "connect_leaf_mask", 
  "connect_class", "connect_cipher_preference", "kill_entry", "@22", 
  "kill_type", "@23", "kill_type_items", "kill_type_item", "kill_items", 
  "kill_item", "kill_user", "kill_reason", "deny_entry", "@24", 
  "deny_items", "deny_item", "deny_ip", "deny_reason", "exempt_entry", 
  "exempt_items", "exempt_item", "exempt_ip", "gecos_entry", "@25", 
  "gecos_flags", "@26", "gecos_flags_items", "gecos_flags_item", 
  "gecos_items", "gecos_item", "gecos_name", "gecos_reason", 
  "general_entry", "general_items", "general_item", "general_max_watch", 
  "general_gline_min_cidr", "general_gline_min_cidr6", 
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
  "gline_logging", "@30", "gline_logging_types", 
  "gline_logging_type_item", "gline_user", "gline_server", "gline_action", 
  "@31", "gdeny_types", "gdeny_type_item", "channel_entry", 
  "channel_items", "channel_item", "channel_disable_fake_channels", 
  "channel_restrict_channels", "channel_disable_local_channels", 
  "channel_use_except", "channel_use_invex", "channel_use_knock", 
  "channel_knock_delay", "channel_knock_delay_channel", 
  "channel_max_chans_per_user", "channel_quiet_on_ban", 
  "channel_max_bans", "channel_default_split_user_count", 
  "channel_default_split_server_count", "channel_no_create_on_split", 
  "channel_no_join_on_split", "channel_burst_topicwho", 
  "channel_jflood_count", "channel_jflood_time", "serverhide_entry", 
  "serverhide_items", "serverhide_item", "serverhide_flatten_links", 
  "serverhide_hide_servers", "serverhide_hidden_name", 
  "serverhide_links_delay", "serverhide_hidden", 
  "serverhide_disable_hidden", "serverhide_hide_server_ips", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
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
static const unsigned short yyr1[] =
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
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     460,   459,   462,   461,   463,   463,   464,   465,   465,   466,
     466,   466,   466,   467,   468,   470,   469,   471,   471,   472,
     472,   472,   473,   474,   475,   476,   476,   477,   477,   478,
     480,   479,   482,   481,   483,   483,   484,   485,   485,   486,
     486,   486,   486,   487,   488,   489,   490,   490,   491,   491,
     491,   491,   491,   491,   491,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   491,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   491,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   491,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   491,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   518,   519,   519,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   541,   540,   542,   542,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   545,   544,   546,   546,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   548,   549,
     550,   551,   552,   554,   553,   555,   555,   556,   556,   556,
     556,   556,   556,   556,   557,   558,   560,   559,   561,   561,
     562,   562,   563,   564,   566,   565,   567,   567,   568,   568,
     569,   570,   570,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   591,   592,   592,   592,   592,   592,   592,   592,
     592,   593,   594,   595,   596,   597,   598,   599
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
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
       2,     0,     1,     0,     0,     0,   214,   383,   455,     0,
     470,     0,   643,   270,   440,   248,     0,     0,   118,   324,
       0,     0,   335,   360,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      22,    20,    21,     7,    12,    24,    25,     0,     0,   216,
     385,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,    77,    79,    78,   691,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   672,   690,   685,   673,
     674,   675,   676,   678,   679,   680,   681,   677,   682,   683,
     684,   686,   687,   688,   689,   235,     0,   217,   409,     0,
     386,     0,   468,     0,     0,   466,   467,     0,   543,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   616,     0,   594,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   487,   542,   538,   539,   536,
     540,   541,   537,   498,   488,   489,   527,   490,   491,   492,
     493,   494,   495,   496,   497,   532,   499,   500,   501,   502,
     504,   509,   505,   507,   506,   521,   522,   508,   510,   511,
     512,   513,   515,   514,   503,   517,   526,   528,   529,   518,
     519,   534,   535,   531,   520,   516,   524,   525,   523,   530,
     533,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    91,    98,    92,    96,    93,    94,    97,    95,
      89,    90,     0,     0,     0,     0,    42,    43,    44,   148,
       0,   121,     0,   720,     0,     0,     0,     0,     0,     0,
       0,     0,   712,   713,   714,   718,   715,   717,   716,   719,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,    61,    58,    51,    60,    54,    55,
      56,    52,    59,    57,    53,     0,     0,    80,     0,     0,
       0,     0,    75,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   671,     0,     0,   461,     0,     0,     0,   458,
     459,   460,     0,     0,   465,   482,     0,     0,   472,   481,
       0,   478,   479,   480,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     486,   653,   664,     0,     0,   656,     0,     0,     0,   646,
     647,   648,   649,   650,   651,   652,     0,     0,     0,     0,
       0,   296,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   273,   274,   275,   284,   276,   289,
     277,   278,   279,   280,   287,   281,   282,   283,   285,   286,
     288,   452,     0,   442,     0,   451,     0,   448,   449,   450,
       0,   250,     0,     0,     0,   259,     0,   257,   258,   260,
     261,    99,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    45,     0,     0,     0,
      41,     0,     0,     0,     0,     0,     0,   327,   328,   329,
     330,     0,     0,     0,     0,     0,     0,     0,     0,   711,
      62,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,     0,     0,   345,     0,     0,   338,
     339,   340,   341,     0,     0,   368,     0,   363,   364,   365,
       0,     0,     0,    74,     0,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   670,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   219,
     220,   223,   224,   226,   227,   228,   229,   230,   231,   232,
     221,   222,   225,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   418,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   388,   389,   390,   391,   392,   393,   395,
     394,   396,   397,   405,   402,   404,   403,   401,   398,   399,
     400,   406,     0,     0,     0,   457,     0,   464,     0,     0,
       0,     0,   477,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    34,     0,     0,     0,     0,     0,
       0,   485,     0,     0,     0,     0,     0,     0,     0,   645,
     290,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   272,     0,
       0,     0,     0,   447,   262,     0,     0,     0,     0,     0,
     256,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
       0,     0,    40,     0,     0,     0,     0,     0,   190,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   154,     0,     0,     0,     0,   123,   124,   125,
     126,   143,   144,   130,   129,   131,   132,   138,   133,   134,
     135,   136,   137,   139,   140,   141,   127,   128,   142,   145,
     331,     0,     0,     0,     0,   326,     0,     0,     0,     0,
       0,     0,     0,   710,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,   342,     0,     0,     0,
       0,   337,   366,     0,     0,     0,   362,    83,    82,    81,
     707,   704,   703,   692,   694,    26,    26,    26,    26,    26,
      28,    27,   698,   699,   702,   700,   705,   706,   708,   709,
     701,   693,   695,   696,   697,   233,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     218,   407,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   387,     0,     0,   456,   469,     0,     0,     0,   471,
     556,   560,   547,   575,   588,   587,   640,   592,   554,   642,
     584,   590,   555,   545,   546,   563,   552,   583,   553,   566,
     551,   565,   564,   559,   558,   557,   585,   544,   582,   638,
     639,   579,   576,   620,   635,   636,   621,   622,   623,   630,
     624,   633,   637,   626,   631,   627,   632,   625,   629,   628,
     634,     0,   619,   581,   598,   613,   614,   599,   600,   601,
     608,   602,   611,   615,   604,   609,   605,   610,   603,   607,
     606,   612,     0,   597,   574,   577,   591,   549,   586,   550,
     578,   572,   573,   570,   571,   568,   569,   562,   561,    34,
      34,    34,    36,    35,   641,   593,   580,   589,   548,   567,
       0,     0,     0,     0,     0,     0,   644,     0,     0,     0,
       0,   302,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   271,     0,     0,     0,   441,     0,     0,
       0,   266,     0,   265,   249,   103,   109,   107,   106,   108,
     104,   105,   102,   110,   116,   111,   115,   113,   114,   112,
     101,   100,   117,    46,    47,   146,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   122,
       0,     0,     0,   325,   726,   721,   725,   723,   727,   722,
     724,    67,    73,    65,    69,    68,    64,    63,    66,    72,
      70,    71,     0,     0,     0,   336,     0,     0,   361,    29,
      30,    31,    32,    33,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   215,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   424,     0,
       0,     0,     0,     0,     0,     0,     0,   384,   462,   463,
     483,   484,   476,     0,   475,   617,     0,   595,     0,    37,
      38,    39,   669,   668,     0,   667,   655,   654,   661,   660,
       0,   659,   663,   662,   317,   294,   295,   316,   300,     0,
     299,     0,   319,   315,   314,   323,   318,   292,   322,   321,
     320,   293,   291,   454,   446,     0,   445,   453,   255,   254,
       0,   253,   269,   268,     0,   263,     0,     0,     0,     0,
       0,   196,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   119,
     333,   334,   332,   343,   349,   355,   359,   358,   357,   354,
     350,   353,   356,   351,   352,     0,   348,   344,   367,   372,
     378,   382,   381,   380,   377,   373,   376,   379,   374,   375,
       0,   371,   245,   246,   239,   241,   243,   242,   240,   234,
     247,   238,   236,   237,   244,   413,   415,   416,   435,   439,
     438,   434,   433,   432,   417,   422,     0,   421,     0,   410,
     436,   437,   408,   414,   431,   412,   411,   473,     0,   618,
     596,   665,     0,   657,     0,     0,   297,   302,   308,   309,
     305,   311,   307,   306,   313,   310,   312,   304,   303,   443,
       0,   251,     0,   267,   264,   186,   153,   184,   151,   194,
       0,   193,     0,   182,   176,   187,   188,   179,   147,   183,
     150,   185,   177,   178,   152,   189,   158,   173,   174,   159,
     160,   161,   168,   162,   171,   175,   164,   169,   165,   170,
     163,   167,   166,   172,     0,   157,   181,   149,   180,   346,
       0,   369,     0,     0,   419,   424,   428,   429,   426,   427,
     430,   425,   474,   666,   658,   301,   298,   444,   252,     0,
     191,   196,   206,   204,   213,   203,   198,   207,   211,   200,
     208,   210,   205,   199,   212,   209,   201,   202,   197,   155,
       0,   347,   370,   423,   420,   195,   192,   156
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     1,    24,   890,   891,  1042,  1043,    25,   275,   276,
     277,   278,    26,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,    27,    71,    72,    73,
      74,    75,    28,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,    29,    61,   280,
     816,   817,   818,   281,   819,   820,   821,   822,   823,   824,
    1124,  1414,  1415,   825,   826,   827,   828,   829,   830,   831,
     832,   833,   834,   835,   836,   837,   838,   839,  1110,  1380,
    1381,  1439,  1382,  1458,    30,    49,   116,   608,   609,   610,
     117,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,    31,    58,   495,   765,  1250,  1251,   496,
     497,   498,  1082,  1083,   499,   500,    32,    56,   463,   464,
     465,   466,   467,   468,   469,   470,   745,  1229,  1230,  1355,
    1231,  1368,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,    33,    62,   526,   527,   528,   529,   530,    34,
      65,   558,   559,   560,   561,   562,   868,  1295,  1296,    35,
      66,   566,   567,   568,   569,   874,  1310,  1311,    36,    50,
     119,   642,   643,   644,   120,   645,   646,   647,   648,   649,
     650,   651,   652,   931,  1336,  1337,  1423,  1338,  1431,   653,
     654,   655,   656,   657,   658,   659,   660,   661,    37,    57,
     485,   760,  1245,  1246,   486,   487,   488,   489,    38,    51,
     358,   359,   360,   361,    39,   124,   125,   126,    40,    53,
     369,   670,  1203,  1204,   370,   371,   372,   373,    41,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     409,  1022,  1023,   235,   407,  1001,  1002,   236,   237,   238,
     239,   240,    42,    55,   438,   439,   440,   441,   442,   735,
    1220,  1221,   443,   444,   445,   732,  1214,  1215,    43,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    44,
     291,   292,   293,   294,   295,   296,   297,   298,   299
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -746
static const short yypact[] =
{
    -746,   900,  -746,  -216,  -244,  -236,  -746,  -746,  -746,  -207,
    -746,  -201,  -746,  -746,  -746,  -746,  -192,  -189,  -746,  -746,
    -165,  -141,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,   318,   767,  -144,
     -59,  -136,    35,  -133,   484,  -110,  -103,  -100,   -91,   654,
      75,    20,   -89,   565,   297,   -74,   -68,   -62,   -58,   -55,
     -49,     7,  -746,  -746,  -746,  -746,  -746,   -23,   -20,   -19,
     -15,   -14,    -8,     4,    26,    37,    43,    44,    46,    50,
      70,    73,    77,    92,    93,   215,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,    32,  -746,  -746,    52,
    -746,    24,  -746,    95,     9,  -746,  -746,   184,  -746,    97,
      98,   103,   104,   105,   108,   109,   113,   117,   118,   119,
     120,   123,   126,   127,   129,   130,   131,   133,   135,   139,
     143,   145,   147,   150,   156,   157,   159,   164,   168,   169,
     170,   171,  -746,   175,  -746,   177,   178,   182,   186,   188,
     189,   190,   192,   194,   195,   198,   199,   200,   208,   210,
     211,   212,   214,   216,    15,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,   338,   822,     3,   290,    -3,   218,   222,   229,   230,
     231,   232,   235,   239,   241,   243,   245,   246,   219,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,    84,   247,   251,    30,  -746,  -746,  -746,  -746,
     185,  -746,   160,  -746,   252,   255,   256,   259,   260,   261,
     265,    96,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
     274,   273,   277,   279,   280,   292,   293,   295,   296,   299,
     300,   304,   283,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,    25,    17,  -746,   271,   278,
     319,   306,  -746,    79,   345,   368,   369,   370,   400,   400,
     436,   438,   380,   381,   450,   400,   389,   390,   393,   396,
     403,   348,  -746,   373,   700,  -746,   349,   350,    55,  -746,
    -746,  -746,   452,   354,  -746,  -746,   353,   357,  -746,  -746,
      14,  -746,  -746,  -746,   418,   400,   422,   400,   485,   467,
     491,   432,   434,   435,   500,   481,   442,   505,   506,   508,
     447,   400,   454,   455,   518,   502,   463,   530,   535,   400,
     537,   541,   524,   551,   553,   494,   496,   433,   499,   437,
     400,   400,   503,   400,   542,   504,   507,  -132,  -117,   509,
     510,   400,   400,   574,   400,   514,   525,   527,   529,   472,
    -746,  -746,  -746,   460,   471,  -746,   473,   476,    31,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,   482,   478,   483,   486,
     487,  -746,   488,   489,   492,   493,   497,   498,   501,   512,
     513,   515,   517,   242,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,   520,  -746,   522,  -746,    81,  -746,  -746,  -746,
     528,  -746,   531,   532,   533,  -746,    16,  -746,  -746,  -746,
    -746,  -746,   585,   588,   589,   598,   603,   607,   609,   610,
     324,   611,   618,   566,   539,  -746,  -746,   628,   631,   540,
    -746,   614,   543,   534,   538,   544,   101,  -746,  -746,  -746,
    -746,   593,   594,   613,   643,   615,   616,   400,   550,  -746,
    -746,   657,   619,   658,   660,   661,   662,   663,   664,   687,
     666,   669,   569,  -746,   570,   568,  -746,   571,    51,  -746,
    -746,  -746,  -746,   572,   575,  -746,     2,  -746,  -746,  -746,
     573,   577,   580,  -746,   581,   582,   583,   587,   591,   174,
     595,   596,   599,   600,   605,   608,   620,   624,   625,   626,
     627,   629,   630,  -746,   632,   586,   604,   612,   633,   634,
     635,   638,   640,   645,   647,   649,   650,   651,   303,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,   646,   652,   655,   659,   665,   668,   671,
     672,   674,   675,  -746,   676,   678,   679,   680,   681,   682,
     683,   684,    64,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,   686,   689,   688,  -746,   690,  -746,   695,   707,
     691,   692,  -746,   693,   698,   701,   702,   703,   704,   705,
     706,   708,   711,   713,   714,   716,   717,   720,   721,   722,
     723,   726,   727,   728,   729,   730,   731,   732,   733,   734,
     735,   737,   738,   739,   740,   741,   815,   742,   884,   743,
     744,   745,   747,   749,   750,   751,   752,   753,   754,   760,
     768,   772,   773,   775,     5,   776,   777,   778,   779,   780,
     781,  -746,   697,   400,   636,   787,   761,   764,   783,  -746,
    -746,   694,   765,   852,   854,   791,   857,   858,   859,   860,
     861,   766,   736,   770,   792,   862,   808,   802,  -746,   904,
     801,   906,   806,  -746,  -746,   804,   909,   910,   757,   811,
    -746,   812,   813,   816,   817,   818,   819,   820,   821,   825,
     826,   827,   834,   837,   841,   842,   844,   845,   846,  -746,
     847,   848,  -746,   849,   856,   866,   869,   873,  -746,   874,
     876,   877,   878,   879,   880,   881,   882,   883,   891,   892,
     894,   895,  -746,   897,   898,   899,   167,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,   916,   923,   951,   851,  -746,   863,   887,   903,   905,
     907,   908,   911,  -746,   912,   913,   914,   915,   917,   918,
     920,   921,   922,   924,   925,  -746,  -746,   953,   901,   961,
     926,  -746,  -746,   963,   927,   928,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,   400,   400,   400,   400,   400,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,   795,  1029,   400,  1032,
    1033,  1039,  1042,  1024,  1050,  1052,   400,   400,   574,   931,
    -746,  -746,  1034,    10,   993,  1035,  1036,   997,   998,   999,
    1040,   937,  1043,  1044,  1045,  1046,  1064,  1047,  1048,  1049,
     949,  -746,   950,   952,  -746,  -746,   954,   955,   724,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -247,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -227,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,   574,
     574,   574,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
      -6,   956,   957,    -5,   958,   959,  -746,   960,   962,   964,
     965,   755,   966,   967,   968,   969,   970,   971,   972,   973,
     974,   975,   976,  -746,   977,  1057,   978,  -746,   -66,   979,
     980,  1007,  -218,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  1014,  1082,  1051,  1053,
     981,  1054,  1055,  1056,  1058,  1059,  1083,  1060,  1084,  1061,
    1062,  1063,  1086,  1065,   983,  1066,  1088,  1067,   988,  -746,
     989,   991,   996,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  1003,   352,  1008,  -746,  1009,   419,  -746,  -746,
    -746,  -746,  -746,  -746,  1010,  1011,  1012,  1013,  1015,  1016,
    1017,  1018,  1019,  1020,  1021,  1022,  1023,  -746,  1025,  1026,
    1027,  1028,  1030,  1031,  1037,  1038,  1041,  1068,  1087,  1069,
    1070,  1071,  1072,  1073,  1074,  1075,  1076,  -746,  -746,  -746,
    -746,  -746,  -746,  -210,  -746,  -746,   815,  -746,   884,  -746,
    -746,  -746,  -746,  -746,  -175,  -746,  -746,  -746,  -746,  -746,
    -162,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -150,
    -746,   784,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -147,  -746,  -746,  -746,  -746,
    -140,  -746,  -746,  -746,  1130,  -746,   757,  1077,  1078,  1079,
    1080,  1138,  1081,  1085,  1089,  1090,  1091,  1092,  1093,  1094,
    1095,  1096,  1097,  1098,  1099,   919,  1100,  1101,  1102,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,   -73,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
     -41,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,   -30,  -746,    18,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,   724,  -746,
    -746,  -746,    -6,  -746,    -5,   784,  -746,   755,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    1057,  -746,   -66,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
     -27,  -746,   606,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,   -25,  -746,  -746,  -746,  -746,  -746,
     352,  -746,   419,    18,  -746,  1087,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,   606,
    -746,  1138,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
     919,  -746,  -746,  -746,  -746,  -746,  -746,  -746
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -746,  -746,  -746,  -745,  -338,  -740,  -421,  -746,  -746,  1005,
    -746,  -746,  -746,  -746,   984,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  1214,  -746,
    -746,  -746,  -746,  -746,  1103,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,   474,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -172,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -152,  -746,  -746,  -148,  -746,  -746,  -746,  -746,   696,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,   -80,  -746,
     799,  -746,  -746,    42,  -746,  -746,  -746,  -746,  -746,   836,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,   -57,  -746,
    -746,   -54,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,   782,  -746,  -746,  -746,  -746,
    -746,  -746,   748,  -746,  -746,  -746,  -746,  -746,  -118,  -746,
    -746,  -746,   746,  -746,  -746,  -746,  -746,  -119,  -746,  -746,
    -746,  -746,   667,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -120,  -746,  -746,  -116,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,   -60,  -746,   828,  -746,  -746,  -746,  -746,
    -746,   982,  -746,  -746,  -746,  -746,  1187,  -746,  -746,  -746,
    -746,  -746,  -746,   -35,  -746,   945,  -746,  -746,  -746,  -746,
    1132,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,   110,  -746,  -746,  -746,   111,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,   885,  -746,  -746,  -746,  -746,
    -746,   -34,  -746,  -746,  -746,  -746,  -746,   -33,  -746,  -746,
    1226,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  1104,  -746,  -746,  -746,  -746,  -746,  -746,  -746
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, parse error.  */
#define YYTABLE_NINF -1
static const unsigned short yytable[] =
{
     580,   581,   725,   563,   481,  1212,  1218,   587,    67,  1205,
     122,   115,  1248,  1206,    47,   365,   128,   490,   563,  1039,
    1040,  1041,    48,   129,   130,   355,   554,   131,  1426,  1207,
    1427,   272,   431,  1208,   132,   432,   122,   674,  1255,   676,
      45,    46,  1256,   133,    68,  1428,  1347,   134,   135,  1429,
    1348,    52,   554,   690,   136,    69,   355,    54,   137,   138,
     139,   698,   140,   716,   717,   623,    59,   624,   141,    60,
     625,   491,   709,   710,   626,   712,   272,   433,   718,   719,
     434,  1351,   481,   722,   723,  1352,   726,   142,   143,   627,
     628,   629,   144,    63,  1353,   630,   118,   283,  1354,   145,
     123,   492,   522,   146,   147,   148,  1356,   493,   149,  1369,
    1357,   150,   151,  1370,   631,   356,  1371,    64,   632,   633,
    1372,   152,   121,   523,   564,   127,   123,   153,   154,    70,
     155,   156,   157,   158,   159,   435,   366,   284,   724,   564,
    1159,  1160,  1161,  1162,  1163,   160,   356,   555,   241,   634,
     273,   635,   285,   436,   161,   242,   162,   163,   243,   164,
     482,   522,   165,   166,   636,  1249,   167,   244,   793,   282,
     494,   367,   794,   555,   286,   279,   287,   168,   288,   289,
     274,   357,   523,  1419,   325,   365,   637,  1420,   565,   483,
     326,  1213,  1219,   795,   327,   273,   169,   290,   170,   852,
     368,   328,   171,   565,   329,   796,   172,   173,   174,   175,
     330,   556,   357,   176,   177,  1421,    76,   797,   638,  1422,
     245,   178,   798,  1179,  1180,   274,  1424,   524,    77,  1440,
    1425,  1459,   639,  1441,   799,  1460,   333,   556,   482,   334,
     335,   800,   640,   446,   336,   337,   801,   484,   802,    78,
      79,   338,   179,   501,   180,    80,  1430,    81,   525,   875,
     181,   803,   447,   339,   331,   182,   363,   483,   448,   557,
     183,   671,   429,   769,   574,   437,   246,   247,   248,   249,
     250,   251,   252,   253,   300,   340,   524,   519,   738,   804,
     353,   490,   449,   450,   805,   557,   341,   451,   300,  1209,
    1210,  1211,   342,   343,   594,   344,   366,   579,   870,   345,
     354,   452,   664,    82,    83,   641,   806,   525,   453,    67,
     301,   940,    84,    85,   254,   484,   595,   596,   807,   346,
     808,   809,   347,   597,   301,   810,   348,   454,   762,   431,
     516,   367,   432,    86,    87,   491,   885,   886,   887,   888,
     889,   349,   350,   538,   362,    68,   374,   375,   844,   255,
      88,    89,   376,   377,   378,   455,    69,   379,   380,   302,
     368,    90,   381,   456,   594,   492,   382,   383,   384,   385,
      91,   493,   386,   302,   433,   387,   388,   434,   389,   390,
     391,   457,   392,   811,   393,  1051,   595,   596,   394,   812,
     458,   459,   395,   597,   396,   303,   397,   304,   305,   398,
     813,   814,   598,   599,   600,   399,   400,   601,   401,   303,
     815,   304,   305,   402,  1128,   602,   570,   403,   404,   405,
     406,   460,   461,   571,   408,   256,   410,   411,   603,   604,
      70,   412,   435,   521,   494,   413,  1284,   414,   415,   416,
     306,   417,   307,   418,   419,   605,   606,   420,   421,   422,
     436,    92,    93,    94,   306,   308,   307,   423,   257,   424,
     425,   426,   351,   427,   572,   428,   514,   502,   575,   308,
     607,   503,   598,   599,   600,   128,   462,   601,   504,   505,
     506,   507,   129,   130,   508,   602,   131,  1176,   509,   757,
     510,   576,   511,   132,   512,   513,   517,   309,   603,   604,
     518,   531,   133,  1299,   532,   533,   134,   135,   534,   535,
     536,   309,  1285,   136,   537,   605,   606,   137,   138,   139,
     540,   140,   541,   579,   310,   311,   542,   141,   543,   544,
     552,   779,   780,   781,   782,   783,   784,   785,   310,   311,
     607,   545,   546,  1286,   547,   548,   142,   143,   549,   550,
     919,   144,   573,   551,   577,   578,   283,  1287,   145,   582,
    1166,   583,   146,   147,   148,   584,   585,   149,  1174,  1175,
     150,   151,   437,   586,   588,   589,  1288,  1289,   590,  1300,
     152,   591,  1290,  1291,  1292,  1293,   153,   154,   592,   155,
     156,   157,   158,   159,   593,  1294,   284,   666,   662,   663,
     667,  1442,   668,   673,   160,   793,   669,   675,   677,   794,
    1301,   285,   678,   161,   679,   162,   163,   680,   164,   681,
     682,   165,   166,   683,  1302,   167,   684,   685,   686,   687,
     795,   688,   689,   286,  1443,   287,   168,   288,   289,   691,
     692,   693,   796,  1303,  1304,   245,  1444,   694,   695,  1305,
    1306,  1307,  1308,   696,   797,   169,   290,   170,   697,   798,
     699,   171,  1309,  1445,   700,   172,   173,   174,   175,   701,
    1446,   799,   176,   177,   702,  1447,   703,  1448,   800,   704,
     178,   705,   706,   801,   707,   802,   708,   713,   711,   714,
    1449,   623,   715,   624,   720,   721,   625,   724,   803,   727,
     626,   246,   247,   248,   249,   250,   251,   252,   253,   733,
     728,   179,   729,   180,   730,   627,   628,   629,   731,   181,
     734,   630,   736,  1450,   182,   737,   804,   741,   740,   183,
     771,   805,   742,   772,   773,   743,   744,   746,   747,  1451,
     631,   748,   749,   774,   632,   633,   750,   751,   775,   254,
     752,   788,   776,   806,   777,   778,   786,  1452,    76,  1453,
    1454,   753,   754,   787,   755,   807,   756,   808,   809,   759,
      77,   761,   810,   790,   764,   634,   791,   635,   846,   847,
     766,   767,   768,   841,   255,   789,   792,   842,   849,   840,
     636,    78,    79,   843,  1358,  1359,   853,    80,   848,    81,
     850,   851,   854,   856,   855,   857,   858,   859,   860,   861,
     862,   863,   637,   446,   864,   865,   866,   867,   872,   877,
     869,  1052,  1455,   878,   873,  1360,   879,   880,   881,   882,
     811,   942,   447,   883,   943,   906,   812,   884,   448,  1456,
     946,   892,   893,  1361,   638,   894,   895,   813,   814,  1457,
    1362,   896,   947,   907,   897,    82,    83,   815,   639,  1068,
     256,   908,   449,   450,    84,    85,   898,   451,   640,  1363,
     899,   900,   901,   902,  1202,   903,   904,  1228,   905,  1057,
    1081,   452,   909,   910,   911,    86,    87,   912,   453,   913,
       2,     3,   921,   257,   914,     4,   915,  1364,   916,   917,
     918,   922,    88,    89,   923,  1365,  1054,   454,   924,  1055,
    1058,  1067,     5,    90,   925,  1069,     6,   926,  1164,     7,
     927,   928,    91,   929,   930,   932,     8,   933,   934,   935,
     936,   937,   938,   939,   944,   455,   945,  1070,   949,   950,
     948,   641,     9,   456,   951,  1366,  1050,   952,   953,   954,
     955,   956,   957,  1072,   958,    10,    11,   959,    12,   960,
     961,   457,   962,   963,  1367,    13,   964,   965,   966,   967,
     458,   459,   968,   969,   970,   971,   972,   973,   974,   975,
     976,   977,    14,   978,   979,   980,   981,   982,  1003,  1024,
    1025,  1026,    15,  1027,    16,  1028,  1029,  1030,  1031,  1032,
    1033,   460,   461,    92,    93,    94,  1034,   983,   984,   985,
     986,    17,   987,   988,  1035,   989,   990,   991,  1036,  1037,
     992,  1038,  1044,  1045,  1046,  1047,  1048,  1049,    18,  1056,
     993,   994,   995,   996,   997,   998,  1053,  1059,   999,  1060,
    1061,  1000,  1062,  1063,  1064,  1065,  1066,  1071,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,  1080,   462,  1084,  1085,  1086,
      19,  1130,  1087,  1088,  1089,  1090,  1091,  1092,  1131,    20,
      21,  1093,  1094,  1095,    22,    23,  1004,  1005,  1006,  1007,
    1096,  1008,  1009,  1097,  1010,  1011,  1012,  1098,  1099,  1013,
    1100,  1101,  1102,  1103,  1104,  1105,  1132,  1133,  1152,  1014,
    1015,  1016,  1017,  1018,  1019,  1106,  1154,  1020,  1156,  1134,
    1021,  1396,  1397,  1398,  1399,  1107,  1400,  1401,  1108,  1402,
    1403,  1404,  1109,  1111,  1405,  1112,  1113,  1114,  1115,  1116,
    1117,  1118,  1119,  1135,  1406,  1407,  1408,  1409,  1410,  1411,
    1120,  1121,  1412,  1122,  1123,  1413,  1125,  1126,  1127,  1136,
    1153,  1137,  1165,  1138,  1139,  1167,  1168,  1140,  1141,  1142,
    1143,  1144,  1169,  1145,  1146,  1170,  1147,  1148,  1149,  1171,
    1150,  1151,  1155,  1172,  1158,  1173,  1157,  1177,  1181,  1178,
    1182,  1183,  1184,  1185,  1186,  1187,  1188,  1193,  1189,  1190,
    1191,  1192,  1194,  1195,  1196,  1197,  1198,  1254,  1199,  1257,
    1200,  1201,  1216,  1217,  1222,  1223,  1224,  1244,  1225,  1335,
    1226,  1227,  1232,  1233,  1234,  1235,  1236,  1237,  1238,  1239,
    1240,  1241,  1242,  1243,  1247,  1252,  1253,  1258,  1267,  1269,
    1261,  1273,  1275,  1277,  1279,  1280,  1259,  1281,  1260,  1262,
    1263,  1264,  1282,  1265,  1266,  1268,  1270,  1271,  1272,  1283,
    1274,  1276,  1278,  1373,  1297,  1298,  1312,  1313,  1314,  1315,
    1379,  1316,  1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,
     520,  1325,  1326,  1327,  1328,   332,  1329,  1330,  1467,  1466,
    1129,  1465,  1438,  1331,  1332,   770,   553,  1333,  1374,   758,
    1436,  1435,  1461,  1462,   920,  1464,   871,  1463,   845,   941,
    1437,   364,   876,  1432,   763,   672,   430,  1349,  1350,  1433,
    1434,   352,     0,   739,  1334,  1339,  1340,  1341,  1342,  1343,
    1344,  1345,  1346,  1375,  1376,  1377,  1378,  1383,     0,     0,
     665,  1384,     0,     0,     0,  1385,  1386,  1387,  1388,  1389,
    1390,  1391,  1392,  1393,  1394,  1395,  1416,  1417,  1418,     0,
       0,   515,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   539
};

static const short yycheck[] =
{
     338,   339,   423,     1,     1,    11,    11,   345,     1,   256,
       1,   155,    78,   260,   258,     1,     1,     1,     1,    14,
      15,    16,   258,     8,     9,     1,     1,    12,    10,   256,
      12,     1,     1,   260,    19,     4,     1,   375,   256,   377,
     256,   257,   260,    28,    37,    27,   256,    32,    33,    31,
     260,   258,     1,   391,    39,    48,     1,   258,    43,    44,
      45,   399,    47,   195,   196,     1,   258,     3,    53,   258,
       6,    55,   410,   411,    10,   413,     1,    46,   195,   196,
      49,   256,     1,   421,   422,   260,   424,    72,    73,    25,
      26,    27,    77,   258,   256,    31,   155,     1,   260,    84,
      91,    85,     1,    88,    89,    90,   256,    91,    93,   256,
     260,    96,    97,   260,    50,    91,   256,   258,    54,    55,
     260,   106,   258,    22,   122,   258,    91,   112,   113,   122,
     115,   116,   117,   118,   119,   104,   122,    41,   133,   122,
     885,   886,   887,   888,   889,   130,    91,   122,   258,    85,
     120,    87,    56,   122,   139,   258,   141,   142,   258,   144,
     157,     1,   147,   148,   100,   231,   151,   258,     1,   258,
     154,   157,     5,   122,    78,   155,    80,   162,    82,    83,
     150,   157,    22,   256,   258,     1,   122,   260,   186,   186,
     258,   197,   197,    26,   256,   120,   181,   101,   183,   537,
     186,   259,   187,   186,   259,    38,   191,   192,   193,   194,
     259,   186,   157,   198,   199,   256,     1,    50,   154,   260,
       1,   206,    55,   213,   214,   150,   256,   126,    13,   256,
     260,   256,   168,   260,    67,   260,   259,   186,   157,   259,
     259,    74,   178,     1,   259,   259,    79,   244,    81,    34,
      35,   259,   237,   256,   239,    40,   238,    42,   157,   257,
     245,    94,    20,   259,   257,   250,   257,   186,    26,   244,
     255,   257,   257,   257,   195,   244,    57,    58,    59,    60,
      61,    62,    63,    64,     1,   259,   126,   257,   257,   122,
     258,     1,    50,    51,   127,   244,   259,    55,     1,  1039,
    1040,  1041,   259,   259,     1,   259,   122,   133,   257,   259,
     258,    69,   257,    98,    99,   251,   149,   157,    76,     1,
      37,   257,   107,   108,   105,   244,    23,    24,   161,   259,
     163,   164,   259,    30,    37,   168,   259,    95,   257,     1,
     256,   157,     4,   128,   129,    55,   172,   173,   174,   175,
     176,   259,   259,   257,   259,    37,   259,   259,   257,   140,
     145,   146,   259,   259,   259,   123,    48,   259,   259,    86,
     186,   156,   259,   131,     1,    85,   259,   259,   259,   259,
     165,    91,   259,    86,    46,   259,   259,    49,   259,   259,
     259,   149,   259,   226,   259,   733,    23,    24,   259,   232,
     158,   159,   259,    30,   259,   122,   259,   124,   125,   259,
     243,   244,   109,   110,   111,   259,   259,   114,   259,   122,
     253,   124,   125,   259,   257,   122,   155,   259,   259,   259,
     259,   189,   190,   155,   259,   216,   259,   259,   135,   136,
     122,   259,   104,   258,   154,   259,    94,   259,   259,   259,
     167,   259,   169,   259,   259,   152,   153,   259,   259,   259,
     122,   246,   247,   248,   167,   182,   169,   259,   249,   259,
     259,   259,   257,   259,   155,   259,   257,   259,   133,   182,
     177,   259,   109,   110,   111,     1,   244,   114,   259,   259,
     259,   259,     8,     9,   259,   122,    12,   918,   259,   257,
     259,   133,   259,    19,   259,   259,   259,   224,   135,   136,
     259,   259,    28,    94,   259,   259,    32,    33,   259,   259,
     259,   224,   170,    39,   259,   152,   153,    43,    44,    45,
     256,    47,   259,   133,   251,   252,   259,    53,   259,   259,
     257,   217,   218,   219,   220,   221,   222,   223,   251,   252,
     177,   259,   259,   201,   259,   259,    72,    73,   259,   259,
     257,    77,   256,   259,   195,   195,     1,   215,    84,   133,
     908,   133,    88,    89,    90,   195,   195,    93,   916,   917,
      96,    97,   244,   133,   195,   195,   234,   235,   195,   170,
     106,   195,   240,   241,   242,   243,   112,   113,   195,   115,
     116,   117,   118,   119,   256,   253,    41,   155,   259,   259,
     256,     5,   259,   195,   130,     1,   259,   195,   133,     5,
     201,    56,   155,   139,   133,   141,   142,   195,   144,   195,
     195,   147,   148,   133,   215,   151,   155,   195,   133,   133,
      26,   133,   195,    78,    38,    80,   162,    82,    83,   195,
     195,   133,    38,   234,   235,     1,    50,   155,   195,   240,
     241,   242,   243,   133,    50,   181,   101,   183,   133,    55,
     133,   187,   253,    67,   133,   191,   192,   193,   194,   155,
      74,    67,   198,   199,   133,    79,   133,    81,    74,   195,
     206,   195,   259,    79,   195,    81,   259,   155,   195,   195,
      94,     1,   195,     3,   195,   195,     6,   133,    94,   195,
      10,    57,    58,    59,    60,    61,    62,    63,    64,   259,
     195,   237,   195,   239,   195,    25,    26,    27,   256,   245,
     259,    31,   259,   127,   250,   259,   122,   259,   256,   255,
     155,   127,   259,   155,   155,   259,   259,   259,   259,   143,
      50,   259,   259,   155,    54,    55,   259,   259,   155,   105,
     259,   195,   155,   149,   155,   155,   155,   161,     1,   163,
     164,   259,   259,   155,   259,   161,   259,   163,   164,   259,
      13,   259,   168,   155,   256,    85,   155,    87,   195,   195,
     259,   259,   259,   259,   140,   256,   256,   259,   155,   256,
     100,    34,    35,   259,    20,    21,   256,    40,   195,    42,
     195,   195,   155,   155,   195,   155,   155,   155,   155,   155,
     133,   155,   122,     1,   155,   256,   256,   259,   256,   256,
     259,   195,   226,   256,   259,    51,   256,   256,   256,   256,
     226,   155,    20,   256,   155,   259,   232,   256,    26,   243,
     155,   256,   256,    69,   154,   256,   256,   243,   244,   253,
      76,   256,   155,   259,   256,    98,    99,   253,   168,   133,
     216,   259,    50,    51,   107,   108,   256,    55,   178,    95,
     256,   256,   256,   256,   160,   256,   256,   132,   256,   195,
     133,    69,   259,   259,   259,   128,   129,   259,    76,   259,
       0,     1,   256,   249,   259,     5,   259,   123,   259,   259,
     259,   259,   145,   146,   259,   131,   155,    95,   259,   155,
     155,   155,    22,   156,   259,   155,    26,   259,   133,    29,
     259,   259,   165,   259,   259,   259,    36,   259,   259,   259,
     259,   259,   259,   259,   256,   123,   256,   155,   256,   256,
     259,   251,    52,   131,   256,   171,   259,   256,   256,   256,
     256,   256,   256,   155,   256,    65,    66,   256,    68,   256,
     256,   149,   256,   256,   190,    75,   256,   256,   256,   256,
     158,   159,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,    92,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   102,   256,   104,   256,   256,   256,   256,   256,
     256,   189,   190,   246,   247,   248,   256,   202,   203,   204,
     205,   121,   207,   208,   256,   210,   211,   212,   256,   256,
     215,   256,   256,   256,   256,   256,   256,   256,   138,   256,
     225,   226,   227,   228,   229,   230,   259,   195,   233,   195,
     259,   236,   195,   195,   195,   195,   195,   195,   256,   155,
     259,   155,   256,   259,   155,   155,   244,   256,   256,   256,
     170,   155,   256,   256,   256,   256,   256,   256,   155,   179,
     180,   256,   256,   256,   184,   185,   202,   203,   204,   205,
     256,   207,   208,   256,   210,   211,   212,   256,   256,   215,
     256,   256,   256,   256,   256,   256,   155,   256,   155,   225,
     226,   227,   228,   229,   230,   259,   155,   233,   155,   256,
     236,   202,   203,   204,   205,   259,   207,   208,   259,   210,
     211,   212,   259,   259,   215,   259,   259,   259,   259,   259,
     259,   259,   259,   256,   225,   226,   227,   228,   229,   230,
     259,   259,   233,   259,   259,   236,   259,   259,   259,   256,
     259,   256,   133,   256,   256,   133,   133,   256,   256,   256,
     256,   256,   133,   256,   256,   133,   256,   256,   256,   155,
     256,   256,   256,   133,   256,   133,   259,   256,   195,   155,
     155,   155,   195,   195,   195,   155,   259,   133,   155,   155,
     155,   155,   155,   155,   155,   256,   256,   200,   256,   195,
     256,   256,   256,   256,   256,   256,   256,   160,   256,   132,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   155,   155,   155,
     259,   155,   259,   155,   256,   256,   195,   256,   195,   195,
     195,   195,   256,   195,   195,   195,   195,   195,   195,   256,
     195,   195,   195,   133,   256,   256,   256,   256,   256,   256,
     132,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     275,   256,   256,   256,   256,    71,   256,   256,  1460,  1441,
     816,  1439,  1372,   256,   256,   496,   312,   256,  1256,   463,
    1357,  1355,  1420,  1422,   608,  1425,   558,  1423,   526,   642,
    1370,   124,   566,  1348,   486,   370,   184,  1206,  1208,  1352,
    1354,    95,    -1,   438,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,    -1,    -1,
     358,   256,    -1,    -1,    -1,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,    -1,
      -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   291
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,   262,     0,     1,     5,    22,    26,    29,    36,    52,
      65,    66,    68,    75,    92,   102,   104,   121,   138,   170,
     179,   180,   184,   185,   263,   268,   273,   287,   293,   308,
     345,   364,   377,   403,   410,   420,   429,   459,   469,   475,
     479,   489,   553,   569,   590,   256,   257,   258,   258,   346,
     430,   470,   258,   480,   258,   554,   378,   460,   365,   258,
     258,   309,   404,   258,   258,   411,   421,     1,    37,    48,
     122,   288,   289,   290,   291,   292,     1,    13,    34,    35,
      40,    42,    98,    99,   107,   108,   128,   129,   145,   146,
     156,   165,   246,   247,   248,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   155,   347,   351,   155,   431,
     435,   258,     1,    91,   476,   477,   478,   258,     1,     8,
       9,    12,    19,    28,    32,    33,    39,    43,    44,    45,
      47,    53,    72,    73,    77,    84,    88,    89,    90,    93,
      96,    97,   106,   112,   113,   115,   116,   117,   118,   119,
     130,   139,   141,   142,   144,   147,   148,   151,   162,   181,
     183,   187,   191,   192,   193,   194,   198,   199,   206,   237,
     239,   245,   250,   255,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   544,   548,   549,   550,   551,
     552,   258,   258,   258,   258,     1,    57,    58,    59,    60,
      61,    62,    63,    64,   105,   140,   216,   249,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,     1,   120,   150,   269,   270,   271,   272,   155,
     310,   314,   258,     1,    41,    56,    78,    80,    82,    83,
     101,   591,   592,   593,   594,   595,   596,   597,   598,   599,
       1,    37,    86,   122,   124,   125,   167,   169,   182,   224,
     251,   252,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   258,   258,   256,   259,   259,
     259,   257,   289,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   257,   571,   258,   258,     1,    91,   157,   471,   472,
     473,   474,   259,   257,   477,     1,   122,   157,   186,   481,
     485,   486,   487,   488,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   545,   259,   541,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   257,
     491,     1,     4,    46,    49,   104,   122,   244,   555,   556,
     557,   558,   559,   563,   564,   565,     1,    20,    26,    50,
      51,    55,    69,    76,    95,   123,   131,   149,   158,   159,
     189,   190,   244,   379,   380,   381,   382,   383,   384,   385,
     386,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,     1,   157,   186,   244,   461,   465,   466,   467,   468,
       1,    55,    85,    91,   154,   366,   370,   371,   372,   375,
     376,   256,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   257,   295,   256,   259,   259,   257,
     270,   258,     1,    22,   126,   157,   405,   406,   407,   408,
     409,   259,   259,   259,   259,   259,   259,   259,   257,   592,
     256,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   257,   275,     1,   122,   186,   244,   412,   413,
     414,   415,   416,     1,   122,   186,   422,   423,   424,   425,
     155,   155,   155,   256,   195,   133,   133,   195,   195,   133,
     265,   265,   133,   133,   195,   195,   133,   265,   195,   195,
     195,   195,   195,   256,     1,    23,    24,    30,   109,   110,
     111,   114,   122,   135,   136,   152,   153,   177,   348,   349,
     350,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,     1,     3,     6,    10,    25,    26,    27,
      31,    50,    54,    55,    85,    87,   100,   122,   154,   168,
     178,   251,   432,   433,   434,   436,   437,   438,   439,   440,
     441,   442,   443,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   259,   259,   257,   472,   155,   256,   259,   259,
     482,   257,   486,   195,   265,   195,   265,   133,   155,   133,
     195,   195,   195,   133,   155,   195,   133,   133,   133,   195,
     265,   195,   195,   133,   155,   195,   133,   133,   265,   133,
     133,   155,   133,   133,   195,   195,   259,   195,   259,   265,
     265,   195,   265,   155,   195,   195,   195,   196,   195,   196,
     195,   195,   265,   265,   133,   267,   265,   195,   195,   195,
     195,   256,   566,   259,   259,   560,   259,   259,   257,   556,
     256,   259,   259,   259,   259,   387,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   257,   380,   259,
     462,   259,   257,   466,   256,   367,   259,   259,   259,   257,
     371,   155,   155,   155,   155,   155,   155,   155,   155,   217,
     218,   219,   220,   221,   222,   223,   155,   155,   195,   256,
     155,   155,   256,     1,     5,    26,    38,    50,    55,    67,
      74,    79,    81,    94,   122,   127,   149,   161,   163,   164,
     168,   226,   232,   243,   244,   253,   311,   312,   313,   315,
     316,   317,   318,   319,   320,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     256,   259,   259,   259,   257,   406,   195,   195,   195,   155,
     195,   195,   265,   256,   155,   195,   155,   155,   155,   155,
     155,   155,   133,   155,   155,   256,   256,   259,   417,   259,
     257,   413,   256,   259,   426,   257,   423,   256,   256,   256,
     256,   256,   256,   256,   256,   172,   173,   174,   175,   176,
     264,   265,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   257,
     349,   256,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   444,   259,   259,   259,   259,   259,   259,   259,   259,
     257,   433,   155,   155,   256,   256,   155,   155,   259,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   202,   203,   204,   205,   207,   208,   210,
     211,   212,   215,   225,   226,   227,   228,   229,   230,   233,
     236,   546,   547,   256,   202,   203,   204,   205,   207,   208,
     210,   211,   212,   215,   225,   226,   227,   228,   229,   230,
     233,   236,   542,   543,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,    14,
      15,    16,   266,   267,   256,   256,   256,   256,   256,   256,
     259,   265,   195,   259,   155,   155,   256,   195,   155,   195,
     195,   259,   195,   195,   195,   195,   195,   155,   133,   155,
     155,   195,   155,   256,   155,   259,   155,   256,   259,   155,
     155,   133,   373,   374,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   259,   259,   259,   259,
     339,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   321,   259,   259,   259,   257,   312,
     155,   155,   155,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   155,   259,   155,   256,   155,   259,   256,   264,
     264,   264,   264,   264,   133,   133,   265,   133,   133,   133,
     133,   155,   133,   133,   265,   265,   267,   256,   155,   213,
     214,   195,   155,   155,   195,   195,   195,   155,   259,   155,
     155,   155,   155,   133,   155,   155,   155,   256,   256,   256,
     256,   256,   160,   483,   484,   256,   260,   256,   260,   266,
     266,   266,    11,   197,   567,   568,   256,   256,    11,   197,
     561,   562,   256,   256,   256,   256,   256,   256,   132,   388,
     389,   391,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   160,   463,   464,   256,    78,   231,
     368,   369,   256,   256,   200,   256,   260,   195,   155,   195,
     195,   259,   195,   195,   195,   195,   195,   155,   195,   155,
     195,   195,   195,   155,   195,   259,   195,   155,   195,   256,
     256,   256,   256,   256,    94,   170,   201,   215,   234,   235,
     240,   241,   242,   243,   253,   418,   419,   256,   256,    94,
     170,   201,   215,   234,   235,   240,   241,   242,   243,   253,
     427,   428,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   132,   445,   446,   448,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   260,   547,
     543,   256,   260,   256,   260,   390,   256,   260,    20,    21,
      51,    69,    76,    95,   123,   131,   171,   190,   392,   256,
     260,   256,   260,   133,   374,   256,   256,   256,   256,   132,
     340,   341,   343,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   202,   203,   204,   205,
     207,   208,   210,   211,   212,   215,   225,   226,   227,   228,
     229,   230,   233,   236,   322,   323,   256,   256,   256,   256,
     260,   256,   260,   447,   256,   260,    10,    12,    27,    31,
     238,   449,   484,   568,   562,   392,   389,   464,   369,   342,
     256,   260,     5,    38,    50,    67,    74,    79,    81,    94,
     127,   143,   161,   163,   164,   226,   243,   253,   344,   256,
     260,   419,   428,   449,   446,   344,   341,   323
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1

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
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");			\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)           \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#define YYLEX	yylex ()

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
# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)
/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

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
  register const char *yys = yystr;

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
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*-----------------------------.
| Print this symbol on YYOUT.  |
`-----------------------------*/

static void
#if defined (__STDC__) || defined (__cplusplus)
yysymprint (FILE* yyout, int yytype, YYSTYPE yyvalue)
#else
yysymprint (yyout, yytype, yyvalue)
    FILE* yyout;
    int yytype;
    YYSTYPE yyvalue;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvalue;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyout, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyout, yytoknum[yytype], yyvalue);
# endif
    }
  else
    YYFPRINTF (yyout, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyout, ")");
}
#endif /* YYDEBUG. */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
#if defined (__STDC__) || defined (__cplusplus)
yydestruct (int yytype, YYSTYPE yyvalue)
#else
yydestruct (yytype, yyvalue)
    int yytype;
    YYSTYPE yyvalue;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvalue;

  switch (yytype)
    {
      default:
        break;
    }
}



/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
#  define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL
# else
#  define YYPARSE_PARAM_ARG YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
# endif
#else /* !YYPARSE_PARAM */
# define YYPARSE_PARAM_ARG
# define YYPARSE_PARAM_DECL
#endif /* !YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
# ifdef YYPARSE_PARAM
int yyparse (void *);
# else
int yyparse (void);
# endif
#endif


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of parse errors so far.  */
int yynerrs;


int
yyparse (YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yychar1 = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



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

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
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

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with.  */

  if (yychar <= 0)		/* This means end of input.  */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more.  */

      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yychar1 = YYTRANSLATE (yychar);

      /* We have to keep this `#if YYDEBUG', since we use variables
	 which are defined only if `YYDEBUG' is set.  */
      YYDPRINTF ((stderr, "Next token is "));
      YYDSYMPRINT ((stderr, yychar1, yylval));
      YYDPRINTF ((stderr, "\n"));
    }

  /* If the proper action on seeing token YYCHAR1 is to reduce or to
     detect an error, take that action.  */
  yyn += yychar1;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yychar1)
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

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %d (%s), ",
	      yychar, yytname[yychar1]));

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



#if YYDEBUG
  /* We have to keep this `#if YYDEBUG', since we use variables which
     are defined only if `YYDEBUG' is set.  */
  if (yydebug)
    {
      int yyi;

      YYFPRINTF (stderr, "Reducing via rule %d (line %d), ",
		 yyn - 1, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (yyi = yyprhs[yyn]; yyrhs[yyi] >= 0; yyi++)
	YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
      YYFPRINTF (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif
  switch (yyn)
    {
        case 26:
#line 411 "ircd_parser.y"
    { yyval.number = 0; }
    break;

  case 28:
#line 413 "ircd_parser.y"
    {
			yyval.number = yyvsp[-1].number + yyvsp[0].number;
		}
    break;

  case 29:
#line 417 "ircd_parser.y"
    {
			yyval.number = yyvsp[-2].number + yyvsp[0].number;
		}
    break;

  case 30:
#line 421 "ircd_parser.y"
    {
			yyval.number = yyvsp[-2].number * 60 + yyvsp[0].number;
		}
    break;

  case 31:
#line 425 "ircd_parser.y"
    {
			yyval.number = yyvsp[-2].number * 60 * 60 + yyvsp[0].number;
		}
    break;

  case 32:
#line 429 "ircd_parser.y"
    {
			yyval.number = yyvsp[-2].number * 60 * 60 * 24 + yyvsp[0].number;
		}
    break;

  case 33:
#line 433 "ircd_parser.y"
    {
			yyval.number = yyvsp[-2].number * 60 * 60 * 24 * 7 + yyvsp[0].number;
		}
    break;

  case 34:
#line 438 "ircd_parser.y"
    { yyval.number = 0; }
    break;

  case 36:
#line 439 "ircd_parser.y"
    { yyval.number = yyvsp[-1].number + yyvsp[0].number; }
    break;

  case 37:
#line 440 "ircd_parser.y"
    { yyval.number = yyvsp[-2].number + yyvsp[0].number; }
    break;

  case 38:
#line 441 "ircd_parser.y"
    { yyval.number = yyvsp[-2].number * 1024 + yyvsp[0].number; }
    break;

  case 39:
#line 442 "ircd_parser.y"
    { yyval.number = yyvsp[-2].number * 1024 * 1024 + yyvsp[0].number; }
    break;

  case 46:
#line 456 "ircd_parser.y"
    {
}
    break;

  case 47:
#line 460 "ircd_parser.y"
    {
}
    break;

  case 63:
#line 480 "ircd_parser.y"
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
#line 514 "ircd_parser.y"
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
#line 574 "ircd_parser.y"
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
#line 588 "ircd_parser.y"
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
#line 606 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
}
    break;

  case 68:
#line 615 "ircd_parser.y"
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
#line 629 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
}
    break;

  case 70:
#line 638 "ircd_parser.y"
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
#line 666 "ircd_parser.y"
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
#line 696 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    recalc_fdlimit(NULL);

    if (yyvsp[-1].number < MAXCLIENTS_MIN)
    {
      char buf[IRCD_BUFSIZE];
      ircsprintf(buf, "MAXCLIENTS too low, setting to %d", MAXCLIENTS_MIN);
      yyerror(buf);
    }
    else if (yyvsp[-1].number > MAXCLIENTS_MAX)
    {
      char buf[IRCD_BUFSIZE];
      ircsprintf(buf, "MAXCLIENTS too high, setting to %d", MAXCLIENTS_MAX);
      yyerror(buf);
    }
    else
      ServerInfo.max_clients = yyvsp[-1].number;
  }
}
    break;

  case 73:
#line 719 "ircd_parser.y"
    {
  if (ypass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 81:
#line 734 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
}
    break;

  case 82:
#line 743 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
}
    break;

  case 83:
#line 752 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
}
    break;

  case 100:
#line 779 "ircd_parser.y"
    {
                        }
    break;

  case 101:
#line 783 "ircd_parser.y"
    {
                        }
    break;

  case 102:
#line 787 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.userlog, yylval.string,
            sizeof(ConfigLoggingEntry.userlog));
}
    break;

  case 103:
#line 794 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.failed_operlog, yylval.string,
            sizeof(ConfigLoggingEntry.failed_operlog));
}
    break;

  case 104:
#line 801 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.operlog, yylval.string,
            sizeof(ConfigLoggingEntry.operlog));
}
    break;

  case 105:
#line 808 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.operspylog, yylval.string,
            sizeof(ConfigLoggingEntry.operspylog));
}
    break;

  case 106:
#line 815 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.glinelog, yylval.string,
            sizeof(ConfigLoggingEntry.glinelog));
}
    break;

  case 107:
#line 822 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.klinelog, yylval.string,
            sizeof(ConfigLoggingEntry.klinelog));
}
    break;

  case 108:
#line 829 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.ioerrlog, yylval.string,
            sizeof(ConfigLoggingEntry.ioerrlog));
}
    break;

  case 109:
#line 836 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.killlog, yylval.string,
            sizeof(ConfigLoggingEntry.killlog));
}
    break;

  case 110:
#line 843 "ircd_parser.y"
    { 
  if (ypass == 2)
    set_log_level(L_CRIT);
}
    break;

  case 111:
#line 847 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_ERROR);
}
    break;

  case 112:
#line 851 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_WARN);
}
    break;

  case 113:
#line 855 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_NOTICE);
}
    break;

  case 114:
#line 859 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_TRACE);
}
    break;

  case 115:
#line 863 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_INFO);
}
    break;

  case 116:
#line 867 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_DEBUG);
}
    break;

  case 117:
#line 873 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 118:
#line 882 "ircd_parser.y"
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
#line 895 "ircd_parser.y"
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
#line 987 "ircd_parser.y"
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
#line 999 "ircd_parser.y"
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
#line 1011 "ircd_parser.y"
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
#line 1045 "ircd_parser.y"
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
#line 1057 "ircd_parser.y"
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
#line 1068 "ircd_parser.y"
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
#line 1110 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 154:
#line 1119 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 158:
#line 1126 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 159:
#line 1130 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 160:
#line 1134 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 161:
#line 1138 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 162:
#line 1142 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 163:
#line 1146 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 164:
#line 1150 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 165:
#line 1154 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 166:
#line 1158 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 167:
#line 1162 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 168:
#line 1166 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 169:
#line 1170 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 170:
#line 1174 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 171:
#line 1178 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 172:
#line 1182 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 173:
#line 1186 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 174:
#line 1190 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 175:
#line 1194 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 176:
#line 1200 "ircd_parser.y"
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
#line 1211 "ircd_parser.y"
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
#line 1222 "ircd_parser.y"
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
#line 1233 "ircd_parser.y"
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
#line 1244 "ircd_parser.y"
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
#line 1255 "ircd_parser.y"
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
#line 1266 "ircd_parser.y"
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
#line 1277 "ircd_parser.y"
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
#line 1288 "ircd_parser.y"
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
#line 1299 "ircd_parser.y"
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
#line 1310 "ircd_parser.y"
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
#line 1321 "ircd_parser.y"
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
#line 1332 "ircd_parser.y"
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
#line 1343 "ircd_parser.y"
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
#line 1354 "ircd_parser.y"
    {
}
    break;

  case 194:
#line 1358 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 196:
#line 1359 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 198:
#line 1362 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)yy_aconf->port &= ~OPER_FLAG_GLOBAL_KILL;
    else yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
  }
}
    break;

  case 199:
#line 1369 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTE;
    else yy_aconf->port |= OPER_FLAG_REMOTE;
  }
}
    break;

  case 200:
#line 1376 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_K;
    else yy_aconf->port |= OPER_FLAG_K;
  }
}
    break;

  case 201:
#line 1383 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_UNKLINE;
    else yy_aconf->port |= OPER_FLAG_UNKLINE;
  } 
}
    break;

  case 202:
#line 1390 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_X;
    else yy_aconf->port |= OPER_FLAG_X;
  }
}
    break;

  case 203:
#line 1397 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_GLINE;
    else yy_aconf->port |= OPER_FLAG_GLINE;
  }
}
    break;

  case 204:
#line 1404 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_DIE;
    else yy_aconf->port |= OPER_FLAG_DIE;
  }
}
    break;

  case 205:
#line 1411 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REHASH;
    else yy_aconf->port |= OPER_FLAG_REHASH;
  }
}
    break;

  case 206:
#line 1418 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_ADMIN;
    else yy_aconf->port |= OPER_FLAG_ADMIN;
  }
}
    break;

  case 207:
#line 1425 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_ADMIN;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_ADMIN;
  }
}
    break;

  case 208:
#line 1432 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_N;
    else yy_aconf->port |= OPER_FLAG_N;
  }
}
    break;

  case 209:
#line 1439 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPERWALL;
    else yy_aconf->port |= OPER_FLAG_OPERWALL;
  }
}
    break;

  case 210:
#line 1446 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPER_SPY;
    else yy_aconf->port |= OPER_FLAG_OPER_SPY;
  }
}
    break;

  case 211:
#line 1453 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_OPER;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_OPER;
  }
}
    break;

  case 212:
#line 1460 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTEBAN;
    else yy_aconf->port |= OPER_FLAG_REMOTEBAN;
  }
}
    break;

  case 213:
#line 1467 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) ClearConfEncrypted(yy_aconf);
    else SetConfEncrypted(yy_aconf);
  }
}
    break;

  case 214:
#line 1480 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = &yy_conf->conf.ClassItem;
  }
}
    break;

  case 215:
#line 1487 "ircd_parser.y"
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
#line 1539 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 235:
#line 1548 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 236:
#line 1557 "ircd_parser.y"
    {
  if (ypass == 1)
    PingFreq(yy_class) = yyvsp[-1].number;
}
    break;

  case 237:
#line 1563 "ircd_parser.y"
    {
  if (ypass == 1)
    PingWarning(yy_class) = yyvsp[-1].number;
}
    break;

  case 238:
#line 1569 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxPerIp(yy_class) = yyvsp[-1].number;
}
    break;

  case 239:
#line 1575 "ircd_parser.y"
    {
  if (ypass == 1)
    ConFreq(yy_class) = yyvsp[-1].number;
}
    break;

  case 240:
#line 1581 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxTotal(yy_class) = yyvsp[-1].number;
}
    break;

  case 241:
#line 1587 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxGlobal(yy_class) = yyvsp[-1].number;
}
    break;

  case 242:
#line 1593 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxLocal(yy_class) = yyvsp[-1].number;
}
    break;

  case 243:
#line 1599 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxIdent(yy_class) = yyvsp[-1].number;
}
    break;

  case 244:
#line 1605 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxSendq(yy_class) = yyvsp[-1].number;
}
    break;

  case 245:
#line 1611 "ircd_parser.y"
    {
  if (ypass == 1)
    CidrBitlenIPV4(yy_class) = yyvsp[-1].number;
}
    break;

  case 246:
#line 1617 "ircd_parser.y"
    {
  if (ypass == 1)
    CidrBitlenIPV6(yy_class) = yyvsp[-1].number;
}
    break;

  case 247:
#line 1623 "ircd_parser.y"
    {
  if (ypass == 1)
    NumberPerCidr(yy_class) = yyvsp[-1].number;
}
    break;

  case 248:
#line 1632 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 249:
#line 1639 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 250:
#line 1648 "ircd_parser.y"
    {
}
    break;

  case 254:
#line 1653 "ircd_parser.y"
    {
  if (ypass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 255:
#line 1657 "ircd_parser.y"
    {
  if (ypass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 266:
#line 1670 "ircd_parser.y"
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
    add_listener(yyvsp[0].number, listener_address, listener_flags);
    listener_flags = 0;
  }
}
    break;

  case 267:
#line 1685 "ircd_parser.y"
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

    for (i = yyvsp[-2].number; i <= yyvsp[0].number; ++i)
      add_listener(i, listener_address, listener_flags);

    listener_flags = 0;
  }
}
    break;

  case 268:
#line 1707 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 269:
#line 1716 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 270:
#line 1728 "ircd_parser.y"
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
#line 1740 "ircd_parser.y"
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
#line 1805 "ircd_parser.y"
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
#line 1842 "ircd_parser.y"
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
#line 1855 "ircd_parser.y"
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
#line 1866 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 295:
#line 1875 "ircd_parser.y"
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
#line 1886 "ircd_parser.y"
    {
}
    break;

  case 300:
#line 1890 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 302:
#line 1891 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 304:
#line 1894 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_SPOOF_NOTICE;
    else yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
  }

}
    break;

  case 305:
#line 1902 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NOLIMIT;
    else yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
  }
}
    break;

  case 306:
#line 1909 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTKLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
  } 
}
    break;

  case 307:
#line 1916 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_IDENTD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
  }
}
    break;

  case 308:
#line 1923 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_CAN_FLOOD;
    else yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
  }
}
    break;

  case 309:
#line 1930 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_IDLE_LINED;
    else yy_aconf->flags |= CONF_FLAGS_IDLE_LINED;
  }
}
    break;

  case 310:
#line 1937 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NO_TILDE;
    else yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
  } 
}
    break;

  case 311:
#line 1944 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTGLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
  } 
}
    break;

  case 312:
#line 1951 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTRESV;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
  }
}
    break;

  case 313:
#line 1958 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_PASSWORD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
  }
}
    break;

  case 314:
#line 1967 "ircd_parser.y"
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
#line 1978 "ircd_parser.y"
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
#line 1989 "ircd_parser.y"
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
#line 2000 "ircd_parser.y"
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
#line 2011 "ircd_parser.y"
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
#line 2022 "ircd_parser.y"
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
#line 2034 "ircd_parser.y"
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
#line 2053 "ircd_parser.y"
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
#line 2063 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = yyvsp[-1].number;
  }
}
    break;

  case 323:
#line 2072 "ircd_parser.y"
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
#line 2087 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 325:
#line 2094 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 332:
#line 2106 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 333:
#line 2115 "ircd_parser.y"
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
#line 2130 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 335:
#line 2143 "ircd_parser.y"
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
#line 2151 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 343:
#line 2162 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 344:
#line 2171 "ircd_parser.y"
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
#line 2193 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = 0;
}
    break;

  case 349:
#line 2200 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 350:
#line 2204 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TKLINE;
}
    break;

  case 351:
#line 2208 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 352:
#line 2212 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 353:
#line 2216 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TXLINE;
}
    break;

  case 354:
#line 2220 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 355:
#line 2224 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 356:
#line 2228 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TRESV;
}
    break;

  case 357:
#line 2232 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 358:
#line 2236 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 359:
#line 2240 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 360:
#line 2249 "ircd_parser.y"
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
#line 2258 "ircd_parser.y"
    {
  yy_conf = NULL;
  yy_match_item = NULL;
}
    break;

  case 367:
#line 2267 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 368:
#line 2276 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = 0;
}
    break;

  case 372:
#line 2283 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 373:
#line 2287 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TKLINE;
}
    break;

  case 374:
#line 2291 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 375:
#line 2295 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 376:
#line 2299 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TXLINE;
}
    break;

  case 377:
#line 2303 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 378:
#line 2307 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 379:
#line 2311 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TRESV;
}
    break;

  case 380:
#line 2315 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 381:
#line 2319 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 382:
#line 2323 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 383:
#line 2332 "ircd_parser.y"
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
#line 2350 "ircd_parser.y"
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

  case 409:
#line 2501 "ircd_parser.y"
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
#line 2513 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 411:
#line 2522 "ircd_parser.y"
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
#line 2548 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yyvsp[-1].string[0] == ':')
      yyerror("Server passwords cannot begin with a colon");
    else if (strchr(yyvsp[-1].string, ' ') != NULL)
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
#line 2566 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yyvsp[-1].string[0] == ':')
      yyerror("Server passwords cannot begin with a colon");
    else if (strchr(yyvsp[-1].string, ' ') != NULL)
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
#line 2584 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->port = yyvsp[-1].number;
}
    break;

  case 415:
#line 2590 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 416:
#line 2594 "ircd_parser.y"
    {
#ifdef IPV6
  if (ypass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 417:
#line 2602 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->fakename);
    DupString(yy_aconf->fakename, yylval.string);
  }
}
    break;

  case 418:
#line 2611 "ircd_parser.y"
    {
}
    break;

  case 422:
#line 2615 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 424:
#line 2616 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 426:
#line 2619 "ircd_parser.y"
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
#line 2630 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfCryptLink(yy_aconf);
    else SetConfCryptLink(yy_aconf);
  }
}
    break;

  case 428:
#line 2637 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfAllowAutoConn(yy_aconf);
    else SetConfAllowAutoConn(yy_aconf);
  }
}
    break;

  case 429:
#line 2644 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfAwayBurst(yy_aconf);
    else SetConfAwayBurst(yy_aconf);
  }
}
    break;

  case 430:
#line 2651 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfTopicBurst(yy_aconf);
    else SetConfTopicBurst(yy_aconf);
  }
}
    break;

  case 431:
#line 2661 "ircd_parser.y"
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
#line 2702 "ircd_parser.y"
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
#line 2713 "ircd_parser.y"
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
#line 2724 "ircd_parser.y"
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
#line 2739 "ircd_parser.y"
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
#line 2750 "ircd_parser.y"
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
#line 2763 "ircd_parser.y"
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
#line 2776 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 439:
#line 2785 "ircd_parser.y"
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
#line 2820 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 441:
#line 2827 "ircd_parser.y"
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
#line 2883 "ircd_parser.y"
    {
}
    break;

  case 446:
#line 2888 "ircd_parser.y"
    {
  if (ypass == 2)
    regex_ban = 1;
}
    break;

  case 453:
#line 2897 "ircd_parser.y"
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
#line 2916 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 455:
#line 2925 "ircd_parser.y"
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
#line 2934 "ircd_parser.y"
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
#line 2950 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 463:
#line 2959 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->reason);
    DupString(yy_aconf->reason, yylval.string);
  }
}
    break;

  case 469:
#line 2976 "ircd_parser.y"
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
#line 2997 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 471:
#line 3004 "ircd_parser.y"
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
#line 3038 "ircd_parser.y"
    {
}
    break;

  case 476:
#line 3043 "ircd_parser.y"
    {
  if (ypass == 2)
    regex_ban = 1;
}
    break;

  case 483:
#line 3052 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 484:
#line 3058 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 544:
#line 3102 "ircd_parser.y"
    {
  ConfigFileEntry.max_watch = yylval.number;
}
    break;

  case 545:
#line 3107 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = yyvsp[-1].number;
}
    break;

  case 546:
#line 3112 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = yyvsp[-1].number;
}
    break;

  case 547:
#line 3117 "ircd_parser.y"
    {
  ConfigFileEntry.burst_away = yylval.number;
}
    break;

  case 548:
#line 3122 "ircd_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 549:
#line 3127 "ircd_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 550:
#line 3132 "ircd_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 551:
#line 3137 "ircd_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = yyvsp[-1].number;
}
    break;

  case 552:
#line 3142 "ircd_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 553:
#line 3147 "ircd_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 554:
#line 3152 "ircd_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 555:
#line 3157 "ircd_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 556:
#line 3162 "ircd_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 557:
#line 3167 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_time = yyvsp[-1].number; 
}
    break;

  case 558:
#line 3172 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_changes = yyvsp[-1].number;
}
    break;

  case 559:
#line 3177 "ircd_parser.y"
    {
  ConfigFileEntry.max_accept = yyvsp[-1].number;
}
    break;

  case 560:
#line 3182 "ircd_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = yyvsp[-1].number;
}
    break;

  case 561:
#line 3187 "ircd_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = yyvsp[-1].number;
}
    break;

  case 562:
#line 3192 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.ts_max_delta = yyvsp[-1].number;
}
    break;

  case 563:
#line 3198 "ircd_parser.y"
    {
  if ((yyvsp[-1].number > 0) && ypass == 1)
  {
    ilog(L_CRIT, "You haven't read your config file properly.");
    ilog(L_CRIT, "There is a line in the example conf that will kill your server if not removed.");
    ilog(L_CRIT, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
    break;

  case 564:
#line 3209 "ircd_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 565:
#line 3214 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 566:
#line 3223 "ircd_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 567:
#line 3228 "ircd_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 568:
#line 3233 "ircd_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 569:
#line 3238 "ircd_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 570:
#line 3243 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 571:
#line 3246 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 572:
#line 3251 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 573:
#line 3254 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 574:
#line 3259 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait = yyvsp[-1].number;
}
    break;

  case 575:
#line 3264 "ircd_parser.y"
    {
  ConfigFileEntry.caller_id_wait = yyvsp[-1].number;
}
    break;

  case 576:
#line 3269 "ircd_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 577:
#line 3274 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = yyvsp[-1].number;
}
    break;

  case 578:
#line 3279 "ircd_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 579:
#line 3284 "ircd_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 580:
#line 3289 "ircd_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 581:
#line 3294 "ircd_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 582:
#line 3299 "ircd_parser.y"
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
#line 3310 "ircd_parser.y"
    {
  ConfigFileEntry.idletime = yyvsp[-1].number;
}
    break;

  case 584:
#line 3315 "ircd_parser.y"
    {
  ConfigFileEntry.dots_in_ident = yyvsp[-1].number;
}
    break;

  case 585:
#line 3320 "ircd_parser.y"
    {
  ConfigFileEntry.max_targets = yyvsp[-1].number;
}
    break;

  case 586:
#line 3325 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.servlink_path);
    DupString(ConfigFileEntry.servlink_path, yylval.string);
  }
}
    break;

  case 587:
#line 3334 "ircd_parser.y"
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
#line 3366 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    ConfigFileEntry.compression_level = yyvsp[-1].number;
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
#line 3384 "ircd_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 590:
#line 3389 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 591:
#line 3398 "ircd_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 592:
#line 3403 "ircd_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 593:
#line 3408 "ircd_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 594:
#line 3413 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 598:
#line 3419 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 599:
#line 3422 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 600:
#line 3425 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 601:
#line 3428 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 602:
#line 3431 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 603:
#line 3434 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 604:
#line 3437 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 605:
#line 3440 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 606:
#line 3443 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 607:
#line 3446 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 608:
#line 3449 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 609:
#line 3452 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 610:
#line 3455 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 611:
#line 3458 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 612:
#line 3461 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 613:
#line 3464 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 614:
#line 3467 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 615:
#line 3470 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 616:
#line 3475 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 620:
#line 3481 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 621:
#line 3484 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 622:
#line 3487 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 623:
#line 3490 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 624:
#line 3493 "ircd_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 625:
#line 3496 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 626:
#line 3499 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 627:
#line 3502 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 628:
#line 3505 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 629:
#line 3508 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 630:
#line 3511 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 631:
#line 3514 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 632:
#line 3517 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 633:
#line 3520 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 634:
#line 3523 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 635:
#line 3526 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 636:
#line 3529 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 637:
#line 3532 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 638:
#line 3537 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = yyvsp[-1].number;
}
    break;

  case 639:
#line 3542 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = yyvsp[-1].number;
}
    break;

  case 640:
#line 3547 "ircd_parser.y"
    {
  ConfigFileEntry.default_floodcount = yyvsp[-1].number;
}
    break;

  case 641:
#line 3552 "ircd_parser.y"
    {
  ConfigFileEntry.client_flood = yyvsp[-1].number;
}
    break;

  case 642:
#line 3557 "ircd_parser.y"
    {
  ConfigFileEntry.dot_in_ip6_addr = yylval.number;
}
    break;

  case 643:
#line 3565 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = &yy_conf->conf.AccessItem;
  }
}
    break;

  case 644:
#line 3572 "ircd_parser.y"
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
#line 3598 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 655:
#line 3604 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_time = yyvsp[-1].number;
}
    break;

  case 656:
#line 3610 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 660:
#line 3616 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 661:
#line 3620 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 662:
#line 3626 "ircd_parser.y"
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
#line 3660 "ircd_parser.y"
    {
  if (ypass == 2)  
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 664:
#line 3669 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 665:
#line 3673 "ircd_parser.y"
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
#line 3720 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 669:
#line 3724 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 692:
#line 3748 "ircd_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 693:
#line 3753 "ircd_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 694:
#line 3758 "ircd_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 695:
#line 3763 "ircd_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 696:
#line 3768 "ircd_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 697:
#line 3773 "ircd_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 698:
#line 3778 "ircd_parser.y"
    {
  ConfigChannel.knock_delay = yyvsp[-1].number;
}
    break;

  case 699:
#line 3783 "ircd_parser.y"
    {
  ConfigChannel.knock_delay_channel = yyvsp[-1].number;
}
    break;

  case 700:
#line 3788 "ircd_parser.y"
    {
  ConfigChannel.max_chans_per_user = yyvsp[-1].number;
}
    break;

  case 701:
#line 3793 "ircd_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 702:
#line 3798 "ircd_parser.y"
    {
  ConfigChannel.max_bans = yyvsp[-1].number;
}
    break;

  case 703:
#line 3803 "ircd_parser.y"
    {
  ConfigChannel.default_split_user_count = yyvsp[-1].number;
}
    break;

  case 704:
#line 3808 "ircd_parser.y"
    {
  ConfigChannel.default_split_server_count = yyvsp[-1].number;
}
    break;

  case 705:
#line 3813 "ircd_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 706:
#line 3818 "ircd_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 707:
#line 3823 "ircd_parser.y"
    {
  ConfigChannel.burst_topicwho = yylval.number;
}
    break;

  case 708:
#line 3828 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 709:
#line 3833 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 721:
#line 3852 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 722:
#line 3858 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 723:
#line 3864 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 724:
#line 3873 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if ((yyvsp[-1].number > 0) && ConfigServerHide.links_disabled == 1)
    {
      eventAddIsh("write_links_file", write_links_file, NULL, yyvsp[-1].number);
      ConfigServerHide.links_disabled = 0;
    }

    ConfigServerHide.links_delay = yyvsp[-1].number;
  }
}
    break;

  case 725:
#line 3887 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 726:
#line 3893 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 727:
#line 3899 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


    }

/* Line 1016 of /usr/local/share/bison/yacc.c.  */
#line 7262 "y.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;


#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

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
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("parse error, unexpected ") + 1;
	  yysize += yystrlen (yytname[yytype]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("parse error");
    }
  goto yyerrlab1;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyssp > yyss)
	    {
	      YYDPRINTF ((stderr, "Error: popping "));
	      YYDSYMPRINT ((stderr,
			    yystos[*yyssp],
			    *yyvsp));
	      YYDPRINTF ((stderr, "\n"));
	      yydestruct (yystos[*yyssp], *yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
		  yychar, yytname[yychar1]));
      yydestruct (yychar1, yylval);
      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */

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

      YYDPRINTF ((stderr, "Error: popping "));
      YYDSYMPRINT ((stderr,
		    yystos[*yyssp], *yyvsp));
      YYDPRINTF ((stderr, "\n"));

      yydestruct (yystos[yystate], *yyvsp);
      yyvsp--;
      yystate = *--yyssp;


#if YYDEBUG
      if (yydebug)
	{
	  short *yyssp1 = yyss - 1;
	  YYFPRINTF (stderr, "Error: state stack now");
	  while (yyssp1 != yyssp)
	    YYFPRINTF (stderr, " %d", *++yyssp1);
	  YYFPRINTF (stderr, "\n");
	}
#endif
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


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
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 382 "ircd_parser.y"

