/**
    Handle multiple socket connections with select and fd_set on Linux
*/
  
#include <stdio.h>
#include <string.h>   		//strlen
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>   		//close
#include <arpa/inet.h>    	//close
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h> 		//FD_SET, FD_ISSET, FD_ZERO macros
 
 
#define TRUE   1
#define FALSE  0
//#define PORT 2069
 
int main(int argc , char *argv[])
{
    int opt = TRUE;
    int master_socket , src_addrlen, cli_addrlen , new_socket , client_socket[30] , max_clients = 30 , activity, i , valread , sd;
    int max_sd;
    struct sockaddr_in src_addr;
	struct sockaddr_in cli_addr;
      
    char buffer[1025];  //data buffer of 1K
      
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
/*    if( setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0 )
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }*/
  
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
          
        //else its some IO operation on some other socket :)
        for (i = 0; i < max_clients; i++ ) 
        {

			if (i) {
				int j;
				FD_ZERO(&readfds);
				FD_SET(0, &readfds);
	        	//add child sockets to set
    	    	for ( j = 0 ; j < max_clients ; j++) 
   		    	{
            		//socket descriptor
         	   		sd = client_socket[j];
             
            		//if valid socket descriptor then add to read list
            		if(sd > 0)
                		FD_SET( client_socket[j] , &readfds);
             
            		//highest file descriptor number, need it for the select function
            		if(sd > max_sd)
                		max_sd = sd;
        		}

        		select( max_sd + 1 , &readfds , NULL , NULL , NULL);
			}

			sd = client_socket[i];

            if (FD_ISSET( sd , &readfds)) 
            {
                //Check if it was for closing , and also read the incoming message
				
                valread = recv ( sd , buffer, 1024, 0);
				//printf("sd value = %d\n", sd);
				if ( valread == 0)
                {
                    //Somebody disconnected , get his details and print
                    getpeername(sd , (struct sockaddr*)&cli_addr , (socklen_t*)&cli_addrlen);
                    printf("Host disconnected , ip %s , port %d \n" , inet_ntoa(cli_addr.sin_addr) , ntohs(cli_addr.sin_port));
                      
                    //Close the socket and mark as 0 in list for reuse
                    close( sd );
                    client_socket[i] = 0;
                } else if ( valread > 0) 
					printf ("\n\t\t\tMessage from %s from Socket %d::%s\n", inet_ntoa(cli_addr.sin_addr), sd, buffer);
				
				bzero (buffer, 1024);

            }else if ( FD_ISSET ( 0, &readfds) ) {
				//__fpurge(stdin);
				//printf ("Enter Message to socket %d::", sd);
				if ( fgets(buffer,1024, stdin) == NULL) 
					printf ("fgets failed\n");
				if ( buffer[strlen(buffer)-1] == '\n')
					buffer[strlen(buffer)-1] = '\0';
        	    if ( send(sd , buffer , strlen(buffer) , 0 ) == -1 )
					perror ("send");
				bzero (buffer, 1024);
			}
        }
    }
      
    return 0;
} 
