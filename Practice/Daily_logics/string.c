#include	<stdio.h>
#include	<string.h>

int main(void)
{
	int i = 0;
	int j = 0;
	char s[100] = "I Am At Global Edge";
	while ( s[i] != '\0'){
		if ( s[i] == ' ') {
			j = strlen(s) - 1;
			while ( j != i) {
				s[j+2] = s[j];
				j--;
			}
			s[i] = '%';
			s[i+1]= '2';
			s[i+2]= '0';
			i = i+2;
		}
		i++;
	}
	printf("\n%s\n",s);		
}
			
