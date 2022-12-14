#include<stdio.h>

void func()
{
	int a[1] = {6};
	int c = 4;
	int b[2] = {5, 7};
	printf("%u\n",a);
	printf("%u\n",b);	
	printf("%d\n",b-a);
	b[b-a] = 3;
	printf("%d\n",b[2]);
//	return 0;
}
int main()
{
	int a;

	func();
	
	a = 5;

	return 0;
}

