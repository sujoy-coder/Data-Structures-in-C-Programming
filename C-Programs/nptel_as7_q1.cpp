#include<stdio.h>
#include<string.h>
struct student 
{
	
	char n[130];
	
	int p,m,c;
};
void swap(struct student*,struct student*);
int main()
{
	struct student s[100];
	int i,j,a;
	char nam[130];
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		scanf("%s",s[i].n);
		scanf("%d",&s[i].p);
		scanf("%d",&s[i].c);	
		scanf("%d",&s[i].m);	
				
	}
	
	for (i = 0; i < a-1; i++)       
    {
	  
       for (j = 0; j < a-i-1; j++){
	   
           if ((s[j].p>s[j+1].p))
           {
           		swap(&s[j],&s[j+1]);
		   }

		}
	}
	
	for (i = 0; i < a-1; i++)       
    {
	  
       for (j = 0; j < a-i-1; j++){
	   
           if (((s[j].p==s[j+1].p)&&(s[j].c==s[j+1].c)&&(s[j].m>s[j+1].m))||((s[j].p==s[j+1].p)&&(s[j].c>s[j+1].c)))
           {
           		swap(&s[j],&s[j+1]);
		   }

		}
	}
	/*
	for (i = 0; i < a-1; i++)       
    {
	  
       for (j = 0; j < a-i-1; j++){
	   
           if ((s[j].p==s[j+1].p)&&(s[j].c==s[j+1].c)&&(s[j].m>s[j+1].m))
           {
           		swap(&s[j],&s[j+1]);
		   }

		}
	}	
	*/
	for (i = 0; i < a-1; i++)       
    {
	  
       for (j = 0; j < a-i-1; j++){
	   
           if ((s[j].p==s[j+1].p)&&(s[j].c==s[j+1].c)&&(s[j].m==s[j+1].m))
           {
           		if(strcmp(s[j].n,s[j+1].n)>0)
           		{
           			strcpy(nam,s[j].n);	
					strcpy(s[j].n,s[j+1].n);
					strcpy(s[j+1].n,nam);	
           			
				}
		   }

		}
	}
	
	for(i=0;i<a;i++)
	{
		printf("%s\t%d\t%d\t%d\n",s[i].n,s[i].p,s[i].c,s[i].m);
				
	}		
	
	
	
	
	return 0;
}
void swap(struct student *p,struct student *p1)
{
	char name[130];

	strcpy(name,p->n);	
	strcpy(p->n,p1->n);
	strcpy(p1->n,name);
		
	p->p=p->p+p1->p;
	p1->p=p->p-p1->p;
	p->p=p->p-p1->p;
	
	p->c=p->c+p1->c;
	p1->c=p->c-p1->c;
	p->c=p->c-p1->c;
	
	p->m=p->m+p1->m;
	p1->m=p->m-p1->m;
	p->m=p->m-p1->m;
	
}
