#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct item{
	int no;
	char name_itm[];
};
struct item itm[50];
float sum[50];
void show(void);
float gst(float);
float discount(float);
float total_sum(int);
char user[50],zip_code[50];
int main()
{
	
	
	int i=0,f=1,key,j;
	float gross_total,rebate;
	
	printf("\n\t\t--------WELCOME TO 'FOOD - SHOP'--------\n");
	printf("\n\t\t\tPlease Enter your name>>\n");
	gets(user);
	printf("\n\t\t\tPlease Enter your ZIP Code>>\n");
	gets(zip_code);
	
	printf("\n\t\t-----<< Hi %s , please make Your Order>>-----\n",user);
	printf("\n--------------------------------------------------------------------------------------------\n");
	
	while(f==1)
	{
		show();
		scanf("%d",&key);
		if(key==1){
			strcpy(itm[i].name_itm,"AB");
			printf("\n\t\tEnter No. of Piece of 'AB' (It should be in range [ 0 to 10 ] ) >>\n");////
			scanf("%d",&itm[i].no);
			if(itm[i].no>=0&&itm[i].no<=10){
				sum[i]=sum[i]+20*itm[i].no;////
			}
			else if(!(itm[i].no>=0&&itm[i].no<=10)){
				printf("\n\n\t\tSorry , You have entered a wrong input !!!!! >>\n");
				printf("\n--------------------------------------------------------------------------------------------\n");
				exit(0);
			}
				
			printf("\n\t\tContinue ?\n");
			printf("\n\t\tYes:1\t\tNo:0\n");
			scanf("%d",&f);
			if(f==1){
				i++;
				continue;
			}	
			else if(f==0)
				break;
			else if(f!=0){
				printf("\n\n\t\tSorry , You have entered a wrong input !!!!! >>\n");////
				printf("\n--------------------------------------------------------------------------------------------\n");
				exit(0);
			
			}
					
		}	
	/*	else if(){
			
		}
	*/	
	else{
		printf("\n\n\t\tSorry , You have entered a wrong input !!!!! >>\n");////
		printf("\n--------------------------------------------------------------------------------------------\n");
		exit(0);
	}
		
	}
	
	
		
	
	printf("\n--------------------------------------------------------------------------------------------\n");
	printf("\n\t\t           ----This is Your Bill----        \n");
	printf("\n\t\t           ----Please Pay Your Bill----        \n\n");
	printf("\n\t\tNAME - %s\t\t\t\tZIP CODE - %s\n\n",user,zip_code);
	printf("\n\t\tItem Name\t\tPiece No.\t\tAmount\n");
	for(j=0;j<=i;j++)
		printf("\n\t\t%s\t\t\t%d\t\t\t%.2f\n",itm[i].name_itm,itm[j].no,sum[j]);//
	
	gross_total=gst(total_sum(i))+total_sum(i);
	rebate=discount(gross_total);	
	gross_total-=rebate;
	printf("\n\t  ----------------------------------------------------------------\n");
	printf("\n\t\tTotal ==>>\t\t\t\t\t%.2f",total_sum(i));
	printf("\n\t\tGST (18%%) ==>>\t\t\t\t\t+%.2f",gst(total_sum(i)));	
	printf("\n\t\tDiscount (5%%) ==>>\t\t\t\t-%.2f",rebate);
	printf("\n\t  ----------------------------------------------------------------\n");
	printf("\n\t  ----------------------------------------------------------------\n");
	printf("\n\t\tNet Amount to be paid ==>>\t\t\t%.2f\n",gross_total);
	printf("\n\t  ----------------------------------------------------------------\n");
	printf("\n\t  ----------------------------------------------------------------\n");
	printf("\n\n\t\t Thank You sir ..... \n\t\t Please visit again.....\n\n");
	printf("\n--------------------------------------------------------------------------------------------\n");
	printf("\n--------------------------------------------------------------------------------------------\n");
	printf("\n--------------------------------------------------------------------------------------------\n");

	return 0;
}

void show(void)
{
	printf("\n\t\t(A). Item 'AB' & Rs.20 per piece & To Buy Press >> (1)\n");
//	printf("\n\t\t(2)>> Item 'BC' & Rs.30 per piece\n");
//	printf("\n\t\t(3)>> Item 'CD' & Rs.40 per piece\n");
//	printf("\n\t\t(4)>> Item 'DE' & Rs.50 per piece\n");	
}

float gst(float s)	// consider GST = 18%
{
	return (0.18*s);
}

float total_sum(int n)	//	calculate the total cost/Bill price
{
	int j;
	float temp_sum=0;
	for(j=0;j<=n;j++)
		temp_sum+=sum[j];
		
	return temp_sum;
}
float discount(float total)	// consider Discount = 5%
{
	return (0.05*total);
}
