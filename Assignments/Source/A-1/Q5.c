/*	Name :: Veera
	Batch:: B80
String reverse program here the function is defined in another program 
*/

#include	"hdr1.h"

void main(void)
{
	char str1[MAX];
	int c;
	int i = 0;

	printf("Enter string to reverse\n");

	while ( ( ( c = getchar() ) != EOF) && c != '\n') {
		str1[i++] = c;
	}
	str1[i] = '\0';

 	reverse(str1);
		printf("reversed string is %s\n", str1 );
}


