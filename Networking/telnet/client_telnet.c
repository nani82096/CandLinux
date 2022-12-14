/****************************************************************************
 *                                                                          *
 * @file client_telnet.c                                                    *
 *                                                                          *
 * @brief File contains source code for  telnet remote login client         *
 * @detail                                                                  *
 * This file establishes remote login by sending request to the deamon      *
 * server which is running in the original host.                            *
 *                                                                          *
 ****************************************************************************/


#include    "header.h"

int main(int argc, char **argv)
{
	int cfd;
	int limit = 1;
	char *arg[SIZE];
	socklen_t addrlen;
	char buf[MAX] = {0};
	char *passwd = NULL;
	char *usr = (char *)malloc(sizeof(char)*127);
	char buffer[MAX] = {0};
	struct sockaddr_in server_addr;

	if (argc != 3) {
		printf("Usage : %s <IPaddress> <Portnumber>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(atoi(argv[2]));
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);

	addrlen = sizeof(server_addr);	

	if((cfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		handle_error("socket");

	if(connect(cfd, (const struct sockaddr *) &server_addr, addrlen) == -1)
		handle_error("connect");

	//    while (1) {
	bzero(usr,127);
	printf ("Username to login:");
	if (fgets(usr, 127, stdin) != NULL){
		if( usr[strlen(usr)-1] == '\n')
			usr[strlen(usr)-1] = '\0';
	}
	if ( write(cfd,usr,strlen(usr)+1) == ERROR)
		handle_error("write");
	bzero(usr,127);
	if ( read(cfd,usr,127) == ERROR)
		handle_error("read");
	while (limit ++ <= 3) {

		// printf("enter the password\n");
		/*if (fgets(buf, MAX, stdin) == NULL)
		  handle_error("fgets");
		  buf[strlen(buf)-1] = '\0';*/

		passwd = password();


		/*	//Message diagnosis
			printf ("password entered :%s\n",passwd);
			printf ("the lenght = %d\n", strlen(passwd));
			printf (" new pass encrypted ::: %s\n", buff);
			printf ("The length = %d\n", strlen(buff)); 
		 */        
		if(write(cfd, passwd, strlen(passwd)+1) == -1)
			handle_error("write");

		if(read(cfd, buffer, MAX) == -1) 
			handle_error("read");

		if (!strstr(buffer, "failed"))
			break;
		else {
			puts(buffer);
			bzero(buf, MAX);
			continue;
		}
	}

	if (limit > 3) {
		close(cfd);
		exit(EXIT_FAILURE);
	}

	puts(buffer);

	while (1) {

		printf("enter command to execute : ");
		if (fgets(buf, MAX, stdin) == NULL)
			handle_error("fgets");

		buf[strlen(buf)-1] = '\0';

		if (!strcmp(buf, "quit") || !strcmp(buf, "exit")) {
			close(cfd);
			exit(EXIT_SUCCESS);
		}
		
		if (write(cfd, buf, MAX) == -1)
			handle_error("write");
		bzero(buffer, strlen(buffer));
		if (read(cfd, buffer, MAXLIMIT) == -1) 
			handle_error("write");
		puts(buffer);

		bzero(buf, sizeof(buf));
	}

	close(cfd);

	return 0;
}
