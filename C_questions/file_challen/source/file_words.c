#include	"header.h"

int main(void)
{
	FILE *fp = fopen("somefile.txt", "r");
	if (fp == NULL){
		printf ("file openenig failed\n");
		return 0;
	}
	FILE *fp1 = fopen("somefile.txt", "r");
	if (fp1 == NULL){
		printf ("file openenig failed\n");
		return 0;
	}
	
	char *buff;
	char str[20];
	char str2[400];	
	int ln = 0;
	int wc = 0;
	int flag = 0;
	while (!feof(fp)){//
		fscanf(fp, "%s", str);
		ln = 0;
		wc = 0;
		rewind(fp1);	
		//fseek(fp1, ftell(fp), 0);
		//wc++;ln++;
		while (fgets(str2, 400, fp1)){
			buff = strstr(str2, str);
			while (buff) {
				//if ( str <= buff){
				  if ( ftell(fp) < ftell(fp1)){
//					printf("%d %d\n",fp, fp1);

					wc++;
					flag = 1;
				}
				buff  = strstr(buff+strlen(str),str);
			}
			if (flag && ftell(fp) < ftell(fp1) )
				ln++;
			flag = 0;				
		}
		printf ("Word = %s wc = %d ln = %d\n", str, wc, ln); 
	}
	fclose(fp);
	return 0;
}
		
