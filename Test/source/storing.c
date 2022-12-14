#include	"header.h"

char buff[MAX]="";
int store_message (char *file,char *frame)
{
	FILE *fp = fopen(file , "r");
	if (fp == NULL){
		printf ("file opening failed\n");
		return 0;
	}
	char *line = (char *)malloc(sizeof(char ) * 1024);
	if (line == NULL){
		printf ("Malloc failed\n");
		return 0;
	}
	char *fr = NULL;
	int length = 0;
	int i = 0;
	char *temp = NULL;	/* temp to point the tokens */
	char *ds = NULL;	/* data size */
	char *data = NULL;	/* data pointer */
	int flag = 0;
	while ( fgets (line, malloc_usable_size(line), fp)){
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
		result = valid_msg (fp, fr, t1);
		if ( result )
			printf ("valid message \n"); */
		if (!strcmp(frame, fr)){
			if ( ((length = strlen(buff) < 255) && (length+atoi(ds) < 255) )){
				/* discard if buff is overflowing and also no room for new data */
				/* Multiplying data because here in character buffer hexadecimal data 
				02 03 0F AB is treating as 8 bytes */
				memcpy(buff+strlen(buff), data, strlen(data)/*2*atoi(ds)*/);
				memcpy(buff+strlen(buff), " ",1);
				flag = 1; 		/* Write success */
			}
		}
		bzero(line,strlen(line));
	}
	if (flag) 
		return 1;
	return 0;
}
