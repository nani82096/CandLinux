#include	<stdio.h>
#include	<stdlib.h>
int str_atoi( char *str);
int integervalidation(void);
typedef struct CDLL {
	struct CDLL *prev;
	int data;
	struct CDLL *next;
	}NODE;
void display(NODE *);

void display_back(NODE *);

NODE *cdl_insert(NODE *);

NODE *cdl_del(NODE *);

NODE *insert_big(NODE *,NODE *);

NODE *insert_end(NODE *, NODE *);
