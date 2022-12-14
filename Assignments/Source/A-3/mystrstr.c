#include	"hdr2.h"

char* mystrstr(char *s, char *d)
{
	int i;
	int j;

	/*taking first char and searching the destination string*/
	for ( i = 0; *(s+i) != '\0'; i++) {
		if ( *d == *(s+i)) {
			/*comparing string 2 and string 1 if not found breaking */
			for ( j = 1; *(d+j) != '\0' ; j++) {
				
				if ( *(d+j) != *(s+i+j) )
					break;
			}
			/*returning the occurance*/
			if ( *(d+j) == '\0')
				return (s+i);
		}
	}
	if ( *(s+i) == '\0')
		return NULL;
} 
