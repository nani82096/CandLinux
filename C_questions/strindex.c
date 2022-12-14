#include	<stdio.h>

#include	<ctype.h>

char * mystrindex ( char *a , char *b )
{

	char *temp = NULL;
	char *temp1 = NULL;

	while ( *a ) {
		
		temp = b;
		temp1 = a;

		while ( *temp ) {
			
			if ( *temp != *temp1 ) 
				break;
			
			temp1++;
			temp++;
		}

		if ( *temp == '\0' )
			return a;
		a++;
	}

	return NULL;

}

int main ( void )
{

//	char *a = "India is awesome great and Ap is super";
//	char *b = "dia";

//	char *a = "Hi harsha how are you";
//	char *b = "how";

	char *a = "harsha";
	char *b = "a";
	
	printf ("The index of great in ::::%s::::\n%s\n", a, mystrindex(a, b));
	printf ("The original string = %s\n", a);
	return 0;

}

