#include	<stdio.h>

int main(void)
{
	char str[]="Global Edge";
	int front=0;
	int len = strlen(str);
	int end = len-1;
	char str1[len];
	int count = 1;
	while (count <= len){
		if (count%2){
			strncpy(str1+count-1,str+end,count);
			
			end = end - count;
		}else{
			strncpy(str1+count-1,str+front,count);
			front = front + count;
		}
		count++;
	}
	printf ("%s\n",str1);
	return 0;
}
