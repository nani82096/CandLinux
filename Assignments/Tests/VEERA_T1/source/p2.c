#include	"header.h"
int main(void)
{

	int i = 0;
	int j = (sizeof(int)*8) - 1;
	printf("Enter a number::");
	unsigned int n;
	int count = 0;
	scanf("%d", &n);
	/*comparing from last to first bit by bit*/
	while ( i < j){
		if ( ((n >> i) & 1) == ((n >> j) & 1) )
			count++;
		i++;
		j--;
	}
	/*if all equals then count will be 16 */
	if ( count == 16)
		printf("Given number is Bit Wise palindrome\n");
	else 
		printf("Given number is Not a Bit Wise palindrome\n");
} 
