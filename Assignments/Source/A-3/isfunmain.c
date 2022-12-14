#include	"hdr2.h"

void main(void)
{

	int n ;
	int c ;
	printf ("######### MENU ############\n") ;
	printf("1.macro for isalnum\n"
			"2.macro for isalpha\n"
			"3.macro for isdigit\n"
			"4.macro for isprint\n"
			"5.macro for isupper\n"
			"6.macro for isxdigit\n"
			"7.macro for islower\n");

	printf("please enter ur choice \n") ;					
	scanf("%d",&n);	
	getchar();
	switch( n) {
		
		case 1 :
				printf("Enter character::");
				c = getchar();
				if(ISALNUM(c)) {
					printf ("%c is alphanumeric character \n",c) ;
				}
				else 
					printf ("%c is not alphanumeric  character \n",c) ;
				break ;
		case 2 :
				printf("Enter character::");                                              
                c = getchar();                                                            
                getchar();  
				if(ISALPHA(c)) {
                    printf ("%c is alphabetic character \n",c) ;
                }
                else
                    printf ("%c is not alphabetic character \n",c) ;
                break ;
		case 3 :
				printf("Enter character::");                                              
                c = getchar();                                                            
                getchar();  
				if(ISDIGIT(c)) {
                	printf ("%c is digit  \n",c) ;
                }
                else
                	printf ("%c is not digit  \n",c) ;
                break ;
		case 4 :
				printf("Enter character::");                                              
                c = getchar();                                                            
                getchar();  
				if(ISPRINT(c)) {
                   printf ("%c is not printable character \n",c) ;
                }
                else
                   printf ("%c is printable character  \n",c) ;
                break ;
		case 5 :
				printf("Enter character::");                                              
                c = getchar();                                                            
                getchar();  
				 if(ISUPPER(c)) {
                     printf ("%c is uppercase  character \n",c) ;
                 }
                 else
                     printf ("%c is not uppercase  character \n",c) ;
                 break ;
		case 6 :
				printf("Enter character::");                                              
                c = getchar();                                                            
                getchar();  
				 if(ISXDIGIT(c)) {
                    printf ("%c is hexadecimal character \n",c) ;
                 }
                 else
                     printf ("%c is not hexadecimal  character \n",c) ;
                 break ;
		case 7 :
				printf("Enter character::");                                              
                c = getchar();                                                            
                getchar();  
				 if(ISLOWER(c)) {
                    printf ("%c is lowercase  character \n",c) ;
                 }
                 else
                     printf ("%c is not lowercase  character \n",c) ;
                 break ;
		default :
				printf("Enter the valid option\n");
	}

}

				


