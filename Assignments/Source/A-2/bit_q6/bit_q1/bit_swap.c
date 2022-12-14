#include	"hdr1.h"

int bit_swap(int n, int d, int s)
{
	if ( ( (d < 32 && d >= 0) && (s < 32 && s >= 0))&& (((n >> s) & 1) != ((n >> d) & 1)) ) {

		 n =  n ^ ((1 << s) | ( 1 << d));

 	}
	return n;

}
