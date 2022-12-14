#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

int main(int argc, char *argv[])
{
	int line = 0;
	int total = 0;

	int i = argc - 1;
	int flag = 0;
	while (i > 0){
		if (!strcmp(argv[i], "-l")){
			flag = 1;
			break;
		}
		i--;
	}
	if (!flag )
		return 0;
	flag = 0;
	
	i = 1;
	FILE *fp;
	int c;
	while ( i < argc){
		
		if ( !strcmp(argv[i], "-l")){
			i++;
			continue;
		}
		fp = fopen(argv[i], "r");
		if ( fp == NULL){
			printf ("failed in opening file\n");
			return 0;
		}
		while (!feof(fp)){
			c = fgetc(fp);
			if ( c == '\n')
				line++;
		}
		printf ("%3d %s\n", line, argv[i]);
		total = total + line;
		line = 0;
		i++;
		fclose(fp);
		fp = NULL;
		flag++;
	}
	if (flag != 1 && flag != 0)
		printf ("%3d %s\n", total, "total");

	return 0;
}
