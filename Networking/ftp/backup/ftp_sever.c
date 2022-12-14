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

	/* creating the socket */
	serverfd = socket (AF_INET, SOCK_STREAM, 0); 			
	if ( serverfd < 0)
		error ("socket");
	/* Initializing Socket structure */
	saddr.sin_family = AF_INET;		/* address family: AF_INET */
	saddr.sin_port = htons (atoi(argv[1]));	/* port in network byte order */
	saddr.sin_addr.s_addr = INADDR_ANY;	//inet_addr ("0.0.0.0");	


	if ( bind ( serverfd, (const struct sockaddr *)&saddr, \
									sizeof (saddr) ) == -1 )
		error ("bind");

	if ( listen ( serverfd, 5 ) == -1 )
		error ("listen");

	
	clientfd = (int )accept (serverfd, (struct sockaddr *)&caddr,  \
											(socklen_t *)&cli_addr_len);
	if ( clientfd < 0) 
		error ("accept");


	int ret;
	char file_name[30];
	int fd;
	
	ret = read(clientfd,file_name, sizeof(file_name));
	if (ret <= 0)
		error("read");
	int mode;
	ret = read(clientfd,&mode, sizeof(mode));
	if (ret <= 0)
		error("read");
 	int size;
	ret = read(clientfd,&size, sizeof(size));
	if (ret <= 0)
		error("read");
	char buff[4096];
	fd = open(file_name, O_CREAT | O_WRONLY, mode);

	int size1 = size / 4096;
	int size2 = size % 4096;
	
	while ( size1 ){
		ret = recv ( clientfd, buff, 4096, MSG_WAITALL);
		if ( ret <=  0 )
			error ("recv");

		ret = write ( fd, buff, 4096 );			
		if ( ret <= 0 )
			error ("write");
		memset(buff, 0, 4096);		
		size1--;
	}
	ret = recv ( clientfd, buff, size2, MSG_WAITALL );
	if ( ret <= 0 )
		error ("recv");

	ret = write ( fd, buff, size2 );			
	if ( ret  <= 0)
		error ("write");

	close (serverfd);
	close (fd);
	return 0;
}
