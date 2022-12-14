#include	"head.h"
NODE *selection_ll(NODE *head)
{
	int min = 0;
	NODE *p = head;
	NODE *q = NULL;
	int i;
	while(p->link){
		q = p -> link;
		while(q) {

			if((p->data) > (q->data)) {
				head = swap_links(head,p->data,q->data);
				NODE * temp = p;
				p = q;
				q = temp;
			}
				
			q = q->link;
		}
		p = p -> link;
	}
	return head;
}

/*NODE * selection_ll(NODE *head)
{
	NODE *curr = NULL;
    NODE *temp = NULL;
	int temp1;

	for(curr = head; curr->link  != NULL; curr = curr -> link) {

		for(temp = curr -> link; temp != NULL; temp = temp -> link) {

				if(temp -> data < curr -> data) {

						temp1 = temp -> data;
						
						temp -> data = curr -> data;

						curr -> data = temp1;
					
					head = swap_links(head,temp->data,curr->data) ;
				}

					
		}
	}
	return head;
}*/
