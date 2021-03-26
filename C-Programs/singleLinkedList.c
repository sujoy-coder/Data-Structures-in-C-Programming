#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *link;
}node;

node *head = NULL;

void insert(){
	node *p,*cur;
	p = (node*)malloc(sizeof(node));
	if(p != NULL){
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
	else{
		printf("Not possible to Enter New Node into this Linked List !!!\n");
	}
	printf("--------------------------------------------------\n");
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
	printf("--------------------------------------------------\n");
}

void insert_begin(int key){
	node *p,*temp;
	p = head;
	temp = (node*)malloc(sizeof(node));
	if(p == NULL){
		temp->data = key;
		temp->link = NULL;
		head = temp;
	}
	else{
		temp->data = key;
		temp->link = head;
		head = temp;
	}
	printf("%d inserted successfully in the Linked List.\n",key);
	printf("--------------------------------------------------\n");
}

void insert_Nth_node(int pos, int key){
	node *p,*temp;
	int len = 0;
	p = head;
	if(p == NULL){
		printf("Invalid Position !!! List is Empty now :(\n");
		printf("--------------------------------------------------\n");
		return;
	}
	else if(pos < 1){
		printf("Invalid Position !!!\n");
		printf("--------------------------------------------------\n");
		return;
	}
	else if(pos == 1){
		insert_begin(key);
		return;
	}
	else{
		while(p != NULL){
			len++;
			if((len+1) == pos){
				temp = (node*)malloc(sizeof(node));
				temp->data = key;
				temp->link = p->link;
				p->link = temp;
				printf("%d is inserted successfully at position %d\n",key,pos);
				printf("--------------------------------------------------\n");
				return;
			}
			p = p->link;
		}
	}
	printf("Invalid Position !!! Presently,Your List contains %d nodes\n",len);
	printf("--------------------------------------------------\n");
	return;
}

void insert_before_value(int pos_val, int new_val){
	node *p,*temp;
	p = head;
	if(p == NULL){
		printf("Invalid input !!! List is Empty now :(\n");
		printf("--------------------------------------------------\n");
		return;
	}
	else if(p->data == pos_val){
		insert_begin(new_val);
		return;
	}
	else{
		while(p->link != NULL){
			if(p->link->data == pos_val){
				temp = (node*)malloc(sizeof(node));
				temp->data = new_val;
				temp->link = p->link;
				p->link = temp;
				printf("%d is inserted successfully before %d\n",new_val,pos_val);
				printf("--------------------------------------------------\n");
				return;
			}
			p = p->link;
		}
	}
	printf("Invalid input !!! %d is not prersent in the List\n",pos_val);
	printf("--------------------------------------------------\n");
	return;
}

void delete_front(){
	node *p = head;
	if(p == NULL){
		printf("Sorry !!! List is Empty now :(\n");
		printf("--------------------------------------------------\n");
	}
	else{
		head = p->link;
		p->link = NULL;
		printf("%d is deleted successfully...\n",p->data);
		printf("--------------------------------------------------\n");
		free(p);
	}
}

void delete_last(){
	node *p = head;
	if(p == NULL){
		printf("Sorry !!! List is Empty now :(\n");
		printf("--------------------------------------------------\n");
	}
//	case, if list contains single node...
	else if(p->link == NULL){
		delete_front();
	}
	else{
		node *q = NULL;
		while(p->link != NULL){
			q = p;
			p = p->link;
		}
		q->link = NULL;
		printf("%d is deleted successfully...\n",p->data);
		printf("--------------------------------------------------\n");
		free(p);
	}
}

// alternative logic can be used like insert_Nth_node() function...
void delete_Nth_node(int pos){
	node *p = head;
	int len, i = 1;
	if(p == NULL){
		printf("Sorry !!! List is Empty now :(\n");
		printf("--------------------------------------------------\n");
	}
	else if(pos == 1){
		delete_front();
	}
	else if((pos > (len = length())) || (pos < 1)){
		printf("Invalid position !!! List contains %d nodes...\n",len);
		printf("--------------------------------------------------\n");
	}
	else{
		node *q = NULL;
		while(i<pos){
			q = p;
			p = p->link;
			i++;
		}
		q->link = p->link;
		p->link = NULL;
		printf("%d is deleted successfully...\n",p->data);
		printf("--------------------------------------------------\n");
		free(p);
	}
}

int delete_value(int key){
	node *p = head;
	if(p == NULL){
		printf("Sorry !!! List is Empty now :(\n");
		printf("--------------------------------------------------\n");
		return 0;
	}
	else if(p->data == key){
		delete_front();
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
				printf("--------------------------------------------------\n");
				free(p);
				return 1;
			}
		}
	}
	printf("Sorry Unable to delete, %d is not present in the List...\n",key);
	printf("--------------------------------------------------\n");
	return 0;
}

int length(){
	int len = 0;
	node *p;
	p = head;
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

void display_reverse_list(node *p){
	 if(p == NULL){
	 	return;
	 }
	 else{
	 	display_reverse_list(p->link);
	 	printf("%d\t",p->data);
	 }
}

void reverse(){
	node *p = head,*next = NULL,*previous = NULL;
	while(p != NULL){
		next = p->link;
		p->link = previous;
		previous = p;
		p = next;
	}
	head = previous;
//	calling display() to show the reverse list...
	display();
}

// By shifting the data of each node...but this is selection sort acutally 
void selection_sort(){
	node *p,*q;
	int temp;
	for(p = head;p->link != NULL;p = p->link){
		for(q = p->link;q != NULL;q = q->link){
			if(p->data>q->data){
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
		}	
	}
	display();
}

int main(){
	int ch,new_val,pos,key;
	printf("----- Single Linked List Operations -----\n\n");
	while(1){
		printf("1.INSERT (At the End)\n2.DISPLAY\n3.INSERT AT BEGINING\n4.INSERT AT SPECIFIED POSITION\n5.INSERT BEFORE A GIVEN VALUE\n");
		printf("6.DELETE FRONT NODE\n7.DELETE LAST NODE\n8.DELETE SPECIFIED NODE\n9.DELETE A NODE WITH GIVEN VALUE\n10.LENGTH OF LIST\n");
		printf("11.DISPLAY THE LIST IN REVERSE WAY\n12.REVERSE THE LINKS OF LIST (Permanently)\n13.SORT THE LIST (Bubble Sort)\n0.EXIT\n");
		printf("  Choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1: insert();
				 	break;
				 	
			case 2: display();
				 	break;
				 	
            case 3: printf("Enter the new data : ");
					scanf("%d",&new_val);
					insert_begin(new_val);
            	 	break;
            	 	
			case 4: printf("Enter Position where you want to Insert : ");
					scanf("%d",&pos);
					printf("Enter the new data : ");
					scanf("%d",&new_val);
					insert_Nth_node(pos,new_val);
            	 	break;
            	 	
			case 5: printf("Enter the value before which you want to insert : ");
					scanf("%d",&pos);
					printf("Enter the new data : ");
					scanf("%d",&new_val);
					insert_before_value(pos,new_val);
            	 	break;
            	 	
			case 6: delete_front();
				 	break;
            
			case 7: delete_last();
				 	break;
				 	
			case 8: printf("Which node you want to delete : ");
				 	scanf("%d",&pos);
				 	delete_Nth_node(pos);
				 	break;
			
			case 9: printf("Enter the value, you want to delete from List : ");
				 	scanf("%d",&key);
					delete_value(key);
					break;
					
			case 10: printf("The length of the Linked-List is : %d\n",length());
				 	 printf("--------------------------------------------------\n");
				 	 break;
				 	 
			case 11: printf("The List in REVERSE way is :\n");
				 	 display_reverse_list(head);
				 	 printf("\n--------------------------------------------------\n");
				 	 break;
			
			case 12: reverse();
				 	 break;
				 	 
		    case 13: selection_sort();
		    	 	 break;
					  	 	 
   	 	    case 0: exit(0);
   	 	    
   	 	    default: printf("Invalid Input !!!\n");
		}
	}
	
	free(head);
	
	return 0;
}


