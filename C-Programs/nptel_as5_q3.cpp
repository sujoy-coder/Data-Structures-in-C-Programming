#include<stdio.h>
#include<stdlib.h>
#include<string.h>
static char *p;

static char *p1;
int f (int);

int main()
{
char s[10],s1[10];
int l,i;
scanf ("%s",s);
i=0;
while (s[i]!='\0')
{
i++;
}
l=i;
p=s;
p1=s1;
f(l-1);

puts(s1);

/*
for(i=0;i<l;i++)
	printf("%c",s1[i]);

*/

return 0;
}
int f(int k)
{
if(k>0){
*p1=*(p+k);
k--;
p1++;
return f(k);
}
else {
	*p1='\0';
	
	return ;
}
}
