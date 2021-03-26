#include <stdio.h>

int partition(int *arr, int lb, int ub){
	int pivot = arr[lb], i = lb+1, j = ub, temp;
	while(i<=j){
		while((arr[i]<= pivot) && (i<=ub)){
			i++;
		}
		while(arr[j]>pivot){
			j--;
		}
		if(i<j){
//			swap b/n arr[i] and arr[j]
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++,j--;
		}
	}
	arr[lb] = arr[j];
	arr[j] = pivot;
	return j;
}

void quickSort(int *arr, int lb, int ub){
	int pos;
	if(lb<ub){
		pos = partition(arr,lb,ub);
		quickSort(arr,lb,pos-1);
		quickSort(arr,pos+1,ub);	
	}
}

int main(){
	int n,i,arr[10];
	printf("Enter the length of array : ");
	scanf("%d",&n);
	printf("Enter the elements of array one by one -->\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	quickSort(arr,0,n-1);
	printf("After Sorting the array is -->\n");
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	return 0;
}


