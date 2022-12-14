#include	<stdio.h>

int main(int argc, char *argv[])
{
	char *str = argv[1];
	char *str1 = str;

	while ( *str ){
		if (isupper(*str))
			*str = ('Z' - (('Z' - *str)+1) % 26);
		else if (islower(*str))
			*str = ('z' - (('z' - *str)+1) % 26);
		str++;
	}
	printf ("string = %s\n", str1);

	return 0;
}
