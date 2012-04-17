#include "SquidShell.h"
//
//
void _syslog(char *log_string){
	openlog("SquidShell",LOG_NDELAY | LOG_PID,LOG_USER);
	syslog(LOG_INFO,"%s",log_string);
	closelog();
	}

//
void log_debug(char *log_string)
{
    ticks = time(NULL);
    snprintf(D_TIME,25,"%.24s",ctime(&ticks));
    if ((log_fd = fopen(log_file,"a+")) == NULL)
    {
	snprintf(TMP_MSG,MAXLINE,"Cannot create log file '%s' - %s\n",log_file,strerror(errno));
	_syslog(TMP_MSG);
	}else{
    fprintf(log_fd,"[%s][pid %d] %s\n",D_TIME,getpid(),log_string);
    fclose(log_fd);
	}
}
