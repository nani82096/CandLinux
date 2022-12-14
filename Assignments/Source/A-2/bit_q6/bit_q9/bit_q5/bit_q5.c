#include	"hdr1.h"

void main(void)
{
	printf("\n\nreversing order of bits in a value from left to right.\n\n");
	printf("\nEnter Source number\n");
    unsigned int num = integervalidation();


    printf("\nNumber binary representation is\n");
    show_bits(num);

    printf("\n\nAfter reversing the bits\n\n");
	
	num = reverse_bits(num);
    show_bits( num );

}

