#include <stdio.h>
#define SIZE 4

int main(char *argv[],int argc)
{
	char list[4]={'a','b','c', 'd'};
	int i,j,k,l;
	for(i = 0; i < SIZE; i++ )
		for(j = 0; j < SIZE; j++)
			for(k = 0; k < SIZE; k++)
				for(l = 0;l < SIZE; l++)
				
					if(i != j && j != k && i != k && i != l && j != l && k!= l)
						printf("%c%c%c%c\n", list[i], list[j],list[k],list[l]);
	return(0);
}
