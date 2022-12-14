#include	<stdio.h>

int main(void)
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int i;
	int j = 1;
	for ( i = 0; i < 10 ; j++) {
		if ( j == 10){
			j = 1;
			i++;
		}
		if (a[j] > a[j-1]){
			int temp = a[j-1];
			a[j-1] = a[j];
			a[j] = temp;
		}
	}
	printf ("%d\n", a[2]);
	return 0;
}
