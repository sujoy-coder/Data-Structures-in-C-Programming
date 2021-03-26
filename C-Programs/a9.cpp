#include<stdio.h>
union student
{
	char name[30];
	int r,m;
};
int main()
{
	union student s;
	printf("enter details\n");
	scanf("%s%d%d",s.name,&s.r,&s.m);
	printf("details are:\n%s\t%d\t%d",s.name,s.r,s.m);
	return 0;
}
