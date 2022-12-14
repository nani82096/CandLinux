#include	"header.h"

/* main function*/

int main(void)
{

	int choice;
	NODE *root = NULL;
	int value;
	while (1) {
		printf("\n\n---------------MENU-------------\n"
				"1.Insert Into Tree\n"
				"2.Traverse in Preorder\n"
				"3.Traverse in Inorder\n"
				"4.Traverse in Postorder\n"
				"5.Delete\n"
				"6.Level Order\n"
				"7.Sum of all elements\n"
				"8.Mirror Image of BST\n"
				"9.Exit\n");
		choice = integervalidation();
		switch(choice) {
			
			case 1:
				/*inserting into tree*/
				printf("Enter the data to insert into the Tree:");
				value = integervalidation();
				root = insert_BST(root, value);
				break;
			case 2:
				/*traverse preorder*/
				traverse_preorder( root );
				break;
			case 3:
                /*traverse_inorder*/                                                     
				traverse_inorder(root);
				break;
			case 4:
	            /*traverse_preorder*/                   
				traverse_postorder(root); 
				break;
			case 5:
				printf("Enter the data to delete from the Tree");
				value = integervalidation();
				root = delete_BST(root,value);
				break;
			case 6:
				level_order(root); 
				break;					
			case 7:
				{
				int sum = sum_all(root);
				printf ("sum = %d\n", sum);
				break;
				}
			case 8:
				root = mirror(root);
				break;
			case 9:
				exit(1);
		}
	}
	return 0;

}
