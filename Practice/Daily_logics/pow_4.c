#include	<stdio.h>

int main(void)

{
	int num;
	printf("Enter number to check ");
	scanf("%d", &num);
	int i;
	int flag = 0;
	for ( i = 0; i < 32; i = i+4) {
		if (!(num ^ ( 1 << i))){
			flag = 1;
			break;
		}
	}
	if ( flag == 1)
		printf("Number is power of 8\n");
	else
		printf("Number is not power of 8\n");
	return 0;
}
