#include	"header.h"

void traverse_postorder(NODE *root)
{

	int i = 0;
	if(root) {
		traverse_postorder(root->left);
		traverse_postorder(root->right);
		while(i++ != root->count)
			printf("%d ", root->data);
	}
}
