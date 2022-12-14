/* Header for the BST*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

typedef struct BST {
	int count;
	int ln;
	struct BST *left;
	struct BST *right;
	//char *str;
	char str[20];
}NODE;

NODE *insert_BST(NODE *, char *,int);

void traverse_inorder(NODE *);

