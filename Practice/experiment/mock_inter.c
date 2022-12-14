#include	<stdio.h>
#include	<stdlib.h>
#if 0
void main()
{
	char *p;
	p = malloc(sizeof(char)*20);
	printf("%p\n", p);
	p++;
	printf("%p\n", p);
}

#endif

#if 1
int main(void)
{
	char *p;
	p = malloc(sizeof(char)*10);
	char *temp = p;
	char *q = malloc(sizeof(char)*10);
	p = realloc(p,sizeof(char)*25);
		
	printf("%p\n", (temp));
	printf("%p\n", (q));
	printf("%p\n\n", (p));
	temp = NULL;
	temp = malloc(sizeof(char)*20);
	
	printf("%p\n", (temp));
	printf("%p\n", (q));
	printf("%p\n\n", (p));


	
	free(p);
	printf ("Temp freed\n");
	free(q);
	printf ("q freed\n");
	free(temp);
	printf ("p freed\n");
	return 0;
}

#endif


#if 0
int main(void)
{
	char *p;
	p = malloc(10);
	char *q = malloc(10);
		

	int i;

	for(i=0; i<12; i++) {
		*(p+i) = i + 1;
		*(q+i) = i + 2;
	}

	for(i=-8; i<40; i++)
		printf("\n %d ", *(p+i) );
 	
//	free(temp);
//	free(q);
//	free(p);
	return 0;
}

#endif
