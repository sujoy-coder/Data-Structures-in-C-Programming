#include <stdio.h>
int maxMinArray(int[],int);

int main() {    
	int arr[40],len;
	printf("Enter Size :");
	scanf("%d",&len);
	printf("Enter the elements :\n");
    	for(int i=0;i<len;i++){
    	scanf("%d",&arr[i]);
	}
	maxMinArray(arr,len);
    return 0;
}

int maxMinArray(int arr[],int len){
	int max,min;
	max = min = arr[0];
	for(int i=1;i<len;i++){
		if(arr[i]>max){
			max = arr[i];
		}
		else if(arr[i]<min){
			min = arr[i];
		}
	}
	printf("Max Element is : %d",max);
	printf("\nMin Element is : %d",min);
	return 0;
}
