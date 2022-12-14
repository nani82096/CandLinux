#include	"header.h"

/* main function*/

int main(void)
{

	NODE *root = NULL;

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
	int flag = 0;
	while (!feof(fp)){
		fscanf(fp, "%s", str);
		ln = 0;
		rewind(fp1);
		while (fgets(str2,400,fp1)){
			buff = strtok(str2," \n");
			while (buff){
				if (!strcmp(buff,str))
					flag = 1;
				buff = strtok(NULL," \n");
			}
			if (flag)
				ln++;
			flag = 0;
		}
		root = insert_BST(root, str, ln);
	}
	traverse_inorder(root);
	fclose(fp);
	fclose(fp1);

	return 0;

}
