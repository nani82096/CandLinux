#include    "hdr2.h"                                                                      
                                                                                          
int mystrncmp(char *s, char *d, int n)                                                  
{                                                                                         
    int i = 0;
	int flag = 0;
	/* comparing n characters with src to dst*/
	for ( i = 0 ; i < n, *s == *d ; s++, d++, i++) {
		if ( *s == '\0' || i == n-1 || *d == '\0' )
			return 0;
    }
	if ( (*s - *d) > 0)
		return 1;
	else
		return -1;
}   
