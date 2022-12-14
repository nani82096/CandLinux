#include	"header.h"

NODE *pre_max(NODE *root)
{                                                                                         
    NODE *temp = root;                                                                    
    /*loop down to find the right most leaf*/                                             
	if ( temp->right == NULL)
		return temp;
    while(temp->right->right != NULL)                                                            
        temp = temp->right;                                                              
    return temp;                                                                          
}  




NODE *delete_BST(NODE *root, int value)
{
	if ( root == NULL ){
		printf("Element Not Found\n");
		return root;
	}
	if ( value < root->data) 
		root->left =  delete_BST(root->left, value);

	else if ( value > root->data) 
		root->right =  delete_BST(root->right, value);

	else  {
		/*node with one or no child*/
		if ( root->left == NULL) {
			NODE *temp = root->right;
			free(root);
			return temp;
		}
		else if ( root->right == NULL) {
			NODE *temp = root->left;
			free(root);
			return temp;
		} else {			/*With 2 child*/
			NODE *temp = max_bst (root->left);
			NODE *cur = temp;
			/* Max's Least Left Node */
			while ( cur->left){
				cur = cur->left;
			}

			/* Max is right of root then*/ 
			if (root->left == temp) {
				temp->right = root->right;
				free(root);
				return temp;
			}
			else {
				NODE *pre = pre_max (root->left);
				temp->right = root->right;
				pre->right = NULL;
				cur->left = root->left;
				free(root);
				return temp;
			}
		}
		/* 
		 * Node with 2 childs
		 *
		 * Find the MIN of right subtree and swap them with key delete the key
		 */
	/*	NODE *temp = min_bst(root->right);
		root->data = temp->data;
		root->right = delete_BST(root->right,temp->data);
		*/
		/*
		 * Or find the MAX of left subtree and copy them with key delete the max
		 */
	/*	NODE *temp = max_bst(root->left);
		root->data = temp->data;
		root->left = delete_BST(root->left, temp->data);*/
		
	}
	return root;
}



