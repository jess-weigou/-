<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
typedef  struct bitnode{
	struct bitnode *lchild,*rchild;
	char data;
}bitnode ,*bitree;
create(bitree *t)
{
	char ch;
	scanf("%c",&ch);
	if(ch=='#') *t=NULL;
	else{
		*t =(bitnode*)malloc(sizeof(bitnode));
		(*t)->data=ch;
		create(&(*t)->lchild);
		create(&(*t)->rchild);	
	} 
}
visit(char c,int level){
	printf("%c λ�ڵ�%d��\n",c,level);
} 
void inorder(bitree t)//�ǵݹ���� 
{
	int i=0;
	bitree s[100];//���ڽ�ջ��ջ 
	bitree r;
	r=t;
	do{
		while(r!=NULL)
		{
			printf("%c\n",r->data);
			if(r->rchild!=NULL){
				s[i]=r->rchild;
				i=i+1;
//				printf("%d\n",i); 
			} 
			r=r->lchild;
		}
		if(i>0){
			i=i-1;
			r=s[i];
		} 
	}while(i>0||r!=NULL);
}
order(bitree t,int level){//�ݹ���� 
	if(t){
		visit(t->data,level);
		order(t->lchild,level+1);
		order(t->rchild,level+1);
	}
}
int main()
{
	bitree t;
	int level=1; 
	create(&t);
	printf("��������ǰ��ѭ��������\n");
	order(t,level);
	printf("��������ǰ���ѭ��������\n");
	inorder(t) ;
	return 0;
}

=======
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
typedef  struct bitnode{
	struct bitnode *lchild,*rchild;
	char data;
}bitnode ,*bitree;
create(bitree *t)
{
	char ch;
	scanf("%c",&ch);
	if(ch=='#') *t=NULL;
	else{
		*t =(bitnode*)malloc(sizeof(bitnode));
		(*t)->data=ch;
		create(&(*t)->lchild);
		create(&(*t)->rchild);	
	} 
}
visit(char c,int level){
	printf("%c λ�ڵ�%d��\n",c,level);
} 
void inorder(bitree t)//�ǵݹ���� 
{
	int i=0;
	bitree s[100];//���ڽ�ջ��ջ 
	bitree r;
	r=t;
	do{
		while(r!=NULL)
		{
			printf("%c\n",r->data);
			if(r->rchild!=NULL){
				s[i]=r->rchild;
				i=i+1;
//				printf("%d\n",i); 
			} 
			r=r->lchild;
		}
		if(i>0){
			i=i-1;
			r=s[i];
		} 
	}while(i>0||r!=NULL);
}
order(bitree t,int level){//�ݹ���� 
	if(t){
		visit(t->data,level);
		order(t->lchild,level+1);
		order(t->rchild,level+1);
	}
}
int main()
{
	bitree t;
	int level=1; 
	create(&t);
	printf("��������ǰ��ѭ��������\n");
	order(t,level);
	printf("��������ǰ���ѭ��������\n");
	inorder(t) ;
	return 0;
}

>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
