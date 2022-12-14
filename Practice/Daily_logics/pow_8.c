#include	<stdio.h>

int main(void)

{
	int num;
	printf("Enter number to check ");
	scanf("%d", &num);
	int i;
	int flag = 0;
	if ( !( num & (num-1))) {
		flag = 0;
		i = 0;
		while ( i < 8) {
			if ( num &  ( 1<<(3*i))) {
				flag = 1;
				break;
			}
			i++;
		}
	}
	if ( flag == 1)
		printf("Number is power of 8\n");
	else 
		printf("Number is not power of 8\n");
	return 0;
}
