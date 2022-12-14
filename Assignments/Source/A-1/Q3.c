/*	Name :: Veera
	Batch:: B80
Word count, character count and lines count program */

#include	"hdr1.h"

void main(void)
{
	int nw = 0;		/* initial words 0 */
	int nc = 0;		/* initial chars 0 */
	int nl = 0;
	int c;
	int present = 0;
	while( (c = getchar () ) != EOF ){
		++nc;			/*counting characters */
		if ( c == '\n' )
			++nl;					/*counting lines */
		if( c == ' ' || c == '\n' || c == '\t' )
			present = 0; 				/* whether we are outside the word */
		else if ( present == 0 ){
			present = 1;				/* we are in word and increasing the word count */
			++nw;
		}
	}
	printf("No of chars = %d\nNo of new lines = %d\nNo of words = %d\n ", nc, nl, nw);

}
