#include	"hdr2.h"

int myisalnum(int ch)
{
	if ( ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (  (ch >= '0')  && (ch <= '9'))) )
		return 1;
	else
		return 0;
}
