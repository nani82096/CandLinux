#include	<stdio.h>
int main()
{
	int n = 0x5346;
//	n = (((n & (~(~0<<4)))<<8) | ((n & ((~(~0 << 4))<<8))>>8))  | \
		(((n & (~0<< 4) )) &( (~((~(~0<<4)) << 8))&n ));
	n = (((n & (~(~0<<4)))<<4) | ((n & ((~(~0 << 4))<<4))>>4))  | \
		(((n & (~0<< 4) )) &( (~((~(~0<<4)) << 4))&n ));
	printf("%0x\n", n);
	return 0;
}
