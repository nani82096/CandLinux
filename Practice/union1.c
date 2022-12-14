#include<stdio.h>
union s
{
	int a[2];
	double b;
	char c;
}s1={ 10 , 20 , 30 , 40};

int main()
{
	printf("a[0] = %d , address%p\n" , s1.a[0] , &s1.a[0]);
	printf("a[1] = %d , address%p\n" , s1.a[1] , &s1.a[1]);
	printf("b = %lld  , address%p\n" , s1.b , &s1.b);
	printf("c = %d  , address%p\n" , s1.c , &s1.c);

	return 0;
}
