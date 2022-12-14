/*	Name :: Veera
	Batch:: B80
Verification of the expressiong that getchar()!=EOF is true or false) */

#include	"hdr1.h"

void main(void)
{
	int c;
	int temp;
	temp =  ( ( c = getchar () ) != EOF); 
	printf("\n\nThe expression getchar () != EOF is returning  %d\n\n", temp);
}
