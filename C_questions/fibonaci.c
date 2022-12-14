#include	<stdio.h>

int fibonaci(int b)
{
	if ( b == 0)
		return 1;
	if ( b == 1)
		return 1;

	return (fibonaci(b-1)+fibonaci(b-2));
}
int main(void)
{
	int n;
	printf ("Enter max value:");
	scanf ("%d", &n);
	
	int i = 0;
	for ( i = 0 ; i < n; i++){
		
		printf ("%d ", fibonaci(i));
	}	
	return 0;

}
