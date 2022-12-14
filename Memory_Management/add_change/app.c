#include	<stdio.h>
#include	<fcntl.h>
#include	<sys/ioctl.h>

void asdf(void)
{
	printf ("No in Function1\n");
	return ;
}
void qwer(void)
{
	printf ("No in Function2\n");
	return ;
}

const int var1 = 10;
int main ()
{
	printf("asdf address = %d\n",&asdf);
	printf("qwer  address = %d\n",&qwer);
	int fd;	
	unsigned int pid = getpid();
	fd	=	open ("/dev/myChar",O_RDWR | O_CREAT);

	if (fd < 0)
		perror ("Unable to open the device\n");
	else 
		printf ("File opened Successfully %d\n", fd);

	printf ("In Main Function\n");	
	if (!ioctl(fd,&asdf,&qwer))
		printf ("Ioctl success\n");
	else 
		perror ("Ioctl ");
	asdf();
	printf("asdf address = %d\n",&asdf);
	printf("qwer  address = %d\n",&qwer);
	close (fd);

	return 0;	
}
