#include	"header.h"

void traverse_inorder(NODE *root)

{
	if(root){
		traverse_inorder(root->left);
		printf("Word = %-30s Word Count = %d line = %d\n",root->str, root->count,root->ln);
	traverse_inorder(root->right);
	}
}
