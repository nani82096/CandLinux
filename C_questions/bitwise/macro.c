#include	<stdio.h>

#define extract(m,n,r) ((m & ((~((~0) << r) )<<(n-r)))>>(n-r))

int main(void){
	
	int m = 0x48;

	int n = 7;
	
	int r = 4;

	m = extract (m,n,r);
	
	printf ("%d\n", m);

}
