#include	"header.h"

copy_file(char *old, char *new)
{
	int fd1;
	int fd2;
	struct stat st1;
	
	fd1 = open(old, O_RDONLY);
	if (fd1 == 0){
		printf ("failed\n");
	}
	fstat (fd1, &st1);
	char buff[4096];
	
	fd2 = open(new, O_CREAT | O_WRONLY, st1.st_mode);
	while (read (fd1, buff, 4096) > 0)
		write(fd2, buff, strlen(buff));
	
	return 0;
}
