#include	"header.h"
int main (void)
{
	int fd;
	int i = 0;
	char *ptr;
		/* Open, get size, map */

	if  ( (fd = shm_open ("/shm", O_RDWR | O_CREAT, 0777) ) == -1) {
		
		perror ("shm_open");
		exit (EXIT_FAILURE);
	}
	printf ("fd : %d\n",fd);

	if((ftruncate(fd, (size_t)4096)) == -1){                                                                                  
        perror("ftrucate failed\n");                                                      
        exit(EXIT_FAILURE);
	}
	if ((ptr = mmap(NULL, (size_t)4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, (off_t)0)) == MAP_FAILED)
		perror ("mmap");
	
	
	for (i = 0 ; i < 100 ; i++){
		printf ("Done writing %d...\n", i); 
		*ptr = i;
		sleep(1);
	}
	
	
	if ( (munmap(ptr, (size_t) 4096)) == -1) {
		perror ("munmap");
	}
	if (close (fd) == -1 )
		perror ("close");
	return 0;
}
