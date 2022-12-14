#include	"hdr2.h"

char* squeeze( char *src, char *dst)
{

	char *temp = (char *)malloc(SIZE*sizeof(char));
	char *temp1 = temp;
	int flag;
	char *temp2;
	while(*src){
		flag = 0;
		temp2 = dst;
		while (*temp2) {

		/* Comparing string2 if chars are there assigning flag = 1*/
			if ( *src == *temp2 )
				flag = 1;
			
			temp2++;
		}

		/* if flag is zero then that char is not in 1st string so assign it to temp */
		if ( flag == 0){
			*temp = *src;
			temp++;
		}
		src++;
	}
	return temp1;
}
