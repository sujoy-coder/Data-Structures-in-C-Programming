#include<stdio.h>
void insertElementArray(int[],int*,int,int);

int main(){
	int arr[20],len,pos,element;
	printf("Enter Size :");
	scanf("%d",&len);
	printf("Enter the Elements :\n");
	for(int i=0;i<len;i++){
    	scanf("%d",&arr[i]);
	}
	printf("Enter Position where you want to insert :");
	scanf("%d",&pos);
	printf("Enter the value of New Element : ");
	scanf("%d",&element);
	insertElementArray(arr,&len,pos,element);
	return 0;
}

void insertElementArray(int arr[], int* len, int pos, int element){
	
	if(pos>*len || pos<1){
		printf("You are out of index !!!");
	}
	else{
		for(int i =(*len-1);i >=(pos-1);i--){
			arr[i+1] = arr[i];
		}
		arr[pos-1] = element;
		
		printf("New Array is : \n");
		*len = *len+1;
		for(int i=0;i<*len;i++){
    		printf("%d",arr[i]);
    		printf("\n");
		}
	}	
}


