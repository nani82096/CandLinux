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
	struct sockaddr_in claddr;
	int clen = sizeof(claddr);

	/* Initializing Socket structure */
	claddr.sin_family = AF_INET;								/* address family: AF_INET */
	claddr.sin_port = htons (atoi(argv[2]));					/* port in network byte order */
	claddr.sin_addr.s_addr = inet_addr (argv[1]);			/* internet address */
	
	clientfd = socket (AF_INET, SOCK_DGRAM, 0); 			/* creating the socket */

	if ( clientfd < 0)
		error ("socket");

	char buff[MAXBUF];
	int ret;
	
	while (1) {
		printf ("Enter your message::");
		bzero (buff, MAXBUF);
		if ( fgets(buff, MAXBUF, stdin) == NULL)
			error ("fgets failed");

		ret = sendto ( clientfd, buff, sizeof(buff), 0,(const struct sockaddr_in *)&claddr, sizeof(claddr));			/* Sending the message to the server */
		if ( ret == -1)
			error ("send");
	
		bzero (buff, MAXBUF);
		printf ("waiting for reply...\n");
		ret = recvfrom (clientfd, buff, MAXBUF, 0, (const struct sockaddr_in *)&claddr, &clen);			/* reveving the message from the server */
	
		if ( ret == -1 )
			error ("recv");
		if ( ret == 0)
			error ("performed an orderly shutdown");
		
		printf ("The message \n%s\n", buff);
	}
	close (clientfd);
	return 0;
}
