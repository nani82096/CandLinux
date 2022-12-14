typedef struct SLL {
	int data;
	struct SLL * next;
	}NODE;

#include	<stdio.h>
#include	<stdlib.h>

NODE *insert(NODE *start)
{
	NODE *temp = start;
	NODE *new = (NODE *)malloc(sizeof(struct SLL));
	printf ("Enter DATA");
	scanf("%d", &new->data);
	new->next = NULL;
	if ( start == NULL){
		start = new;
	}
	else {
		while(temp->next){
			temp = temp->next;
		}
		temp->next = new;
	}
	return start;
}
void display(NODE *start)
{
	NODE *temp = start;
	printf ("Data \n");
	while(temp){
		printf ("%d ", temp->data);
		temp = temp->next;
	}
	printf ("\n");
	return ;
		
}
NODE * delete (NODE *start)
{
	NODE *temp = start;
	if ( start == NULL){
		printf ("List is empty\n");
		return NULL;
	}
	else{
		
		start = start->next;
		free(temp);
		temp = NULL;
	}
	return start;
}


int main(void)
{

	NODE *start = NULL;
	NODE *temp = NULL;
	int c;
	while(1){
		printf ("Enter choice\n"
				"1.insert\n"
				"2.Delete\n"
				"3.Display\n"
				"4.Exit\n");
		scanf("%d", &c);
		switch(c){

			case 1:
				start = insert(start);
				break;
			case 2:
				start = delete(start);
				break;
			case 3:
				display(start);
				break;
			case 4:
				exit(EXIT_SUCCESS);
		}

	}
		return 0;
}
