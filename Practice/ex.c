#include	<stdio.h>
void main(void)

{

	int a[5] = { 1,2,3,4,5};
	int *b;
	int i;
	b = &a[0];

		//printf("%d\n",*
	for ( i = 0 ; i < 5 ; i++)

		printf(" %d ----%p\n ", *(b+i), b+i);
	for ( i = 0 ; i < 5 ; i++)                                                            
        printf(" %d ----%p\n ", a[i], &a[i]);    

	printf ("Atoi(9999999999) =%d\n",atoi("-923"));
	return 0;
}
