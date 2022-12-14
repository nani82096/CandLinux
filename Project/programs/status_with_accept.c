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


//#define	PORT 2069
#define MAX  4
int fd[MAX];
int fd_online[MAX];

int j  = 0;
char* ip[] = {"172.16.5.228","172.16.5.227", "172.16.5.238", "172.16.5.240", "172.16.5.224" };

struct hostent *srv;
struct sockaddr_in client;

void getstatus(char* ip[])

{
	int i;
	int ret;
	
	j = 0;
	
	client.sin_family = AF_INET;
	client.sin_port = htons (PORT);

	for(i = 0; i < MAX; i++){
	
	fd[i] = socket(AF_INET, SOCK_STREAM,  0);
	
	if(fd[i] == -1){

		perror("socket\n");

		exit(EXIT_FAILURE);

	}
	srv = gethostbyname(ip[i]);

    if(srv == NULL){

        perror("gethostbyaddr failed\n");

        exit(EXIT_FAILURE);

    }

	bcopy( (char*)(srv -> h_addr), (char*)&client.sin_addr.s_addr, srv -> h_length);

	ret = connect(fd[i], (struct sockaddr*)&client, sizeof(client));

    if(ret == -1){

        printf("%s is in [--- OFF-LINE ---] \n",  (char*)inet_ntoa(client.sin_addr.s_addr));

		close(fd[i]);

    }else{

		printf("%s is in [--- ON-LINE ---] with fd : %d\n",  (char*)inet_ntoa(client.sin_addr.s_addr), fd[i]);

		fd_online[j++] = fd[i];

	}
		
	}
}

int main(void)

{

	int len;
	int ret;
	int i;
	int k;
	int sd = 0;
	int max = 5;
	char buff[256] = "";
	char new_fd[13] = "";	 
	struct hostent *server;
	struct sockaddr_in main;
	struct sockaddr_in cli;

	int sock;

	len = sizeof(client);
	fd_set readset;


	main.sin_family = AF_INET;
	main.sin_port = htons ( PORT );
	main.sin_addr.s_addr = INADDR_ANY;	

	sock = socket(AF_INET, SOCK_STREAM,  0);

    if(sock == -1){

        perror("socket\n");

        exit(EXIT_FAILURE);

    }

	if((bind(sock, (struct sockaddr*)&main, sizeof(main))) != 0){

        perror("bind\n");

        exit(EXIT_FAILURE);

    }

	if(listen(sock, 5) != 0){

		perror("listen:");

		exit(EXIT_FAILURE);

	}

	getstatus(ip);					// calling function to get status of all contacts


	while(1){

		FD_ZERO(&readset);

		FD_SET(sock, &readset);
		
		FD_SET(0, &readset);

		max = sock;

		for( i = 0; i < j; i++){
		
			sd = fd_online[i];

			if(sd > 0)

				FD_SET(fd_online[i],&readset);

			if(sd > max)
		
				max = sd;

		}

		select(max + 1, &readset, NULL, NULL, NULL);

		if(FD_ISSET(sock, &readset)){			 	
	
			printf("waiting for connection...\n");

			fd_online[j] = accept(sock, (struct sockaddr*)&cli, &len);

			if(fd_online[j] == -1){

        			perror("accept");

        			exit(EXIT_FAILURE);

			}else{
		
				printf("connection success with fd: %d and ip : %s\n", fd_online[j],  (char*)inet_ntoa(cli.sin_addr.s_addr));

				j++;
//				getstatus(ip);

			}
		}
		
		for( i = 0; i < MAX; i++){

			if(i){

				FD_ZERO(&readset);
				FD_SET(0, &readset);

				for(k = 0; k < MAX; k++){

					if(fd_online[k] > 0){

						FD_SET(fd_online[k], &readset);

					}
					
					 if(fd_online[k] > max)
						
						max = fd_online[k];

				}
			
				select(max + 1, &readset, NULL, NULL, NULL);

			}

				sd = fd_online[i];

				if(FD_ISSET(sd, &readset)){

					ret = recv(sd, buff, 256, 0);

					if(ret == 0){
			
						printf("connection closed from th fd: %d\n", sd);

						j--;

						FD_CLR(sd, &readset);

						close(sd);
			
					}else if(ret > 0){

						printf("\n\t\t\t\treceived msg from fd: %d id :%s\n", sd, buff);

						bzero(buff, 256);

					}

				}else if(FD_ISSET(0, &readset)){

            	   if((fgets(buff, 256, stdin)) == NULL){

                	   printf("fgets failed\n");

                  	   exit(EXIT_FAILURE);

                	}

                	ret = send(sd, buff, strlen(buff) + 1, 0);

               		if(ret == -1){

                    	perror("send failed\n");

                    	exit(EXIT_FAILURE);

                	}
                   
					bzero(buff, 256);

				}
		}
	}
	return 0;
}
