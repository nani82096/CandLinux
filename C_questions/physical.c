#include	<stdio.h>
#include	<stdlib.h>
int a = 10;
int d ;

void fun(int a )
{
	printf ("in func a = %d\n",a);
}

int main(void)
{
	int c = 23;
	//int *ptr = (int *)malloc(sizeof(int)*1024*1024);

	fun(c);
	printf ("pid = %d\n", getpid());
	getchar();
	//free(ptr);
	//ptr = NULL;
	return 0;
}
		
	
