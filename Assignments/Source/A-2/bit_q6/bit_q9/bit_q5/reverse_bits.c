#include	"hdr1.h"
#include	<limits.h>

unsigned int reverse_bits(unsigned int num)
{
	int i;
	int j;
	for ( i = 0, j = (sizeof(int)*CHAR_BIT - 1 ); i < j; i++, j--) {
		if ( ( (num >> i) & 1) != ( (num >> j) & 1 ) ) 
			num = num ^ ( (1 << i) ^ (1 << j) );
	}
	return num;
}
