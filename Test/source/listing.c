#include	"header.h"
void list_frames (char *file, char *tr)
{
	FILE *fp = fopen(file , "r");
	if (fp == NULL){
		printf ("file opening failed\n");
		return ;
	}
	char *line = (char *)malloc(sizeof(char ) * 1000);
	char *fr = NULL;
	char *last = NULL;
	int i = 0;
	char *temp = NULL;	/* temp pointer to point to tokens */
	if (line == NULL){
		printf ("Malloc failed\n");
		return ;
	}
	while ( fgets (line, malloc_usable_size(line), fp)){
		temp = strtok(line, ".");
		i = 8;			/*to parse the tokens from file*/ 
		while(i--){
			temp = strtok(NULL, ".");
			if ( i == 6)
				fr = temp;
			if ( i == 1)
				last = temp;
		}
		if (!strcmp(last, tr)){
				printf ("Frame %s with Tr %s \n", fr, tr);
		}
		bzero(line,strlen(line));
	}
}
