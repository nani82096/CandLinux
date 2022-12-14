#include	<stdio.h>
int main(void)
{
	float a = -4.4;

	*(int *)&a  ^= ( 1 << 31);

	printf ("%f\n", a);

	return 0;
}
