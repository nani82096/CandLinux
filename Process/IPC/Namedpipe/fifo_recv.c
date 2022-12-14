#include	<stdio.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/stat.h>
#include	<sys/types.h>


int main(void)
{
	int fd;
	int status;
	char rdbuff[50] = "";
	fd = open("./myfifo",O_RDONLY); 	/* Statically created myfifo using command mkfifo myfifo in command prompt */	
	close (fd);
	getchar();
	while (1) {
		memset(rdbuff,0,50);
		printf ("\nWaiting For message...\n");
		status = read (fd, rdbuff, sizeof(rdbuff));
	
		if ( !strcmp (rdbuff, "quit"))
			exit (EXIT_SUCCESS);
		if (status == -1) {
				printf ("Read Failed\n");
				return 0;
		}
		printf ("Message Received Successfully\n");
		printf ("Message  %s \n\n", rdbuff);
	}

	return 0;
}
