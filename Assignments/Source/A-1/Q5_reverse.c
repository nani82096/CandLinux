/*	Name :: Veera
	Batch:: B80
function for the Question 5 this function reverses the string */


#include	"hdr1.h"

char *reverse( char *a)
{
	int i = 0;
	int nc = 0;
	char *r;
	while( a[i++] != '\0' ){			/* finding the string length */
		nc++;
	}
	
	r = (char *) malloc( nc * sizeof(char) );
	i = 0;
	for ( nc ; nc >=0; nc--) {
		r[i++] = a[nc-1]; 
	}
	
	r[i] = '\0';
	
	printf("%s\n", r);

}
