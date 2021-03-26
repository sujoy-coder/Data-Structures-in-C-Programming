#include<stdio.h>
int main()
{
  char s[10]="hugman";
  char ch;	
  int i,n,j=0,flag=0;
  printf("enter no. of attempts:");
  scanf("%d",&n);
  for(i=n;i>=1;i--)
   {
	printf("enter any letter:");
	scanf("%c",&ch);
		while(s[j]!='\0')
		{
		     if(s[j]==ch)
		       {
 printf("letter matches\n you have %d chance",(n-i));
			  flag=1;
			  break;
		       }	
		   j++;
		}
	if(flag==0)
	{
	    printf("letter is not matched");
	    printf("you have %d chance",(n-i));
	}
       
   }
   return 0;
}	

