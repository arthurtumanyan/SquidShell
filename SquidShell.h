#ifndef SQUIDSHELL_H_INCLUDED
#define SQUIDSHELL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <error.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/file.h>     /*  socket definitions        */
#include <sys/types.h>        /*  socket types              */
#include <arpa/inet.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <regex.h>
#include <fcntl.h>
#include <syslog.h>
#include <signal.h>
#include <time.h>
#include <sys/file.h>


#define MAXLINE 	255
#define HIST_MAX        100
#define SQUID_DEF_PORT  3128


int doneProg = 0;
int n,v,port,c,i,opt;

int clf = 0; // command line flag
time_t ticks;
char D_TIME[MAXLINE];
char TMP_MSG[MAXLINE];
char inputline[MAXLINE];
char sendline[MAXLINE];
char listen_addr[15];
char *asciiWelcome[6];
char *p;
char ip_addr[15];
char ml[16]; // cache manager login
char mp[64]; // cache manager password
char rh[15]; // remote host
char rp[5];  // remote port

const char delimiters[] = ",:= ";
const char *log_file = "SquidShell.log";
const char *welcome_str = "Welcome to SquidShell";
const char *bye_str = "Force be with you!";

ssize_t n;
regex_t regex;
FILE *log_fd,*history;
/*

*/
struct {
    char login[16];
    char pwd[64];
    char cmd[64];
    char data[64];
    
}cmds,result;

#endif // SQUIDSHELL_H_INCLUDED
