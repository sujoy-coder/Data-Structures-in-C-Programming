#include <stdio.h>
#define LENGTH 20

int main(){
	int arr[LENGTH],len,j,flag;
	printf("Enter Size : ");
	scanf("%d",&len);
	printf("Enter the Elements : \n");
	for(int i=0;i<len;i++){
    	scanf("%d",&arr[i]);
	}
//	apply the logic,if array is sorted in ascending order
	flag = 1;
	for(j=0;j<len-1;j++){
		if(arr[j]>arr[j+1]){
			flag = 0;
			break;
		}
	}
	if(flag){
		printf("The array is sorted in ascending order\n");
	}
	else{
 	    printf("The array is not sorted in ascending order\n");
	}
	return 0;
}


