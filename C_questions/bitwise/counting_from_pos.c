#include	<stdio.h>

int main(void)
{
	int n = MAX;
	int pos = 0;
	int cnt = 0;
	printf ("Enter postion:\n");
	scanf ("%d",&pos);

	if ( !((1 << pos) & n)){
		printf ("Sum = %d\n", cnt);
		return 0;
	}

	n = n & ( ~(~0 << pos+1));
	while(n){
		cnt++;
		n = n & ( n - 1 );
	}
	printf ("Sum = %d\n", cnt);

	return 0;
}
