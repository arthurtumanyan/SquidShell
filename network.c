#include "SquidShell.h"
#include "commands.h"
#include "prototypes.h"
#include "network.h"

ssize_t Readline(int sockd, void *vptr, size_t maxlen) {
    ssize_t n, rc;
    char    c, *buffer;

    buffer = vptr;

    for ( n = 1; n < maxlen; n++ ) {

	if ( (rc = read(sockd, &c, 1)) == 1 ) {
	    *buffer++ = c;
	    if ( c == '\n' )
		break;
	}
	else if ( rc == 0 ) {
	    if ( n == 1 )
		return 0;
	    else
		break;
	}
	else {
	    if ( errno == EINTR )
		continue;
	    return -1;
	}
    }

    *buffer = 0;
    return n;
}

/*  Write a line to a socket  */

ssize_t Writeline(int sockd, const void *vptr, size_t n) {
    size_t      nleft;
    ssize_t     nwritten;
    const char *buffer;

    buffer = vptr;
    nleft  = n;

    while ( nleft > 0 ) {
	if ( (nwritten = write(sockd, buffer, nleft)) <= 0 ) {
	    if ( errno == EINTR )
		nwritten = 0;
	    else
		return -1;
	}
	nleft  -= nwritten;
	buffer += nwritten;
    }

    return n;
}

void reset_connection(int sockfd)
{
	shutdown(sockfd,SHUT_RDWR);
}



void dialog(int sockfd)
{
       while (Readline(sockfd,sendline, MAXLINE) != 0) {

		if (sscanf(sendline, "%16s%64s%64s%64s", cmds.login, cmds.pwd,cmds.cmd,cmds.data) != 4) {
			printf("invalid input: %s\n", sendline);
			continue;
		}
		Writeline(sockfd, &cmds, sizeof(cmds));

		if (Readline(sockfd, &result, sizeof(result)) == 0)
			printf("dialog: server terminated prematurely\n");
		
	}
	
}
