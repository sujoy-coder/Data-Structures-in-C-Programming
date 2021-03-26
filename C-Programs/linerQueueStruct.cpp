#include <stdio.h>
#define SIZE 5

typedef struct queue{
	int front;
	int rear;
	int arr[SIZE];
}queue;


int isFull(queue*);
int isEmpty(queue*);
void insert(queue*,int);
int del(queue*);
void display(queue*);

int main(){
	int choice,ele,flag = 1;
	queue Q;
	Q.front = Q.rear = -1;
	
	printf("--- Linear Queue Implimentation ---\n");
	while(flag){
		printf("\n");
		printf("1. INSERT\n");
		printf("2. DELETE\n");
		printf("3. IS_FULL\n");
		printf("4. IS_EMPTY\n");
		printf("5. DISPLAY\n");
		printf("6. Exit\n");
		printf("\n Choice : ");
		scanf("%d",&choice);
		
		switch(choice) {
			case 1:	printf("Enter the new Element in queue :\n");
				 	scanf("%d",&ele);
				 	insert(&Q,ele);
				 	break;
				 	
			case 2:	if(isEmpty(&Q)){
	                    printf("The queue is Empty/underflow ...\n");
			        }
			        else{
			        	del(&Q);
					}
				 	break;
				 	
			case 3:	if(isFull(&Q)){
		     	 	    printf("YES, The queue is overflow/filled ...\n");
				 	}
				 	else{
				 		printf("The queue is not overflow/filled ...\n");
					 }
				 	break;
				 	
			case 4:	if(isEmpty(&Q)){
		     	 	    printf("YES, The queue is Empty/underflow ...\n");
				 	}
				 	else{
				 		printf("The queue is not Empty/underflow ...\n");
					 }
				 	break;
				 	
			case 5:	display(&Q);
				 	break;
			
			case 6:	flag = 0;
				 	break;
			
			default:printf("Invalid input !!!\n");
		}
	}

	return 0;
}


int isFull(queue* Q){
	if(Q->rear == (SIZE-1)){
		return 1;
	}
	
	return 0;
}


int isEmpty(queue* Q){
	if((Q->front == -1)||(Q->front == Q->rear + 1)){
		return 1;
	}
	
	return 0;
}


void insert(queue* Q,int ele){
	if(Q->rear == (SIZE-1)){
		printf("The queue is overflow/filled ...\n");
	}
	else{
	    if(Q->front == -1){
	    	Q->front++;
		}
		Q->rear++;
		Q->arr[Q->rear] = ele;
		printf("%d inserted successfully ...\n",ele);
	}
}


int del(queue* Q){
	printf("%d deleted successfully ...\n",Q->arr[Q->front]);
	return Q->arr[Q->front++];
}


void display(queue* Q){
	if((Q->front == -1)||(Q->front == Q->rear + 1)){
        printf("The queue is Empty/underflow ...\n");
    }
    else{
    	int i;
		printf("The elements of Queue's are :\n");
		for(i = Q->front; i <= Q->rear; i++){
			printf("%d   ",Q->arr[i]);
		}
	}
}

