#include	"hdr1.h"

void show_bits(int n)
{

	int i;
	for ( i = sizeof(int)*8 - 1; i >= 0; i--) {

		printf("%d", (n >> i) & 1 );
		if( i % 8 == 0)
			printf(" ");
	}
	printf("\n\n");
}
