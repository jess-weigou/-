<<<<<<< HEAD
/*������ħ������:(�������#�Ž���) ��ab��#
-93-889798-93-8735ab
40   9798   4135aba
*/
#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100;
#define STACKINCREMENT 10;
#define null 0;
#include<queue>
using namespace std;
typedef struct sqstack//����ջ 
{
  char *base;
  char *top;
  int stacksize;
}sqstack;

void InitStack(sqstack *s)//����ջ 
{
  s->base =(char*) malloc(1009 * sizeof(char));
  s->top=s->base;
  s->stacksize=STACK_INIT_SIZE;
}
void push(sqstack *s,char e)
{
	*(s->top)=e;
	s->top++;
}
char getTop(sqstack *s)//���ջ 
{
	char e;
	if(s->top==s->base)
		 return -1;
	 e=*(s->top-1);
	 s->top--;
	 return e;
}
int main()
{
	
	queue<char> q;
	sqstack *s;
	int m,j,number=0;
	int i=0;
	s=(sqstack*)malloc(sizeof(sqstack));
    InitStack(s);
   //������ħ�����ԣ�������һά����demon
    printf("������ħ������:(�������#�Ž���) ");
	char demon[100];
	char c;
	while(c!='#')
	{
		scanf("%c",&c);
		//printf("%d",c);
		if(c<=0)
		{
			printf("��������ȫ���ַ��������˳�"); 
			return -1;
		} 
		demon[i]=c;
		i++;
	}
	i--; 
  //�������飬��������������Ԫ����ջ��������Ӧ����ĸ
   for(j=0;j<i-1;j++)
   {
     if(demon[j]=='(')
	 {
		 m=j;
         push(s,demon[m+1]);
	   while(demon[j+2]!=')')
       {
	     push(s,demon[j+2]);
		 push(s,demon[m+1]);
		 j++;
	   }
	  
	 }
   }
	int p=0;
	while(p<=i)
	{
		char ch=demon[p];
		if(ch=='#') break;//����#���� 
		if(ch>='a'&&ch<='z')//����� 
		{
			
			q.push(ch);
			ch=q.front();
			q.pop();
			printf("%c",ch);
			//printf("%c",ch);
		}
		else if(ch=='A')
		{
		
		 printf("%s"," sae ");
		}
		else if(ch=='B')
		{
		  printf("%s"," tsaedsae ");
		}else if(ch=='(')
		{
			
			while(s->top!=s->base)//��ջ����� 
			{
				number++;
				q.push(getTop(s));
				ch=q.front();
				q.pop();
				printf("%c",ch);
				//printf("%c",getTop(s));
			}
			p=p+number/2+1;
		}
		p++;
	}
	 
return 0;
}
=======
/*������ħ������:(�������#�Ž���) ��ab��#
-93-889798-93-8735ab
40   9798   4135aba
*/
#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100;
#define STACKINCREMENT 10;
#define null 0;
#include<queue>
using namespace std;
typedef struct sqstack//����ջ 
{
  char *base;
  char *top;
  int stacksize;
}sqstack;

void InitStack(sqstack *s)//����ջ 
{
  s->base =(char*) malloc(1009 * sizeof(char));
  s->top=s->base;
  s->stacksize=STACK_INIT_SIZE;
}
void push(sqstack *s,char e)
{
	*(s->top)=e;
	s->top++;
}
char getTop(sqstack *s)//���ջ 
{
	char e;
	if(s->top==s->base)
		 return -1;
	 e=*(s->top-1);
	 s->top--;
	 return e;
}
int main()
{
	
	queue<char> q;
	sqstack *s;
	int m,j,number=0;
	int i=0;
	s=(sqstack*)malloc(sizeof(sqstack));
    InitStack(s);
   //������ħ�����ԣ�������һά����demon
    printf("������ħ������:(�������#�Ž���) ");
	char demon[100];
	char c;
	while(c!='#')
	{
		scanf("%c",&c);
		//printf("%d",c);
		if(c<=0)
		{
			printf("��������ȫ���ַ��������˳�"); 
			return -1;
		} 
		demon[i]=c;
		i++;
	}
	i--; 
  //�������飬��������������Ԫ����ջ��������Ӧ����ĸ
   for(j=0;j<i-1;j++)
   {
     if(demon[j]=='(')
	 {
		 m=j;
         push(s,demon[m+1]);
	   while(demon[j+2]!=')')
       {
	     push(s,demon[j+2]);
		 push(s,demon[m+1]);
		 j++;
	   }
	  
	 }
   }
	int p=0;
	while(p<=i)
	{
		char ch=demon[p];
		if(ch=='#') break;//����#���� 
		if(ch>='a'&&ch<='z')//����� 
		{
			
			q.push(ch);
			ch=q.front();
			q.pop();
			printf("%c",ch);
			//printf("%c",ch);
		}
		else if(ch=='A')
		{
		
		 printf("%s"," sae ");
		}
		else if(ch=='B')
		{
		  printf("%s"," tsaedsae ");
		}else if(ch=='(')
		{
			
			while(s->top!=s->base)//��ջ����� 
			{
				number++;
				q.push(getTop(s));
				ch=q.front();
				q.pop();
				printf("%c",ch);
				//printf("%c",getTop(s));
			}
			p=p+number/2+1;
		}
		p++;
	}
	 
return 0;
}
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
