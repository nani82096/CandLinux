#include	<stdio.h>
static int i = 1;
void func(void)
{
	int a[1]  = {1};
	a[4] = a[4] - 5*(1 - (i/100));
	printf("%d\n",i++);
//	sleep(1);
	return ;
}
int main(void)
{
	func();
	int x = 10;
	return 0;
}
