#include	"hdr2.h"

int mystrcspn(char *s, char *rjct)
{
	int count = 0;
	int flag;
	char *temp;
	for ( ; *s != '\0' ; s++) {
		temp = rjct;
		flag = 0;
		for ( ; *temp != '\0' ; temp++) {
			/*checking whether chars in reject are present in source */
			if ( *s == *temp) {
				flag = 1;
				break;	
			}
		}
		/*counting if chars are not there in source*/
		if ( flag == 0)
			count++;
		else 
			break;
	}
	/*returning the count*/
	return count;
}

