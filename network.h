#ifndef NETWORK_H_INCLUDED
#define NETWORK_H_INCLUDED

int listenfd,
connfd,sockfd,
is_connected = 0,
maxcon,
nready;
socklen_t clilen;
int listen_port;
struct sockaddr_in cliaddr,servaddr;



#endif // NETWORK_H_INCLUDED
