#ifndef HDR
#define HDR

#define _GNU_SOURCE
/* Header Files */
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<malloc.h>
#include	<unistd.h>

/* For Mapping Frame acronyms */
#define MAX 255
#define getName(var) #var
enum FRM {FRM_001 = 0x18DA00FB, FRM_002 = 0x18DAFB00};  

/* functions */
void list_frames (FILE *, FILE *, char *);
int valid_msg(FILE *, char *, char *);
int store_message (FILE *, int);
int power(int , int );
unsigned int str_to_hex(char *);
unsigned int frame_map(char *); 

#endif

