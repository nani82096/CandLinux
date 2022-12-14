#include	<stdio.h>
int main(int argc, char *argv[])
{
	if ( argc != 2 ){
		printf ("Usage < %s > < file >\n", argv[1]);
		return 0;
	}

	FILE *fp = fopen(argv[1], "r+");
	int c ;

	if (fp == NULL){
		printf ("file open error\n");
		return 0;
	}
	while ( (c = fgetc(fp)) != EOF){
		if (isalpha(c)) {
			c ^= 32;

		fseek(fp, -1, 1);
		fputc(c, fp);}
	}
	fclose(fp);
	return 0;
}
