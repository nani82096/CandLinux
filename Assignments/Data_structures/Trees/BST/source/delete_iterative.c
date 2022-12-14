/**
 * BST Deleting using iterative Method 
 * Cond	1 : No Children
 * Cond	2 : One Child
 * Cond	3 : Both Children
 * Carefull of dangling Pointers 
 * Pointers Used ::
	
	* temp in delete_BST --- > Max of targets left
	* cur  --- > Min of Max Node
	* parent --- > parent of targeted node
	* search --- > Target Node
	* pre --- > parent of max 
	* child --- > Child of targets node in case 2
 * Here in every Case again two Conditions were considered, Those are if target node is having parent 
   And not having a parent i.e the root node.
 */

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
	NODE *search = root;
	NODE *parent = NULL;

	/* Finding the Targeted Node to Delete */
	while (search != NULL && search->data != value ) {
		parent = search;
		if ( value < search->data)
			search =  search->left;
		else if (  value > search->data) 
			search = search->right;
	}
	if ( search == NULL) {
		printf ("Not Found the element\n");
		return root;
	}	


	/* With No Child */
	if ( (search->left == NULL) && (search->right == NULL)) {	

		if ( parent == NULL)
			root = NULL;
		else if ( parent->left == search)
			parent->left = NULL;
		else 
			parent->right = NULL;
		free(search);				/* No need to make search = NULL since it is not having any child i.e not pointing to any node */
		return root;

	} else if ( search->left == NULL || search->right == NULL ) {			/* Node With Single Child */

		NODE *child = NULL;
		/* Finding the Target's Child i.e Any one child left  or right */
		if ( search->left != NULL)
			child = search->left;
		else 
			child = search->right;


		/* If target is root then  Root will be Targets child , i.e roots child either left or right */
		if ( parent == NULL ) 
			root = child;
		/* if Target is Parents left child then parents left will be Targets child else parents left is targets child */
		else if ( search == parent->left )
			parent->left = child;
		else 
			parent->right = child;

		free(search);
		search = NULL;		
		return root;	

	} else { /*With 2 child*/
		
		/* Maximum of targets left */
		NODE *temp = max_bst (search->left);
		
		/* Max's Least Left Node */
		NODE *cur = temp;
		while ( cur->left){
			cur = cur->left;
		}


		/* Max is right of root */ 
		if (search->left == temp ) {

			temp->right = search->right;
			/* If Target is root then make the Max as root. */
			if ( parent == NULL) {
				root = temp;
				free(search);
				search = NULL;
				return root;
			}

			/* If Target has Parent, Parent has to adopt Max of Child and kill present Child */
			if ( search = parent->right)
				parent->right = temp;
			else 
				parent->left = temp;

			free(search);
			search = NULL;
		} else {
		
			NODE *pre = pre_max (search->left);					/* Parent of Max */
			temp->right = search->right;						/* Attach what there in target's right Node to max's Right Node */
			pre->right = NULL;
			cur->left = search->left;							/* Attach Waht there in targets's left Node to Max's least left Node*/
			if ( parent == NULL){									/* If target is root i.e No Parent */
				root = temp;
				free(search);
				search = NULL;
				return root;
			}
			/* If Target has Parent, Parent has to adopt Max of Child and kill present Child */
			
			if (search = parent->left)
				parent->left = temp;
			else 
				parent->right = temp;
	
			free(search);
			search = NULL;
		}
	}
	return root;
}
