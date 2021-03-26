#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

int binarySearch(int[], int, int);
void sort(int[], int);

int main(){
	int arr[SIZE],key,len,i,st;
	printf("Enter Array Size :\n");
	scanf("%d",&len);
	printf("Enter the Array Elements in Sorted order :\n");
	for(i=0;i<len;i++){
    	scanf("%d",&arr[i]);
	}
//	sorting the array
//	sort(arr,len);
	
	printf("\n");
	while(1){
	printf("\n1. Search\n2. Exit\n");
	scanf("%d",&st);
	switch(st){
		case 1: //	searching element in array
			 		printf("Enter The Element you want to search :\n");
					scanf("%d",&key);
					binarySearch(arr,len,key);
			 		break;
			 	
		case 2: exit(0);
		
		default:printf("Invalid input !!!\n");
		}
	}
	return 0;
}

int binarySearch(int array[], int len, int search){
	int first = 0, last = len - 1, middle;
	middle = (first+last)/2;
	while (first <= last) {
	if (array[middle] == search) {
      printf("%d found at index %d.\n", search, middle+1);
      return 1;
    }
    else if (array[middle] < search){
    	first = middle + 1;
	}
    else{
    	last = middle - 1;
	}	
    middle = (first + last)/2;
  	}
  	if (first > last){
  		printf("Not found!!! %d is not present.\n", search);
	}
	return 0;
    
}

// bubble sorting
void sort(int arr[], int len){
	int i,j;
	for(i=0;i<len-1;i++){
		for(j=0;j<len-1-i;j++){
			if(arr[j]>arr[j+1]){
				arr[j] = arr[j] + arr[j+1];
				arr[j+1]= arr[j] - arr[j+1];
				arr[j] = arr[j] - arr[j+1];
			}
		}
	}
}
