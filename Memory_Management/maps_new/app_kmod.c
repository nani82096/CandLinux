#include	<stdio.h>
#include	<fcntl.h>
#include	<sys/ioctl.h>
int main ()
{
	int fd;
	unsigned int x;
	fd	=	open ("/dev/myChar",O_RDWR);
	ioctl(fd,x);
	printf("PID == %d\n",getpid());
	getchar();
	if (fd < 0)
		perror ("Unable to open the device\n");
	else 
		printf ("File opened Successfully %d\n", fd);

	close (fd);

	return 0;	
}
