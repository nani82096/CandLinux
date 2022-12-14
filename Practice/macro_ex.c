#include <stdio.h>
#if 0 
#define UNCHANGEABLE_VALUE 5
#define CHANGEABLE_VALUE foo
int foo = 5;

int main() {
    printf("%d %d\n", UNCHANGEABLE_VALUE, CHANGEABLE_VALUE);
	CHANGEABLE_VALUE = 10;
    printf("%d %d\n", UNCHANGEABLE_VALUE, CHANGEABLE_VALUE);
}

#endif

#if 0 
#define MAX 20
int a = MAX;
int main(void)

{
	printf("%d\n",&a);	
	printf("%d\n",getpid());
	getchar();
	return 0;
}

#endif


#if 0 

int main( void )
{
	int a[2] = { 1,7};
	int b[3] = { 3,4,5};
	int *c[10] = { a, b};
	printf("%d\n",*(*c+1));
	return 0;
}

#endif

#if 0

#if x==0
	#define y 5
#else 
	#define y 10
#endif

int main(void)
{
	printf ("MAx =%d\n", y);
	return 0;
}

#endif
#if 0 


#define print(s) printf("this is buff <%s>\n", s);
int main(void)

{
	char *str = "Hello";
	print (str);
	return 0;
}
#endif
#if 0
int main(void)
{
	int *ptr =(int*) malloc(sizeof(int)*10);
	int *pptr;
	pptr = ptr;
	free(pptr);
	pptr = NULL;
	return 0;
}

#endif
#if 1
int main(void)
{
	int *pt = NULL;
	int count = 0;
	while(pt = (int*)malloc(1000)){
		pt = count;
		count += 1000;
		
	printf ("count  = %d\n", count);
	}
	return 0;
}
#endif
