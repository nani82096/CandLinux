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

	serverfd = socket (AF_INET, SOCK_STREAM, 0); 			/* creating the socket */
	if ( serverfd < 0)
		error ("socket");
	/* Initializing Socket structure */
	saddr.sin_family = AF_INET;								/* address family: AF_INET */
	saddr.sin_port = htons (atoi(argv[1]));					/* port in network byte order */
	saddr.sin_addr.s_addr = INADDR_ANY;						//inet_addr ("0.0.0.0");			/* internet address */


	if ( bind ( serverfd, (const struct sockaddr *)&saddr, sizeof (saddr) ) == -1 )
		error ("bind");

	if ( listen ( serverfd, 5 ) == -1 )
		error ("listen");

	
	clientfd = (int )accept (serverfd, (struct sockaddr *)&caddr, (socklen_t *)&cli_addr_len);
	if ( clientfd < 0) 
		error ("accept");

	char *ip = (char *)inet_ntoa(caddr.sin_addr.s_addr);	/* Getting the Client info */
	unsigned short port = htons(caddr.sin_port);
	printf ("Client ip = %s and Port = %d\n", (char *)ip, port);

	int ret;
	char buff[MAXBUF];

	while (1) {
		printf ("Waiting for reply...\n");
		bzero (buff, sizeof(buff));
															/* reveving the message from client */
		ret = recv ( clientfd, buff, MAXBUF, MSG_WAITFORONE);

		printf("recv returned %d\n" , ret) ;
		if ( ret == -1 )
			error ("recv");
		if ( ret == 0)
			error ("performed an orderly shutdown");
		printf ("Message from %s :: %s\n", ip, buff);

		bzero (buff, sizeof(buff));
		printf ("Enter your message::");
		if ( fgets(buff, MAXBUF, stdin) == NULL)
			error ("fgets failed");

		ret = send ( clientfd, buff, sizeof(buff), 0);			/* Sending the message to the client */
		if ( ret == -1)
			error ("send");
	}

	close (serverfd);
	return 0;
}
