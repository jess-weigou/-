<<<<<<< HEAD
#include<stdio.h>
int main(){
	int a;
	int c,d;
	int i,j,max,sum;
	scanf("%d",&a);//a�����м��� 
	int number[a];
	for( i=0;i<a;i++)
	{
		scanf("%d",&number[i]);
		scanf("%d",&max);//�����һ���� 
		sum=max;
		for(j=1;j<number[i];j++)
		{
			scanf("%d",&c);
			sum+=c;
			if(c>max) max=c;
		}
		sum=sum-max;
		if(max<=sum+1) printf("Yes\n");
		else printf("No\n");	
	}
} 

=======
#include<stdio.h>
int main(){
	int a;
	int c,d;
	int i,j,max,sum;
	scanf("%d",&a);//a�����м��� 
	int number[a];
	for( i=0;i<a;i++)
	{
		scanf("%d",&number[i]);
		scanf("%d",&max);//�����һ���� 
		sum=max;
		for(j=1;j<number[i];j++)
		{
			scanf("%d",&c);
			sum+=c;
			if(c>max) max=c;
		}
		sum=sum-max;
		if(max<=sum+1) printf("Yes\n");
		else printf("No\n");	
	}
} 

>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
