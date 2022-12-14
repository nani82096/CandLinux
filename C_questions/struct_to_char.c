#include	<stdio.h>

struct str {

	int a ;

	int b ;

	char c[10];

	short int d;
};

int main(void)
{
	struct str st = {0x2096,0x2069,"Hello", 2};

	unsigned char buff[sizeof(st)] = "";

	memcpy(buff, &st,sizeof(st));

	printf ("a = %x b = %x c = %s d = %x\n", st.a, st.b, st.c, st.d);

	int i = 0;
	while ( i < sizeof(st)){

		printf (" %x ",buff[i]);
		i++;
	}

	unsigned char (*ptr)[4] = buff;

	printf ("first byte = %02x\n", *(*ptr));
	printf ("2nd byte =  %02x\n", *((*ptr)+1));
	char (*ptr1)[6] = buff+8;

	printf("string = %s\n",  *ptr1);
	char (*pt)[2] = buff+sizeof(st.c)+8;

	return 0;

}
