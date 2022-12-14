#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    char* time = (char *)malloc(10240 * sizeof(char));
    scanf("%s",time);
    char *temp = time;
	printf ("%c\n", *(temp+8));
/*  if (*(temp+8) == 'P'&& (*(temp+3) == '0' && *(temp+4) == '0')){
        *(temp+1) = 2 + *(temp+1);
        *(temp) = 1+*(temp);
	
    }*/
	if (*(temp+8) == 'P'){
		if ( (*(temp) == '1' && *(temp+1) == '2') && *(temp+4) != '0' ){
			*temp = '1';                                                        
        	*(temp+1) = '2';
		}else {
			if ( *(temp+1) == '8'){
				*(temp+1) = '0';
				*(temp) = '2';
			}
			else if (*(temp+1) == '9'){
				
				*(temp+1) = '1';
				*(temp) = '2';
			}
			else{  
				*(temp+1) = 2 + *(temp+1);
				*temp = 1  + *(temp);
			}
		}
	
	}else{
        if (*temp == '1'&& *(temp+1) == '2'){
            *temp = '0';
            *(temp+1) = '0';
        }
    }
    *(temp+8) = '\0';
	printf ("%s\n", time);
    return 0;
}
