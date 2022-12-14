#include	"hdr2.h"

int mystrlen(char *src)
{
	int length = 0;
	/* counting the characters till null char occurs*/
	while(*src++ != '\0')
		length++;
	return length;

}
