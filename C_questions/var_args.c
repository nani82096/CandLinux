#include	<stdio.h>

#include	<stdarg.h>

int avg (int num, ...){

	va_list varlist;
	
	va_start (varlist, num);

	int a = 0;
	while (num--){
	
		a = va_arg ( varlist, int);
		printf ("A = %d\n", a);
	}
		
}

int main(int argc, char *argv[])
{
	int main = 20;
	avg (/*atoi(argv[1]),*/5,3,4,5,6,7,NULL);
	return 0;
}
