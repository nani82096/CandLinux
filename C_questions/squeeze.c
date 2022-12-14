#include	<stdio.h>

#include	<stdlib.h>

int main (void)
{
	char buff[] = "Hi Manideep               Hello               how";
	
	char *ptr = buff;
	char *p = NULL;

	while (*ptr){
		
		if ( *ptr == *(ptr+1) ){
		//if ( (*ptr == ' ' && *(ptr+1) == ' ' )){
	
		/* p = ptr;
			while(*p != ' '){
				p++;
			}*/
			memmove (ptr, ptr+1, strlen(ptr));	
			ptr--;
		
		}

		ptr++;
	}
	printf ("buff = %s\n", buff);
	return 0;

}
