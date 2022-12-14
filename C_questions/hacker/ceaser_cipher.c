#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>

int main(){
    int n; 
    scanf("%d",&n);
    char* s = (char *)malloc(n * sizeof(char));
    scanf("%s",s);
    int k; 
    scanf("%d",&k);
    char *temp = s;
    k = k % 26;
    while ( *s){
        if (islower(*s)){
            if ( (*s + k) <= 'z' )
                *s = *s + k ;
            else //(*s > 'z')
                *s = (*s - 26) + k;
        }else if (isupper(*s)){
            if ( (*s + k) <= 'Z')
                *s += k ;
            else // ( *s > 'Z')
                *s = (*s - 26) + k;
        }
        s++;
    }
    printf ("%s\n", temp);
    return 0;
}
