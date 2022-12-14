#include "header.h"


void traverse_inorder(NODE *root)
{
	NODE *current,*pre;

	if(root == NULL)

		return; 

	current = root;

	pre = NULL;

	while(current != NULL){
		
		if ( current->left == NULL) {
		
			printf(" %d ", current->data);
			
			current = current->right;
		} else {

			pre = current->left;

			while(pre->right != NULL && pre->right != current)

				pre = pre->right;

			/* Make current as right child of its inorder predecessor */
			if(pre->right == NULL){

				pre->right = current;

				current = current->left;
			} else {
				
				pre->right = NULL;
				
				printf(" %d ", current->data);
		
				current = current->right;
			}

		} /* End of if condition current->left == NULL*/
		/* End of while */
	}
}
