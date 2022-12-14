#include	<stdio.h>

int main(void)
{
	FILE *fp = fopen("file", "r");
	FILE *fp1 = fopen("tempfile", "w");
	int len = 0;
	char buff[255];
	while(fgets(buff, sizeof(buff), fp)){
		len = strlen(buff);
		printf ("buff = %s\n", buff);
		char buff1[255]="";
		char *str = strtok(buff," ");
		while(str){
			strcat(buff1,str);
			strcat(buff1," ");
			str = strtok(NULL," ");
		}
		printf ("buff1 = %s\n", buff1);
		
		//fseek(fp,-len,SEEK_CUR);
		fputs(buff1,fp1);
		bzero(buff1,sizeof(buff1));
		bzero(buff,sizeof(buff));
		
	}
	remove("file");
	rename("tempfile","file");
	return 0;
}
