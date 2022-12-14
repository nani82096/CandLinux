#include	"header_cll.h"

int main( void )
{
	int pos;
	int choice;
	NODE *start = NULL;
	while (1) {
		printf("\n\n\n....................MENU..................\n"
				"\t1.INSERTION\n"
				"\t2.DELETION\n"
				"\t3.DISPLAY\n"
				"\t4.EXIT\n"
				"...............................................\n");
		
		printf("enter choice\n");
		choice = integervalidation();
		
		switch( choice ) {
			
			case 1:
		
				start = cl_insert( start );
				break;
		
			case 2:
				start = cl_del( start );
				break;
	
			case 3:
				display( start );
				break;
			case 4:
				exit( 0 );

			default:
				printf("invalid choice please re-enter choice\n");
				break;
		}
	}
	return 0;
}	
void display( NODE *start)                                                                  
{                                                                                         
    NODE *temp = start;                                                                     
    if (start == NULL) {                                                                    
        printf("List is empty \n");                                                       
        return ;                                                                          
    }
	printf("\n\n");                                                                                     
    while ( temp->next != start) {                                                                       
        printf("%d\t", temp->data);                                                     
        temp = temp->next;                                                                
    }
	printf("%d\t", temp->data);                                                                                     
} 

