/*	Name :: Veera
	Batch:: B80
function for the Question 5 this function reverses the string */


#include	"hdr1.h"

char *reverse( char *a)
{
	char *p = a;
	char *q = a;
	int i = 0;
	while(*q){			/* finding the string length */
		q++;
		i++;
	}
	q = q - 1;
	while(p < q){
		*(p) = *p ^ *q;
		*(q) = *p ^ *q;
		*(p) = *p ^ *q;
		p++;
		q--;
	}
//	*(a+i) = '\0';	
	return a;
}
