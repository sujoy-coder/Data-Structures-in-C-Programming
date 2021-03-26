#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char stack[20];
int top = -1;

void push(char ch){
	top++;
	stack[top] = ch;
}

char pop(){
	if(top > -1){
		return stack[top--];
	}
	else{
		printf("Invalid Expression...\n");
		exit(0);
	}
}

int prec(char ch){
	switch(ch){
		case '+': return 1;
		case '-': return 1;
		case '*': return 2;
		case '/': return 2;
		case '^': return 3;
		default : return -1;
	}
}

int main(){
	char infix[30],postfix[30],ch;
	int i = 0,j = 0;
	printf("Enter the infix expression :\n");
	gets(infix);
//	logic starts from here ...
	while((ch=infix[i]) != '\0'){
		if(isalnum(ch)){
			postfix[j] = ch;
			j++;
		}
		else if(ch == '('){
			push(ch);
		}
		else if(ch == ')'){
			while((ch=pop()) != '('){
				postfix[j] = ch;
				j++;
			}
		}
		else{
			while(prec(stack[top]) >= prec(ch)){
				postfix[j] = pop();
				j++;
			}
			push(ch);
		}
		i++;
	}
	while(top != -1){
		if((ch=pop()) != '('){
			postfix[j] = ch;	
		}
		else{
		    printf("Invalid Expression...\n");
	        exit(0);	
		}
		j++;
	}
	postfix[j] = '\0';
//	logic ends here ...
	printf("The Postfix form of given expression will be :\n");
	puts(postfix);
	
	return 0;
}
