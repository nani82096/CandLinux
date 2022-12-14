#include	<stdio.h>
#include	<sys/stat.h>
#include	<errno.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	<sys/socket.h>
#include	<sys/types.h>
#include	<netinet/ip.h>

int main (int argc, char **argv)
{
	if ( 2 != argc){
		printf("usage: <%s> <arg> \n",argv[0]);
		exit(EXIT_FAILURE);
	}

//	int fd = open ("text.txt", O_CREAT | O_RDWR);
//	perror ("opening file:");
	int sockfd;
	int clientfd;
	int actfd;

	pid_t pid;
	
	char opt[1024]="";
	char buf[100];
	
	struct sockaddr_in servaddr;
	struct sockaddr_in clientaddr;
	struct sockaddr_in test;
	socklen_t testlen = sizeof(struct sockaddr);
	socklen_t servlen ;
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = 0; 
	servaddr.sin_port = htons (atoi(argv[1]));

	servlen = sizeof(servaddr);

	if ( (sockfd = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1 ) {
		perror ("socket");
		exit(0);
	}

	if ( errno = bind (sockfd,(const struct sockaddr *) &servaddr, servlen) ) {
		perror ("bind");
		exit(1);
	}

	if ( errno = listen (sockfd, 10) ){
		perror("listen");
		exit(1);
	}
		if ( ( actfd = accept (sockfd, (struct sockaddr *)&clientaddr, &servlen) ) == -1) {
			perror("accept");
			exit(1);
		}
	while (1) {
	

		FILE *fp = fopen("new", "r");
		int fd = open("new",O_WRONLY | O_CREAT,0777);
		bzero(buf, strlen(buf));
		if (( errno = recv(actfd, buf, 100,0)) == -1) {
			perror("read ");
			exit(1);
		}

		//char *ptr = strtok(buf, "\n");
		pid = fork();
		if(pid > 0){
			wait(NULL);
//			close (1);
			close (fd);
			while (fgets(buf,sizeof(buf), fp)){
				strcat(opt, buf);
			}
			if ( ( errno = send (actfd, opt,strlen(opt),0 )) == -1 ) {
				perror("write");
				exit(1);
			}
			remove("new");
			bzero(opt, sizeof(opt));

		}else if(pid == 0){
			close(1);
			dup(fd);
			execlp(buf,buf,NULL);
		}else {
			printf ("fork failed\n");
		}
		

	//	system("rm new");
	}
	return 0;
}
