/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 28 "conf_parser.y" /* yacc.c:339  */


#define YY_NO_UNPUT
#include <sys/types.h>
#include <string.h>

#include "config.h"
#include "stdinc.h"
#include "ircd.h"
#include "list.h"
#include "conf.h"
#include "conf_class.h"
#include "conf_pseudo.h"
#include "event.h"
#include "log.h"
#include "client.h"	/* for UMODE_ALL only */
#include "irc_string.h"
#include "memory.h"
#include "modules.h"
#include "server.h"
#include "hostmask.h"
#include "send.h"
#include "listener.h"
#include "resv.h"
#include "numeric.h"
#include "user.h"
#include "motd.h"

#ifdef HAVE_LIBCRYPTO
#include <openssl/rsa.h>
#include <openssl/bio.h>
#include <openssl/pem.h>
#include <openssl/dh.h>
#endif

#include "rsa.h"

int yylex(void);

static struct
{
  struct
  {
    dlink_list list;
  } mask,
    leaf,
    hub;

  struct
  {
    char buf[IRCD_BUFSIZE];
  } name,
    nick,
    user,
    host,
    addr,
    bind,
    file,
    ciph,
    cert,
    rpass,
    spass,
    class,
    target,
    prepend,
    command;

  struct
  {
    unsigned int value;
  } flags,
    modes,
    size,
    type,
    port,
    aftype,
    ping_freq,
    max_perip,
    con_freq,
    min_idle,
    max_idle,
    max_total,
    max_global,
    max_local,
    max_ident,
    max_sendq,
    max_recvq,
    max_channels,
    cidr_bitlen_ipv4,
    cidr_bitlen_ipv6,
    number_per_cidr;
} block_state;

static void
reset_block_state(void)
{
  dlink_node *node = NULL, *node_next = NULL;

  DLINK_FOREACH_SAFE(node, node_next, block_state.mask.list.head)
  {
    MyFree(node->data);
    dlinkDelete(node, &block_state.mask.list);
    free_dlink_node(node);
  }

  DLINK_FOREACH_SAFE(node, node_next, block_state.leaf.list.head)
  {
    MyFree(node->data);
    dlinkDelete(node, &block_state.leaf.list);
    free_dlink_node(node);
  }

  DLINK_FOREACH_SAFE(node, node_next, block_state.hub.list.head)
  {
    MyFree(node->data);
    dlinkDelete(node, &block_state.hub.list);
    free_dlink_node(node);
  }

  memset(&block_state, 0, sizeof(block_state));
}


#line 190 "conf_parser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_CONF_PARSER_H_INCLUDED
# define YY_YY_CONF_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ACCEPT_PASSWORD = 258,
    ADMIN = 259,
    AFTYPE = 260,
    ANTI_NICK_FLOOD = 261,
    ANTI_SPAM_EXIT_MESSAGE_TIME = 262,
    AUTOCONN = 263,
    AWAY_COUNT = 264,
    AWAY_TIME = 265,
    BYTES = 266,
    KBYTES = 267,
    MBYTES = 268,
    CALLER_ID_WAIT = 269,
    CAN_FLOOD = 270,
    CHANNEL = 271,
    CIDR_BITLEN_IPV4 = 272,
    CIDR_BITLEN_IPV6 = 273,
    CLASS = 274,
    CONNECT = 275,
    CONNECTFREQ = 276,
    CYCLE_ON_HOST_CHANGE = 277,
    DEFAULT_FLOODCOUNT = 278,
    DEFAULT_SPLIT_SERVER_COUNT = 279,
    DEFAULT_SPLIT_USER_COUNT = 280,
    DENY = 281,
    DESCRIPTION = 282,
    DIE = 283,
    DISABLE_AUTH = 284,
    DISABLE_FAKE_CHANNELS = 285,
    DISABLE_REMOTE_COMMANDS = 286,
    DOTS_IN_IDENT = 287,
    EGDPOOL_PATH = 288,
    EMAIL = 289,
    ENCRYPTED = 290,
    EXCEED_LIMIT = 291,
    EXEMPT = 292,
    FAILED_OPER_NOTICE = 293,
    FLATTEN_LINKS = 294,
    GECOS = 295,
    GENERAL = 296,
    GLINE = 297,
    GLINE_DURATION = 298,
    GLINE_ENABLE = 299,
    GLINE_EXEMPT = 300,
    GLINE_MIN_CIDR = 301,
    GLINE_MIN_CIDR6 = 302,
    GLINE_REQUEST_DURATION = 303,
    GLOBAL_KILL = 304,
    HAVENT_READ_CONF = 305,
    HIDDEN = 306,
    HIDDEN_NAME = 307,
    HIDE_CHANS = 308,
    HIDE_IDLE = 309,
    HIDE_IDLE_FROM_OPERS = 310,
    HIDE_SERVER_IPS = 311,
    HIDE_SERVERS = 312,
    HIDE_SERVICES = 313,
    HIDE_SPOOF_IPS = 314,
    HOST = 315,
    HUB = 316,
    HUB_MASK = 317,
    IGNORE_BOGUS_TS = 318,
    INVISIBLE_ON_CONNECT = 319,
    INVITE_CLIENT_COUNT = 320,
    INVITE_CLIENT_TIME = 321,
    IP = 322,
    IRCD_AUTH = 323,
    IRCD_FLAGS = 324,
    IRCD_SID = 325,
    JOIN_FLOOD_COUNT = 326,
    JOIN_FLOOD_TIME = 327,
    KILL = 328,
    KILL_CHASE_TIME_LIMIT = 329,
    KLINE = 330,
    KLINE_EXEMPT = 331,
    KNOCK_CLIENT_COUNT = 332,
    KNOCK_CLIENT_TIME = 333,
    KNOCK_DELAY_CHANNEL = 334,
    LEAF_MASK = 335,
    LINKS_DELAY = 336,
    LISTEN = 337,
    MASK = 338,
    MAX_ACCEPT = 339,
    MAX_BANS = 340,
    MAX_CHANNELS = 341,
    MAX_GLOBAL = 342,
    MAX_IDENT = 343,
    MAX_IDLE = 344,
    MAX_LOCAL = 345,
    MAX_NICK_CHANGES = 346,
    MAX_NICK_LENGTH = 347,
    MAX_NICK_TIME = 348,
    MAX_NUMBER = 349,
    MAX_TARGETS = 350,
    MAX_TOPIC_LENGTH = 351,
    MAX_WATCH = 352,
    MIN_IDLE = 353,
    MIN_NONWILDCARD = 354,
    MIN_NONWILDCARD_SIMPLE = 355,
    MODULE = 356,
    MODULES = 357,
    MOTD = 358,
    NAME = 359,
    NEED_IDENT = 360,
    NEED_PASSWORD = 361,
    NETWORK_DESC = 362,
    NETWORK_NAME = 363,
    NICK = 364,
    NO_CREATE_ON_SPLIT = 365,
    NO_JOIN_ON_SPLIT = 366,
    NO_OPER_FLOOD = 367,
    NO_TILDE = 368,
    NUMBER = 369,
    NUMBER_PER_CIDR = 370,
    NUMBER_PER_IP = 371,
    OPER_ONLY_UMODES = 372,
    OPER_PASS_RESV = 373,
    OPER_UMODES = 374,
    OPERATOR = 375,
    OPERS_BYPASS_CALLERID = 376,
    PACE_WAIT = 377,
    PACE_WAIT_SIMPLE = 378,
    PASSWORD = 379,
    PATH = 380,
    PING_COOKIE = 381,
    PING_TIME = 382,
    PORT = 383,
    QSTRING = 384,
    RANDOM_IDLE = 385,
    REASON = 386,
    REDIRPORT = 387,
    REDIRSERV = 388,
    REHASH = 389,
    REMOTE = 390,
    REMOTEBAN = 391,
    RESV = 392,
    RESV_EXEMPT = 393,
    RSA_PRIVATE_KEY_FILE = 394,
    RSA_PUBLIC_KEY_FILE = 395,
    SECONDS = 396,
    MINUTES = 397,
    HOURS = 398,
    DAYS = 399,
    WEEKS = 400,
    MONTHS = 401,
    YEARS = 402,
    SEND_PASSWORD = 403,
    SENDQ = 404,
    SERVERHIDE = 405,
    SERVERINFO = 406,
    SHORT_MOTD = 407,
    SPOOF = 408,
    SPOOF_NOTICE = 409,
    SQUIT = 410,
    SSL_CERTIFICATE_FILE = 411,
    SSL_CERTIFICATE_FINGERPRINT = 412,
    SSL_CONNECTION_REQUIRED = 413,
    SSL_DH_ELLIPTIC_CURVE = 414,
    SSL_DH_PARAM_FILE = 415,
    SSL_MESSAGE_DIGEST_ALGORITHM = 416,
    STATS_E_DISABLED = 417,
    STATS_I_OPER_ONLY = 418,
    STATS_K_OPER_ONLY = 419,
    STATS_O_OPER_ONLY = 420,
    STATS_P_OPER_ONLY = 421,
    STATS_U_OPER_ONLY = 422,
    T_ALL = 423,
    T_BOTS = 424,
    T_CALLERID = 425,
    T_CCONN = 426,
    T_COMMAND = 427,
    T_CLUSTER = 428,
    T_DEAF = 429,
    T_DEBUG = 430,
    T_DLINE = 431,
    T_EXTERNAL = 432,
    T_FARCONNECT = 433,
    T_FILE = 434,
    T_FULL = 435,
    T_GLOBOPS = 436,
    T_INVISIBLE = 437,
    T_IPV4 = 438,
    T_IPV6 = 439,
    T_LOCOPS = 440,
    T_LOG = 441,
    T_MAX_CLIENTS = 442,
    T_NCHANGE = 443,
    T_NONONREG = 444,
    T_PREPEND = 445,
    T_PSEUDO = 446,
    T_RECVQ = 447,
    T_REJ = 448,
    T_RESTART = 449,
    T_SERVER = 450,
    T_SERVICE = 451,
    T_SERVNOTICE = 452,
    T_SET = 453,
    T_SHARED = 454,
    T_SIZE = 455,
    T_SKILL = 456,
    T_SOFTCALLERID = 457,
    T_SPY = 458,
    T_SSL = 459,
    T_SSL_CIPHER_LIST = 460,
    T_TARGET = 461,
    T_UMODES = 462,
    T_UNAUTH = 463,
    T_UNDLINE = 464,
    T_UNLIMITED = 465,
    T_UNRESV = 466,
    T_UNXLINE = 467,
    T_WALLOP = 468,
    T_WALLOPS = 469,
    T_WEBIRC = 470,
    TBOOL = 471,
    THROTTLE_COUNT = 472,
    THROTTLE_TIME = 473,
    TKLINE_EXPIRE_NOTICES = 474,
    TMASKED = 475,
    TRUE_NO_OPER_FLOOD = 476,
    TS_MAX_DELTA = 477,
    TS_WARN_DELTA = 478,
    TWODOTS = 479,
    TYPE = 480,
    UNKLINE = 481,
    USE_EGD = 482,
    USE_LOGGING = 483,
    USER = 484,
    VHOST = 485,
    VHOST6 = 486,
    WARN_NO_CONNECT_BLOCK = 487,
    XLINE = 488
  };
#endif
/* Tokens.  */
#define ACCEPT_PASSWORD 258
#define ADMIN 259
#define AFTYPE 260
#define ANTI_NICK_FLOOD 261
#define ANTI_SPAM_EXIT_MESSAGE_TIME 262
#define AUTOCONN 263
#define AWAY_COUNT 264
#define AWAY_TIME 265
#define BYTES 266
#define KBYTES 267
#define MBYTES 268
#define CALLER_ID_WAIT 269
#define CAN_FLOOD 270
#define CHANNEL 271
#define CIDR_BITLEN_IPV4 272
#define CIDR_BITLEN_IPV6 273
#define CLASS 274
#define CONNECT 275
#define CONNECTFREQ 276
#define CYCLE_ON_HOST_CHANGE 277
#define DEFAULT_FLOODCOUNT 278
#define DEFAULT_SPLIT_SERVER_COUNT 279
#define DEFAULT_SPLIT_USER_COUNT 280
#define DENY 281
#define DESCRIPTION 282
#define DIE 283
#define DISABLE_AUTH 284
#define DISABLE_FAKE_CHANNELS 285
#define DISABLE_REMOTE_COMMANDS 286
#define DOTS_IN_IDENT 287
#define EGDPOOL_PATH 288
#define EMAIL 289
#define ENCRYPTED 290
#define EXCEED_LIMIT 291
#define EXEMPT 292
#define FAILED_OPER_NOTICE 293
#define FLATTEN_LINKS 294
#define GECOS 295
#define GENERAL 296
#define GLINE 297
#define GLINE_DURATION 298
#define GLINE_ENABLE 299
#define GLINE_EXEMPT 300
#define GLINE_MIN_CIDR 301
#define GLINE_MIN_CIDR6 302
#define GLINE_REQUEST_DURATION 303
#define GLOBAL_KILL 304
#define HAVENT_READ_CONF 305
#define HIDDEN 306
#define HIDDEN_NAME 307
#define HIDE_CHANS 308
#define HIDE_IDLE 309
#define HIDE_IDLE_FROM_OPERS 310
#define HIDE_SERVER_IPS 311
#define HIDE_SERVERS 312
#define HIDE_SERVICES 313
#define HIDE_SPOOF_IPS 314
#define HOST 315
#define HUB 316
#define HUB_MASK 317
#define IGNORE_BOGUS_TS 318
#define INVISIBLE_ON_CONNECT 319
#define INVITE_CLIENT_COUNT 320
#define INVITE_CLIENT_TIME 321
#define IP 322
#define IRCD_AUTH 323
#define IRCD_FLAGS 324
#define IRCD_SID 325
#define JOIN_FLOOD_COUNT 326
#define JOIN_FLOOD_TIME 327
#define KILL 328
#define KILL_CHASE_TIME_LIMIT 329
#define KLINE 330
#define KLINE_EXEMPT 331
#define KNOCK_CLIENT_COUNT 332
#define KNOCK_CLIENT_TIME 333
#define KNOCK_DELAY_CHANNEL 334
#define LEAF_MASK 335
#define LINKS_DELAY 336
#define LISTEN 337
#define MASK 338
#define MAX_ACCEPT 339
#define MAX_BANS 340
#define MAX_CHANNELS 341
#define MAX_GLOBAL 342
#define MAX_IDENT 343
#define MAX_IDLE 344
#define MAX_LOCAL 345
#define MAX_NICK_CHANGES 346
#define MAX_NICK_LENGTH 347
#define MAX_NICK_TIME 348
#define MAX_NUMBER 349
#define MAX_TARGETS 350
#define MAX_TOPIC_LENGTH 351
#define MAX_WATCH 352
#define MIN_IDLE 353
#define MIN_NONWILDCARD 354
#define MIN_NONWILDCARD_SIMPLE 355
#define MODULE 356
#define MODULES 357
#define MOTD 358
#define NAME 359
#define NEED_IDENT 360
#define NEED_PASSWORD 361
#define NETWORK_DESC 362
#define NETWORK_NAME 363
#define NICK 364
#define NO_CREATE_ON_SPLIT 365
#define NO_JOIN_ON_SPLIT 366
#define NO_OPER_FLOOD 367
#define NO_TILDE 368
#define NUMBER 369
#define NUMBER_PER_CIDR 370
#define NUMBER_PER_IP 371
#define OPER_ONLY_UMODES 372
#define OPER_PASS_RESV 373
#define OPER_UMODES 374
#define OPERATOR 375
#define OPERS_BYPASS_CALLERID 376
#define PACE_WAIT 377
#define PACE_WAIT_SIMPLE 378
#define PASSWORD 379
#define PATH 380
#define PING_COOKIE 381
#define PING_TIME 382
#define PORT 383
#define QSTRING 384
#define RANDOM_IDLE 385
#define REASON 386
#define REDIRPORT 387
#define REDIRSERV 388
#define REHASH 389
#define REMOTE 390
#define REMOTEBAN 391
#define RESV 392
#define RESV_EXEMPT 393
#define RSA_PRIVATE_KEY_FILE 394
#define RSA_PUBLIC_KEY_FILE 395
#define SECONDS 396
#define MINUTES 397
#define HOURS 398
#define DAYS 399
#define WEEKS 400
#define MONTHS 401
#define YEARS 402
#define SEND_PASSWORD 403
#define SENDQ 404
#define SERVERHIDE 405
#define SERVERINFO 406
#define SHORT_MOTD 407
#define SPOOF 408
#define SPOOF_NOTICE 409
#define SQUIT 410
#define SSL_CERTIFICATE_FILE 411
#define SSL_CERTIFICATE_FINGERPRINT 412
#define SSL_CONNECTION_REQUIRED 413
#define SSL_DH_ELLIPTIC_CURVE 414
#define SSL_DH_PARAM_FILE 415
#define SSL_MESSAGE_DIGEST_ALGORITHM 416
#define STATS_E_DISABLED 417
#define STATS_I_OPER_ONLY 418
#define STATS_K_OPER_ONLY 419
#define STATS_O_OPER_ONLY 420
#define STATS_P_OPER_ONLY 421
#define STATS_U_OPER_ONLY 422
#define T_ALL 423
#define T_BOTS 424
#define T_CALLERID 425
#define T_CCONN 426
#define T_COMMAND 427
#define T_CLUSTER 428
#define T_DEAF 429
#define T_DEBUG 430
#define T_DLINE 431
#define T_EXTERNAL 432
#define T_FARCONNECT 433
#define T_FILE 434
#define T_FULL 435
#define T_GLOBOPS 436
#define T_INVISIBLE 437
#define T_IPV4 438
#define T_IPV6 439
#define T_LOCOPS 440
#define T_LOG 441
#define T_MAX_CLIENTS 442
#define T_NCHANGE 443
#define T_NONONREG 444
#define T_PREPEND 445
#define T_PSEUDO 446
#define T_RECVQ 447
#define T_REJ 448
#define T_RESTART 449
#define T_SERVER 450
#define T_SERVICE 451
#define T_SERVNOTICE 452
#define T_SET 453
#define T_SHARED 454
#define T_SIZE 455
#define T_SKILL 456
#define T_SOFTCALLERID 457
#define T_SPY 458
#define T_SSL 459
#define T_SSL_CIPHER_LIST 460
#define T_TARGET 461
#define T_UMODES 462
#define T_UNAUTH 463
#define T_UNDLINE 464
#define T_UNLIMITED 465
#define T_UNRESV 466
#define T_UNXLINE 467
#define T_WALLOP 468
#define T_WALLOPS 469
#define T_WEBIRC 470
#define TBOOL 471
#define THROTTLE_COUNT 472
#define THROTTLE_TIME 473
#define TKLINE_EXPIRE_NOTICES 474
#define TMASKED 475
#define TRUE_NO_OPER_FLOOD 476
#define TS_MAX_DELTA 477
#define TS_WARN_DELTA 478
#define TWODOTS 479
#define TYPE 480
#define UNKLINE 481
#define USE_EGD 482
#define USE_LOGGING 483
#define USER 484
#define VHOST 485
#define VHOST6 486
#define WARN_NO_CONNECT_BLOCK 487
#define XLINE 488

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 152 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 701 "conf_parser.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 716 "conf_parser.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1311

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  240
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  297
/* YYNRULES -- Number of rules.  */
#define YYNRULES  667
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1319

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   488

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   238,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   239,   234,
       2,   237,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   236,     2,   235,     2,     2,     2,     2,
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
     225,   226,   227,   228,   229,   230,   231,   232,   233
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   389,   389,   390,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   420,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   431,   431,
     432,   433,   434,   435,   442,   445,   445,   446,   446,   446,
     448,   454,   461,   463,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   484,   524,   582,   611,   619,   633,   661,
     676,   691,   701,   715,   724,   752,   780,   805,   827,   849,
     858,   860,   860,   861,   862,   863,   864,   866,   875,   884,
     897,   896,   914,   914,   915,   915,   915,   917,   923,   933,
     932,   951,   951,   952,   952,   952,   952,   952,   954,   960,
     966,   972,   995,   996,   996,   998,   998,   999,  1001,  1008,
    1008,  1021,  1022,  1024,  1024,  1025,  1025,  1027,  1035,  1038,
    1044,  1043,  1049,  1049,  1050,  1054,  1058,  1062,  1066,  1070,
    1074,  1078,  1082,  1093,  1092,  1178,  1178,  1179,  1180,  1181,
    1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,  1191,  1197,
    1203,  1209,  1220,  1226,  1232,  1243,  1250,  1249,  1255,  1255,
    1256,  1260,  1264,  1268,  1272,  1276,  1280,  1284,  1288,  1292,
    1296,  1300,  1304,  1308,  1312,  1316,  1320,  1324,  1328,  1332,
    1336,  1340,  1347,  1346,  1352,  1352,  1353,  1357,  1361,  1365,
    1369,  1373,  1377,  1381,  1385,  1389,  1393,  1397,  1401,  1405,
    1409,  1413,  1417,  1421,  1425,  1429,  1433,  1437,  1441,  1452,
    1451,  1513,  1513,  1514,  1515,  1516,  1517,  1518,  1519,  1520,
    1521,  1522,  1523,  1524,  1525,  1526,  1526,  1527,  1528,  1529,
    1530,  1532,  1538,  1544,  1550,  1556,  1562,  1568,  1574,  1580,
    1586,  1592,  1599,  1605,  1611,  1617,  1626,  1636,  1635,  1641,
    1641,  1642,  1646,  1657,  1656,  1663,  1662,  1667,  1667,  1668,
    1672,  1676,  1682,  1682,  1683,  1683,  1683,  1683,  1683,  1685,
    1685,  1687,  1687,  1689,  1702,  1719,  1725,  1735,  1734,  1776,
    1776,  1777,  1778,  1779,  1780,  1781,  1782,  1783,  1784,  1785,
    1787,  1793,  1799,  1805,  1817,  1816,  1822,  1822,  1823,  1827,
    1831,  1835,  1839,  1843,  1847,  1851,  1855,  1859,  1865,  1879,
    1888,  1902,  1901,  1916,  1916,  1917,  1917,  1917,  1917,  1919,
    1925,  1931,  1941,  1943,  1943,  1944,  1944,  1946,  1962,  1961,
    1986,  1986,  1987,  1987,  1987,  1987,  1989,  1995,  2015,  2014,
    2020,  2020,  2021,  2025,  2029,  2033,  2037,  2041,  2045,  2049,
    2053,  2057,  2067,  2066,  2087,  2087,  2088,  2088,  2088,  2090,
    2097,  2096,  2102,  2102,  2103,  2107,  2111,  2115,  2119,  2123,
    2127,  2131,  2135,  2139,  2149,  2148,  2220,  2220,  2221,  2222,
    2223,  2224,  2225,  2226,  2227,  2228,  2229,  2230,  2231,  2232,
    2233,  2234,  2235,  2237,  2243,  2249,  2255,  2268,  2281,  2287,
    2293,  2297,  2304,  2303,  2308,  2308,  2309,  2313,  2319,  2330,
    2336,  2342,  2348,  2364,  2363,  2389,  2389,  2390,  2390,  2390,
    2392,  2412,  2422,  2421,  2448,  2448,  2449,  2449,  2449,  2451,
    2457,  2466,  2468,  2468,  2469,  2469,  2471,  2489,  2488,  2511,
    2511,  2512,  2512,  2512,  2514,  2520,  2529,  2532,  2532,  2533,
    2534,  2535,  2536,  2537,  2538,  2539,  2540,  2541,  2542,  2543,
    2544,  2545,  2546,  2547,  2548,  2549,  2550,  2551,  2552,  2553,
    2554,  2555,  2556,  2557,  2558,  2559,  2560,  2561,  2562,  2563,
    2564,  2565,  2566,  2567,  2568,  2569,  2570,  2571,  2572,  2573,
    2574,  2575,  2576,  2577,  2578,  2579,  2580,  2581,  2584,  2589,
    2594,  2599,  2605,  2611,  2617,  2623,  2628,  2633,  2638,  2643,
    2648,  2653,  2658,  2663,  2668,  2673,  2678,  2683,  2689,  2700,
    2705,  2710,  2715,  2720,  2725,  2730,  2733,  2738,  2741,  2746,
    2751,  2756,  2761,  2766,  2771,  2776,  2781,  2786,  2791,  2796,
    2801,  2806,  2811,  2817,  2816,  2821,  2821,  2822,  2825,  2828,
    2831,  2834,  2837,  2840,  2843,  2846,  2849,  2852,  2855,  2858,
    2861,  2864,  2867,  2870,  2873,  2876,  2879,  2882,  2885,  2891,
    2890,  2895,  2895,  2896,  2899,  2902,  2905,  2908,  2911,  2914,
    2917,  2920,  2923,  2926,  2929,  2932,  2935,  2938,  2941,  2944,
    2947,  2950,  2953,  2958,  2963,  2968,  2977,  2980,  2980,  2981,
    2982,  2983,  2984,  2985,  2986,  2987,  2988,  2989,  2990,  2991,
    2992,  2993,  2994,  2995,  2997,  3002,  3007,  3012,  3017,  3022,
    3027,  3032,  3037,  3042,  3047,  3052,  3057,  3062,  3070,  3073,
    3073,  3074,  3075,  3076,  3077,  3078,  3079,  3080,  3081,  3082,
    3084,  3090,  3096,  3102,  3108,  3117,  3132,  3138
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ACCEPT_PASSWORD", "ADMIN", "AFTYPE",
  "ANTI_NICK_FLOOD", "ANTI_SPAM_EXIT_MESSAGE_TIME", "AUTOCONN",
  "AWAY_COUNT", "AWAY_TIME", "BYTES", "KBYTES", "MBYTES", "CALLER_ID_WAIT",
  "CAN_FLOOD", "CHANNEL", "CIDR_BITLEN_IPV4", "CIDR_BITLEN_IPV6", "CLASS",
  "CONNECT", "CONNECTFREQ", "CYCLE_ON_HOST_CHANGE", "DEFAULT_FLOODCOUNT",
  "DEFAULT_SPLIT_SERVER_COUNT", "DEFAULT_SPLIT_USER_COUNT", "DENY",
  "DESCRIPTION", "DIE", "DISABLE_AUTH", "DISABLE_FAKE_CHANNELS",
  "DISABLE_REMOTE_COMMANDS", "DOTS_IN_IDENT", "EGDPOOL_PATH", "EMAIL",
  "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT", "FAILED_OPER_NOTICE",
  "FLATTEN_LINKS", "GECOS", "GENERAL", "GLINE", "GLINE_DURATION",
  "GLINE_ENABLE", "GLINE_EXEMPT", "GLINE_MIN_CIDR", "GLINE_MIN_CIDR6",
  "GLINE_REQUEST_DURATION", "GLOBAL_KILL", "HAVENT_READ_CONF", "HIDDEN",
  "HIDDEN_NAME", "HIDE_CHANS", "HIDE_IDLE", "HIDE_IDLE_FROM_OPERS",
  "HIDE_SERVER_IPS", "HIDE_SERVERS", "HIDE_SERVICES", "HIDE_SPOOF_IPS",
  "HOST", "HUB", "HUB_MASK", "IGNORE_BOGUS_TS", "INVISIBLE_ON_CONNECT",
  "INVITE_CLIENT_COUNT", "INVITE_CLIENT_TIME", "IP", "IRCD_AUTH",
  "IRCD_FLAGS", "IRCD_SID", "JOIN_FLOOD_COUNT", "JOIN_FLOOD_TIME", "KILL",
  "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT", "KNOCK_CLIENT_COUNT",
  "KNOCK_CLIENT_TIME", "KNOCK_DELAY_CHANNEL", "LEAF_MASK", "LINKS_DELAY",
  "LISTEN", "MASK", "MAX_ACCEPT", "MAX_BANS", "MAX_CHANNELS", "MAX_GLOBAL",
  "MAX_IDENT", "MAX_IDLE", "MAX_LOCAL", "MAX_NICK_CHANGES",
  "MAX_NICK_LENGTH", "MAX_NICK_TIME", "MAX_NUMBER", "MAX_TARGETS",
  "MAX_TOPIC_LENGTH", "MAX_WATCH", "MIN_IDLE", "MIN_NONWILDCARD",
  "MIN_NONWILDCARD_SIMPLE", "MODULE", "MODULES", "MOTD", "NAME",
  "NEED_IDENT", "NEED_PASSWORD", "NETWORK_DESC", "NETWORK_NAME", "NICK",
  "NO_CREATE_ON_SPLIT", "NO_JOIN_ON_SPLIT", "NO_OPER_FLOOD", "NO_TILDE",
  "NUMBER", "NUMBER_PER_CIDR", "NUMBER_PER_IP", "OPER_ONLY_UMODES",
  "OPER_PASS_RESV", "OPER_UMODES", "OPERATOR", "OPERS_BYPASS_CALLERID",
  "PACE_WAIT", "PACE_WAIT_SIMPLE", "PASSWORD", "PATH", "PING_COOKIE",
  "PING_TIME", "PORT", "QSTRING", "RANDOM_IDLE", "REASON", "REDIRPORT",
  "REDIRSERV", "REHASH", "REMOTE", "REMOTEBAN", "RESV", "RESV_EXEMPT",
  "RSA_PRIVATE_KEY_FILE", "RSA_PUBLIC_KEY_FILE", "SECONDS", "MINUTES",
  "HOURS", "DAYS", "WEEKS", "MONTHS", "YEARS", "SEND_PASSWORD", "SENDQ",
  "SERVERHIDE", "SERVERINFO", "SHORT_MOTD", "SPOOF", "SPOOF_NOTICE",
  "SQUIT", "SSL_CERTIFICATE_FILE", "SSL_CERTIFICATE_FINGERPRINT",
  "SSL_CONNECTION_REQUIRED", "SSL_DH_ELLIPTIC_CURVE", "SSL_DH_PARAM_FILE",
  "SSL_MESSAGE_DIGEST_ALGORITHM", "STATS_E_DISABLED", "STATS_I_OPER_ONLY",
  "STATS_K_OPER_ONLY", "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY",
  "STATS_U_OPER_ONLY", "T_ALL", "T_BOTS", "T_CALLERID", "T_CCONN",
  "T_COMMAND", "T_CLUSTER", "T_DEAF", "T_DEBUG", "T_DLINE", "T_EXTERNAL",
  "T_FARCONNECT", "T_FILE", "T_FULL", "T_GLOBOPS", "T_INVISIBLE", "T_IPV4",
  "T_IPV6", "T_LOCOPS", "T_LOG", "T_MAX_CLIENTS", "T_NCHANGE",
  "T_NONONREG", "T_PREPEND", "T_PSEUDO", "T_RECVQ", "T_REJ", "T_RESTART",
  "T_SERVER", "T_SERVICE", "T_SERVNOTICE", "T_SET", "T_SHARED", "T_SIZE",
  "T_SKILL", "T_SOFTCALLERID", "T_SPY", "T_SSL", "T_SSL_CIPHER_LIST",
  "T_TARGET", "T_UMODES", "T_UNAUTH", "T_UNDLINE", "T_UNLIMITED",
  "T_UNRESV", "T_UNXLINE", "T_WALLOP", "T_WALLOPS", "T_WEBIRC", "TBOOL",
  "THROTTLE_COUNT", "THROTTLE_TIME", "TKLINE_EXPIRE_NOTICES", "TMASKED",
  "TRUE_NO_OPER_FLOOD", "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS", "TYPE",
  "UNKLINE", "USE_EGD", "USE_LOGGING", "USER", "VHOST", "VHOST6",
  "WARN_NO_CONNECT_BLOCK", "XLINE", "';'", "'}'", "'{'", "'='", "','",
  "':'", "$accept", "conf", "conf_item", "timespec_", "timespec",
  "sizespec_", "sizespec", "modules_entry", "modules_items",
  "modules_item", "modules_module", "modules_path", "serverinfo_entry",
  "serverinfo_items", "serverinfo_item", "serverinfo_ssl_certificate_file",
  "serverinfo_rsa_private_key_file", "serverinfo_ssl_dh_param_file",
  "serverinfo_ssl_cipher_list", "serverinfo_ssl_message_digest_algorithm",
  "serverinfo_ssl_dh_elliptic_curve", "serverinfo_name", "serverinfo_sid",
  "serverinfo_description", "serverinfo_network_name",
  "serverinfo_network_desc", "serverinfo_vhost", "serverinfo_vhost6",
  "serverinfo_max_clients", "serverinfo_max_nick_length",
  "serverinfo_max_topic_length", "serverinfo_hub", "admin_entry",
  "admin_items", "admin_item", "admin_name", "admin_email",
  "admin_description", "motd_entry", "$@1", "motd_items", "motd_item",
  "motd_mask", "motd_file", "pseudo_entry", "$@2", "pseudo_items",
  "pseudo_item", "pseudo_command", "pseudo_name", "pseudo_prepend",
  "pseudo_target", "logging_entry", "logging_items", "logging_item",
  "logging_use_logging", "logging_file_entry", "$@3", "logging_file_items",
  "logging_file_item", "logging_file_name", "logging_file_size",
  "logging_file_type", "$@4", "logging_file_type_items",
  "logging_file_type_item", "oper_entry", "$@5", "oper_items", "oper_item",
  "oper_name", "oper_user", "oper_password", "oper_encrypted",
  "oper_rsa_public_key_file", "oper_ssl_certificate_fingerprint",
  "oper_ssl_connection_required", "oper_class", "oper_umodes", "$@6",
  "oper_umodes_items", "oper_umodes_item", "oper_flags", "$@7",
  "oper_flags_items", "oper_flags_item", "class_entry", "$@8",
  "class_items", "class_item", "class_name", "class_ping_time",
  "class_number_per_ip", "class_connectfreq", "class_max_channels",
  "class_max_number", "class_max_global", "class_max_local",
  "class_max_ident", "class_sendq", "class_recvq",
  "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6",
  "class_number_per_cidr", "class_min_idle", "class_max_idle",
  "class_flags", "$@9", "class_flags_items", "class_flags_item",
  "listen_entry", "$@10", "listen_flags", "$@11", "listen_flags_items",
  "listen_flags_item", "listen_items", "listen_item", "listen_port",
  "$@12", "port_items", "port_item", "listen_address", "listen_host",
  "auth_entry", "$@13", "auth_items", "auth_item", "auth_user",
  "auth_passwd", "auth_class", "auth_encrypted", "auth_flags", "$@14",
  "auth_flags_items", "auth_flags_item", "auth_spoof", "auth_redir_serv",
  "auth_redir_port", "resv_entry", "$@15", "resv_items", "resv_item",
  "resv_mask", "resv_reason", "resv_exempt", "service_entry",
  "service_items", "service_item", "service_name", "shared_entry", "$@16",
  "shared_items", "shared_item", "shared_name", "shared_user",
  "shared_type", "$@17", "shared_types", "shared_type_item",
  "cluster_entry", "$@18", "cluster_items", "cluster_item", "cluster_name",
  "cluster_type", "$@19", "cluster_types", "cluster_type_item",
  "connect_entry", "$@20", "connect_items", "connect_item", "connect_name",
  "connect_host", "connect_vhost", "connect_send_password",
  "connect_accept_password", "connect_ssl_certificate_fingerprint",
  "connect_port", "connect_aftype", "connect_flags", "$@21",
  "connect_flags_items", "connect_flags_item", "connect_encrypted",
  "connect_hub_mask", "connect_leaf_mask", "connect_class",
  "connect_ssl_cipher_list", "kill_entry", "$@22", "kill_items",
  "kill_item", "kill_user", "kill_reason", "deny_entry", "$@23",
  "deny_items", "deny_item", "deny_ip", "deny_reason", "exempt_entry",
  "exempt_items", "exempt_item", "exempt_ip", "gecos_entry", "$@24",
  "gecos_items", "gecos_item", "gecos_name", "gecos_reason",
  "general_entry", "general_items", "general_item", "general_away_count",
  "general_away_time", "general_max_watch", "general_cycle_on_host_change",
  "general_gline_enable", "general_gline_duration",
  "general_gline_request_duration", "general_gline_min_cidr",
  "general_gline_min_cidr6", "general_tkline_expire_notices",
  "general_kill_chase_time_limit", "general_ignore_bogus_ts",
  "general_failed_oper_notice", "general_anti_nick_flood",
  "general_max_nick_time", "general_max_nick_changes",
  "general_max_accept", "general_anti_spam_exit_message_time",
  "general_ts_warn_delta", "general_ts_max_delta",
  "general_havent_read_conf", "general_invisible_on_connect",
  "general_warn_no_connect_block", "general_stats_e_disabled",
  "general_stats_o_oper_only", "general_stats_P_oper_only",
  "general_stats_u_oper_only", "general_stats_k_oper_only",
  "general_stats_i_oper_only", "general_pace_wait",
  "general_caller_id_wait", "general_opers_bypass_callerid",
  "general_pace_wait_simple", "general_short_motd",
  "general_no_oper_flood", "general_true_no_oper_flood",
  "general_oper_pass_resv", "general_dots_in_ident", "general_max_targets",
  "general_ping_cookie", "general_disable_auth", "general_throttle_count",
  "general_throttle_time", "general_oper_umodes", "$@25", "umode_oitems",
  "umode_oitem", "general_oper_only_umodes", "$@26", "umode_items",
  "umode_item", "general_min_nonwildcard",
  "general_min_nonwildcard_simple", "general_default_floodcount",
  "channel_entry", "channel_items", "channel_item",
  "channel_disable_fake_channels", "channel_invite_client_count",
  "channel_invite_client_time", "channel_knock_client_count",
  "channel_knock_client_time", "channel_knock_delay_channel",
  "channel_max_channels", "channel_max_bans",
  "channel_default_split_user_count", "channel_default_split_server_count",
  "channel_no_create_on_split", "channel_no_join_on_split",
  "channel_jflood_count", "channel_jflood_time", "serverhide_entry",
  "serverhide_items", "serverhide_item", "serverhide_flatten_links",
  "serverhide_disable_remote_commands", "serverhide_hide_servers",
  "serverhide_hide_services", "serverhide_hidden_name",
  "serverhide_links_delay", "serverhide_hidden",
  "serverhide_hide_server_ips", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
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
     485,   486,   487,   488,    59,   125,   123,    61,    44,    58
};
# endif

#define YYPACT_NINF -1083

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1083)))

#define YYTABLE_NINF -130

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   -1083,   639, -1083,  -184,  -226,  -207, -1083, -1083, -1083,  -202,
   -1083,  -197, -1083, -1083, -1083,  -194, -1083, -1083, -1083,  -191,
    -179, -1083,  -155, -1083,  -153, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083,   283,   909,  -152,  -147,  -146,    10,  -138,   395,  -126,
    -112,   -79,   212,   -59,   -52,   -33,   355,   376,   -21,    13,
      -2,     2,    50,    38,    28,    65,    68,    25, -1083, -1083,
   -1083, -1083, -1083,    82,    97,    98,    99,   115,   122,   128,
     138,   139,   141,   143,   145,   146,   147,   229, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083,   630,   566,    15, -1083,   148,    32, -1083,
   -1083,    91, -1083,   152,   153,   154,   155,   156,   158,   160,
     161,   163,   171,   173,   177,   179,   182,   183,   185,   188,
     189,   191,   194,   197,   198,   203,   207,   211,   223,   224,
   -1083,   225, -1083,   233,   234,   237,   238,   240,   241,   244,
     245,   248,   254,   256,   259,   261,   262,   263,   264,   265,
     266,   126, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083,   297,    29,    19,    94,   267,   268,    36, -1083, -1083,
   -1083,     8,   529,   284, -1083,   269,   271,   272,   282,   285,
     286,   288,   291,     4, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083,   129,   292,   294,   296,   301,   302,   303,
     304,   306,   308,   309,   313,   314,   315,   316,   318,   331,
     335,    46, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
      71,   215,   336,    22, -1083, -1083, -1083,   103,    14, -1083,
     337,    62, -1083, -1083,    11, -1083,   358,   391,   405,   232,
   -1083,   442,   461,   360,   463,   464,   465,   464,   466,   464,
     464,   468,   470,   367,   370,   353, -1083,   354,   352,   357,
     359, -1083,   363,   365,   371,   372,   373,   374,   378,   384,
     385,   388,   393,   397,   399,     7, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083,   356,   400,   401,   404,   407,   412,
     415, -1083,   419,   420,   424,   425,   427,   429,   431,   319,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083,   434,   435,    20, -1083,
   -1083, -1083,   462,   361, -1083, -1083,   436,   437,    77, -1083,
   -1083, -1083,   381,   464,   478,   464,   464,   416,   490,   426,
     561,   472,   464,   475,   563,   578,   464,   579,   480,   482,
     464,   586,   587,   464,   589,   590,   591,   592,   492,   473,
     493,   474,   497,   464,   464,   499,   509,   510,  -189,  -172,
     515,   516,   517,   621,   464,   521,   523,   464,   464,   524,
     513, -1083,   514,   506,   507, -1083,   512,   518,   519,   525,
     526,    35, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083,   527,   528,    40, -1083, -1083, -1083,   520,   531,
     532, -1083,   533, -1083,    52, -1083, -1083, -1083, -1083, -1083,
     622,   623,   538, -1083,   539,   537,   540,    45, -1083, -1083,
   -1083,   541,   543,   544, -1083,   545,   546,   547,   548,   549,
   -1083,   550,    39, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083,   554,   555,   556,   557,    31, -1083,
   -1083, -1083, -1083,   534,   562,   575,   624,   581,   582,   588,
     464,   569, -1083, -1083,   632,   598,   637,   646,   681,   678,
     686,   688,   689,   694,   697,   698,   700,   717,   707,   708,
     711,   607, -1083,   608,   606, -1083,    48, -1083, -1083, -1083,
   -1083,   633,   614, -1083,    75,   618,   620,   625,   626,   629,
      21, -1083, -1083, -1083, -1083, -1083,   726,   634, -1083,   636,
     638, -1083,   643,    74, -1083, -1083, -1083, -1083,   640,   642,
     647, -1083,   648,   654,   658,   661,   227,   663,   665,   666,
     668,   672,   673,   674,   682,   687,   691, -1083, -1083,   745,
     753,   464,   675,   757,   801,   809,   464,   812,   813,   464,
     731,   814,   816,   464,   818,   818,   701, -1083, -1083,   807,
    -118,   808,   722,   811,   819,   704,   820,   821,   828,   822,
     823,   824,   825,   709, -1083,   827,   830,   728, -1083,   729,
   -1083,   831,   835,   732, -1083,   733,   736,   737,   739,   742,
     743,   744,   748,   749,   750,   751,   755,   756,   758,   759,
     762,   763,   764,   765,   766,   767,   768,   769,   770,   771,
     772,   773,   716,   774,   631,   775,   776,   777,   778,   779,
     780,   781,   782,   783,   784,   787,   788,   789,   790,   791,
     792,   793,   794,   795,   796, -1083, -1083,   836,   815,   754,
     840,   918,   904,   905,   906,   802, -1083,   908,   910,   804,
   -1083, -1083,   911,   912,   805,   929,   810, -1083,   817,   826,
   -1083, -1083,   916,   917,   829, -1083, -1083,   919,   833,   832,
     921,   923,   924,   925,   839,   834,   927,   838, -1083, -1083,
     928,   930,   932,   841, -1083,   842,   843,   844,   845,   846,
     847,   848,   849, -1083,   850,   851,   852,   853,   854,   855,
     856,   857,   858,   859,   860,   861,   862,   863,   864,   865,
     866, -1083, -1083,   933,   837,   867, -1083,   868, -1083,    79,
   -1083,   935,   936,   937,   938,   869, -1083,   870, -1083, -1083,
     939,   871,   941,   872, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083,   464,   464,   464,   464,   464,   464,   464, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083,   873,   875,   876,     9,   877,   878,   879,   880,   881,
     882,   883,   884,   885,   886,   887,   250,   888,   889, -1083,
     890,   891,   892,   893,   894,   895,   896,     5,   897,   898,
     899,   900,   901,   902,   903, -1083,   907,   913, -1083, -1083,
     914,   915, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
    -167, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083,   -40, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083,   920,   922,   584,
     926,   931,   934,   940,   942, -1083,   943,   944, -1083,   945,
     946,   -13,   721,   124, -1083, -1083, -1083, -1083,   947,   948,
   -1083,   949,   950,   469,   951,   952,   953,   954,   955,   676,
     956, -1083,   957,   958,   959, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083,   960,   735, -1083, -1083,   961,   962,   963, -1083,   125,
   -1083, -1083, -1083, -1083,   964,   967,   968,   969, -1083, -1083,
     970,   746,   971, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083,   -22, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,   818,
     818,   818, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083,   -20, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,   716,
   -1083,   631, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083,    -6, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,    -3, -1083,
     991,   929,   972, -1083, -1083, -1083, -1083, -1083,   973, -1083,
   -1083,   974, -1083, -1083, -1083, -1083,   975, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083,    93, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083,    95, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083,   108, -1083, -1083,  1009,   -45,   978,   976,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083,   117, -1083, -1083, -1083,
       9, -1083, -1083, -1083, -1083,     5, -1083, -1083, -1083,   584,
   -1083,   -13, -1083, -1083, -1083,  1004,  1005,  1007, -1083,   469,
   -1083,   676, -1083,   735,   977,   982,   983,   390, -1083, -1083,
     746, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083,   119, -1083, -1083, -1083,   390, -1083
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   229,   394,   442,     0,
     457,     0,   297,   433,   273,     0,   100,   153,   331,     0,
       0,   372,     0,   109,     0,   348,     3,    23,    11,     4,
      24,    25,     5,     6,     8,     9,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    21,     7,    12,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    93,
      95,    94,   633,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   618,   632,
     620,   621,   622,   623,   624,   625,   619,   626,   627,   628,
     629,   630,   631,     0,     0,     0,   455,     0,     0,   453,
     454,     0,   517,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     589,     0,   563,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   468,   469,   470,   515,   516,   509,   510,   511,
     512,   513,   508,   480,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   505,   481,   482,   514,   484,   489,   490,
     485,   487,   486,   498,   499,   488,   491,   492,   493,   494,
     483,   496,   506,   507,   503,   504,   497,   495,   501,   502,
     500,     0,     0,     0,     0,     0,     0,     0,    46,    47,
      48,     0,     0,     0,   659,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   650,   651,   652,   653,   654,   657,
     655,   656,   658,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    54,    69,    66,    64,    70,    71,    65,    55,
      68,    58,    59,    60,    56,    67,    61,    62,    63,    57,
       0,     0,     0,     0,   124,   125,   126,     0,     0,   346,
       0,     0,   344,   345,     0,    96,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   617,     0,     0,     0,
       0,   267,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   232,   233,   236,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   234,   235,
     237,   247,   248,   249,     0,     0,     0,     0,     0,     0,
       0,   422,     0,     0,     0,     0,     0,     0,     0,     0,
     397,   398,   399,   400,   401,   402,   403,   405,   404,   407,
     411,   408,   409,   410,   406,   448,     0,     0,     0,   445,
     446,   447,     0,     0,   452,   463,     0,     0,     0,   460,
     461,   462,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   467,     0,     0,     0,   314,     0,     0,     0,     0,
       0,     0,   300,   301,   302,   303,   308,   304,   305,   306,
     307,   439,     0,     0,     0,   436,   437,   438,     0,     0,
       0,   275,     0,   285,     0,   283,   284,   286,   287,    49,
       0,     0,     0,    45,     0,     0,     0,     0,   103,   104,
     105,     0,     0,     0,   202,     0,     0,     0,     0,     0,
     176,     0,     0,   156,   157,   158,   159,   162,   163,   164,
     165,   161,   160,   166,     0,     0,     0,     0,     0,   334,
     335,   336,   337,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   649,    72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,     0,     0,   380,     0,   375,   376,   377,
     127,     0,     0,   123,     0,     0,     0,     0,     0,     0,
       0,   112,   113,   115,   114,   116,     0,     0,   343,     0,
       0,   358,     0,     0,   351,   352,   353,   354,     0,     0,
       0,    90,     0,     0,     0,     0,    28,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   616,   250,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   231,   412,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   396,     0,     0,     0,   444,     0,
     451,     0,     0,     0,   459,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   466,   309,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   299,     0,     0,     0,
     435,   288,     0,     0,     0,     0,     0,   282,     0,     0,
      44,   106,     0,     0,     0,   102,   167,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   155,   338,
       0,     0,     0,     0,   333,     0,     0,     0,     0,     0,
       0,     0,     0,   648,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,   378,     0,     0,     0,   374,     0,   122,     0,
     117,     0,     0,     0,     0,     0,   111,     0,   342,   355,
       0,     0,     0,     0,   350,    99,    98,    97,   643,   642,
     634,   635,    28,    28,    28,    28,    28,    28,    28,    30,
      29,   636,   646,   647,   637,   638,   639,   641,   640,   644,
     645,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,     0,   230,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   395,     0,     0,   443,   456,
       0,     0,   458,   531,   535,   518,   519,   550,   521,   615,
     560,   557,   530,   523,   522,   525,   526,   524,   538,   529,
     539,   528,   534,   533,   532,   558,   520,   613,   614,   554,
     599,   593,   609,   594,   595,   596,   604,   612,   597,   606,
     610,   600,   611,   601,   605,   598,   608,   603,   602,   607,
       0,   592,   556,   572,   573,   574,   567,   585,   568,   569,
     570,   580,   588,   571,   582,   586,   576,   587,   577,   581,
     575,   584,   579,   578,   583,     0,   566,   551,   549,   552,
     559,   553,   541,   547,   548,   545,   546,   542,   543,   544,
     561,   562,   527,   555,   537,   536,   540,     0,     0,     0,
       0,     0,     0,     0,     0,   298,     0,     0,   434,     0,
       0,     0,   293,   289,   292,   274,    50,    51,     0,     0,
     101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   154,     0,     0,     0,   332,   661,   660,   666,   664,
     667,   662,   663,   665,    81,    89,    80,    87,    88,    79,
      83,    82,    74,    73,    78,    75,    77,    86,    76,    84,
      85,     0,     0,   373,   128,     0,     0,     0,   140,     0,
     132,   133,   135,   134,     0,     0,     0,     0,   110,   347,
       0,     0,     0,   349,    31,    32,    33,    34,    35,    36,
      37,   262,   263,   254,   272,   271,     0,   270,   255,   257,
     259,   266,   258,   256,   265,   251,   264,   253,   252,    38,
      38,    38,    40,    39,   260,   261,   417,   420,   421,   431,
     428,   414,   429,   426,   427,     0,   425,   430,   413,   419,
     416,   418,   432,   415,   449,   450,   464,   465,   590,     0,
     564,     0,   312,   313,   322,   319,   324,   320,   321,   327,
     323,   325,   318,   326,     0,   317,   311,   330,   329,   328,
     310,   441,   440,   296,   295,   280,   281,   279,     0,   278,
       0,     0,     0,   107,   108,   175,   171,   222,   209,   219,
     218,   207,   212,   228,   221,   226,   211,   214,   223,   225,
     220,   227,   215,   217,   224,   213,   216,     0,   205,   168,
     170,   172,   173,   174,   185,   186,   187,   180,   198,   181,
     182,   183,   193,   201,   184,   195,   199,   189,   200,   190,
     194,   188,   197,   192,   191,   196,     0,   179,   169,   341,
     339,   340,   379,   384,   390,   393,   386,   392,   387,   391,
     389,   385,   388,     0,   383,   136,     0,     0,     0,     0,
     131,   119,   118,   120,   121,   356,   362,   368,   371,   364,
     370,   365,   369,   367,   363,   366,     0,   361,   357,   268,
       0,    41,    42,    43,   423,     0,   591,   565,   315,     0,
     276,     0,   294,   291,   290,     0,     0,     0,   203,     0,
     177,     0,   381,     0,     0,     0,     0,     0,   130,   359,
       0,   269,   424,   316,   277,   208,   206,   210,   204,   178,
     382,   137,   139,   138,   146,   151,   150,   145,   148,   152,
     149,   144,   147,     0,   143,   360,   141,     0,   142
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1083, -1083, -1083,  -381,  -313, -1082,  -644, -1083, -1083,   980,
   -1083, -1083, -1083, -1083,   874, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083,   981, -1083, -1083, -1083, -1083, -1083,
   -1083,   644, -1083, -1083, -1083, -1083, -1083,   457, -1083, -1083,
   -1083, -1083, -1083, -1083,   965, -1083, -1083, -1083, -1083,    84,
   -1083, -1083, -1083, -1083, -1083,  -244, -1083, -1083, -1083,   628,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083,  -137, -1083, -1083, -1083,  -133, -1083, -1083, -1083,   966,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,  -108,
   -1083, -1083, -1083, -1083, -1083,  -116, -1083,   659, -1083, -1083,
   -1083,    -4, -1083, -1083, -1083, -1083, -1083,   690, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083,  -111, -1083, -1083, -1083, -1083,
   -1083, -1083,   635, -1083, -1083, -1083, -1083, -1083,   979, -1083,
   -1083, -1083, -1083,   559, -1083, -1083, -1083, -1083, -1083,  -131,
   -1083, -1083, -1083,   593, -1083, -1083, -1083, -1083,  -120, -1083,
   -1083, -1083,   785, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083,   -99, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083,   683, -1083, -1083, -1083, -1083, -1083,   798,
   -1083, -1083, -1083, -1083,  1052, -1083, -1083, -1083, -1083,   800,
   -1083, -1083, -1083, -1083,  1000, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083,    41, -1083, -1083, -1083,    80, -1083, -1083, -1083, -1083,
   -1083,  1078, -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083, -1083,   984, -1083,
   -1083, -1083, -1083, -1083, -1083, -1083, -1083
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   839,   840,  1102,  1103,    27,   227,   228,
     229,   230,    28,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,    29,    77,    78,    79,    80,    81,    30,    63,
     507,   508,   509,   510,    31,    70,   590,   591,   592,   593,
     594,   595,    32,   293,   294,   295,   296,   297,  1059,  1060,
    1061,  1062,  1063,  1238,  1313,  1314,    33,    64,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   765,
    1216,  1217,   533,   759,  1187,  1188,    34,    53,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   632,  1086,  1087,
      35,    61,   493,   744,  1158,  1159,   494,   495,   496,  1162,
    1003,  1004,   497,   498,    36,    59,   471,   472,   473,   474,
     475,   476,   477,   729,  1144,  1145,   478,   479,   480,    37,
      65,   538,   539,   540,   541,   542,    38,   301,   302,   303,
      39,    72,   603,   604,   605,   606,   607,   821,  1256,  1257,
      40,    68,   576,   577,   578,   579,   804,  1233,  1234,    41,
      54,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   655,  1115,  1116,   390,   391,   392,   393,   394,
      42,    60,   484,   485,   486,   487,    43,    55,   398,   399,
     400,   401,    44,   118,   119,   120,    45,    57,   408,   409,
     410,   411,    46,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   441,
     965,   966,   217,   439,   940,   941,   218,   219,   220,    47,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,    48,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     867,   868,   617,   299,   619,   234,   621,   622,   327,   504,
      51,   116,   599,  1113,   291,   585,   395,  1261,  1262,  1263,
     488,   395,   585,   291,   328,   329,    73,   711,   330,    52,
     481,   712,   534,   116,    56,   235,   462,   224,  1155,    58,
     511,   481,    62,   236,   713,    66,   504,   253,   714,   573,
      49,    50,    74,   488,   463,   237,   238,    67,   512,    75,
     239,   240,   241,   299,  1084,   871,   872,  1128,   535,   866,
     464,  1129,   573,   254,   513,   599,   331,   117,   405,   489,
    1055,    69,   396,    71,   113,   242,   490,   396,   491,   114,
     115,   505,   405,   332,   333,   334,   335,   336,   121,   117,
     676,   337,   678,   679,   465,   338,   300,   255,   514,   685,
     221,   339,   489,   689,   536,   600,   256,   693,   586,   490,
     696,   491,   340,   341,   222,   586,  1055,   122,   505,    76,
     706,   707,   123,   124,   342,   125,   126,   225,   257,  1085,
     127,   719,   258,   515,   722,   723,   397,   492,   128,   129,
     259,   397,   574,   260,   261,   130,   343,   223,   131,   466,
     482,   226,   537,   516,   132,  1285,   300,   467,   468,   133,
     134,   482,   135,   136,   137,   574,   138,   231,   600,   517,
     492,   406,  1156,  1056,   232,   262,   587,   506,   469,   139,
     140,  1157,  -129,   587,  1130,   406,   518,   519,  1131,   344,
     141,  -129,   263,   233,   588,   264,   265,   266,   407,  1114,
     142,   588,  1259,   224,  1264,   290,  1260,   143,  1265,   144,
     589,   145,   407,   146,   506,   147,   148,   589,  1268,  1056,
      82,  1270,  1269,   267,   298,  1271,   601,   782,   149,   551,
     602,   292,   646,   150,   151,   152,   520,   153,   154,   155,
     292,   268,   156,    83,    84,   667,   815,   582,   483,    85,
     309,  1099,  1100,  1101,   470,   306,   773,   403,   521,   483,
     735,   502,   305,   575,   767,   739,   269,   270,   157,  1057,
     754,   571,   584,   805,    73,   534,   304,   746,   158,   159,
     160,   161,   162,   163,    86,    87,   575,   597,   462,   601,
      88,    89,   307,   602,  1058,   308,    90,    91,    92,   823,
      74,   809,   673,   225,    93,    94,   463,    75,   853,   311,
     364,   535,   365,   858,   366,  1057,   861,  1278,   499,  1280,
     865,  1279,   464,  1281,   312,   313,   314,   226,   367,    95,
      96,   616,  1282,   164,   165,   166,  1283,   167,   168,   169,
    1058,  1289,   315,  1316,   368,  1290,   234,  1317,   170,   316,
    1239,   460,  1161,   553,   866,   317,   465,   536,   832,   833,
     834,   835,   836,   837,   838,   318,   319,   253,   320,   369,
     321,   370,   322,   323,   324,   402,   235,    76,   371,   412,
     413,   414,   415,   416,   236,   417,   122,   418,   419,   372,
     420,   123,   124,   254,   125,   126,   237,   238,   421,   127,
     422,   239,   240,   241,   423,   537,   424,   128,   129,   425,
     426,   466,   427,   373,   130,   428,   429,   131,   430,   467,
     468,   431,  1304,   132,   432,   433,   242,   255,   133,   134,
     434,   135,   136,   137,   435,   138,   256,   374,   436,   580,
     469,  1074,  1075,  1076,  1077,  1078,  1079,  1080,   139,   140,
     437,   438,   440,  1305,   325,  1306,   611,   375,   257,   141,
     442,   443,   258,  1167,   444,   445,   376,   446,   447,   142,
     259,   448,   449,   260,   261,   450,   143,   608,   144,  1168,
     145,   451,   146,   452,   147,   148,   453,  1169,   454,   455,
     456,   457,   458,   459,   500,   501,   543,   149,   544,   545,
    1307,  1170,   150,   151,   152,   262,   153,   154,   155,   546,
     609,   156,   547,   548,   377,   549,   470,  1308,   550,   554,
     511,   555,   263,   556,   610,   264,   265,   266,   557,   558,
     559,   560,  1171,   561,  1172,   562,   563,   157,   512,   378,
     564,   565,   566,   567,   663,   568,   612,   158,   159,   160,
     161,   162,   163,   267,   513,  1309,  1310,   364,   569,   365,
    1173,   366,   570,   581,   596,   613,   614,   615,   616,   618,
     620,   268,   623,   625,   624,   367,   626,   627,   628,   629,
     648,   669,   677,  1286,   630,   670,   631,   675,   514,  1134,
     633,   368,   634,  1174,   681,  1175,   269,   270,   635,   636,
     637,   638,   164,   165,   166,   639,   167,   168,   169,  1311,
    1135,   640,   641,  1312,  1176,   642,   369,   170,   370,  1136,
     643,   327,   680,   515,   644,   371,   645,   649,   650,     2,
       3,   651,   682,     4,   652,  1177,   372,   328,   329,   653,
    1178,   330,   654,   516,  1179,     5,   656,   657,     6,     7,
    1137,   658,   659,  1180,   660,     8,   661,  1181,   662,   517,
     373,   665,   666,   671,   672,   683,     9,   687,  1182,    10,
      11,  1183,   943,  1184,   944,   945,   518,   519,   684,  1138,
    1139,   686,   688,   690,   374,  1185,   691,  1140,   692,   331,
     694,   695,  1186,   697,   698,   699,   700,    12,   701,   703,
     702,   704,    13,   705,   375,   708,   332,   333,   334,   335,
     336,    14,  1141,   376,   337,   709,   710,  1194,   338,  1195,
    1196,   715,   716,   717,   339,   718,   520,   720,  1142,   721,
     724,    15,    16,   727,   728,   340,   341,   725,   726,   730,
     775,   748,   749,   778,   741,   731,   732,   342,   521,    17,
     787,   784,   733,   734,   737,   738,   786,   920,   742,   743,
     745,   377,   750,   751,   752,   756,    18,   753,   776,   343,
     757,   758,   760,   761,   762,   763,   764,   766,   769,    19,
      20,   777,   770,   771,   772,   788,   378,   779,   780,  1143,
     946,   947,   948,   783,   781,   949,   950,   789,   951,   952,
    1223,   953,    21,   954,   785,   790,   955,   791,   792,   956,
     957,  1246,   344,   793,   958,    22,   794,   795,   959,   796,
      23,   797,   960,   961,   962,    24,   798,   799,    25,   963,
     800,   801,   802,   803,   964,  1197,  1198,  1199,   808,   807,
    1200,  1201,   810,  1202,  1203,   817,  1204,   811,  1205,   851,
     862,  1206,   812,   813,  1207,  1208,   814,   852,   818,  1209,
     819,   855,  1224,  1210,   825,   820,   826,  1211,  1212,  1213,
     822,   827,   828,  1247,  1214,   921,   922,   923,   829,  1215,
     924,   925,   830,   926,   927,   831,   928,   841,   929,   842,
     843,   930,   844,  1225,   931,   932,   845,   846,   847,   933,
      82,  1226,   854,   934,  1248,   856,   848,   935,   936,   937,
    1227,   849,  1249,   857,   938,   850,   859,   860,   863,   939,
     864,  1250,   866,    83,    84,   869,   870,   873,   874,    85,
     875,   877,   880,   885,  1228,  1160,  1229,  1230,   876,   878,
     879,   881,   882,   883,   884,  1251,   886,  1252,  1253,   887,
     890,  1231,   888,   889,   891,   987,   892,   893,  1232,   990,
     894,   895,  1254,   896,    86,    87,   897,   898,   899,  1255,
      88,    89,   900,   901,   902,   903,    90,    91,    92,   904,
     905,   989,   906,   907,    93,    94,   908,   909,   910,   911,
     912,   913,   914,   915,   916,   917,   918,   919,   942,   967,
     968,   969,   970,   971,   972,   973,   974,   975,   976,    95,
      96,   977,   978,   979,   980,   981,   982,   983,   984,   985,
     986,   988,   991,   992,   993,   994,   995,   996,   998,   997,
     999,  1000,  1001,  1002,  1005,  1008,  1009,   816,  1011,  1012,
    1014,  1006,  1015,  1016,  1017,  1018,  1020,  1022,   310,  1023,
    1007,  1024,  1051,  1010,  1064,  1065,  1066,  1067,  1070,  1013,
    1072,  1019,  1021,  1318,  1052,  1025,  1026,  1027,  1028,  1029,
    1030,  1031,  1032,  1033,  1034,  1035,  1036,  1037,  1038,  1039,
    1040,  1041,  1042,  1043,  1044,  1045,  1046,  1047,  1048,  1049,
    1050,  1053,  1054,  1068,  1069,  1272,  1073,  1081,  1071,  1082,
    1083,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,
    1097,  1098,  1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,
    1112,  1117,  1118,  1119,  1120,  1121,  1122,  1123,  1284,  1295,
    1296,  1124,  1297,  1240,  1299,   572,  1298,  1125,  1126,  1127,
     768,   755,  1291,   747,  1132,  1294,  1133,  1273,  1293,  1315,
    1146,   736,   824,  1300,   664,  1147,  1292,   740,  1148,   806,
     404,   461,  1267,   774,  1149,   326,  1150,  1151,  1152,  1153,
    1154,  1163,  1164,  1165,  1166,  1189,  1190,  1191,  1192,  1193,
    1218,  1219,  1220,  1221,  1222,  1235,   668,     0,  1241,  1236,
    1237,  1242,  1243,  1244,  1245,  1258,  1274,   503,   674,  1266,
    1288,  1301,  1275,  1276,  1277,  1287,  1302,  1303,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   552,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   583,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     598,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   647
};

static const yytype_int16 yycheck[] =
{
     644,   645,   315,     1,   317,     1,   319,   320,     1,     1,
     236,     1,     1,     8,     1,     1,     1,  1099,  1100,  1101,
       1,     1,     1,     1,    17,    18,     1,   216,    21,   236,
       1,   220,     1,     1,   236,    31,     1,     1,    51,   236,
       1,     1,   236,    39,   216,   236,     1,     1,   220,     1,
     234,   235,    27,     1,    19,    51,    52,   236,    19,    34,
      56,    57,    58,     1,    55,   183,   184,   234,    37,   114,
      35,   238,     1,    27,    35,     1,    69,    67,     1,    60,
       1,   236,    67,   236,   236,    81,    67,    67,    69,   236,
     236,    83,     1,    86,    87,    88,    89,    90,   236,    67,
     413,    94,   415,   416,    69,    98,   104,    61,    69,   422,
     236,   104,    60,   426,    83,   104,    70,   430,   104,    67,
     433,    69,   115,   116,   236,   104,     1,     1,    83,   104,
     443,   444,     6,     7,   127,     9,    10,   101,    92,   130,
      14,   454,    96,   104,   457,   458,   131,   128,    22,    23,
     104,   131,   104,   107,   108,    29,   149,   236,    32,   124,
     131,   125,   131,   124,    38,   210,   104,   132,   133,    43,
      44,   131,    46,    47,    48,   104,    50,   236,   104,   140,
     128,   104,   195,   104,   236,   139,   172,   179,   153,    63,
      64,   204,   179,   172,   234,   104,   157,   158,   238,   192,
      74,   179,   156,   236,   190,   159,   160,   161,   131,   204,
      84,   190,   234,     1,   234,   236,   238,    91,   238,    93,
     206,    95,   131,    97,   179,    99,   100,   206,   234,   104,
       1,   234,   238,   187,   236,   238,   225,   550,   112,   235,
     229,   228,   235,   117,   118,   119,   207,   121,   122,   123,
     228,   205,   126,    24,    25,   235,   235,   235,   229,    30,
     235,    11,    12,    13,   229,   237,   235,   235,   229,   229,
     235,   235,   234,   225,   235,   235,   230,   231,   152,   200,
     235,   235,   179,   235,     1,     1,   236,   235,   162,   163,
     164,   165,   166,   167,    65,    66,   225,   235,     1,   225,
      71,    72,   237,   229,   225,   237,    77,    78,    79,   235,
      27,   236,   235,   101,    85,    86,    19,    34,   631,   237,
       1,    37,     3,   636,     5,   200,   639,   234,   234,   234,
     643,   238,    35,   238,   237,   237,   237,   125,    19,   110,
     111,   114,   234,   217,   218,   219,   238,   221,   222,   223,
     225,   234,   237,   234,    35,   238,     1,   238,   232,   237,
     235,   235,   238,   234,   114,   237,    69,    83,   141,   142,
     143,   144,   145,   146,   147,   237,   237,     1,   237,    60,
     237,    62,   237,   237,   237,   237,    31,   104,    69,   237,
     237,   237,   237,   237,    39,   237,     1,   237,   237,    80,
     237,     6,     7,    27,     9,    10,    51,    52,   237,    14,
     237,    56,    57,    58,   237,   131,   237,    22,    23,   237,
     237,   124,   237,   104,    29,   237,   237,    32,   237,   132,
     133,   237,    42,    38,   237,   237,    81,    61,    43,    44,
     237,    46,    47,    48,   237,    50,    70,   128,   237,   234,
     153,   832,   833,   834,   835,   836,   837,   838,    63,    64,
     237,   237,   237,    73,   235,    75,   234,   148,    92,    74,
     237,   237,    96,     4,   237,   237,   157,   237,   237,    84,
     104,   237,   237,   107,   108,   237,    91,   129,    93,    20,
      95,   237,    97,   237,    99,   100,   237,    28,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   112,   237,   237,
     120,    42,   117,   118,   119,   139,   121,   122,   123,   237,
     129,   126,   237,   237,   205,   237,   229,   137,   237,   237,
       1,   237,   156,   237,   129,   159,   160,   161,   237,   237,
     237,   237,    73,   237,    75,   237,   237,   152,    19,   230,
     237,   237,   237,   237,   235,   237,   114,   162,   163,   164,
     165,   166,   167,   187,    35,   175,   176,     1,   237,     3,
     101,     5,   237,   237,   237,   114,   216,   114,   114,   114,
     114,   205,   114,   216,   114,    19,   216,   234,   234,   237,
     234,   129,   114,  1237,   237,   234,   237,   216,    69,    15,
     237,    35,   237,   134,   114,   136,   230,   231,   237,   237,
     237,   237,   217,   218,   219,   237,   221,   222,   223,   229,
      36,   237,   237,   233,   155,   237,    60,   232,    62,    45,
     237,     1,   216,   104,   237,    69,   237,   237,   237,     0,
       1,   237,   216,     4,   237,   176,    80,    17,    18,   237,
     181,    21,   237,   124,   185,    16,   237,   237,    19,    20,
      76,   237,   237,   194,   237,    26,   237,   198,   237,   140,
     104,   237,   237,   237,   237,   114,    37,   114,   209,    40,
      41,   212,    51,   214,    53,    54,   157,   158,   216,   105,
     106,   216,   114,   114,   128,   226,   216,   113,   216,    69,
     114,   114,   233,   114,   114,   114,   114,    68,   216,   216,
     237,   237,    73,   216,   148,   216,    86,    87,    88,    89,
      90,    82,   138,   157,    94,   216,   216,    51,    98,    53,
      54,   216,   216,   216,   104,   114,   207,   216,   154,   216,
     216,   102,   103,   237,   237,   115,   116,   234,   234,   237,
     216,   129,   129,   129,   234,   237,   237,   127,   229,   120,
     114,   129,   237,   237,   237,   237,   129,    51,   237,   237,
     237,   205,   234,   234,   237,   234,   137,   237,   216,   149,
     237,   237,   237,   237,   237,   237,   237,   237,   234,   150,
     151,   216,   237,   237,   237,   114,   230,   216,   216,   215,
     169,   170,   171,   234,   216,   174,   175,   129,   177,   178,
      75,   180,   173,   182,   216,   129,   185,   129,   129,   188,
     189,    75,   192,   129,   193,   186,   129,   129,   197,   129,
     191,   114,   201,   202,   203,   196,   129,   129,   199,   208,
     129,   234,   234,   237,   213,   169,   170,   171,   234,   216,
     174,   175,   234,   177,   178,   129,   180,   237,   182,   114,
     129,   185,   237,   237,   188,   189,   237,   114,   234,   193,
     234,   114,   137,   197,   234,   237,   234,   201,   202,   203,
     237,   234,   234,   137,   208,   169,   170,   171,   234,   213,
     174,   175,   234,   177,   178,   234,   180,   234,   182,   234,
     234,   185,   234,   168,   188,   189,   234,   234,   234,   193,
       1,   176,   237,   197,   168,   114,   234,   201,   202,   203,
     185,   234,   176,   114,   208,   234,   114,   114,   114,   213,
     114,   185,   114,    24,    25,   234,   129,   129,   216,    30,
     129,   237,   114,   234,   209,   224,   211,   212,   129,   129,
     129,   129,   129,   129,   129,   209,   129,   211,   212,   129,
     129,   226,   234,   234,   129,   129,   234,   234,   233,   129,
     234,   234,   226,   234,    65,    66,   234,   234,   234,   233,
      71,    72,   234,   234,   234,   234,    77,    78,    79,   234,
     234,   237,   234,   234,    85,    86,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   110,
     111,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   216,   114,   129,   129,   129,   234,   129,   234,   129,
     129,   129,   237,   114,   234,   129,   129,   590,   129,   216,
     129,   234,   129,   129,   129,   216,   129,   129,    77,   129,
     234,   129,   129,   234,   129,   129,   129,   129,   129,   237,
     129,   237,   234,  1317,   237,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   114,   234,   234,   237,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   129,   135,
     135,   234,   135,  1059,  1281,   271,  1279,   234,   234,   234,
     522,   507,  1260,   494,   234,  1271,   234,  1161,  1269,  1290,
     234,   471,   603,  1283,   379,   234,  1265,   484,   234,   576,
     118,   171,  1131,   538,   234,    97,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   398,    -1,   234,   237,
     237,   234,   234,   234,   234,   234,   234,   227,   408,  1129,
     234,   234,   239,   239,   239,   237,   234,   234,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   293,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     301,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   345
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   241,     0,     1,     4,    16,    19,    20,    26,    37,
      40,    41,    68,    73,    82,   102,   103,   120,   137,   150,
     151,   173,   186,   191,   196,   199,   242,   247,   252,   272,
     278,   284,   292,   306,   326,   350,   364,   379,   386,   390,
     400,   409,   430,   436,   442,   446,   452,   509,   526,   234,
     235,   236,   236,   327,   410,   437,   236,   447,   236,   365,
     431,   351,   236,   279,   307,   380,   236,   236,   401,   236,
     285,   236,   391,     1,    27,    34,   104,   273,   274,   275,
     276,   277,     1,    24,    25,    30,    65,    66,    71,    72,
      77,    78,    79,    85,    86,   110,   111,   510,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   236,   236,   236,     1,    67,   443,   444,
     445,   236,     1,     6,     7,     9,    10,    14,    22,    23,
      29,    32,    38,    43,    44,    46,    47,    48,    50,    63,
      64,    74,    84,    91,    93,    95,    97,    99,   100,   112,
     117,   118,   119,   121,   122,   123,   126,   152,   162,   163,
     164,   165,   166,   167,   217,   218,   219,   221,   222,   223,
     232,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   502,   506,   507,
     508,   236,   236,   236,     1,   101,   125,   248,   249,   250,
     251,   236,   236,   236,     1,    31,    39,    51,    52,    56,
      57,    58,    81,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,     1,    27,    61,    70,    92,    96,   104,
     107,   108,   139,   156,   159,   160,   161,   187,   205,   230,
     231,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     236,     1,   228,   293,   294,   295,   296,   297,   236,     1,
     104,   387,   388,   389,   236,   234,   237,   237,   237,   235,
     274,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   235,   511,     1,    17,    18,
      21,    69,    86,    87,    88,    89,    90,    94,    98,   104,
     115,   116,   127,   149,   192,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,     1,     3,     5,    19,    35,    60,
      62,    69,    80,   104,   128,   148,   157,   205,   230,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     425,   426,   427,   428,   429,     1,    67,   131,   438,   439,
     440,   441,   237,   235,   444,     1,   104,   131,   448,   449,
     450,   451,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   503,
     237,   499,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     235,   454,     1,    19,    35,    69,   124,   132,   133,   153,
     229,   366,   367,   368,   369,   370,   371,   372,   376,   377,
     378,     1,   131,   229,   432,   433,   434,   435,     1,    60,
      67,    69,   128,   352,   356,   357,   358,   362,   363,   234,
     237,   237,   235,   249,     1,    83,   179,   280,   281,   282,
     283,     1,    19,    35,    69,   104,   124,   140,   157,   158,
     207,   229,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   322,     1,    37,    83,   131,   381,   382,
     383,   384,   385,   237,   237,   237,   237,   237,   237,   237,
     237,   235,   528,   234,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   235,   254,     1,   104,   225,   402,   403,   404,   405,
     234,   237,   235,   294,   179,     1,   104,   172,   190,   206,
     286,   287,   288,   289,   290,   291,   237,   235,   388,     1,
     104,   225,   229,   392,   393,   394,   395,   396,   129,   129,
     129,   234,   114,   114,   216,   114,   114,   244,   114,   244,
     114,   244,   244,   114,   114,   216,   216,   234,   234,   237,
     237,   237,   347,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   235,   329,   234,   237,
     237,   237,   237,   237,   237,   422,   237,   237,   237,   237,
     237,   237,   237,   235,   412,   237,   237,   235,   439,   129,
     234,   237,   237,   235,   449,   216,   244,   114,   244,   244,
     216,   114,   216,   114,   216,   244,   216,   114,   114,   244,
     114,   216,   216,   244,   114,   114,   244,   114,   114,   114,
     114,   216,   237,   216,   237,   216,   244,   244,   216,   216,
     216,   216,   220,   216,   220,   216,   216,   216,   114,   244,
     216,   216,   244,   244,   216,   234,   234,   237,   237,   373,
     237,   237,   237,   237,   237,   235,   367,   237,   237,   235,
     433,   234,   237,   237,   353,   237,   235,   357,   129,   129,
     234,   234,   237,   237,   235,   281,   234,   237,   237,   323,
     237,   237,   237,   237,   237,   319,   237,   235,   309,   234,
     237,   237,   237,   235,   382,   216,   216,   216,   129,   216,
     216,   216,   244,   234,   129,   216,   129,   114,   114,   129,
     129,   129,   129,   129,   129,   129,   129,   114,   129,   129,
     129,   234,   234,   237,   406,   235,   403,   216,   234,   236,
     234,   237,   237,   237,   237,   235,   287,   129,   234,   234,
     237,   397,   237,   235,   393,   234,   234,   234,   234,   234,
     234,   234,   141,   142,   143,   144,   145,   146,   147,   243,
     244,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   114,   114,   244,   237,   114,   114,   114,   244,   114,
     114,   244,   129,   114,   114,   244,   114,   246,   246,   234,
     129,   183,   184,   129,   216,   129,   129,   237,   129,   129,
     114,   129,   129,   129,   129,   234,   129,   129,   234,   234,
     129,   129,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
      51,   169,   170,   171,   174,   175,   177,   178,   180,   182,
     185,   188,   189,   193,   197,   201,   202,   203,   208,   213,
     504,   505,   234,    51,    53,    54,   169,   170,   171,   174,
     175,   177,   178,   180,   182,   185,   188,   189,   193,   197,
     201,   202,   203,   208,   213,   500,   501,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   129,   216,   237,
     129,   114,   129,   129,   129,   234,   129,   129,   234,   129,
     129,   237,   114,   360,   361,   234,   234,   234,   129,   129,
     234,   129,   216,   237,   129,   129,   129,   129,   216,   237,
     129,   234,   129,   129,   129,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   129,   237,   234,   234,     1,   104,   200,   225,   298,
     299,   300,   301,   302,   129,   129,   129,   129,   234,   234,
     129,   237,   129,   234,   243,   243,   243,   243,   243,   243,
     243,   234,   234,   234,    55,   130,   348,   349,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,    11,
      12,    13,   245,   246,   234,   234,   234,   234,   234,   234,
     234,   234,   234,     8,   204,   423,   424,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   238,
     234,   238,   234,   234,    15,    36,    45,    76,   105,   106,
     113,   138,   154,   215,   374,   375,   234,   234,   234,   234,
     234,   234,   234,   234,   234,    51,   195,   204,   354,   355,
     224,   238,   359,   234,   234,   234,   234,     4,    20,    28,
      42,    73,    75,   101,   134,   136,   155,   176,   181,   185,
     194,   198,   209,   212,   214,   226,   233,   324,   325,   234,
     234,   234,   234,   234,    51,    53,    54,   169,   170,   171,
     174,   175,   177,   178,   180,   182,   185,   188,   189,   193,
     197,   201,   202,   203,   208,   213,   320,   321,   234,   234,
     234,   234,   234,    75,   137,   168,   176,   185,   209,   211,
     212,   226,   233,   407,   408,   234,   237,   237,   303,   235,
     299,   234,   234,   234,   234,   234,    75,   137,   168,   176,
     185,   209,   211,   212,   226,   233,   398,   399,   234,   234,
     238,   245,   245,   245,   234,   238,   505,   501,   234,   238,
     234,   238,   114,   361,   234,   239,   239,   239,   234,   238,
     234,   238,   234,   238,   129,   210,   246,   237,   234,   234,
     238,   349,   424,   375,   355,   135,   135,   135,   325,   321,
     408,   234,   234,   234,    42,    73,    75,   120,   137,   175,
     176,   229,   233,   304,   305,   399,   234,   238,   305
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   240,   241,   241,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   243,   243,
     244,   244,   244,   244,   244,   244,   244,   244,   245,   245,
     246,   246,   246,   246,   247,   248,   248,   249,   249,   249,
     250,   251,   252,   253,   253,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   273,   274,   274,   274,   274,   275,   276,   277,
     279,   278,   280,   280,   281,   281,   281,   282,   283,   285,
     284,   286,   286,   287,   287,   287,   287,   287,   288,   289,
     290,   291,   292,   293,   293,   294,   294,   294,   295,   297,
     296,   298,   298,   299,   299,   299,   299,   300,   301,   301,
     303,   302,   304,   304,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   307,   306,   308,   308,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   319,   318,   320,   320,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   323,   322,   324,   324,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   327,
     326,   328,   328,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   347,   346,   348,
     348,   349,   349,   351,   350,   353,   352,   354,   354,   355,
     355,   355,   356,   356,   357,   357,   357,   357,   357,   359,
     358,   360,   360,   361,   361,   362,   363,   365,   364,   366,
     366,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     368,   369,   370,   371,   373,   372,   374,   374,   375,   375,
     375,   375,   375,   375,   375,   375,   375,   375,   376,   377,
     378,   380,   379,   381,   381,   382,   382,   382,   382,   383,
     384,   385,   386,   387,   387,   388,   388,   389,   391,   390,
     392,   392,   393,   393,   393,   393,   394,   395,   397,   396,
     398,   398,   399,   399,   399,   399,   399,   399,   399,   399,
     399,   399,   401,   400,   402,   402,   403,   403,   403,   404,
     406,   405,   407,   407,   408,   408,   408,   408,   408,   408,
     408,   408,   408,   408,   410,   409,   411,   411,   412,   412,
     412,   412,   412,   412,   412,   412,   412,   412,   412,   412,
     412,   412,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   420,   422,   421,   423,   423,   424,   424,   425,   426,
     427,   428,   429,   431,   430,   432,   432,   433,   433,   433,
     434,   435,   437,   436,   438,   438,   439,   439,   439,   440,
     441,   442,   443,   443,   444,   444,   445,   447,   446,   448,
     448,   449,   449,   449,   450,   451,   452,   453,   453,   454,
     454,   454,   454,   454,   454,   454,   454,   454,   454,   454,
     454,   454,   454,   454,   454,   454,   454,   454,   454,   454,
     454,   454,   454,   454,   454,   454,   454,   454,   454,   454,
     454,   454,   454,   454,   454,   454,   454,   454,   454,   454,
     454,   454,   454,   454,   454,   454,   454,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   482,   483,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   499,   498,   500,   500,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   503,
     502,   504,   504,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   506,   507,   508,   509,   510,   510,   511,
     511,   511,   511,   511,   511,   511,   511,   511,   511,   511,
     511,   511,   511,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     527,   528,   528,   528,   528,   528,   528,   528,   528,   528,
     529,   530,   531,   532,   533,   534,   535,   536
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     0,     1,
       2,     3,     3,     3,     3,     3,     3,     3,     0,     1,
       2,     3,     3,     3,     5,     2,     1,     1,     1,     2,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     2,     4,     4,     4,
       0,     6,     2,     1,     1,     1,     2,     4,     4,     0,
       6,     2,     1,     1,     1,     1,     1,     2,     4,     4,
       4,     4,     5,     2,     1,     1,     1,     2,     4,     0,
       6,     2,     1,     1,     1,     1,     2,     4,     4,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     4,
       4,     4,     4,     4,     4,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     5,     3,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       6,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     0,     5,     3,
       1,     1,     1,     0,     6,     0,     5,     3,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     2,     0,
       5,     3,     1,     1,     3,     4,     4,     0,     6,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     0,     6,     2,     1,     1,     1,     1,     2,     4,
       4,     4,     5,     2,     1,     1,     1,     4,     0,     6,
       2,     1,     1,     1,     1,     2,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     2,     1,     1,     1,     2,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     6,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     0,     5,     3,     1,     1,     1,     4,     4,
       4,     4,     4,     0,     6,     2,     1,     1,     1,     1,
       4,     4,     0,     6,     2,     1,     1,     1,     1,     4,
       4,     5,     2,     1,     1,     1,     4,     0,     6,     2,
       1,     1,     1,     1,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
#ifndef YYINITDEPTH
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
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
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
      YYSIZE_T yyn = 0;
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

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
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 28:
#line 420 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2880 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 421 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2886 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 422 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2892 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 423 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2898 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 424 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2904 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 425 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2910 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 426 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2916 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 427 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2922 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 428 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2928 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 431 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2934 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 432 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2940 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 433 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2946 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 434 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2952 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 435 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2958 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 449 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2967 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 455 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2976 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 485 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
  {
    if (!ConfigServerInfo.rsa_private_key_file)
    {
      conf_error_report("No rsa_private_key_file specified, SSL disabled");
      break;
    }

    if (SSL_CTX_use_certificate_chain_file(ConfigServerInfo.server_ctx, yylval.string) <= 0 ||
        SSL_CTX_use_certificate_chain_file(ConfigServerInfo.client_ctx, yylval.string) <= 0)
    {
      report_crypto_errors();
      conf_error_report("Could not open/read certificate file");
      break;
    }

    if (SSL_CTX_use_PrivateKey_file(ConfigServerInfo.server_ctx, ConfigServerInfo.rsa_private_key_file,
                                    SSL_FILETYPE_PEM) <= 0 ||
        SSL_CTX_use_PrivateKey_file(ConfigServerInfo.client_ctx, ConfigServerInfo.rsa_private_key_file,
                                    SSL_FILETYPE_PEM) <= 0)
    {
      report_crypto_errors();
      conf_error_report("Could not read RSA private key");
      break;
    }

    if (!SSL_CTX_check_private_key(ConfigServerInfo.server_ctx) ||
        !SSL_CTX_check_private_key(ConfigServerInfo.client_ctx))
    {
      report_crypto_errors();
      conf_error_report("Could not read RSA private key");
      break;
    }
  }
#endif
}
#line 3019 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 525 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  BIO *file = NULL;

  if (conf_parser_ctx.pass != 1)
    break;

  if (ConfigServerInfo.rsa_private_key)
  {
    RSA_free(ConfigServerInfo.rsa_private_key);
    ConfigServerInfo.rsa_private_key = NULL;
  }

  if (ConfigServerInfo.rsa_private_key_file)
  {
    MyFree(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = NULL;
  }

  ConfigServerInfo.rsa_private_key_file = xstrdup(yylval.string);

  if ((file = BIO_new_file(yylval.string, "r")) == NULL)
  {
    conf_error_report("File open failed, ignoring");
    break;
  }

  ConfigServerInfo.rsa_private_key = PEM_read_bio_RSAPrivateKey(file, NULL, 0, NULL);

  BIO_set_close(file, BIO_CLOSE);
  BIO_free(file);

  if (ConfigServerInfo.rsa_private_key == NULL)
  {
    conf_error_report("Couldn't extract key, ignoring");
    break;
  }

  if (!RSA_check_key(ConfigServerInfo.rsa_private_key))
  {
    RSA_free(ConfigServerInfo.rsa_private_key);
    ConfigServerInfo.rsa_private_key = NULL;

    conf_error_report("Invalid key, ignoring");
    break;
  }

  if (RSA_size(ConfigServerInfo.rsa_private_key) < 128)
  {
    RSA_free(ConfigServerInfo.rsa_private_key);
    ConfigServerInfo.rsa_private_key = NULL;

    conf_error_report("Ignoring serverinfo::rsa_private_key_file -- need at least a 1024 bit key size");
  }
#endif
}
#line 3080 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 583 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
  {
    BIO *file = BIO_new_file(yylval.string, "r");

    if (file)
    {
      DH *dh = PEM_read_bio_DHparams(file, NULL, NULL, NULL);

      BIO_free(file);

      if (dh)
      {
        if (DH_size(dh) < 128)
          conf_error_report("Ignoring serverinfo::ssl_dh_param_file -- need at least a 1024 bit DH prime size");
        else
          SSL_CTX_set_tmp_dh(ConfigServerInfo.server_ctx, dh);

        DH_free(dh);
      }
    }
    else
      conf_error_report("Ignoring serverinfo::ssl_dh_param_file -- could not open/read Diffie-Hellman parameter file");
  }
#endif
}
#line 3112 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 612 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    SSL_CTX_set_cipher_list(ConfigServerInfo.server_ctx, yylval.string);
#endif
}
#line 3123 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 620 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
  {
    if ((ConfigServerInfo.message_digest_algorithm = EVP_get_digestbyname(yylval.string)) == NULL)
    {
      ConfigServerInfo.message_digest_algorithm = EVP_sha256();
      conf_error_report("Ignoring serverinfo::ssl_message_digest_algorithm -- unknown message digest algorithm");
    }
  }
#endif
}
#line 3140 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 634 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
#if OPENSSL_VERSION_NUMBER >= 0x009080FFL && !defined(OPENSSL_NO_ECDH)
  int nid = 0;
  EC_KEY *key = NULL;

  if (conf_parser_ctx.pass == 2)
  {
    if ((nid = OBJ_sn2nid(yylval.string)) == 0)
    {
        conf_error_report("Ignoring serverinfo::serverinfo_ssl_dh_elliptic_curve -- unknown curve name");
        break;
    }

    if ((key = EC_KEY_new_by_curve_name(nid)) == NULL)
    {
      conf_error_report("Ignoring serverinfo::serverinfo_ssl_dh_elliptic_curve -- could not create curve");
      break;
    }

    SSL_CTX_set_tmp_ecdh(ConfigServerInfo.server_ctx, key);
    EC_KEY_free(key);
}
#endif
#endif
}
#line 3171 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 662 "conf_parser.y" /* yacc.c:1646  */
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ConfigServerInfo.name)
  {
    if (valid_servname(yylval.string))
      ConfigServerInfo.name = xstrdup(yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::name -- invalid name. Aborting.");
      exit(0);
    }
  }
}
#line 3189 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 677 "conf_parser.y" /* yacc.c:1646  */
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ConfigServerInfo.sid)
  {
    if (valid_sid(yylval.string))
      ConfigServerInfo.sid = xstrdup(yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::sid -- invalid SID. Aborting.");
      exit(0);
    }
  }
}
#line 3207 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 692 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerInfo.description);
    ConfigServerInfo.description = xstrdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3220 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 702 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *p;

    if ((p = strchr(yylval.string, ' ')))
      *p = '\0';

    MyFree(ConfigServerInfo.network_name);
    ConfigServerInfo.network_name = xstrdup(yylval.string);
  }
}
#line 3237 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 716 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3249 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 725 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2 && *yylval.string != '*')
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(LOG_TYPE_IRCD, "Invalid netmask for server vhost(%s)", yylval.string);
    else
    {
      assert(res);

      memcpy(&ConfigServerInfo.ip, res->ai_addr, res->ai_addrlen);
      ConfigServerInfo.ip.ss.ss_family = res->ai_family;
      ConfigServerInfo.ip.ss_len = res->ai_addrlen;
      freeaddrinfo(res);

      ConfigServerInfo.specific_ipv4_vhost = 1;
    }
  }
}
#line 3280 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 753 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2 && *yylval.string != '*')
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(LOG_TYPE_IRCD, "Invalid netmask for server vhost6(%s)", yylval.string);
    else
    {
      assert(res);

      memcpy(&ConfigServerInfo.ip6, res->ai_addr, res->ai_addrlen);
      ConfigServerInfo.ip6.ss.ss_family = res->ai_family;
      ConfigServerInfo.ip6.ss_len = res->ai_addrlen;
      freeaddrinfo(res);

      ConfigServerInfo.specific_ipv6_vhost = 1;
    }
  }
}
#line 3311 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 781 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].number) < MAXCLIENTS_MIN)
  {
    char buf[IRCD_BUFSIZE] = "";

    snprintf(buf, sizeof(buf), "MAXCLIENTS too low, setting to %d", MAXCLIENTS_MIN);
    conf_error_report(buf);
    ConfigServerInfo.max_clients = MAXCLIENTS_MIN;
  }
  else if ((yyvsp[-1].number) > MAXCLIENTS_MAX)
  {
    char buf[IRCD_BUFSIZE] = "";

    snprintf(buf, sizeof(buf), "MAXCLIENTS too high, setting to %d", MAXCLIENTS_MAX);
    conf_error_report(buf);
    ConfigServerInfo.max_clients = MAXCLIENTS_MAX;
  }
  else
    ConfigServerInfo.max_clients = (yyvsp[-1].number);
}
#line 3339 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 806 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].number) < 9)
  {
    conf_error_report("max_nick_length too low, setting to 9");
    ConfigServerInfo.max_nick_length = 9;
  }
  else if ((yyvsp[-1].number) > NICKLEN)
  {
    char buf[IRCD_BUFSIZE] = "";

    snprintf(buf, sizeof(buf), "max_nick_length too high, setting to %d", NICKLEN);
    conf_error_report(buf);
    ConfigServerInfo.max_nick_length = NICKLEN;
  }
  else
    ConfigServerInfo.max_nick_length = (yyvsp[-1].number);
}
#line 3364 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 828 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].number) < 80)
  {
    conf_error_report("max_topic_length too low, setting to 80");
    ConfigServerInfo.max_topic_length = 80;
  }
  else if ((yyvsp[-1].number) > TOPICLEN)
  {
    char buf[IRCD_BUFSIZE] = "";

    snprintf(buf, sizeof(buf), "max_topic_length too high, setting to %d", TOPICLEN);
    conf_error_report(buf);
    ConfigServerInfo.max_topic_length = TOPICLEN;
  }
  else
    ConfigServerInfo.max_topic_length = (yyvsp[-1].number);
}
#line 3389 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 850 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3398 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 867 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3410 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 876 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3422 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 885 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3434 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 897 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3443 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 901 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3460 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 918 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3469 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 924 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3478 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 933 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3487 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 937 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.command.buf[0] ||
      !block_state.name.buf[0] ||
      !block_state.nick.buf[0] ||
      !block_state.host.buf[0])
    break;

  pseudo_register(block_state.name.buf, block_state.nick.buf, block_state.host.buf,
                  block_state.prepend.buf, block_state.command.buf);
}
#line 3505 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 955 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3514 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 961 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3523 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 967 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3532 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 973 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = block_state.user.buf;
    nuh.hostptr  = block_state.host.buf;
    nuh.nicksize = 0;
    nuh.usersize = sizeof(block_state.nick.buf);
    nuh.hostsize = sizeof(block_state.host.buf);
    split_nuh(&nuh);

    strlcpy(block_state.nick.buf, nuh.userptr, sizeof(block_state.nick.buf));
    strlcpy(block_state.host.buf, nuh.hostptr, sizeof(block_state.host.buf));
  }
}
#line 3555 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1002 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3564 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1008 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3573 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1012 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3586 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1028 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3597 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1036 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3605 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1039 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3613 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1044 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3622 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1051 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3631 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1055 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3640 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1059 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
#line 3649 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1063 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3658 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1067 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3667 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1071 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3676 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1075 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3685 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1079 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3694 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1083 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3703 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1093 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3715 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1100 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0])
    break;
#ifdef HAVE_LIBCRYPTO
  if (!block_state.file.buf[0] &&
      !block_state.rpass.buf[0])
    break;
#else
  if (!block_state.rpass.buf[0])
    break;
#endif

  DLINK_FOREACH(node, block_state.mask.list.head)
  {
    struct MaskItem *conf = NULL;
    struct split_nuh_item nuh;

    nuh.nuhmask  = node->data;
    nuh.nickptr  = NULL;
    nuh.userptr  = block_state.user.buf;
    nuh.hostptr  = block_state.host.buf;
    nuh.nicksize = 0;
    nuh.usersize = sizeof(block_state.user.buf);
    nuh.hostsize = sizeof(block_state.host.buf);
    split_nuh(&nuh);

    conf         = conf_make(CONF_OPER);
    conf->name   = xstrdup(block_state.name.buf);
    conf->user   = xstrdup(block_state.user.buf);
    conf->host   = xstrdup(block_state.host.buf);

    if (block_state.cert.buf[0])
      conf->certfp = xstrdup(block_state.cert.buf);

    if (block_state.rpass.buf[0])
      conf->passwd = xstrdup(block_state.rpass.buf);

    conf->flags = block_state.flags.value;
    conf->modes = block_state.modes.value;
    conf->port  = block_state.port.value;
    conf->htype = parse_netmask(conf->host, &conf->addr, &conf->bits);

    conf_add_class_to_conf(conf, block_state.class.buf);

#ifdef HAVE_LIBCRYPTO
    if (block_state.file.buf[0])
    {
      BIO *file = NULL;
      RSA *pkey = NULL;

      if ((file = BIO_new_file(block_state.file.buf, "r")) == NULL)
      {
        ilog(LOG_TYPE_IRCD, "Ignoring rsa_public_key_file -- file doesn't exist");
        break;
      }

      if ((pkey = PEM_read_bio_RSA_PUBKEY(file, NULL, 0, NULL)) == NULL)
        ilog(LOG_TYPE_IRCD, "Ignoring rsa_public_key_file -- key invalid; check key syntax");
      else
      {
        if (RSA_size(pkey) > 128)
          ilog(LOG_TYPE_IRCD, "Ignoring rsa_public_key_file -- key size must be 1024 or below");
        else
          conf->rsa_public_key = pkey;
      }

      BIO_set_close(file, BIO_CLOSE);
      BIO_free(file);
    }
#endif /* HAVE_LIBCRYPTO */
  }
}
#line 3797 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1192 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3806 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1198 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3815 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1204 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3824 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1210 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3838 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1221 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3847 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1227 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3856 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1233 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3870 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1244 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3879 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1250 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3888 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1257 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3897 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1261 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3906 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1265 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3915 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1269 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3924 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1273 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3933 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1277 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3942 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1281 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3951 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1285 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3960 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1289 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3969 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1293 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3978 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1297 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3987 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1301 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3996 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1305 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 4005 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1309 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 4014 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1313 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 4023 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1317 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 4032 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1321 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 4041 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1325 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 4050 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1329 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 4059 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1333 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 4068 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1337 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4077 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1341 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4086 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1347 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4095 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1354 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4104 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1358 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4113 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1362 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4122 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1366 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4131 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1370 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4140 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1374 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4149 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1378 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4158 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1382 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4167 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1386 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4176 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1390 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4185 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1394 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4194 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1398 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4203 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1402 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
#line 4212 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1406 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4221 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1410 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4230 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1414 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4239 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1418 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4248 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1422 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4257 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1426 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4266 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1430 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4275 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1434 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4284 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1438 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4293 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1442 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4302 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1452 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = DEFAULT_PINGFREQUENCY;
  block_state.con_freq.value  = DEFAULT_CONNECTFREQUENCY;
  block_state.max_total.value = MAXIMUM_LINKS_DEFAULT;
  block_state.max_sendq.value = DEFAULT_SENDQ;
  block_state.max_recvq.value = DEFAULT_RECVQ;
}
#line 4319 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1464 "conf_parser.y" /* yacc.c:1646  */
    {
  struct ClassItem *class = NULL;

  if (conf_parser_ctx.pass != 1)
    break;

  if (!block_state.class.buf[0])
    break;

  if (!(class = class_find(block_state.class.buf, 0)))
    class = class_make();

  class->active = 1;
  MyFree(class->name);
  class->name = xstrdup(block_state.class.buf);
  class->ping_freq = block_state.ping_freq.value;
  class->max_perip = block_state.max_perip.value;
  class->con_freq = block_state.con_freq.value;
  class->max_total = block_state.max_total.value;
  class->max_global = block_state.max_global.value;
  class->max_local = block_state.max_local.value;
  class->max_ident = block_state.max_ident.value;
  class->max_sendq = block_state.max_sendq.value;
  class->max_recvq = block_state.max_recvq.value;
  class->max_channels = block_state.max_channels.value;

  if (block_state.min_idle.value > block_state.max_idle.value)
  {
    block_state.min_idle.value = 0;
    block_state.max_idle.value = 0;
    block_state.flags.value &= ~CLASS_FLAGS_FAKE_IDLE;
  }

  class->flags = block_state.flags.value;
  class->min_idle = block_state.min_idle.value;
  class->max_idle = block_state.max_idle.value;

  if (class->number_per_cidr && block_state.number_per_cidr.value)
    if ((class->cidr_bitlen_ipv4 && block_state.cidr_bitlen_ipv4.value) ||
        (class->cidr_bitlen_ipv6 && block_state.cidr_bitlen_ipv6.value))
      if ((class->cidr_bitlen_ipv4 != block_state.cidr_bitlen_ipv4.value) ||
          (class->cidr_bitlen_ipv6 != block_state.cidr_bitlen_ipv6.value))
        rebuild_cidr_list(class);

  class->cidr_bitlen_ipv4 = block_state.cidr_bitlen_ipv4.value;
  class->cidr_bitlen_ipv6 = block_state.cidr_bitlen_ipv6.value;
  class->number_per_cidr = block_state.number_per_cidr.value;
}
#line 4372 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1533 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4381 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1539 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4390 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1545 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4399 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1551 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4408 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1557 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4417 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1563 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4426 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1569 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4435 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1575 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4444 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1581 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4453 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1587 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4462 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1593 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4472 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1600 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4481 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1606 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4490 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1612 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4499 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1618 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4511 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1627 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4523 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1636 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4532 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1643 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4541 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1647 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4550 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1657 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4559 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1663 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4567 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1669 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4576 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1673 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4585 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1677 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4594 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1685 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4600 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 293:
#line 1690 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
#ifndef HAVE_LIBCRYPTO
    if (block_state.flags.value & LISTENER_SSL)
    {
      conf_error_report("SSL not available - port closed");
      break;
    }
#endif
    add_listener((yyvsp[0].number), block_state.addr.buf, block_state.flags.value);
  }
}
#line 4618 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1703 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
#ifndef HAVE_LIBCRYPTO
    if (block_state.flags.value & LISTENER_SSL)
    {
      conf_error_report("SSL not available - port closed");
      break;
    }
#endif

    for (int i = (yyvsp[-2].number); i <= (yyvsp[0].number); ++i)
      add_listener(i, block_state.addr.buf, block_state.flags.value);
  }
}
#line 4638 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1720 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4647 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1726 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4656 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1735 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4665 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1739 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
  {
    struct MaskItem *conf = NULL;
    struct split_nuh_item nuh;

    nuh.nuhmask  = node->data;
    nuh.nickptr  = NULL;
    nuh.userptr  = block_state.user.buf;
    nuh.hostptr  = block_state.host.buf;
    nuh.nicksize = 0;
    nuh.usersize = sizeof(block_state.user.buf);
    nuh.hostsize = sizeof(block_state.host.buf);
    split_nuh(&nuh);

    conf        = conf_make(CONF_CLIENT);
    conf->user  = xstrdup(block_state.user.buf);
    conf->host  = xstrdup(block_state.host.buf);

    if (block_state.rpass.buf[0])
      conf->passwd = xstrdup(block_state.rpass.buf);
    if (block_state.name.buf[0])
      conf->name = xstrdup(block_state.name.buf);

    conf->flags = block_state.flags.value;
    conf->port  = block_state.port.value;

    conf_add_class_to_conf(conf, block_state.class.buf);
    add_conf_by_address(CONF_CLIENT, conf);
  }
}
#line 4706 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1788 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4715 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1794 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4724 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1800 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4733 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1806 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4747 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1817 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4756 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1824 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4765 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1828 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4774 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1832 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4783 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1836 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4792 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1840 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4801 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1844 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4810 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1848 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
#line 4819 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1852 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4828 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1856 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4837 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1860 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4846 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1866 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_hostname(yylval.string))
  {
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
    block_state.flags.value |= CONF_FLAGS_SPOOF_IP;
  }
  else
    ilog(LOG_TYPE_IRCD, "Spoof either is too long or contains invalid characters. Ignoring it.");
}
#line 4863 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1880 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4875 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1889 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4887 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1902 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4899 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1909 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4910 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1920 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4919 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1926 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4928 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1932 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4937 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1947 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct MaskItem *conf = conf_make(CONF_SERVICE);
    conf->name = xstrdup(yylval.string);
  }
}
#line 4952 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1962 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4968 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1973 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_ULINE);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
  conf->user = xstrdup(block_state.user.buf);
  conf->host = xstrdup(block_state.host.buf);
}
#line 4985 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1990 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4994 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1996 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = block_state.user.buf;
    nuh.hostptr  = block_state.host.buf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(block_state.user.buf);
    nuh.hostsize = sizeof(block_state.host.buf);

    split_nuh(&nuh);
  }
}
#line 5016 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 358:
#line 2015 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5025 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 362:
#line 2022 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5034 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 2026 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5043 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 2030 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5052 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 2034 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5061 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 2038 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5070 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 367:
#line 2042 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5079 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 368:
#line 2046 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5088 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 369:
#line 2050 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5097 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 370:
#line 2054 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5106 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 371:
#line 2058 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5115 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 2067 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5129 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 2076 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
#line 5144 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 379:
#line 2091 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5153 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 2097 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5162 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 2104 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5171 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 2108 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5180 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 2112 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5189 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 2116 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5198 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 2120 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5207 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2124 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5216 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 390:
#line 2128 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5225 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 391:
#line 2132 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5234 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 392:
#line 2136 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5243 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 393:
#line 2140 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5252 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 394:
#line 2149 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5266 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 395:
#line 2158 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;
  struct addrinfo hints, *res;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0] ||
      !block_state.host.buf[0])
    break;

  if (!block_state.rpass.buf[0] ||
      !block_state.spass.buf[0])
    break;

  if (has_wildcards(block_state.name.buf) ||
      has_wildcards(block_state.host.buf))
    break;

  conf = conf_make(CONF_SERVER);
  conf->port = block_state.port.value;
  conf->flags = block_state.flags.value;
  conf->aftype = block_state.aftype.value;
  conf->host = xstrdup(block_state.host.buf);
  conf->name = xstrdup(block_state.name.buf);
  conf->passwd = xstrdup(block_state.rpass.buf);
  conf->spasswd = xstrdup(block_state.spass.buf);

  if (block_state.cert.buf[0])
    conf->certfp = xstrdup(block_state.cert.buf);

  if (block_state.ciph.buf[0])
    conf->cipher_list = xstrdup(block_state.ciph.buf);

  dlinkMoveList(&block_state.leaf.list, &conf->leaf_list);
  dlinkMoveList(&block_state.hub.list, &conf->hub_list);

  if (block_state.bind.buf[0])
  {
    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (getaddrinfo(block_state.bind.buf, NULL, &hints, &res))
      ilog(LOG_TYPE_IRCD, "Invalid netmask for server vhost(%s)", block_state.bind.buf);
    else
    {
      assert(res);

      memcpy(&conf->bind, res->ai_addr, res->ai_addrlen);
      conf->bind.ss.ss_family = res->ai_family;
      conf->bind.ss_len = res->ai_addrlen;
      freeaddrinfo(res);
    }
  }

  conf_add_class_to_conf(conf, block_state.class.buf);
  lookup_confhost(conf);
}
#line 5332 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 413:
#line 2238 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5341 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 414:
#line 2244 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5350 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 415:
#line 2250 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5359 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 416:
#line 2256 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].string)[0] == ':')
    conf_error_report("Server passwords cannot begin with a colon");
  else if (strchr((yyvsp[-1].string), ' '))
    conf_error_report("Server passwords cannot contain spaces");
  else
    strlcpy(block_state.spass.buf, yylval.string, sizeof(block_state.spass.buf));
}
#line 5375 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 417:
#line 2269 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].string)[0] == ':')
    conf_error_report("Server passwords cannot begin with a colon");
  else if (strchr((yyvsp[-1].string), ' '))
    conf_error_report("Server passwords cannot contain spaces");
  else
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5391 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 418:
#line 2282 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5400 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2288 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5409 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2294 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5418 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2298 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5427 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2304 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5435 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 426:
#line 2310 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5444 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 427:
#line 2314 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5453 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 428:
#line 2320 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5467 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 429:
#line 2331 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5476 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 430:
#line 2337 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5485 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2343 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5494 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2349 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
#line 5508 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2364 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5517 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2368 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.user.buf[0] ||
      !block_state.host.buf[0])
    break;

  conf = conf_make(CONF_KLINE);
  conf->user = xstrdup(block_state.user.buf);
  conf->host = xstrdup(block_state.host.buf);

  if (block_state.rpass.buf[0])
    conf->reason = xstrdup(block_state.rpass.buf);
  else
    conf->reason = xstrdup(CONF_NOREASON);
  add_conf_by_address(CONF_KLINE, conf);
}
#line 5542 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 440:
#line 2393 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass == 2)
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = block_state.user.buf;
    nuh.hostptr  = block_state.host.buf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(block_state.user.buf);
    nuh.hostsize = sizeof(block_state.host.buf);

    split_nuh(&nuh);
  }
}
#line 5565 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 441:
#line 2413 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5574 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 442:
#line 2422 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5583 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2426 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.addr.buf[0])
    break;

  if (parse_netmask(block_state.addr.buf, NULL, NULL) != HM_HOST)
  {
    conf = conf_make(CONF_DLINE);
    conf->host = xstrdup(block_state.addr.buf);

    if (block_state.rpass.buf[0])
      conf->reason = xstrdup(block_state.rpass.buf);
    else
      conf->reason = xstrdup(CONF_NOREASON);
    add_conf_by_address(CONF_DLINE, conf);
  }
}
#line 5609 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 449:
#line 2452 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5618 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2458 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5627 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 456:
#line 2472 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.string[0] && parse_netmask(yylval.string, NULL, NULL) != HM_HOST)
    {
      struct MaskItem *conf = conf_make(CONF_EXEMPT);
      conf->host = xstrdup(yylval.string);

      add_conf_by_address(CONF_EXEMPT, conf);
    }
  }
}
#line 5644 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 457:
#line 2489 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5653 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2493 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0])
    break;

  conf = conf_make(CONF_XLINE);
  conf->name = xstrdup(block_state.name.buf);

  if (block_state.rpass.buf[0])
    conf->reason = xstrdup(block_state.rpass.buf);
  else
    conf->reason = xstrdup(CONF_NOREASON);
}
#line 5675 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 464:
#line 2515 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5684 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 465:
#line 2521 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5693 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 518:
#line 2585 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5701 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2590 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5709 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2595 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5717 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2600 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5726 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2606 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.glines = yylval.number;
}
#line 5735 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2612 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.gline_time = (yyvsp[-1].number);
}
#line 5744 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2618 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.gline_request_time = (yyvsp[-1].number);
}
#line 5753 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2624 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.gline_min_cidr = (yyvsp[-1].number);
}
#line 5761 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2629 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.gline_min_cidr6 = (yyvsp[-1].number);
}
#line 5769 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2634 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.tkline_expire_notices = yylval.number;
}
#line 5777 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2639 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5785 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2644 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ignore_bogus_ts = yylval.number;
}
#line 5793 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2649 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5801 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2654 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5809 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2659 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5817 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2664 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5825 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2669 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5833 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2674 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5841 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2679 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5849 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2684 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5858 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2690 "conf_parser.y" /* yacc.c:1646  */
    {
  if (((yyvsp[-1].number) > 0) && conf_parser_ctx.pass == 1)
  {
    ilog(LOG_TYPE_IRCD, "You haven't read your config file properly.");
    ilog(LOG_TYPE_IRCD, "There is a line in the example conf that will kill your server if not removed.");
    ilog(LOG_TYPE_IRCD, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
#line 5872 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2701 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5880 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2706 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5888 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2711 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5896 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2716 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5904 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2721 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5912 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2726 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5920 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2731 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5928 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2734 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5936 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2739 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5944 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2742 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5952 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2747 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5960 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2752 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5968 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2757 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5976 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2762 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5984 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2767 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5992 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2772 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 6000 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2777 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.true_no_oper_flood = yylval.number;
}
#line 6008 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2782 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_pass_resv = yylval.number;
}
#line 6016 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2787 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 6024 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2792 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6032 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2797 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6040 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2802 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6048 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2807 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6056 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 562:
#line 2812 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6064 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2817 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 6072 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2823 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 6080 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2826 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6088 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2829 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6096 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2832 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 6104 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2835 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 6112 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2838 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6120 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2841 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6128 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2844 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6136 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2847 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6144 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2850 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6152 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2853 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6160 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2856 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 6168 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2859 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6176 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2862 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6184 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2865 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6192 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2868 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6200 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2871 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6208 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2874 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6216 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2877 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6224 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2880 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6232 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2883 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6240 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 588:
#line 2886 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6248 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 589:
#line 2891 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6256 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2897 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6264 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2900 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6272 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2903 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6280 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2906 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6288 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2909 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6296 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2912 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6304 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2915 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6312 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2918 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6320 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2921 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6328 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2924 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6336 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2927 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6344 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2930 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6352 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2933 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6360 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2936 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6368 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2939 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6376 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2942 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6384 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2945 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6392 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2948 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6400 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2951 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6408 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2954 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6416 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2959 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6424 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 614:
#line 2964 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6432 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 615:
#line 2969 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6440 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 634:
#line 2998 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6448 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 635:
#line 3003 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6456 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 3008 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6464 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 3013 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6472 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 638:
#line 3018 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6480 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 639:
#line 3023 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6488 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 640:
#line 3028 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6496 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 641:
#line 3033 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6504 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 642:
#line 3038 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_user_count = (yyvsp[-1].number);
}
#line 6512 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 643:
#line 3043 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_server_count = (yyvsp[-1].number);
}
#line 6520 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 644:
#line 3048 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
#line 6528 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 645:
#line 3053 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
#line 6536 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 646:
#line 3058 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
#line 6544 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 647:
#line 3063 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodtime = (yyvsp[-1].number);
}
#line 6552 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 660:
#line 3085 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6561 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 661:
#line 3091 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6570 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 662:
#line 3097 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6579 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 663:
#line 3103 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6588 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 664:
#line 3109 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6600 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 665:
#line 3118 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (((yyvsp[-1].number) > 0) && ConfigServerHide.links_disabled == 1)
    {
      event_write_links_file.when = (yyvsp[-1].number);
      event_addish(&event_write_links_file, NULL);
      ConfigServerHide.links_disabled = 0;
    }

    ConfigServerHide.links_delay = (yyvsp[-1].number);
  }
}
#line 6618 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 666:
#line 3133 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6627 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 667:
#line 3139 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6636 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6640 "conf_parser.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
