#include	"hdr1.h"

void main(void)
{
	printf("\n\nProgram to test and set the bit\n\n");
	printf("\nEnter Source number\n");
    int num = integervalidation();

	printf("\nEnter Bit Position\n");
    int pos = integervalidation();

	printf("\nNumber binary representation is\n");
	show_bits(num);
    
	printf("\n\nAfter the Testing and Setting the bit\n\n");
	num = bit_ts(num, pos);
	show_bits( num );

}

