#include "SquidShell.h"
#include "commands.h"
#include "prototypes.h"
#include "network.h"
#
unsigned int do_command(char *cmd){

  char p[MAXLINE];
  strncpy(p,cmd,MAXLINE);
  
 struct cmd_p *r = parseCmd(cmd);
  printf("CMD: %s Len: %d\n",r->cmd,strlen(r->cmd));//must be deleted
for(n = 0;n < CMD_COUNT;n++){
    if(0 == strcmp(cmd_table[n].cmd_name,r->cmd)){
       (cmd_table[n].func)(**(r->args));
    if(!is_digit(p))saveCmd(p);
       return 1;
        }
    } /* end of for loop */
    return 0;
} /* end of do_command */

struct cmd_p * parseCmd(char *cmd){

    rv = (struct cmd_p *)malloc(sizeof(struct cmd_p));

     char *token;
     token = strtok (cmd, delimiters);

    if(is_digit(token)){
     int index = atoi(token);
        sscanf(he->cmd[index],"%s",rv->cmd);
        token = strtok (he->cmd[index], delimiters);
        fillArgs(he->cmd[index]);
    }else{
        sscanf(token,"%s",rv->cmd);
        fillArgs(token);
    }

  	return rv;
} /* end of parseCmd */

void cmd_set(char **argv){

   printf("I'm %s\nMy first arg is: %s\n",
          __FUNCTION__,
          rv->args[0]);
}

void cmd_history(){
initHistory();
int c;
 printf("--LAST COMMANDS--\n");
 for(c = 1;c <= HIST_MAX;c++){

     if(he->no[c] == 0||
        he->no[c] > HIST_MAX||
        he->no[c] < he->no[c - 1])break;

        printf("%2d   %s\n",he->no[c],he->cmd[c]);
        if((c == 20 || (c % 20) == 0) && c != 0){
            printf("Press any key to continue...");
            getc(stdin);
        }

 }
} /* end of cmd_history */


void cmd_proxy(char **argv){}
void cmd_show(char **argv){}
void cmd_benchmark(char **argv){}


void cmd_connect(char **argv)
{

char mlogin[MAXLINE],*pwd;

if (clf == 0){
   v = isValidHost(rv->args[0]);
   port = isValidPort(rv->args[1]);
}else{
  v = isValidHost((char *)rh);
  port = isValidPort(rp);
}

if(1 == v && port != -1){
if(clf == 0){
   printf("Enter the cache manager login:");
    fgets(mlogin,MAXLINE,stdin);
    pwd = getpass("Password:");
    printf("Login: %s Pass: %s\n",mlogin,pwd); //delete
}
Trim(mlogin);
Trim(pwd);
strcpy(cmds.login,mlogin);
strcpy(cmds.pwd,pwd);
strcpy(cmds.cmd,"");
strcpy(cmds.data,"");

  make_connect((clf == 0)?rv->args[0]:rh,
          (clf == 0)?rv->args[1]:rp,
          mlogin,pwd);
  
    }else {
printf("%s %s",
       "\tPlease enter valid proxy server ip address and port\n\t",
       "Usage: 127.0.0.1 3128\n");
    return;
    } /* if-else condition */

    
}

void make_connect(char *hostname, int port,char *login,char *pwd)
{
  is_connected = 1;
  
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	inet_pton(AF_INET, hostname, &servaddr.sin_addr);

	connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
        dialog(sockfd);
}


void cmd_save(char **argv){}

void cmd_help(){
        for(n = 0;n < CMD_COUNT;n++){
             printf("%20s\t%s\n",cmd_table[n].cmd_name,cmd_table[n].desc);
            }
            putchar ('\n');
} /* end of cmd_help */

void cmd_quit(){
    doneProg = 1;
    fprintf(stdout,"%s\n",bye_str);

    exit(EXIT_SUCCESS);
}

void cmd_shell(){

  system("/bin/sh");

}