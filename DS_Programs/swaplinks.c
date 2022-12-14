#include	"head.h"
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
		curx = curx -> link;  
	}
	while(cury && cury -> data != y){
		prevy = cury;
		cury = cury -> link;
	}
	if(curx == NULL || cury == NULL)
		return head;
	if(prevx == NULL){
		head = cury;
	}
	else 
		prevx -> link = cury;
	if(prevy == NULL){
		head = curx;
	}
	else
		prevy -> link = curx;
	temp = cury -> link;
	cury -> link = curx -> link;
	curx -> link = temp;
	return head;
}
