#include	<stdio.h>

#include	<stdlib.h>

#include	<string.h>

#define SIZE 100


char* mystrcpy(char *, char *); 

int mystrlen(char *);

char* mystrncpy(char *, char *, int);

char* mystrncat(char *, char *, int);

int integervalidation(void);

int str_atoi(char *);

int mystrncmp(char *, char *, int);

char*  ystrrchr(char *, int );

int mystrspn(char *, char *);

int mystrcspn(char *, char*);

char* mystrtok(char *, char *);

char* mystrcat( char *, char *);

int mystrcasecmp(char *, char*);

char* mystrstr(char *, char *);

int myislower(int );

int myisupper(int );

int myiscntrl(int );

int myisxdigit(int );

int myisprint(int );

int myisdigit(int );

int myisalpha(int );

int myisalnum(int );

char* squeeze(char *, char *);


#define ISALNUM(ch) (((ch >= 'a') && (ch <= 'z')) ||((ch >= 'A') && (ch <= 'Z')) \
										|| ((ch >= '0' ) && (ch <= '9') ))

#define ISALPHA(ch) (((ch >= 'a') && (ch <= 'z')) ||((ch >= 'A') && (ch <= 'Z')))

#define ISDIGIT(ch)  ((ch >= '0' ) && (ch <= '9'))

#define ISPRINT(ch) ((ch >= 0) && (ch <= 31) )

#define ISUPPER(ch) ((ch >= 'A' ) && (ch <= 'Z') ) 

#define ISLOWER(ch) ((ch >= 'a') && (ch <= 'z'))

#define ISXDIGIT(ch) (((ch >= 'a') && (ch <= 'f') ) || ((ch >= 'A' ) && (ch <= 'F')) \
											  ||((ch >= '0' ) && (ch <= '9')))

