#include	"header.h"
int main(void)
{
	int i = 0;
	int arr[SIZE];
	int key;
	int result;
	printf("Enter values to the array\n");
	for ( i = 0; i < SIZE; i++) 
		scanf("%d", &arr[i]);
	for ( i = 0; i < SIZE; i++) 
		printf ("%d ", arr[i]);
	printf("Enter the element to search:");
	scanf("%d", &key);
	quick_sort(arr, 0, SIZE-1);
	for ( i = 0; i < SIZE; i++) 
		printf ("%d ", arr[i]);
	result = bin_search(arr, 0, SIZE-1, key);
	if ( result != -1 )
		printf("The Element Found in the array\n");
	else
		printf("OOPS Element Not found\n");
	return 0;
}
int bin_search(int arr[],int low, int high, int key)
{
	int mid = (low+high) / 2;
	
	if ( low > high)
		return -1;
	if ( arr[mid] == key) 
		return mid;
	(arr[mid] > key) ? (high = mid - 1):(low = mid + 1);
		bin_search(arr, low, high, key);
	return 0;
}
