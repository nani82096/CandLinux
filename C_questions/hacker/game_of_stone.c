#include	<stdio.h>
#include	<stdlib.h>

int main(void)
{

	int n,i = 0;
	printf ("Enter Stone Count:");
	scanf ("%d", &n);
	n = n % 7; 			/* This Is So Crazy Logic ... Coz for 10 it is 
						Failing so Make it around 5 not more than 7 */
	while (n){

		if ( n >= 5 ){
		i++;
			n -= 5;
			continue;
		}else if ( n >= 3){
		i++;
			n -= 3;
			continue;
		}else if ( n >= 2 ){
		i++;
			n -= 2;
			continue;
		}else
			break;
	}
	if ( (i % 2) ) 
		printf ("First\n");
	else 
		printf ("Second\n");
	return 0;
}
