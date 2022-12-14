#include	<stdio.h>
int a; // COMN before linking and .bss after linking

int b = 1; // .data

static int c; // .bss

static int d = 2; // .data

const int l; // COMN before linking and .bss after linking

const int m = 3; // .rodata

static const int g; // .bss

static const int p = 4; // .rodata

volatile int v; // COMN before linking and .bss after linking

volatile int u = 11; // .data

volatile const int q; // COMN before linking and .bss after linking

volatile const int r = 8; // .data

int main(void)
{
	int n; // stack
	
	int o = 5; // stack
	
	static int x; // .bss
	
	static int y = 6; // .data
	
	const int z; // stack
	
	const int k = 7; //stack
	
	static const int i; // .bss
	
	static const int j = 9; // .rodata
	
	volatile int h; // stack
	
	volatile int s = 12; // stack
	
	volatile const int e; // stack
	
	volatile const int f = 10; // stack

	int zzzz = b;

	return 0;
}
