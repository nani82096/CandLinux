#include	<stdio.h>
#define SWAP_BIT(num, spos, dpos) (((num&(1<<spos)) ^ (num&(1<<dpos))) && \
									(num = num^(1<<spos)^(1<<dpos)))


int main(void)
{
	int a = MAX;
	printf ("a = %d\n", a);
	SWAP_BIT(a, 1, 2);
	printf ("a = %d\n", a);
	return 0;
}
