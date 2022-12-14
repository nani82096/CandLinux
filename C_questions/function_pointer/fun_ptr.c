#include	<stdio.h>

typedef int (*func_type)(void);

int function(void)
{
	printf("In function\n");
	return 1;
}

void function_to_function(int(*f)(void))
{
	printf("In function_to_function: return value = %d\n", f());
	return;
}			

int main(void)
{
	func_type func;
	func = function;
	function_to_function(func);
	return 0;
}
