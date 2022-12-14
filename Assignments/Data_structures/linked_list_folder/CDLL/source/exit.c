#include	"header_cdll.h"

void exit1( NODE *head )
{
	NODE *temp;
	if( head == NULL ) {
		return ;

	} else {
		temp = head;
		while( head) {
			head = head -> next;
			free ( temp );
			temp = NULL;
			temp = head;
		}
		
		return;
	}
}		
