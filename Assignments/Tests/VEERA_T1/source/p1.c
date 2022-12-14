#include	"header.h"

int main(void)

{
	char *str;
	char *temp2;
	char *dummy;					/*dummty variable to store a temperary character*/
	int i;
	int j;
	str = (char *)malloc(sizeof(char)*100);
	printf ("Size of buffer = %d\n", str - 4);
	char *temp1 = str;				/*temp2 will always point to str */
	printf("Enter the line::");
	fgets(str, 100, stdin);
	i = 0;
	/*string length*/

	if ( str[strlen(str) - 1]  == '\n')
		 str[strlen(str) - 1]  = '\0'; 
	//while (str[i] != '\0')
	//	i++;

	//str[i-1] = '\0'; /* just to assign new line to null */	
	while (*str) {
		i = 0;
		temp2 = str;
		/*each word length */
		while ( (*( temp2 + i) != ' ') && (* (temp2 + i) != '\0' ) ) {
			i++;
		}
		j = i - 1;
		i = 0;
		/*swapping word character by character */
		if ( i < j) {
			while ( (*( temp2 + i ) != ' ') && ( *(temp2 + i ) != '\0') ) {
				if ( i < j){
					*dummy = *(temp2 + i);
					*(temp2 + i) = *( temp2 + j);
					*(temp2 + j) = *dummy;
				}
				i++;
				j--;
			}
		}
		/*moving to next word i.e moving pointer to next word*/
		temp2 = temp2 + i;
		str = temp2;
		str++;
	}
	/*printing the char*/
	printf("\n\n%s\n\n", temp1);
	/* doing the extra that printing from the reverse*/
	i = 0;
	while(*(temp1+i)) {
		i++;
	}
	i = i - 1;
	j = 0;
	while(i > j){
		*dummy = *(temp1+i);
		*(temp1+i) = *(temp1 + j);
		*(temp1+j) = *dummy;
		i--;
		j++;
	}
	printf("%s\n",temp1);
	return 0;
}
