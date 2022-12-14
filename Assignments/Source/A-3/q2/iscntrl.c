#include	"hdr2.h"
int myiscntrl( int ch )
{
	if ( ((ch >= 7) && (ch <= 13)) || (ch == 0) )
		return 1;
	else 
		return 0;
}
