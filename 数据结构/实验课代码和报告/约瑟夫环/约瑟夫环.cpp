<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>
typedef  struct node{
	struct node *next;
	struct node *prior;
	int number1;//Ϊλ��� 
	int number2;//Ϊ���� 
}node;
node* createnode(int i){//������� 
	node *p;
	int b;
	p=(node*)malloc(sizeof(node));//���붯̬�ڴ� 
	if(p==NULL){
		printf("��̬�����ڴ�ʧ��"); 
		exit(0);
	} 
	printf("�������%d���˵����룺",i);
	p->number1=i;
	scanf("%d",&p->number2);//�������� 
	p->next=NULL;
	p->prior=NULL;
	return p;
} 
node* creat_list(int n)//���ӽ�� 
{
	node * p;
	node * new1;
	node * head;
	if(n>=1){
		new1=createnode(1);
		head=new1;
		p=new1;
	}
	for(int i=2;i<=n;i++){//β�巨���� 
		new1=createnode(i);
		p->next=new1;
		new1->prior=p;
		p=new1;
	}
	p->next=head;//�γɻ� 
	head->prior=p;//�γɻ� 
	if (n>=1) return head;
}
node* delete1(node *p){//ɾ����� 
	node *new2;
	int static k=1;//���ڱ�ע�ڼ������� 
	p->prior->next=p->next;
	p->next->prior=p->prior;
	printf("��%d�����е�λ���ǣ�%d\n",k,p->number1);//�������λ�� 
	k++;
	new2=p->next;
	p->next=NULL;
	return new2;
} 
void xunhuan(int number,node *head,int n){//��whileѭ����� ,n���ִ���˵ĸ��� 
	node *p=head;
	while(p!=NULL)
	{
		//number=number%n;
		if(number ==0){
			p=delete1(p->prior);
			number=p->number2;
			n--;
		}else{
			for(int i=2;i<=number;i++) p=p->next;
			number=p->number2;
			p=delete1(p);
		}
	}
} 
int main(){
	int n; //�ܹ��ж�����; 
	int number;
	node *p;
	printf("������������ "); 
	scanf("%d",&n);
	p=creat_list(n);
	printf("�����һ������ֵ��"); 
	scanf("%d",&number); 
	xunhuan(number,p,n);
	return 0;
} 
=======
#include<stdio.h>
#include<stdlib.h>
typedef  struct node{
	struct node *next;
	struct node *prior;
	int number1;//Ϊλ��� 
	int number2;//Ϊ���� 
}node;
node* createnode(int i){//������� 
	node *p;
	int b;
	p=(node*)malloc(sizeof(node));//���붯̬�ڴ� 
	if(p==NULL){
		printf("��̬�����ڴ�ʧ��"); 
		exit(0);
	} 
	printf("�������%d���˵����룺",i);
	p->number1=i;
	scanf("%d",&p->number2);//�������� 
	p->next=NULL;
	p->prior=NULL;
	return p;
} 
node* creat_list(int n)//���ӽ�� 
{
	node * p;
	node * new1;
	node * head;
	if(n>=1){
		new1=createnode(1);
		head=new1;
		p=new1;
	}
	for(int i=2;i<=n;i++){//β�巨���� 
		new1=createnode(i);
		p->next=new1;
		new1->prior=p;
		p=new1;
	}
	p->next=head;//�γɻ� 
	head->prior=p;//�γɻ� 
	if (n>=1) return head;
}
node* delete1(node *p){//ɾ����� 
	node *new2;
	int static k=1;//���ڱ�ע�ڼ������� 
	p->prior->next=p->next;
	p->next->prior=p->prior;
	printf("��%d�����е�λ���ǣ�%d\n",k,p->number1);//�������λ�� 
	k++;
	new2=p->next;
	p->next=NULL;
	return new2;
} 
void xunhuan(int number,node *head,int n){//��whileѭ����� ,n���ִ���˵ĸ��� 
	node *p=head;
	while(p!=NULL)
	{
		//number=number%n;
		if(number ==0){
			p=delete1(p->prior);
			number=p->number2;
			n--;
		}else{
			for(int i=2;i<=number;i++) p=p->next;
			number=p->number2;
			p=delete1(p);
		}
	}
} 
int main(){
	int n; //�ܹ��ж�����; 
	int number;
	node *p;
	printf("������������ "); 
	scanf("%d",&n);
	p=creat_list(n);
	printf("�����һ������ֵ��"); 
	scanf("%d",&number); 
	xunhuan(number,p,n);
	return 0;
} 
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
