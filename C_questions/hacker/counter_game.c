#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    unsigned long long int N;
    int count = 0;
    scanf ("%d", &T);
    while(T <= 10 && T--){
        scanf("%lld",&N);
        count = 1;
        while (N > 1){
            if ((N&N-1)){
				N = N & N-1;
            	count++;
            }else{
                N = N/2;
            	count++;
			}
            printf ("N = %lld\n", N);
        }
        if (count % 2 == 0 )
            printf ("Richard\n");
        else 
            printf ("Louise\n");
    }
    return 0;
}
