#include	<stdio.h>
#include	<string.h>
int main(void)
{
	char a[500];
	char b[500];
	int i = 0;
	int j = 0;
	printf("Enter The first Number::");
	if ( (fgets(a,500,stdin) == NULL  )){
		printf("Invalid Input\n");
		return 0;
	}
	if (a[0] == '\n')
		return 0;
	
	if (a[strlen(a) - 1] == '\n')
		a[strlen(a) - 1] = '\0';
	__fpurge(stdin);	
	
	printf("Enter The Second Number::");
	if ( (fgets(b,500,stdin) == NULL )) {
		printf("Invalid Input\n");
		return 0;
	}
	if (b[0] == '\n')
		return 0;
	if (b[strlen(b) - 1] == '\n')
		b[strlen(b) - 1] = '\0';
	printf("a = %s\n",a);
	printf("b = %s\n",b);
	int m = strlen(a);
	int n = strlen(b);
	if ( m < n ) {
		for ( i = n, j = m ; i >= 0; i--,j--) {
			if ( j >= 0)
				a[i] = a[j];
			else
				a[i] = '0';	
		}
	}
	
	else if ( n < m) {
		for ( i = m, j = n ; i >= 0; i--,j--) {
			if ( j >= 0)
				b[i] = b[j];
			else
				b[i] = '0';	
		}
	}
	m = strlen(a);
	n = strlen(b);
	a[m+2] = '\0';
	b[m+2] = '\0';
	for ( i = m+1, j = m ; i > 0, j >=0 ; i--,j--){
		a[i] = a[j];
		b[i] = b[j];
	}
	a[i] = '0';
	b[i] = '0';
	m = m+1;
	n = n+1;
	printf("a = %s\n",a);
	printf("b = %s\n",b);
	char result[500];
	int sum = 0;
	int carry = 0;
	for ( i = 0; i <= m ; i++)
		result[i] = '0';
	result[i] = '\0';
	for ( i = m-1; i >= 0 ; i-- ){
		sum = sum + (a[i] - 48 ) + (b[i] - 48 );
		carry = sum/10;
		sum = sum %10;
//		printf("%d",carry);
//		printf(" %d",sum);
		result[i] =  (result[i] - 48 )+sum + 48;
		sum = carry;
	}
	result[m] = '\0';
	printf("The result = %s\n",result);
	return 0;
}
