#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>

#if 0 
int main(void)
{
	void *pp;
	int n = 20;
	pp = &n;
	printf("%d \n",*(int*)pp);
	return 0;

}
#endif

#if 0
int *fun ( int a, int b)
{
	int c;
	c = a + b;
	return (&c);
}
int main (void)
{
	int a = 10;
	int b = 20;
	int *c;
	c = fun( a, b );
	printf ("%d\n", *c);
	printf ("%d\n", *c);
	printf ("%d\n", *c);	
	
	return 0;
}

#endif



#if 0 
int fun ( int a, int b)
{
	int c;
	c = a + b;
	printf ("%d\n",c);
}
int main (void)
{
	int a = 10;
	int b = 20;
	int c;
	c = fun( a, b );
	printf ("%d\n", c);
	printf ("%d\n", c);
	
	
	return 0;
}
#endif

#if 0
int main(void)
{
	int i = 0;
	char a = 'a';
	char *ptr = &a;
	ptr++;
	for ( i = 0; i < 16; i++){
		printf ("%d\t", *ptr);
	}
	return 0;
}
#endif


#if 0 
int main (void)
{
	int *ptr = NULL;
	printf ("sizeof ptr = %zu \n", sizeof(ptr) );
	ptr = (int *)malloc(10);
	
	printf ("sizeof ptr = %zu \n", sizeof(ptr) );
	printf ("addr of ptr = %p \n", ptr );
	printf ("sizeof ptr = %d\n", malloc_usable_size(ptr));	
	printf ("sizeof ptr = %d\n", *(ptr-1));	
	return 0;

}

#endif

#if 1
int main(void)
{
	int a = 10;
	int b = 20;

	int *p = &a;

	printf( "*p++ = %d\n",*p++);
	printf( "*p = %d\n",*p);
	p--;
	printf( "++*p = %d\n",++*p);
	//printf( "++(*p) = %d\n",++(*p));
	printf( "*p = %d\n",*p);
	
//	printf( "(*p)++ = %d\n",(*p)++);
//	printf( "*p = %d\n",*p);
	
		
	return 0;
}

#endif
