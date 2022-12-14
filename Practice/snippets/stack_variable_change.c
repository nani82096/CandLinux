#include	<stdio.h>

void fun (void)
{
	int a = 10;
	*(&a + 10) = 200;
	/*
	int i = 0;
	for ( i = 0; i < 200; i++)
		if (*(&a+i) == 20){
			*(&a+i) = 2000;
			break;
		}
	*/
	return ;
}

int main (void)
{
	int d = 20;

	printf ( "D value Before = %d\n",d);
	fun();
	printf( "D value After  = %d\n",d);
	return 0;

}
