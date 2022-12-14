#include	"hdr2.h"
int main(void)
{
	int n ;
	int nc ;
	char *buf;
	int nw ;
	int nlw ;
	int state = 0;
	int i ;
	printf ("enter num of characters per line \n") ;
	scanf ("%d", &n) ;
	printf("Enter the string");
	__fpurge(stdin);
	fgets(buf,SIZE,stdin);
	buf[strlen(buf)-1] = '\0';
	char *tmp = buf;
	char *t2 = buf;

	while (*buf) {
		nc = 0 ;
		while (nc < n-1 && (*tmp) )
		{
			nc++ ;
			if ( *tmp == ' ' || *tmp == '\t' ) 
				state = 0 ;
			else if (nw == 0 ) {
				state = 1 ;
				nw = 1 ;
				nlw = 1 ;
			}
			else if (state == 1) {
				nlw++ ;
			}
			else if ( state == 0) {
				nlw = 1 ;
				nw ++ ;
				state = 1 ;
			}
			tmp ++ ;
		}
		tmp-- ;
		if ( state == 1 ) {
			tmp = tmp - nlw ;
			*tmp = '\n' ;
		}
		else 
 			*tmp = '\n' ;
		buf++;
	}	
	printf("\n%s\n",t2);
	return 0 ;
}


