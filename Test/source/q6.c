#include	"header.h"

int valid_msg(FILE *fp, char *frame, char *buff){

	printf ("buff = %s\n fram = %s ", buff, frame);
	if (feof(fp))
		return 0;
	if ( sizeof(buff) > 8){
		printf (" size of frame is more \n");
		return 0;
	}
	if ( strstr(buff,frame) == NULL ){
		printf ("Frame not found\n");
		return 0;
	}
	return 1;
}
