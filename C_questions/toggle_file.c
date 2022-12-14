/*
 *
 * Program that Toggles All charecters in the file and write backs to it
 * Author: Sriharsha & Veera Murari
 */



#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

int main ( int a, char *b[] )
{

	if ( a != 2 ) {
		printf ("Invalid Arguments, Give as <a.out> <file_name>\n" );
		return 0;
	}

	FILE *fp = NULL;
	char *str = NULL;
	int size = 0;

	if ( NULL == ( fp = fopen ( b[1], "rb+" ) ) ) {
		printf ("Opening of file failed, Please re-run your program\n");
		return 0;
	}

	fseek ( fp, 0, 2 );
	size = ftell ( fp );

	if ( ! ( str = ( char * ) malloc ( ( size + 1 ) * sizeof ( char ) ) ) ) {
		printf ("Memory allocation Failed, Please re-run your program...!!!\n" );
		return 0;
	}

	rewind ( fp );
	fread ( str, size , 1, fp );

	char *temp = str;

	while ( *temp ) {
		if ( ( *temp != '\n' ) && ( *temp != ' ' ) )
			*temp = ((*temp) ^ 32);
		temp++;
	}
	
	rewind(fp);
	if ( ! ( fwrite ( str, size , 1, fp ) ) ) {
		printf ("Writing to file failed...!!!\n");
		return 0;
	}

	fclose ( fp );
	free ( str );

	return 0;

}

	
