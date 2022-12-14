#include	<stdio.h>

union a {
		
	struct {
		char a[2];
		char b[2];
	}st;
	struct {
		int i;
		int j;
	}str;
	}uu = {12, 1};
int main(void)
{
	printf ("%d %d\n", uu.str.i, uu.str.j);

	return 0;
}

