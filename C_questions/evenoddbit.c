#include	<stdio.h>
#include	<stdlib.h>
#include	<limits.h>


void showbits(int ,int);
int swap(unsigned int n)
{
	int i = 0;
	/*Another Way*/
	while ( i < (sizeof(int)*CHAR_BIT)) {
	
		( (n >> i) & 1) ^ (( n >> i+1) & 1) ? n = ( n ^ ~(~0<<2) << i) :0;
			
		i = i + 2;	
	}

	return n;
}
int main(void)
{
		unsigned int n;
		printf("Enter a number:");
		scanf("%d",&n);
		showbits(n,sizeof(n)*8);
		n = swap(n);
		showbits(n,sizeof(n)*8);
		return 0;	
}
void showbits(int n,int bound)
{
	int i = 0;
	for ( i = bound - 1 ; i >= 0; i--){
		printf("%d",(n >> i)&1);
		if ( i % 8 == 0)
			printf(" ");
	}
	printf("\n");
}


