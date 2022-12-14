#include 	<stdio.h>
#include 	<fcntl.h>
#include 	<sys/ioctl.h>
#include 	<string.h>
#include 	<stdlib.h>
#define MB ( 40 * 1024)

int main( void )
{
	int fd;
	int pid;
	int status;
	int i;
	unsigned char *ptr = NULL;

	printf ("PID = %d \n", getpid());
	fd = open("/dev/mydev", O_RDWR);
	if (fd < 0) {
		perror("Unable to open the device ");
		exit(1);
	} else {
		printf("File opened Sucessfully %d\n", fd);
	}
	pid = getpid();
	ptr = malloc(MB);
	printf ("Value of ptr = 0x%08x \n", ptr);
	status = ioctl( fd, pid,(int)ptr );
	if (status < 0)
	{
		perror("ioctl failed");
		exit (1);
	}
	getchar();
	for (i = 0; i<MB; i++)
	{
		*(ptr+i) = 0xFF;
	}
	getchar();
	status = ioctl( fd, pid,(int)ptr );
	if (status < 0)
	{
		perror("ioctl failed");
		exit (1);
	}
	free (ptr);
	getchar();
	
	status = ioctl( fd, pid,(int)ptr );
	if (status < 0)
	{
		perror("ioctl failed");
		exit (1);
	}
	
	
	return 0;
}

