#include <stdio.h>
#define LENGTH 20

void bubbleSort(int*, int);

int main(){
	int arr[LENGTH],len;
	printf("Enter Size :");
	scanf("%d",&len);
	printf("Enter the Elements :\n");
	for(int i=0;i<len;i++){
    	scanf("%d",&arr[i]);
	}
//	sorting the array
	bubbleSort(arr,len);
//	printing array
	printf("Sorted Array is :\n");
	for(int i=0;i<len;i++){
    	printf("%d\t",arr[i]);
	}
	return 0;
}


void bubbleSort(int *arr, int len){
	int i,j,t;
	for(i=0;i<len-1;i++){
		for(j=0;j<len-1-i;j++){
			if(arr[j]>arr[j+1]){
				t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
			}
		}
	}
}
