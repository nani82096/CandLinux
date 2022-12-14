#include	<stdio.h>
#include	<stdlib.h>
int str_atoi( char *str);
int integervalidation(void);
typedef struct CLL {
	
	int data;
	struct CLL *next;
	}NODE;
void display(NODE *);

NODE *cl_insert(NODE *);

NODE *cl_del(NODE *);

NODE *insert_big(NODE *,NODE *);

NODE *insert_end(NODE *, NODE *);
