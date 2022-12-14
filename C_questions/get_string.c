#include	<stdio.h>

#include	<string.h>

#include	<stdlib.h>

void get_string(char *str, int size)
{
	printf ("Enter input String::");
	
	str = fgets (str, size, stdin);

	if ( str == NULL){

		printf ("input not read\n");
		
		return ;	
	}
	
	if ( str[strlen(str)-1] == '\n')
		 str[strlen(str)-1] = '\0';
}
