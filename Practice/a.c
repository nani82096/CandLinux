#include	<stdio.h>
enum a{x = 12, y, z, w,p};
int  bb[4] = {1.2,4.5,2.5,'a'};

int add(int a , int b)
{
	
	int c ;
	c = a + b;
	return c;
}


int main(void)
{
	printf ("enum x = %d\n", x);
	printf ("enum y = %d\n", y);
	printf ("enum z = %d\n", z);
	printf ("enum w = %d\n", w);
	printf ("bb[2] = %d\n",bb[2]);
	int a = 10;
	int b = 20;
	int c = add(a , b);
	printf (" sum = %d", c);
	return 0 ;
}

