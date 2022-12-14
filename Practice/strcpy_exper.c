#include	<stdio.h>
#if 1 
int main(void)
{
	int a = 0x88888888;
	int b = 0x88888888;
	int d = 0x88888888;
	unsigned char c[20] ;
	strncpy(c,&a,20);
//	printf("%c\n",c);
	int i = 0;
	for( i = 0; i < 20; i++)
		printf("%d\n",c[i]);
	return 0;
}

#endif 

#if 0
int main(void)
{
	char *s[] = {"india","usa"};
	char ptr[50];

	strcpy(ptr,s);
	printf("%s\n",ptr);

	strcpy(ptr,s[1]);
	printf("%s\n",ptr);

	strcpy(ptr,s[0][1]);
	printf("%s\n",ptr);
	return 0;
}
#endif 
