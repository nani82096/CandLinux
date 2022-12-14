#include	"header.h"

int arr[SIZE];
int top = -1;
int main(void)
{
	int choice;
	int value;
	while(1) {
		printf("\n\n---------STACK---------\n"                                                    
            "1.For Push\n"                                                                
            "2.For POP\n"                                                                 
            "3.For display\n"                                                             
            "4.For EXIT\n");  
		choice = integervalidation();
		switch( choice ) {
			case 1:
				/*reading value and calling the function*/
				printf("\nEnter a value to PUSH into STACK::");
				value = integervalidation();
				push(value);
				break;
			case 2:
				/*checking wheather empty*/
				if ( top == -1)
					printf("STACK is empty\n\n");
				else {
					value = pop();
					printf("The value has been popped from the STACK is %d\n",value);
				}
				break;
			case 3:
		/*checking wheather empty*/
				if ( top == -1)
					printf("STACK is empty\n\n");
				else
					display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Please choose valid options\n\n");
				break;
		}
	}
	return 0;
}

void push(int value)
{
	if ( top == SIZE - 1)
		printf("\nStack is full \n\n");
	else {
		top = top + 1;
		arr[top] = value;
	}
}

int pop(void)
{
	int value;
	value = arr[top];
	top = top - 1;
	return value;
}

void display(void)
{
	int i;
	printf("\nThe values in the stack is \n\n");
	for ( i = top; i >= 0; i--)
		printf("%d ", arr[i]);
	printf("\n\n");
}
