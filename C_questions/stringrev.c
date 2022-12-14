#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

void swap_char( char *temp1, char *temp2)
{
	*temp1 = *temp1 ^ *temp2;
	*temp2 = *temp1 ^ *temp2;
	*temp1 = *temp1 ^ *temp2;
		
	return; 
}
void strrev ( char str[], int index, int size)
{
	if (  index >= size)
		return ;

	swap_char( str+index, str+size);
	strrev(str, index+1, size-1);
}

void strrev2 ( char str[], int index, int size)
{
	if (index == size/2)
		return ;

	swap_char( str+index, str+(size-index));
	strrev2(str, index+1, size);
}


void strrev1(char *str){
	static char *temp1 = NULL;
	static char *temp2 = NULL;
	if ( str != NULL ){
		temp1 = str;
		temp2 = (str + (strlen(str) - 1 ));
	}
	if ( temp1 == temp2 ||  temp1 > temp2 )
		return ;
	else{
		swap_char(temp1++, temp2--);		/* Not a Good practice to use ++ operators in function call, it is implementation depends */
//		temp1++;
//		temp2--;
		strrev1 (NULL);
	}
	return ;
}

int main (void)
{
	char str[] = "hello";
	printf ("string rev = %s\n", str); 
	strrev(str,0, strlen(str)-1);
	printf ("string rev = %s\n", str); 
	
	return 0;
}
