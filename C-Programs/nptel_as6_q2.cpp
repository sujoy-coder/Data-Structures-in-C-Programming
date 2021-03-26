#include<stdio.h>
int main()
{
	char s[20];
	int a[20],i=0,j,c,p=0,temp;
	scanf("%s",s);
	while(s[i]!='\0')
	{
		c=1;
		j=i+1;
		while(s[j]!='\0')
		{
			if(s[i]==s[j])
				c++;
			else
				break;
				
		    j++;
		    
		}
		a[i]=c;
		p++,i++;
	}
	
	for (i = 0; i < p-1; i++) {
      for (j = i+1; j < p; j++) {
         if (a[i] > a[j]) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
         }
      }
   }
   printf("%d",a[p-1]);
   
   
  return 0;
}
