#include	<stdio.h>
#include	<stdlib.h>
int str_atoi( char *str);
int integervalidation(void);
typedef struct DLL {
	struct DLL *prev;
	int data;
	struct DLL *next;
	}NODE;
void display(NODE *);

void display_back(NODE *);

NODE *dl_insert(NODE *);

NODE *dl_del(NODE *);

NODE *insert_big(NODE *,NODE *);

NODE *insert_end(NODE *, NODE *);
