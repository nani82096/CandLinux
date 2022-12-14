#include	<stdio.h>

void main(void)

{


	long int a = -1;
	unsigned long int b = 1;
	if( a < b)

		printf( " a is less than b and b = %x",b);
	else
	
		printf(" a is big than b and   a = %x",a);

	printf(" \n0x%08x \n", 1 | -6);

}
