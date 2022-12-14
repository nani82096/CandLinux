#include	<stdio.h>
	struct MB{
		char str[16][1024][1024];
		};
int main(void)
{
	int count = 0;
	struct MB *ptr = NULL;
	while ( (ptr = (struct MB*)malloc(sizeof(struct MB))) != NULL) {
		printf("%d\n",count++);
	}
	while(1);
	return 0;

}
