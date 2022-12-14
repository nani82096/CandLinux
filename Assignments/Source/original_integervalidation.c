
#include	"hdr1.h"

void main (void)

{
	int c;
	char s[50];
	int i = 0;
	int digit_count = 0;
	int n;
	int length;
	int choice;
	printf("\nEnter to check the validation\n");
	
	while ( ( c = getchar() )!= EOF && c != '\n') {
		s[i++] = c;
	}
	
	s[i] = '\0';
	length = i;

	n = str_atoi(s);

	int temp;
	if ( n < 0)
		n = -1 * n;
	while (n > 0) {
	
		temp = n % 10;
	
		digit_count++;
	
		n = n / 10;
	}

	for ( i = 0; s[i] != '\0' ; i++) {

		if ( s[i] == ' ') {
			length --;
		
			if ( s[i+1] == '+' || s[i+1] == '-')
				length --;
		}
	}
	i = 0; 	
	if ( s[i] == EOF || s[i] == '\0' )
			printf("\n1Not Valid Integer\n");

	else if ( s[i] == '+' || s[i] == '-' ) {
		length = length - 1;

		if ( length == digit_count )
			printf("\nAbove is Valid Integer \n");
		else
			printf("\n2Not Valid Integer\n");
	} else {
		if ( length  == digit_count)
			printf(" \nAbove is Valid integer\n");
		else
			printf("\n3Not Valid integer \n");
	}
}
