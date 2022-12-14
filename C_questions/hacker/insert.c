#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
void insertionSort(int ar_size, int *  ar) {
    int i, j, temp,k;
    for (i = ar_size - 1 ; i >= 0; i--){
        j = i;
        temp = ar[i];
        while ( j > 0 && temp < ar[j-1]){
            ar[j] = ar[j-1];
			for ( k = 0 ; k < ar_size; k++)
				printf ("%d ", ar[k]);
			printf ("\n");
            j--;
        }
        ar[j] = temp;
		for ( k = 0 ; k < ar_size && i == 0; k++)
			printf ("%d ", ar[k]);
    }
}
int main(void) {
    int _ar_size;
    scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
        scanf("%d", &_ar[_ar_i]); 
    }

    insertionSort(_ar_size, _ar);
    return 0;
}
