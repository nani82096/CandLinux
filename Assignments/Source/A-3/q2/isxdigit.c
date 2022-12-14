#include	"hdr2.h"

int myisxdigit(int ch)
{

	if ( (( ch >= '0')  && ( ch <= '9')) || (ch >= 'a' && ch <= 'f' ) || ( ch >= 'A' && ch <= 'F') )
		return 1;
	else 
		return 0;
}
