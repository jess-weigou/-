<<<<<<< HEAD
#include<stdio.h>
#include<stdio.h>
#include<string.h>
int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
int main()
{
	int shuzu[105][105];

	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		memset(shuzu,0,sizeof(shuzu));
		scanf("%d",&n);
		for(int i=0;i<n;i++)//���� 
		{
			for(int j=0;j<=i;j++)
			{
				scanf("%d",&shuzu[i][j]);
			}
		}
		for(int i=n-2;i>=0;i--)
		{
			for(int j=0;j<=i;j++)
			{
				shuzu[i][j]+=max(shuzu[i+1][j],shuzu[i+1][j+1]);
			}
		}
		printf("%d\n",shuzu[0][0]);
	}
}
=======
#include<stdio.h>
#include<stdio.h>
#include<string.h>
int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
int main()
{
	int shuzu[105][105];

	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		memset(shuzu,0,sizeof(shuzu));
		scanf("%d",&n);
		for(int i=0;i<n;i++)//���� 
		{
			for(int j=0;j<=i;j++)
			{
				scanf("%d",&shuzu[i][j]);
			}
		}
		for(int i=n-2;i>=0;i--)
		{
			for(int j=0;j<=i;j++)
			{
				shuzu[i][j]+=max(shuzu[i+1][j],shuzu[i+1][j+1]);
			}
		}
		printf("%d\n",shuzu[0][0]);
	}
}
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
