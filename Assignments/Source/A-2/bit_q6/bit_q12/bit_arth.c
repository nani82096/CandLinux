#include	"hdr1.h"


int add(int a,int b)
{
	int x;
	x=a^b;
	while(a&b){
		b=((a&b)<<1);
   		a=x;
	    x=a^b;
    	//b=(a^b);
	}
	return x;
}

int sub(int a, int b) // add a with b's 2's complement.
{
    return (add(a, add(~b, 1)));
}

int bit_arth(int m, int n)
{
	printf("\n\nEnter 1 for addition\nEnter 2 for substraction\nEnter 3 for multiplication\nEnter 4 for division\n\n");
	int choice;
	int sum;
	int diff;
	int mul = 0;
	int i = -1;
	int div = m;
	int carry;
	scanf("%d", &choice);
	
	switch(choice) {
		case 1:
			sum = add ( m, n);
			return sum;
			break;

		case 2:
			diff = sub(m,n);
			return diff;
			break;
		case 3:
			for ( i = 1; i <= n; i++) {
				mul = add(m,mul);
			}
			return mul;
			break;
		case 4:
			while ( div >= 0) {
				div = sub( div, n );
				i++;
			}
			return i;
			break;
 
		default :
			printf("Choose any other");
			break;
	}
}
