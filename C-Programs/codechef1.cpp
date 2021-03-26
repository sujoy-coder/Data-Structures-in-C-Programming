#include<stdio.h>
int main()
{
	
	int t,n,i,k,a[10];
	printf("try:");
	scanf("%d",&t);
	while(t>0)
	{
		int f=0;
		printf("size:	key:");
		scanf("%d%d",&n,&k);
		printf("elements:");
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<n-1;i++)
		{
			if((a[i]+a[i+1])==k)
			{
				f=1;
				break;
			}
		}
		if(f==1)
			printf("yes\n");
		else
			printf("no\n");
		t--;
	
	}
	return 0;
}

