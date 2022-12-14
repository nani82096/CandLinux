#include	"header.h"

#define SERVER_PORT 2096
#define SERVER_IP "172.16.5.224"
#define PORT 2323 
#define TRUE 1

char online_ip[100][16] = { };

int client_sock = 0;
int sfd;
int max_clients = 30;
int client_socket[30];

int client_fds[100];

void C_Sched_Msg(char *);
char *ip[16] = {"172.16.5.238", "172.16.5.240","172.16.5.229","172.16.5.228"};

void error (char *msg)
{
    perror (msg);
    exit (EXIT_SUCCESS);
}

void* reading(void* p)
{

	rec_read();

}

int main(void){	
	int i = 0;
	pthread_t th_id;

	for ( i = 0; i < 100; i++)
		strcpy(online_ip[i], "");

	connect_server ();

	getstatus(ip, 4);

	int j;
	
	for(j = 0; j < 20; j++ )

		printf("fd : %d\t ip : %s\n", j , online_ip[j]);

	pthread_create(&th_id, NULL, reading, NULL);
	
	while (1){	
		
		int a;
		printf ("enter 1 to send::");	
		scanf ("%d",&a);
		if ( a == 1) {
			
			C_send_Msg("I am sending", "172.16.5.229");
	
		}
	}

}

void connect_server ( void )
{
    struct sockaddr_in saddr;
	int ret;
    
	/* Initializing Socket Structure */
    
	saddr.sin_family = AF_INET;                             /* Adress family: AF_INET */
    saddr.sin_port = htons (SERVER_PORT);                 	/* Port in network byte order */
    saddr.sin_addr.s_addr = inet_addr (SERVER_IP);          /* Internet address */

    client_sock = socket (AF_INET, SOCK_STREAM, 0);            /* Creating the socket */

    if ( client_sock < 0)

       perror ("socket");

    if ( (ret = connect ( client_sock, (const struct sockaddr *)&saddr, sizeof(saddr)))  ==  -1 )

        error ("connect");

	printf("connected with server....\n");

	strcpy(online_ip[client_sock], SERVER_IP);

	client_socket[0] = client_sock;
	
	printf ("Connected To server with fd = %d\n", client_sock );
	return ;	
}

void rec_read ( void )
{
	int max_sd;
	int src_addrlen, cli_addrlen, new_socket, activity, i, j, valread, sd;

	fd_set readfds;
    sfd = socket (AF_INET, SOCK_STREAM, 0);            /* Creating the socket */

	struct sockaddr_in cli_addr;
	
	struct sockaddr_in src_addr;
	src_addr.sin_family = AF_INET;
    src_addr.sin_addr.s_addr = INADDR_ANY;
    src_addr.sin_port = htons( PORT );
	
	if ( bind (sfd, (struct sockaddr *)&src_addr, sizeof(src_addr)) < 0) 

		error ("bind ");

	if ( listen (sfd, 30 ) < 0)
			
		error ("listen");

	cli_addrlen = sizeof(cli_addr);
	
	AcceptTCPConn_read ( sfd );
}

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
		//client_socket[0] = sock;			// new changes

        for ( i = 0; i < max_clients; i++ ) {

/*			if(client_socket[i] == 0)

				client_socket[i] = sock;*/

            if ( client_socket[i] > 0 )

                FD_SET ( client_socket[i] , &readfds);
			
			if ( client_socket[i] > max_fd)
			
                max_fd = client_socket[i];
        }

        //wait for an activity on one of the sockets , timeout is NULL , so wait indefinitely
        activity = select( max_fd + 1 , &readfds , NULL , NULL , NULL);

        if ((activity < 0) && (errno!=EINTR)) {
            printf("select error");
        }
        if ( FD_ISSET (sock, &readfds) ) { 	

	    	memset (&cli_addr, 0, sizeof (cli_addr));

            if ( (new_socket = accept(sock, (struct sockaddr *)&cli_addr, (socklen_t *)&cli_addrlen)) < 0)		
           
			     error ("accept");
			
			strcpy(online_ip[new_socket], (char*)inet_ntoa(cli_addr.sin_addr));
			perror ( "strcpy");
			printf(" Accept : %s\n", online_ip[new_socket]);

            //inform user of socket number - used in send and receive commands
            printf("New connection , socket fd is %d , ip is : %s , port : %d \n" , new_socket , inet_ntoa(cli_addr.sin_addr) , ntohs(cli_addr.sin_port));
        	for(i = 0; i < 20; i++) {

				if(online_ip[i]) 
			
					printf("ip : %s\t fd : %d\n", online_ip[i], i) ;

			} 
	
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

		int sd;

        for ( i = 0; i < max_clients; i++ ) {

/*			FD_ZERO(&readfds);

			for(j = 0; j < max_clients; j++){

             	sd = client_socket[j];
				
				if(sd > 0)

					FD_SET(sd, &readfds);

				if(sd > max_fd)

					max_fd = sd;

			}

			select(max_fd +1, &readfds, NULL, NULL, NULL);
*/
			sd = client_socket[i];

            struct message buffer;

            if (FD_ISSET (sd, &readfds)) {

                valread = read ( sd, (char *)&buffer, sizeof(buffer));

                if (  buffer.flag == 3 ) {

                    getpeername(sd , (struct sockaddr*)&cli_addr , (socklen_t*)&cli_addrlen);
            
			        printf("Host disconnected , ip %s , port %d \n" , inet_ntoa(cli_addr.sin_addr) , ntohs(cli_addr.sin_port));

                    //Close the socket and mark as 0 in list for reuse
                    bzero (online_ip[sd],strlen(online_ip[sd]));
                  
					close( sd );
                    
					client_socket[i] = 0;

					FD_CLR (sd, &readfds);

					for(j = 0; j < 20; j++)

						printf("%d\t%s\n", j, online_ip[j]);

				} else if ( valread > 0) {
            
		            printf ("msg = %s\n",buffer.buff);
                   //     py_receive_msg ( buffer.buff, buffer.src_ip);
                }
            }
        }
    }
}
