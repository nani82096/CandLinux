/*
 *
 *
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
	if ( argc != 3 ) {
		printf ("<client> <server_ip> <port_no>\n");
		exit (EXIT_FAILURE);
	}
	/* Socket variable */
	int clientfd;
	struct sockaddr_in saddr;

	/* Initializing Socket structure */
	saddr.sin_family = AF_INET;								/* address family: AF_INET */
	saddr.sin_port = htons (atoi(argv[2]));					/* port in network byte order */
	saddr.sin_addr.s_addr = inet_addr (argv[1]);			/* internet address */

	clientfd = socket (AF_INET, SOCK_STREAM, 0); 			/* creating the socket */

	if ( clientfd < 0)
		error ("socket");

	if ( connect ( clientfd, (const struct sockaddr *)&saddr, sizeof(saddr))  ==  -1 )
		error ("connect");

	char buff[MAXBUF];
	int ret;
	
	while (1) {
		printf ("Enter your message::");
		bzero (buff, MAXBUF);
		if ( fgets(buff, MAXBUF, stdin) == NULL)
			error ("fgets failed");

		ret = send ( clientfd, buff, sizeof(buff), 0);			/* Sending the message to the server */
		if ( ret == -1)
			error ("send");
	
		bzero (buff, MAXBUF);
		printf ("waiting for reply...\n");
		ret = recv (clientfd, buff, MAXBUF, 0);			/* reveving the message from the server */
	
		if ( ret == -1 )
			error ("recv");
		if ( ret == 0)
			error ("performed an orderly shutdown");
		
		printf ("The message \n%s\n", buff);
	}
	close (clientfd);
	return 0;
}
