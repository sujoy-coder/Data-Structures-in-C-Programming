# include <stdio.h>
void sumArray(int[],int);

int main() {    
	int arr[40],len;
	printf("Enter Size :");
	scanf("%d",&len);
	printf("Enter the elements :\n");
    for(int i=0;i<len;i++){
    	scanf("%d",&arr[i]);
	}
	sumArray(arr,len);
    return 0;
}

void sumArray(int arr[],int len){
	int sum = 0;
	for(int i=0;i<len;i++){
		sum += arr[i];
	}
	printf("The sum of array is  : %d",sum);
}
