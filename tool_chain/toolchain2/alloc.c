#include	<stdio.h>
int main(void)
{
	int *p = NULL;
	while (1){
		p = (int *) malloc(sizeof(int) * 100);
		printf ("Hello\n");
	}
	return 0;

}
