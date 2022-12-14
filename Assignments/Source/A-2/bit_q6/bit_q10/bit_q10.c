#include	"hdr1.h"

void main(void)
{
	printf("\n\nprogram to count the trailing zero's\n\n");
	int num;
	printf("\n\nEnter the The number\n\n");
	num = integervalidation();
	
	
	printf("\n\nNumber in binary validation\n\n");
	show_bits(num);
	
	printf("\n\nThe number of trailing zeros is %d\n\n", trailing_zero(num));
}
