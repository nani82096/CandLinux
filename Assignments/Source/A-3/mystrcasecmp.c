#include    "hdr2.h"                                                                      
                                                                                          
int mystrcasecmp(char *s, char *d)                                                    
{                                                                                         
	/*comparing both lowercase and upper case charecters if equal returing 0*/                                                                   
    for (  ; ( (*s == *d) || (((*s) + 32 ) == *d) || (*s == ((*d) + 32 )) ) ; s++, d++) {                                      
        if ( *s == '\0' )                                       
            return 0;                                                                     
    }                                                                                     
    if ( (*s - *d) > 0)                                                                   
        return 1;                                                                         
    else                                                                                  
        return -1;                                                                        
}
