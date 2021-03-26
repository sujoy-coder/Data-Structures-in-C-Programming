#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
struct Node{
	Node *right;
	Node *left;
	int data;
};

Node *root = NULL;

void insert(int data){
	Node *temp = root, *new_node;
	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	if(temp == NULL){
		root = new_node;
		printf("%d inserted ...\n",data);
	}
	else{
		Node *cur = root;
		while(cur != NULL){
//			temp is perent node
			temp = cur;
			if(cur->data < data){
//				for inserting right side
				cur = cur->right;
			}
			else{
//				for inserting left side
				cur = cur->left;
			}
		}
		if(temp->data < data){
			temp->right = new_node;
		}
		else{
			temp->left = new_node;
		}
		printf("%d inserted ...\n",data);
	}
}

void preorder_display(Node *temp){
	if(temp == NULL){
		return;
	}
	else{
		printf("%d  ",temp->data);
		preorder_display(temp->left);
		preorder_display(temp->right);
	}
}

void inorder_display(Node *temp){
	if(temp == NULL){
		return;
	}
	else{
		inorder_display(temp->left);
		printf("%d  ",temp->data);
		inorder_display(temp->right);
	}
}

void postorder_display(Node *temp){
	if(temp == NULL){
		return;
	}
	else{
		postorder_display(temp->left);
		postorder_display(temp->right);
		printf("%d  ",temp->data);
		
	}
}

int main(){
	int ch,val;
	while(1){
		printf("1. Insert\n2. PreOrder Traversal\n3. InOrder Traversal\n4. PostOrder Traversal\n0. Exit\n");
		printf("Choise : ");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter New Data : ");
				 	scanf("%d",&val);
				 	insert(val);
				 	break;
				 	
			case 2: printf("Elements are in PreOrder form\n");
				 	preorder_display(root);
				 	printf("\n");
				 	break;
				 	
			case 3: printf("Elements are in InOrder form\n");
				 	inorder_display(root);
				 	printf("\n");
				 	break;
				 	
			case 4: printf("Elements are in PostOrder form\n");
				 	postorder_display(root);
				 	printf("\n");
				 	break;
				 	
			case 0: exit(0);
			
			default: printf("Invalid Choise !!!\n");	 	
		}
		printf("------------------------------------------------\n");
	}
	
	free(root);
	return 0;
}


