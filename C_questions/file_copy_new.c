#include	<stdio.h>
#include	<string.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	<sys/types.h>
#include	<sys/stat.h>

int main(int argc, char *argv[])
{
	int fd1;
	int fd2;
	int ret = 0;
	struct stat st1;
	
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == 0){
		printf ("failed\n");
	}
	fstat (fd1, &st1);
	char buff[4096] ;

	fd2 = open(argv[2], O_CREAT | O_WRONLY,st1.st_mode);
	
	int size1 = st1.st_size / 4096;
	int size2 = st1.st_size % 4096;
	
	while ( size1){
		
		if ((ret = read (fd1, buff, 4096)) < 0)
			printf ("failed for read\n");
		ret = write(fd2, buff, 4096);
		size1--;
		memset(buff, 0, 4096);
	}
	if ((ret = read (fd1, buff, size2)) > 0)
		printf ("failed for read\n");
	ret = write(fd2, buff, size2);
	
	
	return 0;
}
