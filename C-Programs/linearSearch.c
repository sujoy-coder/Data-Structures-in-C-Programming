#include <stdio.h>

int linearSearch(int[], int*, int*);

int main(){
	int arr[20],key,len,i;
	printf("Enter Array Size :\n");
	scanf("%d",&len);
	printf("Enter the Array Elements :\n");
	for(i=0;i<len;i++){
    	scanf("%d",&arr[i]);
	}
	printf("Enter The Element you want to search :\n");
	scanf("%d",&key);
//	function calling
	linearSearch(arr,&len,&key);
	return 0;
}

int linearSearch(int arr[], int *len, int *key){
	int i;
	for(i=0;i<*len;i++){
		if(arr[i] == *key){
			printf("\n%d found at Index Position = %d\n",*key,i);
			return 1;
		}
	}
	printf("\n%d is not found !!!\n",*key);
	return 0;
}

