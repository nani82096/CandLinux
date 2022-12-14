#include	"header.h"

extern int online_ip[100][16];

int fd[100];
struct hostent *srv;
struct sockaddr_in client;

#define PORT 2323

void getstatus(char* ip[], int max)
{

	int i;
	int ret;
	

	for(i = 0; i < max ; i++){
	
		fd[i] = socket(AF_INET, SOCK_STREAM,  0);
	
		if(fd[i] == -1){

			perror("socket\n");

			exit(EXIT_FAILURE);

		}

		srv = gethostbyname(ip[i]);

    	if(srv == NULL){

        	perror("gethostbyaddr failed\n");

     	  	exit(EXIT_FAILURE);

    	}
		

		bcopy( (char*)(srv -> h_addr), (char*)&client.sin_addr.s_addr, srv -> h_length);
		client.sin_family = AF_INET;
		client.sin_port = htons (PORT);

		ret = inet_pton (AF_INET, srv -> h_addr, client.sin_addr.s_addr);
		if (ret < 1)
			error ("inet_pton");

	
		ret = connect(fd[i], (struct sockaddr*)&client, sizeof(client));

    	if(ret == -1){

        	printf("%s is in [--- OFF-LINE ---] \n",  (char*)inet_ntoa(client.sin_addr));

			close(fd[i]);
			
    	}else{

			printf("%s is in [--- ON-LINE ---] with fd : %d\n",  (char*)inet_ntoa(client.sin_addr), fd[i]);
			
			char *temp = inet_ntoa(client.sin_addr);
		
			strcpy(online_ip[fd[i]], temp);


		}
		
			printf("%s\n", online_ip[i]);
	}

	return ;

}
