/***
    Handle multiple socket connections with select and fd_set on Linux
*
  
*/
#include	"header.h"


int max_clients = 30;
int client_socket[30];
char online_ip[100][16];
 
int main(int argc , char *argv[])
{
	int PORT = atoi(argv[1]);
    int opt = TRUE;
    int max_sd;
    int master_socket , src_addrlen, cli_addrlen , new_socket , activity, i , j , valread , sd;
      
	//set of socket descriptors
    fd_set readfds;
	
    struct sockaddr_in src_addr;
	struct sockaddr_in cli_addr;
    struct message buffer = {"",""};  //data buffer of 1K
      
	NODE *head = NULL;

    //initialise all client_socket[] to 0 so not checked
    for (i = 0; i < max_clients; i++) 
    {
        client_socket[i] = 0;
    }
      
    //create a master socket
    if( (master_socket = socket(AF_INET , SOCK_STREAM , 0)) == 0) 
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
  
    //set master socket to allow multiple connections , this is just a good habit, it will work without this
    if( setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0 )
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
  
    //type of socket created
    src_addr.sin_family = AF_INET;
    src_addr.sin_addr.s_addr = INADDR_ANY;
    src_addr.sin_port = htons( PORT );
      
    //bind the socket to localhost port 8888
    if (bind(master_socket, (struct sockaddr *)&src_addr, sizeof(src_addr))<0) 
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    printf("Listener on port %d \n", PORT);
     
    //try to specify maximum of 3 pending connections for the master socket
    if (listen(master_socket, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
     
    //accept the incoming connection
    cli_addrlen = sizeof(cli_addr);
    puts("Waiting for connections ...");
    
	pid_t pid = fork();
	
	if ( pid == 0) {
		AcceptTCPConn_read(master_socket);
	}else if (pid > 0) {
	}else 
		printf ("fork failed\n");
    
	return 0;
} 
