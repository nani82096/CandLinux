#include    <stdio.h>                                                           
#include    <signal.h>                                                           
#include    <shadow.h>                                                           
#include    <sys/stat.h>                                                        
#include    <errno.h>                                                           
#include    <string.h>                                                          
#include    <stdlib.h>                                                          
#include    <unistd.h>                                                          
#include    <termios.h>                                                          
#include    <fcntl.h>                                                           
#include    <sys/socket.h>                                                      
#include    <sys/types.h>                                                       
#include    <netinet/ip.h>    

#include	<sys/types.h>
#include	<pwd.h>


#define _XOPEN_SOURCE       /* See feature_test_macros(7) */

#include	<unistd.h>

#define ERROR -1
#define MAX 1024                                                                  
#define SIZE 10                                                                
#define LIMIT 10       
#define P_LIMIT 3
#define PASS_LIMIT 20
#define MAXLIMIT 65535                                                          
#define handle_error(msg) do { perror(msg); exit(EXIT_FAILURE); } while(0) 

extern void dis_echo(int );
extern char *password(void);
