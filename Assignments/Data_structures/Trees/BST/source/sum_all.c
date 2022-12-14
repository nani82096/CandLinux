#include	"header.h"

int sum_all(NODE* root)
{
	int sum = 0;
	if ( root ==  NULL )
		return sum;
	//sum = sum + root -> data;
	//sum = sum + sum_all(root -> left) + sum_all(root -> right);

	sum = root->data + sum_all(root->left) + sum_all(root->right);
	//int rsum = sum_all(root->right);
				
//	return (lsum+rsum);
	return (sum);
}
