#include	<stdio.h>

#include	<stdlib.h>

typedef struct p_q{
	int priority;
	int data;
	struct p_q *next;
	}queue;

typedef struct lkd{
	int data;
	struct lkd *next;
	}node;

queue *enque(queue *, queue*);

node *insert(node *, node *);

void display(queue *);
void displayld(node*);
int integervalidation(void);

int mystratoi(char *);

