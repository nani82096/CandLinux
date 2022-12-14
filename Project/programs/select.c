#include 	<stdio.h>
#include    <stdio.h>
#include    <stdlib.h>
#include    <sys/types.h>
#include    <sys/socket.h>
#include    <unistd.h>
#include    <netinet/in.h>
#include    <linux/libc-compat.h>
#include    <string.h>
#include 	<sys/select.h>
#include 	<sys/time.h>

void error (char *msg)
{
	perror (msg);
	exit ( EXIT_FAILURE );
}

int main(int argc, char* argv[])
{
	int accept_fd;
	int sock;
	int len;
	int ret;
	int i;
	int max;
	char buff[256] = "";	 

	struct sockaddr_in server;
	struct sockaddr_in client;

	len = sizeof(client);

	fd_set readset;

	server.sin_family = AF_INET;
	server.sin_port = htons ( atoi(argv[1]) );
	server.sin_addr.s_addr = INADDR_ANY;

	sock = socket(AF_INET, SOCK_STREAM,  0);
	
	if(sock == -1){

		error("socket\n");
	}

	if((bind(sock, (struct sockaddr*)&server, sizeof(server))) != 0){

		error("bind\n");
	}

	if(listen(sock, 5) != 0){

		error("listen");
	}

	accept_fd = accept(sock, (struct sockaddr*)&client, &len);

    if(accept_fd == -1){

		error("accept");
    }

	printf("client ip address : %s\n", (char*)inet_ntoa(client.sin_addr.s_addr));
	
	max = accept_fd;

	while(1){

		FD_ZERO(&readset);

		FD_SET(0, &readset);
		FD_SET(accept_fd, &readset);

		if ( select(max + 1, &readset, NULL, NULL, NULL) == -1)
			error ("select");

		if(FD_ISSET(accept_fd, &readset)){
			 	
			ret = recv(accept_fd, buff, 256, 0);

        	if(ret == 0){

            	printf("connection closed form %s\n", (char*)inet_ntoa(client.sin_addr.s_addr));
            	exit(EXIT_FAILURE);
        	}
	
			printf("received msg : %s\n", buff);
	
		}else if(FD_ISSET(0, &readset)){

        	bzero(buff, 256);

			if((fgets(buff, 256, stdin)) == NULL){

           		printf("fgets failed\n");
           		exit(EXIT_FAILURE);
       		}

       		ret = send(accept_fd, buff, strlen(buff) + 1, 0);

       		if(ret == -1){

           		printf("writing failed\n");
           		exit(EXIT_FAILURE);
    	 	}

	 	 	bzero(buff, 256);
		}
	}
}

