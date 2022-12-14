#include	<stdio.h>

void show_bits (int , int );
int count_bit (int n){
	
	int cnt = 0;
	while (n){

		cnt++;

		n &= n-1;
	}
	return cnt;
}

int count_odd (int n){
	
	n = n & 0xaaaaaaaa;

	return count_bit(n);
}

int main(int argc, char *argv[]){

	if ( argc != 2){
		printf ("Usage : <%s>, <number>\n", argv[0]);
		return 0;
	}
	int a  = atoi(argv[1]);

	int count = 0;
	printf ("size = %d\n", sizeof(a));
	
	printf ("The number in binary\n");

	show_bits (sizeof(a), a);

	count = count_odd(a);

	printf ( "The number of odd bits = %d\n", count);

	return 0;
}

