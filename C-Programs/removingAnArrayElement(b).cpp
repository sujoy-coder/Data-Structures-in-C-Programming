#include <stdio.h>
void remArray(int*,int*,int);

int main() {    
	int arr[40],len,pos;
	printf("Enter Size :");
	scanf("%d",&len);
	printf("Enter the elements :\n");
    for(int i=0;i<len;i++){
    	scanf("%d",&arr[i]);
	}
	printf("\nEnter Position you want to remove :");
	scanf("%d",&pos);
	remArray(arr,&len,pos);
    return 0;
}

// Removing Method, in the same array
void remArray(int *arr,int *len, int pos){

	if(pos>*len || pos<1){
		printf("You are out of index");
	}
	else{
		for(int i = (pos-1);i<(*len-1);i++){
			arr[i] = arr[i+1];
		}
		
//		printing New Array
		printf("New Array is : \n");
		*len -= 1;
		for(int i=0;i<*len;i++){
    		printf("%d",arr[i]);
    		printf("\n");
		}
	}
	
}
