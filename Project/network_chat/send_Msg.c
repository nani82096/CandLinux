
#include	"header.h"


extern char online_ip[100][16];

extern int client_sock;
int C_send_Msg ( char *msg, const char *ip )
{

	struct message packet;

	strcpy ( packet.buff, msg);
	strcpy ( packet.ip, ip);
	packet.time = 0;
	packet.flag = 0;
	packet.group_id = 0;
	
	int ret = 0;
	int i;
	int flag = 0;
	for ( i = 0; i < 20; i++ ) {
		
		printf ("fd = %d \t ip = %s\n", i , online_ip[i]);
			
		if (!(strcmp(online_ip[i], ip))) {
			
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
