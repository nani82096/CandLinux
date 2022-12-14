#include	<stdio.h>

void main(void)

{


 	int x = -6;

	int y = 6;
	
/*	printf("\n\nleft shift of -6 %08x\nright shift of -6 is %08x"
			"\n\nleft shift of 6 %08x\nright shift of 6 is %08x\n\n", x<<1, x>>1, y<<1, y>>1);*/
	signed int z =-6;
	printf("%08x    %08x", x, z);

} 
