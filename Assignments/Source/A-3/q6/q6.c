#include	"hdr2.h"

int main(void)
{
	FILE *fptr;
	fptr = fopen("q6_file.c","r");  /*opening the file*/
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
	
	printf("\n\nBefore removing comments in the file \n\n%s\n", str);
	
	char *temp = str;
	while (*temp){
		/*removing single line comments moving until new line occurs*/
		if ( *temp == '/' && *(temp+1) == '/') {
			while ( *temp != '\n') {
				*temp = ' ';
				temp++;
			}
		}
		/*removing multi line comments moving until *'/' occurs */
		else if ( *temp == '/' && *(temp+1) == '*') {
			*temp = ' ';
			*(temp + 1) = ' ';
			temp = temp + 2;
			while ( (*temp != '*') && ( *(temp+1) != '/') ){
				*temp = ' ';
				temp++;
			}
			*temp = ' ';
			*(temp + 1) = ' ';
		}
		temp++;
	}
	printf("\n\nAfter removing the comments in file \n\n%s\n", str);
	FILE *dptr;
	dptr = fopen("q6_file_write.c","w");
	fwrite( str, size+1, 1, dptr);
	return 0;

}
