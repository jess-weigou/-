<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
struct number{
	int m;
	int n;
	int e;
}; 
int main()
{
	int a,b,k,swap;
	printf("������a����b��" );
	scanf("%d %d",&a,&b);
	
	int numbers[a][b];
	int num[b]; 
	int cpot[b];
	k=0;//ϡ��������ֵ��Ϊ0��ֵ 
	printf("����ϡ�����" );
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<b;j++)
		{
			scanf("%d",&numbers[i][j]);
			if(numbers[i][j]!=0)
			{
				k++;
			} 
		}
	}
	struct number shuzu[k];
	struct number shuzu2[k];
	struct number shuzu3[k];
	memset(num,0,sizeof(num));
	memset(cpot,0,sizeof(cpot));
	memset(shuzu,0,sizeof(shuzu));
	memset(shuzu2,0,sizeof(shuzu2));
	memset(shuzu3,0,sizeof(shuzu3));
	k=0;
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<b;j++)
		{
			if(numbers[i][j]!=0)
			{
				num[j]+=1;
				shuzu[k].m=i+1;
				shuzu[k].n=j+1;
				shuzu[k].e=numbers[i][j]; 
				k++;
			}
		}
	}
	printf("δת��ǰϡ�������ֵ\n");
	for(int i=0;i<k;i++)
	{
		printf("%d %d %d\n",shuzu[i].m,shuzu[i].n,shuzu[i].e);
	} 
	
	int p=0;
	for(int j=0;j<b;j++)
	{
		for(int i=0;i<k;i++)
		{
			if(shuzu[i].n==j+1)
			{
				shuzu2[p].n=shuzu[i].m;
				shuzu2[p].m=shuzu[i].n;
				shuzu2[p].e=shuzu[i].e;
				p++;
			}
		}
	}
	printf("����1ת�ú�ϡ�������ֵ\n");
	for(int i=0;i<k;i++)
	{
		printf("%d %d %d\n",shuzu2[i].m,shuzu2[i].n,shuzu2[i].e);
	} 
	cpot[0]=0;
	for(int i=1;i<b;i++)
	{
		cpot[i]=cpot[i-1]+num[i-1];
	}
//	for(int i=0;i<b;i++)
//	{
//		printf("num: %d\n",num[i]);
//	} 
	for(int j=0;j<b;j++)
	{
		if(num[j]>0)
		{
			for(int i=0;i<k;i++)
			{
				if(shuzu[i].n==j+1)
				{
					for(p=cpot[j];p<cpot[j]+num[j];p++)
					{
						shuzu3[p].m=shuzu[i].n;
						shuzu3[p].n=shuzu[i].m;
						shuzu3[p].e=shuzu[i].e;
						i++;
					}
				}
			}
		}
	} 
	printf("����2ת�ú�ϡ�������ֵ\n");

	for(int i=0;i<k;i++)
	{
		printf("%d %d %d\n",shuzu3[i].m,shuzu3[i].n,shuzu3[i].e);
	}
	return 0;
}
=======
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
struct number{
	int m;
	int n;
	int e;
}; 
int main()
{
	int a,b,k,swap;
	printf("������a����b��" );
	scanf("%d %d",&a,&b);
	
	int numbers[a][b];
	int num[b]; 
	int cpot[b];
	k=0;//ϡ��������ֵ��Ϊ0��ֵ 
	printf("����ϡ�����" );
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<b;j++)
		{
			scanf("%d",&numbers[i][j]);
			if(numbers[i][j]!=0)
			{
				k++;
			} 
		}
	}
	struct number shuzu[k];
	struct number shuzu2[k];
	struct number shuzu3[k];
	memset(num,0,sizeof(num));
	memset(cpot,0,sizeof(cpot));
	memset(shuzu,0,sizeof(shuzu));
	memset(shuzu2,0,sizeof(shuzu2));
	memset(shuzu3,0,sizeof(shuzu3));
	k=0;
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<b;j++)
		{
			if(numbers[i][j]!=0)
			{
				num[j]+=1;
				shuzu[k].m=i+1;
				shuzu[k].n=j+1;
				shuzu[k].e=numbers[i][j]; 
				k++;
			}
		}
	}
	printf("δת��ǰϡ�������ֵ\n");
	for(int i=0;i<k;i++)
	{
		printf("%d %d %d\n",shuzu[i].m,shuzu[i].n,shuzu[i].e);
	} 
	
	int p=0;
	for(int j=0;j<b;j++)
	{
		for(int i=0;i<k;i++)
		{
			if(shuzu[i].n==j+1)
			{
				shuzu2[p].n=shuzu[i].m;
				shuzu2[p].m=shuzu[i].n;
				shuzu2[p].e=shuzu[i].e;
				p++;
			}
		}
	}
	printf("����1ת�ú�ϡ�������ֵ\n");
	for(int i=0;i<k;i++)
	{
		printf("%d %d %d\n",shuzu2[i].m,shuzu2[i].n,shuzu2[i].e);
	} 
	cpot[0]=0;
	for(int i=1;i<b;i++)
	{
		cpot[i]=cpot[i-1]+num[i-1];
	}
//	for(int i=0;i<b;i++)
//	{
//		printf("num: %d\n",num[i]);
//	} 
	for(int j=0;j<b;j++)
	{
		if(num[j]>0)
		{
			for(int i=0;i<k;i++)
			{
				if(shuzu[i].n==j+1)
				{
					for(p=cpot[j];p<cpot[j]+num[j];p++)
					{
						shuzu3[p].m=shuzu[i].n;
						shuzu3[p].n=shuzu[i].m;
						shuzu3[p].e=shuzu[i].e;
						i++;
					}
				}
			}
		}
	} 
	printf("����2ת�ú�ϡ�������ֵ\n");

	for(int i=0;i<k;i++)
	{
		printf("%d %d %d\n",shuzu3[i].m,shuzu3[i].n,shuzu3[i].e);
	}
	return 0;
}
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
