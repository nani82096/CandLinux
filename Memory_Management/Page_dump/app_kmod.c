#include	<stdio.h>
#include	<fcntl.h>
#include	<sys/ioctl.h>
int main ()
{
	int fd;	
	unsigned int pid = getpid();
	fd	=	open ("/dev/myChar",O_RDWR);

	if (fd < 0)
		perror ("Unable to open the device\n");
	else 
		printf ("File opened Successfully %d\n", fd);
	
	ioctl(fd,pid);

	close (fd);

	return 0;	
}
