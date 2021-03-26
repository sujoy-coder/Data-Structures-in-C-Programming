#include <stdio.h>
#define LENGTH 20

int mod(int);
int checkAscendingDecending(int[], int);

int main(){
	int arr[LENGTH],len,result,i;
	printf("Enter Size : ");
	scanf("%d",&len);
	printf("Enter the Elements : \n");
	for(i=0;i<len;i++){
    	scanf("%d",&arr[i]);
	}
//	function calling
	result = checkAscendingDecending(arr,len);
	if(result == 1){
		printf("The array is sorted in ascending order.\n");
	}
	else if(result == 2){
		printf("The array is sorted in decending order.\n");
	}
	else if(result == -1){
		printf("All the elements of array are same,it may ascending or decending array.\n");
	}
	else{
		printf("The array is not a sorted array.\n");
	}
	
	return 0;
}

int checkAscendingDecending(int arr[], int len){
	int i,sum=0,previous_sum=0;
	for(i=0;i<len-1;i++){
		sum += (arr[i+1] - arr[i]);
		if(mod(previous_sum)>mod(sum)){
//			for not sorted array
			return 0;
		}
		previous_sum = sum;
	}
	if(sum == 0){
//		may be ascending/decending array
		return -1;
	}
	else if(sum>0){
//		for ascending array
		return 1;
	}
	else if(sum<0){
//		for decending array
		return 2;
	}
}

int mod(int number){
	if(number>=0){
		return number;
	}
	else{
		number = -number;
		return number;
	}
}




/*
#include<stdio.h>
int main()
{
    int arr[100],i,n,a=1,d=1;
    printf("How many elements:");
    scanf("%d",&n);
    printf("Enter array elements:\n");
    for(i=0;i<n;++i)
        scanf("%d",&arr[i]); 
   
    for(i=0;i<n-1;i++)
    {
         if(arr[i]<arr[i+1]) 
            {
                d=0;
            }
        else if(arr[i]>arr[i+1])
            {
                a=0;
            }
        if (a==0 && d==0 )
        {
            printf("The array is not sorted.\n");
            break;
        }
    }
if (a == 1)
    printf("The array is sorted in ascending order.\n");
  else if (d == 1)
    printf("The array is sorted in descending order.\n");
  
return 0;
}

*/


