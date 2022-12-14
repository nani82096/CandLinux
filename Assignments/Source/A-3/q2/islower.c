#include	"hdr2.h"

int myislower(int ch)
{
	if ( ( ch >= 97) && ( ch <= 122) )	{
		printf ("ch: %d\n", ch);
		return ch;
	}
	else
		return 0;

	return 0;
}
