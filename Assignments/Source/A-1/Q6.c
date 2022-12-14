/*	Name :: Veera
	Batch:: B80

Entab program that converts input string with minimum number of tabs by replacing the blanks

*/

#include	"hdr1.h"

int main(void)

{
	int i = 0;
	int sp_count;
	int len;
	int t = 0;
	int c;

	while ( ( ( c = getchar() ) != EOF ) && c != '\n' )
		line[i++] = c;
	line[i] = '\0';

	len = strlen(line);

	printf("\n\nThe length of string is %d and string is %s\n\n", strlen(line), line); 
	
	sp_count = 0;
		
	for ( i = 0; i < len; i++) {
	
		if ( line[i] == ' ')
			sp_count++;

		if ( line[i] != ' ')
			sp_count = 0;
		
		if ( sp_count == 4){
			i = i - 3;
			len = len - 3; 
			line [i] = '\t';
			for ( t = i +1 ; t < len; t++) {
		
				line[t] = line[t+3];			
			}
			sp_count = 0;

			line[len] = '\0';	
		}
		
	
	}
	
	printf("\n\nThe length of string is %d and string is %s\n\n", strlen(line), line);
	return 0;

}
