#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int strilen(char *str)
{
	int i,c=0;
	for(i=0;str[i]!='\0';i++)
		c++;
	return c;
	
}
void stricpy(char *s1,char *s2;int k)
{
	int i;
	for(i=0;i<n;i++)
		s1[i]=s2[i];
	s1[i]='\0';
	
}
int main()
{
	char str[102];
	int u=0;
	str[u]=getchar()
	while(str[u]!=EOF)
	{
		u++;
		str[u]=getchar();
		
	}
	str[u+1]='\0';
	char s1[100],s2[100];
	int i,j,k,c=-1;
	for(i=0;i<strilen(str);i++)
	{
		stricpy(s1,str,i+1);
		int i=strilen(s1),c1=0;
		for(j=0;j<strilen(str);j++)
		{
			for(k=0;k<l;k++)
			{
				if(str[j+k]!=s1[k])
					break;
			
			}
			if(k==l)
			{
				c1++;
				k=0;
				
			}
		}
		if(c1>1)
		{
			if(c<l)
			{
				c=l;
				stricpy(s2,s1,l);
				
			}
		}
	}
	if(c!=-1)
		printf("%s",s2);
	else
		printf("NO");
		
		
   return 0;
	
}
