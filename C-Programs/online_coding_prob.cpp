#include<stdio.h>
void sort(int[],int);
void marge(int[],int[],int);
int sum(int[],int);
int main()
{
	int i,j,X,N,Y,s=0,f=0;
	scanf("%d%d%d",&N,&X,&Y);
	int arr1[2*N],arr2[N];
	for(i=0;i<N;i++)
		scanf("%d",&arr1[i]);
	for(i=0;i<N;i++)
		scanf("%d",&arr2[i]);	
	marge(arr1,arr2,N);
	sort(arr1,2*N);
	s=sum(arr1,N);
	printf("%d",s);

	return 0;
}

void sort(int a[],int n)
{
	int i,j,t;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j]<a[j+1]){
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
}

int sum(int arr[],int n)
{
	int s=0,i;
	for(i=0;i<n;i++)
		s+=arr[i];
	
	return s;
}

void marge(int a[],int b[],int n)
{
	int i,j;
	
	i=n;
	j=0;
	while(i<2*n&&j<n)
	{
		a[i]=b[j];
		i++,j++;
	}

}

