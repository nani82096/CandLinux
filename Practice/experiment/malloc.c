#include	<stdio.h>

#include	<stdlib.h>

int main(void)

{
	int* p = malloc(12);
	
	int* q = malloc(12);
	*p = 1;
	*(p + 1) = 2;
	*(p + 2) = 3;
	*(p + 3) = 9;

	*q = 4;
	*(q + 1) = 5;
	*(q + 2) = 6;
	*(q + 3) = 7;

	printf("address of p : %p\n", p);

	
	printf("first : %d\t%d\t%d\t%d\n", *p,*(p + 1), *(p + 2), *(p + 3));
//	printf("first : %p\t%p\t%p\n", (p + 1), (p + 2), (p + 3));

	printf("address of q : %p\n", q);

	printf("Second : %d\t%d\t%d\t%d\n", *q,*(q + 1), *(q + 2), * (q + 3));

//	printf("first : %p\t%p\t%p\n", (q + 1), (q + 2), (q + 3));

//	free(q);

}
