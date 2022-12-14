#include	<stdio.h>
#include	<limits.h>

void show_bits (int, int );

int main()
{
	int x = 1254635125;
	int i;
	printf("before swap\n");
	show_bits (x, sizeof(x)*8);
	printf ("%08x\n", x);
	printf("after swap\n");

	int k = 0;
	for ( i = 0; i < (CHAR_BIT/2); i++){
		k = ( k | (((~(~0 << 4)) <<(i*CHAR_BIT) & x)<<4) |
				 ((((~(~0 << 4) << 4)<<(i*CHAR_BIT) & x)>>4)));
	}
	printf ("%08x\n", k);
	show_bits (k, sizeof(k)*8);
	return 0;
}

