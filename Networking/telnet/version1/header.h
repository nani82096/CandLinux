#include    <stdio.h>                                                           
#include    <signal.h>                                                           
#include    <sys/stat.h>                                                        
#include    <errno.h>                                                           
#include    <string.h>                                                          
#include    <stdlib.h>                                                          
#include    <unistd.h>                                                          
#include    <fcntl.h>                                                           
#include    <sys/socket.h>                                                      
#include    <sys/types.h>                                                       
#include    <netinet/ip.h>    

#define ERROR -1
#define MAX 1024                                                                  
#define SIZE 10                                                                
#define LIMIT 10                                                                
#define MAXLIMIT 65535                                                          
#define handle_error(msg) do { perror(msg); exit(EXIT_FAILURE); } while(0)   
