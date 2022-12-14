#define right(x,n) ( (x & (~(~0 << n)))  << (32 - n ) | (x >> n))

#define right1(x,n) ( (x << 28) | (x >> 4))

#include	<stdio.h>

int main(void)
{
	unsigned int a = 0XCFFFFFAA;
	printf ("a = %08x\n", a);
	a = right(a,4);
	printf ("a = %08x\n", a);
	a = right1(a,4);
	printf ("a = %08x\n", a);
	return 0;
}
