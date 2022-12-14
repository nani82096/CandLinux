#include	"header.h"
int main(void)
{
	int in_arr[6];
	int i = 0;
	
	for ( i = 0; i < 6; i++)
		scanf ("%d",&in_arr[i]);
	for ( i = 0; i < 6; i++)
		printf ("%d\n",in_arr[i]);
	printf ("After \n");
	quick_sort(in_arr ,0 , 5);
	for ( i = 0; i < 6; i++)
		printf (" %d\n",in_arr[i]);
	return 0;
}
void quick_sort(int in_arr[], int low, int high)
{
	int pivloc;
	if ( low >= high)
		return;
	pivloc = partition(in_arr, low, high);
	quick_sort(in_arr, low, pivloc - 1); /*for left side sub arrays*/
	quick_sort(in_arr, pivloc + 1, high);
}
int partition( int in_arr[], int low, int high)
{
	int temp;
	int i;
	int j;
	int pivot;
	i = low + 1 ;
	j = high;
	pivot = in_arr[low];
	while ( i <= j)	 {
		while ( (in_arr[i] < pivot) && ( i < high) )
			i++;
		while ( (in_arr[j] > pivot) )
			j--;
		if ( i < j) {
			temp = in_arr [i];
			in_arr[i] = in_arr[j];
			in_arr[j] = temp;
			i++;
 			j--;
		}else
			i++;
	}
	in_arr[low] = in_arr[j];
	in_arr[j] = pivot;
	return j;
}	
