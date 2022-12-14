#include	<stdio.h>
#include	<limits.h>


void show_bits(int n, int bound)
{
	int i = 0;
	for ( i = bound - 1 ; i >= 0; i--) {
		printf("%d", (n >> i) & 1 );
		if( i % 8 == 0)
			printf(" ");
	}
	printf("\n\n");
}
