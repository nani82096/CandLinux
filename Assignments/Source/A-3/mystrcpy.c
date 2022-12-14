#include	"hdr2.h"

char* mystrcpy(char *d, char *s)
{

	char *temp = NULL;
	temp = d;
	/*copying the src string to dst string while null occurs*/
	while ( *d++ = *s++);
	*d = '\0';
	return temp;
}
