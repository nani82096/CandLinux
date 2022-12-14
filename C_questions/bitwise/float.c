#include	<stdio.h>

int main(void)
{
	float a = -4.5;

//	int *temp = &a;

	printf ("value = %f\n\n", a);

//	show_bits(*temp, sizeof(*temp));

//	*temp = *temp ^ ( 1 << 31);

//	show_bits(*temp, sizeof(*temp));


//	printf ("%08x\n", (*(int *)&a));

//	printf ("%08x\n", (*(int *)&a) ^ 0x80000000);
	
	*(int *)(&a) = (*(int *)&a) ^ 0x80000000;

	printf ("value = %f\n", a);

//	printf ("%08x\n",*(int*) &a);	
	return 0;
}
