#include	"hdr1.h"


int add(int a,int b)
{
/*	int s;
	s=a^b;
	while(a&b){
		b=((a&b)<<1);
   		a = s;
		s = a^b;
    	//b=(a^b);
	}
	return s;
*/ /*Both codes will work fine */
	int carry = 0;
	while(b){
		carry = a&b;
		a = a^b;
		b = (carry)<<1;
	}	
	return a;
}

int sub(int a, int b) // add a with b's 2's complement.
{
    //return (add(a, add(~b, 1)));
	int barrow;
	while (b){
		barrow = (~a)&b;
		a = a ^ b;
		b = barrow << 1;
	}
	return a;
}


int bit_arth(int m, int n)
{
	printf("\n\nEnter 1 for addition\nEnter 2 for substraction\nEnter 3 for multiplication\nEnter 4 for division\n\n");
	int choice;
	int sum;
	int diff;
	int mul = 0;
	int i = -1;
	int j;
	int k;
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
			if ( m < 0 && n >= 0){
				j = n;
				k = m;
			}
			else if ( m >= 0 && n < 0){
				j = m;
				k = n;
			}
			else if ( m < 0 && n < 0) {
				j = -1*m;
				k = -1*n;
			}
			else {
				j = m;
				k = n;
			}
			for ( i = 1; i <= j; i++) {
				mul = add(k,mul);
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
