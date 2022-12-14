#include	<stdio.h>
#include	<stdlib.h>

int main ( void ) {

	int a[2] = { 10, 20 };

	FILE *fp1 = fopen ( "f1.txt", "w+" );
	FILE *fp2 = fopen ( "f2.txt", "w+" );

	fprintf ( fp1, "%d%d", a[0], a[1] );

	fwrite ( a, sizeof ( int ), 2, fp2 );

	return 0;

}
