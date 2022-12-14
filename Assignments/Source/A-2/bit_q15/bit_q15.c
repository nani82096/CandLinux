#include	"hdr1.h"

void main(void)

{
	printf("\n\nreturns number with n bits that begin at postion p inverted, leaving others unchanged..\n\n");
	int x;
	int p;
	int n;
	printf("\nEnter no of bits\n");
    n = integervalidation();
    printf("\nEnter Position \n");
    p = integervalidation();
    printf("\nEnter the Number\n");
    x = integervalidation();
	printf("\\The Entered number in binary is as follows:\n");
    show_bits(x);

    x = invert(x, p, n);

    show_bits(x);

}
