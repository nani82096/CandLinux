#include	"header.h"

int integervalidation (void)
{
	int i = 0;
	int digit_count = 0;
	int n;
	int length = 0;
	int temp;	
	int value;
	int c;
    char s[100];
	//printf("Enter input\n");
	/*taking the input into a character array*/
    while ( (( c = getchar() ) != EOF) && c != '\n') {
        s[i++] = c;
    }

    s[i] = '\0';
	length = i;
	
 	i = 0;
	/*replacing tab with space*/
	while ( s[i] != '\0'){
		if (s[i] == '\t')
			s[i] = 32;
		i++;
	}
	/*calling atoi */
	n = str_atoi(s);
	value = n;

	if ( n < 0)
		n = -1 * n;
	/*counting the digits*/
	while (n > 0) {
	
		temp = n % 10;
	
		digit_count++;
	
		n = n / 10;
	}
	/*arranging the original string length i.e neglecting space and one plus and one minus*/
	for ( i = 0; s[i] != '\0' ; i++) {

		if ( s[i] == ' ' ) {
			length --;
		
			if ( s[i+1] == '+' || s[i+1] == '-' )
				length --;
		}
		
	}
	for ( i = 0 ; s[i] != '\0' ; i++){
		if ( s[i] != '0')
			break;
		length--;
	}
	i = 0;
	int flag = 0;
	if ( s[i] == EOF || s[i] == '\0' ) {
		printf("\ninput Invalid Please re-enter the input\n");
		return (integervalidation( ) );
	}

	else if ( s[i] == '+' || s[i] == '-' ) {
		length = length - 1;

		if ( length == digit_count )
			flag = 1;
	
		else {
			printf("\ninput Invalid please re-Enter the input\n");
			return ( integervalidation( ) );
		}
			

	} else {
		if ( length  == digit_count)
			flag = 1;

		else {
			printf("\ninput Invalid Please re-Enter the input\n");
			return ( integervalidation() );
		}
	}
	if ( flag == 1)
		return value;
}
