#include	"header.h"

int main (void)
{
	int i;
	int fd;
	volatile char const *ptr;


	/* Open, get size, map */

	fd = shm_open ("/shm", O_RDONLY , 0777);
	if ( fd == -1)
		perror ("shm_open");
	
	if((ptr = mmap(NULL, (size_t)4096, PROT_READ , MAP_SHARED, fd, (off_t)0)) == MAP_FAILED)
		perror("mmap");
	
	for ( ; ;){
		if ( *ptr % 4 == 0)
			printf ("Read %d...\n", *ptr);
	}

/*	if ( (munmap(ptr, (size_t) 4096)) == -1) {                                   
        perror ("unmap");                                                       
    }  */
	shm_unlink("/shm");

	return 0;
}
