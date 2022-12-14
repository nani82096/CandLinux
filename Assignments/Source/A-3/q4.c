#include	"hdr2.h"

int main(void)
{
	char *src = NULL;
	char *dst = NULL;
	
	char *result = NULL;
	src = (char *) malloc(sizeof(char)*SIZE);                                             
    dst = (char *) malloc(sizeof(char)*SIZE);                                             
    if (src == NULL) {                                                                    
        printf("Memory not allocated\n:::");                                              
        return 0;                                                                         
    }                                                                                     
    if (dst == NULL) {                                                                    
        printf("Memory not allocated\n:::");                                              
        return 0;                                                                         
    }

	printf("Enter the first String:::");                                                 
    if (fgets(src, SIZE , stdin) == NULL ) {                                              
        printf("Input is not taken::\n");                                                 
        return 0;                                                                         
    }                                                                                     
    src[mystrlen(src)-1] = '\0';                                                          
                                                                                          
    printf("Enter second string\n");                                                 
    if (fgets(dst, SIZE , stdin) == NULL ) {                                              
        printf("Input is not taken::\n");                                                 
        return 0;                                                                         
    }                                                                                     
    dst[mystrlen(dst)-1] = '\0';

	result = squeeze(src, dst);

	printf("The squeezed string is %s\n\n", result);
	return 0;
}
