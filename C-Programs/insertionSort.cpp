#include <stdio.h>
#define LENGTH 20

void insertionSort(int[], int);

int main(){
	int arr[LENGTH],len;
	printf("Enter Size : ");
	scanf("%d",&len);
	printf("Enter the Array Elements :\n");
	for(int i=0;i<len;i++){
    	scanf("%d",&arr[i]);
	}
	printf("------------------------------------\n");
//	sorting the array
	insertionSort(arr,len);
	printf("------------------------------------\n");
//	printing array after sorting
	printf("Sorted Array is :\n");
	for(int i=0;i<len;i++){
    	printf("%d\t",arr[i]);
	}
	return 0;
}


void insertionSort(int arr[], int len){
	int i,j,temp,k;
	for(i=1;i<len;i++){
		temp = arr[i];
		j = i - 1;
		while(j>=0 && (arr[j]>temp)){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
//		showing matrix after each pass.Where, pass_no = (len-1)
		printf("After Pass: %d\n",i);
		for(k=0;k<len;k++){
  		    printf("%d\t",arr[k]);
		}
		printf("\n");
	}
}



