
#include	"header.h"

extern int server_fd;

void C_Close(void )

{
	close(server_fd);

}
