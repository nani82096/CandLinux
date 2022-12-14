#include "header.h"


void preorder(NODE *root)
{
		NODE *current,*pre;

		if(root == NULL)

				return; 

		current = root;

		pre = root;

		while(current != NULL){


						printf(" %d ", current->data);

						if((current -> lchild == NULL) ){
		
								if(current ->rchild == NULL)
	
									return;

								current = current -> rchild;
								
								if(current == pre->rchild){

										current = current->rchild;

										pre ->rchild = NULL;
	
										pre = current;

								}


						}else{
		
						pre = current->lchild;

						while(pre->rchild != NULL && pre->rchild != current)

								pre = pre->rchild;

						/* Make current as rchild child of its inorder predecessor */
						if(pre->rchild == NULL){

								pre->rchild = current;

								current = current->lchild;
						}

				} /* End of if condition current->lchild == NULL*/
		/* End of while */
	}
}
