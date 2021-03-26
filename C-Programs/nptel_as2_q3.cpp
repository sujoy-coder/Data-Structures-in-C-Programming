#include<stdio.h>
int main()
{
	int key,f,flag=0,pre;
	scanf("%d",&key);
	f=key;
	do{
		
		if(key==-1)
		{
			flag=0;
			break;//0
		}
		else if(f!=key)
		{
			flag=1;//1
		}
		scanf("%d",&key);
		
	}while(key!=-1);
	
	if(flag==1)
		printf("1");
	else
		printf("0");
	
}
