#include	<stdio.h>
char *str_rindex(char *str, int ch)
{
	char *temp = NULL;

	while(*str){
		
		if ( *str == (char) ch){
			
			temp = str;
			
			str++;
		
			continue;
		}
		str++;
	}

	/*int len = strlen(str);

	while(len) {

		if(ch == *(str + len))
			return (str + len);

		else
			len--;
	}
	return NULL;*/
	return temp;
}


int main(void)
{
	char str[] = "india";
	char ch = 'i';
	printf ("last occurance = %s\n", str_rindex(str, ch));
	return 0;

}
