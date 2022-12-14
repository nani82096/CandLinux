#include	"hdr1.h"

int bit_ts(int num, int pos)
{
	int i;
	i = (num >> pos) & 1;
	if ( i == 0)
		num = ( num | (1 << pos) );

	return num;
}
