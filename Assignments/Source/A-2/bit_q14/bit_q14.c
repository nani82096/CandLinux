#include	"hdr1.h"
void main(void)
{
	printf("\n\nreturns number with the n bits that begin at position p set to the right most n bits of y, leaving the other bits unchanged...\n\n");
	printf("\nEnter no of bits\n");
    int n = integervalidation();
    printf("\nEnter Position in number to set that n rigth bits of y\n");
    int p = integervalidation();
    printf("\nEnter first number\n");
    int x = integervalidation();
    printf("\nEnter second (i.e y) number\n");
    int y = integervalidation();
    printf("\\The source and destination numbers respectively are as follows before operations done\n\n");
    show_bits(x);
    show_bits(y);

	x = setbits(x, p, n, y);

	show_bits(x);

}
