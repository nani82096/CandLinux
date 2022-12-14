
#include	<stdio.h>
#include	<stdlib.h>
#include	<sys/mman.h>
int main()
{
	printf ("%p\n", sbrk(0));
void *p = malloc (12);
	//printf ("%p\n", p);
	p =  mmap (0,200000000, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS,-1, 0);
	printf ("%p\n", sbrk(0));
	if (p == MAP_FAILED) {
        perror("mmap");
        return -1;
	}
}	
