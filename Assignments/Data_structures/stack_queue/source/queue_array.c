#include	"header.h"
int arr[SIZE];
int front = -1;
int rear = -1;

int main(void)
{
	int choice;
	int value;
	while(1) {
		printf("\n\n---------QUEUE---------\n"                                                    
			"1.For Enqueue\n"                                                                
			"2.For Dequeue\n"                                                                 
            "3.For display\n"                                                             
            "4.For EXIT\n");  
		choice = integervalidation();
		switch( choice ) {
			case 1:
				printf("\n\nEnter a value to Enqueue into QUEUE::");
				value = integervalidation();
				enqueue(value);
				break;
			case 2:
				if ( front == -1 || front > rear)                                                   
					printf("\nQueue is empty\n\n"); 
				else {
					value = dequeue();
					printf("\n\nThe value has been Dequeued from the QUEUE is %d\n",value);
				}
				break;
			case 3:
				if ( front == -1 || front > rear)
					printf("\nQueus is empty\n\n"); 
				else
					q_display();
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
void enqueue(int value)
{
	if ( rear == SIZE - 1 )
		printf("\n\nQueue is full \n\n");
	else {
		if ( front == -1 )
			front = 0;
		rear = rear + 1;
		arr[rear] = value;
	}
}
int dequeue(void)
{
	int value;
	value = arr[front];
	front = front + 1;
	return value;
}
void q_display(void)
{
	int i;
	printf("\n\nThe values in the QUEUE is \n\n");
	for ( i = front; i <= rear; i++)
			printf("%d ", arr[i]);
	printf("\n\n\n\n");
}
