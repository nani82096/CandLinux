#include	"hdr1.h"

void main(void)

{
	printf("\n\nSwaps the Source and destination bits in a number\n\n");
	int n;
	int d;
	int s;
	printf("\nEnter the number\n");
	n = integervalidation();
	printf("\nEnter Source bit\n");
	s = integervalidation();
	printf("\nEnter Dest bit\n");
	d = integervalidation();
	
	printf("\n\nThe actual number binary representation is\n\n");
	show_bits(n);
	printf("\n\nThe after swap binary representation is\n\n");
	show_bits(bit_swap(n,d,s));

}
