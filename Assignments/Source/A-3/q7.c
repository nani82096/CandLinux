#include	"hdr2.h"

int main(void)
{
	FILE *fptr;
	fptr = fopen("q7_file.c","r");  /*opening the file*/
	if (fptr == NULL){
		printf("Error in opening file\n");
		exit(1);
	}
	fseek( fptr, 0, 0);			/*moving file pointer to starting positon*/
	fseek( fptr, 0, 2);			/*Moving file pointer to last position*/
	char *str;
	int size;
	size = ftell( fptr );		/*assiging the fptr position to size*/
	rewind(fptr);
	str = (char *)malloc( (size+1)*sizeof(char) );
	fread( str, size+1, 1, fptr);		/*reading the file into a string*/
	char *temp = str;
	int brace = 0;
	int brack = 0;
	int paren = 0;
	while ( *temp){
		if ( *temp == '{')
        	--brace;
    	else if ( *temp == '}')
        	++brace;
    	else if( *temp == '(')
       		--brack;
   		else if( *temp == ')')
        	++brack;
    	else if( *temp == '[')
        	--paren;
	    else if( *temp == ']')
			 ++paren;
		temp++;
	}
	if ( brace != 0 )
		printf("\nUnequal braces\n");
	if ( brack != 0)
		printf("\nUnequal brackets\n");
	if ( paren  != 0)
		printf("\nUnequal parenthesis\n");
	return 0;
}
