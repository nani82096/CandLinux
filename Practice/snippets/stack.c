#include	<stdio.h>
int swap(int a, int b){
/*	a = a^b;
	b = a^b;
	a = a^b;*/
	return 0;
}
int main(void)
{
	int a = 3;
	int b = 9;
	printf ("a = %d b = %d \n", a, b);

	swap(a, b);
	a = *(&a-5);
	b = *(&a-6);
	printf ("a = %d b = %d \n", a, b);
	return 0;
}
