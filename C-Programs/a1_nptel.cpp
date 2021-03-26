#include<stdio.h>
int main()
{
	
	int n,k=1;
	scanf("%d",&n);
	while(n!=1)
	{
	
		k++;
		n=n*3+1;
	}
	printf("%d",k);

	return 0;
}

