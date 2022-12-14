#include	<stdio.h>
#include	<stdlib.h>

int main(void)
{

	char *ptr = (char *)malloc(sizeof(char)*1000);
/*	char *tmp = "abcd";
	printf ("tmp - %s\n", tmp);
	ptr = tmp;
	printf ("ptr - %s\n", ptr);
	free(ptr);
	return 0;
*/
	if ( NULL == fgets(ptr, 1000, stdin) ){
		
		printf ("fgets Failed\n");

	}
	printf ("The String is %s\n", ptr);
	return 0;
}
