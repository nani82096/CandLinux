#include	<stdio.h>
#define pow_4(n) (  !(n&n-1) ? 0x55555555 & n  ? 1:0 :0)

int main(void)
{
	int n = MAX;

	n = pow_4(n);
	
	printf ("%d",n);
	n ? printf ("Power of 4\n") : printf ("Not a power of 4\n");
	return 0;

}
