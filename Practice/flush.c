#include	<stdio.h>

		/*
		 *
		 *
		 *Execute by commenting each 
		 *i.e fflush once and fpurge once to understand the functionality of both
		 *
		 *
		 */
			


int main(void)
{

	/* fflush */
	/*
	printf ("Hello");									//Try %s\n once and without once and execute witout fflush and with fflush
	fflush (stdout);
	printf ("%s",1);
	*/


	/* __fpurge */

	char str[10];
	char str1[10];

	printf ("Enter the input string1:\n");			/*Try giving more than 10 chars and understand the functionality Uncomment the fpurge and execute with fpurge and without fpurge*/ 				
	fgets (str,10,stdin);
	//__fpurge (stdin);										
	printf ("Enter the input string1:\n");
	fgets (str1,10,stdin);

	printf ("%s\n",str);
	printf ("%s\n",str1);
	return 0;

}
