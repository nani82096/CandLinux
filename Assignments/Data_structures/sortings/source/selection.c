#include	"header.h"

int main(void)

{
	int size;
	printf("Enter the size of array");
	size = integervalidation();
	int in_arr[size];
	printf("Enter elements into array\n");
	int i;
	int j;
	int count = 0;
	int min;
	int temp;
	/* reading the elements into the array*/
	for ( i = 0; i < size; i++) {
		in_arr[i] = integervalidation();
	}
	/*Selection Sort*/
	for ( i = 0 ; i < size - 1 ; i++ ) {
		min = i;
		/*finding the minimum element in the unsorted array */
		for ( j = i+1 ; j < size ; j ++ ) {
			if ( in_arr[min] > in_arr[j])
				min = j;
		}
		/*swapping the minimum element unsorted array and first element of unsorted array*/
		if ( i != min){	
			temp = in_arr[i];
			in_arr[i] = in_arr[min];
			in_arr[min] = temp;
			count++;
		}
	}
		
	printf("The number of iterations took are %d and \nThe sorted array is \n",count);
	for ( i = 0 ; i < size ; i++)
		printf("%d ", in_arr[i] );
	printf("\n");
}

