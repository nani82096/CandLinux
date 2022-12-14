#include	<stdio.h>
	int n;

int fibonaci(int a, int b)
{

	static int i = 0;

	//int c;

	if ( i == n) {
		
		return 0;

	} else {
		
//		c = a + b;	
		
//		a = b;
		
//		b = c;

		printf ("%d ", a+b);
			
		i++;
		
		fibonaci ( b, a + b ) ;
	}
}
int main(void)
{
	scanf ("%d", &n);
	n = n - 1;
	printf ("1 ");
	fibonaci(0,1);
	return 0;
}
