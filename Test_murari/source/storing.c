#include	"header.h"
#include	"header.h"

char buff[MAX]="";
int store_message (FILE *fp , int frame)
{
	int flag = 0;
	int result = 0;
	int i = 0;
	int length = 0;
	char *fr = NULL;
	char *temp = NULL;	/* temp to point the tokens */
	char *ds = NULL;	/* data size */
	char *data = NULL;	/* data pointer */
	char t[MAX];		
	char *line = (char *)malloc(sizeof(char ) * 1024);

	if (line == NULL){
		printf ("Malloc failed\n");
		return 0;
	}
	while ( fgets (line, malloc_usable_size(line), fp)){
		
		strcpy(t, line);
		temp = strtok(line, ".");
		i = 8;			/*to parse the tokens from file*/ 
		while(i--){
			temp = strtok(NULL, ".");
			if ( i == 6)
				fr = temp;
			if ( i == 3)
				ds = temp;
			if ( i == 2 ){
				data = temp;
			}
		}
		/* VALIDATION FOR MESSAGE 
		 * If not(Continue loop) Discard message get another message
		 */
		result = valid_msg (fp, fr, t);
		if (result)		
			continue;

		/* frame id is in integer and frame id from file is integer so 
		 * converting frame id from file to integer using str_to_hex function
		 */

		if (frame ==  str_to_hex(fr)){
			if ( ((length = strlen(buff) < 255) && (length+atoi(ds) < 255) )){

				/* Discard if buff is overflowing And also no room for new data 
				 * Multiplying data because here in character buffer 
														hexadecimal data 
				 * 02 03 0F AB is treating as 8 bytes or Total length of data.
				 */
				memcpy(buff+strlen(buff), data, strlen(data)/*2*atoi(ds)*/);
				memcpy(buff+strlen(buff), " ",1);
				flag = 1; 		/* Write success */
			}
		}
		bzero(line,strlen(line));
	}
	free(line);
	line = NULL;
	if (flag) 
		return 1;
	return 0;
}
