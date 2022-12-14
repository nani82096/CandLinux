#include	<stdio.h>
#include	<limits.h>


void show_bits(int type,int n)
{
	int i = 0;
	int bound = type * CHAR_BIT;
/*	if (type == 1 ) 			// If integer 
		bound = CHAR_BIT * 4;
	else if (type == 2)
		bound = CHAR_BIT * 2;	// If Short Int 
	else
		bound = CHAR_BIT;		// else char 
	*/

	for ( i = bound - 1 ; i >= 0; i--) {

		printf("%d", (n >> i) & 1 );
		if( i % 8 == 0)
			printf(" ");
	}
	printf("\n\n");
}
