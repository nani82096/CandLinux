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
#include    <netdb.h>
struct msg {

	char buff[1024];
	char ip[16];
	int time;

};

int main(int argc, char* argv[])

{

	int sock_fd;
	int len;
	int ret;
	int i;
	int max;
//	char buff[256] = "";	 
	
	struct hostent *server;
	struct sockaddr_in client;

	len = sizeof(client);

	fd_set readset;

    server = gethostbyname(argv[2]);

    if(server == NULL){

        perror("gethostbyaddr failed\n");

        exit(EXIT_FAILURE);

    }

	client.sin_family = AF_INET;
	client.sin_port = htons ( atoi(argv[1]) );
	bcopy( (char*)(server -> h_addr), (char*)&client.sin_addr.s_addr, server -> h_length);

	sock_fd = socket(AF_INET, SOCK_STREAM,  0);
	
	if(sock_fd == -1){

		perror("socket\n");

		exit(EXIT_FAILURE);

	}

/*	if((bind(sock, (struct sockaddr*)&server, sizeof(server))) != 0){

		perror("bind\n");

		exit(EXIT_FAILURE);

	}

	if(listen(sock, 5) != 0){

		perror("listen");

		exit(EXIT_FAILURE);

	}
    
	sock_fd = accept(sock, (struct sockaddr*)&client, &len);

    if(sock_fd == -1){

        perror("accept");

        exit(EXIT_FAILURE);

    }*/

	ret = connect(sock_fd, (struct sockaddr*)&client, sizeof(client));

    if(ret == -1){

        printf("error in connect\n");

        exit(EXIT_FAILURE);

    }


	printf("client ip address : %s\n", (char*)inet_ntoa(client.sin_addr.s_addr));
	
	max = sock_fd;

	struct msg s;

	while(1){

		FD_ZERO(&readset);

		FD_SET(0, &readset);
		FD_SET(sock_fd, &readset);

		select(max + 1, &readset, NULL, NULL, NULL);

		if(FD_ISSET(sock_fd, &readset)){
			 	
			bzero(&s, sizeof(s));
			ret = recv(sock_fd, &s, sizeof(s), 0);
        		
			printf("received msg : %s\n", s.buff);
//			printf("received msg from: %s\n", s.ip);

        	if(ret == 0){

            	printf("connection closed form %s\n", (char*)inet_ntoa(client.sin_addr.s_addr));

            	exit(EXIT_FAILURE);

        	}
	
		}else if(FD_ISSET(0, &readset)){

        //	bzero(buff, 256);
			bzero(&s, sizeof(s));

			if((fgets(s.buff, 256, stdin)) == NULL){

           		printf("fgets failed\n");

           		exit(EXIT_FAILURE);

       		}
		
//			strcpy(s.ip, "172.16.5.224");
	
			if((fgets(s.ip, 16, stdin)) == NULL){

           		printf("fgets failed\n");

           		exit(EXIT_FAILURE);

       		}
			 
			if(s.ip[strlen(s.ip) - 1] == '\n')

                s.ip[strlen(s.ip) - 1] = '\0';

			scanf("%d\n", s.time);

       		ret = send(sock_fd, &s, sizeof(s), 0);

       		if(ret == -1){

           		printf("writing failed\n");

           		exit(EXIT_FAILURE);

    	 	}

	 	 //	bzero(buff, 256);

		}

	}

}

