#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;

struct Node{
	int data;
	node *next;
};

node *tail = NULL;

// Complexcity : O(1)
void append_first(int data){
	node *temp = tail,*new_node;
//	inserting first node of the linked list...
	if(temp == NULL){
		new_node = (node*)malloc(sizeof(node));
		new_node->data = data;
		new_node->next = new_node;
		tail = new_node;
	}
//	for inserting of a front node of a exsisting list...
	else{
		new_node = (node*)malloc(sizeof(node));
		new_node->data = data;
		new_node->next = temp->next;
		temp->next = new_node;
	}
	printf("%d is inserted at the list...\n",data);
}

// Complexcity : O(1)
void append_last(int data){
	node *temp = tail,*new_node;
	if(temp == NULL){
		append_first(data);
	}
	else{
		new_node = (node*)malloc(sizeof(node));
		new_node->data = data;
		new_node->next = temp->next;
		temp->next = new_node;
		tail = new_node;
		printf("%d is inserted at the list...\n",data);
	}
}

// Complexcity : O(n)
void append_given_position(int data, int pos){
	node *temp = tail,*new_node;
	int count = 2;
	if(pos<1){
		printf("Invalid Position...\n");
	}
	else if(pos == 1){
		append_first(data);
	}
	else if(temp == NULL){
		printf("Invalid Position, The List is Empty...\n");
	}
	else{
		temp = temp->next;
		do{
			if(pos == count){
				new_node = (node*)malloc(sizeof(node));
				new_node->data = data;
				new_node->next = temp->next;
				temp->next = new_node;
//				for inserting in last position of the list...
				if(temp == tail){
					tail = new_node;
				}
				printf("%d is inserted at the list...\n",data);
				return;
			}
			else{
				count = count + 1;
			}
			temp = temp->next;
		}while(temp != tail->next);
		printf("Invalid Position, The List is having %d Nodes now...\n",(count-2));
	}
}

// Complexcity : O(n)
void display(){
	node *temp = tail;
	if(temp == NULL){
		printf("The List is Empty...\n");
	}
	else{
		printf("The List is :\n");
		temp = temp->next;
		do{
			printf("%d\t",temp->data);
			temp = temp->next;
		}while(temp != tail->next);
		printf("\n");
	}
}

int main(){
	int ch,val,pos;
	printf("----- Circular Linked List Operations -----\n\n");
	while(1){
		printf("1.APPEND AT END\n2.DISPLAY\n3.APPEND AT BEGINING\n4.APPEND AT SPECIFIED POSITION\n0.EXIT\n");
		printf("  Choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter the new data : ");
					scanf("%d",&val);
				 	append_last(val);
				 	break;
				 	
			case 2: display();
				 	break;
				 	
            case 3: printf("Enter the new data : ");
					scanf("%d",&val);
					append_first(val);
            	 	break;
            	 	
			case 4: printf("Enter the new data : ");
					scanf("%d",&val);
					printf("Enter the position where you want to insert : ");
					scanf("%d",&pos);
					append_given_position(val,pos);
            	 	break;
				  	    	 	
			case 0: exit(0);
   	 	    
   	 	    default: printf("Invalid Input !!!\n");
		}
			printf("--------------------------------------------------\n");
	}
	
	free(tail);
	
	return 0;
}


