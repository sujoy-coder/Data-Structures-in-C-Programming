#include<stdio.h>
int main()
{
	int n1,n2,a1[20],a2[20],i,j,f=0,c=0;
	scanf("%d",&n1);
	for(i=0;i<n1;i++)
		scanf("%d",&a1[i]);
	scanf("%d",&n2);
	for(i=0;i<n2;i++)
		scanf("%d",&a2[i]);
		
	for(i=0;i<n1-1;i++)
	{
		for(j=0;j<(n1-1-i);j++)
		{
			if(a1[j]>a1[j+1])
			{
				a1[j]=a1[j]+a1[j+1];
				a1[j+1]=a1[j]-a1[j+1];
				a1[j]=a1[j]-a1[j+1];
			}
		}
	}
	
	for(i=0;i<n1;i++)
	{
		f=0;
		for(j=0;j<n2;j++)
		{
			if(a1[i]==a2[j])
			{
				f=1;
				break;
			}
		}
		if(f==0)
			break;
		c++;
	}
	if(f==0)
		printf("%d",a1[c]);
	else
		printf("NO");
		
		
  return 0;
	
}

