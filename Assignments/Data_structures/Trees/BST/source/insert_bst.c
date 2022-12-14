#include	"header.h"

NODE *insert_BST(NODE *root, int value)

{

	if (root != NULL && root->data == value){
		root->count++;
		return root;
	}
	if ( root == NULL){
		NODE *temp;
    	temp = (NODE *)malloc(sizeof(NODE));                                                  
    	if ( temp == NULL) {                                                                  
        	printf("Memory not allocated\n");                                                 
        	return root;                                                                      
    	} 
		temp->data = value;                                                                   
    	temp->count = 1;                                                                      
    	temp->left = NULL;                                                                    
	    temp->right = NULL; 
		root = temp;
		return root;
	}
	else if( value < root->data){
		root->left = insert_BST(root->left, value);
	}
	else if ( value > root->data) {
		root->right = insert_BST(root->right, value);
	}
	return root;
}
	
