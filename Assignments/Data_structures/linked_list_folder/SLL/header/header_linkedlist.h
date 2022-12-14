#include	<stdio.h>
#include	<stdlib.h>

int str_atoi( char *str);
int integervalidation(void);
typedef struct SLL {
	
	int data;
	struct SLL *next;
	}NODE;
#define MAX 5
NODE *push(NODE *, int);
void display(NODE *);
NODE *pop(NODE *);

NODE *insert(NODE *);

NODE *del(NODE *);

NODE *insert_big(NODE *,NODE *);

NODE *insert_end(NODE *, NODE *);

NODE *swap_links(NODE *, int, int);
