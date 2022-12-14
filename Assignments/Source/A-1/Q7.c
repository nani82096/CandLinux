/*	Name :: Veera
	Batch:: B80

for loop equivalant out the expression without using || and && operators 
*/


#include	"hdr1.h"

void main(void)

{
	int c;
	int i = 0;
	char s[MAX];
	while( ( c = getchar()) != '\n' ) {
		if ( ( c != EOF  ) )
			if ( i < MAX-1 ) 
				s[i++] = c;
	}
	s[i] = '\0';
	printf("\nthe output string is below :: \n\n%s\n\n", s);


}
