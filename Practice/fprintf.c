#include	<stdio.h>
int main(void){
	int a[2] = {65535,15};

	FILE *fp = fopen("file.txt", "w");

	

	//fprintf (fp, "%d\n%d",a[0], a[1]);

//	fwrite (a, 8, 1, fp);

unsigned	char *ptr = a;
	
	printf ("1st byte = %d\n", *ptr++);
	printf ("2st byte = %d\n", *ptr++);
	printf ("3st byte = %d\n", *ptr++);
	printf ("4st byte = %d\n", *ptr++);
	printf ("5st byte = %d\n", *ptr++);
	printf ("6st byte = %d\n", *ptr++);
	printf ("7st byte = %d\n", *ptr++);
	printf ("8st byte = %d\n", *ptr++);

	return 0;
}
