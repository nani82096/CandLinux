#include	"header.h"
int main(void)
{
	int i = 0;
	int arr[SIZE];
	int key;
	int result;
	printf("Enter values to the array\n");
	for ( i = 0; i < SIZE; i++) 
		scanf("%d", & arr[i]);
	printf("Enter the element to search");
	scanf("%d", &key);
	result = search(arr, SIZE, key); 
	if ( result != -1 )
		printf("%d is the location of element in the array\n", result);
	else
		printf("OOOPS Not found\n");
}
int search(int arr[], int size, int key)
{
	int i = 0;
	for (i = 0; i < size; i++){ 
		if ( arr[i] == key)
			return i;
	}
	if ( i == size)
		return -1;
	
}
