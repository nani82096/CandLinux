#include	<stdio.h>

int main(void)
{
	char str[]="Global Edge";

	int i = 0;
	int len = strlen(str)-1;
	int j = len;
	int k;
	int n = 0;
	int m = 1;
	while (i < j){
		n = m;
		if (n%2){
			while((i < j) && n){
				j = len - n+1;
				k = j;
				printf ("%c", str[j]);
				j++;
				n--;
			}
		}else{
			while((i < j) && n ){
				printf ("%c", str[i]);
				i++;
				n--;
			}

		}
		j = k;
		m++;
	}
	printf ("\n");
	return 0;
}
