#include	"header_linkedlist.h"

int main(void)
{
	NODE *top = NULL;
	/*NODE is type def to the structure 
	typedef struct STACK {    
                                                                                          
    	int data;                                                                             
    	struct STACK *next;                                                                   
    }NODE;
	*/

	int choice;
	int value;
	while ( 1 ) {
		printf("\n-------------STACK LINKED LIST ------------\n"
				"1. PUSH\n"
				"2. POP\n"
				"3. DISPLAY\n"
				"4. EXIT\n");
		choice = integervalidation();
		
		switch ( choice ) {
			
			case 1:
				printf("Enter value to PUSH ::");
				value = integervalidation();
				top = push(top, value);
				break;
			case 2:
				top = pop(top);
				break;
			case 3:
				display(top);
				break;
			case 4:
				exit(1);
			default:
				printf("Enter valid options\n");
				break;

		}
	}
	return 0;
}
NODE *push ( NODE *top, int value)
{
	static int count = 0;
	if (count == MAX) {
		printf("STACK Is full can't add new elements\n");
		return top;
	}
	NODE *new_node = NULL;
	new_node = (NODE *)malloc(sizeof(NODE));
	new_node->data = value;
	new_node->next = NULL;
	if ( top == NULL)
		top = new_node;
	else {
		new_node->next = top;
		top = new_node;
	}
	count++;
	return top;
}

void display( NODE *top)
{
	NODE *temp = top;
	if (top == NULL) {
		printf("List is empty \n");
		return ;
	}
	while ( temp) {
		printf("%d--->", temp->data);
		temp = temp->next;
	}
}
NODE *pop( NODE *top)
{
	NODE *temp = top;
	if ( top == NULL)	{
		printf( "List is empty \n");
		return top;
	} else {
		printf("The value %d has been popped from stack\n\n ",top->data);
		top = top->next;
		free(temp);
		temp = NULL;
	}
	return top;
}
