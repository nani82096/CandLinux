#include	"hdr1.h"

void main(void)
{
	printf("\n\nCopy n bits from position s of number 1 to position p of number 2\n\n");
	printf("\nEnter Source bit\n");
    int s = integervalidation();
    printf("\nEnter Dest bit\n");
    int p = integervalidation();
    printf("\nEnter Source number\n");
    int num1 = integervalidation();
    printf("\nEnter Destination number\n");
    int num2 = integervalidation();
    printf("\\The source and destination numbers respectively are as follows before operations done\n\n");
    show_bits(num1);
    show_bits(num2);
	
	printf("\n\nEnter no of bits to copy\n\n");
	int n = integervalidation();
	
	num2 = cpy_bits(num1, num2, s, p, n);
	
	show_bits(num2);
}

