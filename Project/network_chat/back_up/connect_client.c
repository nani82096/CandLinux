#include	"header.h"

#define SERVER_PORT 2096
#define SERVER_IP "172.16.5.224"
#define PORT 2323 
#define TRUE 1

struct message {
	char buff[1024];
	char src_ip[16];
};


char online_ip[100][16];

int client_sock = 0;
int max_clients = 30;
int client_socket[30];

int client_fds[100];

void connect_server ( void );
void rec_read ( void );
void AcceptTCPConn_read(int sock);
void error (char *msg)
{
    perror (msg);
    exit (EXIT_SUCCESS);
}

char *ip[] = {"172.16.5.223","172.16.5.228","172.16.5.229","172.16.5.240"};

int sfd;


int main(void){	


	connect_server ();

	pid_t pid = fork();
	if ( pid == 0 )
		
		rec_read();		/* Calling function to Accept and read the incoming messages */
	
	getstatus(ip, 4);
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
	
	for (i = 0; i < max_clients; i++)
          client_socket[i] = 0;
		
	struct sockaddr_in src_addr;
	src_addr.sin_family = AF_INET;
    src_addr.sin_addr.s_addr = INADDR_ANY;
    src_addr.sin_port = htons( PORT );
	
	if ( bind (sfd, (struct sockaddr *)&src_addr, sizeof(src_addr)) < 0) 

		error ("bind ");


	if ( listen (sfd, 20 ) < 0)
			
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
	//printf("function = %s\n", __func__);

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

			printf ("going to child \n");
	    	memset (&cli_addr, 0, sizeof (cli_addr));
            if ( (new_socket = accept(sock, (struct sockaddr *)&cli_addr, (socklen_t *)&cli_addrlen)) < 0)
                error ("accept");


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
                   //     py_receive_msg ( buffer.buff, buffer.src_ip);
                }
            }
        }
    }
}
