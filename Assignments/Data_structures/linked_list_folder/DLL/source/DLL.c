#include	"header_dll.h"

int main( void )
{
	int choice;
	NODE *start = NULL;
	while (1) {
		printf("\n\n\n....................MENU..................\n"
				"\t1.INSERTION\n"
				"\t2.DELETION\n"
				"\t3.DISPLAY\n"
				"\t4.DISPLAY BACKWARD\n"
				"\t5.EXIT\n"
				"...............................................\n");
		
		printf("enter choice\n");
		choice = integervalidation();
		
		switch( choice ) {
			
			case 1:
		
				start = dl_insert( start );
				break;
		
			case 2:
				start = dl_del( start );
				break;
	
			case 3:
				display( start );
				break;
			case 4:
				display_back(start);
				break;
			case 5:
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
    while ( temp) {                                                                       
        printf("%d\t", temp->data);                                                     
        temp = temp->next;                                                                
    }                                                                                     
} 

void display_back(NODE *start)
{
	NODE *tail = start;
	while( tail->next != NULL) {
		tail = tail->next;
	}
	while ( tail) {
		printf("%d\t", tail->data);
		tail = tail->prev;
	}
	//printf("%d\t", tail->data);
}

