#include<stdio.h>

int (*func_type)();

int function(void)
{
	printf("hello");
	return 1;
}
int main(void)
{
	func_type=function;
	printf("%d", func_type());
	return 0;
}
