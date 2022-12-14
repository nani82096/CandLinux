#include	"hdr1.h"

void main(void)

{

	int c;
	char s[MAX];
	char valid[MAX];
	int i = 0;
	int j;
	while ( ( c = getchar() ) != EOF && c != '\n') {
		s[i++] = c;
	}
	s[i] ='\0';

	for ( i = 0, j =0; s[i] != '\0'; i++) {
		if ( s[i] == ' '|| ( s[i] >= 48 && s[i] <= 57) || ( s[i] >= 65 && s[i] <= 90) || ( s[i] >= 97 && s[i] <= 122)){
			valid[j] = s[i];
			j++;
		}
	}
	valid[j] = '\0';
	printf("\nEntered string is \n%s\n", s);
	printf("\nThe valid string is \n%s\n", valid);
	if ( i == j)
		printf("\n\nString is valid\n\n");
	else 
		printf("\nNot valid String\n");
}
	
