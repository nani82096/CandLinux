#include	<stdio.h>
#include	<unistd.h>
int main(void)
{
	int status = 0;
	pid_t pid = fork();
	if (pid > 0){
		printf ("In Parent\n");
		wait(&status);
		printf ("Value of status = %d %d\n", pid, status);
	}
	else if ( pid == 0 ){
		printf ("In Child\n");
		return 8;
	}else
		printf ("Fork Failed\n");

	return 0;
}
