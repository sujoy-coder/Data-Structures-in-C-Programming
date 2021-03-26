// Application of STACK : Equation validation.....
#include <stdio.h>
#define SIZE 20

char stack[SIZE];
int top = -1;

void push(char ch){
	if(top < SIZE-1){
		stack[++top] = ch;
	}	
}

char pop(){
	if(top > -1){
		return stack[top--];
	}
	return '\0';
	
}

int main(){
	char eqn[50],ch;
	int i;
	printf("Enter The Equation : ");
	gets(eqn);
	for(i=0;(ch=eqn[i]) != '\0';i++){
		if(ch == '('){
			push(ch);
		}
		else if((ch == ')') && (pop() != '(')){
			printf("Not Valid Eqation...\n");
			return 0;
		}
	}
	
//	finally if the STACK is not Empty after scanning whole expression, then also the eqation is not valid
	if(top == -1){
		printf("Valid Eqation...\n");
	}
	else{
		printf("Not Valid Eqation...\n");
	}
	return 0;
}


