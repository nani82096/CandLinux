#include    "hdr2.h"                                                                      
                                                                                          
char* mystrcat(char *s, char *d)                                        {                                                                                         
    int i = 0;                                                                                
    char *temp = NULL;                                                                    
    temp = d; 
	/* going to last of string 1*/
	while ( *d != '\0')
		d++;                      
	/*padding string 2 to sting 1*/                                                 
    while (  (( *d++ = *s++) )){
		;                                   
    }                                                                                     
    *d = '\0';                                                                  

    return temp;                                                                          
}   
