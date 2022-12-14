#include	"hdr2.h"

int mystrspn(char *s, char *acpt)
{
	int count = 0;
	int flag;
	char *temp = acpt;
	for ( ; *s != '\0' ; s++) {
		acpt = temp;
		flag = 0;
		/*checking the charecters present in accept and counting */
		for ( ; *acpt != '\0' ; acpt++) {
			if ( *s == *acpt) {
				count++;
				flag = 1;
				break;
			}
		}
		/*if one non occured character came returning the count*/
		if ( flag == 0)
			return count;
	}
	return count;
}

