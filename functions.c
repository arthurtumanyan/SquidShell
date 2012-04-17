#include "SquidShell.h"
#include "commands.h"
#include "prototypes.h"

void Trim(char *str){
	char *p;
if ((p = strchr(str, '\n')) != NULL){
	    *p = '\0';
        }
if ((p = strchr(str, '\r')) != NULL){
	    *p = '\0';
        }
}

void saveCmd(char *cmd){
    if(cmd[0] == '\n' || cmd[0] == '\0')return;
    if((history = fopen(histFile,"a+")) != NULL){
        flock((int)history,LOCK_SH);
        fprintf(history,"%s",cmd);
       }else{
        snprintf(TMP_MSG,MAXLINE,"Cannot write to history file '%s' - err:%s",histFile,strerror(errno));
    log_debug(TMP_MSG);
       }
       flock((int)history,LOCK_UN);
     
}

int is_digit(char *pDigit){
    return isdigit(pDigit[0]);
}

void initHistory(){

    he = (struct hElement *)malloc(sizeof(struct hElement));
  c = 1;

if((history = fopen(histFile,"r")) != NULL){
    flock((int)history,LOCK_SH);
    while(fgets(hline,MAXLINE,history) != NULL){
        hline[strlen(hline)-1] = '\0';
    if(hline[0] == '\n'||hline[0] == '\0')continue;
    if(c >= HIST_MAX){
        truncate(histFile,0);
        break;
        };
        he->no[c] = c;
        sprintf(he->cmd[c],"%s",hline);

        c++;
    }

}else {
    snprintf(TMP_MSG,MAXLINE,"Cannot access history file '%s' - err:%s",histFile,strerror(errno));
    log_debug(TMP_MSG);
}
    flock((int)history,LOCK_UN);
    fclose(history);
}

void fillArgs(char *token){
int i = 0;
token = strtok (NULL, delimiters);
  while(token != NULL){
         sscanf(token,"%s",rv->args[i]);
         printf("Fill args [%d]+> %s\n",i,rv->args[i]);
	 token = strtok (NULL, delimiters);
        i++;
    } /* end of while loop */
} /* end of fillArgs */

int isValidHost(char *str){

    int segs = 0;   /* Segment count. */
    int chcnt = 0;  /* Character count within segment. */
    int accum = 0;  /* Accumulator for segment. */

    /* Catch NULL pointer. */

    if (str == NULL)
        return 0;

    /* Process every character in string. */

    while (*str != '\0') {
        /* Segment changeover. */

        if (*str == '.') {
            /* Must have some digits in segment. */

            if (chcnt == 0)
                return 0;

            /* Limit number of segments. */

            if (++segs == 4)
                return 0;

            /* Reset segment values and restart loop. */

            chcnt = accum = 0;
            str++;
            continue;
        }

        /* Check numeric. */

        if ((*str < '0') || (*str > '9'))
            return 0;

        /* Accumulate and check segment. */

        if ((accum = accum * 10 + *str - '0') > 255)
            return 0;

        /* Advance other segment specific stuff and continue loop. */

        chcnt++;
        str++;
    }

    /* Check enough segments and enough characters in last segment. */

    if (segs != 3)
        return 0;

    if (chcnt == 0)
        return 0;

    /* Address okay. */

    return 1;
}

int isValidPort(const char * p){
int port,z;
if(p == NULL){
    port = SQUID_DEF_PORT;
    printf("Port number is not specified\nUsing default port number: %d\n",SQUID_DEF_PORT);
    return port;
}
if(0 != (z = sscanf(p,"%d",&port))){
    if(port > 0 && port <= 65535){
        return port;
    }
}
  return -1;
}

void handler_sigint(){
	log_debug("Caught SIGINT signal");
	Shutdown();
}
void handler_sigquit(){
	log_debug("Caught SIGQUIT signal");
	Shutdown();
}
void handler_sigterm(){
	log_debug("Caught SIGTERM signal");
	Shutdown();
}
void handler_sigtrap(){
	log_debug("Caught SIGTRAP signal");
	Shutdown();
}
void handler_sighup(){

	log_debug("Caught SIGHUP signal");
	Shutdown();
}
void handler_sigusr(){
	log_debug("Caught SIGUSR signal");
	Shutdown();
}
void set_sig_handler(){

	signal(SIGINT,handler_sigint);
	signal(SIGHUP,handler_sighup);
	signal(SIGTERM,handler_sigterm);
	signal(SIGQUIT,handler_sigquit);
	signal(SIGUSR1|SIGUSR2,handler_sigusr);
	signal(SIGTRAP,handler_sigtrap);
	signal(SIGCHLD,SIG_IGN); /* ignore child */
	signal(SIGTSTP,SIG_IGN); /* ignore tty signals */
	signal(SIGTTOU,SIG_IGN);
	signal(SIGTTIN,SIG_IGN);
	signal(SIGIOT,SIG_IGN);
	signal(SIGABRT,SIG_IGN);
}

void Shutdown(){
  log_debug("Shutting down");
  exit(EXIT_SUCCESS);
}

void low_string(char *str){
int h;
	for(h = 0;h < strlen(str);h++)str[h] = tolower((int)str[h]);
}
