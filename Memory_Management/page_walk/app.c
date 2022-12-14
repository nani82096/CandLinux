#include	<stdio.h>
#include	<fcntl.h>
#include	<sys/ioctl.h>

int var1 = 10;
int main ()
{
	printf("var1 before changing = %d\n",var1);
	int fd;	
	unsigned int pid = getpid();
	fd	=	open ("/dev/myChar",O_RDWR | O_CREAT);

	if (fd < 0)
		perror ("Unable to open the device\n");
	else 
		printf ("File opened Successfully %d\n", fd);
	
	ioctl(fd,pid,&var1);
	printf("var1 after changing = %d\n",var1);
	close (fd);

	return 0;	
}
