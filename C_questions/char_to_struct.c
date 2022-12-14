#include	<stdio.h>

struct aa  {
	
	char a[6];

	char b[6];
	
	};
struct bb{
	char c;
	char d;
	char ttl;
	char dd[4];
	int ee;
	};

int main(void)
{
	char buff[100] = "Hello Dude how are 172.16.5.238";

	struct aa str;

	struct bb strr;

	strncpy(str.a, buff, 6);

	printf ("String = %s\n", str.a);

	strr.ttl = buff[14];

	char (*p)[17] = buff+18;

	printf ("%c\n", strr.ttl);

	strncpy(strr.dd, p, 3);

	printf ("string = %s\n", strr.dd);

	return 0;
}
