
#include	<stdio.h>
#define getName(myvar) #myvar
enum a {FRM_001 = 0x18DA00FB, FRM_002 = 0x18DAFB00};
enum b {e='a',f,c,d};
int main(void)
{
	printf ("%s = %08X\n", getName(FRM_001), FRM_001);
	printf ("%s = %08X\n", getName(FRM_001), FRM_001);
	printf ("c = %d d = %d e = %d f = %d\n", c,d,e,f);
	return 0;
}
