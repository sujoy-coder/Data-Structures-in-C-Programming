#include<stdio.h>
int find_even(int);
int main()
{
	int k;
	scanf("%d",&k);
	if(k>0)
		printf("%d",find_even(k));
		
		
	return 0;
}

int find_even(int k)
{
	int test,c=0,dp=-1;
	scanf("%d",&test);
	while(test!=-1&&test>0)
	{
		if(test%2==0)
		{
			dp=test;
			c++;
		}
		scanf("%d",&test);
		
	}
	
	if(k==c)
		return dp;
	else
		return -1;
}
