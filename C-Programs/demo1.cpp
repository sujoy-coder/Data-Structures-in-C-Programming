#include<stdio.h>
#include<string.h>
//void add(int*,int);
char fun(char[]);
int main()
{
	char a[5],b[10];
//	for(int i=0;i<2;i++)
//		scanf("%d",&a[i]);
//	printf("from main\n");
//	for(int i=0;i<2;i++)
//		printf("%d\n",a[i]);
//	printf("from fun\n");
//	add(a,2);
//	for(int i=0;i<2;i++)
//		printf("%d\n",a[i]);
	gets(a);
	
	
		printf("%s",fun(a));

	return 0;
	
}

char fun(char x[])
{
//	for(int i=0;i<y;i++)
//		*(x+i)+=2;
	return 'a';
}
