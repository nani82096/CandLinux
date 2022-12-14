#include	<stdio.h>

//#define SIZEOF(a) 	( ( __typeof__(a) *) 0 + 1 )
  #define SIZEOF(a) 	(( (char *)(&a+1)) - (((char *) &a)) )
int main(void)
{
	char a = 3;
	printf ("size is %zu \n", SIZEOF(a));
/*	typeof (4) a = 5;
	printf ("a = %d\n", a);
	char t[20];
	strcpy(t,"indi");*/
	return 0;
}
