/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  ircd.c: Starts up and runs the ircd.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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

#ifdef IN_IRCD
#include "stdinc.h"
#include "conf/conf.h"
#include "user.h"
#include "ircd.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "common.h"
#include "hash.h"
#include "ircd_signal.h"
#include "motd.h"
#include "ircd_handler.h"
#include "msg.h"         /* msgtab */
#include "numeric.h"
#include "packet.h"
#include "parse.h"
#include "restart.h"
#include "s_auth.h"
#include "parse_aline.h"
#include "server.h"
#include "send.h"
#include "whowas.h"
#include "motd.h"
#include "watch.h"
#include "patchlevel.h"
#include "serno.h"


/* /quote set variables */
struct SetOptions GlobalSetOptions;
struct ServerStatistics ServerStats;
/* admin info set from ircd.conf */
struct Counter Count = { 0, 0, 0, 0, 0, 0, 0, 0 };
struct ServerState_t ServerState = { 0 };
struct Client me;             /* That's me */
struct LocalUser meLocalUser; /* That's also part of me */

char **myargv;
const char *ircd_version = PATCHLEVEL;
const char *serno = SERIALNUM;
char ircd_platform[IRCD_BUFSIZE];

int dorehash = 0;
int doremotd = 0;

/* Set to zero because it should be initialized later using
 * initialize_server_capabs
 */
int default_server_capabs = 0;

#ifdef HAVE_LIBCRYPTO
int bio_spare_fd = -1;
#endif

int splitmode;
int splitchecking;

static dlink_node *fdlimit_hook;

/* Do klines the same way hybrid-6 did them, i.e. at the
 * top of the next io_loop instead of in the same loop as
 * the klines are being applied.
 *
 * This should fix strange CPU starvation as very indirectly reported.
 * (Why do you people not email bug reports? WHY? WHY?)
 *
 * - Dianora
 */

int rehashed_klines = 0;

#ifndef _WIN32
/*
 * print_startup - print startup information
 */
static void
print_startup(int pid)
{
  printf("ircd: version %s\n", ircd_version);
  printf("ircd: pid %d\n", pid);
  printf("ircd: running in %s mode from %s\n",
         ServerState.foreground ? "foreground" : "background", DPATH);
}

static void
make_daemon(void)
{
  int pid;

  if ((pid = fork()) < 0)
  {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  else if (pid > 0)
  {
    print_startup(pid);
    exit(EXIT_SUCCESS);
  }

  setsid();
}
#endif

static struct lgetopt myopts[] = {
  {"configfile", &ServerState.configfile,
   STRING, "File to use for ircd.conf"},
  {"klinefile",  &ServerState.klinefile,
   STRING, "File to use for kline.conf"},
  {"rklinefile", &ServerState.rklinefile,
   STRING, "File to use for rkline.conf"},
  {"dlinefile",  &ServerState.dlinefile,
   STRING, "File to use for dline.conf"},
  {"glinefile",  &ServerState.glinefile,
   STRING, "File to use for gline.conf"},
  {"xlinefile",  &ServerState.xlinefile,
   STRING, "File to use for xline.conf"},
  {"rxlinefile", &ServerState.rxlinefile,
   STRING, "File to use for rxline.conf"},
  {"cresvfile",  &ServerState.cresvfile,
   STRING, "File to use for cresv.conf"},
  {"nresvfile",  &ServerState.nresvfile,
   STRING, "File to use for nresv.conf"},
  {"logfile",    &ServerState.logfile,
   STRING, "File to use for ircd.log"},
  {"pidfile",    &ServerState.pidfile,
   STRING, "File to use for process ID"},
  {"foreground", &ServerState.foreground,
   YESNO, "Run in foreground (don't detach)"},
  {"version",    &ServerState.printversion,
   YESNO, "Print version and exit"},
  {"help", NULL, USAGE, "Print this text"},
  {NULL, NULL, STRING, NULL},
};

static void
io_loop(void)
{
  while (1 == 1)
  {
    /*
     * Maybe we want a flags word?
     * ie. if (REHASHED_KLINES(global_flags)) 
     * SET_REHASHED_KLINES(global_flags)
     * CLEAR_REHASHED_KLINES(global_flags)
     *
     * - Dianora
     */
    if (rehashed_klines)
    {
      check_conf_klines();
      rehashed_klines = 0;
    }

    if (listing_client_list.head)
    {
      dlink_node *ptr = NULL, *ptr_next = NULL;
      DLINK_FOREACH_SAFE(ptr, ptr_next, listing_client_list.head)
      {
        struct Client *client_p = ptr->data;
        assert(client_p->localClient->list_task);
        safe_list_channels(client_p, client_p->localClient->list_task, 0);
      }
    }

    /* Run pending events, then get the number of seconds to the next
     * event
     */
    while (eventNextTime() <= CurrentTime)
      eventRun();

    comm_select();
    exit_aborted_clients();
    free_exited_clients();
    send_queued_all();

    // Check to see whether we have to rehash the configuration ..
    if (dorehash)
    {
      sendto_realops_flags(UMODE_ALL, L_ALL,
        "Got signal SIGHUP, reloading ircd configuration");
      read_conf_files(NO);
      dorehash = 0;
    }

    if (doremotd)
    {
      read_message_file(&motd);
      sendto_realops_flags(UMODE_ALL, L_ALL,
        "Got signal SIGUSR1, reloading ircd MOTD file");
      doremotd = 0;
    }
  }
}

/* initalialize_global_set_options()
 *
 * inputs       - none
 * output       - none
 * side effects - This sets all global set options needed 
 * XXX to be removed with old s_conf.c
 */
static void
initialize_global_set_options(void)
{
  memset(&GlobalSetOptions, 0, sizeof(GlobalSetOptions));

  GlobalSetOptions.autoconn  = 1;
  GlobalSetOptions.spam_time = MIN_JOIN_LEAVE_TIME;
  GlobalSetOptions.spam_num  = MAX_JOIN_LEAVE_COUNT;

  if (General.default_floodcount)
    GlobalSetOptions.floodcount = General.default_floodcount;
  else
    GlobalSetOptions.floodcount = 10;

  // XXX I have no idea what to try here - Dianora
  GlobalSetOptions.joinfloodcount = 16;
  GlobalSetOptions.joinfloodtime = 8;

  GlobalSetOptions.split_servers = Channel.default_split_server_count;
  GlobalSetOptions.split_users   = Channel.default_split_user_count;

  if (GlobalSetOptions.split_users && GlobalSetOptions.split_servers &&
      (Channel.no_create_on_split || Channel.no_join_on_split))
  {
    splitmode     = 1;
    splitchecking = 1;
  }

  GlobalSetOptions.ident_timeout = IDENT_TIMEOUT;
  GlobalSetOptions.idletime = General.idletime;
  GlobalSetOptions.maxlisters = 10; /* XXX ya ya ya - db */
}

/* write_pidfile()
 *
 * inputs       - filename+path of pid file
 * output       - NONE
 * side effects - write the pid of the ircd to filename
 */
static void
write_pidfile(const char *filename)
{
  FBFILE *fb;

  if ((fb = fbopen(filename, "w")))
  {
    char buff[32];
    unsigned int pid = (unsigned int)getpid();
    size_t nbytes = ircsprintf(buff, "%u\n", pid);

    if ((fbputs(buff, fb, nbytes) == -1))
      ilog(L_ERROR, "Error writing %u to pid file %s (%s)",
           pid, filename, strerror(errno));

    fbclose(fb);
  }
  else
  {
    ilog(L_ERROR, "Error opening pid file %s", filename);
  }
}

/* check_pidfile()
 *
 * inputs       - filename+path of pid file
 * output       - none
 * side effects - reads pid from pidfile and checks if ircd is in process
 *                list. if it is, gracefully exits
 * -kre
 */
static void
check_pidfile(const char *filename)
{
#ifndef _WIN32
  FBFILE *fb;
  char buff[32];
  pid_t pidfromfile;

  // Don't do logging here, since we don't have log() initialised
  if ((fb = fbopen(filename, "r")))
  {
    if (fbgets(buff, 20, fb) == NULL)
    {
      /* log(L_ERROR, "Error reading from pid file %s (%s)", filename,
       * strerror(errno));
       */
    }
    else
    {
      pidfromfile = atoi(buff);

      if (!kill(pidfromfile, 0))
      {
        // log(L_ERROR, "Server is already running");
        printf("ircd: daemon is already running\n");
        exit(-1);
      }
    }

    fbclose(fb);
  }
  else if (errno != ENOENT)
  {
    // log(L_ERROR, "Error opening pid file %s", filename);
  }
#endif
}

/* init_ssl()
 *
 * inputs       - nothing
 * output       - nothing
 * side effects - setups SSL context.
 */
static void
ssl_init(void)
{
#ifdef HAVE_LIBCRYPTO
  SSL_library_init();
  SSL_load_error_strings();

  ServerInfo.ctx = SSL_CTX_new(SSLv23_server_method());

  if (!ServerInfo.ctx)
  {
    const char *s;

    fprintf(stderr, "ERROR: Could not initialize the SSL context -- %s\n",
            s = ERR_lib_error_string(ERR_get_error()));
    ilog(L_CRIT, "ERROR: Could not initialize the SSL context -- %s\n", s);
  }

  SSL_CTX_set_options(ServerInfo.ctx, SSL_OP_NO_SSLv2);
  SSL_CTX_set_options(ServerInfo.ctx, SSL_OP_TLS_ROLLBACK_BUG|SSL_OP_ALL);
  SSL_CTX_set_verify(ServerInfo.ctx, SSL_VERIFY_NONE, NULL);

  bio_spare_fd = save_spare_fd("SSL private key validation");
#endif /* HAVE_LIBCRYPTO */
}

/* init_callbacks()
 *
 * inputs       - nothing
 * output       - nothing
 * side effects - setups standard hook points
 */
static void
init_callbacks(void)
{
  entering_umode_cb = register_callback("entering_umode", NULL);
  iorecv_cb = register_callback("iorecv", iorecv_default);
  iosend_cb = register_callback("iosend", iosend_default);
  iorecvctrl_cb = register_callback("iorecvctrl", NULL);
  iosendctrl_cb = register_callback("iosendctrl", NULL);
  authorize_client = register_callback("authorize_client", do_authorize_client);
  uid_get = register_callback("uid_get", do_uid_get);
  umode_cb = register_callback("changing_umode", change_simple_umode);
}

static void *
changing_fdlimit(va_list args)
{
  int old_fdlimit = hard_fdlimit;
  int fdmax = va_arg(args, int);

  /*
   * allow MAXCLIENTS_MIN clients even at the cost of MAX_BUFFER and
   * some not really LEAKED_FDS
   */
  fdmax = LIBIO_MAX(fdmax, LEAKED_FDS + MAX_BUFFER + MAXCLIENTS_MIN);

  pass_callback(fdlimit_hook, fdmax);

  if (ServerInfo.max_clients > MAXCLIENTS_MAX)
  {
    if (old_fdlimit != 0)
      sendto_realops_flags(UMODE_ALL, L_ALL,
        "HARD_FDLIMIT changed to %d, adjusting MAXCLIENTS to %d",
        hard_fdlimit, MAXCLIENTS_MAX);

    ServerInfo.max_clients = MAXCLIENTS_MAX;
  }

  return NULL;
}

EXTERN int
main(int argc, char *argv[])
{
  /*
   * Check to see if the user is running us as root, which is a nono
   */
#ifndef _WIN32
  if (geteuid() == 0)
  {
    fprintf(stderr, "Don't run ircd as root!!!\n");
    return 1;
  }

  // Setup corefile size immediately after boot -kre
  setup_corefile();
#endif

  memset(&ServerInfo, 0, sizeof(ServerInfo));
  memset(&ServerStats, 0, sizeof(ServerStats));

  ServerState.configfile = CPATH;  // Server configuration file
  ServerState.klinefile  = KPATH;  // Server kline file
  ServerState.rklinefile = RKPATH; // Server regex kline file
  ServerState.dlinefile  = DLPATH; // dline file
  ServerState.glinefile  = GPATH;  // gline log file
  ServerState.xlinefile  = XPATH;  // Server xline file
  ServerState.rxlinefile = RXPATH; // Server regex xline file
  ServerState.cresvfile  = CRESVPATH; // channel resv file
  ServerState.nresvfile  = NRESVPATH; // nick resv file
  ServerState.logfile    = LPATH;
  ServerState.pidfile    = PPATH;
  myargv = argv;
  umask(077);                // better safe than sorry --SRB

  parseargs(&argc, &argv, myopts);

  if (ServerState.printversion)
  {
    printf("ircd: version %s\n", ircd_version);
    exit(EXIT_SUCCESS);
  }

  if (chdir(DPATH))
  {
    perror("chdir");
    exit(EXIT_FAILURE);
  }

  ssl_init();

#ifndef _WIN32
  if (!ServerState.foreground)
    make_daemon();
  else
    print_startup(getpid());
#endif

  libio_init(!ServerState.foreground);
  init_restart();
  fdlimit_hook = install_hook(fdlimit_cb, changing_fdlimit);

  check_pidfile(ServerState.pidfile);
  setup_signals();
  libio_get_platform(ircd_platform, sizeof(ircd_platform));
  init_log(ServerState.logfile);
  ServerState.can_use_v6 = check_can_use_v6();

  memset(&me, 0, sizeof(me));
  memset(&meLocalUser, 0, sizeof(meLocalUser));
  me.localClient = &meLocalUser;
  me.from = me.servptr = &me;
  me.lasttime = me.since = me.firsttime = CurrentTime;
  SetMe(&me);
  make_server(&me);
  dlinkAdd(&me, &me.node, &global_client_list);
  dlinkAdd(&me, make_dlink_node(), &global_serv_list);

  init_callbacks();
  init_motd();
  init_isupport();
  hash_init();
  clear_tree_parse();
  init_client();
  whowas_init();
  watch_init();
  init_auth();
  channel_init();
  init_channel_modes();
  server_init();
  init_conf();
  modules_init();
  read_conf_files(YES); // cold start init conf files
  init_uid();
  initialize_global_set_options();

  /*
   * assemble_umode_buffer() has to be called after
   * reading conf/loading modules.
   */
  assemble_umode_buffer();

  write_pidfile(ServerState.pidfile);

  ilog(L_NOTICE, "Server Ready");

  // We want try_connections to be called as soon as possible now! -- adrian
  // No, 'cause after a restart it would cause all sorts of nick collides
  eventAddIsh("try_connections", try_connections, NULL, STARTUP_CONNECTIONS_TIME);

  eventAddIsh("collect_zipstats", collect_zipstats, NULL, ZIPSTATS_TIME);

  // Setup the timeout check. I'll shift it later :)  -- adrian
  eventAddIsh("comm_checktimeouts", comm_checktimeouts, NULL, 1);

  io_loop();
  return 0;
}

#else

#include <windows.h>

extern __declspec(dllimport) main(int, char **);

/*
 * Initial entry point for Win32 GUI applications, called by the C runtime.
 *
 * It should be only a wrapper for main(), since when compiled as a console
 * application, main() is called instead.
 */
int WINAPI
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
        LPSTR lpCmdLine, int nCmdShow)
{
  /* Do we really need these pidfile, logfile etc arguments?
   * And we are not on a console, so -help or -foreground is meaningless. */

  char *argv[2] = {"ircd", NULL};

  return main(1, argv);
}

#endif
