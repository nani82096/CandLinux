#include	"header.h"

extern int online_ip[100][16];

int fd[100];
struct sockaddr_in client;

#define PORT 2323

void getstatus(char* ip[], int max)
{

	int i;
	int ret;
	

	for(i = 0; i < max ; i++){
		memset(&client, 0, sizeof (client));
		fd[i] = socket(AF_INET, SOCK_STREAM,  0);
	
		if(fd[i] == -1){

			perror("socket\n");

			exit(EXIT_FAILURE);

		}


//		#####bcopy( (char*)(srv -> h_addr), (char*)&client.sin_addr.s_addr, srv -> h_length);// check wether we need to convert this
	//address to network address and then copy
		client.sin_family = AF_INET;
		client.sin_port = htons (PORT);
		client.sin_addr.s_addr = inet_addr(ip[i]);

		ret = inet_pton (AF_INET, ip[i], &client.sin_addr.s_addr);	//####client.sin_addr.s_addr  //address should be given
		if (ret < 1)
			error ("inet_pton");

	
		ret = connect(fd[i], (struct sockaddr*)&client, sizeof(client));
		perror("connect\n");

    	if(ret == -1){

        	printf("%s is in [--- OFF-LINE ---] \n",  (char*)inet_ntoa(client.sin_addr));

			close(fd[i]);
			
    	}else{

			printf("%s is in [--- ON-LINE ---] with fd : %d\n",  (char*)inet_ntoa(client.sin_addr), fd[i]);
			
			char *temp = inet_ntoa(client.sin_addr);
		
			strcpy(online_ip[fd[i]], temp);

			//printf("%s\n", online_ip[i]);

		}
		
	}

	return ;

}
