#include	"header_linkedlist.h"
NODE *del_beg(NODE *head){


	if ( head->next == NULL){
		
		free(head);
		head = NULL;
	}else {
		
		NODE *temp = head;
	
		head = head->next;
	
		free(temp);
	
		temp = NULL;
	}
	return head;
}


int main( void )
{
	int choice;
	NODE *start = NULL;
	NODE *temp1 = NULL;
	NODE *temp2 = NULL;
	while (1) {
		printf("\n\n\n....................MENU..................\n"
				"\t1.INSERTION\n"
				"\t2.DELETION\n"
				"\t3.DISPLAY\n"
				"\t4.Swap links\n"
				"\t5.EXIT\n"
				"\t6.Swap_Adjacent\n"
				"...............................................\n");
		
		printf("enter choice\n");
		choice = integervalidation();
		
		switch( choice ) {
			
			case 1:
		
				start = insert( start );
				break;
		
			case 2:
				start = del( start );
				break;
	
			case 3:
				display( start );
				break;
			case 4:
			{
				int x;
				int y;
				printf ("Enter first element to swap ::");
				x = integervalidation();
				
				printf ("Enter first element to swap ::");
				y = integervalidation();
				start = swap_links(start, x, y );
				break;
			}
			case 5:
				while ( start ){
					start = del_beg(start);
				}
				return 0;
				break;
			case 6:
				temp1 = start;
				temp2 = temp1->next;
				while ( temp1 && temp2) {
				
					start = swap_links(start, temp1->data, temp2->data);

					if ( temp1 && temp2) {	

						NODE *t1 = temp1;

						temp1 = temp2;

						temp2 = t1;
					}

					temp1 = temp2->next;
					if (temp1 != NULL)
						temp2 = temp1->next;

				}		
				break;
			default:
				printf("invalid choice please re-enter choice\n");
				break;
		}
	}
	return 0;
}	
void display( NODE *top)
{
	if (top == NULL) {
		printf("List is empty \n");
		return ;
	}
	while ( top ) {
		printf("%d\t", top->data);
		top = top->next;
	}
} 

