#include	"header.h"

extern char *optarg;
extern int optind;
extern int optopt;
extern char buff[];

int main(int argc, char *argv[])
{

	/* Please Specify operation as single character i.e l - list, d - decode 
	 * For simplicity Purpose Enter options and arguments as -option argument
	 */ 
	if ( argc < 7 ){
		printf ("Usage error <%s> <-s Src file > < -f FRAME_ID > <-o Oper > <dest optional>\n", argv[0]);
		return 0;
	}
	int c;
	FILE *fp = NULL;		/* Src File */
	FILE *fp1 = NULL;		/* Dst File */
	int result = 0;	
	char *file_src = NULL; /* CAN Message File Name */
	char *file_dst = NULL; 	/* If specified Dest file Name */
	char *frame_id = NULL;
	int frm_id = 0;
	char opr;			/* operations options char */
	char tr[3];			/* for Tx or Rx. */

	/* Flags */
	int sflag = 0;
	int oflag = 0;
	int fflag = 0;
	int dflag = 0;

	/* Variable for validation part for valid_msg function */
	int j = 8;
	char *token = NULL;
	char line[MAX];
	char temp[MAX] ;

	while ( (c = getopt(argc, argv,"s:do:f:")) != -1 ){	//All options require arguments except d
		
		switch(c){
			case 's':
				file_src = optarg;		/* For now take it as file */
				sflag = 1;
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
				if (file_dst[strlen(file_dst)-1] == '\n')
					file_dst[strlen(file_dst)-1] = '\0';
				dflag = 1;
				break;
			case 'f':
				frame_id = optarg;
				/* Mapping frame_id */
				frm_id = frame_map(frame_id);
				fflag = frm_id ? 1 : 0;
				break;
			case 'o':
				opr = optarg[0];		/* for oparations on frame id */
				oflag = 1;
				break;
			case '?':
				if (optopt == 's'){
					fprintf (stderr, "Option %c Requires an argument <file name>\n", optopt);
				}else if (optopt == 'f'){
					fprintf (stderr, "Option %c Requires an argument <Frame ID>\n", optopt);
				}else if (optopt == 'o'){
					fprintf (stderr, "Option %c Requires an argument <Operation>\n", optopt);
				}
				break;
			}
			
		}
		
		/* Validation on Commandline arguments taken */
		if ( sflag ){
			fp = fopen(file_src, "r");
			if ( fp == NULL){
				printf ("File opening failed\n");
				return 0;
			}
		}else {
			printf ("Input File Not Given\n");
			return 0;
		}
		
		if ( dflag ){
			fp1 = fopen(file_dst, "w");
			if (fp1 == NULL){
				printf ("File opening failed\n");
				return 0;
			}
		}else 
			fp1 = stdout;

						/* Storing the Data in Buffer And calling The Function */
		if ( fflag ){
			
		//	frm_id = frame_map(frame_id);
			/* Storing the Message For frame_id from src file*/
			result = store_message(fp, frm_id);
			if (result){
				fprintf (fp1, "\t\tDATA\n%s\n", buff);
			}
		}else{
			printf ("Invalid Frame Acronym\n");
			return 0;
		}
			
		rewind (fp);
		/* Performing operations */
		if (oflag){
			if (opr == 'l'){ 	/*listing operation */
				printf ("\n\nEnter Which type of frames you want to list <Tx, Rx> :");
				if (!fgets(tr, sizeof(tr), stdin))
					printf ("failed in input taking\n");
				list_frames(fp, fp1, tr);
			}else if(opr == 'v') {
				while (fgets(line, sizeof(line), fp)){
					strcpy(temp,line);
					j = 8;
					token = strtok(line, ".");
					while(token && j != 6){
						j--;
						token = strtok(NULL, ".");
					}
					result = valid_msg(fp,  token,temp);
					switch(result){
						case 1:
							printf ("Read an EOF\n");
							break;
						case 2:
							printf ("Frame Id %s is more than 29 bits\n",token);
							break;
						case 3:
							printf ("Frame Id %s not Found\n",token);
							break;
						case 4:
							printf ("Fram Id %s Invalid Time Stamp\n", token);
							break;
						case 5:
							printf ("Fram Id %s Invalid Transmission\n", token);
							break;
						case 6:
							printf ("Fram Id %s Invalid Protocol\n", token);
							break;
					}
				}
			}else 
				printf ("Invalid Operation\n");
		}

		fclose(fp);
		fp = NULL;
		if (dflag){
			fclose(fp1);
			fp1 = NULL;
			free(file_dst);
			file_dst = NULL;
		}
		return 0;
}
