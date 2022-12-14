#include	<stdio.h>
int main(void)
{
	__typeof__('a') pt = 'b';
	printf ("size = %d\n", sizeof(pt));
	printf ("pt = %c\n", pt);
	return 0;
}
