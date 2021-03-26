#include<stdio.h>
int main()
{
	int i,j,k,s,n,f=0;
	printf(" enter the no. of row:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		k=i;
		f=0;
		for(s=1;s<=n-i;s++)
		{
			printf("  ");
		}
		for(j=1;j<=2*i-1;j++)
		{
			printf("%d ",k);  
			if((k<(2*i-1))&&f==0)
			{
				k++;
			}
			else
			{
				k--;
				f=1;
			}
		}	
		printf("\n");
	}
	return 0;	
}
