#include<stdio.h>
int len(char[]);
int sort(char[],char[],int);
int main()
{
	char s1[20],s2[20];
	int i=0,f=0,k=0,l1,l2,c=0;
	scanf("%s",s1);
	scanf("%s",s2);
	l1=len(s1);
	l2=len(s2);
	while(s1[i]!='\0'&&s2[i]!='\0')
		{
			if(s1[i]==s2[i])
			{
				f=1;	
				c++;
				
			}
			i++;
		}
	if(l1==l2)
		k=sort(s1,s2,l1);
	if(k==1)
	{
		printf("%d",c);
	}
	if(f==0)
		printf("-1");
		
  return 0;
}

int len(char s[])
{
	int i=0;
	while(s[i]!='\0')
	{
		i++;
	}
  return i;
}
int sort(char s1[],char s2[],int n)
{
	int i,j,f=1;
	char temp;
	
	for (i = 0; i < n-1; i++) {
      for (j = i+1; j < n; j++) {
         if (s1[i] > s1[j]) {
            temp = s1[i];
            s1[i] = s1[j];
            s1[j] = temp;
         }
      }
   }
   
   for (i = 0; i < n-1; i++) {
      for (j = i+1; j < n; j++) {
         if (s2[i] > s2[j]) {
            temp = s2[i];
            s2[i] = s2[j];
            s2[j] = temp;
         }
      }
   }
   
   for(i=0;i<n;i++)
   {
   		if(s1[i]!=s2[i])
   		{
   			f=0;	
		   break;
		}
   }
   
   if(f==1)
   {
		return 1;
   }
	else
	{
		return 0;
	}
	
	
}

