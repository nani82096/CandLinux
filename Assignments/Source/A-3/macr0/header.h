#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ISALNUM(ch) (((ch >= 'a') && (ch <= 'z')) ||((ch >= 'A') && (ch <= 'Z')) \
										|| ((ch >= '0' ) && (ch <= '9') ))

#define ISALPHA(ch) (((ch >= 'a') && (ch <= 'z')) ||((ch >= 'A') && (ch <= 'Z')))

#define ISDIGIT(ch)  ((ch >= '0' ) && (ch <= '9'))

#define ISPRINT(ch) ((ch >= 0) && (ch <= 31) )

#define ISUPPER(ch) ((ch >= 'A' ) && (ch <= 'Z') ) 

#define ISLOWER(ch) ((ch >= 'a') && (ch <= 'z'))

#define ISXDIGIT(ch) (((ch >= 'a') && (ch <= 'f') ) || ((ch >= 'A' ) && (ch <= 'F')) \
											  ||((ch >= '0' ) && (ch <= '9')))





extern int stringcopy (void ) ;
extern int string_n_copy (void ) ;
extern char *mystrcpy ( char *dst, char *src ) ;
extern int mystrlen (char * dst) ;
extern char *mystrncpy (char *dst, char *src, int num);
extern int myatoi() ;
extern int str_ncat(void) ;
extern char *mystrncat(char *, char *,int ) ;
extern int mystrncmp( char * , char *, int ) ;
extern int str_ncmp(void) ;
extern int str_rchr(void) ;
extern char * mystrrch(char * src, char ch ) ;
extern int str_spn(void) ;
extern int mystrspn( char * ,char * );
extern int str_cspn(void );
extern int mystrcspn( char *, char * ) ;
extern char*  mystrtok(char *,char * ) ;
extern int mystrcasecmp( char * ,char *) ;
extern char *mystrstr( char *, char * ) ;
extern int myisalnum( char ch) ;
extern int myisalpha(char ch) ;
extern int myisdigit(char ch) ;
extern int myisprint(char ch ) ;
extern int myisupper (char ch);
extern int myisxdigit(char ch) ;
extern char *string_valid(void) ;
extern int myislower( char ch) ;
extern char * squeez( char * , char * ) ;
extern int rotate(char * ,char* ) ;
extern int is_alnum(void) ;
extern int is_alpha(void) ;
extern int is_digit(void) ;
extern int is_print(void) ;
extern int is_upper(void) ;
extern int is_xdigit(void) ;
extern int is_lower(void) ;
extern int str_tok(void) ;
extern int str_casecmp(void) ;
extern int str_str(void) ;
extern char input(void) ;
