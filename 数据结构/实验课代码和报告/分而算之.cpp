<<<<<<< HEAD
#include<stdio.h>
int *a;
int max(int d,int b,int c)
{
    if(d>=b&&d>=c) return d;
    else if(b>=d&&b>=c) return b;
    else return c;
}
int divideandconquer(int left,long int right)
{
    int maxleftborder;int maxrightborder;
    int sumleftborder;int sumrightborder;
    int center;
    int maxleftsum,maxrightsum;
    if(left==right)//���ֻ��һ������
    {
        if(a[left]>0) return a[left];
        else return 0;
    }
    center=(left+right)/2;
    maxleftsum=divideandconquer(left,center);
    maxrightsum=divideandconquer(center,right);
    sumleftborder=0;sumrightborder=0; 
    for(int i=center+1;i<=right;i++)//�ұ�ɨ��
    {
        sumrightborder+=a[i];
        if(sumrightborder>maxrightborder)
        {
            maxrightborder=sumrightborder;
        }
    }
    for(int i=center;i>=left;i--)//s���ɨ��
    {
        sumleftborder+=a[i];
        if(sumleftborder>maxleftborder)
        {
            maxleftborder=sumleftborder;
        }
    }
    return max(maxleftsum,maxrightsum,maxleftborder+maxrightborder);
}

int main()
{
    long int number;
    
    scanf("%d\n",number);
    for(int i=0;i<number;i++)
    {
        scanf("%d",a[i]);
    }
    printf("%d",divideandconquer(1 ,number));
}
=======
#include<stdio.h>
int *a;
int max(int d,int b,int c)
{
    if(d>=b&&d>=c) return d;
    else if(b>=d&&b>=c) return b;
    else return c;
}
int divideandconquer(int left,long int right)
{
    int maxleftborder;int maxrightborder;
    int sumleftborder;int sumrightborder;
    int center;
    int maxleftsum,maxrightsum;
    if(left==right)//���ֻ��һ������
    {
        if(a[left]>0) return a[left];
        else return 0;
    }
    center=(left+right)/2;
    maxleftsum=divideandconquer(left,center);
    maxrightsum=divideandconquer(center,right);
    sumleftborder=0;sumrightborder=0; 
    for(int i=center+1;i<=right;i++)//�ұ�ɨ��
    {
        sumrightborder+=a[i];
        if(sumrightborder>maxrightborder)
        {
            maxrightborder=sumrightborder;
        }
    }
    for(int i=center;i>=left;i--)//s���ɨ��
    {
        sumleftborder+=a[i];
        if(sumleftborder>maxleftborder)
        {
            maxleftborder=sumleftborder;
        }
    }
    return max(maxleftsum,maxrightsum,maxleftborder+maxrightborder);
}

int main()
{
    long int number;
    
    scanf("%d\n",number);
    for(int i=0;i<number;i++)
    {
        scanf("%d",a[i]);
    }
    printf("%d",divideandconquer(1 ,number));
}
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
