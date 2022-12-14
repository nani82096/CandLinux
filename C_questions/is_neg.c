#include	<stdio.h>
#include	<limits.h>

int main (void)
{
	
	switch(MAX) {
		case 0 ... INT_MAX:
			printf ("positive = %d\n", MAX);
			break;
		default:
			printf ("Negative = %d\n", MAX);
	}

	return 0;

}
