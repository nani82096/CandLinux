#include <stdio.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/ioctl.h>
void asdf(void){

	printf ("Hello World!\n");
	return 0;
}

int main ()
{
	int fd;

	fd	=	open ("/dev/device",O_RDWR | O_CREAT);

	if (fd < 0)
		perror ("Unable to open the device\n");
	else 
		printf ("File opened Successfully %d\n", fd);

	if (!ioctl(fd , getpid() , 8  )){
		printf ("Ioctl success\n");
	} else{
		perror("ioctl");
		printf ("Ioctl Failed\n");
	}
	//close (fd);

	system("rm /dev/device");

	return 0;	
}
