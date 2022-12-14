#include	"header.h"

void traverse_inorder(NODE *root)

{
	int i = 0;
	if(root){
		traverse_inorder(root->left);
		while(i++ != root->count)
			printf("%d ", root->data);
		traverse_inorder(root->right);
	}
}
