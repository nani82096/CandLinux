
#include	"header.h"

extern char online_ip[100][16];

extern int client_sock;

int C_Fwd_Msg ( char *msg, char *ip[], int max )
{


	int j;
	for ( j = 0; j < max, j++ ) {
		
		struct message packet;

		strcpy ( packet.buff, msg);
		strcpy ( packet.ip, ip[j]);
		packet.time = 0;
		packet.flag = 2;
		packet.group_id = 0;
	
		int ret = 0;
		int i;
		int flag = 0;
		for ( i = 0; i < 20; i++ ) {
		
			printf ("fd = %d \t ip = %s\n", i , online_ip[i]);
				
			if (!(strcmp(online_ip[i], ip[j]))) {
			
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
	}
	return ret;

}
