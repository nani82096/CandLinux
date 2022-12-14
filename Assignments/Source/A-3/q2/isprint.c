#include	"hdr2.h"

int myisprint(int ch)
{
	if ( ch >= 32 && ch <= 126)
		return 1;
	else
		return 0;
}
