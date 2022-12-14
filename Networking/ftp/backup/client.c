/*
 *
 *
 */

#include	"header.h"
#define MAXBUF 256
#define PORT 1234
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
	saddr.sin_family = AF_INET;		/* address family: AF_INET */
	saddr.sin_port = htons (PORT);	/* port in network byte order */
	saddr.sin_addr.s_addr = inet_addr (argv[2]);/* internet address */

	clientfd = socket (AF_INET, SOCK_STREAM, 0);/* creating the socket */

	if ( clientfd < 0)
		error ("socket");

	if (connect (clientfd,(const struct sockaddr *)&saddr, 
										sizeof(saddr))  ==  -1 )
		error ("connect");

	int ret;
	int fd;
	struct stat st1;

	fd = open(argv[1], O_RDONLY);
	if (fd == 0)
		error("open");
	fstat (fd,&st1);

	
	char buff[4096];
	/* Sending file name */
	
	send (clientfd, argv[1], strlen(argv[1])+1, 0);
	
	send (clientfd, &st1.st_mode, sizeof(st1.st_mode),0);
	printf ("mode = %d\n", st1.st_mode);	
	send (clientfd, &st1.st_size, sizeof(st1.st_size),0);

	int size1 = st1.st_size / 4096;
	int size2 = st1.st_size % 4096;


	while( size1 ){
		if ( read(fd, buff, 4096) > 0 ){
			ret = write ( clientfd, buff, 4096 );			
			if ( ret == -1)
				error ("send");
			memset(buff, 0, 4096);
		}/*else{
			ret = write ( clientfd, buff, strlen(buff)+1);			
		}*/
		size1--;
	}

	if ( read(fd, buff, size2) > 0 ){
		ret = write ( clientfd, buff, size2 );			
		if ( ret == -1)
			error ("send");
		memset(buff, 0, size2);
	}/*else{
		ret = write ( clientfd, buff, strlen(buff)+1);			
	}*/
	
	close(fd);
	close (clientfd);
	return 0;
}
