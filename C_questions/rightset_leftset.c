#include	<stdio.h>
#include	<math.h>

int main(void)
{
	int x = MAX;
/*	int y = -(x | ~x);
	int y = (log (x)/ log (2));
*/	
	int y = log2(x);
	printf ("The Right Most Set Bit = %d\n", y);

/*	y = -(x | -x);		
	y = (log (y)/ log (2));
*/
	y = log2(x & -x);
	printf ("The Left Most Set Bit = %d\n", y);
	return 0;
}
