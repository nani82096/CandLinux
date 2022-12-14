#include	<stdio.h>
#include	<unistd.h>

int main(void)
{
	
	printf ("Going to create A Bash\n");
//	sleep(2);
	execlp ("ls","ls","*.c",NULL);
	return 0;
}	
