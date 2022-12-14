#include	"hdr1.h"

int bit_cp(int s, int d, int snum, int dnum)
{

	dnum = ( (dnum & ( ~(1 << d) )) | ( ( (snum >> s) & 1) << d ) );
	return dnum;
}
