#include	<stdio.h>

char buff[] = "027568ABCD";

struct ss{
	
	char type:2;
	char ops:4;
	int len:20;
	char str[];
	}pkt;
int main(void)
{
	pkt.type = buff[0]-'0';
	pkt.ops =  buff[1]-'0';
	pkt.len =  buff[2]-'0';
	memcpy(pkt.str,buff+3,(int)(pkt.len));

	printf ("type = %d ops = %d len = %d str = %s\n",pkt.type, pkt.ops, pkt.len, pkt.str);
	bzero(&pkt, sizeof(pkt));
/*	memcpy(&pkt, buff, sizeof(buff));

	printf( "type = %d ops = %d len = %d str = %s\n",pkt.type, pkt.ops, pkt.len, pkt.str);
*/	return 0;

}
