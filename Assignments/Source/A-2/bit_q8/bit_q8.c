#include	"hdr1.h"

void main(void)
{

	printf("\n\nrotate bits in given number\n\n");
    printf("\nEnter First number\n");
    int num = integervalidation();

    printf("\nEnter number of bits\n");
    int nbit = integervalidation();

    printf("\nEnter 1 for right rotation\nEnter 0 for left rotation\n");
	int dir = integervalidation();

    printf("\nNumber binary representation is\n");
    show_bits(num);

    int result = rotate_bit(num, nbit, dir);
    show_bits( result );

    printf("\n\nThe result in decimal is %d\n", result);

}
