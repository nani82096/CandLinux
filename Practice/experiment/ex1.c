#include	<stdio.h>
void func(void);
#define MAX 40
int main(void)
{
	printf("%d ", MAX);
	func();
	printf("%d" , MAX);
	return 0;
}

void func(void)                                                                           
{                                                                                         
    printf("%d ", MAX);                                                                   
    #undef MAX;                                                                           
	#define MAX 232
    printf("%d ", MAX);                                                                   
    return ;                                                                              
} 
