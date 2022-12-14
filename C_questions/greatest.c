//#define least(a,b,c) ( (a < b && a < c) ? a : (b < a && b < c) ? b:c )
#define	least(a,b,c) ( (a > b) ? (b > c)? c:b : (a > c) ? c:a )
#include	<stdio.h>

int main(void)
{
	int a = 222;
	int b = 10;
	int c = 5;
	int l = least(a,b,c);
	printf( "least = %d\n", l);
	return 0;
}
