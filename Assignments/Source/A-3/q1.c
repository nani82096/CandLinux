#include	"hdr2.h"

int main(void)

{
	int choice;
	int n;
	int value;
	char *src = NULL;
	char *dst = NULL;
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
	
/*	printf("Enter the Source String:::");
	if (fgets(src, SIZE , stdin) == NULL ) {
		printf("Input is not taken::\n");
		return 0;
	}
	src[mystrlen(src)-1] = '\0';

	printf("Enter destination string\n");                                     
	if (fgets(dst, SIZE , stdin) == NULL ) {
		printf("Input is not taken::\n");
		return 0;
	}
	dst[mystrlen(dst)-1] = '\0'; 
*/	
	while (1) {
		printf("-------------Menu--------------------\n\n\n"
			"Enter 1 For string copy\n"
			"Enter 2 For copy n bytes of string\n"
			"Enter 3 For concatenate n bytes of string 2 to string 1\n"
			"Enter 4 For comparing n bytes of string 1 to string 2\n"
			"Enter 5 For finding last occurance of character\n"
			"Enter 6 For finding number of bytes in the initial segment of s which consist only of bytes from accept\n"
			"Enter 7 for number of bytes in the initial segment of s which are not in the string reject.\n"
			"Enter 8 For string tokenization :\n"
			"Enter 9 For string case comparision :\n"
			"Entter 10 For to find the first occurrence in haystack of any of the entire sequence of characters specified in needle\n"
			"Enter 0 For Exit\n\n");
		choice = integervalidation();
		__fpurge(stdin);
		switch(choice) {

			case 1:
				printf("Enter the Source String:::");
				if (fgets(src, SIZE , stdin) == NULL ) {                                              
					printf("Input is not taken::\n");                                                 
					return 0;                                                                         
			    }                                                                                     
				src[mystrlen(src)-1] = '\0'; 
				dst = mystrcpy(dst, src);                                                             
				
			    printf("after the string copy::: %s\n", dst);
				break;
			case 2:
				printf("Enter the Source String:::");                                                 
			    if (fgets(src, SIZE , stdin) == NULL ) {                                              
			        printf("Input is not taken::\n");                                                 
			        return 0;                                                                         
			    }                                                                                     
			    src[mystrlen(src)-1] = '\0'; 
				printf("Enter number of chars to copy:::");
				n = integervalidation();
				dst = mystrncpy(dst, src, n);                                                             
			    printf("after the string copy of %d charecter::: %s\n", n, dst);
				break;
			case 0:
				return 0;
			case 3:
				printf("Enter the Source String:::");                                                 
			    if (fgets(src, SIZE , stdin) == NULL ) {                                              
			        printf("Input is not taken::\n");                                                 
			        return 0;                                                                         
			    }                                                                                     
			    src[mystrlen(src)-1] = '\0'; 
			    printf("Enter the destination String:::");                                                 
			    if (fgets(dst, SIZE , stdin) == NULL ) {                                              
			        printf("Input is not taken::\n");                                                 
			        return 0;                                                                         
			    }                                                                                     
			    dst[mystrlen(dst)-1] = '\0';  
				printf("Enter number of chars to copy:::");                             
                n = integervalidation();                                  
				dst = mystrncat(src, dst, n);                                             
                printf("\nafter the string catenation of %d charecter::: %s\n\n", n, dst);        
                break;
			case 4:
				printf("Enter the Source String:::");                                     
                if (fgets(src, SIZE , stdin) == NULL ) {                                  
                    printf("Input is not taken::\n");                                     
                    return 0;                                                             
                }                                                                         
                src[mystrlen(src)-1] = '\0';                                              
                printf("Enter the destination String:::");                                
                if (fgets(dst, SIZE , stdin) == NULL ) {                                  
                    printf("Input is not taken::\n");                                     
                    return 0;                                                             
                }                                                                         
                dst[mystrlen(dst)-1] = '\0';                                              
                printf("Enter number of chars to compare:::");                               
                n = integervalidation();                                                  
                value = mystrncmp(src, dst, n);                                             
                printf("\nafter the string comparision of %d charecter::: %d\n\n", n, value);
                break;

			case 5:
				printf("Enter the Source String:::");                                     
                if (fgets(src, SIZE , stdin) == NULL ) {                                  
                    printf("Input is not taken::\n");                                     
                    return 0;                                                             
                }                                                                         
                src[mystrlen(src)-1] = '\0';
				int ch;
				printf("Enter the charecter to found::");
				ch = getchar();                                                 
                src = mystrrchr(src, ch); 
				int l2 = mystrlen(src);                          
                if ( l2 > 0)
					printf("\nafter the last occurance of '%c' the string is ::: %s\n\n", ch, src);
				else 
					printf("\nNo match found\n");
                break;
			case 6:
				printf("Enter the Source String:::");                                     
                if (fgets(src, SIZE , stdin) == NULL ) {                                  
                    printf("Input is not taken::\n");                                     
                    return 0;                                                             
                }                                                                         
                src[mystrlen(src)-1] = '\0';
				printf("Enter the Accept  String:::");                                
                if (fgets(dst, SIZE , stdin) == NULL ) {                                  
                    printf("Input is not taken::\n");                                     
                    return 0;                                                             
                }                                                                         
                dst[mystrlen(dst)-1] = '\0';                                                          
                value = mystrspn(src, dst);                                                 
                printf("\nNumber of chars found from starting of source string that are in accept string is::: %d\n\n", value);
                break;      
			case 7:
				printf("Enter the Source String:::");                                     
                if (fgets(src, SIZE , stdin) == NULL ) {                                  
                    printf("Input is not taken::\n");                                     
                    return 0;                                                             
                }                                                                         
                src[mystrlen(src)-1] = '\0';                                              
                printf("Enter the Reject  String:::");                                    
                if (fgets(dst, SIZE , stdin) == NULL ) {                                  
                    printf("Input is not taken::\n");                                     
                    return 0;                                                             
                }                                                                         
                dst[mystrlen(dst)-1] = '\0';                                              
                value = mystrcspn(src, dst);                                               
                printf("\nNumber of chars found from starting of source string that are not in reject string is::: %d\n\n", value);
                break;

			case 8:
				printf("Enter the Source String:::");                                     
                if (fgets(src, SIZE , stdin) == NULL ) {                                  
                    printf("Input is not taken::\n");                                     
                    return 0;                                                             
                }                                                                         
                src[mystrlen(src)-1] = '\0';                                              
                printf("Enter the Reject  String:::");                                    
                if (fgets(dst, SIZE , stdin) == NULL ) {                                  
                    printf("Input is not taken::\n");                                     
                    return 0;                                                             
                }                                                                         
                dst[mystrlen(dst)-1] = '\0';				

				char *token;
				//char *token = (char*) malloc(SIZE*sizeof(char)) ;
				/* get the first token */
				token = mystrtok(src, dst);
   
				/* walk through other tokens */
				while( token != NULL ) {
					printf( "%s\n", token );
					token = mystrtok(NULL, dst);
				}
				free (token);
				break;	
			case 9:                                                                       
                printf("Enter the Source String:::");                                     
                if (fgets(src, SIZE , stdin) == NULL ) {                                  
                    printf("Input is not taken::\n");                                     
                    return 0;                                                             
                }                                                                         
                src[mystrlen(src)-1] = '\0';                                              
                printf("Enter the Reject  String:::");                                    
                if (fgets(dst, SIZE , stdin) == NULL ) {                                  
                    printf("Input is not taken::\n");                                     
                    return 0;                                                             
                }                                                                         
                dst[mystrlen(dst)-1] = '\0';
				value = mystrcasecmp(src, dst);                                           
                printf("\nafter the string case comparision of both strings::: %d\n\n", value);
                break;
			case 10:
				printf("Enter the Haystack String:::");                                     
                if (fgets(src, SIZE , stdin) == NULL ) {                                  
                    printf("Input is not taken::\n");                                     
                    return 0;                                                             
                }                                                                         
                src[mystrlen(src)-1] = '\0';                                              
                printf("Enter the Needle  String:::");                                    
                if (fgets(dst, SIZE , stdin) == NULL ) {                                  
                    printf("Input is not taken::\n");                                     
                    return 0;                                                             
                }                                                                         
                dst[mystrlen(dst)-1] = '\0';
				char *ret;
				ret = mystrstr(src, dst);
				printf("The substring is: %s\n", ret);			
				break;
			default:
				printf("Enter valid number in the limit of above\n\n");
				break;	
		}

	}
	free (src);
	free (dst);
	return 0;

}
