#include	"hdr1.h"

int main(int argc, char **argv)
{
	int i = -1;
	int num1 = atoi(argv[1]);
	int num2 = atoi(argv[3]);
	int mul = 0;
	int j = 0;
	int div = num1;
	if ( argv[2][0] == '+') {
		printf("\n\nThe sum is %d\n\n", add(num1, num2) );
	}
	else if ( argv[2][0] == '-') 
		printf("\n\nThe difference is %d\n\n", sub(num1, num2) );
	else if ( argv[2][0] == '*') {
		for ( j = 1; j <= num2; j++)
			mul = add(num1, mul);
		printf("\n\nThe multiplication is %d\n\n", mul);
	}
	else if ( argv[2][0] == '/') {
		while ( div >= 0) {
                div = sub( div, num2 );
                i++;
		}
		printf("\n\nThe division is %d \n\n", i);
	}
		
}
