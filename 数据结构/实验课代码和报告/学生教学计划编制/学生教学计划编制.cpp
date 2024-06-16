<<<<<<< HEAD
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include<math.h> 
#include <iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define MAX_NAME 10   //�����ַ�������󳤶�;
#define MAX_CLASS_NUM 100
#define MAX_VERTEX_NUM 100
typedef int Status; // Status�Ǻ����ķ������ͣ�
typedef int Boolean;

int Z=0;
int X=0;
int term_num,credit_lim,q=1;
typedef int InfoType;
typedef char VertexType[MAX_NAME]; //�ַ�������;
typedef enum{DG}GraphKind;  //{����ͼ,������,����ͼ,������};
typedef struct ArcNode{     //���ṹ��
    int adjvex;      //�û���ָ��Ķ����λ��;
    struct ArcNode * nextarc;    //ָ����һ������ָ��;
    InfoType * info;    //����Ȩֵָ��;
}ArcNode;     //����;

typedef struct{
        VertexType data; //������Ϣ;
        ArcNode *firstarc; //��һ������ĵ�ַ,ָ���һ�������ö���Ļ���ָ��;
}VNode, AdjList[MAX_VERTEX_NUM];
//����һ��ͼ
typedef struct{                    
    AdjList vertices,vertices2;   //�ֱ��γ�����ѧ�֣�
    int vexnum,arcnum;    //�γ��������޹�ϵ�� 
    int kind;
}ALGraph;
//strcmp�����ȷ���0��������������Ƿ���ں���� ���޹�ϵ���±� 
int LocateVex(ALGraph G,VertexType u){
    int i;
    for(i=0;i<G.vexnum;++i)
        if(strcmp(u, G.vertices[i].data)==0)
            return i;
    return -1;
}
//����һ��ͼ 
Status CreateGraph(ALGraph &G){
    int i,j,k;
    VertexType v1,v2;  //������Ϣ��
    ArcNode * p;       //ָ���һ������ĳ����Ļ���ָ�룻
    printf("�������ѧ�ƻ��Ŀγ���: ");
    scanf("%d",& G.vexnum);
    printf("������γ����޹�ϵ��: ");
    scanf("%d",& G.arcnum);
    printf("������%d���γ̵Ĵ���ֵ(��:c01):\n",G.vexnum);
    for(i=0;i<G.vexnum;++i) {
        scanf("%s",G.vertices[i].data);
        G.vertices[i].firstarc=NULL;
    }
    printf("������%d���γ̵�ѧ��ֵ:\n",(G).vexnum);
    for(i=0;i<G.vexnum;++i) {
        scanf("%s",G.vertices2[i].data);
    }
    printf("��˳������ȫ�����޹�ϵ(�Կո���Ϊ���):\n");
    for(k=0;k<G.arcnum;++k) {         
        scanf("%s%s",v1,v2);
        i=LocateVex(G,v1);
        j=LocateVex(G,v2);
        p = (ArcNode*)malloc(sizeof(ArcNode)); //�½�һ���ڵ㣻
        p->adjvex = j;
        p->info = NULL;
        p->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p;
    }
    return OK;
}

void Display(ALGraph G){
    int i;
    ArcNode * p;
    switch(G.kind){
        case DG: printf("����ͼ\n");
    }
    printf("%d�����㣺\n",G.vexnum);
    for(i=0;i<G.vexnum;++i)
        printf("%s ",G.vertices[i].data);
    printf("\n%d����:\n",G.arcnum);
    for(i=0;i<G.vexnum;i++){
        p=G.vertices[i].firstarc;
        while(p){
            printf("%s��%s ",G.vertices[i].data,G.vertices[p->adjvex].data);
            p=p->nextarc;
        }
        printf("\n");
    }
}
//�����ֵ����Ⱥͳ��� 
void FindInDegree(ALGraph G,int indegree[]){
    int i;
    ArcNode *p;
	//����0 
    for(i=0;i<G.vexnum;i++)
        indegree[i]=0;
    for(i=0;i<G.vexnum;i++){
        p=G.vertices[i].firstarc;
        while(p){
        indegree[p->adjvex]++;
        p=p->nextarc;
        }
    }
}

typedef int SElemType;
#define STACK_INIT_SIZE 10
#define STACKINCREMENT 2
typedef struct SqStack{
    SElemType *base;
    SElemType *top;
     int stacksize;
}SqStack;

Status InitStack(SqStack *S){
    (*S).base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
        if(!(*S).base)
          exit(OVERFLOW);
    (*S).top=(*S).base;
    (*S).stacksize=STACK_INIT_SIZE;
    return OK;
}

void ClearStack(SqStack *S) { //���ջ�Ĳ���
        S->top=S->base;
}

Status StackEmpty(SqStack S){
    if(S.top==S.base)
          return true;
    else
          return false;
}

Status Pop(SqStack *S,SElemType *e){
    if((*S).top==(*S).base)
          return ERROR;
    *e=*--(*S).top;
    return OK;
}

Status Push(SqStack *S,SElemType e){
    if((*S).top-(*S).base>=(*S).stacksize){
          (*S).base=(SElemType *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(SElemType));
   if(!(*S).base)
        exit(OVERFLOW);
   (*S).top=(*S).base+(*S).stacksize;
   (*S).stacksize+=STACKINCREMENT;
    }
    *((*S).top)++=e;
    return OK;
}

Status zxf(ALGraph G){ //���ѧ���пγ���ѧ�֣�
    int z=0;
    for(int i=0; i < G.vexnum; i++){
        z += atoi(G.vertices2[i].data);
    }
    return z;
}

typedef int pathone[MAX_CLASS_NUM];
typedef int pathtwo[MAX_CLASS_NUM];
Status TopologicalSort(ALGraph G){
	int i,k,count,indegree[MAX_VERTEX_NUM];
	bool has = false;
	SqStack S;
	pathone a;
	pathtwo b;
	ArcNode * p;
	FindInDegree(G,indegree);
	InitStack(&S);
    for(i=0;i<G.vexnum;++i){
        if(!indegree[i])
        Push(&S,i);
   }
    count = 0;
    while(!StackEmpty(S)){
        Pop(&S,&i);
        a[i]=*G.vertices[i].data;  //�γ�����
        b[i]=*G.vertices2[i].data;  //ѧ�֣�
        printf("�γ�%s��ѧ��%s  ",G.vertices[i].data,G.vertices2[i].data);
        ++count;
	        for(p=G.vertices[i].firstarc; p; p=p->nextarc){
	            k=p->adjvex;
	            //�����Ȳ�����0��push 
	            if(!(--indegree[k]))
	                Push(&S,k);
	        }
        }
        if(count<G.vexnum){
            printf("������ͼ�л�·\n");
            return ERROR;
        }
        else{
            printf("Ϊһ���������С�\n\n");
            has=true;
        }
        printf("��������ʹѧ���ڸ�ѧ���е�ѧϰ�����������ȣ�����1��\n");
        printf("������ʹ�γ̾����ܵؼ�����ǰ����ѧ���У�����2����\n");
        int pattern;
        printf("��ѡ��(1 or 2):");
        scanf("%d",&pattern);
     	FindInDegree(G,indegree); //�Ը����������indegree[0..vernum-1] ;
        ClearStack(&S);
        printf("=====================================================\n");
        printf("��ѧ�ƻ����£�\n");
        int xq = 1; //ѧ����;
        int xfh;  //ѧ�ֺͣ�
        int now=0;
        int top = G.vexnum / term_num ; //ƽ��ÿѧ�ڿγ�����
        int pjxf = zxf(G) / term_num ; //ÿѧ��ƽ��ѧ�֣�
        while(xq <= term_num + 1){             
        	int result[20]; //ĳ��ѧ�ڵĿγ̣�
            int m = 0;
            xfh = 0;
            now=0;   //��ǰѧ�ڿγ��� ��
            for(i=0;i<G.vexnum;++i){  
			   //�������Ϊ0�ĵ�       
                if(0 == indegree[i])
                    Push(&S,i);
                }
                if(xq == term_num+1 && !StackEmpty(S)){
                    printf("���пγ�δ���ţ�\n");
                }
               while(!StackEmpty(S) && xq <= term_num){
                    int xf;
                    Pop(&S,&i); //����ջ��Ԫ�أ�
                    xf = atoi(G.vertices2[i].data); //atoi:�ַ���ת����������, xf:ѧ��;
                    xfh = xfh+xf;
                    now++;
                    //�����ѧ��ѧ�ִ������ѧ�֣����˳� 
                    if(xfh > credit_lim){
                        ClearStack(&S);
                        break;
                    }
                    if(pattern == 1){
                    	//���ѧ�ڲ����ڶ���֮һ��ѧ�ڶ������ڿγ̴���ƽ��ÿѧ�ڿγ̾����� 
                        if(xq!=term_num/2&&now>top){
                            ClearStack(&S); //�ò���ʹ�����������ڲ��whileѭ��;
                            now = 0;
                            break;      
                        }
                    }
                    if(pattern == 2){
                        if(xq!=1&&xq!=term_num/2&&xq!=term_num/2-1&&now>top){
                            ClearStack(&S);
                            now = 0;
                            break;
                        }
                    }
                    indegree[i]--; //��Ϊ-1,���ⱻ�ٴμ��룻
                    for(p=G.vertices[i].firstarc; p; p=p->nextarc){
                        k=p->adjvex;
                        //kͷ�ڵ����ȼ�1  
                        indegree[k]--;
                        if(indegree[k]==0)
                        Push(&S,k);     
                    }
                    result[m]=i;
                    m++;
                }
                if(xq <= term_num){
                    printf("��%d��ѧ�ڵĿγ�Ϊ��",xq);
                    for(int j=0; j<m; j++){
                        printf("�γ�%s ",G.vertices[result[j]].data);
                    }
                }
                printf("\n");
                xq++;
                ClearStack(&S);     
       }
       printf("=====================================================\n");
    return OK;
}
int main(){  
	printf("                            ��ѧ�ƻ���������(��������AOV-��)\n");
    //AOV-��:�����ʾ�������ʾ������ȹ�ϵ������ͼ��
        int CONTINUE = 1;
        printf("------------------------------------------------\n");
            ALGraph f;      //ͼ���ڽӱ�洢��
            printf("������ѧ������: ");
            scanf("%d",&term_num);
            printf("������ÿѧ�ڵ�ѧ������: ");
            scanf("%d",&credit_lim);
            CreateGraph(f);
            Display(f);
        while(CONTINUE != 0){
            TopologicalSort(f);
            printf("\n��1��������0����:");
            scanf("%d",&CONTINUE);      
        }
   return 0;
}
=======
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include<math.h> 
#include <iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define MAX_NAME 10   //�����ַ�������󳤶�;
#define MAX_CLASS_NUM 100
#define MAX_VERTEX_NUM 100
typedef int Status; // Status�Ǻ����ķ������ͣ�
typedef int Boolean;

int Z=0;
int X=0;
int term_num,credit_lim,q=1;
typedef int InfoType;
typedef char VertexType[MAX_NAME]; //�ַ�������;
typedef enum{DG}GraphKind;  //{����ͼ,������,����ͼ,������};
typedef struct ArcNode{     //���ṹ��
    int adjvex;      //�û���ָ��Ķ����λ��;
    struct ArcNode * nextarc;    //ָ����һ������ָ��;
    InfoType * info;    //����Ȩֵָ��;
}ArcNode;     //����;

typedef struct{
        VertexType data; //������Ϣ;
        ArcNode *firstarc; //��һ������ĵ�ַ,ָ���һ�������ö���Ļ���ָ��;
}VNode, AdjList[MAX_VERTEX_NUM];
//����һ��ͼ
typedef struct{                    
    AdjList vertices,vertices2;   //�ֱ��γ�����ѧ�֣�
    int vexnum,arcnum;    //�γ��������޹�ϵ�� 
    int kind;
}ALGraph;
//strcmp�����ȷ���0��������������Ƿ���ں���� ���޹�ϵ���±� 
int LocateVex(ALGraph G,VertexType u){
    int i;
    for(i=0;i<G.vexnum;++i)
        if(strcmp(u, G.vertices[i].data)==0)
            return i;
    return -1;
}
//����һ��ͼ 
Status CreateGraph(ALGraph &G){
    int i,j,k;
    VertexType v1,v2;  //������Ϣ��
    ArcNode * p;       //ָ���һ������ĳ����Ļ���ָ�룻
    printf("�������ѧ�ƻ��Ŀγ���: ");
    scanf("%d",& G.vexnum);
    printf("������γ����޹�ϵ��: ");
    scanf("%d",& G.arcnum);
    printf("������%d���γ̵Ĵ���ֵ(��:c01):\n",G.vexnum);
    for(i=0;i<G.vexnum;++i) {
        scanf("%s",G.vertices[i].data);
        G.vertices[i].firstarc=NULL;
    }
    printf("������%d���γ̵�ѧ��ֵ:\n",(G).vexnum);
    for(i=0;i<G.vexnum;++i) {
        scanf("%s",G.vertices2[i].data);
    }
    printf("��˳������ȫ�����޹�ϵ(�Կո���Ϊ���):\n");
    for(k=0;k<G.arcnum;++k) {         
        scanf("%s%s",v1,v2);
        i=LocateVex(G,v1);
        j=LocateVex(G,v2);
        p = (ArcNode*)malloc(sizeof(ArcNode)); //�½�һ���ڵ㣻
        p->adjvex = j;
        p->info = NULL;
        p->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p;
    }
    return OK;
}

void Display(ALGraph G){
    int i;
    ArcNode * p;
    switch(G.kind){
        case DG: printf("����ͼ\n");
    }
    printf("%d�����㣺\n",G.vexnum);
    for(i=0;i<G.vexnum;++i)
        printf("%s ",G.vertices[i].data);
    printf("\n%d����:\n",G.arcnum);
    for(i=0;i<G.vexnum;i++){
        p=G.vertices[i].firstarc;
        while(p){
            printf("%s��%s ",G.vertices[i].data,G.vertices[p->adjvex].data);
            p=p->nextarc;
        }
        printf("\n");
    }
}
//�����ֵ����Ⱥͳ��� 
void FindInDegree(ALGraph G,int indegree[]){
    int i;
    ArcNode *p;
	//����0 
    for(i=0;i<G.vexnum;i++)
        indegree[i]=0;
    for(i=0;i<G.vexnum;i++){
        p=G.vertices[i].firstarc;
        while(p){
        indegree[p->adjvex]++;
        p=p->nextarc;
        }
    }
}

typedef int SElemType;
#define STACK_INIT_SIZE 10
#define STACKINCREMENT 2
typedef struct SqStack{
    SElemType *base;
    SElemType *top;
     int stacksize;
}SqStack;

Status InitStack(SqStack *S){
    (*S).base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
        if(!(*S).base)
          exit(OVERFLOW);
    (*S).top=(*S).base;
    (*S).stacksize=STACK_INIT_SIZE;
    return OK;
}

void ClearStack(SqStack *S) { //���ջ�Ĳ���
        S->top=S->base;
}

Status StackEmpty(SqStack S){
    if(S.top==S.base)
          return true;
    else
          return false;
}

Status Pop(SqStack *S,SElemType *e){
    if((*S).top==(*S).base)
          return ERROR;
    *e=*--(*S).top;
    return OK;
}

Status Push(SqStack *S,SElemType e){
    if((*S).top-(*S).base>=(*S).stacksize){
          (*S).base=(SElemType *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(SElemType));
   if(!(*S).base)
        exit(OVERFLOW);
   (*S).top=(*S).base+(*S).stacksize;
   (*S).stacksize+=STACKINCREMENT;
    }
    *((*S).top)++=e;
    return OK;
}

Status zxf(ALGraph G){ //���ѧ���пγ���ѧ�֣�
    int z=0;
    for(int i=0; i < G.vexnum; i++){
        z += atoi(G.vertices2[i].data);
    }
    return z;
}

typedef int pathone[MAX_CLASS_NUM];
typedef int pathtwo[MAX_CLASS_NUM];
Status TopologicalSort(ALGraph G){
	int i,k,count,indegree[MAX_VERTEX_NUM];
	bool has = false;
	SqStack S;
	pathone a;
	pathtwo b;
	ArcNode * p;
	FindInDegree(G,indegree);
	InitStack(&S);
    for(i=0;i<G.vexnum;++i){
        if(!indegree[i])
        Push(&S,i);
   }
    count = 0;
    while(!StackEmpty(S)){
        Pop(&S,&i);
        a[i]=*G.vertices[i].data;  //�γ�����
        b[i]=*G.vertices2[i].data;  //ѧ�֣�
        printf("�γ�%s��ѧ��%s  ",G.vertices[i].data,G.vertices2[i].data);
        ++count;
	        for(p=G.vertices[i].firstarc; p; p=p->nextarc){
	            k=p->adjvex;
	            //�����Ȳ�����0��push 
	            if(!(--indegree[k]))
	                Push(&S,k);
	        }
        }
        if(count<G.vexnum){
            printf("������ͼ�л�·\n");
            return ERROR;
        }
        else{
            printf("Ϊһ���������С�\n\n");
            has=true;
        }
        printf("��������ʹѧ���ڸ�ѧ���е�ѧϰ�����������ȣ�����1��\n");
        printf("������ʹ�γ̾����ܵؼ�����ǰ����ѧ���У�����2����\n");
        int pattern;
        printf("��ѡ��(1 or 2):");
        scanf("%d",&pattern);
     	FindInDegree(G,indegree); //�Ը����������indegree[0..vernum-1] ;
        ClearStack(&S);
        printf("=====================================================\n");
        printf("��ѧ�ƻ����£�\n");
        int xq = 1; //ѧ����;
        int xfh;  //ѧ�ֺͣ�
        int now=0;
        int top = G.vexnum / term_num ; //ƽ��ÿѧ�ڿγ�����
        int pjxf = zxf(G) / term_num ; //ÿѧ��ƽ��ѧ�֣�
        while(xq <= term_num + 1){             
        	int result[20]; //ĳ��ѧ�ڵĿγ̣�
            int m = 0;
            xfh = 0;
            now=0;   //��ǰѧ�ڿγ��� ��
            for(i=0;i<G.vexnum;++i){  
			   //�������Ϊ0�ĵ�       
                if(0 == indegree[i])
                    Push(&S,i);
                }
                if(xq == term_num+1 && !StackEmpty(S)){
                    printf("���пγ�δ���ţ�\n");
                }
               while(!StackEmpty(S) && xq <= term_num){
                    int xf;
                    Pop(&S,&i); //����ջ��Ԫ�أ�
                    xf = atoi(G.vertices2[i].data); //atoi:�ַ���ת����������, xf:ѧ��;
                    xfh = xfh+xf;
                    now++;
                    //�����ѧ��ѧ�ִ������ѧ�֣����˳� 
                    if(xfh > credit_lim){
                        ClearStack(&S);
                        break;
                    }
                    if(pattern == 1){
                    	//���ѧ�ڲ����ڶ���֮һ��ѧ�ڶ������ڿγ̴���ƽ��ÿѧ�ڿγ̾����� 
                        if(xq!=term_num/2&&now>top){
                            ClearStack(&S); //�ò���ʹ�����������ڲ��whileѭ��;
                            now = 0;
                            break;      
                        }
                    }
                    if(pattern == 2){
                        if(xq!=1&&xq!=term_num/2&&xq!=term_num/2-1&&now>top){
                            ClearStack(&S);
                            now = 0;
                            break;
                        }
                    }
                    indegree[i]--; //��Ϊ-1,���ⱻ�ٴμ��룻
                    for(p=G.vertices[i].firstarc; p; p=p->nextarc){
                        k=p->adjvex;
                        //kͷ�ڵ����ȼ�1  
                        indegree[k]--;
                        if(indegree[k]==0)
                        Push(&S,k);     
                    }
                    result[m]=i;
                    m++;
                }
                if(xq <= term_num){
                    printf("��%d��ѧ�ڵĿγ�Ϊ��",xq);
                    for(int j=0; j<m; j++){
                        printf("�γ�%s ",G.vertices[result[j]].data);
                    }
                }
                printf("\n");
                xq++;
                ClearStack(&S);     
       }
       printf("=====================================================\n");
    return OK;
}
int main(){  
	printf("                            ��ѧ�ƻ���������(��������AOV-��)\n");
    //AOV-��:�����ʾ�������ʾ������ȹ�ϵ������ͼ��
        int CONTINUE = 1;
        printf("------------------------------------------------\n");
            ALGraph f;      //ͼ���ڽӱ�洢��
            printf("������ѧ������: ");
            scanf("%d",&term_num);
            printf("������ÿѧ�ڵ�ѧ������: ");
            scanf("%d",&credit_lim);
            CreateGraph(f);
            Display(f);
        while(CONTINUE != 0){
            TopologicalSort(f);
            printf("\n��1��������0����:");
            scanf("%d",&CONTINUE);      
        }
   return 0;
}
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
