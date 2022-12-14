#include	<stdio.h>

#include	<stdlib.h>

void get_string(char *, int);
int main(int argc, char *argv[])
{

	//char *str[6] = {"India", "USA","Australia", "NewZeland"};
	if ( argc != 3 ){
		printf ("Error: Usage <%s> <no of strings> <max length of string> \n", argv[0]);
		return 0;
	}

	int i = 0;
	int size = atoi(argv[1]);
	int size1 = atoi(argv[2]);

	char *str[size+1];

	for ( i = 0; i < size; i++){
		
		*(str+i) = (char *)malloc(sizeof(char)*size1);
	
		if ( *(str+i) == NULL)
			perror("malloc");
	}
	*(str+i) = '\0';

	for ( i = 0; i < size; i++)
		
		get_string(*(str+i), size1);

	i = 0;

	while (*(str+i)){
		printf ("str = %s\n", *(str+i));

		i++;
	}
	
	char *ptr1 = NULL;

	i = 0;

	int j = 0;

	printf ("Entered");
	while (*(str+i)){
		
		j = 0;

		while (*(str+j)){
		
			if ( strcmp(*(str+i), *(str+j)) < 0 ) {
			
				ptr1 = *(str+i);

				*(str+i) = *(str+j);

				*(str+j) = ptr1;	

			}
			j++;
		}
		i++;
	}

	printf ("\n");	

	i = 0;

	while (*(str+i)){

		printf ("str = %s\n", *(str+i));

		i++;
	}
	return 0;
}
