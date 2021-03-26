#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;

struct Node{
	int data;
	node *link;
};

node *head = NULL;

void insert_last(){
	node *p,*cur;
	p = (node*)malloc(sizeof(node));
	printf("Enter the Node Data : ");
	scanf("%d",&p->data);
	printf("%d inserted successfully in the Linked List.\n",p->data);
	p->link = NULL;
	cur = head;
	if(cur == NULL){
		head = p;
	}
	else{
		while(cur->link != NULL){
			cur = cur->link;
		}
		cur->link = p;
	}
}

void display(){
	node *p;
	p = head;
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

void find_second_max_min(){
	int max,min,max_pre,min_pre;
	node* t = head;
	if(t == NULL){
		printf("List is Empty Now !\n");
	}
	else if(t->link == NULL){
		printf("Second Max : %d\nSecond Min : %d\n",t->data,t->data);
	}
	else{
		if(t->data < t->link->data){
			min_pre = max = t->link->data;
			max_pre = min = t->data;
		}
		else{
			min_pre = max = t->data;
			max_pre = min = t->link->data;
		}
		t = t->link->link;
		while(t != NULL){
//			for getting 2nd maximum
			if((max>t->data)&&(t->data>max_pre)){
				max_pre = t->data;
			}
			else if((t->data>max)&&(t->data>max_pre)){
				max_pre = max;
				max = t->data;
			}
//			for getting 2nd minimum
			if((t->data>min)&&(t->data<min_pre)){
				min_pre = t->data;
			}
			else if((t->data<min)&&(t->data<min_pre)){
				min_pre = min;
				min = t->data;
			}
			
			t = t->link;						
		}
		printf("Second Max : %d\nSecond Min : %d\n",max_pre,min_pre);
	}
}

int main(){
	int ch;
	while(1){
		printf("1. Insert Data\n2. Display\n3. Find Second Max & Second Min\n0. Exit\n  Choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1: insert_last();
				 	break;
			case 2: printf("\n");
				 	display();
				 	break;
			case 3: find_second_max_min();
				 	break;
			case 0: exit(0);
			default: printf("Invalid Input !!!");
		}
		printf("----------------------------------------\n");
	}

	return 0;
}


