#include	<stdio.h>
int mystrlen_re(char *s)
{
	static int l  = 0;
	if( *s == '\0')
		return l;
	else{
		l++;
		mystrlen_re(s+1);
		l = 0;
	}
}
int main(void)
{
	char str[20] = "Narayana";
	char str1[20] = "India";
	printf("length of %s = %d\n" ,str, mystrlen_re(str));
	printf("length of %s = %d\n" ,str1, mystrlen_re(str1));
	return 0;
}
