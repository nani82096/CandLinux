#include	"header.h"

void traverse_preorder(NODE *root)
{
	int i = 0;
	if (root){
		while(i++ != root->count)
			printf("%d ", root->data);
		traverse_preorder(root->left);
		traverse_preorder(root->right);
	}
}
