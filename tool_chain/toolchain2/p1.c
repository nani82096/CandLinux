#include	<stdio.h>

int a;			/*uninitialised global*/
int b = 10;		/*Initialised global*/

static int c = 10;	/*initialised file static*/
static int d;		/*Unitialised file static*/
const int h = 20;
const int i;
static const int m = 10;
static const int n;
int main(void)
{
	static int e = 10;	/*initialised function static*/
	static int f;		/*Uninitialised function static*/
	const int g = 10;
	const int j;
	static const int k;
	static const int l = 10;
	register o;
	return 0;
}
