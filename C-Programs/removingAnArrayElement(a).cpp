#include <stdio.h>
void remArray(int[],int);

int main() {    
	int arr[40],len;
	printf("Enter Size :");
	scanf("%d",&len);
	printf("Enter the elements :");
    for(int i=0;i<len;i++){
    	scanf("%d",&arr[i]);
	}
	remArray(arr,len);
    return 0;
}
// Removing Method, Coping array to another array
void remArray(int arr[],int len){
	int pos,newArr[40];
	repeact:
		printf("\nEnter Position you want to remove :");
		scanf("%d",&pos);
		if(pos>len || pos<1){
			printf("You are outof index, Please Enter Position in the Range of 1 to %d",len);
			goto repeact;
		}
		else{
			for(int i=0;i<(len-1);i++){
				if(i >= (pos-1)){
					newArr[i] = arr[i+1];
				}
				else{
					newArr[i] = arr[i];
				}
			}
		}
		
		for(int i=0;i<(len-1);i++){
	    	printf("%d",newArr[i]);
	    	printf("\n");
		}
}
