//This is The Coding Area
#include<stdio.h>

int main()
{
  int coin,c1,c2,c5;
  unsigned int x;
  scanf("%u",&x);
    if(x>0&&x<100000)
    {
    	if(x%5==0)
      		coin=(x/5)+2;
    	else if(x%5==1||x%5==2||x%5==4)
      		coin=(x/5)+3;
		else
      		coin=(x/5)+4;
        if(x%5==0)
        {
        
        	c1=1;
          	c2=2;
          	c5=coin-c1-c2;
        
        
        }
		else if(x%5==1)
        {
        
        	c1=2;
          	c2=2;
          	c5=coin-c1-c2;
        
        
        }
        else if(x%5==2)
        {
        
        	c1=1;
          	c2=3;
          	c5=coin-c1-c2;
        
        
        }
      else if(x%5==3)
        {
        
        	c1=2;
          	c2=3;
          	c5=coin-c1-c2;
        
        
        }
      else 
        {
        
        	c1=2;
          	c2=2;
          	c5=coin-c1-c2;
        
        
        }
      
      printf("%d\t%d\t%d\t%d",coin,c5,c2,c1);
        
    
    }
  
  
  return 0;
  
}