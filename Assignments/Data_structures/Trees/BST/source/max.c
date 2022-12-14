#include	"header.h"

NODE *max_bst(NODE *root)
{
	NODE *temp = root;
	/*loop down to find the right most leaf*/
	while(temp->right != NULL)
		temp = temp->right;
	return temp;
}
