#include	<stdio.h>
#include	<limits.h>
int main(void)

{
	FILE *fp;
	fp = fopen("2.txt","rb+");

//	char str[10] = "India";	
	struct a {
		int b;
	}bb;
	struct a *ptr = &bb;
	struct a *ptr1 = NULL;
	ptr1 = (struct a *) (malloc(sizeof(struct a)));
	ptr->b = 65;
//	fwrite ( ptr, sizeof(struct a) , 1, stdout);
	fwrite ( ptr, sizeof(struct a) , 1, fp);
//	fwrite ( str, sizeof(str) , 1, stdout);

	fclose(fp);
	fp = fopen("2.txt","rb+");
	fread ( ptr1, sizeof(struct a) , 1, fp);
	printf ("\n%d\n",ptr1->b);
	fclose (fp);

//	fprintf (stdout , "%d,%d,%d",a[0],a[1],a[2]);
//	fprintf (fp, "%d,%d,%d",a[0],a[1],a[2]);
	
	return 0;

}
