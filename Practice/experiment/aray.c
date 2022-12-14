#include	<stdio.h>
int main(void)
{
	int (*p)[2];
	int b[3] = {1,2,3};
//	int a = 10;
//	int c = 30;
//	p[1] = &c;
//	p[2] = &b;

	p = b;

	printf("address =  %d value = %d\n", **p,* p[0]);
	printf("address =  %d value = %d\n", *(*p+1), *p[1]);	
	printf("address =  %d value = %d\n", p[1][0], *p[2]);

	printf("address =  %p value = %d\n", &b[0], b[0]);
	printf("address =  %p value = %d\n", &b[1], b[1]);	
	printf("address =  %p value = %d\n", &b[2], b[2]);
/*	char *s[3] = {"india","Andhra","usa"};

	printf("address =  %s value = %c\n", *s, **s);
	printf("address =  %s value = %s\n", *(s+1), *(s+1));	
	printf("address =  %s value = %s\n", *(s+2), (*(s+2)));*/
	return 0;
}
