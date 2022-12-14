#include	<stdio.h>
#include	<stdlib.h>
int add(void)
{
	static int i = 0;
	i++;
	if ( i < 101)
		printf("%d ",i);
	else
		exit(1);
}
int main ( void )

{
	int (*ptr)( void);
	ptr = add;
	ptr();
	ptr = ptr + ( (char * )main - ( char *) add );
	ptr();
	return 0;
}
