# include <stdio.h>

gl = 10; 
const int gc;
const int rodata = 123;
int gi = 20;
int gsui ;
const static int gcsi;

static const int scgu;
static const int scgi = 100;

int main()
{
		int uv;
		int iv = 10;
		const static int uv1;
		const static int iv1 = 30;

		static int si = 20;
		static int sui;

		static const int ui;
		static const int li = 300;
		return 0;
}

/*Check where stack variables will be stored (in which section??)*/

/*declare register and auto variables globally and locally check what happens 
 * and why register and auto varialbes cant be declared globally?
 */

/* use nm command to see symbol table of  .o and .out file */


