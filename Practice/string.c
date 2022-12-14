#include	<stdio.h>
#include	<string.h>
#if 0
int main(void)
{
//	char a[] = "Lakshmi";
	printf("%08x\n",("Lakshmi"+1));
	printf("%c\n",*("Lakshmi"+1));
	return 0;
}

#endif

#if 0

void func(void)
{
	printf ("Exiting the func\n");
}
void mystrcpy(char *dst, char *src)
{
	while ((*dst = *src)!= '\0'){
		dst++;
		src++;
	}
}

int main(void)

{
	atexit(func);
	char a[10] = "global";
	char b[10] = "edgesiva";
	mystrcpy(b,a);
	printf("%s\n",b);
	return 0;
}

#endif
#if 0

int main(void)
{
	char *s = "Hello";
	printf (s);
}
#endif

#if 1
int main(void)
{
	char *a[10] ={"hi", "how","hello"};
	int i = 0;
	for (i = 0; i < 10; i++){
		printf ("%s",a[i]);
		fflush(stdout);
	}
	return 0;
}
#endif
