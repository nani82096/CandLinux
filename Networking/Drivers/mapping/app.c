#include 	<stdio.h>
#include 	<fcntl.h>
#include 	<sys/ioctl.h>
#include 	<string.h>
#include 	<stdlib.h>

int main( void )
{
	int fd;
	int pid;
	int status;
	
	fd = open("/dev/myChar", O_RDWR);
	if (fd < 0) {
		perror("Unable to open the device ");
		exit(1);
	} else {
		printf("File opened Sucessfully %d\n", fd);
	}

	pid = getpid();
	status = ioctl( fd, pid );
	if (status < 0)
	{
		perror("ioctl failed");
		exit (1);
	}
	
	
	return 0;
}

