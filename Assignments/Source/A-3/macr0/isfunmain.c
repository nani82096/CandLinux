#include "header.h"
#include <stdio_ext.h>
int main(void)
{

	int ch ;
	char c ;
	printf ("######### MENU ############\n") ;
	printf("1.isalnum\n2.isalpha\n3.isdigit\n4.isprint\n5.isupper\n"
					"6.isxdigit\n7.islower\n.iscntrl\n8.macro for isalnum\n"
						"9.macro for isalpha\n10.macro for isdigit\n11.macro for isprint\n"
							"12.macro for isupper\n13.macro for isxdigit\n14.macro for islower\n"
									"15.macro for iscntrl\n");

	printf("please enter ur choice \n") ;					
		scanf("%d",&ch) ;	
	__fpurge(stdin) ;
	switch( ch) {
		
		case 1 :
				is_alnum() ;
				break;
		case 2 :
				is_alpha() ;
				break ;
		case 3 :
				is_digit() ;
				break ;
		case 4 :
				is_print() ;
				break ;
		case 5 :
				is_upper() ;
				break ;
		case 6 :
				is_xdigit() ;
				break ;
		case 7 :
				is_lower() ;
				break ;
		case 8 :
				c = input() ;
				if(ISALNUM(c)) {
					printf ("%c is alphanumeric character \n",c) ;
				}
				else 
					printf ("%c is not alphanumeric  character \n",c) ;
				break ;
		case 9 :
				c = input() ;
				if(ISALPHA(c)) {
                    printf ("%c is alphabetic character \n",c) ;
                }
                else
                    printf ("%c is not alphabetic character \n",c) ;
                break ;
		case 10 :
				 c = input() ;
				 if(ISDIGIT(c)) {
                    printf ("%c is digit  \n",c) ;
                 }
                 else
                     printf ("%c is not digit  \n",c) ;
                 break ;
		case 11 :
				 c = input() ;
				 if(ISPRINT(c)) {
                    printf ("%c is not printable character \n",c) ;
                 }
                 else
                    printf ("%c is printable character  \n",c) ;
                 break ;
		case 12 :
				 c = input() ;
				 if(ISUPPER(c)) {
                     printf ("%c is uppercase  character \n",c) ;
                 }
                 else
                     printf ("%c is not uppercase  character \n",c) ;
                 break ;
		case 13 :
				 c = input() ;
				 if(ISXDIGIT(c)) {
                    printf ("%c is hexadecimal character \n",c) ;
                 }
                 else
                     printf ("%c is not hexadecimal  character \n",c) ;
                 break ;
		case 14 :
				 c = input() ;
				 if(ISLOWER(c)) {
                    printf ("%c is lowercase  character \n",c) ;
                 }
                 else
                     printf ("%c is not lowercase  character \n",c) ;
                 break ;


		

	}

		return 0 ;

}

				


