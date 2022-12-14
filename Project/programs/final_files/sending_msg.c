#include	"header.h"

struct sent_msg{
	char dst_ip[16];
	int time;
	int flag;
	char buff[1024];
};
extern int server_fd;
int C_Send_Msg ( char *msg, char *ip )
{

	struct sent_msg packet;

	strcpy ( packet.buff, msg);
	strcpy ( packet.dst_ip, ip);
	packet.time = 0;
	packet.flag = 0;
	
	int ret = 0;
	ret = send (server_fd, &packet, sizeof(packet), 0);

	if ( ret == -1)
			
		error ("send");

	return ret;
}
	
