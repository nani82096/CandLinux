#include	"header_linkedlist.h"

NODE *insert(NODE *start)

{
	int choice;
	NODE *temp;
	NODE *new;
	
	int data;
	printf("Enter value to insert into the list:");                                       
    data = integervalidation();                                                          
    new = (NODE*)malloc(sizeof(NODE));                                                    
    new->data = data;                                                                    
    new->next = NULL; 
	int i = 1;
	int pos;
	printf("\n\t\t\t\t------------INSERT-----------\n\n"
			"\t\t1.At beginning\n"
			"\t\t2.At end\n"
			"\t\t3.At Position\n"
			"\t\t4.Before position\n"
			"\t\t5.After position\n"
			"\t\t6.At midile position\n"
			"\t\t7.Before Value\n"
			"\t\t8.After Value\n"
			"\t\t9.At penultimation\n\n");
	choice = integervalidation();
	switch(choice) {
		
		case 1:
			start = insert_big(start,new);
			printf("value iserted at the begining\n");
			return start;
			break;
		case 2:
			start = insert_end(start,new);
			printf("value inserted at End\n");
			return start;
			break;
		case 3:
			i = 1;
			printf("Enter position to insert:");
			pos = integervalidation();
			temp = start;
			if ( pos == 1 ) {
				start = insert_big(start,new);
				printf("value inserted at %d\n", pos);
				return start;
			}
			while ( i < pos && temp->next != NULL ) {
				if ( i+1 == pos)
					break;
				i++;
				temp = temp->next;
			}
			if ( pos == i+1) {
				if ( temp->next == NULL)
					temp->next = new;
				else {
					new->next = temp->next;
					temp->next = new;
				}
				printf("value inserted at %d\n", pos);
			} else {
				printf("position is out of range cant insert value\n ");
			}
			return start;
			break;
		case 4:
			i = 1;
			printf("Enter position to insert before postion:");
			pos = integervalidation();
			temp = start;
			if ( pos == 1 || pos  == 2) {
				start = insert_big(start,new);
				return start;
			}
			while ( i < pos - 2 && temp->next != NULL ) {                                     
                i++;                                                                      
                temp = temp->next;                                                        
            }                                                            
			if ( temp->next == NULL)                                                  
                    printf("There is no %d position so cant insert before it\n",pos);                                                     
			else if (i == pos -2){
				new->next = temp->next;
				temp->next = new;                                                        
                printf("value inserted Before %d\n", pos);                                    
            }
            return start;                                                                 
            break;
		case 5:
			i = 1;
			printf("Enter position to insert After postion:");                           
            pos = integervalidation();                                                    
            temp = start;                                                                
            while ( i < pos && temp->next != NULL ) {                                 
                i++;                                                                      
                temp = temp->next;                                                        
            }                                                                             
			if (i == pos){                                                        
                new->next = temp->next;                                                   
                temp->next = new;                                                         
                printf("value inserted After %d\n", pos);                                    
            }
			else
				printf("No Position Found to insert\n");                                                                             
            return start;                                                                 
            break; 
		case 6:
				{
			NODE *temp2 = start;
			temp = start;
			if ( start == NULL)
				printf("List is empty \n");
			while ( temp2->next && temp2->next->next ) {    //if condition is true then finding the mid NODE 
				temp = temp->next;                                                              
				temp2 = temp2->next->next;                                                                                
			}
			new->next = temp->next;                                                   
			temp->next = new;                                                         
			printf("value inserted At middle  \n");
			return start;
			break;
		}
		case 7:
			temp = start;
			if ( start == NULL) {
				printf("List is empty\n");
				return start;
			}
			/*using the same varible for Before value*/
			printf("Enter the value to add Before this value:");
			pos = integervalidation();
			if ( pos == start->data) {
				start = insert_big(start,new);
				printf("value Inserted Before the value %d\n",pos);
				return start;
			}
			while (temp->next->data != pos)
				temp = temp->next;
			if ( temp->next->data == pos) {
				new->next = temp->next;
				temp->next = new;
				printf("value Inserted Before the value %d\n",pos);
			}
			else
				printf("Value not found to insert\n");
			return start;
			
		case 8:
			temp = start;
			if ( start == NULL) {
				printf("List is empty\n");
				return start;
			}
			/*using the same varible for After value*/
			printf("Enter value to add after that value:");
			pos = integervalidation();
			while ( temp->data != pos) {
				temp = temp->next;
			}
			if ( temp->data == pos) {
				new->next = temp->next;
				temp->next = new;
				printf("Value inserted After the value %d\n",pos);
			}
			else
				printf("Value not found to insert\n");
			return start;
		case 9:
			temp = start;
			if ( start == NULL) {
				printf("List is empty\n");
				return start;
			}
			if ( start->next == NULL) {
				printf("Only one node is there\n");
				return start;
			}
			while ( temp->next->next != NULL)
				temp = temp->next;
			new->next = temp->next;
			temp->next = new;
			printf("Value inserted at penultimate position\n");
			return start;
		
		default :
			printf("Enter valid option\n\n");		
			return start;
			break;
	}
}

NODE *insert_big(NODE *start, NODE *new)
{
	if ( start == NULL)                                                           
		start = new;                                                              
	else{
		new->next = start;
		start = new;
	} 
	return start;
}
NODE *insert_end(NODE *start, NODE *new)
{
	if ( start == NULL ) {
		start = new;
		return start;
	}
	NODE *temp = start;
	while (temp->next != NULL) {
		temp = temp->next;
		}
	temp->next = new;
	return start;
}
