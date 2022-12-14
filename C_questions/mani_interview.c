#include	<stdio.h>
int main(void)
{
	int i = 0;
	int arr[] = {1,0,0,1,0,1,0,0,1,1,0,1};
	int j = (sizeof(arr)/sizeof(arr[0])) - 1 ;
	int temp = 0;
	for(i = 0; i < j; ){
		if (arr[i] == 1)
			i++;
		if (arr[j] == 0)
			j--;
		if (arr[i] != 1 && arr[j] != 0){
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}

	for(i = 0 ; i < (sizeof(arr)/4) ; i++){
		printf ("%d ", arr[i]);
	}
	

	printf ("\n");
	return 0;
}
