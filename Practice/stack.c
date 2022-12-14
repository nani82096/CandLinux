#include	<stdio.h>

int fun(){
		char buf1[5]="AAAAAAAA";
//		char buf2[10]="BBBBBBBBBBBB";
		char *ret;;
		int *ptr;

/*		int o=50;
		while(o--){
				printf("%c\n",*ret);
				ret--;
				printf("%p\n",ret);
		}
		printf("buf1  %p\n",buf1);
		printf("buf2 %p\n",buf2);
		printf("buf2+1 %p\n",&buf2+1);
		printf("adress ret %p\n",&ret);*/
		ret=buf1+17;
		ptr=ret;
		*ptr=*ptr+2;
		//printf("ret + 13  %p\n",ret);
	//	(*ret) += 8;
}
int main(void) {

		int x;
		
		x = 10;
		fun();
		x = 99;
		printf("value of x is %d\n",x);
}

