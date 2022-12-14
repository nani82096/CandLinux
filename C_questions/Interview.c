#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>

#if 0
int main(void)
{
	static int a = 5;
	if (--a)
		main();
	printf ("Value of a = %d\n", a);
	return 0;
}
#endif

#if 0
int fun(register int a)
{
	if (--a){
		fun(a);
	}
	printf ("Value of a = %d\n", a);

	return 0;
}
int main(void)
{
	static int a = 5;
	fun(a);
	return 0;
}
#endif
#if 0
int main(void)
{
	char a = 120;
	int i = 0;
	for ( i = 0; i < 20; i++,a++)
		printf ("a = %d\n", a);
	return 0;

}
#endif
#if 0
int main(void)
{
	if ( 6 - printf ("Hello "))
		printf ("Hello ");
	else 
		printf ("World\n");
}
#endif

#if 0
int main(void)
{
	int *ptr = (int *)malloc(20*sizeof(int));
	int *pptr = "Hello";
//	printf ("pptr address = %p\n", &pptr);
	printf ("pptr pointing = %p \n", ptr);
	pptr = ptr;
	printf ("pptr pointing = %p \n", ptr);
	free(pptr);
	free(ptr);
	return 0;
}
#endif 

#if 0
int main(void)
{
	static int a = 5;
	static int b = a;

	printf ("Value of b = %d\n", b);

#endif

#if 0
int main(void)
{
	int b = 5;
	printf ("A = %d\n", a);
	return 0;
}

#endif 
#if 0
int main(void)
{
	int a;
	a = 5;
	printf ("a  = %d\n", a);
	{
	static int a = 4;
	}
	printf ("a  = %d\n", a);
	return 0;
}

#endif
