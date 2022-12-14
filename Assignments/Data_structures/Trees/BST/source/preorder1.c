#include "header.h"


void traverse_preorder(NODE *root)
{
	NODE *current,*pre;

	if(root == NULL)

		return; 

	current = root;

	pre = root;

	while(current != NULL){

		printf(" %d ", current->data);

		if((current -> left == NULL) ){
		
			if(current ->right == NULL)
	
				return;

			current = current -> right;
					
			if(current == pre->right){

				current = current->right;

				pre ->right = NULL;
	
				pre = current;

			}
		} else{
		
			pre = current->left;

			while(pre->right != NULL && pre->right != current)

				pre = pre->right;

			/* Make current as right child of its inorder predecessor */
			if(pre->right == NULL){

				pre->right = current;

				current = current->left;
			}

		} /* End of if condition current->left == NULL*/
		/* End of while */
	}
}
