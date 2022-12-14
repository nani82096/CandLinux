#include	<stdio.h>

void main(void)

{


	int a = 5;
	printf("\n%d  %d  %d  %d  %d\n\n", ++a, a, a++, ++a, a++);

	volatile b = 5;	
	printf("\n%d  %d  %d  %d  %d\n\n", ++b, b, b++, ++b, b++);
	
	int c = 2;
	int d = (2,3);
	printf(" \nc=  %d d= %d\n", c, d);
}
