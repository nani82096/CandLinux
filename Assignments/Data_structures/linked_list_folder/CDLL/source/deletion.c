#include	"header_cdll.h"

NODE* cdl_del( NODE *head)
{
    NODE *temp = NULL;
    NODE *temp1 = NULL;
	int i = 0;

    int value;  // value to search for delete before and after
    int pos;    // position to delete

    int option;
    printf("\n\n\n...............DELETE..............\n"
            "\t1.delete at begining\n"
            "\t2.delete at end\n"
            "\t3.delete at middle\n"
            "\t4.delete at penultimate\n"
            "\t5.delete after value\n"
            "\t6.delete before value\n"
            "\t7.delete at position\n"
            "\t8.delete after position\n"
            "\t9.delete before position\n"
            "........................................\n");
    printf("Enter insert option \n");
    option = integervalidation();

    switch( option ) {

		case 1:
			/* delete at begining */
			temp = head;
			if( head == NULL ) {
				printf(" no elements to delete \n ");
				return head;
			} else if ( head -> next == head ) {
				free( head ) ;
				head = NULL;
			//	head = temp;
			}
			else {	
			temp->prev -> next = temp->next;
			temp->next->prev = temp->prev;
			head = temp->next;
			free ( temp );
			temp = NULL;
			}
			return head;
			break;
		case 2:
			/* delete at end */
			if( head == NULL ) {
				printf(" no elements in list to delete \n ");
				return head;

			} else if ( head -> next == head ) {
				free(head);
				head = NULL;
				return head;
			}			
			temp = head -> prev ;
			head -> prev -> prev -> next = head;
			head -> prev = head -> prev -> prev;
			free( temp );
			temp = NULL;
			return head;
			break;		
	
		case 3:
			/* delete at middle */
            if( head == NULL ) {
                printf(" no elements in list to delete \n ");
                return head;

            } else if ( head -> next == head ) {
                printf(" there is only one element in the list , so deletion not posible in middle\n");
                return head;
  			}
			temp = head;
			temp1 = temp -> next;
			
			while ( ( temp1 -> next != head) && ( temp1 -> next -> next != head) ) {
				temp = temp -> next;
				temp1 = temp1 -> next -> next;
			}
			temp1 = temp -> next;
			temp -> next = temp1 -> next;
			temp1 -> next -> prev = temp;
			free ( temp1 );
			temp1 = NULL ;
			return head ;
			break;
		
		case 4:
			/* delete at penultimate */
            if( head == NULL ) {
                printf(" no elements in list to delete \n ");
                return head;

            } else if ( head -> next == head ) {
                printf(" there is only one element in the list , so deletion not posible at penultimate\n");              
                return head;

			} else if ( head -> next -> next == head ) {
				temp = head;
				head = head ->next;
				head -> next = head;
				head -> prev = head;
				free( temp );
				temp = NULL;
				return head;	
			}			
              
			temp = head;
			temp1 = temp -> next -> next;
			
			while ( temp1 -> next != head ) {
				temp = temp -> next;  
				temp1 = temp1 -> next ;
			}
			temp1 = temp -> next;
            temp -> next = temp1 -> next;
			temp1 -> next -> prev = temp;
            free ( temp1 );
            temp1 = NULL ;
            return head ;
            break;

		case 5:
			/* delete after value */
            if( head == NULL ) {
                printf(" no elements in list to delete \n ");
                return head;
            }
			printf("enter value to delete \n");
			value = integervalidation() ;
			
			temp = head;
			
			while ( ( temp -> next != head ) && ( temp -> data != value ) ) {
				temp = temp -> next ;
			}

			if( !(temp -> next != head ) && temp -> data == value ) {
                printf(" the value you entered is at last node , no elements after it  \n");
				return head;

			} else if( ! ( temp -> next != head ) ) {
				printf(" the value you entered has not found \n");
                return head;
	
			} else if ( temp -> data == value ) {
				temp1 = temp -> next;
				temp -> next = temp -> next -> next;
				temp1 -> next -> prev = temp;
				free ( temp1 );
				temp1 = NULL;
				return head;
			}
			break;

		case 6:
			/* delete before value */
            if( head == NULL ) {
                printf(" no elements in list to delete \n ");
                return head;
            }
            printf("enter value to delete \n");
            value = integervalidation() ;

            temp = head;
			if( temp -> data == value ) {
				printf(" value is at 1st position , no node before 1st position \n ");
				return head;

			} else if ( temp -> next -> data == value ) {
				head = temp -> next ;
				head -> prev = temp -> prev;
				temp -> prev -> next = head;
				free ( temp ) ;
				temp = NULL;
				return head;
			} else { 
				temp1 = temp;
				temp = temp -> next -> next;

	            while ( ( temp -> next != head ) && ( temp -> data != value ) ) {
    	            temp = temp -> next ;
					temp1 = temp1 -> next;

    	        } if ( temp -> data == value ) {
					temp = temp1 -> next;
        	        temp1 -> next = temp1 -> next -> next;
					temp -> next -> prev = temp1;
                	free ( temp );
	                temp = NULL;
    	            return head;

        	    } else if ( !( temp -> next != head ) ) {
					printf (" value you entered is not found \n ");
					return head;
				}
            }
			break;
		case 7:
			/* delete at position */
            if( head == NULL ) {
                printf(" no elements in list to delete \n ");
                return head;
            }
            printf("enter position to delete \n");
            pos = integervalidation() ;
			if( pos == 1 ) {
				temp = head;
				head = head -> next;
    	        temp->prev -> next = temp->next;
        	    temp->next->prev = temp->prev;
       	    	free ( temp );
        	    temp = NULL;
				return head;
			}
            temp = head;
 			pos--;
			pos--;
			while ( ( temp -> next != head ) && pos ) {
				temp = temp -> next ;
				pos--;
			}
			
			if( ! ( temp -> next != head) ) {
				printf(" position you entered is out of range \n ");
				return head;

			} else if ( !pos ) {
				temp1 = temp -> next ;
				temp -> next = temp -> next -> next ;
				temp1 -> next -> prev = temp;
				free( temp1);
				temp1 = NULL;
				return head;
			}
			break;					
		
		case 8:
			/* delete after position */
            if( head == NULL ) {
                printf(" no elements in list to delete \n ");
                return head;
            }
  
            printf("enter position to delete \n");
            pos = integervalidation() ;

            if( pos == 1 ) {
                temp = head -> next;
				head -> next = head -> next -> next;
				temp -> next -> prev = head;
                free ( temp );
                temp = NULL;
                return head;
            }
            temp = head;
            pos--;
           // pos--;
            while ( ( temp -> next != head ) && pos ) {
                temp = temp -> next ;
                pos--;
            }

            if( ! ( temp -> next != head ) ) {
                printf(" position you entered is out of range \n ");
                return head;

            } else if ( !pos ) {
                temp1 = temp -> next ;
                temp -> next = temp -> next -> next ;
				temp1 -> next -> prev = temp;
                free( temp1);
                temp1 = NULL;
                return head;
            }
 			break;

    	case 9:
			/*  delete before position  */
			temp = head;
			temp1 = NULL;
            if( head == NULL ) {
                printf(" no elements in list to delete \n ");
                return head;
            }
            printf("enter position to delete \n");
            pos = integervalidation() ;
  			
			if ( pos == 1 ) {
				printf(" there is no node before position 1\n");
				return head;

			}
			
			pos = pos - 3;
			temp = head;
			if( pos ==-1 ) {
				head = head -> next;
				head -> prev = temp -> prev ;
				temp -> prev -> next = head;
				free( temp );
				temp = NULL;
				return head;
			}

			while ( ( temp -> next != head )  && ( pos ) ) {
				temp = temp -> next;
				pos--;
			}

            if( ! ( temp -> next != head ) ) {
                printf(" position you entered is out of range \n ");
                return head;

            } else if ( !pos ) {
                temp1 = temp -> next ;
                temp -> next = temp -> next -> next ;
				temp1 -> next -> prev = temp;
                free( temp1 );
                temp1 = NULL;
                return head;
            }
   

			break;			
	

		default:
			printf(" invalid option , choose valid option \n");
			return  head;
			break;
	}
}	
	
