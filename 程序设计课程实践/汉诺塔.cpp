<<<<<<< HEAD
#include<stdio.h> 

void Hanoi(int level,char A,char B,char C)
{
	if (level == 1)//��4����������ֻ��һ������ʱ��ֱ�Ӵ�A�ƶ���C
	{
		printf("%c->%c\n",A,C);
		return;
	}
	//��1��������������1ʱ���Ȱ�n-1����A����C�ƶ���B��
	Hanoi(level - 1, A, C, B);
	//��2��Ȼ������һ����A�ƶ���C��
	printf("%c->%c\n",A,C);
	//��3���ٽ��Ű�����������1ʱ���Ȱ�n-1����B����A�ƶ���C��
	Hanoi(level - 1, B, A, C);
}
int main()
{
	int level=1;

	scanf("%d", &level);
	Hanoi(level,'A','B','C');
	return 0;
} 
=======
#include<stdio.h> 

void Hanoi(int level,char A,char B,char C)
{
	if (level == 1)//��4����������ֻ��һ������ʱ��ֱ�Ӵ�A�ƶ���C
	{
		printf("%c->%c\n",A,C);
		return;
	}
	//��1��������������1ʱ���Ȱ�n-1����A����C�ƶ���B��
	Hanoi(level - 1, A, C, B);
	//��2��Ȼ������һ����A�ƶ���C��
	printf("%c->%c\n",A,C);
	//��3���ٽ��Ű�����������1ʱ���Ȱ�n-1����B����A�ƶ���C��
	Hanoi(level - 1, B, A, C);
}
int main()
{
	int level=1;

	scanf("%d", &level);
	Hanoi(level,'A','B','C');
	return 0;
} 
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
