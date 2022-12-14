#include	"hdr1.h"

int setbits( int x, int p, int n, int y)
{

	int t2;
	int t1;
	if ( p > 32)
		printf("\nNot possible to bit posision is exceeding\n");
	else {
		
		t1 = ( x & (~( ((~0) << p) ^ ((~0) << p+n ))) );
		t2 = ((y & (~((~0) << n))) << (p - (n-1)));
		x = t1 | t2;
	}
	return x;
}
