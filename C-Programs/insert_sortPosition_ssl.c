#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;

struct Node{
	int data;
	node *link;
};

void insert_last(node **head){
	node *p,*cur;
	p = (node*)malloc(sizeof(node));
	printf("Enter the Node Data : ");
	scanf("%d",&p->data);
	printf("%d inserted successfully in the Linked List.\n",p->data);
	p->link = NULL;
	cur = *head;
	if(cur == NULL){
		*head = p;
	}
	else{
		while(cur->link != NULL){
			cur = cur->link;
		}
		cur->link = p;
	}
}

void display(node **head){
	node *p;
	p = *head;
	if(p == NULL){
		printf("Linked List is Empty now...\n");
	}
	else{
		printf("The Linked List is : \n");
		while(p != NULL){
			printf("%d\t",p->data);
			p = p->link;
		}
		printf("\n");
	}
}

void insert_at_SortedPosition(node **head, int val){
	node *p,*temp,*q;
	p = *head;
	temp = (node*)malloc(sizeof(node));
	if(p == NULL){
		temp->data = val;
		temp->link = NULL;
		*head = temp;
	}
	else if(p->data > val){
//		insert at front
		temp->data = val;
		temp->link = *head;
		*head = temp;
	}
	else{
		while(p != NULL){
			if(p->data > val){
				break;
			}
			q = p;
			p = p->link;
		}
//		q holds the previous node address where new node has to be inserted
		temp->data = val;
		temp->link = q->link;
		q->link = temp;
	}
	printf("%d inserted at sorted position of the Linked List...\n",val);
}

void reverse(node **head){
	node *p = *head,*next = NULL,*previous = NULL;
	if(p != NULL){
			while(p != NULL){
			next = p->link;
			p->link = previous;
			previous = p;
			p = next;
		}
		*head = previous;
		printf("The Linked List is reversed now...\n");
	}
	else{
		printf("The List is Empty now :(\n");
	}
}

int main(){
	int ch,val;
	node *head = NULL;
	printf("----- Single Linked List Operations -----\n\n");
	while(1){
		printf("1.INSERT (At the End)\n2.DISPLAY\n3.INSERT AT SORTED POSITION\n4.REVERSE LIST\n0.EXIT\n");
		printf("  Choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1: insert_last(&head);
				 	break;
				 	
			case 2: display(&head);
				 	break;
				 	
            case 3: printf("Enter the new data : ");
					scanf("%d",&val);
					insert_at_SortedPosition(&head,val);
            	 	break;
            	 	
			case 4: reverse(&head);
				 	break;
				  	    	 	
			case 0: exit(0);
   	 	    
   	 	    default: printf("Invalid Input !!!\n");
		}
			printf("--------------------------------------------------\n");
	}
	
	free(head);
	
	return 0;
}
