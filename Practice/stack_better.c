
#include	<stdio.h>
int  main(void)
{
short	int a =12;
short	int b = 13;
short	int c = 14;

	*( &c+1 ) = 99;

	printf ( "A = %d\n",a);
	printf ( "B = %d\n",b);
	printf ( "C = %d\n",c);
	return 0;
}
