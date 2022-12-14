#include	"hdr2.h"

char* mystrtok(char *src, char *dlm)
{
		/*static pointer to point to orinal string always */
		static char *temp = NULL;
		char *temp2 = NULL;
		char *temp3 = NULL;
		int flag = 0;
		if (src != NULL)
				temp = src;
		/*temp3 always points to temp temp points to src initially but changing as delimiter occurs*/
		temp3 = temp;
		while (*temp) {
				/*temp2 pointing to delimiters string*/
				temp2 = dlm;
				while (*temp2) {
						/*if src equals to delimeters then making it to null and returning to temp3 */
						if ( (*temp) == (*temp2)){
								(*temp++) = '\0';
								/* eliminating the first occured delimeters */
								flag = 1;
								if ( (temp-1) == temp3){
									temp3++;
									temp2++;
									continue;
								}
								return temp3;	
						}
						temp2++;
				}
//				if (*temp == '\0')
//						return temp3;
				/*if not equal ot delimeters then increse the temp*/
				if ( flag == 0)
					temp++;
				flag = 0;
		}
		/*returning null if temp3 reaches last string*/
		if ( *temp3 == '\0' )
				return NULL;
		/*returning temp3 if src come to last*/
		if ( *temp == '\0' )
				return temp3;
}
