#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/time.h>


#define MAXLINE 4096    /* max text line length*/
#define SA struct sockaddr  
#define LISTENQ 5       /* requests in queue */ 
#define TCPPORT 2069      /* TCP daytime port */

char    buff[MAXLINE];  /* buffer for message */


int main()
{
	int listenfd,connfd,n;
	socklen_t len;
	int retval;
	int a = 1;
	struct timeval tv;
	struct  sockaddr_in servaddr, cliaddr;
	fd_set rfds;


	listenfd = socket(AF_INET,SOCK_STREAM,0);

	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(TCPPORT);          /* day time server */

	inet_pton(AF_INET, "172.16.5.229", &servaddr.sin_addr);
	//		setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &a, sizeof(a));

	connfd = connect(listenfd, (SA *)&servaddr, sizeof(servaddr));
	if (connfd == -1) {
		printf("fail\n");
		exit(0);
	}

	printf("%d\n", listenfd);
	printf("%d\n", connfd);
	tv.tv_sec = 20;
	tv.tv_usec = 0;



	for (;;) {

		FD_ZERO(&rfds);
		FD_SET(0, &rfds);
		FD_SET(listenfd, &rfds);
		select(5, &rfds, NULL, NULL, &tv);
		perror("");

		if(FD_ISSET(0, &rfds)) {
			fgets(buff, 100, stdin);
			write(listenfd, buff, strlen(buff));
		}
		else if(FD_ISSET(connfd, &rfds)) {
			if((n = read(listenfd, buff, MAXLINE)) > 0) {
				printf("\t\t\t %s", buff);
			}
		}
	}

	close(listenfd);
	close(connfd);
	exit(EXIT_FAILURE);

}

