#include	<stdio.h>
#include	<math.h>

int main(void)
{
	int x = 255;
//	int y = -(x | ~x);
	int y = (log (x)/ log (2));
	printf ("The Right Most Set Bit = %d\n", y);

	y = -(x | -x);		
	y = (log (y)/ log (2));
	printf ("The Left Most Set Bit = %d\n", y);
	return 0;
}
