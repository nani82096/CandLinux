#include	<stdio.h>


void show_bit_rec(int n)
{
	if (n != 0){
		
		show_bit_rec(n/2);

		printf ("%d", n%2);
	} 
	return ;
}
int main(void)
{
	int a = 4;

	show_bit_rec(MAX);
		
	printf ("\n");

	return 0;
}
