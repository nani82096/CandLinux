#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>

struct DB{                                                                                
    char name[50];                                                                        
    int emp_id;                                                                           
    int ph_no;                                                                            
    int batch;                                                                            
    char mail[20];
}data;

int search ( FILE *fptr, int id)
{
	/*searching the id by reading block by block into structure*/
	unsigned flag = 0;
	rewind(fptr);
	while ( fread(&data, sizeof(data), 1 , fptr) == 1) {
		if ( id ==  data.emp_id ) {
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		printf("Record not found\n\n");
	return flag;
}

int main(void)

{
/*	data.name = (char *)malloc(sizeof(char)*50);
	data.mail = (char *)malloc(sizeof(char)*50);*/
	int choice;
	struct DB *emp;
	int id;					/*id as a primary key*/
	emp = &data;
	char name[50];
	FILE *fptr;
	FILE *fptmp;/*temp file pointer*/
	if ((fptr = fopen ("GESL","rb+")) == NULL){	
		if ((fptr = fopen("GESL", "wb+")) == NULL) {
			puts("Error in opening the file");
			exit(1);
		
		}
	}
	while (1){
		printf("\n\n**********Welcome To GESL**********\n"
				"Enter 1. Update the Database\n"
				"Enter 2. Show the Database\n"
				"Enter 3. Modify the Database\n"
				"Enter 4. To remove Entry from database\n"
				"Enter 5. To Exit from the Database\n");
		scanf("%d", &choice);
		getchar();
		switch( choice ){

			case 1:
				fseek(fptr, 0, 2);
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
				getchar();                                                             
			    printf("Enter mail::");                                                               
			    fgets(name, 50, stdin);
				name[strlen(name)-1] = '\0';
				strcpy(emp->mail,name);
				/*writing into file*/
				
				fwrite(&data ,sizeof(data), 1, fptr);
				break;
			case 2:
				printf("Enter id to retrive the data::");
				scanf("%d", &id);
				/*scanning for a particular record*/
				if ( search (fptr, id) == 1) {
						printf("\n\nThe following are the employee details\n\n");         
                        printf("Name ::\t\t%s\n", emp->name);                               
                        printf("Emp ID::\t%d\n", emp->emp_id);                            
                        printf("Phone No::\t%d\n", emp->ph_no);                           
                        printf("Batch No::\t%d\n", emp->batch);                           
                        printf("Mail ::\t\t%s\n\n\n", emp->mail);
				}
				
				break;
			case 3:
				printf("Enter id to modify the data::");                                 
                scanf("%d", &id);                                                         
				getchar();
				/*searching for a record matches then updating*/
                if ( search (fptr, id) == 1) {                                            
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
					getchar();
                	printf("Enter mail::");                                                  
					fgets(name, 50, stdin);                                                   
	                name[strlen(name)-1] = '\0';                                             
                	strcpy(emp->mail,name);  
					fseek(fptr,-(sizeof(data)), 1);
					fwrite(&data, sizeof(data), 1, fptr);
					printf("\n\nrecord Enter successfully\n\n");
                }          
				break;
			case 4:
				printf("Enter id to delete the record::");               	
				scanf("%d", &id);
				getchar();
				rewind (fptr);
				fptmp = fopen("tempfile","wb+");
				fseek(fptmp, 0, 2);
				while ( fread(&data, sizeof(data) , 1, fptr) == 1 ) {
					if ( id != emp->emp_id){
						/*searching a record if not matches then writing it to temperary file*/						
						
						fwrite(&data, sizeof(data), 1, fptmp);
					}
				}
				fclose (fptr);
				fclose (fptmp);
				/*removing the old file*/
				remove("GESL");
				/*renaming the temp file as GESL*/
				rename("tempfile", "GESL");
				printf("Record deleted successfully\n\n");
				/*again opening the file for further actions*/
				fptr = fopen("GESL", "rb+");
				break;
			case 5:
				exit (1);
		}
	}
	return 0;
}

