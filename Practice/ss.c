#include	<stdio.h>
int fun(int a)
{
	int b = 100;
	a = a+b;
}
int main(void)
{
	printf("%d\n",fun(1));
	return 0;
}
