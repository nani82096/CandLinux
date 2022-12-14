/* Please Compile the function files Q8_str_atoi and integervalidation_func and bit_cp .*/


#include	"hdr1.h"

void main( void )

{
	printf("\n\ncopies the bitvalu es from num1 to num2\n\n");
	
	printf("\nEnter Source bit\n");
	int s = integervalidation();
	printf("\nEnter Dest bit\n");
	int d = integervalidation();
	printf("\nEnter Source number\n");
	int snum = integervalidation();
	printf("\nEnter Destination number\n");
	int dnum = integervalidation();
	printf("\\The source and destination numbers respectively are as follows before operations done\n\n");
	show_bits(snum);
	show_bits(dnum);
	printf("\n\nThe after bit copy the binary representation is\n\n");
	
	
	show_bits( bit_cp (s, d, snum, dnum) );

}

