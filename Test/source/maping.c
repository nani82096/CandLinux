#include	"header.h"
/* mapping FRM_001 to the corresponding Frame id */
unsigned int frame_map(char *frame)
{
	struct frame Fram;
	
	if (!strcmp(frame,"FRM_001")){
		Fram.fr_id = 0x18DA00FB;
	}else if (!strcmp(frame,"FRM_002")){
		Fram.fr_id = 0x18DAFB00;
	}
	return Fram.fr_id;
}
