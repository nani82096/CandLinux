#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int sma(int *a, int n)
{
    int small = 0;
    int i;
    for (i = 0; i < n ; i++){
        if (a[i] > 0){
            small = a[i];
            break;
        }
    }
    for (i = 0 ; i < n; i++){
        if (a[i] != 0 && small > a[i])
            small = a[i];
    }
    return small;
}

int main(){
    int n; 
    scanf("%d",&n);
    int arr[n];
    for(int arr_i = 0; arr_i < n; arr_i++){
       scanf("%d",&arr[arr_i]);
    }
    int count = n;
    int small = 0;
    while (count > 1 ){
        printf ("%d\n",count);       
        small = sma(arr,n);
        //printf ("small = %d\n",small);
        for (int i = 0; i < n; i++){
            if (arr[i] > 0){
                arr[i] = arr[i] - small;
                if (arr[i] == 0){
                    count--;
                }
            }
        }
         
    }
    
    count ? printf ("%d\n",count):0;
    
    return 0;
}

