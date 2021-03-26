#include<stdio.h>
int main()
{
   int i=0,n=0,j;
   float a[50],ip=0.0,sum,avg;
   while(ip!=-1&&i>=0)
   {
   		scanf("%f",&ip);
     	a[i]=ip;
     	i++;
     	n++;
   
   
   }
  n--;
  if(n>=3)
  {
      for(i=0;i<n-1;i++)
      {
      sum=0;
      for(j=i+2;j>=i;j--)
      {
          sum=sum+a[j];
      }
      printf("%.1f ",(sum/3));
      }
   
  
  }
  
   
    
    return 0;
}
