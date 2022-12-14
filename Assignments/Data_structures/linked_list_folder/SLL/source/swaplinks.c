#include	"header_linkedlist.h"
NODE *swap_links(NODE *head, int x, int y)
{
	if(x == y)
		return head;

	NODE *curx = head;
	NODE *cury = head;
	NODE *prevx = NULL;
	NODE *prevy = NULL;
	NODE *temp;

	while(curx && curx -> data != x){
		prevx = curx;
		curx = curx -> next;  
	}
	while(cury && cury -> data != y){
		prevy = cury;
		cury = cury -> next;
	}

	if(curx == NULL || cury == NULL)
		return head;

	if(prevx == NULL){
		head = cury;
	}
	else 
		prevx -> next = cury;

	if(prevy == NULL){
		head = curx;
	}
	else
		prevy -> next = curx;

	temp = cury -> next;
	cury -> next = curx -> next;
	curx -> next = temp;
	

/*
	if ( x == y )
		return head;

	NODE *curx = head;

	NODE *cury = head;

	while (curx && curx->data != x) {
		curx = curx->next;
	}
	while ( cury && cury->data != y){
		cury = cury->next;
	}
	if (curx == NULL || cury == NULL)
		return head;

	curx->next = (NODE *) ((int )curx->next ^ (int) cury->next);

	cury->next = (NODE *) ((int )curx->next ^ (int) cury->next);

	curx->next = (NODE *) ((int )curx->next ^ (int) cury->next);
*/	
	return head;
}
