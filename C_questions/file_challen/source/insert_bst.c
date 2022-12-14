#include	"header.h"

NODE *insert_BST(NODE *root, char *s,int ln)

{
	int cond;
	if ( root == NULL){
		NODE *temp;
    	temp = (NODE *)malloc(sizeof(NODE));
    	if ( temp == NULL) {
        	printf("Memory not allocated\n");
        	return root;
    	}
		strcpy(temp->str,s);
		//memcpy(temp->str,s,strlen(s));   
		//temp->str = strdup(s);
    	temp->count = 1;
		temp->ln = ln;
    	temp->left = NULL;
	    temp->right = NULL; 
		root = temp;
		return root;
	}
	else if( (cond = strcmp(root->str,s)) == 0)
		root->count++;
	else if (cond > 0){
		root->left = insert_BST(root->left, s,ln);
	}
	else if ( cond < 0) {
		root->right = insert_BST(root->right, s,ln);
	}
	return root;
}
	
