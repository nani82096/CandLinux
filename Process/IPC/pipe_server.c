#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>

int main ( void )
{

	int fd1[2];
	char wrbuff[50];
	char rdbuff[50];

	pipe ( fd1 );

	while ( 1 ) {

		printf ("Enter your message: ");
		if ( NULL == fgets ( wrbuff, 50, stdin ))
			exit (EXIT_FAILURE);
		if ( wrbuff[strlen(wrbuff)-1] == '\n' )
			wrbuff[strlen(wrbuff)-1] = '\0';
	
		if ( write ( fd1[1], wrbuff, strlen ( wrbuff ) ) ) {
			printf ("String Written\n");
			read ( fd1[0], rdbuff, strlen ( rdbuff  ) );
			fprintf (stdout, "Message read: %s\n", rdbuff );

		}

		if ( strcmp ( wrbuff, "quit" ) == 0 ) 
			return 0;

	}

	return 0;

}
