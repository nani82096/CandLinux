#include	<stdio.h>

int main (void)
{
	
	((MAX >> 31 ) & 1) || printf("Positive\n");
	((MAX >> 31 ) & 1) && printf("Negative\n");
//	((MAX >> 31 ) & 1) && printf("Negative\n") || printf("+ve");
//	!(((MAX >> 31 ) & 1) && printf("Negative\n")) && printf("+ve");
	return 0;

}
