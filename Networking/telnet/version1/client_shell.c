#include    "header.h"

int main(int argc, char **argv)
{
    int cfd;
    int fd;	
    int limit = 0;
    char buf[MAX] = {0};
    char buff[10000] = {0};
    char *arg[LIMIT];
    struct sockaddr_in instance;
    socklen_t addrlen;

    if (argc != 3) {
        printf("Usage : %s <IPaddress> <Portnumber>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    instance.sin_family = AF_INET;
    instance.sin_port = htons(atoi(argv[2]));
    instance.sin_addr.s_addr = inet_addr(argv[1]);

    addrlen = sizeof(instance);	

    if((cfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        handle_error("socket");

    if(connect(cfd, (const struct sockaddr *) &instance, addrlen) == -1)
        handle_error("connect");

        //while (limit <=3)
        while (limit++ <=3) {

        printf("enter the password\n");
        if (fgets(buf, MAX, stdin) == NULL)
            handle_error("fgets");
        buf[strlen(buf)-1] = '\0';

        if(write(cfd, buf, MAX) == -1)
            handle_error("write");

        if(read(cfd, buff, MAXLIMIT) == -1) 
            handle_error("read");

        if (!strcmp(buff, "1"))
            break;
        else
            continue;
        }
        if (limit > 3) {
            close(cfd);
            exit(EXIT_FAILURE);
        }

    while (1) {

        printf("enter command to be sent:");
        if (fgets(buf, MAX, stdin) == NULL)
            handle_error("fgets");

        buf[strlen(buf)-1] = '\0';

        if(write(cfd, buf, MAX) == -1)
            handle_error("write");

        if(read(cfd, buff, MAXLIMIT) != -1) 
            puts(buff);
        else
            handle_error("write");
        bzero(buf, sizeof(buf));
        bzero(buff, sizeof(buff));
    }

    close(cfd);

    return 0;
}
