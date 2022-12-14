#include	<stdio.h>

char *ptr ;
void strrev(char *str){
	if (*(str+1) != '\0'){
		str++;
		strrev(str);
	}
	if (*str == '\0')
		return ;
	
	*ptr = *str;
	ptr++;

}

int main(void){
	char str[] = "abcd";
	ptr = (char *)malloc(sizeof(char)*8);
	strrev(str);
	printf ("original = %s\n", str);
	ptr = ptr - 4;
	printf ("new   = %s\n", ptr);

	return 0;
}

