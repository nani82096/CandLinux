#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>

struct DB{                                                                                
    char *name;                                                                        
    int emp_id;                                                                           
    int ph_no;                                                                            
    int batch;                                                                            
    char *mail;                                                                        
}data;

int main(void)

{
	data.name = (char *)malloc(sizeof(char)*50);
	data.mail = (char *)malloc(sizeof(char)*50);
	int choice,i = 0;
	struct DB *emp;
	char id[10];
	emp = &data;
	char name[50];
	char temp [500];
	FILE *fptr;
	char nll = '\0';
	if ((fptr = fopen ("GESL","r+")) == NULL)
		printf("falied to open file\n");
	while (1){
		printf("**********Welcome To GESL**********\n"
				"Enter 1. Update the Database\n"
				"Enter 2. Show the Database\n"
				"Enter 3. To remove Entry from database\n"
				"Enter 4. To Exit from the Database\n");
		scanf("%d", &choice);
		getchar();
		switch( choice ){

			case 1:
				printf("Enter name::");                                                               
			    fgets(name, 50,stdin);
				name[strlen(name)-1] = '\0';
				strcpy(emp->name,name);
			    printf("Enter id::");                                                                 
			    scanf("%d", &emp->emp_id);                                                            
			    printf("Enter ph::");                                                                 
			    scanf("%d", &emp->ph_no);                                                             
			    printf("Enter batch::");                                                              
			    scanf("%d", &emp->batch);                                                             
			    printf("Enter mail::");                                                               
			    scanf("%s", emp->mail);
				fseek(fptr, 0, 2);
				fprintf(fptr,"%s\t%d\t%d\t%d\t%s\n", emp->name, emp->emp_id, emp->ph_no, emp->batch, emp->mail);
				break;
			case 2:
				printf("Enter id to retrive the data::");
				scanf("%s", id);
				rewind(fptr);
			/*	while ( (fscanf(fptr,"%s\t%d\t%d\t%d\t%s\n", emp->name, &emp->emp_id, &emp->ph_no, &emp->batch, emp->mail)) != EOF )  {*/
				while ( fgets ( temp , 500 , fptr) != NULL) {
//					printf("%s",temp);	
					emp->name = strcpy(emp->name,strtok(temp, "\t"));
					emp->emp_id = atoi(strtok(NULL, "\t"));
					emp->ph_no = atoi(strtok(NULL, "\t"));
					emp->batch = atoi(strtok(NULL, "\t"));
					emp->mail = strcpy(emp->mail,strtok(NULL, "\n"));
					if ( emp->emp_id == atoi(id)) {
						printf("\n\nThe following are the employee details\n\n");
						printf("Name ::\t%s\n", emp->name);
						printf("Emp ID::\t%d\n", emp->emp_id);
						printf("Phone No::\t%d\n", emp->ph_no);
						printf("Batch No::\t%d\n", emp->batch);
						printf("Mail ::\t%s\n\n\n", emp->mail);
					}
				}
				break;
			case 3:
				printf("Enter id to remove the data::");                                 
                scanf("%s", id);                                 
                rewind(fptr);                                                             
                while ( (fgets (temp,500,fptr) != NULL) )  {
					emp->name = strcpy(emp->name,strtok(temp, "\t"));                     
                    emp->emp_id = atoi(strtok(NULL, "\t"));                               
                    emp->ph_no = atoi(strtok(NULL, "\t"));                                
                    emp->batch = atoi(strtok(NULL, "\t"));                                
                    emp->mail = strcpy(emp->mail,strtok(NULL, "\n"));
                    if ( emp->emp_id == atoi(id)) {
						fseek(fptr, -(sizeof(struct DB)+51), 1);
						fputc(nll, fptr);				
						
					}
				}
				break;
			case 4:
				exit (1);
		}
	}
	return 0;
}


