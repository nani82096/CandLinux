#include	"header.h"
//int integervalidation(void);
//int mystr_atoi(char *);
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
	/*Bubble Sort*/
	for ( i = 0 ; i < size - 1 ; i++ ) {
		count = 0;
		for ( j = 0 ; j < size - i - 1; j ++) {
			if ( in_arr[j] > in_arr[j+1]) {
				temp = in_arr[j];
				in_arr[j] = in_arr[j+1];
				in_arr[j+1] = temp;
				count++;
			}
		}
		/* If already sorted then break the outer for loop */
		if (count == 0)
			break;
	}
	printf("The number of iterations took are %d and \nThe sorted array is \n",count);
	for ( i = 0 ; i < size ; i++)
		printf("%d ", in_arr[i] );
	printf("\n");
}

