#ifndef HDR
#define HDR

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<malloc.h>
#include	<unistd.h>

#define MAX 255

struct frame{
	unsigned int fr_id :29;
};

int store_message (char *, char *);
void list_frames (char *, char *);
unsigned int frame_map(char *); 
int valid_msg(FILE *, char *, char *);
#endif

