#include <stdio.h>

int nSum(int);

int main(){
	int n;
	printf("Enter the positive Number : ");
	scanf("%d",&n);
	printf("The sum of first %d integer is = %d ",n,nSum(n));

	return 0;
}

int nSum(int n){
	if(n == 1){
		return 1;
	}
	else{
		return n+nSum(n-1);
	}
}
