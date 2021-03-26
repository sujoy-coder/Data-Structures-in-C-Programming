/*
QUESTION :::
Stack Implimentation using Static Array,
Operations: 1. Insert 2. Delete(pop) 3. Traverse(display) 4. Peak(top_element) 5. Length ...
*/
#include <stdio.h>
#define SIZE 5

// function decleration ...
void insert(int);
int pop(void);
void display(void);
void peek(void);
int length(void);
int isFull(void);
int isEmpty(void);

// Global variables
int stack[SIZE];
int top = -1;

int main(){
	int choice,ele,flag = 1;
	
	printf("--- Stack Implimentation using Static Array ---\n");
	while(flag){
		printf("\n");
		printf("1. Insert\n");
		printf("2. Delete(pop)\n");
		printf("3. Traverse(display)\n");
		printf("4. Peak(top_element)\n");
		printf("5. Length\n");
		printf("6. Exit\n");
		printf("\nChoice : ");
		scanf("%d",&choice);
		
		switch(choice) {
			case 1:	printf("Enter the Element in stack :\n");
				 	scanf("%d",&ele);
				 	insert(ele);
				 	break;
			case 2:	if(isEmpty()){
	                    printf("The stack is Empty/underflow ...\n");
			        }
			        else{
			        	pop();
					}
				 	break;
			case 3:	display();
				 	break;
			case 4:	peek();
				 	break;
			case 5:	printf("The length of the Stack is : %d\n",length());
				 	break;
			case 6:	flag = 0;
				 	break;
			
			default:printf("Invalid input !!!\n");
		}
	}

	return 0;
}


void insert(int ele){
	if(isFull()){
		printf("The stack is overflow/filled ...\n");
	}
	else{
		top++;
		stack[top] = ele;
		printf("%d inserted successfully ...\n",ele);
	}
}


int pop(){
	printf("%d deleted successfully ...\n",stack[top]);
	return stack[top--];
}


void display(){
	if(isEmpty()){
		printf("The stack is Empty/underflow ...\n");
	}
	else{
		printf("The stack\'s elements are ...\n");
		int i;
		for(i=0;i<=top;i++){
			printf("%d \n",stack[i]);
		}
	}
}


void peek(){
	if(isEmpty()){
		printf("The stack is Empty/underflow ...\n");
	}
	else{
		printf("The top most element of stack is : %d ...\n",stack[top]);
	}
	
}


int length(){
	return (top+1);
}


int isFull(){
	if(top == (SIZE-1)){
		return 1;
	}
	
	return 0;
}


int isEmpty(){
	if(top == -1){
		return 1;
	}
	
	return 0;
}


