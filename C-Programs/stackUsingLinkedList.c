#include <stdio.h>
#include <stdlib.h>
typedef struct Stack
{
    int data;
    struct Stack *next;
}Stack;

void push(Stack **head, int data){
    Stack *new_node;
    new_node = (Stack*)malloc(sizeof(Stack));
    new_node->data = data;
    new_node->next = NULL;
    new_node->next = *head;
    *head = new_node;
    printf("%d is Inserted In the Stack\n",data);
}

int pop(Stack **head){
	int del_data;
    Stack *temp = *head;
    *head = temp->next;
    temp->next = NULL;
    del_data = temp->data;
    free(temp);
    return del_data;
}

void display(Stack **head){
    Stack *temp = *head;
    if(temp == NULL){
		printf("Stack is Empty now...\n");
	}
	else{
		printf("The Stack is : \n");
		while(temp != NULL){
			printf("%d\t",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main(){
    int ch,data;
	Stack *head = NULL;
	printf("----- Stack Using Single Linked List -----\n\n");
	while(1){
		printf("1.PUSH\n2.DISPLAY\n3.POP\n0.EXIT\n");
		printf("  Choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter the new data in Stack : ");
					scanf("%d",&data);
                    push(&head,data);
				 	break;
				 	
			case 2: display(&head);
				 	break;
				 	
            case 3: if(head == NULL){
                        printf("Stack is Empty now...\n");  
                    }
                    else{
                        data = pop(&head);
                        printf("%d is Deleted from Stack\n",data);
                    }
                    break;                  
				  	    	 	
			case 0: exit(0);
   	 	    
   	 	    default: printf("Invalid Input !!!\n");
		}
			printf("--------------------------------------------------\n");
	}
	free(head);
	return 0;
}
