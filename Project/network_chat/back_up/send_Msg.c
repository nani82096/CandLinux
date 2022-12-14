#include	"header.h"

struct sent_msg{
	char buff[1024];
	char dst_ip[16];
	int time;
	int flag;
};
extern int client_sock;
extern int online_ip[100][16];
int C_send_Msg ( char *msg, const char *ip )
{

	struct sent_msg packet;

	strcpy ( packet.buff, msg);
	strcpy ( packet.dst_ip, ip);
	packet.time = 0;
	packet.flag = 0;
	
	int ret = 0;
	int i;
	int flag = 0;
	for ( i = 0; i < 20; i ++ ) {
		
		if ( !(strcmp(online_ip[i], ip))) {
			
			ret = send (i, &packet, sizeof(packet), 0);			
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
