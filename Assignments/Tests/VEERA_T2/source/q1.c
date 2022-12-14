#include	"header.h"

int main(void)
{
	queue *new;
	queue *head;
	queue *rear;
	int priority;
	int data;
	int choice;
	while (1) {
	printf("----------MENU---------\n"
			"1. Enque the priority queue\n"
			"2. Display the priority queue\n"
			"3. To exit from the menu\n");
	choice = integervalidation();
		switch(choice) {
		
			case 1:
				new = (queue *)malloc(sizeof(queue));
				head = (queue *)malloc(sizeof(queue));
				rear = (queue *)malloc(sizeof(queue));
				printf("Enter the data to insert::");
				data = integervalidation();
				printf("Enter the priority of the data having lowest the highest priority\n");
				priority = integervalidation();
				new->data = data;
				new->priority = priority;
				new->next = NULL;
				head = enque(head , new);
				break;
			case 2:
				display(head);
				break;
			case 3:
				exit(1);
			default:
				printf("please enter valid options\n");
		}
	}
	return 0;

}

queue *enque(queue *head, queue *new)
{
	queue *temp;
	if(head == NULL || new->priority < head->priority ) {
		new->next = head;
		head = new;
		return head;
	}
	else{
		temp = head;
		while( temp->next!= NULL && temp->next ->priority <= new->priority) {
			temp = temp->next;
		}
		new->next = temp->next;
		temp->next = new;
	}
	return head;
}


void display(queue* head)
{
	queue * temp = head;
    if (temp == NULL)
       return;
	while (temp ->next){
    	printf("%d \t %d \n", temp->data, temp->priority);
		temp = temp->next;
	}
	
   	printf("%d \t %d \n", temp->data, temp->priority);
}
