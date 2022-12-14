#include	"header.h"

NODE *min_bst(NODE *root)
{
	NODE *temp = root;
	/* loop down to find the leftmost leaf*/
	while(temp->left != NULL)
		temp = temp->left;
	return temp;
}
