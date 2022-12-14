/************************
 *Author : Veera Murari  *
 *Place  : Bengaluru     *
 *						*
 ************************/




#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
char* mystrtok(char *src, char *dlm);
//char* strtok1(char *str, const char* delim); 
int main(void)
{
	char* buff = malloc(349);
	char *buff1= malloc(232);

	fgets (buff, 349, stdin);
	buff[strlen(buff)-1] = '\0';

	fgets (buff1, 232, stdin);
	buff1[strlen(buff1)-1] = '\0';

	char *token;
	//char *token = (char*) malloc(SIZE*sizeof(char)) ;
	/* get the first token */
	token = mystrtok(buff, buff1);

	/* walk through other tokens */
	while( token != NULL ) {
		printf( "%s\n", token );
		token = mystrtok(NULL, buff1);
	}
}

char* mystrtok(char *src, char *dlm)
{
	/*static pointer to point to orinal string always */
	static char *temp = NULL;
	char *temp2 = NULL;
	char *temp3 = NULL;
	if (src != NULL)
		temp = src;
	if ( *temp == '\0')
		return NULL;
	/*temp3 always points to temp temp points to src initially but changing as delimiter occurs*/
	temp3 = temp;
	int flag = 0;
	while (*temp) {
		/*temp2 pointing to delimiters string*/
		temp2 = dlm;
		while (*temp2) {
			/*if src equals to delimeters then making it to null and returning to temp3 */
			if ( (*temp) == (*temp2)){
				(*temp++) = '\0';
				flag = 1;
				if ( (temp-1) == temp3){
					temp3++;
					temp2++;
					continue;
				}  
				return temp3;	
			}
			temp2++;
		}
		if ( flag == 0)
			temp++;
		flag = 0;
	}
	if ( *temp3 == '\0')
		return NULL;
	if ( *temp == '\0' )
		return temp3;
}
