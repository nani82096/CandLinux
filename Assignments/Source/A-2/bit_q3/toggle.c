

#include	"hdr1.h"
#include	<limits.h>

int even_bit_toggle ( int num)
{
	int i;
	for( i = 0; i < (sizeof(int)*CHAR_BIT); i = i + 2) {
			num = ( num ^ ( 1 << i) );

	}
	return num;

}

int odd_bit_toggle ( int num)
{
	int i;
	for( i = 1; i < sizeof(int)*CHAR_BIT; i = i + 2) {
			num = ( num ^ ( 1 << i) );
	}
	return num;

}
