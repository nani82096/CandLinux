#include	"header.h"
/* mapping FRM_001 to the corresponding Frame id */
unsigned int frame_map(char *frame)
{
	unsigned frm_id = 0;	
	/* comparing the frame acronym and variable name */
	if (!strcmp(frame,getName(FRM_001))){
		frm_id = FRM_001;
	}else if (!strcmp(frame,getName(FRM_002))){
		frm_id = FRM_002;
	}else
		return 0;
	return frm_id;
}
