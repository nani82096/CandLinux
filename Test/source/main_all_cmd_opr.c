#include	"header.h"

extern char *optarg;
extern int optind;
extern int optopt;
extern char buff[];
int main(int argc, char *argv[])
{

	/* Please Specify operation as single character i.e l - list, d - decode */
	/* For simplicity Purpose Enter options and arguments as -option argument */

	if ( argc < 7 ){
		printf ("Usage error <%s> <-s Src file > < -f FRAME_ID > <-o Oper > <dest optional>\n", argv[0]);
		return 0;
	}
	int c;
	int result = 0;	
	char *file_src = NULL; /* CAN Message File Name */
	char *file_dst = NULL; 	/* If specified Dest file Name */
	char *frame_id = NULL;
	int frm_id = 0;
	char opr;			/* operations options char */
	char tr[3];			/* for Tx or Rx. */

	/* Flags */
//	int sflag = 0;
	int oflag = 0;
	int fflag = 0;
//	int dflag = 0;

	while ( (c = getopt(argc, argv,"s:do:f:")) != -1 ){	//All options require arg except d
		
		switch(c){
			case 's':
				file_src = optarg;		/* For now take it as file */
			//	sflag = 1;
				break;
			case 'd':
				file_dst = (char *)malloc(sizeof(char) * 20);
				if ( file_dst == NULL) {
					printf ("Allocation failed\n");	
					return 0;
				}
				printf ("Enter Destination File Name::");
				if (!fgets(file_dst, malloc_usable_size(file_dst),stdin)){
					printf ("fgets failed\n");
					return 0;
				}
				printf ("Dest file = %s\n", file_dst);
			//	dflag = 1;
				break;
			case 'f':
				frame_id = optarg;
				/* Mapping frame_id */
				frm_id = frame_map(frame_id);
				printf("For %s Frame ID = %08X\n",frame_id ,frm_id);
				fflag = 1;
				break;
			case 'o':
				opr = optarg[0];		/* for oparations on frame id */
				oflag = 1;
				break;
			case '?':
				if (optopt == 's'){
					fprintf (stdin, "Option %c Requires an argument <file name>\n", optopt);
				}else if (optopt == 'f'){
					fprintf (stdin, "Option %c Requires an argument <file name>\n", optopt);
				}else if (optopt == 'o'){
					fprintf (stdin, "Option %c Requires an argument <file name>\n", optopt);
				}
				break;
			}
			
		}
		/* Storing the Data in Buffer And calling The Function */
		if ( fflag ){
			
			/* For easy search purpose taking fram_id as in file */
			if (!strcmp(frame_id, "FRM_001"))
				frame_id = "18DA00FB";
			if (!strcmp(frame_id, "FRM_002"))
				frame_id = "18DAFB00";
			/* Storing the Message For frame_id from src file*/
			result = store_message(file_src, frame_id);
			result ? printf ("storing success\nAnd Data = %s\n\n",buff): printf ("storing failed\n\n");
		}

		sleep(1);
		/* Performing operations */
		if (oflag){
			if (opr == 'l'){ 	/*listing operation */
				printf ("\n\nEnter Which frames you want display <Tx, Rx>\n");
				if (!fgets(tr, sizeof(tr), stdin))
					printf ("failed in input taking\n");
				list_frames(file_src,tr);
			}else 
				printf ("Invalid Operation\n");
		}
	return 0;
}
