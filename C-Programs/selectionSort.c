#include <stdio.h>
#define LENGTH 20

void selectionSort(int[], int);
void swap(int*, int*);

int main(){
	int arr[LENGTH],n,i;
	printf("Enter Array Size :\n");
	scanf("%d",&n);
	printf("Enter the Array Elements :\n");
	for(i=0;i<n;i++){
    	scanf("%d",&arr[i]);
	}
//	calling sorting function
	selectionSort(arr,n);
//	printing array
	printf("Sorted Array is :\n");
	for(i=0;i<n;i++){
    	printf("%d\t",arr[i]);
	}
	return 0;
}


void selectionSort(int arr[], int n){
    int i, j, min_id;
    for (i = 0; i < n-1; i++) { 
        min_id = i; 
        for (j = i+1; j < n; j++){
          if (arr[j] < arr[min_id]){
          	min_id = j; 
		  }
		}
        if(min_id != i){
//        	from swap function
        	swap(&arr[i],&arr[min_id]);
        }
    } 
}


void swap(int *p, int *q){
	*p = *p + *q;
	*q = *p - *q;
	*p = *p - *q;
}

