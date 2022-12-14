#include	<stdio.h>

void fun( int a)
{
	*(&a-1) = *(&a-1) + 12;
	return ;
}

int main (void)
{
	fun (10);
	printf ("First Printf\n");
	printf ("Second Printf\n");	
	return 0;
}
