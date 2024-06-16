<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h> 
#define LIST_INIT_SIZE 100//���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10//���Ա�洢�ռ�ķ�������
/**
My Code
to make the paragram run correctlly
*/
#define ElemType int

typedef struct {
    ElemType *elem;//�洢�ռ��ַ
    int length;//��ǰ����
    int listsize;//��ǰ����Ĵ���������sizeof(ElemType)λ��λ��
}SqList;
int compare(ElemType a, ElemType b)
{
    return a==b?1:0;
}
/**
algorithm 2.3
page 23
*/
Status InitList_Sq(SqList &L)
{
    //����һ���յ����Ա�
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem)
    {
        exit(OVERFLOW);
    }
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}//InitList_Sq

/**
algorithm 2.4
*/
Status ListInsert_Sq(SqList &L, int i, ElemType e)
{
    //��˳�����Ա�L�е�i��λ��֮ǰ�����µ�Ԫ��e
    //i�ĺϷ�Ϊ[1, ListLength_Sq(L)+1]
    if (i < 1 || i > L.length + 1)
    {
        return ERROR;//iֵ���Ϸ�
    }
    if (L.length >= L.listsize)
    {//��ǰ�洢�ռ����������ӷ���
        ElemType *newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT)*sizeof(ElemType));
        if (!newbase)
        {
            exit(OVERFLOW);//�洢����ʧ��
        }
        L.elem = newbase;//�»�ַ
        L.listsize += LISTINCREMENT;//���Ӵ洢����
    }
    ElemType *q = &(L.elem[i-1]);//qΪ����λ��
    for (ElemType *p = &L.elem[L.length-1]; p >= q; p--)
    {
        *(p+1) = *p;//����λ�ü�֮���Ԫ������
    }
    *q = e;
    ++L.length;
    return OK;
}//ListInsert_Sq
/**
algorithm 2.5
*/
Status ListDelete_Sq(SqList &L, int i, ElemType &e)
{
    //��˳�����Ա���ɾ����i��Ԫ�أ�����e������ֵ
    //i�ĺϷ�ֵΪ[1, ListLength_Sq(L)]
    if ((i < 1) || (i > L.length))
    {
        return ERROR;//iΪ���Ϸ�ֵ
    }
    ElemType *p = &(L.elem[i-1]);//pΪ��ɾ��Ԫ�ص�λ��
    e = *p;//��ɾ����Ԫ�ظ�ֵ��e
    ElemType *q = L.elem + L.length - 1;//��λԪ�ص�λ��
    for (++p; p <= q; ++p)
    {
        *(p-1) = *p;//��ɾ��Ԫ��֮���Ԫ������
    }
    --L.length;//���� 1
    return OK;
}//ListDelete_Sq
/**
algorithm 2.6
*/
int LocateElem_Sq(SqList L, ElemType e, Status(* compare)(ElemType, ElemType))
{
    //��˳�����Ա�L�в��ҵ�1��ֵ��e����compare()��Ԫ��λ��
    //���ҵ���������L�е�λ�򣬷��򷵻�0
    int i = 1;//i�ĳ�ֵΪ��һ��Ԫ�ص�λ��
    ElemType *p = L.elem;//pΪ��һ��Ԫ�صĴ洢λ��
    while (i <= L.length && !(*compare)(*p++, e))
    {
        ++i;
    }
    if (i <= L.length)
    {
        return i;
    }
    else
    {
        return 0;
    }
}//LocateElem_Sq
/**
algorithm 2.7
*/
void MergeList_Sq(SqList La, SqList Lb, SqList &Lc)
{
    //��֪˳�����Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ�����
    //�鲢La��Lb�õ��µ�˳�����Ա�Lc,Lc��Ԫ��Ҳ��ֵ�ǵݼ�����
    ElemType *pa = La.elem;
    ElemType *pb = Lb.elem;
    Lc.listsize = Lc.length = La.length + Lb.length;
    ElemType *pc = Lc.elem = (ElemType *)malloc(Lc.listsize*sizeof(ElemType));
    if (!Lc.elem)
    {
        exit(OVERFLOW);
    }
    ElemType *pa_last = La.elem + La.length - 1;
    ElemType *pb_last = Lb.elem + Lb.length - 1;
    while (pa <= pa_last && pb <= pb_last)
    {
        if (*pa <= *pb)
        {
            *pc++ = *pa++;
        }
        else
        {
            *pc++ = *pb++;
        }
    }
    while (pa <= pa_last)
    {
        *pc++ = *pa++;
    }
    while (pb <= pb_last)
    {
        *pc++ = *pb++;
    }
}//MergeList_Sq
/**
My code
*/
void PrintList(SqList L)
{
    for (int i = 1; i <= L.length; i++)
    {
        printf("%d\t", L.elem[i-1]);
    }
    printf("\n");
}
/**
My Test
*/
int main(int argc, char const *argv[])
{
	int LA[4]=(3,5,8,11);
    SqList La, Lb, Lc;
    InitList_Sq(La);
    InitList_Sq(Lb);
    InitList_Sq(Lc);
    //����һ��1 2 3 4�����Ա�
    ListInsert_Sq(La, 1, 10);
    ListInsert_Sq(La, 2, 20);
    ListInsert_Sq(La, 3, 30);
    ListInsert_Sq(La, 4, 50);
    PrintList(La);
    //��λ��4����ֵΪ5��λ�ã��� 4
    ListInsert_Sq(La, 4, 40);
    PrintList(La);
    //�������Ա�Lb;10, 20, 5, 30
    ListInsert_Sq(Lb, 1, 15);
    ListInsert_Sq(Lb, 2, 25);
    ListInsert_Sq(Lb, 3, 5);
    ListInsert_Sq(Lb, 4, 35);
    PrintList(Lb);
    int temp;
    //ɾ��λ��3��Ԫ�أ������ظ� temp
    ListDelete_Sq(Lb, 3, temp);
    PrintList(Lb);
    printf("%d\n", temp);
    //���� 30 �� Lb ��λ�� 
    printf("%d\n", LocateElem_Sq(Lb, 30, compare));
    printf("%d\n", LocateElem_Sq(Lb, 35, compare));
    //�ϲ�La�� Lb �� Lc��ע��ǰ���������
    MergeList_Sq(La, Lb, Lc);
    PrintList(Lc);
    return 0;
}
=======
#include<stdio.h>
#include<stdlib.h> 
#define LIST_INIT_SIZE 100//���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10//���Ա�洢�ռ�ķ�������
/**
My Code
to make the paragram run correctlly
*/
#define ElemType int

typedef struct {
    ElemType *elem;//�洢�ռ��ַ
    int length;//��ǰ����
    int listsize;//��ǰ����Ĵ���������sizeof(ElemType)λ��λ��
}SqList;
int compare(ElemType a, ElemType b)
{
    return a==b?1:0;
}
/**
algorithm 2.3
page 23
*/
Status InitList_Sq(SqList &L)
{
    //����һ���յ����Ա�
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem)
    {
        exit(OVERFLOW);
    }
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}//InitList_Sq

/**
algorithm 2.4
*/
Status ListInsert_Sq(SqList &L, int i, ElemType e)
{
    //��˳�����Ա�L�е�i��λ��֮ǰ�����µ�Ԫ��e
    //i�ĺϷ�Ϊ[1, ListLength_Sq(L)+1]
    if (i < 1 || i > L.length + 1)
    {
        return ERROR;//iֵ���Ϸ�
    }
    if (L.length >= L.listsize)
    {//��ǰ�洢�ռ����������ӷ���
        ElemType *newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT)*sizeof(ElemType));
        if (!newbase)
        {
            exit(OVERFLOW);//�洢����ʧ��
        }
        L.elem = newbase;//�»�ַ
        L.listsize += LISTINCREMENT;//���Ӵ洢����
    }
    ElemType *q = &(L.elem[i-1]);//qΪ����λ��
    for (ElemType *p = &L.elem[L.length-1]; p >= q; p--)
    {
        *(p+1) = *p;//����λ�ü�֮���Ԫ������
    }
    *q = e;
    ++L.length;
    return OK;
}//ListInsert_Sq
/**
algorithm 2.5
*/
Status ListDelete_Sq(SqList &L, int i, ElemType &e)
{
    //��˳�����Ա���ɾ����i��Ԫ�أ�����e������ֵ
    //i�ĺϷ�ֵΪ[1, ListLength_Sq(L)]
    if ((i < 1) || (i > L.length))
    {
        return ERROR;//iΪ���Ϸ�ֵ
    }
    ElemType *p = &(L.elem[i-1]);//pΪ��ɾ��Ԫ�ص�λ��
    e = *p;//��ɾ����Ԫ�ظ�ֵ��e
    ElemType *q = L.elem + L.length - 1;//��λԪ�ص�λ��
    for (++p; p <= q; ++p)
    {
        *(p-1) = *p;//��ɾ��Ԫ��֮���Ԫ������
    }
    --L.length;//���� 1
    return OK;
}//ListDelete_Sq
/**
algorithm 2.6
*/
int LocateElem_Sq(SqList L, ElemType e, Status(* compare)(ElemType, ElemType))
{
    //��˳�����Ա�L�в��ҵ�1��ֵ��e����compare()��Ԫ��λ��
    //���ҵ���������L�е�λ�򣬷��򷵻�0
    int i = 1;//i�ĳ�ֵΪ��һ��Ԫ�ص�λ��
    ElemType *p = L.elem;//pΪ��һ��Ԫ�صĴ洢λ��
    while (i <= L.length && !(*compare)(*p++, e))
    {
        ++i;
    }
    if (i <= L.length)
    {
        return i;
    }
    else
    {
        return 0;
    }
}//LocateElem_Sq
/**
algorithm 2.7
*/
void MergeList_Sq(SqList La, SqList Lb, SqList &Lc)
{
    //��֪˳�����Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ�����
    //�鲢La��Lb�õ��µ�˳�����Ա�Lc,Lc��Ԫ��Ҳ��ֵ�ǵݼ�����
    ElemType *pa = La.elem;
    ElemType *pb = Lb.elem;
    Lc.listsize = Lc.length = La.length + Lb.length;
    ElemType *pc = Lc.elem = (ElemType *)malloc(Lc.listsize*sizeof(ElemType));
    if (!Lc.elem)
    {
        exit(OVERFLOW);
    }
    ElemType *pa_last = La.elem + La.length - 1;
    ElemType *pb_last = Lb.elem + Lb.length - 1;
    while (pa <= pa_last && pb <= pb_last)
    {
        if (*pa <= *pb)
        {
            *pc++ = *pa++;
        }
        else
        {
            *pc++ = *pb++;
        }
    }
    while (pa <= pa_last)
    {
        *pc++ = *pa++;
    }
    while (pb <= pb_last)
    {
        *pc++ = *pb++;
    }
}//MergeList_Sq
/**
My code
*/
void PrintList(SqList L)
{
    for (int i = 1; i <= L.length; i++)
    {
        printf("%d\t", L.elem[i-1]);
    }
    printf("\n");
}
/**
My Test
*/
int main(int argc, char const *argv[])
{
	int LA[4]=(3,5,8,11);
    SqList La, Lb, Lc;
    InitList_Sq(La);
    InitList_Sq(Lb);
    InitList_Sq(Lc);
    //����һ��1 2 3 4�����Ա�
    ListInsert_Sq(La, 1, 10);
    ListInsert_Sq(La, 2, 20);
    ListInsert_Sq(La, 3, 30);
    ListInsert_Sq(La, 4, 50);
    PrintList(La);
    //��λ��4����ֵΪ5��λ�ã��� 4
    ListInsert_Sq(La, 4, 40);
    PrintList(La);
    //�������Ա�Lb;10, 20, 5, 30
    ListInsert_Sq(Lb, 1, 15);
    ListInsert_Sq(Lb, 2, 25);
    ListInsert_Sq(Lb, 3, 5);
    ListInsert_Sq(Lb, 4, 35);
    PrintList(Lb);
    int temp;
    //ɾ��λ��3��Ԫ�أ������ظ� temp
    ListDelete_Sq(Lb, 3, temp);
    PrintList(Lb);
    printf("%d\n", temp);
    //���� 30 �� Lb ��λ�� 
    printf("%d\n", LocateElem_Sq(Lb, 30, compare));
    printf("%d\n", LocateElem_Sq(Lb, 35, compare));
    //�ϲ�La�� Lb �� Lc��ע��ǰ���������
    MergeList_Sq(La, Lb, Lc);
    PrintList(Lc);
    return 0;
}
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
