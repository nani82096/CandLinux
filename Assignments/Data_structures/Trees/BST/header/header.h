/* Header for the BST*/

#include	<stdio.h>
#include	<stdlib.h>

typedef struct BST {
	int data;
	int count;
	struct BST *left;
	struct BST *right;
}NODE;

int integervalidation(void);
int sum_all (NODE*);


int str_atoi(char *);

NODE *insert_BST(NODE *, int);

void traverse_preorder(NODE *);

void traverse_inorder(NODE *);

void traverse_preorder(NODE *);

NODE *delete_BST(NODE*, int);

NODE *max_bst(NODE *);

NODE *min_bst(NODE *);

void level_order(NODE * );

void print_level(NODE *, int);

int height ( NODE *);

NODE *mirror(NODE *);
