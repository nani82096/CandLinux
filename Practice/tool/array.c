#include	<stdio.h>
int a[3] = {1,2,3};
int b = 20;
int c = 30;
int d = 40;
int main(void)
{
	
//	a[3] = 550;	
	getchar();
	
	printf("address = %p and value   a[%d] = %d\n",&a[3], 3, a[3]);
	printf("address = %p and value   a[%d] = %d\n",&a[4], 4, a[4]);
	printf("address = %p and value   a[%d] = %d\n",&a[5], 5, a[5]);
	printf("address = %p and value   = %d      \n",&b, b);
	return 0;
	} 
