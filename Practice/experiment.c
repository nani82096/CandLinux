#include	<stdio.h>

#if 0

int g_var = 12;

int main()

{
	printf("%d",atoi("12A4"));
	return 0;
}
#endif

#if 0 
int main(void)
{
	int a[3] = {1,2,3};
	a[5] = 15;
	//printf("%d ", a[13]);
//	fflush(stdout);
//	printf("%d \n", a[13]);	
	return 0;
}
#endif

#if 0
int main(void)
{
	char a;
	char b;
	printf(" %c ", 'a b');
	return 0;
}

#endif

#if 0
int main(void)

{

	int a[3] = { 1,2,3,4,5,6,7,8};
//	a[6] = &main;
	printf("%d %d %d %d \n", a[3], a[4],a[6], ( unsigned int) main);
	return 0;
}
#endif

#if 0
int main ( void ) 
{

	int a[5] = {1,2,3,4,5};
	int *p = a;
	int i = 0;
	printf ("\n");
	for ( i = 0;i < 5 ; p++,i++ ){

		printf ("%d ", *p );
	}
	printf ("\n");
	return 0;

}
#endif


#if 0

int main ( void ) 
{

	int a[5] = { 1,2,3,4,5 };
	int i = 0;
	printf ("\n");
	for ( i = 0; i<5; i++ )
		printf ("%d ", a[i] );
	printf ("\n");
	return 0;

}

#endif


#if 1

int main ( void )
{

/*	int a[3] = {1,2,4 };

	a[4] = 5;
	a[5] = 6;
	a[6] = 7;
	printf ("%d\n", a[4] );
	printf ("%d\n", a[4] ); 
	printf ("%d\n", a[4] ); 
*/
	char arr[11]="The African Queen";
    printf("%s",arr);
	return 0;

}

#endif
