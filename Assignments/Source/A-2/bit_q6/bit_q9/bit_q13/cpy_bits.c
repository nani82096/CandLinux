#include	"hdr1.h"

int cpy_bits(int num1, int num2, int s, int p, int n)
{
	int t1;
	int t2;
	if ( ( (s+n > sizeof(int)*8 )) || ((p+n > sizeof(int)*8)) )
		printf("\n\nNot possible to copy size is exeeding\n\n");
	else{
		t1 = ( num1 & ( ((~0) << s) ^ ((~0) << s+n )) ) >> s;
		num2 = (num2 & (~( ((~0) << p) ^ ((~0) << p+n ))));
		num2 = (t1 << p) | num2 ;
	}
	return num2;
}
