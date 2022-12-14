#include	"header.h"

int main (int argc, char **argv)
{

    int sockfd;
    int actfd;
    pid_t pid = 0;
    char buf[MAX] = {0};
    socklen_t serv_len;
    struct sockaddr_in serv_addr;
    struct sockaddr_in client_addr;
    socklen_t cli_len = sizeof(struct sockaddr);

    if (argc != 2) {
        printf("usage: <%s> <portnumber> \n",argv[0]);
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY; 
    serv_addr.sin_port = htons( atoi(argv[1]));

    serv_len = sizeof(serv_addr);

    if ( (sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == ERROR) 
        handle_error("socket");

    if ( bind(sockfd,(const struct sockaddr *) &serv_addr, serv_len) == ERROR) 
        handle_error("bind");

    if ( listen(sockfd, SIZE) == ERROR)
        handle_error("listen");

    while (1) {

        if ( ( actfd = accept(sockfd, (struct sockaddr *) &client_addr, &cli_len)) == ERROR) 
            handle_error("accept");

        printf("Client connected : IP : <%s> portnum : <%hu>\n", 
                (char *) inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        char password[] = ".";
        unsigned char pass_limit = 1;
        char client_password[20];

               while (pass_limit++ <= 3) {

                if ( recv(actfd, client_password, 20, 0) == ERROR) {
                    handle_error("recv");
                }

                if ( strcmp(password, client_password)) {
                    if ( send(actfd, "Password entered failed...please try again",43,0) == ERROR)
                        handle_error("send");
                    continue;
                }
                else
                    break;
                bzero(buf, sizeof(buf));
               }
               if (pass_limit > 3) {
                    if ( send(actfd, "Password entered failed...limit exceeded",43,0) == ERROR)
                        handle_error("send");
                    close(actfd);
                    continue;
               }
               else {
                    if ( send(actfd, "1", 2, 0) == ERROR)
                        handle_error("send");
               }
                    
        pid = fork();

        if ( pid < 0 ) {
            handle_error("fork");
        }else if (pid == 0){
   
            while (1) {

                char *arg[SIZE] = {NULL};
                bzero(buf, sizeof(buf));

                if ( recv(actfd, buf, MAX, 0) == ERROR) {
                    handle_error("recv");
                }

                if ( strstr(buf, " | ")) {

                    int j = 0;
                    char *arg1[SIZE/2] = {NULL};
                    char *arg2[SIZE/2] = {NULL};

                    arg1[j] = strtok(buf, " ");

                    while (arg1[j] && arg1[j] != "|" ){
                        j++;
                        arg1[j] = strtok(NULL, " ");
                        if ( !strcmp(arg1[j],"|")) {
                            arg1[j] = NULL;
                            break;
                        }
                    }

                    j = 0;
                    arg2[j] = strtok(NULL, " ");
                    while (arg2[j]) {
                        j++;
                        arg2[j] = strtok(NULL, " ");
                    }

                    int pid2 = 0;
                    int pipefd[2];

                    if ( pipe(pipefd) == ERROR)
                        perror("pipe");

                    pid2 = fork();
                    if (!pid2) {
                        if (!fork()) {
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

                    }else if(pid2)  {
                            close(pipefd[1]);
                            close(pipefd[0]);
                        waitpid(pid2, 0, 0);
                    }

                }else {

                    int i = 0;

                    arg[i] = strtok(buf, " ");
                    while (arg[i]) {
                        i++;
                        arg[i] = strtok(NULL, " ");
                    }

                    pid_t pd = fork();

                    if (pd > 0) {
                        wait(NULL);
                    }else if (pd == 0){
                        close(1);
                        dup(actfd);
                        execvp(arg[0],arg);
                    }
                }

            }
        }else {
            waitpid(0, WNOHANG, 0);
        }
    }
    return 0;
}

