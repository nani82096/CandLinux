#include	"header.h"

/* Returning error numbers
 * if valid returning 0
 */

int valid_msg(FILE *fp, char *frame, char *buff)
{
	int fr = str_to_hex(frame);		/* Getting hexa frame number from string */
	if (feof(fp))
		return 1;
	else if ( fr & 0xE0000000 ){	// Frame id more than 29 bit
		return 2;
	}else if ( strstr(buff,frame) == NULL ){//Frm_id Not Found
		return 3;
	}else if ( !(strstr(buff, "Rx") || strstr(buff,"Tr"))){	//Invalid Transmission
		return 5;
	}else if ( (strstr(buff, "CAN - EXT") == NULL )){	//Invalid Protocol
		return 6;
	}else if ( strlen(strtok(buff, ".")) != 16){ //Frm_id Time Stamp Not Valid
		return 4;
	}else {			//Valid
		return 0;
	}
}
