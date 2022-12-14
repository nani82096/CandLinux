/*
 *
 * Better Understanding of Fwrite read hexdump::: analyse it 
 *
 */
#include	<stdio.h>

int main(void)
{

	FILE *fp;

	fp = fopen ("2.txt","wb+");

	int a[3] = {53,53,53};
	
	fwrite ( a, sizeof(a) , 1, stdout );
	
	fwrite ( a, sizeof(a) , 1, fp );

	fclose (fp);
	/*
	 * Reading into another buffer
	 */
	fp = fopen ("2.txt", "rb+");
	
	int b[3];

	fread ( b, sizeof(b), 1, fp );
	
	printf("\nAfter the fread array\n%d, %d, %d\n", b[0], b[1], b[2] );

	fclose (fp);
	
	return 0;

}
