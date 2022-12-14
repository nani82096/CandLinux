#include	<stdio.h>
#include	<sys/types.h>
#include	<pwd.h>

int main(void)
{
	struct passwd *mypass;
	char *usr = "murari";
	mypass = getpwnam(usr);
	if ( NULL == mypass){
		fprintf (stdout, "User %s does not exist\n",usr);
	}else {
		fprintf (stdout, "User %s exits with UID %d.\n", usr, mypass->pw_uid);
	}
	printf ("Pass = %s\n", mypass->pw_passwd);
	return 0;
}	
