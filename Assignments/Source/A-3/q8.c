#include	"hdr2.h"

int main(void)
{
	char *src = NULL;
	char *dst = NULL;
	
	int result;
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
                                                                                          
    printf("Enter second String:::");                                                 
    if (fgets(dst, SIZE , stdin) == NULL ) {                                              
        printf("Input is not taken::\n");                                                 
        return 0;                                                                         
    }                                                                                     
    dst[mystrlen(dst)-1] = '\0';

	dst = strcat(dst, dst);/* concatenating two strings*/
	src = strstr(dst, src);
	result = src - dst;
	if (result > 0)
		printf("no of rotations : %d\n\n", result);
	else 
		printf("not possible:\n\n");
	return 0;
}
