/*	Name :: Veera
	Batch:: B80
function for Question 8 and this function converts string to asci equivalent */
#include	"header.h"
int str_atoi( char *str)

{
	int sum = 0;
	int i;
	int sp_count = 0;
	
	if ( str[0] == '+') {
			
		for( i = 1; str[i] >= 48 && str[i] <=57  ; i++ ) {
					
			sum = sum*10;
			sum = sum + ( str[i] - 48 );
		}
	}

	else if ( str[0] == '-') {

		for( i = 1; str[i] >= 48 && str[i] <=57  ; i++ ) {
			
			sum = sum*10;
			sum = sum + ( str[i] - 48 );
		}
		sum = sum * -1;
	}
	
	else if  (str [0] == ' ')  {
		
		sp_count++;
		for ( i = 1; str[i] == ' '; i++ ) 
			sp_count++;
		

	
		if ( str[sp_count] == '+') {
			
			for( i = sp_count+1; str[i] >= 48 && str[i] <=57; i++ ) {
					
				sum = sum*10;
				sum = sum + ( str[i] - 48 );
			}
		}

		else if ( str[sp_count] == '-') {

			for( i = sp_count+1; str[i] >= 48 && str[i] <=57  ; i++ ) {
			
				sum = sum*10;
				sum = sum + ( str[i] - 48 );
			}
			sum = sum * -1;
		}
		
		else {
		
			for ( i = sp_count; ( str [i] >=48 && str[i] <= 57 ) ; i++) {

				sum = sum*10;
				sum = sum + ( str[i] -48 );
			}
		} 
	}
	else {
		for( i = 0; ( str[i] >= 48 && str[i] <=57 )    ; i++ ) {
			
			sum = sum*10;
			sum = sum + ( str[i] - 48 );
		}
		
	}
	return sum;

}
