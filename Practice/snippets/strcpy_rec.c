#include	<stdio.h>

void mystrcpy_r( char *dst, char *src)
{
	if ( *dst == '\0' && *src == '\0')
		return ;
	else {
		*dst = *src;
		dst++;
		src++;
		mystrcpy_r(dst, src);
	}
	return ;
}

void mystrcat_r( char *dst, char *src)
{

	if ( *dst ) {
		dst++;
		mystrcat_r(dst , src);
	}
	else{ 
		if (*dst++ = *src++)
			mystrcat_r(dst, src);
		else
			return; 
	}
}
int main(void)
{
	char src[20] = "india";
	char dst[20] = "uunited"; 
	mystrcpy_r(dst, src);
	printf ("dst = %s\n", dst);

	return 0;

}

