#include	"hdr1.h"

int trailing_zero(int num)
{
	int i;
	int count = 0;
	for ( i = (sizeof(int)*8 - 1 ); i >= 0, ((num >> i) & 1) != 1; i--) {
		count++;
	}
	return count;
}
