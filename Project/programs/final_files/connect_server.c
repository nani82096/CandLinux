#include	"header.h"

#define SERVER_PORT 2096
#define SERVER_IP "172.16.5.224"

struct message {
	char buff[1024];
	char src_ip[16];
};

int server_fd;

int main(void )
{
	int choice;
	connect_server();
	while (1) {
		printf ("Enter 1 to send message");
		scanf ("%d",&choice);
		char msg[1024] = "I am Sending";
		if ( choice == 1){
			C_send_Msg ( msg, "172.16.5.229");
		}
	}
	
}
int connect_server ( void )
{

	int ret;
	struct sockaddr_in server;
    struct sockaddr_in saddr;
	fd_set readfds;
	struct message packet;	
	
	int fd = 0;
    /* Initializing Socket Structure */
    saddr.sin_family = AF_INET;                             /* Adress family: AF_INET */
    saddr.sin_port = htons (SERVER_PORT);                 	/* Port in network byte order */
    saddr.sin_addr.s_addr = inet_addr (SERVER_IP);          /* Internet address */

    server_fd = socket (AF_INET, SOCK_STREAM, 0);            /* Creating the socket */

    if ( server_fd < 0)

        error ("socket");
   
	if ( (fd = connect ( server_fd, (const struct sockaddr*)&saddr, sizeof(saddr)))  ==  -1 )

        error ("connect");
	
	int max = server_fd;
	
	pid_t pid = fork();

	if ( pid == 0) {
		
		while (1){
		
			FD_ZERO (&readfds);

			FD_SET (server_fd, &readfds);

			select (max+1, &readfds, NULL, NULL, NULL );

			if (FD_ISSET (server_fd, &readfds)){
		
				ret = recv (server_fd, &packet, sizeof(packet), 0);

				if ( ret == 0)
					
						error ("recv");

				else if ( ret > 0) {
					printf ("rec msg = %s\n from %s", packet.buff, packet.src_ip);
					//py_receive_msg(packet.buff, packet.src_ip);
				}

			}	
		}
	
	} 	

	return server_fd;
}
