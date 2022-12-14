/**
 * Socket Server Programming
 * Create socket 
 * bind the socket with address and port numbers
 * listen for connections
 * Create client descriptor
 * accept for one client using client descriptor
 * start communication with client
 */

#include	"header.h"
#define MAXBUF 256


void error(char *msg)
{
	perror (msg);
	exit (EXIT_FAILURE);
}

int main (int argc, char *argv[])
{
	if ( argc != 2 ) {
		printf ("<server> <port_no>\n");
		exit (EXIT_FAILURE);
	}
	/* Socket variable */
	int serverfd;
	int clientfd;
	struct sockaddr_in saddr;
	struct sockaddr_in caddr;
	int cli_addr_len = sizeof (caddr);

	serverfd = socket (AF_INET, SOCK_DGRAM, 0); 			/* creating the socket */

	if ( serverfd < 0)
		error ("socket");
	/* Initializing Socket structure */
	saddr.sin_family = AF_INET;								/* address family: AF_INET */
	saddr.sin_port = htons (atoi(argv[1]));					/* port in network byte order */
	saddr.sin_addr.s_addr = INADDR_ANY;						//inet_addr ("0.0.0.0");			/* internet address */


	if ( bind ( serverfd, (const struct sockaddr *)&saddr, sizeof (saddr) ) == -1 )
		error ("bind");


	int ret;
	char buff[MAXBUF];

	while (1) {
		printf ("Waiting for reply...\n");
		bzero (buff, sizeof(buff));
															/* reveving the message from client */
		ret = recvfrom ( serverfd, buff, MAXBUF, 0, (const struct sockaddr *)&caddr, (socklen_t)&cli_addr_len);
		if ( ret == -1 )
			error ("recv");
		if ( ret == 0)
			error ("performed an orderly shutdown");
		printf ("Message is :: %s\n", buff);

		bzero (buff, sizeof(buff));
		printf ("Enter your message::");
		if ( fgets(buff, MAXBUF, stdin) == NULL)
			error ("fgets failed");

		ret = sendto ( serverfd, buff, sizeof(buff), 0, (const struct sockaddr *)&caddr,sizeof(caddr));			/* Sending the message to the client */
		if ( ret == -1)
			error ("send");
	}

	close (serverfd);
	return 0;
}
