#include	<stdio.h>
#include	<string.h>
int palindrome(char *str)
{
	int l = strlen(str)-1;
	if (str >= (str+l))
		return 1;
	if (*str != *(str+l))
		return 0;
	str++;
	return (palindrome(str));
}
int palindrome1(char *str, int index, int size){
	if ( index >= size)
		return 1;
	if ( *(str+index) != *(str+size))
		return 0;
	return (palindrome1(str,index+1, size-1));
}
int main(void){
	char *str = "wow";
	//(palindrome(str,0,strlen(str)-1) && printf ("Palindrome\n") ) || printf ("Not Palindrome\n");
	(palindrome(str) && printf ("Palindrome\n") ) || printf ("Not Palindrome\n");
	return 0;
}
