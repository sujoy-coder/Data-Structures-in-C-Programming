#include <stdio.h>
#define LENGTH 20

void modifiedBubbleSort(int*, int);

int main(){
	int arr[LENGTH],len;
	printf("Enter Size :");
	scanf("%d",&len);
	printf("Enter the Elements :");
	for(int i=0;i<len;i++){
    	scanf("%d",&arr[i]);
	}
//	sorting the array
	modifiedBubbleSort(arr,len);
//	printing array
	printf("Sorted Array is :\n");
	for(int i=0;i<len;i++){
    	printf("%d\t",arr[i]);
	}
	return 0;
}


void modifiedBubbleSort(int *arr, int len){
	int i,j,t,flag;
	for(i=0;i<len-1;i++){
		flag = 1;
		for(j=0;j<len-1-i;j++){
			if(arr[j]>arr[j+1]){
				t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
				flag = 0;
			}
		}
		if(flag){
			break;
		}
	}
}
