#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>

int main(void)
{
	int count = 1;
	char *str1;
	int a = 1;
	int j;
	int l;
	int k;
	char *temp;
	int flag = 0;
	if ( (str1 = (char *) malloc (sizeof(char)*30) ) ) { 		
		
		printf ("\nEnter String to Check for palindrome::");
		
		if( fgets (str1,30,stdin ) == NULL){
			printf ("String Input Failed\n");
			return 0;
		}
		if (str1 [strlen(str1)-1] == '\n')
			str1 [strlen(str1)-1] = '\0';

		l = strlen (str1);
		while ( a < l ) {
			          
			temp = str1;
			while( *(temp) != '\0' ) {

				j = 0;
				k = a;
				flag = 0;
				while ( j < k) {
					if ( *(temp + k) != *(temp + j))
						flag = 1;
					j++;
					k--;
				}
				if ( flag == 0){
					printf ("count = %d\t",count++);
						for ( k = 0; k <= a; k++)
							printf ("%c",*(temp+k));
						printf ("\n");
				}
				temp++;
			}	
			a++;
		}
	} else  
			printf ("Malloc failed\n");
	return 0;
}
