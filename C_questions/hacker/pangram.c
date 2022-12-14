#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
int count[26];
int main(void) {

    int c = 0;
    int i = 0;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char str[10*10*10];
    if (fgets(str, 1000, stdin) == NULL)
        printf ("failed to get input");
    if ( str[strlen(str)-1] == '\n')
        str[strlen(str)-1] = '\0';
    while (*(str+i)){
		//if (isalpha(*(str+i))){
		if ((*(str+i) >= 'A' && *(str+i) <= 'Z') || (*(str+i) >= 'a' && *(str+i) <= 'z')){
			if (*(str+i) >= 'A' && *(str+i) <= 'Z')
            	*(str+i) ^= 32;
            count[(*(str+i))-'a'] = 1;
        }
        i++;
    }
    i = 0;

    while (i < 26){
        c = count[i] + c;
		i++;
    }
    if ( c == 26)
        printf ("pangram\n");
    else
        printf ("not pangram\n");
  
    return 0;
}

