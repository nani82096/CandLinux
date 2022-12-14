#include	"hdr2.h"

int main(void)
{
	int ch;
	int choice;
	int result;
	while(1) {
		printf("______________________________________\n"
				"1. For islower(c)\n"
				"2. For isupper(c)\n"
				"3. For isalpha(c)\n"
				"4. For isdigit(c)\n"
				"5. For isalnum(c)\n"
				"6. For isprint(c)\n"
				"7. For isxdigit(c)\n"
				"8. For iscntrl(c)\n"
				"0. For Exit\n\n");
		choice = integervalidation();
		switch(choice) {
			
			case 0:
				return 0;
			case 1:
				printf("Enter character::");
				ch = getchar();
				getchar();
				result = myislower(ch);
				if ( result )
					printf("%c Is lower case character\n", ch);
				else
					printf("%c Is not a lower case character\n", ch);
				break;
			case 2:
				printf("Enter character::");                                              
                ch = getchar();                                                           
                getchar();                                                                
                result = myisupper(ch);                                                   
                if ( result )                                                             
                    printf("%c Is upper case character\n", ch);                           
                else                                                                      
                    printf("%c Is not a upper case character\n", ch);                     
                break;
			 case 3:                                                         
                printf("Enter character::");                                              
                ch = getchar();                                                           
                getchar();                                                                
                result = myisalpha(ch);                                                   
                if ( result )                                                             
                    printf("%c Is an alphabet character\n", ch);                           
                else                                                                      
                    printf("%c Is not an alphabet character\n", ch);                     
                break;
			 case 4:                                                                       
                printf("Enter character::");                                              
                ch = getchar();                                                           
                getchar();                                                                
                result = myisdigit(ch);                                                   
                if ( result )                                                             
                    printf("%c Is a Valid digit\n", ch);                           
                else                                                                      
                    printf("%c Is not a Valid digit\n", ch);                     
                break;  
			 case 5:                                                                       
                printf("Enter character::");                                              
                ch = getchar();                                                           
                getchar();                                                                
                result = myisalnum(ch);                                                   
                if ( result )                                                             
                    printf("%c Is alpha numeric character\n", ch);                           
                else                                                                     
                    printf("%c Is not alpha numeric character\n", ch);                     
                break;  
			case 6:                                                                      
                printf("Enter character::");                                              
                ch = getchar();                                                           
                getchar();                                                                
                result = myisprint(ch);                                                   
                if ( result )                                                             
                    printf("%c Is Printable character \n", ch);                        
                else                                                                      
                    printf("%c Is not Printable character \n", ch);                    
                break;
			case 7:                                                                      
                printf("Enter character::");                                              
                ch = getchar();                                                           
                getchar();                                                                
                result = myisxdigit(ch);                                                   
                if ( result )                                                             
                    printf("%c Is a Valid Hexadecimal digit\n", ch);                                  
                else                                                                      
                    printf("%c Is not a Valid Hexadecimal digit\n", ch);                              
                break;
			case 8:                                                                      
                printf("Enter character::");                                              
                ch = getchar();                                                           
                getchar();                                                                
                result = myiscntrl(ch);                                                   
                if ( result )                                                             
                    printf("%c Is a Controlable character\n", ch);                                  
                else                                                                      
                    printf("%c Is not a Controlable character\n", ch);                              
                break;
			defualt:
				printf("Enter valid options\n");
		}
	}
	return 0;
}
