#include	"header.h"

int power(int a, int n)                                                         
{
	int pow = 1;
	while(n--){
		pow = pow * a;
	}
	return pow;                                                                 
}
