#include<stdio.h>
#include<math.h>
#include<string.h>
int base(char *a,int len)
{
    int max=a[0],base;
    for(int i=1;i<len;i++)
    {
        if(a[i]>max)
            max=a[i];
    }
    if(max>=65)
        base=(max-55)+1;
    else
        base=max-48+1;
}

int highdigit(int num)
{
    int digi,max;
    max=num%10;
    num=num/10;
    while(num!=0)
    {
        digi=num%10;
        if(digi>max)
            max=digi;
        num=num/10;
    }
    return max;
}

int baseconvert(int num,int base)
{
    int expo=0,sum=0,rem;
    while(num!=0)
    {
        rem=num%10;
        sum+=rem*pow(base,expo);
        expo++;
        num=num/10;
    }
    return sum;
}

int main()
{
    char arr[100];
    int x,len,sum=0,ba,i;
    scanf("%s",arr);
    len=strlen(arr);
    ba=base(arr,len);
    for(i=0;i<len;i++)
    {
        if(arr[i]>=65)
            sum+=(arr[len-1-i]-55)*pow(ba,i);
        else
            sum+=(arr[len-1-i]-48)*pow(ba,i);
    }
    
    while(1)
    {
        int check,base,result;
        check=highdigit(sum);
        base=check+1;
        result=baseconvert(sum,base);
        if(sum==result)
            break;
        else
            sum=result;
        
    }
    printf("%d",sum);      
}