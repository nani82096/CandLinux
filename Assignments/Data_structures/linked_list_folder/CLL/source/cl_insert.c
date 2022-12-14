#include	"header_cll.h"

NODE *cl_insert(NODE *start)

{
	int choice;
	int value;
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
			while ( i < pos && temp->next != start ) {
				if ( i+1 == pos)
					break;
				i++;
				temp = temp->next;
			}
			if ( pos == i+1) {
				if ( temp->next == start) {
					new->next = start;
					temp->next = new;
				}
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
			while ( i < pos - 2 && temp->next != start ) {                                     
                i++;                                                                      
                temp = temp->next;                                                        
            }                                                            
			if ( temp->next == start)                                                  
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
            while ( i < pos && temp->next != start ) {                                 
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
			/*insert at middle point */
			NODE *temp2 = start;
			temp = start;
			if ( start == NULL)
				printf("List is empty \n");
			while ( (temp2->next != start) && (temp2->next->next != start) ) {    //if condition is true then finding the mid NODE                                                                              
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
			while (temp->next->data != pos && temp->next->next != start)
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
			while ( temp->data != pos && temp->next != start) {
				temp = temp->next;
			}
			if ( temp->data == pos ) {
				new->next = temp->next;
				temp->next = new;
				printf("Value inserted After the value %d\n",pos);
			}
			
			else
				printf("Value not found to insert\n");
			return start;
		case 9:

			/* inserting at the penultimate node*/
			temp = start;
			if ( start == NULL) {
				printf("List is empty\n");
				return start;
			}
			if ( start->next == start) {
				printf("Only one node is there\n");
				return start;
			}
			while ( temp->next->next != start)
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
/*Insert Begining postion*/
NODE *insert_big(NODE *start, NODE *new)
{
	NODE *temp = start;
	if ( start == NULL)  {                                                          
		start = new;
		start->next = start;
	}                                                         
	else{
		while ( temp->next != start) {
			temp = temp->next;
		}
		new->next = start;
		start = new;
		temp->next = start; 
	return start;
	}
}

/*Insert at the ending*/
NODE *insert_end(NODE *start, NODE *new)
{
	if ( start == NULL) {
		start = new;
		start->next = start;	
	}
	NODE *temp = start;
	while (temp->next != start)
		temp = temp->next;
	new->next = start;
	temp->next = new;
	return start;

}
