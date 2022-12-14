/**
	Handle multiple socket connections with select and fd_set on Linux
*/

#ifndef HEADER_H
#define HEADER_H 1

#include    <stdio.h>
#include    <time.h>
#include    <sys/select.h>
#include    <string.h>          //strlen
#include    <stdlib.h>
#include    <errno.h>
#include    <unistd.h>          //close
#include    <arpa/inet.h>       //close
#include    <sys/types.h>
#include    <sys/socket.h>
#include    <netinet/in.h>
#include    <sys/time.h>        //FD_SET, FD_ISSET, FD_ZERO macros
#include    <netdb.h>
#include    <linux/libc-compat.h>
//#include <arpa/inet.h>

#define TRUE   1
#define FALSE  0

void error (char *);

void *reading (void *p);

void connect_server ( void );

void rec_read (void );

void AcceptTCPConn_read (int sock );

struct message {
    int group_id;
    char flag :3;
    char ip[16];
	int time;
    char buff[1024];
};

#endif 
