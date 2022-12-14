/**
    Handle multiple socket connections with select and fd_set on Linux
*/
  
#include	<stdio.h>
#include	<string.h>   		//strlen
#include	<stdlib.h>
#include	<errno.h>
#include	<unistd.h>   		//close
#include	<arpa/inet.h>    	//close
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<sys/time.h> 		//FD_SET, FD_ISSET, FD_ZERO macros
 
 
#define TRUE   1
#define FALSE  0
//#define PORT 2069

struct message {
	char buff[1024];
	char ip[16];
};

typedef struct queue{
	char buff[1024];
	char src_ip[16];
	char dst_ip[16];
	struct queue* next;
	}NODE;


NODE *add_end(NODE *start, NODE *new)
{
    if ( start == NULL ) {
        start = new;
        return start;
    }
    NODE *temp = start;
    while (temp->next != NULL) {
        temp = temp->next;
        }
    temp->next = new;
    return start;
}


char online_ip[100][16];// = {"", "","","","172.16.5.224","172.16.5.229"};
 
int main(int argc , char *argv[])
{
	int PORT = atoi(argv[1]);
    int opt = TRUE;
    int master_socket , src_addrlen, cli_addrlen , new_socket , client_socket[30] , max_clients = 30 , activity, i , j , valread , sd;
    int max_sd;
    struct sockaddr_in src_addr;
	struct sockaddr_in cli_addr;
      
    struct message buffer = {"",""};  //data buffer of 1K
    //set of socket descriptors
    fd_set readfds;
      
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
     
    while(TRUE) 
    {
        //clear the socket set
        FD_ZERO(&readfds);
  
        //add master socket to set
        FD_SET(master_socket, &readfds);
		FD_SET(0, &readfds);
        max_sd = master_socket;
         
        //add child sockets to set
        for ( i = 0 ; i < max_clients ; i++) 
        {
            //socket descriptor
            sd = client_socket[i];
           
            //if valid socket descriptor then add to read list
            if(sd > 0)
                FD_SET( client_socket[i] , &readfds);
             
            //highest file descriptor number, need it for the select function
            if(sd > max_sd)
                max_sd = sd;
        }
  
        //wait for an activity on one of the sockets , timeout is NULL , so wait indefinitely
        activity = select( max_sd + 1 , &readfds , NULL , NULL , NULL);
    
        if ((activity < 0) && (errno!=EINTR)) 
        {
            printf("select error");
        }
          
        //If something happened on the master socket , then its an incoming connection
        if (FD_ISSET(master_socket, &readfds)) 
        {
            if ((new_socket = accept(master_socket, (struct sockaddr *)&cli_addr, (socklen_t*)&cli_addrlen)) < 0)
            {
                perror("accept");
                exit(EXIT_FAILURE);
            }
			char *temp_ip = inet_ntoa(cli_addr.sin_addr);
			strcpy(online_ip[new_socket],temp_ip);
            //inform user of socket number - used in send and receive commands
			printf("New connection , socket fd is %d , ip is : %s , port : %d \n" , new_socket , inet_ntoa(cli_addr.sin_addr) , ntohs(cli_addr.sin_port));
            //add new socket to array of sockets
            for (i = 0; i < max_clients; i++) 
            {
                //if position is empty
                if( client_socket[i] == 0 )
                {
                    client_socket[i] = new_socket;
                    printf("Adding to list of sockets as %d\n" , i);
                     
                    break;
                }
            }
        }
        printf ("List of online fd's and ip's::\n"); 
		for ( i = 4 ; i <  max_sd+2; i++) 
			printf ("fd = %d, ip = %s\n",i, online_ip[i]);
        //else its some IO operation on some other socket :)
        for (i = 0; i < max_clients; i++ ) 
        {
			int j;
			sd = client_socket[i];

            if (FD_ISSET( sd , &readfds)) 
            {
                //Check if it was for closing , and also read the incoming message
				
                valread = read ( sd , (char *)&buffer, sizeof(buffer));
				//printf("sd value = %d\n", sd);
				if ( valread == 0)
                {
                    //Somebody disconnected , get his details and print
                    getpeername(sd , (struct sockaddr*)&cli_addr , (socklen_t*)&cli_addrlen);
                    printf("Host disconnected , ip %s , port %d \n" , inet_ntoa(cli_addr.sin_addr) , ntohs(cli_addr.sin_port));
                      
                    //Close the socket and mark as 0 in list for reuse
                    close( sd );
                    client_socket[i] = 0;
                } else if ( valread > 0) {
					int flag = 0;
					NODE *head = NULL;
					NODE *new = (NODE *)malloc(sizeof(NODE));
					printf ("\n\t\tMessage from %s Socket = %d::%s Message to %s\n", online_ip[sd], sd, buffer.buff,buffer.ip);
					for ( j = 0; j <= max_sd; j++){
						if ( !strcmp(buffer.ip, online_ip[j])) {
							flag = 1;
							printf ("\n\t\t\tMessage to %s Socket = %d::%s\n", buffer.ip, j, buffer.buff);
        	  	 			if ( write(j , buffer.buff , strlen(buffer.buff)  ) == -1 )
								perror ("write");
							bzero (buffer.buff, 1024);
							break;
						}
						if ( flag == 0){
							strcpy(new->buff,buffer.buff);
							strcpy(new->src_ip,buffer.ip);
							strcpy(new->dst_ip,online_ip[sd]);
							new->next = NULL;
							head = add_end(head,new);
						}
					}
					
				}	
				
			}
        }
    }
      
    return 0;
} 
