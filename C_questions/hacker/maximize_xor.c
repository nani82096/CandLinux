#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
/*
 * Complete the function below.
 */
int maxXor(int l, int r) {
	int max = 0;
	int i,j;
	for (i = l; i <= r; i++) {
		
		for ( j = l; j <= r; j++){
				
			if ( (i ^ j) > max)
				max = (i^j);
//			printf ("%d^%d = %d, max = %d\n", i, j, (i^j), max);
		}
	}
	return max;

}
int main() {
    int res;
    int _l;
    scanf("%d", &_l);
    
    int _r;
    scanf("%d", &_r);
    
    res = maxXor(_l, _r);
    printf("%d", res);
    
    return 0;
}
