#include<stdio.h>

# if 0
int main()
{
		int * p = 0x8048423;

//		printf("Hello\n");
//		printf("Hello");
//		*p = 3456;
		
//		getchar();
		
//		printf("%d\n", *p);
		return 0;
}

# endif

#if 1 
void func()
{
	char a[2] = {6};
	char c = 4;
	char b[3] = {5, 7};

//	b[b-a + 2] = 9;
//	b[b-a + 6] = 5;
//	printf("%d\n",b-a);
	 b[b-a+1] =  23;
//	printf("Hello");
//	return ;

}
int main()
{
	int a = 10 ;
 
	func();
//	printf ("hii\n %d", a );
//printf ("hii\n %X\n", a );
	
//a = 5;

	return 0;
}
# endif


/*Try both the code snippet*/


/* Give the conclusion for the snippet 
 * Why segmentation fault*/

/* And try by removing the comments
 * Give one conclusion*/
