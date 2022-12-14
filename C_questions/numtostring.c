#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
void strrev( char *);
int main(int argc, char *argv[])
{
		int num = atoi(argv[1]);
		int length = 0;
		int i = 0;
		char *str = NULL;
		str = (char *)malloc(sizeof(char));

		if ( str == NULL)
				printf ("Memory allocation failed\n");
		if ( num < 0){
				num = num*-1;
				*(str+0) = '-';
				i++;
				length = length + 1;
		}
		int num_cp = num;
		while (num_cp){
				length++;
				num_cp /= 10;
		}
		num_cp = num;
		int temp = 0;
		str = realloc(str, length+1);
		if (str == NULL)
				printf ("Memory allocation failed\n");
		while ( num_cp ){
				temp = num_cp % 10;
				*(str + i) = temp + 48;
				i++;
				num_cp /= 10;
		}
		*(str+i) = '\0';
		printf ("The final string for %d is %s\n", num, str);
		(*str == '-') ? strrev(str+1) : strrev(str);
		printf ("The final strng is %s\n", str);	
		return 0;
}
