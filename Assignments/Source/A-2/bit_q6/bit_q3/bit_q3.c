#include    "hdr1.h"

void main( void )

{
	printf("\n\nToggle the even and odd bits of the number given\n\n");
    printf("\nEnter Source number\n");
    int snum = integervalidation();
	
	printf("\n\nThe actual number binary representation is\n\n");
	show_bits(snum);

	
	printf("\nThe even bits toggle of number above number is\n");
    snum = even_bit_toggle (snum);
	show_bits( snum );

	printf("\nThe odd bits toggle of number above number is\n");
	snum = odd_bit_toggle(snum);
	show_bits( snum );

}

