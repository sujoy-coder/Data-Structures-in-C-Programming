#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

int binarySearchRecursive(int[], int, int, int);

int main(){
	int arr[SIZE],key,len,i,st;
	printf("Enter Array Size :\n");
	scanf("%d",&len);
	printf("Enter the Array Elements :\n");
	for(i=0;i<len;i++){
    	scanf("%d",&arr[i]);
	}
	printf("\n");
	while(1){
		printf("\n1. Search\n2. Exit\n");
		scanf("%d",&st);
		switch(st){
			case 1: //	searching element in array
				 		printf("Enter The Element you want to search :\n");
						scanf("%d",&key);
						binarySearchRecursive(arr,0,len-1,key);
				 		break;
				 	
			case 2: exit(0);
			
			default:printf("Invalid input !!!\n");
		}
	}
	return 0;
}


int binarySearchRecursive(int array[], int first, int last, int search){
	if(first <= last){
		int middle;
		middle = (first + last)/2;
		if(array[middle] == search){
			printf("%d found at position %d.\n", search, middle+1);
			return 1;
		}
		else if(array[middle] < search){
			return binarySearchRecursive(array,middle+1,last,search);
		}
		else{
			return binarySearchRecursive(array,first,middle-1,search);
		}
	}
	else{
		printf("Not found!!! %d is not present.\n", search);
		return 0;
	}
}

