/*	Function to Convert BST to Doubly Linked list
 *  root --> Root of Binary Tree 
 *	head --> Pointer to head node of created doubly linked list
 *
 */

NODE* BtoDLL (NODE* root, NODE** head)
{
	// Base Case
	if ( root == NULL )
		return NULL;

	BtoDLL (root->right, head);			// Recursively convert right subtree

	root->right = *head;				// insert root into DLL

	if ((*head) != NULL )				// change left pointer of prev head
		(*head)->left = root;

	(*head) = root;						// Change head of Doubly Linked list

	BtoDLL (root->left, head);			// Recursively convert left subtree
}
