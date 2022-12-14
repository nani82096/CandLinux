#include	<stdio.h>

int main(void)
{
	int a;
	int count = 0;
	printf ("Enter a number:");
	scanf("%d", &a );
	while (a){
		a = a & (a-1);
//		a = a >> 1;
		count++;
	}
	printf ("The number of set bits = %d\n", count);
	return 0;
}
