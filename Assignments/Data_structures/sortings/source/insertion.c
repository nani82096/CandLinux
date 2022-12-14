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
	int temp;
	/* reading the elements into the array*/
	for ( i = 0; i < size; i++) {
		in_arr[i] = integervalidation();
	}
	/*Insertion Sort*/
	for ( i = 1 ; i < size ; i++ ) {
		j = i - 1;
		temp = in_arr[i];
		/*Inserting the element when the temp is not less than in_arr[j]*/
		/*inserting between the according numbers*/
		while ( j >= 0 && temp < in_arr[j]) {
			in_arr[j+1] = in_arr[j];
			j--;
		}
		in_arr[j+1] = temp;
	}
		
	printf("The number of iterations took are %d and \nThe sorted array is \n",count);
	for ( i = 0 ; i < size ; i++)
		printf("%d ", in_arr[i] );
	printf("\n");
}



