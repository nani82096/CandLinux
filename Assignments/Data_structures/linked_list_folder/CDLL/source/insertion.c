#include	"header_cdll.h"
	
NODE *cdl_insert( NODE *head ) 
{
	NODE *temp = NULL;
	NODE *temp1 = NULL;
	NODE *new_node = NULL;   // It is a new node that is going to add

	int value;  
	int pos;  // position to insert node

	if ( ! ( new_node = (NODE *) malloc ( sizeof(NODE) ) ) ) {
		printf( " error during malloc \n");
		return head;
	}

	int num;
	printf("enter data to insert\n");
	num = integervalidation();

	new_node->data = num;   // giving data to new node
	new_node->next = NULL;
	new_node->prev = NULL;
 
	int option;
	printf("\n\n\n...............INSERT..............\n"
			"\t1.insert at begining\n"
			"\t2.insert at end\n"
			"\t3.insert at middle\n"
			"\t4.insert at penultimate\n"
			"\t5.insert after value\n"
			"\t6.insert before value\n"
			"\t7.insert at position\n"
			"\t8.insert after position\n"
			"\t9.insert before position\n"
			"........................................\n");		
	printf("Enter insert option \n");
	option = integervalidation();
	
	switch( option ) {
		
		case 1:
			/* insert at begining  */	
			if( head == NULL ) {    //checking head node is null or not 
				head = new_node;
				head -> next = head;
				head -> prev = head;
				return head;
			}
			
			new_node -> prev = head -> prev ;
			head -> prev -> next = new_node;
			new_node -> next = head;		
			head -> prev = new_node;
			head = new_node;
			return head ;
			break;
		
		case 2:
			/* insert at end */
            if( head == NULL ) {
        	    head = new_node;
				head -> next = head;
				head -> prev = head;
                return head;
            }
			temp = head;
			new_node -> next = temp ;
			new_node -> prev = temp -> prev;
			temp -> prev -> next = new_node;
			temp -> prev = new_node;
			return head;
			break;
		
		case 3:
			/*  insert at middle */
            if( (head == NULL) || (head -> next == NULL ) ) {
				printf(" not possible to insert at middle \n");
			    return head;
            }
			temp = head;
			temp1 = temp -> next;
			while ( ( ( temp1 -> next ) != head )&& ( ( temp1 -> next -> next ) != head ) ){
				temp = temp -> next;
				temp1 = temp1 -> next -> next; 
			}
			new_node -> next = temp -> next;
			new_node -> prev = temp;
			temp -> next -> prev = new_node;
			temp -> next = new_node;
			return head;
	
		case 4:
			/* insert at penultimate */
            if(head == NULL) {
                printf(" no elements in list to insert at penultimate \n");
                return head;

            } else if ( head -> next == NULL ) {
				temp = head;
				new_node -> next = temp;
				new_node -> prev = temp;
				temp -> next = new_node;
				temp -> prev = new_node;
				head = new_node;
				return head;
			}
     		temp = head;
			temp1 = temp -> next;
			while ( temp1 -> next != head ) {
				temp = temp -> next;
				temp1 = temp1 -> next;
			}
		 	new_node -> next = temp -> next;
			new_node -> prev = temp;
			temp -> next -> prev = new_node;
			temp -> next = new_node;
			return head; 
  				
		case 5:
			/* insert after value */
            if( head == NULL )  {
                printf(" no elements in list to insert  \n");
                return head;
            }
     		printf("enter value to insert  after it\n");
			value = integervalidation();
			
			temp = head;
			while ( temp -> next != head ) {
				if( temp -> data == value ) {
					new_node -> next = temp -> next;
					new_node -> prev = temp;
					temp -> next -> prev = new_node;
					temp -> next = new_node; 
					return head;
				}
			
				temp = temp -> next;
			}
			if( temp -> data == value ) {
				new_node -> next = temp -> next;
				temp -> next = new_node ;
				new_node -> prev = temp;
				head -> prev  = new_node;
				return head;	
			}
			if( ! ( temp -> next != head ) ) {
				printf("value you entered is not found \n ");
				return head;
			}	
		
		case 6:
			/* insert at before value */
            if( head == NULL )  {
                printf(" no elements in list to insert  \n");
                return head;
            }
            printf("enter value to insert  before it\n");
            value = integervalidation();

            temp = head;
			if( temp -> data == value ) {
				head = new_node;
				new_node->next = temp;
				new_node -> prev = temp -> prev;
				temp -> prev -> next = new_node;
				temp -> prev = new_node;
				return head;
			}

            temp1 = temp -> next;
            while ( temp1 -> next ) {
                if( temp1 -> data == value ) {
                    new_node -> next = temp -> next;
					new_node -> prev = temp;
					temp -> next -> prev = new_node;
                    temp -> next = new_node;
                    return head;
                }
                temp = temp -> next;
				temp1 = temp1 -> next;
            }

            if( temp1 -> data == value ) {
				new_node -> next = temp -> next;
				new_node -> prev = temp;
				temp -> next -> prev = new_node;				
                temp -> next = new_node ;
			
                return head;
            } 

            if( ! ( temp1 -> next != head ) ) {
                printf("value you entered is not found \n ");
                return head;
            }
	
		case 7:
			/* insert at position */
            if( head == NULL )  {
                printf(" no elements in list to insert at position \n");
                return head;
            }
            printf("enter position to insert \n");
  			pos = integervalidation();

			temp = head;
			if ( pos == 1) {
				new_node -> next = head;
				new_node -> prev = head -> prev;
				head -> prev -> next = new_node;
				head -> prev = new_node;
				head = new_node;
				return head;
			} else {
				pos--;
				pos--;

				while( ( temp -> next != head ) && ( pos ) ) {
					temp = temp -> next;
					pos--;
				}
	
    		    if( ! ( temp -> next != head ) ) {
            	    printf("position  you entered is out of range \n ");
               		return head;

				} else if ( !pos ) {
					new_node -> next = temp -> next;
					new_node -> prev = temp;
					temp -> next -> prev = new_node;
					temp -> next = new_node;
					return head;
				}
			}	
		
		case 8:
			/* inser node after position */
            if( head == NULL )  {
                printf(" no elements in list to insert after position \n");
                return head;
            }
            printf("enter position to insert after:\n");
            pos = integervalidation();

            temp = head;
			temp1 = temp -> next;
            if ( pos == 1) {
                new_node -> next = temp -> next;
				new_node -> prev = temp;
				temp -> next -> prev = new_node;
				temp -> next = new_node;
              //  head = new_node;
                return head;
            } else {
                pos--;
                pos--;

                while( ( temp1 -> next != head ) && ( pos ) ) {
                    temp1 = temp1 -> next;
                    pos--;
                }
				if( ! ( temp1 -> next != head ) && ( pos == 0 ) ) {
					new_node -> next = temp1 -> next;
					temp1 -> next = new_node;	
					head -> prev = new_node;
					new_node -> prev = temp1;
					return head;

				} else if( ! ( temp1 -> next != head ) ) {
                    printf("position  you entered is out of range \n ");
                    return head;

                } else if ( !pos ) {
                    new_node -> next = temp1 -> next;
					new_node -> prev = temp1;
					temp1 -> next -> prev = new_node;
                    temp1 -> next = new_node;
                    return head;
                }
            }
		case 9:
			/* insert node before position */
            if( head == NULL )  {
                printf(" no elements in list to insert before position \n");
                return head;
            }
            printf("enter position to insert \n");
            pos = integervalidation();

            temp = head;
			temp1 = temp -> next;
            if ( pos == 1) {
                new_node -> next = head;
				new_node -> prev = head -> prev;
				head -> prev -> next = new_node;	
				head -> prev = new_node;
                head = new_node;
                return head;
            } else {
                pos--;
                pos--;

                while( ( temp1 -> next != head ) && ( pos ) ) {
                    temp = temp -> next;
					temp1 = temp1 -> next;
                    pos--;
                }
                if( ! ( temp1 -> next != head ) && ( pos == 0 ) ) {
                    temp -> next = new_node;
					new_node -> prev = temp;
					new_node -> next = temp1;
					temp1 -> prev = new_node;
                    return head;
				}else if( ! ( temp1 -> next != head ) ) {
                    printf("position  you entered is out of range \n ");
                    return head;

                } else if ( !pos ) {
                    new_node -> next = temp -> next;
					new_node -> prev = temp;
					temp -> next -> prev = new_node;
                    temp -> next = new_node;
                    return head;
                }
            }

		default:
			printf("invalid choice ,please re-enter your choice \n");
			return head;
			break;
	}
	
}					











