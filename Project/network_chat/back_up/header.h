/**
	Handle multiple socket connections with select and fd_set on Linux
*/

#include    <stdio.h>
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
//#define PORT 2069

/*struct message {
    char buff[1024];
    char ip[16];
};*/
typedef struct queue{
    char buff[1024];
    char src_ip[16];
    char dst_ip[16];
    struct queue* next;
    }NODE;
void error (char *);

NODE *add_end(NODE *, NODE *);

//char online_ip[100][16];

//int master_socket , src_addrlen, cli_addrlen , new_socket , client_socket[30] , max_clients = 30 , activity, i , j , valread , sd;
//int max_sd;



