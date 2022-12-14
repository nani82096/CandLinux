#include    "header.h"
void merge_divide(int arr[], int low, int high)
{
	int mid;
	int temp[MAX];
	if ( low < high ) {
		mid = (low + high ) / 2;
		/*dividing the left half*/
		merge_divide( arr, low, mid );
		/*dividing the right half*/
		merge_divide( arr, mid + 1, high);
		/*merging the arrays*/
		merge_sort(arr, temp, low, mid, mid+1, high);
		
	}
	return ;
}
void merge_sort( int arr[], int temp[], int low1, int high1, int low2, int high2)
{
	int i = low1;	/*starting of first array*/
	int j = low2; 	/*starting of second array*/
	int k = low1;
	while ( (i <= high1) && (j <= high2) ) {
		/* putting first array elements in temp if less than second array else putting second array elements into temp */
		if ( arr[i] < arr[j] )
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while ( i <= high1 )
		temp[k++] = arr[i++];	/*remaining elements of first array i.e divided first array*/
	while ( j <= high2 )
		temp[k++] = arr[j++]; /*remaining elements of second array i.e divided second array*/
	/*starting from lower bound to largest bound putting temp values back into array */
	for ( i = low1; i <= high2; i++)
		arr[i] = temp[i];
	return ;
}
