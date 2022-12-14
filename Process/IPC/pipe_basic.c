#include	<sys/wait.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<semaphore.h>
#include	<unistd.h>
#include	<string.h>



int main ( void )
{
	int pipefd[2];
	pid_t cpid;
	int status;
	char input[100]="";
	char buf[100]="";


	
	status = pipe (pipefd); /* Opening the Buffer */
	if ( status == -1) {
		perror ("pipe");
		exit (EXIT_FAILURE);
	}

	cpid = fork();

	if ( cpid == -1) {
		perror ("fork");
		exit (EXIT_FAILURE);
	}

	if ( cpid == 0) {		/* Child reads from pipe */
		close (pipefd[1]);	/* Close unused wirte end */
		
		read(pipefd[0], buf, sizeof(buf) );
		
		wait(NULL);
		printf ("Reading from pipe to buffer\n");
		fprintf (stdout ,"Buffer In Child:: %s\n", buf );

		close (pipefd[0]);

		_exit (EXIT_SUCCESS);

	} else {				/* Parent writes argv[1] to pipe */

		close (pipefd[0]);	/* Close unused read end */

		printf ("In Parent Enter The Buffer::");
		if ( fgets (input, sizeof(input), stdin ) == NULL ) {
			printf ("fgets failed\n");
			exit (EXIT_FAILURE);
		}
		 
//		if ( input[strlen(input)-1] == '\n')
//			input[strlen(input)-1] = '\0';
		printf ("Writing into the Pipe from Parent\n");
		write (pipefd[1], input, sizeof(input));
		close (pipefd[1]);	/* Reader will see EOF */
		wait (NULL);		/* Wait for child */
		exit (EXIT_SUCCESS);
	}
	return 0;
}

