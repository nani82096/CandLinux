#include	"hdr1.h"

int count_bit_set(int num)
{
	int i;
	int count = 0;
	for ( i = 0; i < (sizeof(int)*8); i++) {
		if ( (num >> i) & 1)
			count++;
	}
	return count;
}

int count_bit_clear(int m)
{
	int i;
	int count = 0;
	for( i = 0; i < (sizeof(int)*8); i++) {
		if ( ( ( m >> i ) & 1) == 0 )
			count++;
		/*else
			count++;*/
	}
	return count;
}
