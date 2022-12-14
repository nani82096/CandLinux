/*	Name :: Veera
	Batch:: B80
Histogram program of no of word length in it's input 
	here I printed both horizontal and vertical (top down and bottom up)*/

#include	"hdr1.h"

void main(void)
{
	int nw = 0;
	int nc = 0;
	int c;
	int i;
	int j;
	int lengths[MAX] = {0};
	int present = 0;
	int max = 0;
	printf("Enter the string to find The Histogra::");
	while( ((c = getchar () ) != EOF   ) && nw < MAX && c != '\n' ){	

		if( c == ' ' || c == '\n' || c == '\t' )
			present = 0;

		else if ( nw == 0 ){

			present = 1;
			++nw;
			++nc;
		}

		else if ( present == 1)
			++nc;
	
		else if ( present == 0){
 			lengths[nw] = nc;
			++nw;
			nc = 1;
			present = 1;
		}
		
	}
	lengths[nw] = nc;

	printf("\n\nNo of words %d \n",nw);

	printf("\n\nHorizontal histogram\n\n");

	for( i = 1; i <= nw; ++i){

		for(j = 0; j < lengths[i]; j++){
			printf("@");
		}
		printf("\n");	
	}

	printf("\n\nvertical histogram Botom up \n\n");

	for(i = 1; i <= nw; i++){

		if(max < lengths[i])
			max = lengths[i];
	}

	for(i = max; i > 0; i--){

		for(j = 1; j <= nw; j++){
			if( i <= lengths[j])
				printf("@");
			else
				printf(" ");
			
		}
		printf("\n");
	}

	printf("\n\nvertical histogram Top Down \n\n");

	for(i = 1; i <= max; i++){

		for(j = 1; j <= nw; j++){
	
			if( lengths[j] > 0)
				printf("@");

			else
				printf(" ");

			lengths[j]--;
		}

		printf("\n");
	}
		
	
}
