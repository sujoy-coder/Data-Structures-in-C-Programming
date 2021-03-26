#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;

struct Node{
	 node* prev;
	 node* next;
	 int data;
};

node* head = NULL;

void push(int n){
	node *p = head,*t;
	t = (node*)malloc(sizeof(node));
	t->next = t->prev = NULL;
	t->data = n;
	if(p == NULL){
		head = t;
	}
	else{
		while(p->next != NULL){
			p = p->next;
		}
		p->next = t;
		t->prev = p;
	}
	printf("%d inserted successfully...\n",n);
}

void display_forward(){
	node* p = head;
	if(p==NULL){
		printf("Linked List is Empty now...\n");
	}
	else{
		printf("The List in forward way is :\n");
		while(p != NULL){
			printf("%d\t",p->data);
			p = p->next;
		}
		printf("\n");
	}
}

void display_reverse(){
	node* p = head;
	if(p==NULL){
		printf("Linked List is Empty now...\n");
	}
	else{
		printf("The List in forward way is :\n");
		while(p->next != NULL){
			p = p->next;
		}
		while(p != NULL){
			printf("%d\t",p->data);
			p = p->prev;
		}
		printf("\n");
	}
}

void push_front(int n){
	node *p = head,*t;
	t = (node*)malloc(sizeof(node));
	t->next = t->prev = NULL;
	t->data = n;
	if(p == NULL){
		head = t;
	}
	else{
		t->next = p;
		p->prev = t;
		head = t;
	}
	printf("%d inserted successfully at Front...\n",n);
}

void push_Nth_position(int pos, int val){
	node *p = head,*t;
	int count = 1;
	if((p == NULL)&&(pos != 1)){
		printf("Linked List is Empty now...\n");
		return;
	}
	else if(pos == 1){
		push_front(val);
		return;
	}
	else if(pos<1){
		printf("Sorry, Invalid Position...\n");
		return;
	}
	else{
		while(p->next != NULL){
			count++;
			if(count == pos){
				t = (node*)malloc(sizeof(node));
				t->next = p->next;
				t->prev = p;
				t->data = val;
				p->next->prev = t;
				p->next = t;
				printf("%d inserted successfully at position %d...\n",val,pos);
				return;
			}
			p = p->next;
		}
	}
	printf("Sorry, Invalid Position because List have only %d nodes\n",count);
}

void del_front(){
	node *p = head;
	if(p==NULL){
		printf("Linked List is Empty now...\n");
	}
	else if(p->next == NULL){
		head = NULL;
		printf("%d is deleted from Front Node...\n",p->data);
		free(p);
	}
	else{
		head = p->next;
		head->prev = NULL; //alternative : p->next->prev = NULL;
		p->next = NULL;
		printf("%d is deleted from Front Node...\n",p->data);
		free(p);
	}
}

void del_last(){
	node *p = head;
	if(p==NULL){
		printf("Linked List is Empty now...\n");
	}
	else if(p->next == NULL){
		head = NULL;
		printf("%d is deleted from Last Node...\n",p->data);
		free(p);
	}
	else{
		while(p->next != NULL){
			p = p->next;
		}
		p->prev->next = NULL;
		p->prev = NULL;
		printf("%d is deleted from Last Node...\n",p->data);
		free(p);
	}
}

void del_Nth_node(int pos){
	node *p = head;
	int count = 1;
	if(p == NULL){
		printf("Linked List is Empty now...\n");
		return;
	}
	else if(pos == 1){
		del_front();
		return;
	}
	else if(pos<1){
		printf("Sorry, Invalid Position...\n");
		return;
	}
	else{
		while(p->next != NULL){
			count++;
			p = p->next;
			if(count == pos){
//				case for deleting last node of the list...
				if(p->next == NULL){
					del_last();
					return;
				}
				p->next->prev = p->prev->next;
				p->prev->next = p->next;
				p->next = p->prev = NULL;
				printf("%d deleted successfully from position %d...\n",p->data,pos);
				free(p);
				return;
			}
		}
	}
	printf("Sorry, Invalid Position because List have only %d nodes\n",count);
}

void del_value(int val){
	node *p = head,*q = NULL;
	if(p==NULL){
		printf("Linked List is Empty now...\n");
		return;
	}
	else if(p->data == val){
		del_front();
		return;
	}
	else{
		while(p->next != NULL){
			q = p;
			p = p->next;
			if(p->data == val){
//				case for deleting last node of the list...
				if(p->next == NULL){
					del_last();
					return;
				}
				p->next->prev = q;
				q->next = p->next;
				p->prev = p->next = NULL;
				printf("%d is deleted successfully from the list...\n",val);
				free(p);
				return;
			}
		}
		printf("Sorry, %d is not present in the List...\n",val);
		return;
	}
}

void selection_sort(){
	node *p,*q;
	int temp;
	for(p = head;p->next != NULL;p = p->next){
		for(q = p->next;q != NULL;q = q->next){
			if(p->data>q->data){
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
		}	
	}
	display_forward();
}

void reverse(){
//	write logic for reversing the list here...
}

int main(){
	int ch,n,pos;
	printf("----- Double Linked List Operations -----\n\n");
	while(1){
		printf("1.PUSH (At end of List)\n2.DISPLAY FORWARD\n3.DISPLAY REVERSE\n4.PUSH AT FRONT\n5.PUSH AT SPECIFIED POSITION\n");
		printf("6.DELETE FRONT NODE\n7.DELETE LAST NODE\n8.DELETE A SPECIFIED NODE\n9.DELETE A VALUE\n10.SORT THE LIST (Selection Sort)\n0.EXIT\n");
		printf("  Choise : ");
		scanf("%d",&ch);
		switch(ch){
			case 0: exit(0);
			case 1: printf("Enter the data you want to insert : ");
				 	scanf("%d",&n);
				 	push(n);
				 	break;
			case 2: display_forward();
				 	break;
			case 3: display_reverse();
				 	break;
			case 4: printf("Enter the data you want to insert : ");
				 	scanf("%d",&n);
				 	push_front(n);
				 	break;
			case 5: printf("Enter the position where you want to insert : ");
				 	scanf("%d",&pos);
				 	printf("Enter the data you want to insert : ");
				 	scanf("%d",&n);
				 	push_Nth_position(pos,n);
				 	break;
			case 6: del_front();
				 	break;
			case 7: del_last();
				 	break;
			case 8: printf("Enter the position of node what you want to delete : ");
				 	scanf("%d",&pos);
				 	del_Nth_node(pos);
				 	break;
			case 9: printf("Enter the data you want to delete : ");
				 	scanf("%d",&n);
				 	del_value(n);
				 	break;
			case 10: selection_sort();
				 	 break;
			default: printf("Sorry, Invalid Choise :(\n");
		}
		printf("------------------------------------------------------------\n");
	}
	
	free(head);
	
	return 0;
}


