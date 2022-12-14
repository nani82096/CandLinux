#include	<stdio.h>
#include	<stdio.h>
int add(int a)
{
	return a;
}
int sub(int b){
	return b;
}
int (*num[6])(int ) = {
	[0 ... 2] = add,
	[3 ... 5] = sub
};
int main(void)
{

	printf(" num[1] = %d\n", num[1](11));
	printf(" num[2] = %d\n", num[2](12));
	printf(" num[3] = %d\n", num[3](13));
	printf(" num[4] = %d\n", num[4](14));
	return 0;

}
