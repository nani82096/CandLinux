
#include	<stdio.h>

#if 0
#define b 10

#ifndef b // __unix__ is typically defined when targetting Unix 
#error "Only Unix is supported"
#endif

int main(void)
{
	printf ("LINE = %s\n", __func__);
	float a = 25;
	return 0;
}
#endif 


#if defined(__x86_64__) || defined(_M_X64)
#define type 1
#elif defined(__i386) || defined(_M_IX86)
#define type 0
#endif

int main(void)
{
	type ? printf ("Intel 64 Bit\n"):printf ("Intel 32 Bit\n");
	return 0;
}
