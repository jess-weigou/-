<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>
typedef struct PolyNode *Polynomial;
struct PolyNode{
	int coef;
	int expon;
	Polynomial link;
}; 
Polynomial ReadPoly()//�������� 
{
	int N;
	scanf("%d",&N);
	while(N--){
		scanf("%d %d",&c,&e);
		Attach(c,3,&Rear);
	} 
	return P;
}
void Attach(int c,int e,,PLLYNOMIAL *pRear){
	Polynomial P��
	P= (Polynomial)malloc(sizeof(struct PolyNode));
	p->coef=c
	p->expon=e;
	p->link=NULL;
	(*pRear)->link=P;
	*pRear =P;
	}
	 
 
int main()
{
	Polynomial p1,p2,PP,PS;//p1�ŵ�һ������p2�ŵڶ�������pp�ˣ�ps��
	P1=Readpoly(); 
	P2=Readpoly(); 
	pp=Mult(p1,p2);
	PrintPoly(pp);
	ps=add(p1,p2);
	PrintPoly(ps);
	return 0;
} 
=======
#include<stdio.h>
#include<stdlib.h>
typedef struct PolyNode *Polynomial;
struct PolyNode{
	int coef;
	int expon;
	Polynomial link;
}; 
Polynomial ReadPoly()//�������� 
{
	int N;
	scanf("%d",&N);
	while(N--){
		scanf("%d %d",&c,&e);
		Attach(c,3,&Rear);
	} 
	return P;
}
void Attach(int c,int e,,PLLYNOMIAL *pRear){
	Polynomial P��
	P= (Polynomial)malloc(sizeof(struct PolyNode));
	p->coef=c
	p->expon=e;
	p->link=NULL;
	(*pRear)->link=P;
	*pRear =P;
	}
	 
 
int main()
{
	Polynomial p1,p2,PP,PS;//p1�ŵ�һ������p2�ŵڶ�������pp�ˣ�ps��
	P1=Readpoly(); 
	P2=Readpoly(); 
	pp=Mult(p1,p2);
	PrintPoly(pp);
	ps=add(p1,p2);
	PrintPoly(ps);
	return 0;
} 
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
