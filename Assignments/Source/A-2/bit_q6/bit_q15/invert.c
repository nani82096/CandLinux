#include	"hdr1.h"

int invert ( int x, int p, int n)
{
	if ( p > 31 || n > 31 )
		printf("\nNot possible to invert the bits\n");
	else {
		x = x ^ (( (~0) << n) ^ ( (~0) << p + 1) );
	}
	return x;
}
