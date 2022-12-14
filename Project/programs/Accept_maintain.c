#include	"header.h"

void error (char *msg)
{
	perror (msg);
	exit (EXIT_SUCCESS);
}

extern max_clients;
extern client_socket[30];
extern char online_ip[100][16];
void AcceptTCPConn_read(int sock)
{
	int max_fd = 0;
	int i = 0;
	int j = 0;
	int activity;
	int valread = 0;
	int new_socket = 0;
	struct sockaddr_in cli_addr;
	int cli_addrlen = sizeof(cli_addr);
	while (1) {
		fd_set readfds;
		FD_ZERO(&readfds);
	
		FD_SET(sock, &readfds);
		max_fd = sock;

		for ( i = 0; i < max_clients; i++ ) {
			
			if ( client_socket[i] > 0 )
				
				FD_SET ( client_socket[i] , &readfds);

			if ( client_socket[i] > max_fd)
				
				max_fd = client_socket[i];
		}

		//wait for an activity on one of the sockets , timeout is NULL , so wait indefinitely
		activity = select( max_fd + 1 , &readfds , NULL , NULL , NULL);

		if ((activity < 0) && (errno!=EINTR))
		{
			printf("select error");
		}
		if ( FD_ISSET (sock, &readfds) ) {

			if ( (new_socket = accept(sock, (struct sockaddr *)&cli_addr, (socklen_t *)&cli_addrlen)) < 0)
				error ("accept");

			char *temp_ip = inet_ntoa(cli_addr.sin_addr);
			strcpy(online_ip[new_socket],temp_ip);
			
			//inform user of socket number - used in send and receive commands
			printf("New connection , socket fd is %d , ip is : %s , port : %d \n" , new_socket , inet_ntoa(cli_addr.sin_addr) , ntohs(cli_addr.sin_port));
			//add new socket to array of sockets
			for (i = 0; i < max_clients; i++){
				//if position is empty
				if( client_socket[i] == 0 ){

					client_socket[i] = new_socket;
					printf("Adding to list of sockets as %d\n" , i);
					break;
				}
			}
		}
	
		for ( i = 0; i < max_clients; i++ ) {
			
			int sd = client_socket[i];
			struct message buffer;

			if (FD_ISSET (sd, &readfds)) {
				
				valread = read ( sd, (char *)&buffer, sizeof(buffer));
				if ( valread == 0 ) {
						
					getpeername(sd , (struct sockaddr*)&cli_addr , (socklen_t*)&cli_addrlen);
                    printf("Host disconnected , ip %s , port %d \n" , inet_ntoa(cli_addr.sin_addr) , ntohs(cli_addr.sin_port));

                    //Close the socket and mark as 0 in list for reuse
                    close( sd );
                    client_socket[i] = 0;
                    bzero (online_ip[i],strlen(online_ip[i]));
				
				} else if ( valread > 0) {
						printf ("msg = %s\n",buffer.buff);
						//send_front ( buffer );
				}
			}
		}
	}

}


