#include	"header.h"

int main(void)

{
	FILE *fp;
	char *str;
	if ( (str = (char *)malloc(sizeof(char)*200)) == NULL)
		printf("Malloc failed\n");
	/*opening the file if not present opening the new file*/
	if ( (fp = fopen("file.txt","r+") ) == NULL ) {
		fp = fopen("file.txt","w");
	}
	if ( fgets(str,200,fp) == NULL){
		printf("No data in file\n");
		return 0;
	}
	/*assigned last newline character to null*/
	if (str[strlen(str)-1] == '\n')
		str[strlen(str)-1] = '\0';
	printf("Before changing  file Contents are\n\n%s\n", str);
	char *temp = str;
	/*changing the case of each letter by using their ascii numbers*/
	while(*str) {

		if ( (*str >= 'A') && (*str <= 'Z') ) 
			*str = (*str + 32);

		else if ( (*str >= 'a') && (*str <= 'z') )
			*str = (*str - 32);
		str++;
	}
	printf("After changing contents of the file are\n\n%s\n", temp);
	/*rewriting into the file*/
	rewind(fp);
	fputs(temp,fp);
	fclose(fp);
	return 0;
}
