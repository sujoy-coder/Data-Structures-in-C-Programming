//This is The Coding Area
#include<stdio.h>

int main()
{
  int x,n,coin;
  scanf("%d",&n);
  if(n>=1&&n<=100)
  {
  while(n>0)
  {
  	scanf("%d",&x);
    if(x>=1&&x<=5000)
    {
    if(x%5==0)
      coin=(x/5)+2;
    else if(x%5==1||x%5==2||x%5==4)
      coin=(x/5)+3;
    else
      coin=(x/5)+4;
    printf("%d\n",coin);
    }
    
    n--;
  
  }
    
    
  }
 return 0; 
}  