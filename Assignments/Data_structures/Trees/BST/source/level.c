#include	"header.h"
int height (NODE *root)
{

	if ( root == NULL )
		return 0;
	else {
		int lheight = height (root->left);
		int rheight = height (root->right);
		
		if ( lheight > rheight )
			return ( lheight + 1);
		else 
			return ( rheight + 1);
	}
}
void print_level(NODE *root, int h)
{
	if ( root == NULL)
		return;
	if ( h == 1)
		printf("%d ", root->data);
	else if ( h > 1){
		print_level(root->left, h-1);
		print_level(root->right, h-1);
	}
}
void level_order(NODE * root)
{
	int h = height (root);
	int i = 0;
	for ( i = 1; i <= h; i++){
		print_level(root, i);
		printf ("\n");
	}
}
