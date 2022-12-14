#include	<stdio.h>
struct a {
	int a;
	int b;
	int c;
	struct b{
		int k;
		int j;
		}bb;
	}aa = {1,2,3,.bb={4,5}};
int main(void)
{
	int a = 200;
	while ( a < 300){
		printf ("A = %d\n", a++);
	}
	return 0;
}
