<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>
typedef  struct node{
	struct node *next;
	int number1;//Ϊλ��� 
}node;
int arr2[1000];
node* createnode(int i){//������� 
	node *p;
	p=(node*)malloc(sizeof(node));//���붯̬�ڴ� 
	if(p==NULL){
		printf("��̬�����ڴ�ʧ��"); 
		exit(0);
	} 
	p->number1=i;
	p->next=NULL;
	return p;
} 
node* creat_list(int n,int arr[])//���ӽ�� 
{
	node * p;
	node * new1;
	node * head;
	new1=createnode(arr[0]);
	head=new1;
	p=new1;
	for(int i=1;i<n;i++){//β�巨���� 
		new1=createnode(arr[i]);
		p->next=new1;
		p=new1;
	}
	p->next=head;//�γɻ� 
	return head;
}
//��ӡ���ֽ�� 
node* print(node *p,int flag){
	node *new2;
	int static k=0;//���ڱ�ע�ڼ������� 
	new2=p->next;
	if(flag==1){
		printf("%4d",p->next->number1);//�������λ��
	}else{
		arr2[k++]=p->next->number1;
	}
	p->next=p->next->next; 
	free(new2);
	return p->next;
} 
void loop(int number,node *head,int n,int flag){
	node *p=head;
	int count=0;
	while(count<n)
	{
		for(int i=0;i<number-2;i++){
			p=p->next;
		}
		p=print(p,flag);
		count++;
	}
} 
int main(){
	int n; 
	int number1,number2;
	node *head;
	scanf("%d",&n);
	int  arr[n];
	for(int i=0;i<n;i++){
		arr[i]=i+1;
	}
	head=creat_list(n,arr);
	scanf("%d%d",&number1,&number2); 
	loop(number1,head,n,0);
	head=creat_list(n,arr2);
	loop(number2,head,n,1);
	return 0;
}
=======
#include<stdio.h>
#include<stdlib.h>
typedef  struct node{
	struct node *next;
	int number1;//Ϊλ��� 
}node;
int arr2[1000];
node* createnode(int i){//������� 
	node *p;
	p=(node*)malloc(sizeof(node));//���붯̬�ڴ� 
	if(p==NULL){
		printf("��̬�����ڴ�ʧ��"); 
		exit(0);
	} 
	p->number1=i;
	p->next=NULL;
	return p;
} 
node* creat_list(int n,int arr[])//���ӽ�� 
{
	node * p;
	node * new1;
	node * head;
	new1=createnode(arr[0]);
	head=new1;
	p=new1;
	for(int i=1;i<n;i++){//β�巨���� 
		new1=createnode(arr[i]);
		p->next=new1;
		p=new1;
	}
	p->next=head;//�γɻ� 
	return head;
}
//��ӡ���ֽ�� 
node* print(node *p,int flag){
	node *new2;
	int static k=0;//���ڱ�ע�ڼ������� 
	new2=p->next;
	if(flag==1){
		printf("%4d",p->next->number1);//�������λ��
	}else{
		arr2[k++]=p->next->number1;
	}
	p->next=p->next->next; 
	free(new2);
	return p->next;
} 
void loop(int number,node *head,int n,int flag){
	node *p=head;
	int count=0;
	while(count<n)
	{
		for(int i=0;i<number-2;i++){
			p=p->next;
		}
		p=print(p,flag);
		count++;
	}
} 
int main(){
	int n; 
	int number1,number2;
	node *head;
	scanf("%d",&n);
	int  arr[n];
	for(int i=0;i<n;i++){
		arr[i]=i+1;
	}
	head=creat_list(n,arr);
	scanf("%d%d",&number1,&number2); 
	loop(number1,head,n,0);
	head=creat_list(n,arr2);
	loop(number2,head,n,1);
	return 0;
}
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
