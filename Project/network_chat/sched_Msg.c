#include	"header.h"

extern char online_ip[100][16];

extern int client_sock;
int convert_sec (int yy, int mm, int dd, int hh, int min)
{
	struct timeval tv;
	struct tm *tm;
	
	gettimeofday ( &tv, NULL);

	if ( (tm = localtime (&tv.tv_sec)) != NULL) {
	
		if(min <  (tm->tm_min)){

            min = min + 60;
            hh = hh - 1;

        }

        min = min - tm->tm_min;

        if(hh < tm->tm_hour){

            hh = hh + 12;
            dd = dd - 1;

        }

         hh = hh - tm->tm_hour;

        if(dd < tm->tm_mday) {

            dd = dd + 30;
            mm = mm - 1;

        }

		dd = dd - tm->tm_mday;

        if(mm < (tm->tm_mon + 1)){

            mm = mm + 12;
            yy = yy - 1;

        }

        mm = mm - (tm->tm_mon+1);

        yy = yy - (tm->tm_year + 1900);
	}
	int sec = (yy*12*30*24*60*60) + ( mm*30*24*60*60) + ( dd*24*60*60 ) + (hh*60*60) + (min*60);
	printf ("time = %d\n", sec);
	return sec;
}

int C_Sched_Msg (char *list[])
{
	
	struct message packet;

	strcpy ( packet.buff, *(list+6));
	strcpy ( packet.ip, *(list+0));

	int year = atoi(*(list+3));
	int mon = atoi (*(list+2));
	int dd  = atoi (*(list+1));
	int hh  = atoi (*(list+4));
	int min = atoi (*(list+5));

	int sec = convert_sec (year, mon, dd, hh, min);

	printf("sec : %d\n", sec);

	packet.time = sec;
	packet.flag = 1;
	packet.group_id = 0;
	
	int ret = 0;
	int i;
	int flag = 0;
	for ( i = 0; i < 20; i++ ) {
		
		printf ("fd = %d \t ip = %s\n", i , online_ip[i]);
			
		if ( !(strcmp(online_ip[i], packet.ip)) ) {
			
			ret = send (i, &packet, sizeof(packet), 0);			
			printf("\n%d\n", i);
			flag = 1;
			break;
		}
	}
	
	if ( flag == 0 )
		
		ret = send (client_sock, &packet, sizeof(packet), 0);

	if ( ret == -1)
			
		error ("send");

	return ret;

}
