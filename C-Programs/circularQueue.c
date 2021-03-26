#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5

int queue[MAXSIZE];
int front = -1;
int rear = -1;

void insert(int p){
	if((front==0 && rear==MAXSIZE-1)||(front==rear+1)){
	    printf("Queue is overflow\n");
	}
	else{
		if(front==-1)
		{
		    front++;
		}
		rear=(rear+1)%MAXSIZE;
		queue[rear]=p;
		printf("%d is inserted successfully in the Queue\n",p);
	}
}

int del()
{
	int x;
	x=queue[front];
	if(front==rear){
	    front=rear=-1;
	}
    else{
    	front=(front+1)%MAXSIZE;
	}
	return x;
}

void display()
{
	int i;
	if(front==-1){
		printf("Queue is in underflow\n");
	}
	else{
		if(front<=rear){
			for(i=front;i<=rear;i++){
				printf("%d\t",queue[i]);
			}	
		}
		else{
			for(i=front;i<=MAXSIZE-1;i++){
				printf("%d\t",queue[i]);
			}
			for(i=0;i<=rear;i++){
				printf("%d\t",queue[i]);
			}
		}
	}
	
}

int isFull(){
	if((front==0 && rear==MAXSIZE-1)||(front==rear+1)){
		printf("Yes, The Queue is Full\n");
		return 1;
	}
	else{
		printf("No, The Queue is not Full\n");
		return 0;
	}
}

int isEmpty(){
	if(front == -1){
		printf("Yes, The Queue is Empty\n");
		return 1;
	}
	else{
		printf("No, The Queue is not Empty\n");
		return 0;
	}
}

int main()
{
	int ch,k,p;
	printf("----- Implementation of Circulr Queue -----\n\n");
	while(1)
	{
		printf("\n1. INSERT\n2. DELETE\n3. DISPLAY\n4. IS_FULL\n5. IS_EMPTY\n6. EXIT\n\n");
		printf("Enter your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1: printf("Enter the value to be inserted : ");
			 	scanf("%d",&k);
				insert(k);
				break;
	
		case 2: if(front==-1){
				    printf("Queue is in underflow\n");
				}
				else{
					p = del();
				    printf("The deleted element = %d\n",p);
				}
				break;
		
		case 3: printf("Displaying Circular Queue :\n");
				display();
				break;
				
		case 4: isFull();
			 	break;
		
		case 5: isEmpty();
			 	break;
		
		case 6: exit(0);
		
		default: printf("Invalid Input !!!\n");
		
		}
	}
	return 0;
}
