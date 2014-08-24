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
  dlink_node *ptr = NULL, *ptr_next = NULL;

  DLINK_FOREACH_SAFE(ptr, ptr_next, block_state.mask.list.head)
  {
    MyFree(ptr->data);
    dlinkDelete(ptr, &block_state.mask.list);
    free_dlink_node(ptr);
  }

  DLINK_FOREACH_SAFE(ptr, ptr_next, block_state.leaf.list.head)
  {
    MyFree(ptr->data);
    dlinkDelete(ptr, &block_state.leaf.list);
    free_dlink_node(ptr);
  }

  DLINK_FOREACH_SAFE(ptr, ptr_next, block_state.hub.list.head)
  {
    MyFree(ptr->data);
    dlinkDelete(ptr, &block_state.hub.list);
    free_dlink_node(ptr);
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
#define YYLAST   1270

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  240
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  298
/* YYNRULES -- Number of rules.  */
#define YYNRULES  669
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1324

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
     479,   480,   481,   484,   526,   584,   613,   621,   635,   663,
     678,   693,   703,   717,   726,   754,   782,   807,   829,   851,
     860,   862,   862,   863,   864,   865,   866,   868,   877,   886,
     899,   898,   916,   916,   917,   917,   917,   919,   925,   935,
     934,   953,   953,   954,   954,   954,   954,   954,   956,   962,
     968,   974,   997,   998,   998,  1000,  1000,  1001,  1003,  1010,
    1010,  1023,  1024,  1026,  1026,  1027,  1027,  1029,  1037,  1040,
    1046,  1045,  1051,  1051,  1052,  1056,  1060,  1064,  1068,  1072,
    1076,  1080,  1084,  1095,  1094,  1180,  1180,  1181,  1182,  1183,
    1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,  1193,  1199,
    1205,  1211,  1222,  1228,  1234,  1245,  1252,  1251,  1257,  1257,
    1258,  1262,  1266,  1270,  1274,  1278,  1282,  1286,  1290,  1294,
    1298,  1302,  1306,  1310,  1314,  1318,  1322,  1326,  1330,  1334,
    1338,  1342,  1349,  1348,  1354,  1354,  1355,  1359,  1363,  1367,
    1371,  1375,  1379,  1383,  1387,  1391,  1395,  1399,  1403,  1407,
    1411,  1415,  1419,  1423,  1427,  1431,  1435,  1439,  1443,  1454,
    1453,  1515,  1515,  1516,  1517,  1518,  1519,  1520,  1521,  1522,
    1523,  1524,  1525,  1526,  1527,  1528,  1528,  1529,  1530,  1531,
    1532,  1534,  1540,  1546,  1552,  1558,  1564,  1570,  1576,  1582,
    1588,  1594,  1601,  1607,  1613,  1619,  1628,  1638,  1637,  1643,
    1643,  1644,  1648,  1659,  1658,  1665,  1664,  1669,  1669,  1670,
    1674,  1678,  1684,  1684,  1685,  1685,  1685,  1685,  1685,  1687,
    1687,  1689,  1689,  1691,  1704,  1721,  1727,  1737,  1736,  1778,
    1778,  1779,  1780,  1781,  1782,  1783,  1784,  1785,  1786,  1787,
    1789,  1795,  1801,  1807,  1819,  1818,  1824,  1824,  1825,  1829,
    1833,  1837,  1841,  1845,  1849,  1853,  1857,  1861,  1867,  1881,
    1890,  1904,  1903,  1918,  1918,  1919,  1919,  1919,  1919,  1921,
    1927,  1933,  1943,  1945,  1945,  1946,  1946,  1948,  1964,  1963,
    1988,  1988,  1989,  1989,  1989,  1989,  1991,  1997,  2017,  2016,
    2022,  2022,  2023,  2027,  2031,  2035,  2039,  2043,  2047,  2051,
    2055,  2059,  2069,  2068,  2089,  2089,  2090,  2090,  2090,  2092,
    2099,  2098,  2104,  2104,  2105,  2109,  2113,  2117,  2121,  2125,
    2129,  2133,  2137,  2141,  2151,  2150,  2222,  2222,  2223,  2224,
    2225,  2226,  2227,  2228,  2229,  2230,  2231,  2232,  2233,  2234,
    2235,  2236,  2237,  2239,  2245,  2251,  2257,  2270,  2283,  2289,
    2295,  2299,  2306,  2305,  2310,  2310,  2311,  2315,  2321,  2332,
    2338,  2344,  2350,  2366,  2365,  2391,  2391,  2392,  2392,  2392,
    2394,  2414,  2424,  2423,  2450,  2450,  2451,  2451,  2451,  2453,
    2459,  2468,  2470,  2470,  2471,  2471,  2473,  2491,  2490,  2513,
    2513,  2514,  2514,  2514,  2516,  2522,  2531,  2534,  2534,  2535,
    2536,  2537,  2538,  2539,  2540,  2541,  2542,  2543,  2544,  2545,
    2546,  2547,  2548,  2549,  2550,  2551,  2552,  2553,  2554,  2555,
    2556,  2557,  2558,  2559,  2560,  2561,  2562,  2563,  2564,  2565,
    2566,  2567,  2568,  2569,  2570,  2571,  2572,  2573,  2574,  2575,
    2576,  2577,  2578,  2579,  2580,  2581,  2582,  2583,  2584,  2587,
    2592,  2597,  2602,  2608,  2614,  2620,  2626,  2631,  2636,  2641,
    2646,  2651,  2656,  2661,  2666,  2671,  2676,  2681,  2686,  2691,
    2697,  2708,  2713,  2718,  2723,  2728,  2733,  2738,  2741,  2746,
    2749,  2754,  2759,  2764,  2769,  2774,  2779,  2784,  2789,  2794,
    2799,  2804,  2809,  2814,  2819,  2825,  2824,  2829,  2829,  2830,
    2833,  2836,  2839,  2842,  2845,  2848,  2851,  2854,  2857,  2860,
    2863,  2866,  2869,  2872,  2875,  2878,  2881,  2884,  2887,  2890,
    2893,  2899,  2898,  2903,  2903,  2904,  2907,  2910,  2913,  2916,
    2919,  2922,  2925,  2928,  2931,  2934,  2937,  2940,  2943,  2946,
    2949,  2952,  2955,  2958,  2961,  2966,  2971,  2976,  2985,  2988,
    2988,  2989,  2990,  2991,  2992,  2993,  2994,  2995,  2996,  2997,
    2998,  2999,  3000,  3001,  3002,  3003,  3005,  3010,  3015,  3020,
    3025,  3030,  3035,  3040,  3045,  3050,  3055,  3060,  3065,  3070,
    3078,  3081,  3081,  3082,  3083,  3084,  3085,  3086,  3087,  3088,
    3089,  3090,  3092,  3098,  3104,  3110,  3116,  3125,  3140,  3146
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
  "general_kill_chase_time_limit", "general_hide_spoof_ips",
  "general_ignore_bogus_ts", "general_failed_oper_notice",
  "general_anti_nick_flood", "general_max_nick_time",
  "general_max_nick_changes", "general_max_accept",
  "general_anti_spam_exit_message_time", "general_ts_warn_delta",
  "general_ts_max_delta", "general_havent_read_conf",
  "general_invisible_on_connect", "general_warn_no_connect_block",
  "general_stats_e_disabled", "general_stats_o_oper_only",
  "general_stats_P_oper_only", "general_stats_u_oper_only",
  "general_stats_k_oper_only", "general_stats_i_oper_only",
  "general_pace_wait", "general_caller_id_wait",
  "general_opers_bypass_callerid", "general_pace_wait_simple",
  "general_short_motd", "general_no_oper_flood",
  "general_true_no_oper_flood", "general_oper_pass_resv",
  "general_dots_in_ident", "general_max_targets", "general_ping_cookie",
  "general_disable_auth", "general_throttle_count",
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

#define YYPACT_NINF -967

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-967)))

#define YYTABLE_NINF -130

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -967,   692,  -967,  -194,  -218,  -205,  -967,  -967,  -967,  -202,
    -967,  -169,  -967,  -967,  -967,  -162,  -967,  -967,  -967,  -157,
    -151,  -967,  -149,  -967,  -144,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,    20,   930,  -119,   -75,   -64,    14,   -41,   422,   -39,
     -19,   -11,    18,    -7,    -6,    -2,   316,   455,     5,     8,
      35,    44,    39,   -68,     3,    33,    47,    16,  -967,  -967,
    -967,  -967,  -967,    58,    60,    65,    91,    93,    95,    97,
     103,   104,   105,   114,   116,   117,   119,    12,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,   698,   602,    38,  -967,   121,    34,  -967,
    -967,    92,  -967,   129,   132,   133,   134,   138,   139,   140,
     141,   142,   143,   145,   146,   150,   151,   152,   156,   158,
     159,   163,   165,   166,   167,   168,   169,   171,   181,   183,
     185,  -967,   187,  -967,   188,   189,   190,   193,   196,   200,
     201,   205,   206,   210,   211,   212,   213,   215,   224,   225,
     226,   230,   127,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,   445,    23,   325,    42,   234,   236,    26,
    -967,  -967,  -967,    21,   317,   324,  -967,   239,   240,   241,
     242,   247,   250,   252,   254,     7,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,    46,   256,   257,   260,   262,
     263,   265,   267,   268,   271,   272,   273,   274,   275,   281,
     283,   286,   298,   204,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,    10,   269,   299,    27,  -967,  -967,  -967,    84,
     115,  -967,   301,    72,  -967,  -967,    74,  -967,   180,   378,
     413,   318,  -967,   436,   439,   339,   442,   444,   447,   444,
     450,   444,   444,   451,   453,   352,   354,   338,  -967,   341,
     336,   342,   343,  -967,   344,   345,   346,   353,   359,   363,
     364,   369,   372,   373,   375,   376,   380,    94,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,   385,   383,   386,   387,
     388,   389,   392,  -967,   394,   396,   399,   401,   410,   411,
     414,   253,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,   415,   416,
      29,  -967,  -967,  -967,   493,   421,  -967,  -967,   420,   424,
      31,  -967,  -967,  -967,   360,   444,   552,   444,   444,   452,
     555,   454,   558,   457,   444,   459,   563,   564,   444,   565,
     464,   465,   467,   444,   575,   576,   444,   577,   580,   583,
     584,   485,   470,   488,   472,   497,   444,   444,   505,   506,
     509,  -200,  -187,   510,   512,   515,   620,   444,   521,   523,
     444,   444,   524,   508,  -967,   511,   507,   514,  -967,   516,
     517,   519,   520,   526,   266,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,   527,   531,    85,  -967,  -967,
    -967,   513,   532,   533,  -967,   534,  -967,     2,  -967,  -967,
    -967,  -967,  -967,   617,   619,   518,  -967,   538,   536,   539,
      25,  -967,  -967,  -967,   545,   543,   544,  -967,   546,   553,
     554,   556,   561,  -967,   562,    75,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,   548,   566,   567,
     568,    24,  -967,  -967,  -967,  -967,   542,   550,   573,   632,
     585,   590,   592,   444,   586,  -967,  -967,   671,   593,   681,
     635,   697,   687,   690,   693,   694,   695,   699,   701,   702,
     707,   704,   705,   706,   603,  -967,   604,   589,  -967,    43,
    -967,  -967,  -967,  -967,   611,   605,  -967,   600,   606,   607,
     608,   609,   612,    22,  -967,  -967,  -967,  -967,  -967,   712,
     614,  -967,   616,   615,  -967,   623,    48,  -967,  -967,  -967,
    -967,   622,   629,   633,  -967,   634,   636,   637,   640,   270,
     641,   642,   645,   646,   648,   650,   655,   662,   666,   669,
    -967,  -967,   737,   743,   444,   668,   793,   794,   796,   444,
     797,   800,   444,   786,   802,   804,   444,   805,   805,   686,
    -967,  -967,   795,    30,   799,   713,   801,   807,   685,   811,
     814,   809,   816,   818,   819,   821,   717,  -967,   827,   829,
     725,  -967,   728,  -967,   834,   835,   734,  -967,   735,   736,
     739,   740,   741,   742,   744,   745,   746,   747,   748,   749,
     750,   751,   752,   753,   754,   755,   756,   757,   758,   759,
     760,   763,   765,   766,   769,   770,   684,   771,   724,   772,
     776,   777,   778,   779,   780,   783,   784,   785,   787,   788,
     789,   790,   791,   792,   798,   803,   808,   810,   812,  -967,
    -967,   842,   782,   806,   891,   913,   899,   900,   901,   813,
    -967,   902,   904,   815,  -967,  -967,   905,   906,   817,   922,
     822,  -967,   823,   824,  -967,  -967,   909,   910,   825,  -967,
    -967,   916,   832,   826,   921,   923,   924,   926,   844,   828,
     932,   830,  -967,  -967,   933,   937,   938,   836,  -967,   837,
     838,   839,   840,   841,   843,   845,   846,  -967,   847,   848,
     849,   850,   851,   852,   853,   854,   855,   856,   857,   858,
     859,   860,   861,   862,   863,  -967,  -967,   939,   864,   865,
    -967,   866,  -967,    98,  -967,   940,   947,   949,   969,   868,
    -967,   869,  -967,  -967,   975,   870,   976,   872,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,   444,   444,   444,   444,
     444,   444,   444,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,   874,   875,   876,   -50,   877,
     878,   879,   880,   881,   882,   883,   884,   885,   886,   887,
     326,   888,   889,  -967,   890,   892,   893,   894,   895,   896,
     897,     4,   898,   903,   907,   908,   911,   912,   914,  -967,
     915,   917,  -967,  -967,   918,   919,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -186,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -183,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,   920,   925,   582,   927,   928,   929,   931,   934,
    -967,   935,   936,  -967,   941,   942,   -37,   943,   944,  -967,
    -967,  -967,  -967,   945,   946,  -967,   950,   951,   529,   952,
     953,   954,   955,   956,   764,   957,  -967,   958,   959,   960,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,   961,   423,  -967,  -967,
     962,   963,   964,  -967,    81,  -967,  -967,  -967,  -967,   965,
     968,   970,   971,  -967,  -967,   972,   491,   973,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -181,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,   805,   805,   805,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -178,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,   684,  -967,   724,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -168,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -166,  -967,  1011,   922,   974,  -967,  -967,
    -967,  -967,  -967,   977,  -967,  -967,   978,  -967,  -967,  -967,
    -967,   979,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -109,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,   -81,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,   -70,  -967,
    -967,  1004,  -104,   966,   980,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,   -45,  -967,  -967,  -967,   -50,  -967,  -967,  -967,  -967,
       4,  -967,  -967,  -967,   582,  -967,   -37,  -967,  -967,  -967,
     999,  1000,  1001,  -967,   529,  -967,   764,  -967,   423,   981,
     985,   986,   417,  -967,  -967,   491,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,   -31,  -967,
    -967,  -967,   417,  -967
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
      95,    94,   635,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   620,   634,
     622,   623,   624,   625,   626,   627,   621,   628,   629,   630,
     631,   632,   633,     0,     0,     0,   455,     0,     0,   453,
     454,     0,   518,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   591,     0,   565,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   468,   469,   470,   516,   517,   510,   511,
     512,   513,   514,   509,   481,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   506,   482,   483,   515,   485,
     490,   491,   486,   488,   487,   499,   500,   489,   492,   493,
     494,   495,   484,   497,   507,   508,   504,   505,   498,   496,
     502,   503,   501,     0,     0,     0,     0,     0,     0,     0,
      46,    47,    48,     0,     0,     0,   661,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   652,   653,   654,   655,
     656,   659,   657,   658,   660,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    54,    69,    66,    64,    70,    71,
      65,    55,    68,    58,    59,    60,    56,    67,    61,    62,
      63,    57,     0,     0,     0,     0,   124,   125,   126,     0,
       0,   346,     0,     0,   344,   345,     0,    96,     0,     0,
       0,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   619,     0,
       0,     0,     0,   267,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   232,   233,
     236,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     234,   235,   237,   247,   248,   249,     0,     0,     0,     0,
       0,     0,     0,   422,     0,     0,     0,     0,     0,     0,
       0,     0,   397,   398,   399,   400,   401,   402,   403,   405,
     404,   407,   411,   408,   409,   410,   406,   448,     0,     0,
       0,   445,   446,   447,     0,     0,   452,   463,     0,     0,
       0,   460,   461,   462,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   467,     0,     0,     0,   314,     0,
       0,     0,     0,     0,     0,   300,   301,   302,   303,   308,
     304,   305,   306,   307,   439,     0,     0,     0,   436,   437,
     438,     0,     0,     0,   275,     0,   285,     0,   283,   284,
     286,   287,    49,     0,     0,     0,    45,     0,     0,     0,
       0,   103,   104,   105,     0,     0,     0,   202,     0,     0,
       0,     0,     0,   176,     0,     0,   156,   157,   158,   159,
     162,   163,   164,   165,   161,   160,   166,     0,     0,     0,
       0,     0,   334,   335,   336,   337,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   651,    72,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,     0,     0,   380,     0,
     375,   376,   377,   127,     0,     0,   123,     0,     0,     0,
       0,     0,     0,     0,   112,   113,   115,   114,   116,     0,
       0,   343,     0,     0,   358,     0,     0,   351,   352,   353,
     354,     0,     0,     0,    90,     0,     0,     0,     0,    28,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     618,   250,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     231,   412,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   396,     0,     0,
       0,   444,     0,   451,     0,     0,     0,   459,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   466,
     309,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     299,     0,     0,     0,   435,   288,     0,     0,     0,     0,
       0,   282,     0,     0,    44,   106,     0,     0,     0,   102,
     167,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   155,   338,     0,     0,     0,     0,   333,     0,
       0,     0,     0,     0,     0,     0,     0,   650,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,   378,     0,     0,     0,
     374,     0,   122,     0,   117,     0,     0,     0,     0,     0,
     111,     0,   342,   355,     0,     0,     0,     0,   350,    99,
      98,    97,   645,   644,   636,   637,    28,    28,    28,    28,
      28,    28,    28,    30,    29,   638,   648,   649,   639,   640,
     641,   643,   642,   646,   647,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,     0,   230,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   395,
       0,     0,   443,   456,     0,     0,   458,   533,   537,   519,
     520,   552,   522,   617,   562,   559,   532,   524,   523,   526,
     527,   525,   540,   530,   531,   541,   529,   536,   535,   534,
     560,   521,   615,   616,   556,   601,   595,   611,   596,   597,
     598,   606,   614,   599,   608,   612,   602,   613,   603,   607,
     600,   610,   605,   604,   609,     0,   594,   558,   574,   575,
     576,   569,   587,   570,   571,   572,   582,   590,   573,   584,
     588,   578,   589,   579,   583,   577,   586,   581,   580,   585,
       0,   568,   553,   551,   554,   561,   555,   543,   549,   550,
     547,   548,   544,   545,   546,   563,   564,   528,   557,   539,
     538,   542,     0,     0,     0,     0,     0,     0,     0,     0,
     298,     0,     0,   434,     0,     0,     0,   293,   289,   292,
     274,    50,    51,     0,     0,   101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   154,     0,     0,     0,
     332,   663,   662,   668,   666,   669,   664,   665,   667,    81,
      89,    80,    87,    88,    79,    83,    82,    74,    73,    78,
      75,    77,    86,    76,    84,    85,     0,     0,   373,   128,
       0,     0,     0,   140,     0,   132,   133,   135,   134,     0,
       0,     0,     0,   110,   347,     0,     0,     0,   349,    31,
      32,    33,    34,    35,    36,    37,   262,   263,   254,   272,
     271,     0,   270,   255,   257,   259,   266,   258,   256,   265,
     251,   264,   253,   252,    38,    38,    38,    40,    39,   260,
     261,   417,   420,   421,   431,   428,   414,   429,   426,   427,
       0,   425,   430,   413,   419,   416,   418,   432,   415,   449,
     450,   464,   465,   592,     0,   566,     0,   312,   313,   322,
     319,   324,   320,   321,   327,   323,   325,   318,   326,     0,
     317,   311,   330,   329,   328,   310,   441,   440,   296,   295,
     280,   281,   279,     0,   278,     0,     0,     0,   107,   108,
     175,   171,   222,   209,   219,   218,   207,   212,   228,   221,
     226,   211,   214,   223,   225,   220,   227,   215,   217,   224,
     213,   216,     0,   205,   168,   170,   172,   173,   174,   185,
     186,   187,   180,   198,   181,   182,   183,   193,   201,   184,
     195,   199,   189,   200,   190,   194,   188,   197,   192,   191,
     196,     0,   179,   169,   341,   339,   340,   379,   384,   390,
     393,   386,   392,   387,   391,   389,   385,   388,     0,   383,
     136,     0,     0,     0,     0,   131,   119,   118,   120,   121,
     356,   362,   368,   371,   364,   370,   365,   369,   367,   363,
     366,     0,   361,   357,   268,     0,    41,    42,    43,   423,
       0,   593,   567,   315,     0,   276,     0,   294,   291,   290,
       0,     0,     0,   203,     0,   177,     0,   381,     0,     0,
       0,     0,     0,   130,   359,     0,   269,   424,   316,   277,
     208,   206,   210,   204,   178,   382,   137,   139,   138,   146,
     151,   150,   145,   148,   152,   149,   144,   147,     0,   143,
     360,   141,     0,   142
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -967,  -967,  -967,  -310,  -315,  -966,  -647,  -967,  -967,   948,
    -967,  -967,  -967,  -967,   867,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  1061,  -967,  -967,  -967,  -967,  -967,
    -967,   541,  -967,  -967,  -967,  -967,  -967,   551,  -967,  -967,
    -967,  -967,  -967,  -967,   871,  -967,  -967,  -967,  -967,    79,
    -967,  -967,  -967,  -967,  -967,  -175,  -967,  -967,  -967,   625,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -147,  -967,  -967,  -967,  -129,  -967,  -967,  -967,   831,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -108,
    -967,  -967,  -967,  -967,  -967,  -120,  -967,   661,  -967,  -967,
    -967,     6,  -967,  -967,  -967,  -967,  -967,   700,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -114,  -967,  -967,  -967,  -967,
    -967,  -967,   630,  -967,  -967,  -967,  -967,  -967,   967,  -967,
    -967,  -967,  -967,   591,  -967,  -967,  -967,  -967,  -967,  -131,
    -967,  -967,  -967,   594,  -967,  -967,  -967,  -967,  -107,  -967,
    -967,  -967,   873,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,   -87,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,   711,  -967,  -967,  -967,  -967,  -967,   833,
    -967,  -967,  -967,  -967,  1091,  -967,  -967,  -967,  -967,   820,
    -967,  -967,  -967,  -967,  1038,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,    76,  -967,  -967,  -967,    77,  -967,  -967,  -967,
    -967,  -967,  1116,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,   982,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   843,   844,  1107,  1108,    27,   229,   230,
     231,   232,    28,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,    29,    77,    78,    79,    80,    81,    30,    63,
     510,   511,   512,   513,    31,    70,   593,   594,   595,   596,
     597,   598,    32,   295,   296,   297,   298,   299,  1064,  1065,
    1066,  1067,  1068,  1243,  1318,  1319,    33,    64,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   769,
    1221,  1222,   536,   763,  1192,  1193,    34,    53,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   635,  1091,  1092,
      35,    61,   496,   748,  1163,  1164,   497,   498,   499,  1167,
    1008,  1009,   500,   501,    36,    59,   474,   475,   476,   477,
     478,   479,   480,   733,  1149,  1150,   481,   482,   483,    37,
      65,   541,   542,   543,   544,   545,    38,   303,   304,   305,
      39,    72,   606,   607,   608,   609,   610,   825,  1261,  1262,
      40,    68,   579,   580,   581,   582,   808,  1238,  1239,    41,
      54,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   658,  1120,  1121,   392,   393,   394,   395,   396,
      42,    60,   487,   488,   489,   490,    43,    55,   400,   401,
     402,   403,    44,   118,   119,   120,    45,    57,   410,   411,
     412,   413,    46,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     444,   970,   971,   219,   442,   945,   946,   220,   221,   222,
      47,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,    48,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     871,   872,   620,   491,   622,  1089,   624,   625,   236,   293,
     870,   576,  1118,    82,  1160,   116,   715,    73,    51,   226,
     716,    73,   507,   588,   484,   537,   507,   226,   293,   717,
     397,    52,   407,   718,    56,   116,    83,    84,   237,   397,
      49,    50,    85,    74,   576,   301,   238,    74,  1133,   602,
      75,  1135,  1134,  1264,    75,  1136,  1269,  1265,   239,   240,
    1270,   538,   492,   241,   242,   243,  1273,    58,  1275,   493,
    1274,   494,  1276,   301,    62,   602,   514,    86,    87,    66,
    1090,   117,  1060,    88,    89,    67,   484,    69,   244,    90,
      91,    92,    71,   407,   515,   329,   398,    93,    94,  1060,
     679,   117,   681,   682,   508,   398,  1290,   539,   508,   688,
     516,   330,   331,   692,   577,   332,   588,   113,   697,   227,
      76,   700,    95,    96,    76,  1283,   589,   227,   122,  1284,
     495,   710,   711,   123,   124,   408,   125,   126,  1266,  1267,
    1268,   127,   723,   228,   517,   726,   727,   577,   302,   128,
     129,   228,   603,  1285,   485,   540,   130,  1286,  1161,   131,
     399,   114,   409,   333,  1287,   132,   307,  1162,  1288,   399,
     133,   134,   115,   135,   136,   137,   302,   138,   603,   518,
     334,   335,   336,   337,   338,  1061,   139,  -129,   339,  1294,
     140,   141,   340,  1295,   590,   121,   408,   223,   341,   519,
     509,   142,  1061,  1321,   509,   255,  -129,  1322,  1119,   342,
     343,   143,   591,   875,   876,   520,   485,   224,   144,   589,
     145,   344,   146,   409,   147,   225,   148,   149,   592,   233,
     234,   256,   521,   522,   235,   578,   294,   750,   786,   150,
     308,   292,   554,   345,   151,   152,   153,   327,   154,   155,
     156,   311,   486,   157,   366,   294,   367,   819,   368,   777,
     758,   505,   585,   587,   670,   257,   676,   465,   578,   405,
     309,   300,   369,   604,   258,   306,   502,   605,   809,   158,
     556,  1062,   523,   827,   310,   466,   346,   590,   370,   159,
     160,   161,   162,   163,   164,   313,   259,   314,  1062,   604,
     260,   467,   315,   605,   524,   591,  1063,   600,   261,   611,
     771,   262,   263,   371,   486,   372,  1244,   236,   514,   857,
     743,   592,   373,  1063,   862,   537,   491,   865,   316,   649,
     317,   869,   318,   374,   319,   468,   515,  1104,  1105,  1106,
     320,   321,   322,   264,   165,   166,   167,   237,   168,   169,
     170,   323,   516,   324,   325,   238,   326,   375,   404,   171,
     265,   538,   463,   266,   267,   268,   414,   239,   240,   415,
     416,   417,   241,   242,   243,   418,   419,   420,   421,   422,
     423,   376,   424,   425,   619,   492,   517,   426,   427,   428,
     469,   269,   493,   429,   494,   430,   431,   244,   470,   471,
     432,   377,   433,   434,   435,   436,   437,   539,   438,   270,
     378,   836,   837,   838,   839,   840,   841,   842,   439,   472,
     440,   518,   441,   122,   443,   445,   446,   447,   123,   124,
     448,   125,   126,   449,   271,   272,   127,   450,   451,   574,
     870,   519,   452,   453,   128,   129,   465,   454,   455,   456,
     457,   130,   458,   495,   131,   540,   255,   520,   379,  1309,
     132,   459,   460,   461,   466,   133,   134,   462,   135,   136,
     137,   503,   138,   504,   521,   522,   546,   547,   548,   549,
     467,   139,   256,   380,   550,   140,   141,   551,   666,   552,
    1310,   553,  1311,   557,   558,   473,   142,   559,  1228,   560,
     561,   739,   562,   583,   563,   564,   143,   612,   565,   566,
     567,   568,   569,   144,   468,   145,   257,   146,   570,   147,
     571,   148,   149,   572,   523,   258,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,  1172,   150,   573,   584,  1312,   599,   151,
     152,   153,   613,   154,   155,   156,   524,   259,   157,  1173,
     615,   260,   614,   616,  1313,   617,   618,  1174,   619,   261,
    1229,   621,   262,   263,   623,   626,  1251,   627,   628,   469,
     629,  1175,   630,   632,   158,   631,   678,   470,   471,   633,
     634,   636,   637,   638,   159,   160,   161,   162,   163,   164,
     639,  1230,  1314,  1315,   264,  1291,   640,  1139,   472,  1231,
     641,   642,  1176,   366,  1177,   367,   643,   368,  1232,   644,
     645,   265,   646,   647,   266,   267,   268,   648,  1140,   651,
     652,   369,   672,   653,   654,   655,   656,  1141,  1252,   657,
    1178,   659,  1233,   660,  1234,  1235,   661,   370,   662,   165,
     166,   167,   269,   168,   169,   170,  1316,   663,   664,  1236,
    1317,   665,   668,   669,   171,   673,  1237,   674,  1142,  1253,
     270,   675,   371,  1179,   372,  1180,   680,  1254,   683,   684,
     685,   373,   686,   687,   473,   689,  1255,   690,   691,   693,
     694,   695,   374,   696,  1181,   271,   272,  1143,  1144,   698,
     699,   701,     2,     3,   702,  1145,     4,   703,   704,   329,
    1256,   705,  1257,  1258,   707,  1182,   375,   706,     5,   708,
    1183,     6,     7,   709,  1184,   330,   331,  1259,     8,   332,
    1146,   712,   713,  1185,  1260,   714,   719,  1186,   720,     9,
     376,   721,    10,    11,   722,   925,  1147,   724,  1187,   725,
     728,  1188,   729,  1189,   731,   730,   752,   745,   753,   791,
     377,   732,   754,   734,   735,  1190,   736,   737,   779,   378,
      12,   782,  1191,   738,   741,    13,   780,   333,   742,   746,
     747,   749,   755,   756,    14,   948,   757,   949,   950,   760,
     761,   762,   773,   764,   334,   335,   336,   337,   338,   781,
     765,   766,   339,   767,    15,    16,   340,  1148,   768,   770,
     788,   783,   341,   774,   775,   776,   784,   379,   785,   789,
     790,   792,    17,   342,   343,  1199,   793,  1200,  1201,   794,
     787,   801,   795,   796,   797,   344,   807,   811,   798,    18,
     799,   800,   380,   802,   803,   804,   813,   805,   806,   812,
     814,   821,    19,    20,   815,   816,   817,   345,   822,   818,
     823,   855,   824,   926,   927,   928,   829,   856,   929,   930,
     826,   931,   932,   830,   933,    21,   934,   831,   832,   935,
     833,   834,   936,   937,   835,   845,   846,   938,    22,   847,
     848,   939,   849,    23,   850,   940,   941,   942,    24,   851,
     346,    25,   943,   951,   952,   953,   852,   944,   954,   955,
     853,   956,   957,   854,   958,   858,   959,   859,   860,   960,
     861,   863,   961,   962,   864,   866,   867,   963,   868,   870,
     873,   964,   881,   884,   874,   965,   966,   967,   877,   878,
     879,    82,   968,  1202,  1203,  1204,   880,   969,  1205,  1206,
     882,  1207,  1208,   883,  1209,   885,  1210,   886,   887,  1211,
     888,   889,  1212,  1213,    83,    84,   890,  1214,   891,   892,
      85,  1215,   893,   894,   895,  1216,  1217,  1218,   896,   897,
     898,   992,  1219,   899,   900,   901,   902,  1220,   903,   904,
     905,   906,   907,   908,   909,   910,   911,   912,   913,   914,
     915,   916,   917,   918,   919,    86,    87,   920,   993,   921,
     922,    88,    89,   923,   924,   947,   972,    90,    91,    92,
     973,   974,   975,   976,   977,    93,    94,   978,   979,   980,
     995,   981,   982,   983,   984,   985,   986,   996,   997,   998,
     999,  1001,   987,  1002,  1004,  1005,  1007,   988,  1013,  1014,
      95,    96,   989,   994,   990,  1016,   991,  1000,  1017,  1003,
    1019,   759,  1020,  1021,  1006,  1022,  1010,  1011,  1012,  1015,
    1023,  1025,  1027,  1018,  1026,  1024,  1028,  1029,  1056,  1069,
    1030,  1031,  1032,  1033,  1034,  1035,  1070,  1036,  1071,  1037,
    1038,  1039,  1040,  1041,  1042,  1043,  1044,  1045,  1046,  1047,
    1048,  1049,  1050,  1051,  1052,  1053,  1054,  1055,  1072,  1058,
    1059,  1057,  1073,  1074,  1075,  1077,  1078,  1076,  1086,  1087,
    1088,  1093,  1094,  1095,  1096,  1097,  1098,  1099,  1100,  1101,
    1102,  1103,  1109,  1110,  1111,  1277,  1112,  1113,  1114,  1115,
    1116,  1117,  1122,  1289,  1300,  1301,  1302,  1123,   312,  1304,
     575,  1124,  1125,  1245,   820,  1126,  1127,  1323,  1128,  1129,
     772,  1130,  1131,  1132,  1137,  1303,  1299,  1296,   751,  1138,
    1298,  1151,  1152,  1153,  1320,  1154,   586,  1165,  1155,  1156,
    1157,   778,  1278,   810,   740,  1158,  1159,   506,   650,  1168,
    1169,  1305,  1166,  1297,  1170,  1171,  1194,  1195,  1196,  1197,
    1198,  1223,  1224,  1225,  1226,  1227,  1240,   828,   744,  1246,
    1241,  1242,  1247,  1292,  1248,  1249,  1250,  1263,  1279,   406,
     464,  1271,  1272,   328,  1293,  1306,  1280,  1281,  1282,  1307,
    1308,     0,     0,     0,     0,     0,     0,   555,     0,     0,
     677,     0,     0,   671,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   667,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     601
};

static const yytype_int16 yycheck[] =
{
     647,   648,   317,     1,   319,    55,   321,   322,     1,     1,
     114,     1,     8,     1,    51,     1,   216,     1,   236,     1,
     220,     1,     1,     1,     1,     1,     1,     1,     1,   216,
       1,   236,     1,   220,   236,     1,    24,    25,    31,     1,
     234,   235,    30,    27,     1,     1,    39,    27,   234,     1,
      34,   234,   238,   234,    34,   238,   234,   238,    51,    52,
     238,    37,    60,    56,    57,    58,   234,   236,   234,    67,
     238,    69,   238,     1,   236,     1,     1,    65,    66,   236,
     130,    67,     1,    71,    72,   236,     1,   236,    81,    77,
      78,    79,   236,     1,    19,     1,    67,    85,    86,     1,
     415,    67,   417,   418,    83,    67,   210,    83,    83,   424,
      35,    17,    18,   428,   104,    21,     1,   236,   433,   101,
     104,   436,   110,   111,   104,   234,   104,   101,     1,   238,
     128,   446,   447,     6,     7,   104,     9,    10,  1104,  1105,
    1106,    14,   457,   125,    69,   460,   461,   104,   104,    22,
      23,   125,   104,   234,   131,   131,    29,   238,   195,    32,
     131,   236,   131,    69,   234,    38,   234,   204,   238,   131,
      43,    44,   236,    46,    47,    48,   104,    50,   104,   104,
      86,    87,    88,    89,    90,   104,    59,   179,    94,   234,
      63,    64,    98,   238,   172,   236,   104,   236,   104,   124,
     179,    74,   104,   234,   179,     1,   179,   238,   204,   115,
     116,    84,   190,   183,   184,   140,   131,   236,    91,   104,
      93,   127,    95,   131,    97,   236,    99,   100,   206,   236,
     236,    27,   157,   158,   236,   225,   228,   235,   553,   112,
     237,   236,   235,   149,   117,   118,   119,   235,   121,   122,
     123,   235,   229,   126,     1,   228,     3,   235,     5,   235,
     235,   235,   235,   179,   235,    61,   235,     1,   225,   235,
     237,   236,    19,   225,    70,   236,   234,   229,   235,   152,
     234,   200,   207,   235,   237,    19,   192,   172,    35,   162,
     163,   164,   165,   166,   167,   237,    92,   237,   200,   225,
      96,    35,   237,   229,   229,   190,   225,   235,   104,   129,
     235,   107,   108,    60,   229,    62,   235,     1,     1,   634,
     235,   206,    69,   225,   639,     1,     1,   642,   237,   235,
     237,   646,   237,    80,   237,    69,    19,    11,    12,    13,
     237,   237,   237,   139,   217,   218,   219,    31,   221,   222,
     223,   237,    35,   237,   237,    39,   237,   104,   237,   232,
     156,    37,   235,   159,   160,   161,   237,    51,    52,   237,
     237,   237,    56,    57,    58,   237,   237,   237,   237,   237,
     237,   128,   237,   237,   114,    60,    69,   237,   237,   237,
     124,   187,    67,   237,    69,   237,   237,    81,   132,   133,
     237,   148,   237,   237,   237,   237,   237,    83,   237,   205,
     157,   141,   142,   143,   144,   145,   146,   147,   237,   153,
     237,   104,   237,     1,   237,   237,   237,   237,     6,     7,
     237,     9,    10,   237,   230,   231,    14,   237,   237,   235,
     114,   124,   237,   237,    22,    23,     1,   237,   237,   237,
     237,    29,   237,   128,    32,   131,     1,   140,   205,    42,
      38,   237,   237,   237,    19,    43,    44,   237,    46,    47,
      48,   237,    50,   237,   157,   158,   237,   237,   237,   237,
      35,    59,    27,   230,   237,    63,    64,   237,   235,   237,
      73,   237,    75,   237,   237,   229,    74,   237,    75,   237,
     237,   235,   237,   234,   237,   237,    84,   129,   237,   237,
     237,   237,   237,    91,    69,    93,    61,    95,   237,    97,
     237,    99,   100,   237,   207,    70,   836,   837,   838,   839,
     840,   841,   842,     4,   112,   237,   237,   120,   237,   117,
     118,   119,   129,   121,   122,   123,   229,    92,   126,    20,
     114,    96,   234,   114,   137,   216,   114,    28,   114,   104,
     137,   114,   107,   108,   114,   114,    75,   114,   216,   124,
     216,    42,   234,   237,   152,   234,   216,   132,   133,   237,
     237,   237,   237,   237,   162,   163,   164,   165,   166,   167,
     237,   168,   175,   176,   139,  1242,   237,    15,   153,   176,
     237,   237,    73,     1,    75,     3,   237,     5,   185,   237,
     237,   156,   237,   237,   159,   160,   161,   237,    36,   234,
     237,    19,   129,   237,   237,   237,   237,    45,   137,   237,
     101,   237,   209,   237,   211,   212,   237,    35,   237,   217,
     218,   219,   187,   221,   222,   223,   229,   237,   237,   226,
     233,   237,   237,   237,   232,   234,   233,   237,    76,   168,
     205,   237,    60,   134,    62,   136,   114,   176,   216,   114,
     216,    69,   114,   216,   229,   216,   185,   114,   114,   114,
     216,   216,    80,   216,   155,   230,   231,   105,   106,   114,
     114,   114,     0,     1,   114,   113,     4,   114,   114,     1,
     209,   216,   211,   212,   216,   176,   104,   237,    16,   237,
     181,    19,    20,   216,   185,    17,    18,   226,    26,    21,
     138,   216,   216,   194,   233,   216,   216,   198,   216,    37,
     128,   216,    40,    41,   114,    51,   154,   216,   209,   216,
     216,   212,   234,   214,   237,   234,   129,   234,   129,   114,
     148,   237,   234,   237,   237,   226,   237,   237,   216,   157,
      68,   129,   233,   237,   237,    73,   216,    69,   237,   237,
     237,   237,   234,   237,    82,    51,   237,    53,    54,   234,
     237,   237,   234,   237,    86,    87,    88,    89,    90,   216,
     237,   237,    94,   237,   102,   103,    98,   215,   237,   237,
     129,   216,   104,   237,   237,   237,   216,   205,   216,   216,
     129,   114,   120,   115,   116,    51,   129,    53,    54,   129,
     234,   114,   129,   129,   129,   127,   237,   216,   129,   137,
     129,   129,   230,   129,   129,   129,   236,   234,   234,   234,
     234,   129,   150,   151,   237,   237,   237,   149,   234,   237,
     234,   114,   237,   169,   170,   171,   234,   114,   174,   175,
     237,   177,   178,   234,   180,   173,   182,   234,   234,   185,
     234,   234,   188,   189,   234,   234,   234,   193,   186,   234,
     234,   197,   234,   191,   234,   201,   202,   203,   196,   234,
     192,   199,   208,   169,   170,   171,   234,   213,   174,   175,
     234,   177,   178,   234,   180,   237,   182,   114,   114,   185,
     114,   114,   188,   189,   114,   129,   114,   193,   114,   114,
     234,   197,   237,   114,   129,   201,   202,   203,   129,   216,
     129,     1,   208,   169,   170,   171,   129,   213,   174,   175,
     129,   177,   178,   129,   180,   129,   182,   129,   129,   185,
     129,   234,   188,   189,    24,    25,   129,   193,   129,   234,
      30,   197,   234,   129,   129,   201,   202,   203,   234,   234,
     234,   129,   208,   234,   234,   234,   234,   213,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,    65,    66,   234,   216,   234,
     234,    71,    72,   234,   234,   234,   234,    77,    78,    79,
     234,   234,   234,   234,   234,    85,    86,   234,   234,   234,
     129,   234,   234,   234,   234,   234,   234,   114,   129,   129,
     129,   129,   234,   129,   129,   129,   114,   234,   129,   129,
     110,   111,   234,   237,   234,   129,   234,   234,   216,   234,
     129,   510,   129,   129,   237,   129,   234,   234,   234,   234,
     216,   129,   129,   237,   234,   237,   129,   129,   129,   129,
     234,   234,   234,   234,   234,   234,   129,   234,   129,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   129,   234,
     234,   237,   234,   234,   129,   129,   234,   237,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   114,   234,   234,   234,   234,
     234,   234,   234,   129,   135,   135,   135,   234,    77,  1286,
     273,   234,   234,  1064,   593,   234,   234,  1322,   234,   234,
     525,   234,   234,   234,   234,  1284,  1276,  1265,   497,   234,
    1274,   234,   234,   234,  1295,   234,   295,   224,   234,   234,
     234,   541,  1166,   579,   474,   234,   234,   229,   347,   234,
     234,  1288,   238,  1270,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   606,   487,   234,
     237,   237,   234,   237,   234,   234,   234,   234,   234,   118,
     172,  1134,  1136,    97,   234,   234,   239,   239,   239,   234,
     234,    -1,    -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,
     410,    -1,    -1,   400,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   381,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     303
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   241,     0,     1,     4,    16,    19,    20,    26,    37,
      40,    41,    68,    73,    82,   102,   103,   120,   137,   150,
     151,   173,   186,   191,   196,   199,   242,   247,   252,   272,
     278,   284,   292,   306,   326,   350,   364,   379,   386,   390,
     400,   409,   430,   436,   442,   446,   452,   510,   527,   234,
     235,   236,   236,   327,   410,   437,   236,   447,   236,   365,
     431,   351,   236,   279,   307,   380,   236,   236,   401,   236,
     285,   236,   391,     1,    27,    34,   104,   273,   274,   275,
     276,   277,     1,    24,    25,    30,    65,    66,    71,    72,
      77,    78,    79,    85,    86,   110,   111,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   526,   236,   236,   236,     1,    67,   443,   444,
     445,   236,     1,     6,     7,     9,    10,    14,    22,    23,
      29,    32,    38,    43,    44,    46,    47,    48,    50,    59,
      63,    64,    74,    84,    91,    93,    95,    97,    99,   100,
     112,   117,   118,   119,   121,   122,   123,   126,   152,   162,
     163,   164,   165,   166,   167,   217,   218,   219,   221,   222,
     223,   232,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   503,
     507,   508,   509,   236,   236,   236,     1,   101,   125,   248,
     249,   250,   251,   236,   236,   236,     1,    31,    39,    51,
      52,    56,    57,    58,    81,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,     1,    27,    61,    70,    92,
      96,   104,   107,   108,   139,   156,   159,   160,   161,   187,
     205,   230,   231,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   236,     1,   228,   293,   294,   295,   296,   297,
     236,     1,   104,   387,   388,   389,   236,   234,   237,   237,
     237,   235,   274,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   235,   512,     1,
      17,    18,    21,    69,    86,    87,    88,    89,    90,    94,
      98,   104,   115,   116,   127,   149,   192,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,     1,     3,     5,    19,
      35,    60,    62,    69,    80,   104,   128,   148,   157,   205,
     230,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   425,   426,   427,   428,   429,     1,    67,   131,
     438,   439,   440,   441,   237,   235,   444,     1,   104,   131,
     448,   449,   450,   451,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   504,   237,   500,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   235,   454,     1,    19,    35,    69,   124,
     132,   133,   153,   229,   366,   367,   368,   369,   370,   371,
     372,   376,   377,   378,     1,   131,   229,   432,   433,   434,
     435,     1,    60,    67,    69,   128,   352,   356,   357,   358,
     362,   363,   234,   237,   237,   235,   249,     1,    83,   179,
     280,   281,   282,   283,     1,    19,    35,    69,   104,   124,
     140,   157,   158,   207,   229,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   322,     1,    37,    83,
     131,   381,   382,   383,   384,   385,   237,   237,   237,   237,
     237,   237,   237,   237,   235,   529,   234,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   235,   254,     1,   104,   225,   402,
     403,   404,   405,   234,   237,   235,   294,   179,     1,   104,
     172,   190,   206,   286,   287,   288,   289,   290,   291,   237,
     235,   388,     1,   104,   225,   229,   392,   393,   394,   395,
     396,   129,   129,   129,   234,   114,   114,   216,   114,   114,
     244,   114,   244,   114,   244,   244,   114,   114,   216,   216,
     234,   234,   237,   237,   237,   347,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   235,
     329,   234,   237,   237,   237,   237,   237,   237,   422,   237,
     237,   237,   237,   237,   237,   237,   235,   412,   237,   237,
     235,   439,   129,   234,   237,   237,   235,   449,   216,   244,
     114,   244,   244,   216,   114,   216,   114,   216,   244,   216,
     114,   114,   244,   114,   216,   216,   216,   244,   114,   114,
     244,   114,   114,   114,   114,   216,   237,   216,   237,   216,
     244,   244,   216,   216,   216,   216,   220,   216,   220,   216,
     216,   216,   114,   244,   216,   216,   244,   244,   216,   234,
     234,   237,   237,   373,   237,   237,   237,   237,   237,   235,
     367,   237,   237,   235,   433,   234,   237,   237,   353,   237,
     235,   357,   129,   129,   234,   234,   237,   237,   235,   281,
     234,   237,   237,   323,   237,   237,   237,   237,   237,   319,
     237,   235,   309,   234,   237,   237,   237,   235,   382,   216,
     216,   216,   129,   216,   216,   216,   244,   234,   129,   216,
     129,   114,   114,   129,   129,   129,   129,   129,   129,   129,
     129,   114,   129,   129,   129,   234,   234,   237,   406,   235,
     403,   216,   234,   236,   234,   237,   237,   237,   237,   235,
     287,   129,   234,   234,   237,   397,   237,   235,   393,   234,
     234,   234,   234,   234,   234,   234,   141,   142,   143,   144,
     145,   146,   147,   243,   244,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   114,   114,   244,   237,   114,
     114,   114,   244,   114,   114,   244,   129,   114,   114,   244,
     114,   246,   246,   234,   129,   183,   184,   129,   216,   129,
     129,   237,   129,   129,   114,   129,   129,   129,   129,   234,
     129,   129,   234,   234,   129,   129,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,    51,   169,   170,   171,   174,
     175,   177,   178,   180,   182,   185,   188,   189,   193,   197,
     201,   202,   203,   208,   213,   505,   506,   234,    51,    53,
      54,   169,   170,   171,   174,   175,   177,   178,   180,   182,
     185,   188,   189,   193,   197,   201,   202,   203,   208,   213,
     501,   502,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   129,   216,   237,   129,   114,   129,   129,   129,
     234,   129,   129,   234,   129,   129,   237,   114,   360,   361,
     234,   234,   234,   129,   129,   234,   129,   216,   237,   129,
     129,   129,   129,   216,   237,   129,   234,   129,   129,   129,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   129,   237,   234,   234,
       1,   104,   200,   225,   298,   299,   300,   301,   302,   129,
     129,   129,   129,   234,   234,   129,   237,   129,   234,   243,
     243,   243,   243,   243,   243,   243,   234,   234,   234,    55,
     130,   348,   349,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,    11,    12,    13,   245,   246,   234,
     234,   234,   234,   234,   234,   234,   234,   234,     8,   204,
     423,   424,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   238,   234,   238,   234,   234,    15,
      36,    45,    76,   105,   106,   113,   138,   154,   215,   374,
     375,   234,   234,   234,   234,   234,   234,   234,   234,   234,
      51,   195,   204,   354,   355,   224,   238,   359,   234,   234,
     234,   234,     4,    20,    28,    42,    73,    75,   101,   134,
     136,   155,   176,   181,   185,   194,   198,   209,   212,   214,
     226,   233,   324,   325,   234,   234,   234,   234,   234,    51,
      53,    54,   169,   170,   171,   174,   175,   177,   178,   180,
     182,   185,   188,   189,   193,   197,   201,   202,   203,   208,
     213,   320,   321,   234,   234,   234,   234,   234,    75,   137,
     168,   176,   185,   209,   211,   212,   226,   233,   407,   408,
     234,   237,   237,   303,   235,   299,   234,   234,   234,   234,
     234,    75,   137,   168,   176,   185,   209,   211,   212,   226,
     233,   398,   399,   234,   234,   238,   245,   245,   245,   234,
     238,   506,   502,   234,   238,   234,   238,   114,   361,   234,
     239,   239,   239,   234,   238,   234,   238,   234,   238,   129,
     210,   246,   237,   234,   234,   238,   349,   424,   375,   355,
     135,   135,   135,   325,   321,   408,   234,   234,   234,    42,
      73,    75,   120,   137,   175,   176,   229,   233,   304,   305,
     399,   234,   238,   305
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
     454,   454,   454,   454,   454,   454,   454,   454,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   483,   484,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   500,   499,   501,   501,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   504,   503,   505,   505,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   507,   508,   509,   510,   511,
     511,   512,   512,   512,   512,   512,   512,   512,   512,   512,
     512,   512,   512,   512,   512,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   528,   529,   529,   529,   529,   529,   529,   529,
     529,   529,   530,   531,   532,   533,   534,   535,   536,   537
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4
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
#line 2876 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 421 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2882 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 422 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2888 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 423 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2894 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 424 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2900 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 425 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2906 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 426 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2912 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 427 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2918 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 428 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2924 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 431 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2930 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 432 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2936 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 433 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2942 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 434 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2948 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 435 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2954 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 449 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2963 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 455 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2972 "conf_parser.c" /* yacc.c:1646  */
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

    if (SSL_CTX_use_certificate_file(ConfigServerInfo.server_ctx, yylval.string,
                                     SSL_FILETYPE_PEM) <= 0 ||
        SSL_CTX_use_certificate_file(ConfigServerInfo.client_ctx, yylval.string,
                                     SSL_FILETYPE_PEM) <= 0)
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
#line 3017 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 527 "conf_parser.y" /* yacc.c:1646  */
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
#line 3078 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 585 "conf_parser.y" /* yacc.c:1646  */
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
#line 3110 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 614 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    SSL_CTX_set_cipher_list(ConfigServerInfo.server_ctx, yylval.string);
#endif
}
#line 3121 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 622 "conf_parser.y" /* yacc.c:1646  */
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
#line 3138 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 636 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
#if OPENSSL_VERSION_NUMBER >= 0x1000005FL && !defined(OPENSSL_NO_ECDH)
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
#line 3169 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 664 "conf_parser.y" /* yacc.c:1646  */
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
#line 3187 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 679 "conf_parser.y" /* yacc.c:1646  */
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
#line 3205 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 694 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerInfo.description);
    ConfigServerInfo.description = xstrdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3218 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 704 "conf_parser.y" /* yacc.c:1646  */
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
#line 3235 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 718 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3247 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 727 "conf_parser.y" /* yacc.c:1646  */
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
#line 3278 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 755 "conf_parser.y" /* yacc.c:1646  */
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
#line 3309 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 783 "conf_parser.y" /* yacc.c:1646  */
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
#line 3337 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 808 "conf_parser.y" /* yacc.c:1646  */
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
#line 3362 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 830 "conf_parser.y" /* yacc.c:1646  */
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
#line 3387 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 852 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3396 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 869 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3408 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 878 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3420 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 887 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3432 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 899 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3441 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 903 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *ptr = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(ptr, block_state.mask.list.head)
    motd_add(ptr->data, block_state.file.buf);
}
#line 3458 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 920 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3467 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 926 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3476 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 935 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3485 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 939 "conf_parser.y" /* yacc.c:1646  */
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
#line 3503 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 957 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3512 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 963 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3521 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 969 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3530 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 975 "conf_parser.y" /* yacc.c:1646  */
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
#line 3553 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1004 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3562 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1010 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3571 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1014 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3584 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1030 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3595 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1038 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3603 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1041 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3611 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1046 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3620 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1053 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3629 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1057 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3638 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1061 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
#line 3647 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1065 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3656 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1069 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3665 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1073 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3674 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1077 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3683 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1081 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3692 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1085 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3701 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1095 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3713 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1102 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *ptr = NULL;

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

  DLINK_FOREACH(ptr, block_state.mask.list.head)
  {
    struct MaskItem *conf = NULL;
    struct split_nuh_item nuh;

    nuh.nuhmask  = ptr->data;
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
#line 3795 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1194 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3804 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1200 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3813 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1206 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3822 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1212 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3836 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1223 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3845 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1229 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3854 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1235 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3868 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1246 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3877 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1252 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3886 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1259 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3895 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1263 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3904 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1267 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3913 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1271 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3922 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1275 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3931 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1279 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3940 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1283 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3949 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1287 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3958 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1291 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3967 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1295 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3976 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1299 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3985 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1303 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3994 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1307 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 4003 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1311 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 4012 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1315 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 4021 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1319 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 4030 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1323 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 4039 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1327 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 4048 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1331 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 4057 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1335 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 4066 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1339 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4075 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1343 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4084 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1349 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4093 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1356 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4102 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1360 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4111 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1364 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4120 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1368 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4129 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1372 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4138 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1376 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4147 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1380 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4156 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1384 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4165 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1388 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4174 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1392 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4183 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1396 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4192 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1400 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4201 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1404 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
#line 4210 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1408 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4219 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1412 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4228 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1416 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4237 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1420 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4246 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1424 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4255 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1428 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4264 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1432 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4273 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1436 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4282 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1440 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4291 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1444 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4300 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1454 "conf_parser.y" /* yacc.c:1646  */
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
#line 4317 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1466 "conf_parser.y" /* yacc.c:1646  */
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
#line 4370 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1535 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4379 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1541 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4388 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1547 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4397 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1553 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4406 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1559 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4415 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1565 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4424 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1571 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4433 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1577 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4442 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1583 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4451 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1589 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4460 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1595 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4470 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1602 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4479 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1608 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4488 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1614 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4497 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1620 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4509 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1629 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4521 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1638 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4530 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1645 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4539 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1649 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4548 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1659 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4557 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1665 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4565 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1671 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4574 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1675 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4583 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1679 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4592 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1687 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4598 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 293:
#line 1692 "conf_parser.y" /* yacc.c:1646  */
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
#line 4616 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1705 "conf_parser.y" /* yacc.c:1646  */
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
#line 4636 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1722 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4645 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1728 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4654 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1737 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4663 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1741 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *ptr = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  DLINK_FOREACH(ptr, block_state.mask.list.head)
  {
    struct MaskItem *conf = NULL;
    struct split_nuh_item nuh;

    nuh.nuhmask  = ptr->data;
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
#line 4704 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1790 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4713 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1796 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4722 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1802 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4731 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1808 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4745 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1819 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4754 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1826 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4763 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1830 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4772 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1834 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4781 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1838 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4790 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1842 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4799 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1846 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4808 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1850 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
#line 4817 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1854 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4826 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1858 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4835 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1862 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4844 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1868 "conf_parser.y" /* yacc.c:1646  */
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
#line 4861 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1882 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4873 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1891 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4885 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1904 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4897 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1911 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4908 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1922 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4917 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1928 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4926 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1934 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4935 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1949 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct MaskItem *conf = conf_make(CONF_SERVICE);
    conf->name = xstrdup(yylval.string);
  }
}
#line 4950 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1964 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4966 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1975 "conf_parser.y" /* yacc.c:1646  */
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
#line 4983 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1992 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4992 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1998 "conf_parser.y" /* yacc.c:1646  */
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
#line 5014 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 358:
#line 2017 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5023 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 362:
#line 2024 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5032 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 2028 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5041 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 2032 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5050 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 2036 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5059 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 2040 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5068 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 367:
#line 2044 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5077 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 368:
#line 2048 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5086 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 369:
#line 2052 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5095 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 370:
#line 2056 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5104 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 371:
#line 2060 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5113 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 2069 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5127 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 2078 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
#line 5142 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 379:
#line 2093 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5151 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 2099 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5160 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 2106 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5169 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 2110 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5178 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 2114 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5187 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 2118 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5196 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 2122 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5205 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2126 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5214 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 390:
#line 2130 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5223 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 391:
#line 2134 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5232 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 392:
#line 2138 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5241 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 393:
#line 2142 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5250 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 394:
#line 2151 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5264 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 395:
#line 2160 "conf_parser.y" /* yacc.c:1646  */
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
#line 5330 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 413:
#line 2240 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5339 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 414:
#line 2246 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5348 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 415:
#line 2252 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5357 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 416:
#line 2258 "conf_parser.y" /* yacc.c:1646  */
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
#line 5373 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 417:
#line 2271 "conf_parser.y" /* yacc.c:1646  */
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
#line 5389 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 418:
#line 2284 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5398 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2290 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5407 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2296 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5416 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2300 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5425 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2306 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5433 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 426:
#line 2312 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5442 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 427:
#line 2316 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5451 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 428:
#line 2322 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5465 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 429:
#line 2333 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5474 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 430:
#line 2339 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5483 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2345 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5492 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2351 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
#line 5506 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2366 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5515 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2370 "conf_parser.y" /* yacc.c:1646  */
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
#line 5540 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 440:
#line 2395 "conf_parser.y" /* yacc.c:1646  */
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
#line 5563 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 441:
#line 2415 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5572 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 442:
#line 2424 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5581 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2428 "conf_parser.y" /* yacc.c:1646  */
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
#line 5607 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 449:
#line 2454 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5616 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2460 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5625 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 456:
#line 2474 "conf_parser.y" /* yacc.c:1646  */
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
#line 5642 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 457:
#line 2491 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5651 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2495 "conf_parser.y" /* yacc.c:1646  */
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
#line 5673 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 464:
#line 2517 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5682 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 465:
#line 2523 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5691 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2588 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5699 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2593 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5707 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2598 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5715 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2603 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5724 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2609 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.glines = yylval.number;
}
#line 5733 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2615 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.gline_time = (yyvsp[-1].number);
}
#line 5742 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2621 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.gline_request_time = (yyvsp[-1].number);
}
#line 5751 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2627 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.gline_min_cidr = (yyvsp[-1].number);
}
#line 5759 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2632 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.gline_min_cidr6 = (yyvsp[-1].number);
}
#line 5767 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2637 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.tkline_expire_notices = yylval.number;
}
#line 5775 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2642 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5783 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2647 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.hide_spoof_ips = yylval.number;
}
#line 5791 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2652 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ignore_bogus_ts = yylval.number;
}
#line 5799 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2657 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5807 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2662 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5815 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2667 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5823 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2672 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5831 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2677 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5839 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2682 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5847 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2687 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5855 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2692 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5864 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2698 "conf_parser.y" /* yacc.c:1646  */
    {
  if (((yyvsp[-1].number) > 0) && conf_parser_ctx.pass == 1)
  {
    ilog(LOG_TYPE_IRCD, "You haven't read your config file properly.");
    ilog(LOG_TYPE_IRCD, "There is a line in the example conf that will kill your server if not removed.");
    ilog(LOG_TYPE_IRCD, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
#line 5878 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2709 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5886 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2714 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5894 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2719 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5902 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2724 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5910 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2729 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5918 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2734 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5926 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2739 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5934 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2742 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5942 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2747 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5950 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2750 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5958 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2755 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5966 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2760 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5974 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2765 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5982 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2770 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5990 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2775 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5998 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2780 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 6006 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2785 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.true_no_oper_flood = yylval.number;
}
#line 6014 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2790 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_pass_resv = yylval.number;
}
#line 6022 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2795 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 6030 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2800 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6038 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2805 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6046 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 562:
#line 2810 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6054 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2815 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6062 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 564:
#line 2820 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6070 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2825 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 6078 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2831 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 6086 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2834 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6094 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2837 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6102 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2840 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 6110 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2843 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 6118 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2846 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6126 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2849 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6134 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2852 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6142 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2855 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6150 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2858 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6158 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2861 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6166 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2864 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 6174 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2867 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6182 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2870 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6190 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2873 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6198 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2876 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6206 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2879 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6214 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2882 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6222 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2885 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6230 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 588:
#line 2888 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6238 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 589:
#line 2891 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6246 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2894 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6254 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2899 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6262 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2905 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6270 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2908 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6278 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2911 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6286 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2914 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6294 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2917 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6302 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2920 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6310 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2923 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6318 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2926 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6326 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2929 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6334 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2932 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6342 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2935 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6350 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2938 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6358 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2941 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6366 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2944 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6374 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2947 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6382 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2950 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6390 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2953 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6398 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2956 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6406 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2959 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6414 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 614:
#line 2962 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6422 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 615:
#line 2967 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6430 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 616:
#line 2972 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6438 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 617:
#line 2977 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6446 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 3006 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6454 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 3011 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6462 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 638:
#line 3016 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6470 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 639:
#line 3021 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6478 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 640:
#line 3026 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6486 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 641:
#line 3031 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6494 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 642:
#line 3036 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6502 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 643:
#line 3041 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6510 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 644:
#line 3046 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_user_count = (yyvsp[-1].number);
}
#line 6518 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 645:
#line 3051 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_server_count = (yyvsp[-1].number);
}
#line 6526 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 646:
#line 3056 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
#line 6534 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 647:
#line 3061 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
#line 6542 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 648:
#line 3066 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
#line 6550 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 649:
#line 3071 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodtime = (yyvsp[-1].number);
}
#line 6558 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 662:
#line 3093 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6567 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 663:
#line 3099 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6576 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 664:
#line 3105 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6585 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 665:
#line 3111 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6594 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 666:
#line 3117 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6606 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 667:
#line 3126 "conf_parser.y" /* yacc.c:1646  */
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
#line 6624 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 668:
#line 3141 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6633 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 669:
#line 3147 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6642 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6646 "conf_parser.c" /* yacc.c:1646  */
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
