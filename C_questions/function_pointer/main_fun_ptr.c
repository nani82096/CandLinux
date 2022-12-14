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

void another_function(int val)
{
	printf("In another_function: val = %d\n", val);
	return;
}

func_type function_returning_pointer_to_function(void)
{
	int function(void);
	printf("in function_returning_pointer_to_function\n");
	return function;
}

int (*function_returning_pointer_to_function_1(void)) (void)
{
	int function(void);
	printf("in function_returning_pointer_to_function_1\n");
	return function;
}

int main(void)
{
	func_type func;
	func_type func_array[2] = {function, function};
	func = function;
	printf("return value = %d\n", func());
	function_to_function(function);
	another_function(func());
	func = function_returning_pointer_to_function();
	printf("return value = %d\n", func());
	func = function_returning_pointer_to_function_1();
	printf("return value = %d\n", func());
	printf("executing functions using function arrays\n");
	printf("func_array[0]->return value = %d\n", func_array[0]());
	printf("func_array[1]->return value = %d\n", func_array[1]());
	return 0;
}
