#include<stdio.h>
int main()
{
	int i,j,n;
	// printf("enter the no. of row:");
	// scanf("%d",&n);
	n = 5;
	for(i=1;i<=n;i++)
	{
		j=1;
		do
		{	

			printf("* ");
			j++;
		}while(j<=2*i-2);
		
		
		printf("\n");
		
	}

	return 0;
}
