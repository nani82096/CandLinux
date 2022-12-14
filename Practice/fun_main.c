#include	<stdio.h>

void func(void);
int main(void)
{
	char *a;
	a = (char *) malloc (sizeof(char)*10);
	func();
	printf("Word in Function:%s\n", a+16);
	
	return 0;

}
void func(void)
{
	char *s;
	printf ("Enter word in func");
	s = (char *) malloc (sizeof(char)*10);
	fgets(s,10,stdin);
}
