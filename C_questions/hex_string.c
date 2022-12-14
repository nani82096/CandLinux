#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

char buff[9] = "";
char *hex_to_string(unsigned int a){
	int i = 7;
	int dig = 1;
	while (a){
		if (  a % 16 >= 0 && a % 16 < 10){
			buff[i] = a % 16 + '0';
		}
		if ( ( (a % 16) >= 10 && (a % 16) < 16))
			buff[i] = ((a % 16) % 10) +  'A';	
		a = a/16;
		i--;
		dig++;
	}
	i++;
	memcpy(buff, buff+i, dig);
	return buff;
}
int power(int a, int n)
{
	int pow = 1;
	while(n--){
		pow = pow * a;
	}
	return pow;
}
unsigned int str_to_hex(char *str){
	int i = strlen(str)-1;
	unsigned int n = 0;
	while (*str){
		if ( *str >= '0' && *str <= '9')
			n = n + (((*str)-'0')*power(16,i));
		/* OR do Or or  *str >= 'a' && *str <= 'f' For small Hexa nums*/
		if ( *str >= 'A' && *str <= 'F')				
			n = n + ((((*str)-'A')+10)*power(16,i));
		i--;
		str++;
	}
	return n;
}

/*int main(void)
{
	unsigned int a = 0XBA0823a;
	char *str = hex_to_string(a);
	printf ("\nint = %X\tstring = %s\n",a, str);
	a = str_to_hex(str);
	printf ("\nstring = %s\tint = %X\n",str, a);
	return 0;
}*/
