#include <stdio.h>

#include <stdlib.h>

#include	<string.h>

void get_string(char *, int);
//#define N 3
void permute(char list[],int k, int m)
{
	static int count = 1;

	int i;
	
	char temp;
	
	if (k == m){
		/* PRINT A FROM k to m! */
		printf ("%d\t%s\n",count++, list);
	} else {
		for(i=k;i<m;i++) {
		/* swap(a[i],a[m-1]); */
						
			temp=list[i];
					
			list[i]=list[m-1];
				
			list[m-1]=temp;
				
			permute(list,k,m-1);
				/* swap(a[m-1],a[i]); */
			temp=list[m-1];
		
			list[m-1]=list[i];
		
			list[i]=temp;
		}
	}
}
int main(int argc, char *argv[])
{

	if ( argc != 2 )
		
		printf ("Usage <%s> <size of string> \n", argv[0]);


	int size = atoi(argv[1]);

	char list[size];

	get_string(list,size );

	printf ("line = %s\n", list);
	
	permute(list,0,strlen(list));
	
	return 0;
}
