#include    "hdr2.h"                                                                      
                                                                                          
char* mystrncat(char *s, char *d, int n)
{
	char *temp = NULL;
	temp = d;
	/*going to last character of string 1*/
	while ( *d != '\0')
		d++;                               
	/*appending string 2 to string upto n chars*/                                   
	while ( (n--) && (( *d++ = *s++) ));
    *d = '\0';
    return temp; 
}   
