#include	"header.h"

extern char online_ip[100][16];
extern int client_socket[30];
int fd[100];
struct sockaddr_in client;

#define PORT 2323

void getstatus(char* ip[], int max)
{

	printf("Get status...\n");

	int i, j;
	int ret;
	int flag = 0;

	for(i = 0; i < max ; i++){

		flag = 0;

		memset(&client, 0, sizeof (client));

		fd[i] = socket(AF_INET, SOCK_STREAM,  0);
	
		if(fd[i] == -1){

			perror("socket\n");

			exit(EXIT_FAILURE);

		}

	//address to network address and then copy
	
		client.sin_family = AF_INET;
		client.sin_port = htons (PORT);
		client.sin_addr.s_addr = inet_addr(ip[i]);
	

		ret = inet_pton (AF_INET, ip[i], &client.sin_addr.s_addr);	//####client.sin_addr.s_addr  //address should be given
	
		if (ret < 1)
		
			error ("inet_pton");

		for ( j = 0; j < 30; j++ ) {
		
			if (!strcmp(online_ip[j], inet_ntoa(client.sin_addr))){ 
				
				flag = 1;
				
				break;

			}

		}

		if ( flag == 0 ) {

			ret = connect(fd[i], (struct sockaddr*)&client, sizeof(client));
			
		

    		if(ret == -1){

				perror("connect\n");
        		printf("%s is in [--- OFF-LINE ---] \n",  (char*)inet_ntoa(client.sin_addr));

				close(fd[i]);
			
    		}else if (ret == 0 ){

				printf("%s is in [--- ON-LINE ---] with fd : %d\n",  (char*)inet_ntoa(client.sin_addr), fd[i]);
			
				char *temp = inet_ntoa(client.sin_addr);
		
				strcpy(online_ip[fd[i]], temp);

				for(j = 0; j < 30; j++){
				
					if(client_socket[j] == 0){

						client_socket[j] = fd[i];

						break;
					}

				}
			}
		}	
	}
//	for ( j = 0 ; j < 30; j++ )
//		printf("list of online ip's::%s\t , fds: %d\n", online_ip[j], client_socket[j]);
	return ;

}
