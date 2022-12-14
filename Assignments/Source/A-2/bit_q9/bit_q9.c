#include	"hdr1.h"

void main(void)
{

	printf("\n\ncount number of bits set and clear\n\n");
	printf("\n\nEnter the Number\n\n");
	int num;
	num = integervalidation();
	
	printf("\n\nThe Number in binary is\n\n");
	show_bits( num );
	
	printf("\n\nNo of bits set is %d\n\n", count_bit_set(num) );

	printf("\n\nNo of bits clear is %d\n\n", count_bit_clear(num) );

}
	
	
	
