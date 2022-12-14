#include	<stdio.h>
char *mystrcpy(char *dst, char *src)
{
	char *s = dst;
	while(*src) {
		*s++ = *src++;
	}
	*s = '\0';
	return dst;
}
int main(void)
{
	char s[] = "hi how are you";
	char d[] = "India";
	mystrcpy(s,d);
	printf("Srting == %s\n",s);
}
