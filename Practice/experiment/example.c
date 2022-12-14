#include	<stdio.h>
//char * mystrcpy(char *,char *);
#if 1

/*int fun(int a, float b, int c, float d) {
	printf("address of a = %08x\n", &a);
	printf("address of b = %08x\n", &b);
	printf("address of c = %08x\n", &c);
	printf("address of d = %08x\n", &d);

}*/
void main(void)

{
	int a = 0x65aaaa40;
	//float b = 1.25f;
	//fun(a,b, 10,1.25);
	printf("value = %f  \n",   a);

	//scanf ("%d", &a);
	//printf ("\n\n%d\n\n", sizeof (a));
	//fflush(stdout);
	//float b = 10.2542;
	//printf("%d\n", b);
	

}
#endif

#if 0
void main(void)
{
	float a = 10;
	int *p = & a;
	int i = 0, j;
	int ch;
	for ( i = 0; i < 31; i++) {
		ch = *p;
		if ( i  % 8 == 0)
			printf("\t");
		printf("%d " ,((ch>>i)&1));
		
	 }
	
}

#endif

#if 0
int main(void)
{
	char a[] = "hi";
	char b[] = "hello";
	strcpy(a,b);
	printf("%s\n%s\n", a, b);
}

#endif


#if 0

int main(void)
{
	unsigned char a = 120;
	for ( a = 120; a <= 128; a++) 
		printf("%d ", a);
	return 0;
}

#endif
