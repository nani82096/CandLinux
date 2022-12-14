#include	<stdio.h>
int ismul9(int n)
{
	if ( n < 0)
		n = n*-1;
	if ( n == 0 || n == 9)
		return 1;
	if ( n < 9)
		return -1;
	return ismul9(abs((n>>3) - (n&7)));
}
int main(void)
{
	int num;
	printf("Enter a number:");
	scanf("%d",&num);
	int n = ismul9(num);
	if ( n == 1)
		printf("Is a multiple of 9\n");
	else
		printf("Not a multiple of 9\n");
	return 0;
}

	
