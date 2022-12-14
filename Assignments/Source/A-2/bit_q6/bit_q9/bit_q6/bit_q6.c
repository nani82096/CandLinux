#include	"hdr1.h"

void main(void)

{
	printf("\n\nProgram for arthimatic caluculations\n\n");
	printf("\nEnter First number\n");
   	int num1 = integervalidation();

	printf("\nEnter Second number\n");
    int num2 = integervalidation();

    printf("\nNumber binary representation is\n");
    show_bits(num1);

	printf("\nNumber binary representation is\n");
    show_bits(num2);

    printf("\n\nThe following are arthimatic operatins using bitwise operators\n\n");
	
	int result = bit_arth(num1,num2);
	show_bits( result );

	printf("\n\nThe result in decimal is %d\n", result);

}


