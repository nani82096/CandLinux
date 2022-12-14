#include    "header.h"                                                                    
                                                                                          
int main(void)                                                                            
{                                                                                         
    node *new = NULL;                                                                    
    node *head = NULL;                                                                       
	node *temp1;
	node *temp;
	node *temp2;
    int data;                                                                             
    int choice;                                                                           
    while (1) {                                                                           
    printf("\n----------MENU---------\n"                                                    
            "1. Enter the data to the list\n"                                               
            "2. Display\n"                                             
            "3. To exit from the menu\n");                                                
    choice = integervalidation();                                                         
        switch(choice) {                                                                  
                                                                                          
            case 1:                                                                       
                printf("Enter the data to insert::");                                     
                data = integervalidation();                                               
				new = (node*)malloc(sizeof(node));
				head = (node*)malloc(sizeof(node));
                new->data = data;                                                         
                new->next = NULL;                                                         
				head = insert(head , new);
                break;                                                                    
            case 2:                                                                       
                displayld(head);                                                            
                break;                                                                  
            default:                                                                      
                printf("please enter valid options\n");                                   
        }                                                                                 
    }                                                                                     
    return 0;                                                                             
}
node * insert(node *start, node* new)
{                                                                                        
    if ( start == NULL)                                                                   
        start = new;                                                                      
    else{                                                                                 
        new->next = start;                                                                
        start = new;                                                                      
    }                                                                                     
    return start;                                                                         
}

void displayld( node *top)                                                                  
{                                                                                         
    node *temp = top;                                                                     
    if (top == NULL) {                                                                    
        printf("List is empty \n");                                                       
        return ;                                                                          
    }                                                                                     
    while ( temp) {                                                                       
        printf("%d\t", temp->data);                                                       
        temp = temp->next;                                                                
    }                                                                                     
}
