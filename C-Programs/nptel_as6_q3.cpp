#include<stdio.h>
int main()
{
	int i=0,k=1,t=2,a[20],x,j,f=0,m,n;
	scanf("%d",&m);
	scanf("%d",&n);
	a[0]=m;
	if(m<n)
	{
		for(i=0;i<n;i++)
		{
			x=(t*m)%n;
			a[k]=x;
			for(j=0;j<k;j++)
			{
				if(a[j]==x)
				{
					f=1;
					break;
				}
			}
			if(f==1)
			{ 
				break;
			}
			else
			{
				t=t*2;
				k++;
			}
		}
		printf("%d",k);
		
	}
	else
		printf("");
		
		
  return 0;
}
