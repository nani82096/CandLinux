#include	"header.h"

NODE *mirror(NODE *root)
{
	if (root == NULL)

		return NULL;

//	if ( root->right == NULL && root->left == NULL )

//		return NULL;

	else {

		NODE *temp = root->left;
		
		root->left = root->right;

		root->right = temp;
		
		root->left = mirror (root->left);

		root->right = mirror (root->right);
		

	}
	return root;

}	
