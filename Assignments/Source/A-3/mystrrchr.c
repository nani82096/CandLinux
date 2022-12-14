#include	"hdr2.h"

char* mystrrchr(char *s, int ch)
{

	int i = 0;
	int j = 0;
	char *temp = s;// temp pointing to s always
	while (*s){
		if ( *s == ch )
			/*storing the last occurance of ch in src */
			j = i;
		i++;
		s++;
	}
	/* returning the temp+last occurance of character*/
	if ( j > 0)
		return (temp + j);
	else
		return (temp + i);
}
