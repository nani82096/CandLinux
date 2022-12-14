#include	"header_dll.h"

NODE* dl_del( NODE *start)
{
    NODE *temp = NULL;
    NODE *temp1 = NULL;
	NODE *temp2 = NULL;
	int i = 0;

    int value;
    int pos;

    int option;
    printf("\n\n\n...............DELETE..............\n"
            "\t\t1.delete at begining\n"
            "\t\t2.delete at end\n"
            "\t\t3.delete at middle\n"
            "\t\t4.delete at penultimate\n"
            "\t\t5.delete after value\n"
            "\t\t6.delete before value\n"
            "\t\t7.delete at position\n"
            "\t\t8.delete after position\n"
            "\t\t9.delete before position\n"
            "........................................\n");
    printf("Enter insert option \n");
    option = integervalidation();

    switch( option ) {

		case 1:
			/* delete at begining */
			if( start == NULL ) {
				printf(" no elements to delete \n ");
				return start;
			}
			if ( start->next == NULL) {
				free(start);
				start = NULL;
				return start;
			}
			temp = start;	
//			temp = temp -> next;
			start = start -> next;
			start->prev = NULL;
			free ( temp );
			temp = NULL;
			return start;
			break;
		case 2:
			/* delete at end */
			if( start == NULL ) {
				printf(" no elements in list to delete \n ");
				return start;

			} else if ( start -> next == NULL ) {
				start = NULL;
				return start;
			}			
			temp = start;
			while ( temp -> next -> next ) {
				temp = temp -> next ;
			}
			temp1 = temp->next;
			free ( temp1);
			temp1 = NULL;
			temp -> next = NULL;
			return start;
			break;		
	
		case 3:
			/* delete at middle */
            if( start == NULL ) {
                printf(" no elements in list to delete \n ");
                return start;

            } else if ( start -> next == NULL ) {
                printf(" there is only one element in the list , so deletion not posible in middle\n");
                return start;
  			}
			temp = start;
			temp1 = temp->next;
			
			while ( ( temp1 -> next ) && ( temp1 -> next -> next ) ) {
				temp = temp -> next;
				temp1 = temp1 -> next -> next;
			}
			temp1 = temp->next;
			temp2 = temp1->next;
			temp -> next = temp2;
			temp2 -> prev = temp;
			
			free ( temp1 );
			temp1 = NULL ;
			return start ;
			break;
		
		case 4:
			/* delete at penultimate */
            if( start == NULL ) {
                printf(" no elements in list to delete \n ");
                return start;

            } else if ( start -> next == NULL ) {
                printf(" there is only one element in the list , so deletion not posible at penultimate\n");              
                return start;
			}
              
			temp = start;
			temp1 = temp -> next -> next;
			
			while ( temp1 -> next ) {
				temp = temp -> next;  
				temp1 = temp1 -> next ;
			}
			temp1 = temp -> next;
			temp2 = temp1 ->next;
            temp -> next = temp2;
			temp2 ->prev = temp;
            free ( temp1 );
            temp1 = NULL ;
            return start ;
            break;

		case 5:
			/* delete after value */
            if( start == NULL ) {
                printf(" no elements in list to delete \n ");
                return start;
            }
			printf("enter value to delete \n");
			value = integervalidation() ;
			
			temp = start;
			
			while ( ( temp -> next ) && ( temp -> data != value ) ) {
				temp = temp -> next ;
			}
			if( !(temp -> next )) {
				printf(" the value you entered has not found \n");
				return start;

			}else if ( temp -> data == value  ) {
				temp1 = temp -> next;
				temp2 = temp1->next;		
				temp -> next = temp2;
				temp2->prev = temp;
				free ( temp1 );
				temp1 = NULL;
				return start;
			}
			break;

		case 6:
			/* delete before value */
            if( start == NULL ) {
                printf(" no elements in list to delete \n ");
                return start;
            }
            printf("enter value to delete \n");
            value = integervalidation() ;

            temp = start;
			if( temp -> data == value ) {
				printf(" value is at 1st position , no node before 1st position \n ");
				return start;

			} else if ( temp -> next -> data == value ) {
				start = start -> next ;
				start ->prev = NULL;
				free( temp );
				temp = NULL ;
				return start;
			} else { 
				temp1 = temp;
				temp = temp -> next -> next;

	            while ( ( temp -> next ) && ( temp -> data != value ) ) {
    	            temp = temp -> next ;
					temp1 = temp1 -> next;

    	        } if ( temp -> data == value ) {
					temp = temp1 -> next;
					temp2 = temp->next;
        	        temp1 -> next = temp2;
					temp2->prev = temp1;
                	free ( temp );
	                temp = NULL;
    	            return start;

        	    } else if ( !( temp -> next ) ) {
					printf (" value you entered is not found \n ");
					return start;
				}
            }
			break;
		case 7:
			/* delete at position */
            if( start == NULL ) {
                printf(" no elements in list to delete \n ");
                return start;
            }
            printf("enter position to delete \n");
            pos = integervalidation() ;
			if( pos == 1 ) {
				start = start -> next;
				free ( temp );
				temp = NULL;	
				return start;
			}
            temp = start;
 			pos--;
			pos--;
			while ( ( temp -> next ) && pos ) {
				temp = temp -> next ;
				pos--;
			}
			
			if( ! ( temp -> next ) ) {
				printf(" position you entered is out of range \n ");
				return start;

			} else if ( !pos && temp->next->next != NULL ) {
				temp1 = temp -> next ;
				temp2 = temp1->next;
				temp -> next = temp2 ;
				temp2->prev = temp;
				free( temp1);
				temp1 = NULL;
				return start;
			} else if ( !pos && temp->next->next == NULL) {
				temp1 = temp->next;
				temp->next = NULL;
				free(temp1);
				temp1 = NULL;
				return start;
			}
			break;					
		
		case 8:
			/* delete after position */
            if( start == NULL ) {
                printf(" no elements in list to delete \n ");
                return start;
            }
  
            printf("enter position to delete \n");
            pos = integervalidation() ;

            if( pos == 1 && start->next->next != NULL) {
				temp = start;
                temp = temp -> next;
				temp2 = temp->next;
				start -> next = temp2;
				temp2->prev = start;
                free ( temp );
                temp = NULL;
                return start;
            }
			else if ( pos == 1 && (start->next->next == NULL) ) {
				temp = start;
				temp1 = temp->next;
				temp->next = NULL;
				free(temp1);
				temp1 = NULL;
				return start;
			}
            temp = start;
            pos--;
           // pos--;
            while ( ( temp -> next ) && pos ) {
                temp = temp -> next ;
                pos--;
            }

            if( ! ( temp -> next ) ) {
                printf(" position you entered is out of range \n ");
                return start;

            } else if ( !pos  && temp->next != NULL) {
                temp1 = temp -> next ;
				temp2 = temp1 ->next ;
                temp -> next = temp2 ;
				temp2 -> prev = temp ;
                free( temp1);
                temp1 = NULL;
                return start;
            } else if ( !pos && temp->next == NULL) {
				temp1 = temp->next;
				temp->next = NULL;
				free (temp1);
				temp1 = NULL;
				return start;
				}
 			break;

    	case 9:
			/*  delete before position  */
			temp = start;
			temp1 = NULL;
            if( start == NULL ) {
                printf(" no elements in list to delete \n ");
                return start;
            }
            printf("enter position to delete \n");
            pos = integervalidation() ;
  			
			if ( pos == 1 ) {
				printf(" there is no node before position 1\n");
				return start;

			}
			
			pos = pos - 3;
			temp = start;
			if( pos ==-1 ) {
				start = start -> next;
				start->prev = NULL;
				free( temp );
				temp = NULL;
				return start;
			}

			while ( ( temp -> next )  && ( pos ) ) {
				temp = temp -> next;
				pos--;
			}

            if( ! ( temp -> next ) ) {
                printf(" position you entered is out of range \n ");
                return start;

            } else if ( !pos ) {
                temp1 = temp -> next ;
				temp2 = temp1 ->next;
                temp -> next = temp2 ;
				temp2->prev = temp;
                free( temp1);
                temp1 = NULL;
                return start;
            }
   

			break;			
	

		default:
			printf(" invalid option , choose valid option \n");
			return  start;
			break;
	}
}	
	
