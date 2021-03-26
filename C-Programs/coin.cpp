#include<stdio.h>
int sum(int[],int);

int main()
{
	
	int n,a[20],f=0,temp,avg,k,i;
	scanf("%d",&n);
	printf("Enter coins:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	avg=(sum(a,n))/n;
	for(i=0;i<n;i++)
	{
		temp=a[i];
		a[i]=0;
		k=(sum(a,n))/(n-1);
		if(k==avg)
		{
			f=1;
			printf("Yes\tCoin No=%d\n",i+1);
			break;
		}
		a[i]=temp;
		
	}
	
	if(f==0)
	{
		printf("No\n");
	}
	
return 0;
  
}

int sum(int a[],int p)
{
	int i,s=0;
	for(i=0;i<p;i++)
		s=s+a[i];
		
  return s;
	
}

