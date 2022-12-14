#define _GNU_SOURCE

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#define SIZE_BUF 1024
#define SIZE_WORD 20

void error (char *msg)
{
	perror(msg);
	exit (EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	if ( argc != 4 ) {
		printf ("\nUsage:: <%s> <file>  <search_word>  <replacement_word>\n", argv[0]);
		return 0;
	}

	/* Declaring the buffers and file pointers */
	char buff[SIZE_BUF] = "";
	char *src;
	char *replace;
	char *temp;
	char *rev;
	char *temp1;

	int diff ;

	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL)
		error ("fopen");

	FILE *fptmp = fopen("tempfile","wb+");
	if (fptmp == NULL)
		error ("fopen");

	/* Getting the strings (words) from command line */
	
	src = argv[2];
	replace = argv[3];

	while ( fgets (buff, SIZE_BUF, fp)) {

		temp = buff;

		while ( (temp = strstr(temp, src)) ){

			rev = temp;
	
			diff = (strlen(replace) - strlen(src));
														/* If the replace is more than src */
			if ( diff > 0 ){

			/* rev is pointing last to buff */
				while (*rev) 
					rev++;
				
				/* elangating the buff */
				while ( rev != (temp ) ) {
				
					*(rev+diff) = *(rev);
					rev--;
				}
			}else if (diff < 0) {
					
				strncpy(temp, replace, strlen(replace));
				memmove( temp+strlen(replace), temp + strlen(src), strlen(temp+strlen(src)) + 1);
			} 
			temp1 = replace;
			while (*temp1) {
				*temp++ = *temp1++;
				
			}	
			
			temp = temp + strlen(replace);
		}
		//writing to the temparary file 
		fputs (buff, fptmp);
		memset (buff, 0, sizeof (buff));
	}
	/* removing the file and renaming the tempfile to file */
	fcloseall ();
	remove (argv[1]);
	rename ("tempfile", argv[1]);
	
	return 0;
}
