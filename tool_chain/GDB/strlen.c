#include	<stdio.h>

char *mystrlen(char *s)
{
	while(*++s);
	return s;
}
int main(void)
{
	char d[100];
	scanf("%s",d);
	printf("Length of the String = %d\n", (mystrlen(d) - d ) );
	return 0;
}
