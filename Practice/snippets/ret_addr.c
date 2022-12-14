#include	<stdio.h>

/*
 *
 *
 * First Add Change the Eip Address of fun. i.e Add 20 bytes to the ret address of fun 
 *
 *
 */

void fun(void)
{
	int d[4] = {1};
	d[5] = d[5] + 20;	
}

int main(void)
{
	int a = 10;
	int b = 20;
	fun();
	printf ("A = %d \n", a);
	
	printf ("B = %d \n", b);

	return 0;
}
