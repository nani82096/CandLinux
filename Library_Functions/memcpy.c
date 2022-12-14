#include	<stdio.h>

int main(void)
{

	char s1[] = "harsha";
	char s2[] = "sri";
	memcpy(s2,s1,6);
	printf ("s2: %s\n", s2 );
	return 0;
}
