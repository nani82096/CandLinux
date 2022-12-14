#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

void swap_char (char *, char *);

int main(void)
{
	char buff[] = "hello india AP";
	printf ("buf = %s\n", buff);
	char *ptr = buff;
	char *temp = buff;
	char *dummy = NULL;
	while (*ptr ) {
		temp = ptr;
		while ( *temp != ' ' && *temp != '\0') 
			temp++;
		dummy = temp;
		temp--;
		while ( ptr < temp ){
			swap_char (ptr, temp );
			ptr++;
			temp--;
		}
		ptr = dummy + 1;
	}
	printf ("buf = %s\n", buff);
	return 0;
}
