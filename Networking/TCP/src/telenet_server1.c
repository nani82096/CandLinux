#include	<stdio.h>
#include	<sys/stat.h>
#include	<errno.h>
#include	<string.h>
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

    char opt[1024] = "";
    char buf[100] = {0};

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
    while (1) {

        if ( ( actfd = accept (sockfd, (struct sockaddr *)&clientaddr, &servlen) ) == -1) {
            perror("accept");
            exit(1);
        }
        pid = fork();
        if (pid < 0 ){
            perror("fork");
        }else if (pid == 0){

            // close(sockfd);
            while(1){
                char *arg[10] = {NULL};
                bzero(buf, sizeof(buf));
                if (( errno = recv(actfd, buf, 100,0)) == -1) {
                    perror("read ");
                    exit(1);
                }
                if (strstr(buf, " | ")){
                    char *arg1[5] = {NULL};
                    char *arg2[5] = {NULL};
                    int j = 0;
                    arg1[j] = strtok(buf, " ");
                    while (arg1[j] && arg1[j] != "|" ){
                        j++;
                        arg1[j] = strtok(NULL, " ");
                        if (!strcmp(arg1[j],"|")){
                            arg1[j] = NULL;
                            break;
                        }
                    }
                    j = 0;
                    arg2[j] = strtok(NULL, " ");
                    while (arg2[j]){
                        j++;
                        arg2[j] = strtok(NULL, " ");
                    }
                    int pipefd[2];
                    if (pipe(pipefd) == -1)
                        perror("pipe");

                    if (!fork()){
                        close (1);
                        dup(pipefd[1]);
                        close(pipefd[0]);
                        execvp(arg1[0], arg1);
                    }else {
                        close(pipefd[1]);
                        close(0);
                        dup(pipefd[0]);
                        wait(NULL);
                        close(1);
                        dup(actfd);
                        execvp(arg2[0], arg2);
                    }

                }else {

                    int i = 0;
                    arg[i] = strtok(buf, " ");
                    while (arg[i]){
                        i++;
                        arg[i] = strtok(NULL, " ");
                    }
                    //arg[i+1] = NULL;	
                    pid_t pd = fork();
                    if (pd > 0){
                        wait(NULL);
                    }else if (pd == 0){
                        //fflush(stdout);
                        close(1);
                        dup(actfd);
                        execvp(arg[0],arg);
                    }
                }

            }
        }else{
            // close(actfd);
            waitpid(0, WNOHANG, 0);
        }

        //	system("rm new");

    }
    return 0;
}
