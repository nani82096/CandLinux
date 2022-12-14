/*	Name :: Veera
	Batch:: B80

Converting the string into asci equivalant 
*/

#include	"hdr1.h"

void main(void)

{
	char s[50];
	
	int c;
	int i = 0;
	while ( ( c = getchar() ) != EOF && c != '\n') {
		
		s[i++] = c;
	}
	s[i] = '\0';
	
	int out;
	
	printf("%s",s);
	
	out = str_atoi(s);

	printf("\nThe Integer Equivalant to String %s is %d\n", s, out); 
}
