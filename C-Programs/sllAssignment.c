#include <stdio.h>
#include <stdlib.h>
//Sir's Mail : suman.bhattacharya@aot.edu.in
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

void insert_begin(node **head,int key){
	node *p,*temp;
	p = *head;
	temp = (node*)malloc(sizeof(node));
	if(p == NULL){
		temp->data = key;
		temp->link = NULL;
		*head = temp;
	}
	else{
		temp->data = key;
		temp->link = *head;
		*head = temp;
	}
	printf("%d inserted successfully in the Linked List.\n",key);
}

void insert_Nth_node(node **head,int pos, int val){
	node *p,*temp;
	int len = 1;
	p = *head;
	if((p == NULL)&&(pos != 1)){
		printf("Invalid Position !!! List is Empty now :(\n");
		return;
	}
	else if(pos < 1){
		printf("Invalid Position !!!\n");
		return;
	}
	else if(pos == 1){
		insert_begin(head,val);
		return;
	}
	else{
		while(p->link != NULL){
			len++;
			if(len == pos){
				temp = (node*)malloc(sizeof(node));
				temp->data = val;
				temp->link = p->link;
				p->link = temp;
				printf("%d is inserted successfully at position %d\n",val,pos);
				return;
			}
			p = p->link;
		}
		if(pos == (len+1)){
			temp = (node*)malloc(sizeof(node));
			temp->data = val;
			temp->link = NULL;
			p->link = temp;
			printf("%d is inserted successfully at position %d\n",val,pos);
			return;
		}
	}
	printf("Invalid Position !!! Presently,Your List contains %d nodes\n",len);
	return;
}

void delete_front(node **head){
	node *p = *head;
	if(p == NULL){
		printf("Sorry !!! List is Empty now :(\n");
	}
	else{
		*head = p->link;
		p->link = NULL;
		printf("%d is deleted successfully...\n",p->data);
		free(p);
	}
}

int delete_value(node **head,int key){
	node *p = *head;
	if(p == NULL){
		printf("Sorry !!! List is Empty now :(\n");
		return 0;
	}
//	for deleting the front node
	else if(p->data == key){
		delete_front(head);
		return 1;
	}
	else{
		node *q = NULL;
		while(p->link != NULL){
			q = p;
			p = p->link;
			if(p->data == key){
				q->link = p->link;
				p->link = NULL;
				printf("%d is deleted successfully...\n",key);
				free(p);
				return 1;
			}
		}
	}
	printf("Sorry Unable to delete, %d is not present in the List...\n",key);
	return 0;
}

int length(node **head){
	int len = 0;
	node *p;
	p = *head;
	if(p == NULL){
		return len;
	}
	else{
		while(p != NULL){
			len++;
			p = p->link; 
		}
		return len;
	}
}

int search(node **head,int key){
	int pos = 0;
	node *p = *head;
	if(p == NULL){
		printf("Sorry !!! List is Empty now :(\n");
		return 0;
	}
	else{
		while(p != NULL){
			pos++;
			if(p->data == key){
				printf("%d found at position %d\n",key,pos);
				return pos;
			}
			p = p->link;
		}
	}
	printf("%d is not present in the list...\n",key);
	return -1;
}

int main(){
	int ch,val,pos;
	node *head = NULL;
	printf("----- Single Linked List Operations -----\n\n");
	while(1){
		printf("1.INSERT (At the End)\n2.DISPLAY\n3.INSERT AT BEGINING\n4.INSERT AT ANY POSITION\n5.DELETE A GIVEN VALUE\n6.LENGTH OF LIST\n7.SEARCH AN ELEMENT\n8.DELETE FRONT NODE\n0.EXIT\n");
		printf("  Choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1: insert_last(&head);
				 	break;
				 	
			case 2: display(&head);
				 	break;
				 	
            case 3: printf("Enter the new data : ");
					scanf("%d",&val);
					insert_begin(&head,val);
            	 	break;
			
			case 4: printf("Enter the position where you want to insert : ");
				 	scanf("%d",&pos);
				 	printf("Enter the new data : ");
					scanf("%d",&val);
					insert_Nth_node(&head,pos,val);
            	 	break;
			
			case 5: printf("Enter the value you want to delete : ");
					scanf("%d",&val);
					delete_value(&head,val);
            	 	break;
            	 	
            case 6: printf("The length of the Linked-List is : %d\n",length(&head));
				 	break;
					 	 	
			case 7: printf("Enter the value you want to search : ");
					scanf("%d",&val);
					search(&head,val);
            	 	break;	
            	 	
	  	    case 8: delete_front(&head);
	  	    	 	break;
	  	    	 	
			case 0: exit(0);
   	 	    
   	 	    default: printf("Invalid Input !!!\n");
		}
			printf("--------------------------------------------------\n");
	}
	
	free(head);
	
	return 0;
}


