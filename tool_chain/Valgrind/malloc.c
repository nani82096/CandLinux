#include	<stdio.h>
#include	<stdlib.h>
int main(void)
{
	int *s;
	int i;
	s = (int *) malloc(sizeof(int)*100);
	for(i = 0; i < 100; i++)
		s[i] = i;
	
	for(i = 0; i < 100; i++,s++)
		printf("%d ",*s);
	printf("\n");
	free(s);
}
	
