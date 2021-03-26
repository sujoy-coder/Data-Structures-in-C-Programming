#include<stdio.h>
int main()
{
	int i,j,a[20],n,de,el=0;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<(n-1-i);j++)
		{
			if(a[j]>a[j+1])
			{
				a[j]=a[j]+a[j+1];
				a[j+1]=a[j]-a[j+1];
				a[j]=a[j]-a[j+1];
			}
		}
	}
	
	for(i=0;i<n-1;i++)
	{
		de=0;
		for(j=0;j<(n-1-i);j++)
		{
			if(a[j]==a[j+1])
			{
				de++;
				
			}
		}
		if(de!=0)
			el=el+(1+1*de);
			
			
	}
  return 0;
}








