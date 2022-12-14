
#include	"hdr1.h"

void main(void)
{
	int c;
	char s[50];
	int i = 0;
	int j = 0;
	int digit_count = 0;
	int n;
	int length;
	int dot_count = 0;
	while ( ( c = getchar() )!= EOF && c != '\n') {
		s[i++] = c;
	}
		
	s[i] = '\0';
	length = i;

	n = str_atoi(s);
	
	for ( i = 0; s[i] != '\0'; i++) {
		if (s[i] == '.')
			dot_count++;
	}
	printf("Dot count == %d\n",dot_count);
	
	if ( dot_count > 1)
		printf( "The number is not valid floating number\n");
	else {
		for ( i = 0; s[i] != '\0'; i++) {
			
	
	
		
	}
		
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
			j = i;
			if ( s[i+1] == '+' || s[i+1] == '-')
				length --;
		}
	}

	i = 0; 	
	if ( s[i] == EOF || s[i] == '\0' )
			printf("\nNot Valid Integer\n");

	
	else if ( s[i] == '+' || s[i] == '-' ) {
		length = length - 1;

		if ( length == digit_count )
			printf("\nAbove is Valid Integer \n");
		else
			printf("\nNot Valid Integer\n");
	}
	else {
		if ( length  == digit_count)
			printf(" \nAbove is Valid integer\n");
		else
			printf("\nNot Valid integer \n");
	}
}
