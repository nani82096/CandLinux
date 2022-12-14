/* Name :: Veera
   Batch:: B-80 
   header file for all libraries and functions declarations and macros definitions */

#include	<stdio.h> /* Including the library file*/

#include	<string.h>

#define		MAX 50	/* defining MAX macro */

char *reverse (char *);  /* function proto type for reverse(s) */

int str_atoi(char *);	/* function proto type for atoi(s) */

char line[MAX];			/* line character array for entab program */

int integervalidation( void );

void show_bits(int );

int bit_swap(int, int, int);

int bit_cp(int, int, int, int);
	
int even_bit_toggle(int );

int odd_bit_toggle(int );

int rotate_bit(int, int, int);

int bit_ts(int, int);

unsigned int reverse_bits(unsigned int num);

int bit_arth(int, int);

int add(int, int);

int sub(int, int);

int count_bit_clear(int );

int count_bit_set(int );

int trailing_zero(int );

int cpy_bits(int, int, int, int, int);

int setbits(int, int, int, int);

int invert(int, int, int) ;

#define FINDINGMAX(num1,num2) (num1 ^ ((num1 ^ num2) & -(num1 < num2)))

#define FINDINGMIN(num1, num2) (num2 ^ ((num1 ^ num2) & -(num1 < num2)))

#define SET(num,p1,p2) ((((~0)<<(p2+1))^((~0)<<(p1)))|num)

#define TOGGLE(num,p1,p2) ((((~0)<<(p2+1))^((~0)<<(p1)))^num)

#define CLEARRIGHTMOST(num) for(i=0;i<31;i++){if((num>>i)&1){num=num&((~0)<<(i+1));break;}}
