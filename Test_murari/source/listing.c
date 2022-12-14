#include	"header.h"
void list_frames (FILE *fp, FILE *fp1, char *tr)
{
	int result = 0;
	int i = 0;
	char t[MAX];
	char *fr = NULL;
	char *last = NULL;
	char *temp = NULL;	/* temp pointer to point to tokens */
	char *line = (char *)malloc(sizeof(char ) * 1024);

	if (line == NULL){
		printf ("Malloc failed\n");
		return ;
	}
	while ( fgets (line, malloc_usable_size(line), fp)){
		strcpy(t, line);
		temp = strtok(line, ".");
		i = 8;			/*to parse the tokens from file*/ 
		while(i--){
			temp = strtok(NULL, ".");
			if ( i == 6)			// frame id
				fr = temp;
			if ( i == 1)			// trasmission type
				last = temp;
		}
        /* VALIDATION FOR MESSAGE                                               
         * If not(Continue loop) Discard message get another message            
         */
        result = valid_msg (fp, fr, t);                                         
       	if (result )
			continue;
		if (!strcmp(last, tr)){
				fprintf (fp1,"Frame %s With Type %s \n", fr, tr);
		}
		bzero(line,strlen(line));
	}
	free(line);
	line = NULL;
}
