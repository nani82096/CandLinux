#include	"hdr2.h"

char* mystrncpy(char *d, char *s, int n)
{
	char *temp = d;
	/*copying n characters to destination string*/
	while ( ( n-- ) && ( *d++ = *s++ ) );
	*d = '\0';

	return temp;
}
