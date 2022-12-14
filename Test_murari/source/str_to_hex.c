#include	"header.h"

unsigned int str_to_hex(char *str)
{
	int i = strlen(str)-1;
	unsigned int n = 0;
	while (*str){
		if ( *str >= '0' && *str <= '9')
			n = n + (((*str)-'0')*power(16,i));
		/* OR do Or or  *str >= 'a' && *str <= 'f' For small Hexa nums*/
		if ( *str >= 'A' && *str <= 'F')
			n = n + ((((*str)-'A')+10)*power(16,i));
		i--;
		str++;
	}
	return n;                                                                   
}
