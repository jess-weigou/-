<<<<<<< HEAD
/*������Ӧ��ܣ�ѧ�ţ�19151633*/
/*Ŀ�ģ��ϲ�������������ɾ��key������������*/ 
#include<stdio.h> 
#include<stdlib.h>
#define ElemType int 
struct Node{
	ElemType data;
	struct Node *next;
};
struct Node* creatlist()
{     //����һ������ 
	struct Node* headnode = (struct Node*)malloc(sizeof(struct Node));	
	headnode->next = NULL;
	return headnode;
} 
struct Node* createnode(int data)//�����½�� 
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data =data;
	newnode->next = NULL;
	return newnode;
} 
void insertnodebyhead(struct Node* headnode,int data)//ͷ�巨�������� 
{
	struct Node* newnode = createnode(data);
	newnode->next = headnode->next;
	headnode->next = newnode;
	newnode = newnode->next;
}
//void insertnodebytail(struct Node* headnode,int data)//��β����������(δ���) 
//{
//	struct Node* newnode = createnode(data);
//	newnode->next=NULL
//	headnode->next = newnode;  
//}
void printlist(struct Node* headnode)//��ӡ���� 
{
	struct Node* pmove=headnode->next;
	while(pmove)
	{
		printf("%d",pmove->data);
		pmove = pmove->next;
	}
	printf("\n");
} 
void delnode(struct Node* headnode,int data)//ɾ��ֵΪdata�Ľ�� 
{
	struct Node* pmove1=headnode->next;
	struct Node* pmove2=headnode;
	while(pmove1!=NULL)
	{
		if(pmove1->data==data)
		{
			pmove2->next = pmove1->next;
			free(pmove1);
			pmove1=pmove2->next;
		}else{
			pmove2 = pmove1;
			pmove1 = pmove2->next;
		}
	}
}
void nizhinode(struct Node* headnode) //�������� 
{
	struct Node* q = headnode->next;
	struct Node* p ;
	headnode->next = NULL;
	while(q!=NULL)
	{
		p=q;
		q=q->next;
		p->next = headnode->next;
		headnode->next = p; 
	}
}
void addnode(struct Node* list1,struct Node* list2,struct Node* list3) //�ϲ������Ѻϲ�������ŵ�list3���� 
{
	struct Node* p = list1->next;
	struct Node* q = list2->next;
	
	struct Node* c = list3;
	c->next=NULL; 
	while(p!=NULL&&q!=NULL)
	{
		if(p->data<=q->data)
		{
			c->next=p;
			c=p;
			p=p->next;
		}else{
			c->next=q;
			c=q;
			q=q->next;
		}
	}
	while(p!=NULL)
	{
		c->next=p;
		c=p;
		p=p->next;
	}
	while(q!=NULL)
	{
		c->next=q;
		c=q;
		q=q->next;
	}
	
}
int main()
{
	struct Node* list1=creatlist();
	struct Node* list2=creatlist();
	struct Node* list3=creatlist();
	insertnodebyhead(list1,3);//��������3458�ĸ������Ҵ�ӡ 
	insertnodebyhead(list1,4);
	insertnodebyhead(list1,5);
	insertnodebyhead(list1,8);
	insertnodebyhead(list1,2);
	printf("��ӡ����1: ");printlist(list1);
	nizhinode(list1);//�������ò��Ҵ�ӡ
	printf("��ӡ��������1: ");printlist(list1);
	delnode(list1,2); //����ɾ��2���Ҵ�ӡ 
	printf("ɾ������1�е�����2���Ҵ�ӡ: ");printlist(list1);
	insertnodebyhead(list2,9);//�������� 289������ 
	insertnodebyhead(list2,8);
	insertnodebyhead(list2,2);
	printf("��ӡ����2: ");printlist(list2);
	addnode(list1,list2,list3);//�ϲ��������� 
	printf("��ӡ�ϲ�����������: ");printlist(list3);
	return 0;
}
=======
/*������Ӧ��ܣ�ѧ�ţ�19151633*/
/*Ŀ�ģ��ϲ�������������ɾ��key������������*/ 
#include<stdio.h> 
#include<stdlib.h>
#define ElemType int 
struct Node{
	ElemType data;
	struct Node *next;
};
struct Node* creatlist()
{     //����һ������ 
	struct Node* headnode = (struct Node*)malloc(sizeof(struct Node));	
	headnode->next = NULL;
	return headnode;
} 
struct Node* createnode(int data)//�����½�� 
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data =data;
	newnode->next = NULL;
	return newnode;
} 
void insertnodebyhead(struct Node* headnode,int data)//ͷ�巨�������� 
{
	struct Node* newnode = createnode(data);
	newnode->next = headnode->next;
	headnode->next = newnode;
	newnode = newnode->next;
}
//void insertnodebytail(struct Node* headnode,int data)//��β����������(δ���) 
//{
//	struct Node* newnode = createnode(data);
//	newnode->next=NULL
//	headnode->next = newnode;  
//}
void printlist(struct Node* headnode)//��ӡ���� 
{
	struct Node* pmove=headnode->next;
	while(pmove)
	{
		printf("%d",pmove->data);
		pmove = pmove->next;
	}
	printf("\n");
} 
void delnode(struct Node* headnode,int data)//ɾ��ֵΪdata�Ľ�� 
{
	struct Node* pmove1=headnode->next;
	struct Node* pmove2=headnode;
	while(pmove1!=NULL)
	{
		if(pmove1->data==data)
		{
			pmove2->next = pmove1->next;
			free(pmove1);
			pmove1=pmove2->next;
		}else{
			pmove2 = pmove1;
			pmove1 = pmove2->next;
		}
	}
}
void nizhinode(struct Node* headnode) //�������� 
{
	struct Node* q = headnode->next;
	struct Node* p ;
	headnode->next = NULL;
	while(q!=NULL)
	{
		p=q;
		q=q->next;
		p->next = headnode->next;
		headnode->next = p; 
	}
}
void addnode(struct Node* list1,struct Node* list2,struct Node* list3) //�ϲ������Ѻϲ�������ŵ�list3���� 
{
	struct Node* p = list1->next;
	struct Node* q = list2->next;
	
	struct Node* c = list3;
	c->next=NULL; 
	while(p!=NULL&&q!=NULL)
	{
		if(p->data<=q->data)
		{
			c->next=p;
			c=p;
			p=p->next;
		}else{
			c->next=q;
			c=q;
			q=q->next;
		}
	}
	while(p!=NULL)
	{
		c->next=p;
		c=p;
		p=p->next;
	}
	while(q!=NULL)
	{
		c->next=q;
		c=q;
		q=q->next;
	}
	
}
int main()
{
	struct Node* list1=creatlist();
	struct Node* list2=creatlist();
	struct Node* list3=creatlist();
	insertnodebyhead(list1,3);//��������3458�ĸ������Ҵ�ӡ 
	insertnodebyhead(list1,4);
	insertnodebyhead(list1,5);
	insertnodebyhead(list1,8);
	insertnodebyhead(list1,2);
	printf("��ӡ����1: ");printlist(list1);
	nizhinode(list1);//�������ò��Ҵ�ӡ
	printf("��ӡ��������1: ");printlist(list1);
	delnode(list1,2); //����ɾ��2���Ҵ�ӡ 
	printf("ɾ������1�е�����2���Ҵ�ӡ: ");printlist(list1);
	insertnodebyhead(list2,9);//�������� 289������ 
	insertnodebyhead(list2,8);
	insertnodebyhead(list2,2);
	printf("��ӡ����2: ");printlist(list2);
	addnode(list1,list2,list3);//�ϲ��������� 
	printf("��ӡ�ϲ�����������: ");printlist(list3);
	return 0;
}
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
