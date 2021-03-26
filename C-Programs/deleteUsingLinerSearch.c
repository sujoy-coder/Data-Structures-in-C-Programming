#include <stdio.h>
#define LENGTH 20

int remElementArray(int[],int,int*);

int main(){
	int arr[LENGTH],len,key,i,result;
	printf("Enter Size :");
	scanf("%d",&len);
	printf("Enter the elements :\n");
    for(i=0;i<len;i++){
    	scanf("%d",&arr[i]);
	}
	printf("Enter The Element you want to remove : ");
	scanf("%d",&key);
//	function calling
	result = remElementArray(arr,key,&len);
//	displaying the array after removing the element
	if(result){
		printf("Modified Array is :\n");
		for(i=0;i<len;i++){
	    	printf("%d\t",arr[i]);
		}
	}
	else{
		printf("%d is not found !!!\nGiven Array is : \n",key);
		for(i=0;i<len;i++){
	    	printf("%d\t",arr[i]);
		}
	}
	return 0;
}


// this function remove first found element only 
int remElementArray(int arr[], int key, int *len){
	int i,j,pos;
	for(i=0;i<*len;i++){
		if(arr[i] == key){
//			start of deleting logic
			pos = i + 1;
			for(j = (pos-1);j<(*len-1);j++){
			    arr[j] = arr[j+1];
			}
//			end of deleting Logic
			*len = *len - 1;
			return 1;
		 }
	}
	return 0;
}
