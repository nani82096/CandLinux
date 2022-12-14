#include	<stdio.h>

struct A{
	int a;
	char b;
	char c;
	};

int main(void)
{
	struct A u;
	printf("member1 = %08x\t member2 = %08x member 2 = %08x \n",u.a, u.b, u.c);
	printf("PID = %d\n",getpid());
	getchar();
	return 0;
}
