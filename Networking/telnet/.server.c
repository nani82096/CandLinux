#include	"header.h"

int main (int argc, char **argv)
{

    int sockfd;
    int clientfd;
    int actfd;
    pid_t pid;
    char opt[1024] = "";
    char buf[100] = {0};
    struct sockaddr_in servaddr;
    struct sockaddr_in clientaddr;
    struct sockaddr_in test;
    socklen_t servlen ;
    socklen_t testlen = sizeof(struct sockaddr);

    if ( 2 != argc){
        printf("usage: <%s> <arg> \n",argv[0]);
        exit(EXIT_FAILURE);
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = 0; 
    servaddr.sin_port = htons (atoi(argv[1]));

    servlen = sizeof(servaddr);

    if ( (sockfd = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1 ) {
        handle_error("socket");
    }

    if ( errno = bind (sockfd,(const struct sockaddr *) &servaddr, servlen) ) {
        handle_error("bind");
    }

    if ( errno = listen (sockfd, 10) ){
        handle_error("listen");
    }
    while (1) {

        if ( ( actfd = accept (sockfd, (struct sockaddr *)&clientaddr, &servlen) ) == -1) {
            handle_error("accept");
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
                    handle_error("recv");
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
                    pid_t pd = fork();
                    if (pd > 0){
                        wait(NULL);
                    }else if (pd == 0){
                        close(1);
                        dup(actfd);
                        execvp(arg[0],arg);
                    }
                }

            }
        }else{
            waitpid(0, WNOHANG, 0);
        }
    }
    return 0;
}
