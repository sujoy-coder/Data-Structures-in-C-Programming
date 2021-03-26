#include <stdio.h>
#define SIZE 5

int isFull(void);
int isEmpty(void);
void push(int);
int pop(void);

int stack[SIZE];
int top = -1;

int main(){
	int choice,ele,flag = 1;
	
	printf("--- Stack Implimentation using Static Array ---\n");
	while(flag){
		printf("\n");
		printf("1. PUSH\n");
		printf("2. POP\n");
		printf("3. IS_FULL\n");
		printf("4. IS_EMPTY\n");
		printf("5. Exit\n");
		printf("\nChoice : ");
		scanf("%d",&choice);
		
		switch(choice) {
			case 1:	printf("Enter the Element in stack :\n");
				 	scanf("%d",&ele);
				 	push(ele);
				 	break;
			case 2:	if(isEmpty()){
	                    printf("The stack is Empty/underflow ...\n");
			        }
			        else{
			        	pop();
					}
				 	break;
			case 3:	if(isFull()){
		     	 	    printf("YES, The stack is overflow/filled ...\n");
				 	}
				 	else{
				 		printf("The stack is not overflow/filled ...\n");
					 }
				 	break;
			case 4:	if(isEmpty()){
		     	 	    printf("YES, The stack is Empty/underflow ...\n");
				 	}
				 	else{
				 		printf("The stack is not Empty/underflow ...\n");
					 }
				 	break;
			case 5:	flag = 0;
				 	break;
			
			default:printf("Invalid input !!!\n");
		}
	}

	return 0;
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


void push(int ele){
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

