#include	<stdio.h>
#include	<limits.h>

void show_bits(int, int );

int count_set (char *str)
{
	int i = 0;
	
	int count = 0;

	while(*str){
		
		i = 0;

		printf ("%c\n", *str);

		show_bits (*str, 0);		

		while ( i < CHAR_BIT) {	
			if ( (*str & (1 << i) ))
			
				count++;
			i++;
		}
			
		str++;
	}
	
	return count;
}


int main(void)
{
	char *str = "SRIHARSHA";

	printf ("number of setbits  = %d\n", count_set(str));

	return 0;

}
