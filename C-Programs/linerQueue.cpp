#include <stdio.h>
#define SIZE 5

int isFull(void);
int isEmpty(void);
void insert(int);
int del(void);
void display(void);

int queue[SIZE];
int rear = -1, front = -1;

int main(){
	int choice,ele,flag = 1;
	
	printf("--- Linear Queue Implimentation ---\n");
	while(flag){
		printf("\n");
		printf("1. INSERT\n");
		printf("2. DELETE\n");
		printf("3. IS_FULL\n");
		printf("4. IS_EMPTY\n");
		printf("5. DISPLAY\n");
		printf("6. Exit\n");
		printf("\nChoice : ");
		scanf("%d",&choice);
		
		switch(choice) {
			case 1:	printf("Enter the new Element in queue :\n");
				 	scanf("%d",&ele);
				 	insert(ele);
				 	break;
				 	
			case 2:	if(isEmpty()){
	                    printf("The queue is Empty/underflow ...\n");
			        }
			        else{
			        	del();
					}
				 	break;
				 	
			case 3:	if(isFull()){
		     	 	    printf("YES, The queue is overflow/filled ...\n");
				 	}
				 	else{
				 		printf("The queue is not overflow/filled ...\n");
					 }
				 	break;
				 	
			case 4:	if(isEmpty()){
		     	 	    printf("YES, The queue is Empty/underflow ...\n");
				 	}
				 	else{
				 		printf("The queue is not Empty/underflow ...\n");
					 }
				 	break;
				 	
			case 5:	display();
				 	break;
			
			case 6:	flag = 0;
				 	break;
			
			default:printf("Invalid input !!!\n");
		}
	}

	return 0;
}


int isFull(){
	if(rear == (SIZE-1)){
		return 1;
	}
	
	return 0;
}


int isEmpty(){
	if((front == -1)||(front == rear+1)){
		return 1;
	}
	
	return 0;
}


void insert(int ele){
	if(isFull()){
		printf("The queue is overflow/filled ...\n");
	}
	else{
	    if(front == -1){
	    	front++;
		}
		rear++;
		queue[rear] = ele;
		printf("%d inserted successfully ...\n",ele);
	}
}


int del(){
	printf("%d deleted successfully ...\n",queue[front]);
	return queue[front++];
}


void display(){
	if(isEmpty()){
        printf("The queue is Empty/underflow ...\n");
    }
    else{
    	int i;
		printf("The elements of Queue's are :\n");
		for(i = front; i <= rear; i++){
			printf("%d   ",queue[i]);
		}
	}
}

