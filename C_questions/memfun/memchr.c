#include	<stdio.h>
#include	<string.h>
int main(void)
{
	char *src = "Hello World!";
	int c = 'o';
	
	printf ("src = %s \n",src);
	src = memchr(src, c, 5);
	printf ("src = %s \n",src);
	src = memrchr(src, c, 4);
	printf ("src = %s \n",src);
	return 0;
}
