#include<stdio.h>
int main()
{
	int i=0,a[200],t=0,j=0,n,k;
	scanf("%d",&t);
	while(t!=-1){
		
		a[i]=t;
		scanf("%d",&t);
		i++;
		
	}
	
	scanf("%d",&n);
	k=i-n;
	while(j<n){
		printf("%d\t",a[k]);
		j++,k++;
	}
	return 0;
}
