#include	<stdio.h>

unsigned int reverse(register unsigned int x)
{
	x = ( (x >> 16) | (x << 16 ));
    x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));
    x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));
    x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));
    x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));

  	return x;  

}
int main(void)
{
	int a = 10;

	printf ("%08x\n", a);
	
	a = reverse(a);

	printf ("%08x\n", a);

	return 0;
}	
