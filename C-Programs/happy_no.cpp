#include<stdio.h>
int main()
{
	int n,i=0,rem,j,flag=0,sum=-1;
	int a[50];
	printf("enter a number:");
	scanf("%d",&n);
	while((sum!=1)&&(sum!=4))
	{
		for(j=0;j<i-1;j++)
		{
			if(a[j]==sum)
			{
				flag=1;
				break;
				
			}
		
		}
		if(flag==1)
		{
			break;	
		}

		sum=0;
		while(n>0)
		{
			
			rem=n%10;
			sum=sum+(rem*rem);
			n=n/10;
		}
		n=sum;
		a[i]=sum;
		i++;
	}
	
	if((sum==1)||(flag==1))
		printf("It is a HAPPY Number");
	else
		printf("It is not a HAPPY Number");
	
	
	
  return 0;	
	
}
