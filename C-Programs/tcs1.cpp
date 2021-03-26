#include<stdio.h>
int main()
{
	
	unsigned int n,s,x,y,z,five,two,one;
	printf("enter a number:");
	scanf("%u",&n);
	if(n>0&&n<100000)
	{
		x=(n/2)/5;
		five=n/5;
		y=n%5;
		one=y%2;
		two=y/2;
		five=five-x;
		two=two+five*2;
		one=one+five;
		if(n<9)
		{
			five=0;	
		}
		s=five+two+one;
		printf("%d %d %d %d \n",s,z,two,one);
	}
	
	
	
	return 0;
}
