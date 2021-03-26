#include <stdio.h>

void nPrint(int);

int main(){
	int n;
	printf("Enter the positive Number : ");
	scanf("%d",&n);
	printf("The first %d numbers are :\n",n);
	nPrint(n);
	return 0;
}

void nPrint(int n){
	static int i = 1;
	if(n == 0){
		return;
	}
	else{
		printf("%d  ",i);
		i++;
		nPrint(n-1);
	}
}
