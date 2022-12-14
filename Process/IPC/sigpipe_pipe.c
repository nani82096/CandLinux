#include	<sys/wait.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>

void sighand(int signum)
{
	printf ("Broken Pipe %d\n", signum);
}

int main ( int argc, int *argv[] )
{
	int pipefd[2];
	signal (SIGPIPE, sighand);
	pid_t cpid;
	int status;
	char buf[100];

	if (argc != 2) {
		fprintf (stderr, "Usage: %s <string>\n", argv[0]);
		exit (EXIT_FAILURE);
	}
	status = pipe (pipefd);
	if ( status == -1) {
		perror ("pipe");
		exit (EXIT_FAILURE);
	}
	close (pipefd[0]);	/* Close unused read end */
	write (pipefd[1], argv[1], strlen (argv[1]));
	close (pipefd[1]);	/* Reader will see EOF */
	return 0;
}

