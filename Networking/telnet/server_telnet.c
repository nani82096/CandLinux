/*****************************************************************************
 *                                                                           *
 * @file server_telnet.c                                                     *
 H
 * @date 14 Aug 2016                                                         *
 * @brief File contains source code for telnet deamon server                 *
 * @detail                                                                   *
 * This file creates deamon telnet server which enables clients in the       *
 * remote area to login and send the commands (linux commands like executing *
 * the codes and redirecting the output). It simply creates a virtual        *
 * terminal until that session to be terminated.                             *
 *                                                                           *
 *****************************************************************************/


#include	"header.h"

int main(int argc, char **argv)
{

	int actfd;
	int sockfd;
	pid_t pid = 0;
	socklen_t serv_len;
	char buf[MAX] = {0};
	char buff[1024];
	FILE *fp = NULL;
	struct passwd *pwd = NULL;	/* Info Regarding passwd file */
	struct spwd *shad = NULL;	/* Info Regarding Shadow file */
	char *usr = (char *)malloc(sizeof(char)*127);
	char client_password[PASS_LIMIT];
	unsigned char pass_limit = 1;
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

	/** To run telnet server as deamon */
	signal (SIGHUP, SIG_IGN);

	/** Password for future authentication */
	/*    printf("Enter the password\n");
		  dis_echo(1);
		  if ( fgets(password, sizeof(password), stdin) == NULL)
		  handle_error("fgets");
		  password[strlen(password)-1] = '\0'; 
		  dis_echo(0);*/
	//passwd = password();

	if ( (sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == ERROR) 
		handle_error("socket");

	if ( bind(sockfd,(const struct sockaddr *) &serv_addr, serv_len) == ERROR) 
		handle_error("bind");

	if ( listen(sockfd, SIZE) == ERROR)
		handle_error("listen");

	while (1) {

		puts("Waiting for the clients");

		if ( ( actfd = accept(sockfd, (struct sockaddr *) &client_addr, &cli_len)) == ERROR) 
			handle_error("accept");

		printf("Client connected : IP : <%s> portnum : <%hu>\n", 
				(char *) inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

		pid = fork();

		if ( pid < 0 ) {
			handle_error("fork");
		}else if (pid == 0) {

			if (recv (actfd, usr, 127, 0) == ERROR)
				handle_error("recv");
			if (send(actfd, "Username Recieved Successfull", 30, 0) == ERROR)
				handle_error("send");

			shad = getspnam(usr);

			/* // Diagnosis
			printf ("new pass encrypted1 :::%s\nand length = %d\n",passwd1,strlen(passwd));
			printf ("the key :::%s\n", key);	*/

			while (pass_limit++ < P_LIMIT) {
				if ( recv(actfd, client_password, PASS_LIMIT, 0) == ERROR) 
					handle_error("recv");
				//strcpy(buff, (char *)crypt(client_password,pwd->pw_passwd));
				strcpy(buff, (char *)crypt(client_password,shad->sp_pwdp));
				buff[strlen(buff)] = '\0';
				if ( strcmp(shad->sp_pwdp, buff)) {
					if ( send(actfd, "Password entered failed...please try again", 43, 0) == ERROR)
						handle_error("send");
					bzero(client_password, sizeof(client_password));
					continue;
				}
				else
					break;
			}// Password authentication 

			if (pass_limit > P_LIMIT) {
				if ( send(actfd, "Password limit exceeded", 24, 0) == ERROR)
					handle_error("send");
				close(actfd);
				continue;
			}
			else {
				if ( send(actfd, "Successfully loged in :", 24, 0) == ERROR)
					handle_error("send");
			}

			/* Changing root to usr */
			pwd = getpwnam(usr);
			if (setgid (pwd->pw_gid) != 0)
				printf ("Failed in setting gid\n");
			if (setuid (pwd->pw_uid) != 0)
				printf ("Failed in setting uid\n");
			/* Changing the Directory */
			int status = chdir(pwd->pw_dir);
			if (status == -1)
				printf ("Changing Directory failed\n");



			while (1) {

				bzero(buf, sizeof(buf));


				if ( recv(actfd, buf, MAX, 0) == ERROR) 
					handle_error("recv");

				/** Executing commands with pipe */
				if ( strstr(buf, " | ")) {

					int j = 0;
					int pid2 = 0;
					int pipefd[2];
					char *arg1[SIZE/2] = {NULL};
					char *arg2[SIZE/2] = {NULL};

					arg1[j] = strtok(buf, " ");
					while (arg1[j] && arg1[j] != "|" ){
						j++;
						arg1[j] = strtok(NULL, " ");
						if ( !strcmp(arg1[j], "|")) {
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

					}else if (pid2) {

						close(pipefd[1]);
						close(pipefd[0]);
						waitpid(pid2, 0, 0);

					}

				}else {/** Executing commands without pipe */

					int i = 0;
					pid_t pd;
					char *arg[SIZE] = {NULL};

					arg[i] = strtok(buf, " ");
					while (arg[i]) {
						i++;
						arg[i] = strtok(NULL, " ");
					}

					pd = fork();

					if (pd > 0) {
						wait(NULL);
					}else if (pd == 0) {

						close(1);
						dup(actfd);
						execvp(arg[0],arg);

					}
				}

			}
		}else {
			waitpid(0, NULL, WNOHANG);
		}
	}// Executing the linux commands
	
	free(usr);
	usr = NULL;
	fclose(fp);
	fp = NULL;

	return 0;
}
