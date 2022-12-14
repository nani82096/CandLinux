#include	<stdio.h>
#define bitt(n)		(((n & ~(~0 << 8)) << 8) | (n & ~(~0 << 8)))
int main(void)
{
	int a = 0x5747;
	printf ("a = %X\n", a);
	a = bitt(a);
	printf ("a = %X\n", a);
	return 0;
}
