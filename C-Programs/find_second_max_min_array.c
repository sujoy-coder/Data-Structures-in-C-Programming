#include <stdio.h>

void second_max_min(int arr[], int n){
	int i,max,min,max_pre,min_pre;
	if(n<2){
		printf("Second Max : %d\nSecond Min : %d",arr[0],arr[0]);
	}
	else{
		if(arr[0]<arr[1]){
			min_pre = max = arr[1];
			max_pre = min =arr[0];
		}
		else{
			min_pre = max = arr[0];
			max_pre = min =arr[1];
		}
		for(i=2;i<n;i++){
//			for getting 2nd maximum
			if((max>arr[i])&&(arr[i]>max_pre)){
				max_pre = arr[i];
			}
			else if((arr[i]>max)){
				max_pre = max;
				max = arr[i];
			}
//			for getting 2nd minimum
			if((arr[i]>min)&&(arr[i]<min_pre)){
				min_pre = arr[i];
			}
			else if((arr[i]<min)){
				min_pre = min;
				min = arr[i];
			}
		}
		printf("Second Max : %d\nSecond Min : %d",max_pre,min_pre);
	}
}


int main(){
	int arr[20],i,n;
	printf("Enter array size : ");
	scanf("%d",&n);
	printf("Enter array elements :\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("\n");
	printf("Given array elements are :\n");
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
	second_max_min(arr,n);
	return 0;
}



